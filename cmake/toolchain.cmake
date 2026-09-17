include_guard(GLOBAL)

# Target platform -------------------------------------------------------------

list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")

set(CMAKE_SYSTEM_NAME SiemensELF)
set(CMAKE_SYSTEM_PROCESSOR ARM)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_POSITION_INDEPENDENT_CODE FALSE CACHE BOOL "" FORCE)
set(CMAKE_SKIP_RPATH TRUE CACHE BOOL "" FORCE)
set(ENV{SOURCE_DATE_EPOCH} 1172750400)

# Toolchain executables -------------------------------------------------------

set(TOOLCHAIN arm-none-eabi CACHE STRING "GNU Arm Embedded toolchain prefix")

set(CMAKE_C_COMPILER "${TOOLCHAIN}-gcc")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN}-g++")
set(CMAKE_ASM_COMPILER "${TOOLCHAIN}-gcc")

# Compiler flags --------------------------------------------------------------

set(_SDK_COMMON_FLAGS
	-msoft-float
	-fshort-wchar
	-mlittle-endian
	-mcpu=arm926ej-s
	-mthumb-interwork
	-Qn
	-fno-builtin
	-nodefaultlibs
	-nostdlib
	-nostdinc
	-frandom-seed=0
	-fno-common
	-ffunction-sections
	-fdata-sections
)
list(JOIN _SDK_COMMON_FLAGS " " CMAKE_C_FLAGS_INIT)
list(JOIN _SDK_COMMON_FLAGS " " CMAKE_ASM_FLAGS_INIT)
string(JOIN " " CMAKE_CXX_FLAGS_INIT
	${_SDK_COMMON_FLAGS}
	-nostdinc++
	-fno-enforce-eh-specs
	-fno-use-cxa-get-exception-ptr
	-fno-non-call-exceptions
	-fno-exceptions
	-fpermissive
)

set(CMAKE_C_OUTPUT_EXTENSION_REPLACE TRUE)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE TRUE)
set(CMAKE_ASM_OUTPUT_EXTENSION_REPLACE TRUE)

# Linker flags ----------------------------------------------------------------

set(_SDK_COMMON_LINK_FLAGS
	-nostdlib
	-Wl,--defsym=__dso_handle=0
	-Wl,-zmax-page-size=1
	-Wl,--gc-sections
)
string(JOIN " " CMAKE_EXE_LINKER_FLAGS_INIT
	${_SDK_COMMON_LINK_FLAGS}
	-pie
	-Wl,--no-dynamic-linker
)
string(JOIN " " CMAKE_SHARED_LINKER_FLAGS_INIT
	${_SDK_COMMON_LINK_FLAGS}
	-Wl,-Bsymbolic
	-Wl,-Bsymbolic-function
)
set(CMAKE_MODULE_LINKER_FLAGS_INIT "${CMAKE_SHARED_LINKER_FLAGS_INIT}")

# Static archives -------------------------------------------------------------

foreach(_SDK_LANGUAGE C CXX ASM)
	set(CMAKE_${_SDK_LANGUAGE}_ARCHIVE_CREATE
		"<CMAKE_AR> qcD <TARGET> <LINK_FLAGS> <OBJECTS>")
	set(CMAKE_${_SDK_LANGUAGE}_ARCHIVE_APPEND
		"<CMAKE_AR> qD <TARGET> <LINK_FLAGS> <OBJECTS>")
endforeach()
