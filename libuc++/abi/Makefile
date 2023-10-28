PROJECT := libuc++abi
TARGET := NSG
BUILD_TYPE := archive
BUILD_DIR := bin
CXX_TYPE := uclibc++

INCLUDES += -Iinclude
DEFINES += -D__NO_LIBC
CPPFLAGS += -mthumb -Wall -Werror -Wno-unused-but-set-variable
CXXFLAGS += -fvisibility-inlines-hidden

CXXSTD := -std=gnu++98
OPT := -O2

SOURCES += src/si_class_type_info.cc
SOURCES += src/nested_exception.cc
SOURCES += src/eh_catch.cc
SOURCES += src/guard_error.cc
SOURCES += src/enum_type_info.cc
SOURCES += src/dyncast.cc
SOURCES += src/new_opvnt.cc
SOURCES += src/eh_aux_runtime.cc
SOURCES += src/vec.cc
SOURCES += src/bad_cast.cc
SOURCES += src/tinfo.cc
SOURCES += src/eh_terminate.cc
SOURCES += src/pointer_type_info.cc
SOURCES += src/bad_alloc.cc
SOURCES += src/eh_type.cc
SOURCES += src/tinfo2.cc
SOURCES += src/guard.cc
SOURCES += src/new_handler.cc
SOURCES += src/new_opv.cc
SOURCES += src/vmi_class_type_info.cc
SOURCES += src/eh_throw.cc
SOURCES += src/eh_term_handler.cc
SOURCES += src/eh_unex_handler.cc
SOURCES += src/pure.cc
SOURCES += src/eh_exception.cc
SOURCES += src/del_opv.cc
SOURCES += src/del_opvnt.cc
SOURCES += src/fundamental_type_info.cc
SOURCES += src/eh_globals.cc
SOURCES += src/new_op.cc
SOURCES += src/class_type_info.cc
SOURCES += src/eh_arm.cc
SOURCES += src/array_type_info.cc
SOURCES += src/vterminate.cc
SOURCES += src/pbase_type_info.cc
SOURCES += src/bad_typeid.cc
SOURCES += src/eh_alloc.cc
SOURCES += src/del_op.cc
SOURCES += src/pmem_type_info.cc
SOURCES += src/eh_call.cc
SOURCES += src/new_opnt.cc
SOURCES += src/function_type_info.cc
SOURCES += src/eh_personality.cc
SOURCES += src/atexit_arm.cc
SOURCES += src/hash_bytes.cc
SOURCES += src/del_opnt.cc
SOURCES += src/eh_ptr.cc

SDK_PATH := ../..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	cp -v $(OUTPUT_FILENAME) $(SDK_PATH)/lib/$(PROJECT).$(OUTPUT_EXT)

endif
