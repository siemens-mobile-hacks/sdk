cmake_minimum_required(VERSION 3.31)

set(CXX_TYPE libcxx)
include(../config.cmake)
project(libft_server CXX)
set(CMAKE_CXX_STANDARD 11)

add_library(ft_server SHARED
	src/main.cpp
	src/ft_engine.cpp
)
target_sdk_setup(ft_server NSG)
target_sdk_set_lib_name(ft_server ft_server)
target_compile_options(ft_server PRIVATE
	-mthumb
	-Werror
	-Wno-address
	-Wno-dangling-pointer
	-fvisibility-inlines-hidden
)
target_link_libraries(ft_server PRIVATE crt_helper gcc c c++ supc++ m ft)
set_target_properties(ft_server PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

install_sdk_target(ft_server lib)
