moai_set_local_source_dir()

add_library(zlcore STATIC
    "${local_source_dir}/ZLFileSystem.cpp"
    "${local_source_dir}/zl_vfscanf.cpp"
    "${local_source_dir}/zl_replace_new_delete.h"
    "${local_source_dir}/ZLFile.h"
    "${local_source_dir}/zl_util.cpp"
    "${local_source_dir}/ZLFileSystem.h"
    "${local_source_dir}/zl_mutex.cpp"
    "${local_source_dir}/ZLZipStream.h"
    "${local_source_dir}/ZLZipArchive.h"
    "${local_source_dir}/ZLDirectoryItr.cpp"
    "${local_source_dir}/pch.h"
    "${local_source_dir}/ZLZipArchive.cpp"
    "${local_source_dir}/ZLZipStream.cpp"
    "${local_source_dir}/zl_replace_locale.h"
    "${local_source_dir}/zl_replace_stdlib.h"
    "${local_source_dir}/zl_util.h"
    "${local_source_dir}/zlcore-pch.cpp"
    "${local_source_dir}/ZLVirtualPath.cpp"
    "${local_source_dir}/zlcore.h"
    "${local_source_dir}/zl_mutex.h"
    "${local_source_dir}/zl_replace_stdio.h"
    "${local_source_dir}/zlcore.cpp"
    "${local_source_dir}/ZLFile.cpp"
    "${local_source_dir}/ZLDirectoryItr.h"
    "${local_source_dir}/ZLVirtualPath.h"
    "${local_source_dir}/zl_replace.h"
)

target_link_libraries(zlcore
    tlsf
)

