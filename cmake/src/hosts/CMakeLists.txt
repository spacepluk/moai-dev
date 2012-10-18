moai_set_local_source_dir()

add_definitions(-DGLUTHOST_USE_UNTZ)

# Libraries to link
set(hosts_lib_list
    aku
    moaicore
    utf8
    jansson
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    GLEW
)

# Build main executable
add_executable(moai-untz
    "${local_source_dir}/GlutHost.cpp"
    "${local_source_dir}/GlutHostMain.cpp"
    "${local_source_dir}/../lua-headers/moai_lua.h"

)

target_link_libraries(moai-untz ${hosts_lib_list})
