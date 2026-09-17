cmake_minimum_required(VERSION 3.31)

set(CXX_TYPE none)
include(../config.cmake)
project(libsupcxx CXX)
set(CMAKE_CXX_STANDARD 11)

add_library(supc++ STATIC
	src/si_class_type_info.cc
	src/nested_exception.cc
	src/eh_catch.cc
	src/guard_error.cc
	src/enum_type_info.cc
	src/dyncast.cc
	src/new_opvnt.cc
	src/eh_aux_runtime.cc
	src/vec.cc
	src/bad_cast.cc
	src/tinfo.cc
	src/eh_terminate.cc
	src/pointer_type_info.cc
	src/bad_alloc.cc
	src/eh_type.cc
	src/tinfo2.cc
	src/guard.cc
	src/new_handler.cc
	src/new_opv.cc
	src/vmi_class_type_info.cc
	src/eh_throw.cc
	src/eh_term_handler.cc
	src/eh_unex_handler.cc
	src/pure.cc
	src/eh_exception.cc
	src/del_opv.cc
	src/del_opvnt.cc
	src/fundamental_type_info.cc
	src/eh_globals.cc
	src/new_op.cc
	src/class_type_info.cc
	src/eh_arm.cc
	src/array_type_info.cc
	src/vterminate.cc
	src/pbase_type_info.cc
	src/bad_typeid.cc
	src/eh_alloc.cc
	src/del_op.cc
	src/pmem_type_info.cc
	src/eh_call.cc
	src/new_opnt.cc
	src/function_type_info.cc
	src/eh_personality.cc
	src/atexit_arm.cc
	src/hash_bytes.cc
	src/del_opnt.cc
	src/eh_ptr.cc
)
target_sdk_setup(supc++ NSG)
target_compile_definitions(supc++ PRIVATE __NO_LIBC)
target_include_directories(supc++ BEFORE PRIVATE include src ../libc++/include)
target_compile_options(supc++ PRIVATE
	-mthumb
	-Wall
	-Wno-unused-but-set-variable
	-fvisibility-inlines-hidden
	-O2
)

install_sdk_target(supc++ lib)
