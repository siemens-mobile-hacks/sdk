cmake_minimum_required(VERSION 3.13)

project(libgcc NONE)

include(ExternalProject)
include(ProcessorCount)

if(POLICY CMP0135)
	cmake_policy(SET CMP0135 NEW)
endif()

set(GCC_VERSION 13.2.0 CACHE STRING "GCC version used to build libgcc")
set(GCC_URL
	"https://ftp.gnu.org/gnu/gcc/gcc-${GCC_VERSION}/gcc-${GCC_VERSION}.tar.xz"
	CACHE STRING "GCC source archive URL"
)
set(TOOLCHAIN "arm-none-eabi" CACHE STRING "GNU Arm Embedded toolchain prefix")

function(find_target_tool output_name tool_name)
	if(IS_ABSOLUTE "${TOOLCHAIN}")
		set(_LIBGCC_TOOL "${TOOLCHAIN}-${tool_name}")
		if(NOT EXISTS "${_LIBGCC_TOOL}")
			message(FATAL_ERROR "Tool not found: ${_LIBGCC_TOOL}")
		endif()
	else()
		unset(_LIBGCC_TOOL CACHE)
		unset(_LIBGCC_TOOL)
		find_program(_LIBGCC_TOOL NAMES "${TOOLCHAIN}-${tool_name}")
		if(NOT _LIBGCC_TOOL)
			message(FATAL_ERROR "Tool not found: ${TOOLCHAIN}-${tool_name}")
		endif()
	endif()
	set("${output_name}" "${_LIBGCC_TOOL}" PARENT_SCOPE)
endfunction()

find_target_tool(LIBGCC_GCC gcc)
find_target_tool(LIBGCC_AR ar)
find_target_tool(LIBGCC_AS as)
find_target_tool(LIBGCC_LD ld)
find_target_tool(LIBGCC_NM nm)
find_target_tool(LIBGCC_OBJCOPY objcopy)
find_target_tool(LIBGCC_OBJDUMP objdump)
find_target_tool(LIBGCC_RANLIB ranlib)
find_target_tool(LIBGCC_READELF readelf)
find_target_tool(LIBGCC_STRIP strip)

find_program(LIBGCC_MAKE NAMES gmake make)
if(NOT LIBGCC_MAKE)
	message(FATAL_ERROR "GNU Make is required to build libgcc")
endif()

# GCC 13 does not build with every newer host GCC/libstdc++ combination.
# Prefer the newest known-compatible host compiler, but keep it overridable.
find_program(LIBGCC_HOST_CC NAMES gcc-15 gcc-14 gcc-13 gcc)
find_program(LIBGCC_HOST_CXX NAMES g++-15 g++-14 g++-13 g++)
if(NOT LIBGCC_HOST_CC OR NOT LIBGCC_HOST_CXX)
	message(FATAL_ERROR "A host GCC/G++ compiler is required to build GCC ${GCC_VERSION}")
endif()

if(NOT DEFINED LIBGCC_BUILD_JOBS)
	ProcessorCount(LIBGCC_BUILD_JOBS)
	if(NOT LIBGCC_BUILD_JOBS)
		set(LIBGCC_BUILD_JOBS 1)
	endif()
endif()
set(LIBGCC_BUILD_JOBS "${LIBGCC_BUILD_JOBS}" CACHE STRING "Parallel jobs used to build GCC")

set(_LIBGCC_SOURCE_DIR "${CMAKE_BINARY_DIR}/src/gcc-${GCC_VERSION}")
set(_LIBGCC_BUILD_DIR "${CMAKE_BINARY_DIR}/gcc-${GCC_VERSION}-build")
set(_LIBGCC_CACHE_DIR "${CMAKE_BINARY_DIR}/gcc-${GCC_VERSION}-cache")
set(_LIBGCC_INPUT "${_LIBGCC_BUILD_DIR}/gcc/thumb/libgcc.a")
set(_LIBGCC_OUTPUT "${CMAKE_BINARY_DIR}/lib/libgcc.a")
set(_LIBGCC_TARGET_FLAGS
	"-mcpu=arm926ej-s -msoft-float -mlittle-endian -fshort-wchar -mthumb-interwork -frandom-seed=0 -Os"
)
set(_LIBGCC_ENV
	"${CMAKE_COMMAND}" -E env
	"SOURCE_DATE_EPOCH=1172750400"
	"CCACHE_DIR=${_LIBGCC_CACHE_DIR}"
	"CC=${LIBGCC_HOST_CC}"
	"CXX=${LIBGCC_HOST_CXX}"
	"CXXFLAGS=-g -O2 -fno-char8_t"
	"GCC_FOR_TARGET=${LIBGCC_GCC}"
	"AR_FOR_TARGET=${LIBGCC_AR}"
	"AS_FOR_TARGET=${LIBGCC_AS}"
	"LD_FOR_TARGET=${LIBGCC_LD}"
	"NM_FOR_TARGET=${LIBGCC_NM}"
	"OBJCOPY_FOR_TARGET=${LIBGCC_OBJCOPY}"
	"OBJDUMP_FOR_TARGET=${LIBGCC_OBJDUMP}"
	"RANLIB_FOR_TARGET=${LIBGCC_RANLIB}"
	"READELF_FOR_TARGET=${LIBGCC_READELF}"
	"STRIP_FOR_TARGET=${LIBGCC_STRIP}"
	"CFLAGS_FOR_TARGET=${_LIBGCC_TARGET_FLAGS}"
	"LDFLAGS_FOR_TARGET=-zmax-page-size=1"
)

ExternalProject_Add(gcc_runtime
	EXCLUDE_FROM_ALL TRUE
	URL "${GCC_URL}"
	DOWNLOAD_DIR "${CMAKE_BINARY_DIR}/download"
	SOURCE_DIR "${_LIBGCC_SOURCE_DIR}"
	BINARY_DIR "${_LIBGCC_BUILD_DIR}"
	UPDATE_COMMAND ""
	PATCH_COMMAND
		"${CMAKE_COMMAND}" -E chdir <SOURCE_DIR> ./contrib/download_prerequisites
	CONFIGURE_COMMAND
		${_LIBGCC_ENV} <SOURCE_DIR>/configure
			--target=arm-none-eabi
			--disable-decimal-float
			--disable-libffi
			--disable-libgomp
			--disable-libmudflap
			--disable-libquadmath
			--disable-libssp
			--disable-libstdcxx-pch
			--disable-nls
			--disable-shared
			--disable-threads
			--disable-tls
			--enable-long-long
			--without-headers
			--enable-interwork
			--disable-fpu
			--disable-gcov
			--enable-languages=c,c++
	BUILD_COMMAND
		${_LIBGCC_ENV} "${LIBGCC_MAKE}" -j "${LIBGCC_BUILD_JOBS}" all-gcc
		COMMAND ${_LIBGCC_ENV} "${LIBGCC_MAKE}" -j "${LIBGCC_BUILD_JOBS}" all-target-libgcc
	INSTALL_COMMAND ""
	BUILD_BYPRODUCTS "${_LIBGCC_INPUT}"
)

add_custom_command(
	OUTPUT "${_LIBGCC_OUTPUT}"
	COMMAND "${CMAKE_CURRENT_LIST_DIR}/repack.sh"
		"${_LIBGCC_INPUT}"
		"${_LIBGCC_OUTPUT}"
		"${LIBGCC_AR}"
		"${CMAKE_BINARY_DIR}"
	DEPENDS gcc_runtime
	VERBATIM
)
add_custom_target(libgcc DEPENDS "${_LIBGCC_OUTPUT}")

install(FILES "${_LIBGCC_OUTPUT}" DESTINATION lib)
