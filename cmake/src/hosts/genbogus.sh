#!/bin/sh
parent_dir=`dirname "$1"`
mkdir -p "$parent_dir"
printf '#ifndef _moai_lua_H\n#define moai_lua_H\n\n#define moai_lua_SIZE 0x00000000\n\nunsigned char moai_lua [] = {\n};\n\n#endif\n' > "$1"
