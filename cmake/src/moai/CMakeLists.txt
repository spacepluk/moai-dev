moai_set_local_source_dir()

add_executable(moai
    "${local_source_dir}/main.cpp"
)

target_link_libraries(moai
    aku
)
