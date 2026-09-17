cmake_minimum_required(VERSION 3.31)

set(CXX_TYPE libcxx)
include(../config.cmake)
project(libcxxabi CXX)
set(CMAKE_CXX_STANDARD 11)

add_library(cxxabi STATIC
	src/cxa_aux_runtime.cpp
	src/cxa_default_handlers.cpp
	src/cxa_demangle.cpp
	src/cxa_exception_storage.cpp
	src/cxa_guard.cpp
	src/cxa_handlers.cpp
	src/cxa_new_delete.cpp
	src/cxa_unexpected.cpp
	src/cxa_vector.cpp
	src/cxa_virtual.cpp
	src/stdlib_exception.cpp
	src/stdlib_stdexcept.cpp
	src/stdlib_typeinfo.cpp
	src/abort_message.cpp
	src/fallback_malloc.cpp
	src/private_typeinfo.cpp
	src/cxa_noexception.cpp
)
set_target_properties(cxxabi PROPERTIES
	OUTPUT_NAME "c++abi"
)
target_sdk_setup(cxxabi NSG)
target_include_directories(cxxabi BEFORE PRIVATE include)
target_include_directories(cxxabi SYSTEM BEFORE PRIVATE src ../libc++/src)
target_compile_options(cxxabi PRIVATE
	-mthumb
	-fvisibility-inlines-hidden
	-fvisibility=hidden
)

install_sdk_target(cxxabi lib)
