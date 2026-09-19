cmake_minimum_required(VERSION 3.31)

include(../config.cmake)
project(libpng VERSION 12 LANGUAGES C)
set(CMAKE_C_STANDARD 99)

add_library(png SHARED
	src/png.c
	src/pngerror.c
	src/pnggccrd.c
	src/pngget.c
	src/pngmem.c
	src/pngpread.c
	src/pngread.c
	src/pngrio.c
	src/pngrtran.c
	src/pngrutil.c
	src/pngset.c
	src/pngtrans.c
	src/pngvcrd.c
	src/pngwio.c
	src/pngwrite.c
	src/pngwtran.c
	src/pngwutil.c
)
target_sdk_setup(png NSG)
target_sdk_set_lib_name(png png "${PROJECT_VERSION}")
target_include_directories(png BEFORE PRIVATE src)
target_compile_options(png PRIVATE -mthumb -Werror -Wno-implicit-fallthrough -Wno-dangling-pointer)
target_link_libraries(png PRIVATE crt_helper gcc c m z)
set_target_properties(png PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

install_sdk_target(png lib)

epk_install(TARGET png DESTINATION ZBin/lib)
epk_package(TARGET png NAME libpng
	PLATFORMS all
	DEPENDS libcrt_helper libc=1.0 libm=1.0 libz=1.2.5
)
