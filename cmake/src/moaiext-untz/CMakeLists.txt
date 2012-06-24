moai_set_local_source_dir()

add_library(moaiext-untz STATIC
    "${local_source_dir}/MOAIUntzSystem.h"
    "${local_source_dir}/MOAIUntzSystem.cpp"
    "${local_source_dir}/MOAIUntzSound.h"
    "${local_source_dir}/MOAIUntzSound.cpp"
    "${local_source_dir}/MOAIUntzSampleBuffer.h"
    "${local_source_dir}/MOAIUntzSampleBuffer.cpp"
)

target_link_libraries(moaiext-untz
    untz
)
