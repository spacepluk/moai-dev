find_package(ALSA REQUIRED)

moai_set_local_source_dir()

include_directories(
    "${local_source_dir}/include"
    "${local_source_dir}/src"
    "${local_source_dir}/src/native/linux"
    "${local_source_dir}/../rtaudio-4.0.11"
    "${local_source_dir}/../rtaudio-4.0.11/include"
    ${ALSA_INCLUDE_DIRS}
)

add_definitions(-D__LINUX_PULSE__ -D__LINUX_ALSA__ -D__LINUX_OSS__)

add_library(untz STATIC
    "${local_source_dir}/include/Untz.h"
    "${local_source_dir}/include/UntzSystem.h"
    "${local_source_dir}/include/UntzSound.h"
    "${local_source_dir}/src/UserAudioSource.h"
    "${local_source_dir}/src/BufferedAudioSourceThread.h"
    "${local_source_dir}/src/native/linux/WaveFile.h"
    "${local_source_dir}/src/native/linux/RiffFile.h"
    "${local_source_dir}/src/native/linux/WaveFileAudioSource.h"
    "${local_source_dir}/src/SoundData.h"
    "${local_source_dir}/src/RAudioBuffer.h"
    "${local_source_dir}/src/threading/RCriticalSection.h"
    "${local_source_dir}/src/threading/Threading.h"
    "${local_source_dir}/src/threading/RScopedLock.h"
    "${local_source_dir}/src/threading/RThread.h"
    "${local_source_dir}/src/threading/RSyncEvent.h"
    "${local_source_dir}/src/AudioSource.h"
    "${local_source_dir}/src/MemoryAudioSource.h"
    "${local_source_dir}/src/counted_ptr.h"
    "${local_source_dir}/src/BufferedAudioSource.h"
    "${local_source_dir}/src/AudioMixer.h"
    "${local_source_dir}/src/SystemData.h"
    "${local_source_dir}/src/OggAudioSource.h"
    "${local_source_dir}/src/BufferedAudioSourceThread.cpp"
    "${local_source_dir}/src/OggAudioSource.cpp"
    "${local_source_dir}/src/native/linux/WaveFileAudioSource.cpp"
    "${local_source_dir}/src/native/linux/RiffFile.cpp"
    "${local_source_dir}/src/native/linux/UntzSystem.cpp"
    "${local_source_dir}/src/native/linux/WaveFile.cpp"
    "${local_source_dir}/src/UserAudioSource.cpp"
    "${local_source_dir}/src/AudioMixer.cpp"
    "${local_source_dir}/src/UntzSound.cpp"
    "${local_source_dir}/src/MemoryAudioSource.cpp"
    "${local_source_dir}/src/BufferedAudioSource.cpp"

    "${local_source_dir}/../rtaudio-4.0.11/RtAudio.cpp"
    "${local_source_dir}/../rtaudio-4.0.11/RtAudio.h"
    "${local_source_dir}/../rtaudio-4.0.11/RtError.h"
    "${local_source_dir}/../rtaudio-4.0.11/include/soundcard.h"
)

target_link_libraries(untz
    ${ALSA_LIBRARIES}
    pulse-simple
    vorbisfile
)
