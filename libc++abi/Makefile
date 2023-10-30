PROJECT := libc++abi
TARGET := NSG
BUILD_TYPE := archive
BUILD_DIR := bin

CXX_TYPE ?= libcxx

CXXSTD := -std=gnu++11
OPT := -Os

CXXFLAGS += -mthumb -fvisibility-inlines-hidden -fvisibility=hidden

INCLUDES += -isystem src -isystem ../libc++/src

# C++ABI files
SOURCES += src/cxa_aux_runtime.cpp
SOURCES += src/cxa_default_handlers.cpp
SOURCES += src/cxa_demangle.cpp
SOURCES += src/cxa_exception_storage.cpp
SOURCES += src/cxa_guard.cpp
SOURCES += src/cxa_handlers.cpp
SOURCES += src/cxa_new_delete.cpp
SOURCES += src/cxa_unexpected.cpp
SOURCES += src/cxa_vector.cpp
SOURCES += src/cxa_virtual.cpp
# C++ STL files
SOURCES += src/stdlib_exception.cpp
SOURCES += src/stdlib_stdexcept.cpp
SOURCES += src/stdlib_typeinfo.cpp
# Internal files
SOURCES += src/abort_message.cpp
SOURCES += src/fallback_malloc.cpp
SOURCES += src/private_typeinfo.cpp
# -fno-exception
SOURCES += src/cxa_noexception.cpp

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	cp -v $(OUTPUT_FILENAME) $(SDK_LIB_ROOT)/$(PROJECT).$(OUTPUT_EXT)

endif
