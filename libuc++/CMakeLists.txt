cmake_minimum_required(VERSION 3.31)

set(CXX_TYPE uclibc++)
include(../config.cmake)
project(libucxx VERSION 1.2.2 LANGUAGES C CXX)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 98)

add_library(ucxx SHARED
	src/abi/cxa/cp-damagle.c
	src/abi/cxa/cxa_atexit.c
	src/abi/abi.cpp
	src/algorithm.cpp
	src/associative_base.cpp
	src/bitset.cpp
	src/char_traits.cpp
	src/complex.cpp
	src/del_op.cpp
	src/del_opnt.cpp
	src/del_opv.cpp
	src/del_opvnt.cpp
	src/deque.cpp
	src/eh_alloc.cpp
	src/eh_globals.cpp
	src/exception.cpp
	src/fstream.cpp
	src/func_exception.cpp
	src/iomanip.cpp
	src/ios.cpp
	src/iostream.cpp
	src/istream.cpp
	src/iterator.cpp
	src/limits.cpp
	src/list.cpp
	src/locale.cpp
	src/map.cpp
	src/new_handler.cpp
	src/new_op.cpp
	src/new_opnt.cpp
	src/new_opv.cpp
	src/new_opvnt.cpp
	src/numeric.cpp
	src/ostream.cpp
	src/queue.cpp
	src/set.cpp
	src/sstream.cpp
	src/stack.cpp
	src/stdexcept.cpp
	src/streambuf.cpp
	src/string.cpp
	src/utility.cpp
	src/valarray.cpp
	src/vector.cpp
)
target_sdk_setup(ucxx NSG)
target_sdk_set_lib_name(ucxx "stdc++" "${PROJECT_VERSION}" "uc++")
target_compile_definitions(ucxx PRIVATE __ARM_EABI_UNWINDER__)
target_include_directories(ucxx BEFORE PRIVATE include src src/include)
target_compile_options(ucxx PRIVATE
	-mthumb
	-Werror
	$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>
)
target_link_libraries(ucxx PRIVATE crt_helper gcc c supc++)
set_target_properties(ucxx PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

install_sdk_target(ucxx lib)

epk_install(TARGET ucxx DESTINATION ZBin/lib)
epk_package(TARGET ucxx NAME libuc++
	PLATFORMS all
	DEPENDS libcrt_helper libc=1.0
)
