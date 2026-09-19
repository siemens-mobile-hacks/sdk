include_guard(GLOBAL)

function(_epk_validate_destination destination)
	if("${destination}" STREQUAL ""
		OR destination MATCHES "^/"
		OR destination MATCHES "[;:\\\\]"
		OR destination MATCHES "(^|/)\\.\\.?(/|$)"
		OR destination MATCHES "//")
		message(FATAL_ERROR "Invalid EPK destination: ${destination}")
	endif()
endfunction()

function(_epk_validate_name name)
	if("${name}" STREQUAL "" OR name MATCHES "[;:/\\\\]" OR name STREQUAL "." OR name STREQUAL "..")
		message(FATAL_ERROR "Invalid EPK file name: ${name}")
	endif()
endfunction()

function(_epk_validate_package_name name)
	string(LENGTH "${name}" length)
	if(NOT name MATCHES "^[A-Za-z0-9_+][A-Za-z0-9._+-]*$" OR length GREATER 63)
		message(FATAL_ERROR "Invalid EPK package name: ${name}")
	endif()
endfunction()

function(_epk_absolute_path output path)
	get_filename_component(path "${path}" ABSOLUTE BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
	set("${output}" "${path}" PARENT_SCOPE)
endfunction()

function(epk_install)
	cmake_parse_arguments(PARSE_ARGV 0 EPK
		""
		"TARGET;DESTINATION;RENAME"
		"FILES;DIRECTORIES"
	)

	if(EPK_UNPARSED_ARGUMENTS)
		message(FATAL_ERROR "Unknown epk_install arguments: ${EPK_UNPARSED_ARGUMENTS}")
	endif()

	if(EPK_KEYWORDS_MISSING_VALUES)
		message(FATAL_ERROR "Missing epk_install values: ${EPK_KEYWORDS_MISSING_VALUES}")
	endif()

	if(NOT DEFINED EPK_TARGET OR EPK_TARGET STREQUAL "")
		message(FATAL_ERROR "epk_install requires TARGET")
	endif()

	if(NOT TARGET "${EPK_TARGET}")
		message(FATAL_ERROR "Unknown EPK target: ${EPK_TARGET}")
	endif()

	if(TARGET "${EPK_TARGET}_epk")
		message(FATAL_ERROR "epk_install must be called before epk_package for ${EPK_TARGET}")
	endif()

	if(NOT DEFINED EPK_DESTINATION OR EPK_DESTINATION STREQUAL "")
		message(FATAL_ERROR "epk_install requires DESTINATION")
	endif()

	if(DEFINED EPK_FILES AND DEFINED EPK_DIRECTORIES)
		message(FATAL_ERROR "epk_install accepts either FILES or DIRECTORIES, not both")
	endif()

	string(REGEX REPLACE "/+$" "" EPK_DESTINATION "${EPK_DESTINATION}")
	_epk_validate_destination("${EPK_DESTINATION}")

	if(DEFINED EPK_RENAME)
		_epk_validate_name("${EPK_RENAME}")
	endif()

	get_target_property(_EPK_TARGET_BINARY_DIR "${EPK_TARGET}" BINARY_DIR)
	set(_EPK_DESTINATION "${_EPK_TARGET_BINARY_DIR}/epk/${EPK_TARGET}/root/${EPK_DESTINATION}")
	set(_EPK_COMMANDS COMMAND "${CMAKE_COMMAND}" -E make_directory "${_EPK_DESTINATION}")
	set(_EPK_DEPENDS)

	if(DEFINED EPK_FILES)
		list(LENGTH EPK_FILES _EPK_FILE_COUNT)
		if(DEFINED EPK_RENAME AND NOT _EPK_FILE_COUNT EQUAL 1)
			message(FATAL_ERROR "epk_install RENAME requires exactly one file")
		endif()

		foreach(_EPK_SOURCE IN LISTS EPK_FILES)
			_epk_absolute_path(_EPK_SOURCE "${_EPK_SOURCE}")
			if(DEFINED EPK_RENAME)
				set(_EPK_NAME "${EPK_RENAME}")
			else()
				get_filename_component(_EPK_NAME "${_EPK_SOURCE}" NAME)
			endif()
			_epk_validate_name("${_EPK_NAME}")
			list(APPEND _EPK_COMMANDS
				COMMAND "${CMAKE_COMMAND}" -E copy_if_different
					"${_EPK_SOURCE}" "${_EPK_DESTINATION}/${_EPK_NAME}"
			)
			list(APPEND _EPK_DEPENDS "${_EPK_SOURCE}")
		endforeach()
	elseif(DEFINED EPK_DIRECTORIES)
		if(DEFINED EPK_RENAME)
			message(FATAL_ERROR "epk_install RENAME is not valid with DIRECTORIES")
		endif()

		foreach(_EPK_SOURCE IN LISTS EPK_DIRECTORIES)
			set(_EPK_COPY_CONTENTS FALSE)
			if(_EPK_SOURCE MATCHES "/$")
				set(_EPK_COPY_CONTENTS TRUE)
			endif()
			_epk_absolute_path(_EPK_SOURCE "${_EPK_SOURCE}")
			if(NOT IS_DIRECTORY "${_EPK_SOURCE}")
				message(FATAL_ERROR "EPK payload directory does not exist: ${_EPK_SOURCE}")
			endif()

			if(_EPK_COPY_CONTENTS)
				set(_EPK_DIRECTORY_DESTINATION "${_EPK_DESTINATION}")
			else()
				get_filename_component(_EPK_NAME "${_EPK_SOURCE}" NAME)
				_epk_validate_name("${_EPK_NAME}")
				set(_EPK_DIRECTORY_DESTINATION "${_EPK_DESTINATION}/${_EPK_NAME}")
			endif()

			list(APPEND _EPK_COMMANDS
				COMMAND "${CMAKE_COMMAND}" -E make_directory "${_EPK_DIRECTORY_DESTINATION}"
				COMMAND "${CMAKE_COMMAND}" -E copy_directory
					"${_EPK_SOURCE}" "${_EPK_DIRECTORY_DESTINATION}"
			)
			file(GLOB_RECURSE _EPK_DIRECTORY_DEPENDS
				CONFIGURE_DEPENDS
				LIST_DIRECTORIES TRUE
				"${_EPK_SOURCE}/*"
			)
			list(APPEND _EPK_DEPENDS "${_EPK_SOURCE}" ${_EPK_DIRECTORY_DEPENDS})
		endforeach()
	else()
		if(DEFINED EPK_RENAME)
			set(_EPK_TARGET_DESTINATION "${_EPK_DESTINATION}/${EPK_RENAME}")
		else()
			set(_EPK_TARGET_DESTINATION "${_EPK_DESTINATION}")
		endif()
		list(APPEND _EPK_COMMANDS
			COMMAND "${CMAKE_COMMAND}" -E copy_if_different
				"$<TARGET_FILE:${EPK_TARGET}>" "${_EPK_TARGET_DESTINATION}"
		)
	endif()

	set_property(TARGET "${EPK_TARGET}" APPEND PROPERTY EPK_PACKAGE_COMMANDS ${_EPK_COMMANDS})
	set_property(TARGET "${EPK_TARGET}" APPEND PROPERTY EPK_PACKAGE_DEPENDS ${_EPK_DEPENDS})
endfunction()

function(epk_hook)
	cmake_parse_arguments(PARSE_ARGV 0 EPK "" "TARGET;MODULE" "FIELDS")
	if(EPK_UNPARSED_ARGUMENTS OR EPK_KEYWORDS_MISSING_VALUES)
		message(FATAL_ERROR "Invalid epk_hook arguments")
	endif()
	if(NOT DEFINED EPK_TARGET OR NOT TARGET "${EPK_TARGET}")
		message(FATAL_ERROR "epk_hook requires a valid TARGET")
	endif()
	if(TARGET "${EPK_TARGET}_epk")
		message(FATAL_ERROR "epk_hook must be called before epk_package for ${EPK_TARGET}")
	endif()
	if(NOT DEFINED EPK_MODULE OR NOT EPK_MODULE MATCHES "^[A-Za-z][A-Za-z0-9_-]*$")
		message(FATAL_ERROR "epk_hook requires a valid MODULE")
	endif()
	if(NOT EPK_FIELDS)
		message(FATAL_ERROR "epk_hook requires FIELDS")
	endif()

	foreach(_EPK_FIELD IN LISTS EPK_FIELDS)
		if(NOT _EPK_FIELD MATCHES "^[A-Za-z][A-Za-z0-9_]*=[^,;\r\n]+$")
			message(FATAL_ERROR "Invalid EPK hook field: ${_EPK_FIELD}")
		endif()
	endforeach()

	list(JOIN EPK_FIELDS ", " _EPK_FIELDS)
	set_property(TARGET "${EPK_TARGET}" APPEND PROPERTY EPK_HOOKS "${EPK_MODULE}, ${_EPK_FIELDS}")
endfunction()

function(epk_package)
	cmake_parse_arguments(PARSE_ARGV 0 EPK
		""
		"TARGET;NAME;RELEASE;AUTHOR;DESCRIPTION"
		"PLATFORMS;GROUPS;DEPENDS;CONFLICTS;BACKUPS;OWNED_DIRECTORIES"
	)

	if(EPK_UNPARSED_ARGUMENTS)
		message(FATAL_ERROR "Unknown epk_package arguments: ${EPK_UNPARSED_ARGUMENTS}")
	endif()

	if(EPK_KEYWORDS_MISSING_VALUES)
		message(FATAL_ERROR "Missing epk_package values: ${EPK_KEYWORDS_MISSING_VALUES}")
	endif()

	if(NOT DEFINED EPK_TARGET OR EPK_TARGET STREQUAL "")
		message(FATAL_ERROR "epk_package requires TARGET")
	endif()

	if(NOT TARGET "${EPK_TARGET}")
		message(FATAL_ERROR "Unknown EPK target: ${EPK_TARGET}")
	endif()

	if(TARGET "${EPK_TARGET}_epk")
		message(FATAL_ERROR "epk_package was already called for ${EPK_TARGET}")
	endif()

	_epk_validate_package_name("${EPK_NAME}")

	get_property(_EPK_COMMANDS TARGET "${EPK_TARGET}" PROPERTY EPK_PACKAGE_COMMANDS)

	if(NOT _EPK_COMMANDS)
		message(FATAL_ERROR "epk_package requires epk_install for ${EPK_TARGET}")
	endif()

	get_property(EPK_VERSION TARGET "${EPK_TARGET}" PROPERTY VERSION)
	if("${EPK_VERSION}" STREQUAL "")
		set(EPK_VERSION "${PROJECT_VERSION}")
	endif()

	if(DEFINED EPK_RELEASE)
		if(NOT EPK_RELEASE MATCHES "^[1-9][0-9]*$")
			message(FATAL_ERROR "Invalid EPK release: ${EPK_RELEASE}")
		endif()
		string(APPEND EPK_VERSION "-${EPK_RELEASE}")
	endif()

	string(LENGTH "${EPK_VERSION}" _EPK_VERSION_LENGTH)

	if(NOT EPK_VERSION MATCHES "^[A-Za-z0-9.+~_-]+$" OR _EPK_VERSION_LENGTH GREATER 63)
		message(FATAL_ERROR "epk_package requires a valid target or project version")
	endif()

	get_property(EPK_ARCH TARGET "${EPK_TARGET}" PROPERTY SDK_ARCH)

	string(LENGTH "${EPK_ARCH}" _EPK_ARCH_LENGTH)

	if(NOT EPK_ARCH MATCHES "^[a-z0-9._+:-]+$" OR _EPK_ARCH_LENGTH GREATER 31)
		message(FATAL_ERROR "Invalid EPK architecture: ${EPK_ARCH}")
	endif()

	get_property(_EPK_TARGET_PLATFORM TARGET "${EPK_TARGET}" PROPERTY SDK_PLATFORM)

	if(NOT DEFINED EPK_PLATFORMS)
		if("${_EPK_TARGET_PLATFORM}" STREQUAL "")
			message(FATAL_ERROR "${EPK_TARGET} has no SDK platform")
		endif()
		set(EPK_PLATFORMS "${_EPK_TARGET_PLATFORM}")
	endif()

	list(REMOVE_DUPLICATES EPK_PLATFORMS)
	foreach(_EPK_PLATFORM IN LISTS EPK_PLATFORMS)
		string(LENGTH "${_EPK_PLATFORM}" _EPK_PLATFORM_LENGTH)
		if(NOT _EPK_PLATFORM MATCHES "^[A-Za-z0-9._+-]+$" OR _EPK_PLATFORM_LENGTH GREATER 63)
			message(FATAL_ERROR "Invalid EPK platform: ${_EPK_PLATFORM}")
		endif()
	endforeach()

	set(_EPK_ORDERED_PLATFORMS)
	foreach(_EPK_PLATFORM SG X75 NSG ELKA)
		if(_EPK_PLATFORM IN_LIST EPK_PLATFORMS)
			list(APPEND _EPK_ORDERED_PLATFORMS "${_EPK_PLATFORM}")
			list(REMOVE_ITEM EPK_PLATFORMS "${_EPK_PLATFORM}")
		endif()
	endforeach()

	list(SORT EPK_PLATFORMS)
	list(APPEND _EPK_ORDERED_PLATFORMS ${EPK_PLATFORMS})
	set(EPK_PLATFORMS "${_EPK_ORDERED_PLATFORMS}")

	list(LENGTH EPK_PLATFORMS _EPK_PLATFORM_COUNT)
	if("all" IN_LIST EPK_PLATFORMS)
		if(NOT _EPK_PLATFORM_COUNT EQUAL 1)
			message(FATAL_ERROR "EPK platform cannot mix all with specific platforms")
		endif()
	else()
		if("${_EPK_TARGET_PLATFORM}" STREQUAL "" OR NOT _EPK_TARGET_PLATFORM IN_LIST EPK_PLATFORMS)
			message(FATAL_ERROR "${EPK_TARGET} platform ${_EPK_TARGET_PLATFORM} is not listed in PLATFORMS")
		endif()
	endif()

	list(JOIN EPK_PLATFORMS "+" _EPK_PLATFORM_SUFFIX)
	set(_EPK_OUTPUT "${CMAKE_BINARY_DIR}/${EPK_NAME}_${EPK_VERSION}-${_EPK_PLATFORM_SUFFIX}.epk")
	list(JOIN EPK_PLATFORMS ", " EPK_PLATFORMS)
	string(LENGTH "${EPK_PLATFORMS}" _EPK_PLATFORMS_LENGTH)
	if(_EPK_PLATFORMS_LENGTH GREATER 127)
		message(FATAL_ERROR "EPK platform list is too long")
	endif()

	set(_EPK_PKGINFO_CONTENT "")
	string(APPEND _EPK_PKGINFO_CONTENT
		"arch = ${EPK_ARCH}\n"
		"pkgname = ${EPK_NAME}\n"
		"pkgver = ${EPK_VERSION}\n"
		"platform = ${EPK_PLATFORMS}\n"
	)

	if(DEFINED EPK_AUTHOR)
		string(APPEND _EPK_PKGINFO_CONTENT "author = ${EPK_AUTHOR}\n")
	endif()

	if(DEFINED EPK_DESCRIPTION)
		string(APPEND _EPK_PKGINFO_CONTENT "pkgdesc = ${EPK_DESCRIPTION}\n")
	endif()

	foreach(_EPK_VALUE IN LISTS EPK_GROUPS)
		string(APPEND _EPK_PKGINFO_CONTENT "group = ${_EPK_VALUE}\n")
	endforeach()

	if(DEFINED EPK_DEPENDS)
		list(JOIN EPK_DEPENDS ", " _EPK_VALUES)
		string(APPEND _EPK_PKGINFO_CONTENT "depend = ${_EPK_VALUES}\n")
	endif()

	if(DEFINED EPK_CONFLICTS)
		list(JOIN EPK_CONFLICTS ", " _EPK_VALUES)
		string(APPEND _EPK_PKGINFO_CONTENT "conflict = ${_EPK_VALUES}\n")
	endif()

	foreach(_EPK_VALUE IN LISTS EPK_BACKUPS)
		string(APPEND _EPK_PKGINFO_CONTENT "backup = ${_EPK_VALUE}\n")
	endforeach()

	foreach(_EPK_VALUE IN LISTS EPK_OWNED_DIRECTORIES)
		string(APPEND _EPK_PKGINFO_CONTENT "directory = ${_EPK_VALUE}\n")
	endforeach()

	get_property(_EPK_TARGET_HOOKS TARGET "${EPK_TARGET}" PROPERTY EPK_HOOKS)
	foreach(_EPK_VALUE IN LISTS _EPK_TARGET_HOOKS)
		string(APPEND _EPK_PKGINFO_CONTENT "hook = ${_EPK_VALUE}\n")
	endforeach()

	get_target_property(_EPK_TARGET_BINARY_DIR "${EPK_TARGET}" BINARY_DIR)
	set(_EPK_WORK_DIR "${_EPK_TARGET_BINARY_DIR}/epk/${EPK_TARGET}")
	set(_EPK_STAGE_DIR "${_EPK_WORK_DIR}/root")
	set(_EPK_PKGINFO "${_EPK_WORK_DIR}/PKGINFO")
	file(MAKE_DIRECTORY "${_EPK_WORK_DIR}")
	file(CONFIGURE
		OUTPUT "${_EPK_PKGINFO}"
		CONTENT "${_EPK_PKGINFO_CONTENT}"
		@ONLY
		NEWLINE_STYLE UNIX
	)

	get_property(_EPK_DEPENDS TARGET "${EPK_TARGET}" PROPERTY EPK_PACKAGE_DEPENDS)

	# Rebuild when directory contents or install rules change.
	list(JOIN _EPK_COMMANDS "\n" _EPK_RULES)
	list(JOIN _EPK_DEPENDS "\n" _EPK_INPUTS)
	set(_EPK_MANIFEST "${_EPK_WORK_DIR}/package.txt")
	file(CONFIGURE
		OUTPUT "${_EPK_MANIFEST}"
		CONTENT "${_EPK_RULES}\n${_EPK_INPUTS}\n"
		NEWLINE_STYLE UNIX
	)

	add_custom_command(
		OUTPUT "${_EPK_OUTPUT}"
		COMMAND "${CMAKE_COMMAND}" -E rm -rf "${_EPK_STAGE_DIR}"
		COMMAND "${CMAKE_COMMAND}" -E make_directory "${_EPK_STAGE_DIR}"
		COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${_EPK_PKGINFO}" "${_EPK_STAGE_DIR}/.PKGINFO"
		${_EPK_COMMANDS}
		COMMAND "${CMAKE_COMMAND}" -E chdir "${_EPK_STAGE_DIR}"
			"${CMAKE_COMMAND}" -E tar cf "${_EPK_OUTPUT}" --format=zip --mtime=@1172750400 .
		DEPENDS
			"${CMAKE_CURRENT_FUNCTION_LIST_FILE}"
			"${_EPK_PKGINFO}"
			"${_EPK_MANIFEST}"
			"${EPK_TARGET}"
			${_EPK_DEPENDS}
		COMMENT "Creating ${_EPK_OUTPUT}"
		VERBATIM
		COMMAND_EXPAND_LISTS
	)
	add_custom_target("${EPK_TARGET}_epk" ALL DEPENDS "${_EPK_OUTPUT}")
endfunction()
