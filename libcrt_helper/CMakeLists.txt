cmake_minimum_required(VERSION 3.31)

include(../config.cmake)
project(libcrt_helper C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(SOURCES
	main.c
	switab.c
	__cxa_atexit.cpp
)

function(add_crt_helper target output_directory)
	add_library("${target}" SHARED ${SOURCES})
	target_sdk_setup("${target}" NSG)
	target_sdk_set_lib_name("${target}" crt_helper)
	target_compile_definitions("${target}" PRIVATE __NO_LIBC ${ARGN})
	target_compile_options("${target}" PRIVATE
		-Werror
		-Wno-array-bounds
		-marm
		$<$<COMPILE_LANGUAGE:C>:-Wno-missing-prototypes>
	)
	target_link_options("${target}" PRIVATE -Wl,--init=libcrt_helper_init)
	set_target_properties("${target}" PROPERTIES
		LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/${output_directory}"
	)
endfunction()

add_crt_helper(crt_helper_runtime lib)
add_crt_helper(crt_helper lib/stubs LIBCRT_STUBS)

install_sdk_target(crt_helper_runtime lib)
install_sdk_target(crt_helper lib/stubs)
