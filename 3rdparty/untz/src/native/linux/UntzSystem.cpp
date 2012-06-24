//
//  UntzSystem.cpp
//  Part of UNTZ
//
//  Created by Robert Dalton Jr. (bob@retronyms.com) on 06/01/2011.
//  Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
//

#include "UntzSystem.h"
#include "SystemData.h"
#include "AudioMixer.h"
#include "RtAudio.h"
#include <stdio.h>
#include <string.h>

using namespace UNTZ;


/* The linux system data object
 *
 */
class LinuxSystemData : public UNTZ::SystemData
{
public:
	LinuxSystemData(int numFrames) : SystemData(), mNumFrames(numFrames) {};

	// SystemData
	virtual unsigned int getNumFrames()
	{
		return mNumFrames;
	}
	virtual unsigned int getNumOutputChannels()
	{
		return 2;
	}

	RtAudio audioIO;
	UInt32 mNumFrames;
	UInt32 mOptions;
    std::vector< float > mOutputBuffer;
};


int RtInOut( void* outputBuffer, void* inputBuffer, unsigned int framesPerBuffer, 
			double streamTime, RtAudioStreamStatus status, void *userdata )
{
    LinuxSystemData *sysData = (LinuxSystemData *)userdata;
    UInt32 numOutputChannels = UNTZ::System::get()->getData()->getNumOutputChannels();
    UInt32 samples = numOutputChannels * framesPerBuffer;

	if(!UNTZ::System::get()->getData()->isActive())
	{
		memset(outputBuffer, 0, sizeof(float) * samples);
		return 0;
	}

    if(sysData->mOutputBuffer.size() < samples)
    {
        sysData->mOutputBuffer.resize(samples);
    }
    float *mixerOutputBuffer = (float*)&sysData->mOutputBuffer[0];
    
	if(status)
		std::cout << "Stream underflow detected!" << std::endl;	
	AudioMixer *mixer = &sysData->mMixer;
	mixer->process(0, NULL, numOutputChannels, mixerOutputBuffer, framesPerBuffer);
	
    // volume & clipping & interleaving
	float volume = mixer->getVolume();
    float *outB = (float*)outputBuffer;
    for(UInt32 i=0; i<framesPerBuffer; i++)
    {
        for(UInt32 j=0; j<numOutputChannels; j++)
        {
			float val = volume * mixerOutputBuffer[j*framesPerBuffer+i];
            val = val > 1.0 ? 1.0 : val;
            val = val < -1.0 ? -1.0 : val;
            *(outB)++ = val;
        }
    }    

	return 0;
}


System* System::msInstance = 0;

System::System(UInt32 sampleRate, UInt32 numFrames, UInt32 options)
{
	LinuxSystemData *lsd = new LinuxSystemData(numFrames);
	lsd->mOptions = options;
	mpData = lsd;

	RtAudio::StreamParameters outParams;
	outParams.nChannels = 2;
	outParams.deviceId = lsd->audioIO.getDefaultOutputDevice();
	RtAudio::StreamOptions streamOptions;
	streamOptions.flags = 0 | RTAUDIO_MINIMIZE_LATENCY;
	try 
	{
		lsd->audioIO.openStream( &outParams, NULL, RTAUDIO_FLOAT32, sampleRate, &numFrames, &RtInOut, mpData, &streamOptions );
		lsd->audioIO.startStream();
	}
	catch(RtError& error)
	{
		lsd->setError(true);
		printf("!!!AudioIO Error: %s\n", error.getMessage().c_str());
	}
}

System::~System()
{
	if(mpData)
		delete mpData;
}

void System::shutdown()
{
	if(msInstance)
	{
		delete msInstance;
		msInstance = 0;
	}
}

System* System::initialize(UInt32 sampleRate, UInt32 numFrames, UInt32 options)
{
	if(!msInstance)
	{
		msInstance = new System(sampleRate, numFrames, options);
		if(msInstance->mpData->getError())
		{
			delete msInstance;
		}
		else
		{
			msInstance->mpData->mMixer.init();
		}
	}

	return msInstance;
}

System* System::get()
{
	return msInstance;
}

void System::setSampleRate(UInt32 sampleRate)
{
}

unsigned int System::getSampleRate()
{
	LinuxSystemData* lsd = (LinuxSystemData*)mpData;
	return lsd->audioIO.getStreamSampleRate();
}

void System::setVolume(float volume)
{
	return msInstance->mpData->mMixer.setVolume(volume);
}

float System::getVolume() const
{
	return msInstance->mpData->mMixer.getVolume();
}

void System::suspend()
{
	msInstance->mpData->setActive(false);
}

void System::resume()
{
	msInstance->mpData->setActive(true);
}
