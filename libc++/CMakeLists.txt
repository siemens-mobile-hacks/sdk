cmake_minimum_required(VERSION 3.31)

set(CXX_TYPE libcxx)
include(../config.cmake)
project(libcxx VERSION 1.0 LANGUAGES C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_library(c++ SHARED
	src/abi/cxa_atexit.c
	src/memory.cpp
	src/string.cpp
	src/future.cpp
	src/algorithm.cpp
	src/chrono.cpp
	src/valarray.cpp
	src/variant.cpp
	src/new.cpp
	src/utility.cpp
	src/typeinfo.cpp
	src/stdexcept.cpp
	src/hash.cpp
	src/bind.cpp
	src/system_error.cpp
	src/any.cpp
	src/optional.cpp
	src/exception.cpp
	src/vector.cpp
)
target_sdk_setup(c++ NSG)
target_sdk_set_lib_name(c++ "c++" "${PROJECT_VERSION}")
target_compile_definitions(c++ PRIVATE _LIBCPP_BUILDING_LIBRARY LIBCXX_BUILDING_LIBCXXABI)
target_include_directories(c++ SYSTEM BEFORE PRIVATE src)
target_compile_options(c++ PRIVATE
	$<$<COMPILE_LANGUAGE:CXX>:-mthumb>
)
target_link_libraries(c++ PRIVATE crt_helper supc++ gcc c)
set_target_properties(c++ PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

install_sdk_target(c++ lib)

epk_install(TARGET c++ DESTINATION ZBin/lib)
epk_package(TARGET c++ NAME libc++
	PLATFORMS all
	DEPENDS libcrt_helper libc=1.0
)
