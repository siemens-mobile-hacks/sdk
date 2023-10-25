PROJECT := libc++14
TARGET := NSG
BUILD_TYPE := archive
BUILD_DIR := bin

CXX_TYPE ?= none

CXXSTD := -std=gnu++20
OPT := -Os

CXXFLAGS += -fpermissive -mthumb -flto -ffat-lto-objects
LDFLAGS += -flto

DEFINES += -D_LIBCPP_BUILDING_LIBRARY
INCLUDES += -Iinclude -isystem src

LDLIBS += -lcrt_helper -lgcc -lc-1.0

# reproductive builds
export SOURCE_DATE_EPOCH=1172750400
CFLAGS += -frandom-seed=0
CXXFLAGS += -frandom-seed=0 -fvisibility-inlines-hidden -fvisibility=hidden

SOURCES += src/algorithm.cpp
SOURCES += src/any.cpp
SOURCES += src/atomic.cpp
SOURCES += src/barrier.cpp
SOURCES += src/bind.cpp
SOURCES += src/charconv.cpp
SOURCES += src/chrono.cpp
SOURCES += src/condition_variable.cpp
SOURCES += src/condition_variable_destructor.cpp
SOURCES += src/exception.cpp
SOURCES += src/functional.cpp
SOURCES += src/future.cpp
SOURCES += src/hash.cpp
SOURCES += src/legacy_pointer_safety.cpp
SOURCES += src/memory.cpp
SOURCES += src/mutex.cpp
SOURCES += src/mutex_destructor.cpp
SOURCES += src/new.cpp
SOURCES += src/optional.cpp
# SOURCES += src/random_shuffle.cpp
SOURCES += src/ryu/d2fixed.cpp
SOURCES += src/ryu/d2s.cpp
SOURCES += src/ryu/f2s.cpp
SOURCES += src/shared_mutex.cpp
SOURCES += src/stdexcept.cpp
SOURCES += src/string.cpp
SOURCES += src/system_error.cpp
SOURCES += src/thread.cpp
SOURCES += src/typeinfo.cpp
SOURCES += src/utility.cpp
SOURCES += src/valarray.cpp
SOURCES += src/variant.cpp
SOURCES += src/vector.cpp
SOURCES += src/verbose_abort.cpp

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	cp -v $(OUTPUT_FILENAME) ../lib/$(PROJECT).$(OUTPUT_EXT)

endif
