cmake_minimum_required(VERSION 3.31)

include(config.cmake)
project(sdk C CXX ASM)

add_subdirectory(libcrt-static)
add_subdirectory(libcrt)
add_subdirectory(libcrt_helper)

add_subdirectory(dietlibc)
add_subdirectory(libm)
add_subdirectory(libz)
add_subdirectory(libjpeg)
add_subdirectory(libpng)
add_subdirectory(libft)

add_subdirectory(libsupc++)
add_subdirectory(libc++abi)
add_subdirectory(libc++)
add_subdirectory(libuc++)

add_subdirectory(libsigc++)
add_subdirectory(libft_server)
