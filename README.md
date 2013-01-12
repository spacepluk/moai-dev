This is an unofficial fork of Moai SDK
======================================
This fork adds some patches to enable build on Linux via cmake.  So far it's
been tested on Debian and Ubuntu.

System dependencies
-------------------
Before you build the package you'll need to install the following dependencies
on your system:

    sudo aptitude install freeglut3-dev libglew-dev libglu1-mesa-dev libxmu-dev libxi-dev chipmunk-dev libjpeg8-dev libpng-dev libfreetype6-dev liblua5.1-0-dev libjansson-dev libtinyxml-dev libcurl4-openssl-dev zlib1g-dev libexpat1-dev cmake build-essential libasound2-dev libvorbis-dev libpulse-dev


Building Moai
-------------
First clone this repository.  You should use the `linux-cmake` branch, this
should work on both 32 and 64-bit systems.

    git clone -b linux-cmake git://github.com/spacepluk/moai-dev.git

Then create a directory to contain the build.  And start compilation:

    mkdir build
    cd build
    cmake ../cmake/
    make -j4

