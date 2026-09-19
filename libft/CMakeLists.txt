cmake_minimum_required(VERSION 3.31)

include(../config.cmake)
project(libft VERSION 2.4.6 LANGUAGES C)
set(CMAKE_C_STANDARD 11)

add_library(ft SHARED
	main.c
	src/autofit/afangles.c
	src/autofit/afcjk.c
	src/autofit/afdummy.c
	src/autofit/afglobal.c
	src/autofit/afhints.c
	src/autofit/afindic.c
	src/autofit/aflatin.c
	src/autofit/afloader.c
	src/autofit/afmodule.c
	src/autofit/afpic.c
	src/autofit/afwarp.c
	src/base/ftbase.c
	src/base/ftbitmap.c
	src/base/ftglyph.c
	src/base/ftinit.c
	src/base/ftsystem.c
	src/type1/type1.c
	src/raster/raster.c
	src/sfnt/sfnt.c
	src/smooth/smooth.c
	src/truetype/truetype.c
)
target_sdk_setup(ft NSG)
target_sdk_set_lib_name(ft ft 2.4.6-1)
target_compile_options(ft PRIVATE -mthumb -Werror -Wno-address -Wno-dangling-pointer)
target_link_libraries(ft PRIVATE crt_helper gcc c)
set_target_properties(ft PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

install_sdk_target(ft lib)

epk_install(TARGET ft DESTINATION ZBin/lib)
epk_package(TARGET ft NAME libft
	RELEASE 1
	PLATFORMS all
	DEPENDS libcrt_helper libc=1.0
)
