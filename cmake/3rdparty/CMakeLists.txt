option(BOX2D_INSTALL "Install Box2D libs, includes, and CMake scripts" OFF)
option(BOX2D_BUILD_EXAMPLES "Build Box2D examples" OFF)
add_subdirectory("${MOAI_SOURCE_DIR}/3rdparty/box2d-2.2.1" box2d-2.2.1)

add_subdirectory(contrib)
add_subdirectory(tlsf-2.0)

add_subdirectory(untz)
