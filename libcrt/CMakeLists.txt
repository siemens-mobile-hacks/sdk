cmake_minimum_required(VERSION 3.31)

include(../config.cmake)
project(libcrt C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_library(crt STATIC
	main.c
	__cxa_atexit.cpp
)
target_sdk_setup(crt NSG)
target_compile_definitions(crt PRIVATE __NO_LIBC)
target_compile_options(crt PRIVATE
	-Werror
	$<$<COMPILE_LANGUAGE:C>:-Wno-missing-prototypes>
)

install_sdk_target(crt lib)
