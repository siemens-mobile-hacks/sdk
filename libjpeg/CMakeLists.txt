cmake_minimum_required(VERSION 3.31)

include(../config.cmake)
project(libjpeg VERSION 62 LANGUAGES C)
set(CMAKE_C_STANDARD 99)

add_library(jpeg SHARED
	src/jaricom.c
	src/jcapimin.c
	src/jcapistd.c
	src/jcarith.c
	src/jccoefct.c
	src/jccolor.c
	src/jcdctmgr.c
	src/jchuff.c
	src/jcinit.c
	src/jcmainct.c
	src/jcmarker.c
	src/jcmaster.c
	src/jcomapi.c
	src/jcparam.c
	src/jcprepct.c
	src/jcsample.c
	src/jctrans.c
	src/jdapimin.c
	src/jdapistd.c
	src/jdarith.c
	src/jdatadst.c
	src/jdatasrc.c
	src/jdcoefct.c
	src/jdcolor.c
	src/jddctmgr.c
	src/jdhuff.c
	src/jdinput.c
	src/jdmainct.c
	src/jdmarker.c
	src/jdmaster.c
	src/jdmerge.c
	src/jdpostct.c
	src/jdsample.c
	src/jdtrans.c
	src/jerror.c
	src/jfdctflt.c
	src/jfdctfst.c
	src/jfdctint.c
	src/jidctflt.c
	src/jidctfst.c
	src/jidctint.c
	src/jmemmgr.c
	src/jmemname.c
	src/jquant1.c
	src/jquant2.c
	src/jutils.c
	src/transupp.c
)
target_sdk_setup(jpeg NSG)
target_sdk_set_lib_name(jpeg jpeg "${PROJECT_VERSION}")
target_include_directories(jpeg BEFORE PRIVATE src)
target_include_directories(jpeg SYSTEM BEFORE PRIVATE include/jpeglib)
target_compile_options(jpeg PRIVATE -mthumb -Werror -Wno-implicit-fallthrough)
target_link_libraries(jpeg PRIVATE crt_helper gcc c)
set_target_properties(jpeg PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

install_sdk_target(jpeg lib)

epk_install(TARGET jpeg DESTINATION ZBin/lib)
epk_package(TARGET jpeg NAME libjpeg
	PLATFORMS all
	DEPENDS libcrt_helper libc=1.0
)
