PROJECT := libc++
LIB_VERSION := 1.0
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

CXX_TYPE ?= libcxx

CXXSTD := -std=gnu++11
OPT := -Os

CXXFLAGS += -fpermissive -mthumb -fvisibility-inlines-hidden

DEFINES += -D_LIBCPP_BUILDING_LIBRARY -DLIBCXX_BUILDING_LIBCXXABI

INCLUDES += -isystem src

LDLIBS += -lcrt_helper -lsupc++ -lgcc -lc

SOURCES += src/abi/cxa_atexit.c
SOURCES += src/memory.cpp
SOURCES += src/string.cpp
SOURCES += src/future.cpp
SOURCES += src/algorithm.cpp
SOURCES += src/chrono.cpp
SOURCES += src/valarray.cpp
SOURCES += src/variant.cpp
SOURCES += src/new.cpp
SOURCES += src/utility.cpp
SOURCES += src/typeinfo.cpp
SOURCES += src/stdexcept.cpp
SOURCES += src/hash.cpp
SOURCES += src/bind.cpp
SOURCES += src/system_error.cpp
SOURCES += src/any.cpp
SOURCES += src/optional.cpp
SOURCES += src/exception.cpp
SOURCES += src/vector.cpp

# SOURCES += src/thread.cpp
# SOURCES += src/shared_mutex.cpp
# SOURCES += src/condition_variable.cpp
# SOURCES += src/debug.cpp
# SOURCES += src/mutex.cpp
# SOURCES += src/experimental/memory_resource.cpp
# SOURCES += src/experimental/filesystem/directory_iterator.cpp
# SOURCES += src/experimental/filesystem/path.cpp
# SOURCES += src/experimental/filesystem/operations.cpp
# SOURCES += src/random.cpp
# SOURCES += src/ios.cpp
# SOURCES += src/iostream.cpp
# SOURCES += src/locale.cpp
# SOURCES += src/regex.cpp
# SOURCES += src/strstream.cpp

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	@rm -vf $(SDK_PATH)/lib/$(TARGET)/$(PROJECT).* $(SDK_PATH)/lib/$(PROJECT)-*
	@cp -Pv $(OUTPUT_FILENAME) $(OUTPUT_SYMLINK) $(SDK_PATH)/lib

endif
