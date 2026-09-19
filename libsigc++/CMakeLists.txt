cmake_minimum_required(VERSION 3.31)

set(CXX_TYPE libcxx)
include(../config.cmake)
project(libsigc VERSION 2.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

add_library(sigc SHARED
	src/connection.cc
	src/signal.cc
	src/signal_base.cc
	src/slot.cc
	src/slot_base.cc
	src/trackable.cc
)
target_sdk_setup(sigc NSG)
target_sdk_set_lib_name(sigc sigc "${PROJECT_VERSION}")
target_compile_options(sigc PRIVATE
	-mthumb
	-Wall
	-Werror
	-Wno-unused-but-set-variable
	-fvisibility-inlines-hidden
)
target_link_libraries(sigc PRIVATE crt_helper gcc c c++ supc++)
set_target_properties(sigc PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

install_sdk_target(sigc lib)

epk_install(TARGET sigc DESTINATION ZBin/lib)
epk_package(TARGET sigc NAME libsigc++
	PLATFORMS all
	DEPENDS libcrt_helper libc=1.0 libc++=1.0
)
