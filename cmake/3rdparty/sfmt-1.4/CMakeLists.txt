moai_set_local_source_dir()

add_library(sfmt-1.4 STATIC
    "${local_source_dir}/SFMT-alti.h"
    "${local_source_dir}/SFMT-common.h"
    "${local_source_dir}/SFMT-params.h"
    "${local_source_dir}/SFMT-params11213.h"
    "${local_source_dir}/SFMT-params1279.h"
    "${local_source_dir}/SFMT-params132049.h"
    "${local_source_dir}/SFMT-params19937.h"
    "${local_source_dir}/SFMT-params216091.h"
    "${local_source_dir}/SFMT-params2281.h"
    "${local_source_dir}/SFMT-params4253.h"
    "${local_source_dir}/SFMT-params44497.h"
    "${local_source_dir}/SFMT-params607.h"
    "${local_source_dir}/SFMT-params86243.h"
    "${local_source_dir}/SFMT-sse2.h"
    "${local_source_dir}/SFMT.c"
    "${local_source_dir}/SFMT.h"
)

