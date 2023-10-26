PROJECT := libc++11
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

CXX_TYPE ?= none

CXXSTD := -std=gnu++11
OPT := -Os

CXXFLAGS += -fpermissive -mthumb

DEFINES += -D_LIBCPP_BUILDING_LIBRARY -DLIBCXX_BUILDING_LIBCXXABI

INCLUDES += -Iinclude -isystem src -I../libc++11-abi/include

LDLIBS += -lcrt_helper -lgcc -lc-1.0 -lc++11-abi

# reproductive builds
export SOURCE_DATE_EPOCH=1172750400
CFLAGS += -frandom-seed=0
CXXFLAGS += -frandom-seed=0 -fvisibility-inlines-hidden -fvisibility=hidden

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
	cp -v $(OUTPUT_FILENAME) ../lib/$(PROJECT).$(OUTPUT_EXT)

endif
