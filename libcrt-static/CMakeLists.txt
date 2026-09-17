cmake_minimum_required(VERSION 3.31)

include(../config.cmake)
project(libcrt-static C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_library(crt-static STATIC
	main.c
	__cxa_atexit.cpp
)
target_sdk_setup(crt-static NSG)
target_compile_definitions(crt-static PRIVATE __NO_LIBC)
target_compile_options(crt-static PRIVATE
	-Werror
	$<$<COMPILE_LANGUAGE:C>:-Wno-missing-prototypes>
)

install_sdk_target(crt-static lib)
