cmake_minimum_required(VERSION 3.31)

include(../config.cmake)
project(libz C)
set(CMAKE_C_STANDARD 99)

add_library(z SHARED
	src/adler32.c
	src/compress.c
	src/crc32.c
	src/deflate.c
	src/gzclose.c
	src/gzlib.c
	src/gzread.c
	src/gzwrite.c
	src/infback.c
	src/inffast.c
	src/inflate.c
	src/inftrees.c
	src/trees.c
	src/uncompr.c
	src/zutil.c
)
target_sdk_setup(z NSG)
target_sdk_set_lib_name(z z 1.2.5)
target_include_directories(z BEFORE PRIVATE src)
target_compile_options(z PRIVATE -mthumb -Werror -Wno-implicit-fallthrough)
target_link_libraries(z PRIVATE crt_helper gcc c)
set_target_properties(z PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

install_sdk_target(z lib)
