cmake_minimum_required(VERSION 2.8)

project(MOAI)

# Override MOAI_SOURCE_DIR set by project(MOAI)
set(MOAI_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/..")

# Define a helper function to find source directories
function(moai_set_local_source_dir)
    file(RELATIVE_PATH local_source_dir "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
    file(RELATIVE_PATH local_source_dir "${CMAKE_CURRENT_SOURCE_DIR}" "${MOAI_SOURCE_DIR}/${local_source_dir}")
    set(local_source_dir "${local_source_dir}" PARENT_SCOPE)
endfunction(moai_set_local_source_dir)

add_subdirectory(3rdparty)
add_subdirectory(src)

