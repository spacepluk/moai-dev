moai_set_local_source_dir()

add_library(aku STATIC
    "${local_source_dir}/AKU.cpp"
    "${local_source_dir}/AKU.h"
    "${local_source_dir}/AKU-untz.cpp"
    "${local_source_dir}/AKU.h"
)

target_link_libraries(aku
    zlcore
    moaicore
    moaiext-untz
    uslscore
)
