include_guard(GLOBAL)

get_filename_component(SDK_PATH "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)

include("${SDK_PATH}/cmake/EpkPackage.cmake")

set(CMAKE_BUILD_TYPE MinSizeRel CACHE STRING "Build type")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "Generate compile_commands.json")

if(NOT CMAKE_TOOLCHAIN_FILE)
	set(CMAKE_TOOLCHAIN_FILE "${SDK_PATH}/cmake/toolchain.cmake" CACHE FILEPATH "Siemens SDK toolchain")
endif()

if(NOT DEFINED SOURCE_ENCODING)
	set(SOURCE_ENCODING utf-8 CACHE STRING "Source file encoding")
endif()

if(NOT DEFINED OUTPUT_ENCODING)
	set(OUTPUT_ENCODING cp1251 CACHE STRING "Target string literal encoding")
endif()

if(NOT DEFINED CXX_TYPE)
	set(CXX_TYPE libcxx CACHE STRING "C++ library: libcxx, uclibc++, or none")
endif()

set(_SDK_INCLUDE_DIRS
	"${SDK_PATH}/libsupc++/include"
	"${SDK_PATH}/include"
	"${SDK_PATH}/swilib/include"
	"${SDK_PATH}/libgcc/include"
	"${SDK_PATH}/dietlibc/include"
	"${SDK_PATH}/libjpeg/include"
	"${SDK_PATH}/libpng/include"
	"${SDK_PATH}/libsigc++/include"
	"${SDK_PATH}/libft/include"
	"${SDK_PATH}/libft_server/include"
	"${SDK_PATH}/libz/include"
)

# Debug information is always split from .so/.elf files into separate .dbg files.
add_compile_options(-g)

if(NOT SOURCE_ENCODING STREQUAL "cp1251" AND NOT SOURCE_ENCODING STREQUAL "native")
	add_compile_options(
		"-finput-charset=${SOURCE_ENCODING}"
		"-fexec-charset=${OUTPUT_ENCODING}"
	)
endif()

include_directories(${_SDK_INCLUDE_DIRS})
link_directories(
	"${SDK_PATH}/lib/stubs"
	"${SDK_PATH}/lib"
)

function(target_sdk_setup target platform)
	if(CXX_TYPE STREQUAL "libcxx")
		target_include_directories("${target}" BEFORE PRIVATE "${SDK_PATH}/libc++/include")
	elseif(CXX_TYPE STREQUAL "uclibc++")
		target_include_directories("${target}" BEFORE PRIVATE "${SDK_PATH}/libuc++/include")
	elseif(NOT CXX_TYPE STREQUAL "none")
		message(FATAL_ERROR "Invalid CXX_TYPE: ${CXX_TYPE}")
	endif()

	if(platform STREQUAL "SG" OR platform STREQUAL "SGOLD")
		set(_SDK_PLATFORM "SG")
		target_compile_definitions("${target}" PRIVATE SGOLD)
	elseif(platform STREQUAL "SG_X75" OR platform STREQUAL "X75")
		set(_SDK_PLATFORM "X75")
		target_compile_definitions("${target}" PRIVATE X75)
	elseif(platform STREQUAL "NSG" OR platform STREQUAL "NEWSGOLD")
		set(_SDK_PLATFORM "NSG")
		target_compile_definitions("${target}" PRIVATE NEWSGOLD)
	elseif(platform STREQUAL "NSG_ELKA" OR platform STREQUAL "ELKA")
		set(_SDK_PLATFORM "ELKA")
		target_compile_definitions("${target}" PRIVATE NEWSGOLD ELKA)
	else()
		message(FATAL_ERROR "Invalid platform: ${platform}")
	endif()
	set_target_properties("${target}" PROPERTIES
		SDK_ARCH "siemens-sgold"
		SDK_PLATFORM "${_SDK_PLATFORM}"
	)

	set(_SDK_PLATFORM_LINK_DIRS "${SDK_PATH}/lib/${_SDK_PLATFORM}")
	if(_SDK_PLATFORM STREQUAL "ELKA")
		list(APPEND _SDK_PLATFORM_LINK_DIRS "${SDK_PATH}/lib/NSG")
	elseif(_SDK_PLATFORM STREQUAL "X75")
		list(APPEND _SDK_PLATFORM_LINK_DIRS "${SDK_PATH}/lib/SG")
	endif()

	target_link_directories("${target}" BEFORE PRIVATE ${_SDK_PLATFORM_LINK_DIRS})
	set_target_properties("${target}" PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib/${_SDK_PLATFORM}"
		LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib/${_SDK_PLATFORM}"
	)
	target_sdk_postprocess("${target}")
endfunction()

function(target_sdk_postprocess target)
	get_target_property(_SDK_TARGET_TYPE "${target}" TYPE)

	if(_SDK_TARGET_TYPE STREQUAL "STATIC_LIBRARY")
		return()
	endif()

	if(_SDK_TARGET_TYPE STREQUAL "EXECUTABLE")
		target_compile_options("${target}" PRIVATE -fvisibility=hidden -Wno-main)
	endif()

	set(_SDK_DEBUG_FILE
		"$<TARGET_FILE_DIR:${target}>/$<TARGET_FILE_PREFIX:${target}>$<TARGET_FILE_BASE_NAME:${target}>.dbg")

	add_custom_command(TARGET "${target}" POST_BUILD
		COMMAND "${CMAKE_OBJCOPY}" --only-keep-debug
			"$<TARGET_FILE:${target}>" "${_SDK_DEBUG_FILE}"
		VERBATIM
	)

	if(_SDK_TARGET_TYPE STREQUAL "EXECUTABLE")
		add_custom_command(TARGET "${target}" POST_BUILD
			COMMAND "${CMAKE_STRIP}" -R .ARM.attributes --strip-all
				"$<TARGET_FILE:${target}>"
			VERBATIM
		)
	else()
		add_custom_command(TARGET "${target}" POST_BUILD
			COMMAND "${CMAKE_STRIP}" --strip-all "$<TARGET_FILE:${target}>"
			VERBATIM
		)
	endif()

	add_custom_command(TARGET "${target}" POST_BUILD
		COMMAND "${CMAKE_OBJCOPY}" "--add-gnu-debuglink=${_SDK_DEBUG_FILE}"
			"$<TARGET_FILE:${target}>"
		VERBATIM
	)
endfunction()

function(target_sdk_set_lib_name target name)
	set(_SDK_OUTPUT_NAME "${name}")
	if(ARGC GREATER 2)
		set(_SDK_OUTPUT_NAME "${name}-${ARGV2}")
	endif()

	set_target_properties("${target}" PROPERTIES
		NO_SONAME TRUE
		OUTPUT_NAME "${_SDK_OUTPUT_NAME}"
	)
	target_link_options("${target}" PRIVATE "-Wl,-soname,lib${_SDK_OUTPUT_NAME}.so")

	if(ARGC GREATER 2)
		if(ARGC GREATER 3)
			set(_SDK_SYMLINK_NAME "${ARGV3}")
		else()
			set(_SDK_SYMLINK_NAME "${name}")
		endif()
		add_custom_command(TARGET "${target}" POST_BUILD
			COMMAND "${CMAKE_COMMAND}" -E create_symlink
				"$<TARGET_FILE_NAME:${target}>" "$<TARGET_FILE_DIR:${target}>/lib${_SDK_SYMLINK_NAME}.so"
			VERBATIM
		)
		set_property(TARGET "${target}" PROPERTY SDK_SYMLINK_NAME "lib${_SDK_SYMLINK_NAME}.so")
	endif()
endfunction()

function(install_sdk_target target destination)
	get_target_property(_SDK_TARGET_TYPE "${target}" TYPE)
	if(_SDK_TARGET_TYPE STREQUAL "STATIC_LIBRARY")
		install(TARGETS "${target}" ARCHIVE DESTINATION "${destination}")
		return()
	endif()

	install(TARGETS "${target}" LIBRARY DESTINATION "${destination}")
	install(FILES
		"$<TARGET_FILE_DIR:${target}>/$<TARGET_FILE_PREFIX:${target}>$<TARGET_FILE_BASE_NAME:${target}>.dbg"
		DESTINATION "${destination}"
	)

	get_target_property(_SDK_SYMLINK_NAME "${target}" SDK_SYMLINK_NAME)
	if(_SDK_SYMLINK_NAME)
		install(FILES "$<TARGET_FILE_DIR:${target}>/${_SDK_SYMLINK_NAME}"
			DESTINATION "${destination}"
		)
	endif()
endfunction()
