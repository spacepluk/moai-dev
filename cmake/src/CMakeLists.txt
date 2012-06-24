find_package(Lua51 REQUIRED)
find_package(CURL REQUIRED)
find_package(Freetype REQUIRED)
find_package(ZLIB REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)

include_directories(
    "${MOAI_SOURCE_DIR}/3rdparty"
    "${MOAI_SOURCE_DIR}/3rdparty/box2d-2.2.1"
    "${MOAI_SOURCE_DIR}/3rdparty/contrib"
    # Private Lua API is used, requiring inclusion of private header lstate.h
    "${MOAI_SOURCE_DIR}/3rdparty/lua-5.1.3/src"
    "${MOAI_SOURCE_DIR}/3rdparty/ooid-0.99"
    "${MOAI_SOURCE_DIR}/3rdparty/tlsf-2.0"
    "${MOAI_SOURCE_DIR}/3rdparty/untz/include"
    "${MOAI_SOURCE_DIR}/src"
    "${MOAI_SOURCE_DIR}/src/config-default"
    "${MOAI_SOURCE_DIR}/src/zipfs"

    ${FREETYPE_INCLUDE_DIRS}
    ${CURL_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
    ${GLUT_INCLUDE_DIRS}
    ${JPEG_INCLUDE_DIRS}
    ${PNG_INCLUDE_DIRS}
)

add_definitions(
    ${PNG_DEFINITIONS}
)

add_subdirectory(zlcore)
add_subdirectory(aku)
add_subdirectory(moaicore)
add_subdirectory(moaiext-untz)
add_subdirectory(uslscore)
add_subdirectory(hosts)

