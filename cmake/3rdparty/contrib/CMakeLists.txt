moai_set_local_source_dir()

add_library(utf8 STATIC
    "${local_source_dir}/utf8.c"
    "${local_source_dir}/utf8.h"
)

add_library(whirlpool STATIC
    "${local_source_dir}/whirlpool.c"
    "${local_source_dir}/whirlpool.h"
)


