set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR ARM)

get_filename_component(SDK_PATH ${CMAKE_CURRENT_LIST_DIR} ABSOLUTE)
set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)
set_property(GLOBAL PROPERTY NO_SONAME TRUE)

# -----------------------------------------------
# Settings
# -----------------------------------------------

# Custom toolchain
if (NOT DEFINED TOOLCHAIN)
	set(TOOLCHAIN "arm-none-eabi")
endif()

# Source files encoding
if (NOT DEFINED SOURCE_ENCODING)
	set(SOURCE_ENCODING "utf-8")
endif()

# C++ variant: libcxx or uclibc++
if (NOT DEFINED CXX_TYPE)
	set(CXX_TYPE "libcxx")
endif()

# -----------------------------------------------
# Toolchain
# -----------------------------------------------
if (CMAKE_SYSTEM MATCHES Windows)
    set(TOOLCHAIN_EXT ".exe")
else()
    set(TOOLCHAIN_EXT "")
endif()

set(CMAKE_EXECUTABLE_SUFFIX ".elf")
set(ENV{SOURCE_DATE_EPOCH} 1172750400)

set(CMAKE_C_COMPILER ${TOOLCHAIN}-gcc${TOOLCHAIN_EXT})
set(CMAKE_CXX_COMPILER ${TOOLCHAIN}-g++${TOOLCHAIN_EXT})
set(CMAKE_ASM_COMPILER ${TOOLCHAIN}-gcc${TOOLCHAIN_EXT})

function(target_sdk_setup target platform)
	set_property(TARGET ${target} PROPERTY POSITION_INDEPENDENT_CODE OFF)
	get_target_property(target_type ${target} TYPE)
	
	if (target_type STREQUAL "EXECUTABLE")
		set_property(TARGET ${target} PROPERTY SUFFIX ".elf")
	endif()
	
	file(MAKE_DIRECTORY "${PROJECT_BINARY_DIR}/lib/ELKA" "${PROJECT_BINARY_DIR}/lib/NSG" "${PROJECT_BINARY_DIR}/lib/SG")
	
	if (platform STREQUAL "SG" OR platform STREQUAL "SGOLD")
		message("Compiling for target SGOLD")
		target_compile_definitions(${target} PUBLIC SGOLD)
		target_link_directories(${target} PUBLIC ${SDK_PATH}/lib/SG ${SDK_PATH}/lib)
		set(LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib/SG")
		set_target_properties(${target} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib/SG")
	elseif (platform STREQUAL "NSG" OR platform STREQUAL "NEWSGOLD")
		message("Compiling for target NEWSGOLD")
		target_compile_definitions(${target} PUBLIC NEWSGOLD)
		target_link_directories(${target} PUBLIC ${SDK_PATH}/lib/NSG ${SDK_PATH}/lib)
		set(LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib/NSG")
		set_target_properties(${target} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib/NSG")
	elseif (platform STREQUAL "EL" OR platform STREQUAL "ELKA")
		message("Compiling for target ELKA")
		target_compile_definitions(${target} PUBLIC NEWSGOLD ELKA)
		target_link_directories(${target} PUBLIC ${SDK_PATH}/lib/ELKA ${SDK_PATH}/lib/NSG ${SDK_PATH}/lib)
		set(LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib/ELKA")
		set_target_properties(${target} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib/ELKA")
	else()
		message(FATAL "Invalid platform: ${platform}")
	endif()
endfunction()

function(target_sdk_set_lib_name target name version)
	set_target_properties(${target} PROPERTIES NO_SONAME TRUE)
	set_target_properties(${target} PROPERTIES LIBRARY_OUTPUT_NAME ${name})
	target_link_options(${target} PUBLIC "-Wl,--soname,lib${name}.so")
endfunction()

# -----------------------------------------------
# Include dirs
# -----------------------------------------------
if (CXX_TYPE STREQUAL "uclibc++")
	include_directories(${SDK_PATH}/libuc++/include)
elseif (CXX_TYPE STREQUAL "libcxx")
	include_directories(${SDK_PATH}/libc++abi/include)
	include_directories(${SDK_PATH}/libc++/include)
else()
	message(FATAL "Invalid CXX_TYPE: ${CXX_TYPE}")
endif()

include_directories(${SDK_PATH}/include)
include_directories(${SDK_PATH}/libgcc/include)
include_directories(${SDK_PATH}/dietlibc/include)
include_directories(${SDK_PATH}/libjpeg/include)
include_directories(${SDK_PATH}/libpng/include)
include_directories(${SDK_PATH}/libsigc++/include)
include_directories(${SDK_PATH}/libft/include)
include_directories(${SDK_PATH}/libft_server/include)
include_directories(${SDK_PATH}/libz/include)

# -----------------------------------------------
# Common
# -----------------------------------------------
set(SDK_COMMON_LDFLAGS "-Wl,-zmax-page-size=1 -Wl,--defsym=__dso_handle=0")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(SDK_COMMON_LDFLAGS "${SDK_COMMON_LDFLAGS} -g")
else()
	set(SDK_COMMON_LDFLAGS "${SDK_COMMON_LDFLAGS} -s")
endif()

set(SDK_COMMON_CFLAGS "-msoft-float -fshort-wchar -mlittle-endian -mcpu=arm926ej-s -mthumb-interwork")
set(SDK_COMMON_CFLAGS "${SDK_COMMON_CFLAGS} -fno-builtin -nodefaultlibs -nostdlib -nostdinc")
set(SDK_COMMON_CFLAGS "${SDK_COMMON_CFLAGS} -fno-common -ffunction-sections -fdata-sections")
set(SDK_COMMON_CFLAGS "${SDK_COMMON_CFLAGS} -frandom-seed=0")
set(SDK_COMMON_CFLAGS "${SDK_COMMON_CFLAGS} -g")

if (NOT SOURCE_ENCODING STREQUAL "cp1251" AND NOT SOURCE_ENCODING STREQUAL "native")
	set(SDK_COMMON_CFLAGS "${SDK_COMMON_CFLAGS} -finput-charset=${SOURCE_ENCODING} -fexec-charset=cp1251")
endif()

set(CMAKE_C_FLAGS "${SDK_COMMON_CFLAGS}")
set(CMAKE_CXX_FLAGS "${SDK_COMMON_CFLAGS} -nostdinc++ -fno-enforce-eh-specs -fno-use-cxa-get-exception-ptr -fno-non-call-exceptions -fno-exceptions -fpermissive")
set(CMAKE_ASM_FLAGS "${SDK_COMMON_CFLAGS}")

add_compile_definitions(__arm__ __ARM_EABI__)

# -----------------------------------------------
# Shared library
# -----------------------------------------------
set(CMAKE_SHARED_LINKER_FLAGS "${SDK_COMMON_LDFLAGS} -Wl,-shared -Wl,-Bsymbolic -Wl,-Bsymbolic-function")
set(CMAKE_MODULE_LINKER_FLAGS "${SDK_COMMON_LDFLAGS} -Wl,-shared -Wl,-Bsymbolic -Wl,-Bsymbolic-function")

# -----------------------------------------------
# Static library
# -----------------------------------------------
set(CMAKE_STATIC_LINKER_FLAGS "${SDK_COMMON_LDFLAGS} -ar rcsD")

# -----------------------------------------------
# Executable
# -----------------------------------------------
set(CMAKE_EXE_LINKER_FLAGS "${SDK_COMMON_LDFLAGS} -pie")
