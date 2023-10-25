PROJECT := libcxx-1.0
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

CXX_TYPE ?= none

CXXSTD := -std=c++11
OPT := -Os

DEFINES += -D__ARM_EABI_UNWINDER__ -mthumb
INCLUDES += -Iinclude

LDLIBS += -lcrt_helper -lgcc -lc-1.0

# reproductive builds
export SOURCE_DATE_EPOCH=1172750400
CFLAGS += -frandom-seed=0
CXXFLAGS += -frandom-seed=0 -fvisibility-inlines-hidden

SOURCES += src/algorithm.cpp
SOURCES += src/any.cpp
SOURCES += src/atomic.cpp
SOURCES += src/barrier.cpp
SOURCES += src/bind.cpp
SOURCES += src/charconv.cpp
SOURCES += src/chrono.cpp
SOURCES += src/condition_variable.cpp
SOURCES += src/condition_variable_destructor.cpp
SOURCES += src/error_category.cpp
SOURCES += src/exception.cpp
SOURCES += src/functional.cpp
SOURCES += src/future.cpp
SOURCES += src/hash.cpp
SOURCES += src/ios.cpp
SOURCES += src/ios.instantiations.cpp
SOURCES += src/iostream.cpp
SOURCES += src/legacy_pointer_safety.cpp
SOURCES += src/locale.cpp
SOURCES += src/memory.cpp
SOURCES += src/memory_resource.cpp
SOURCES += src/mutex.cpp
SOURCES += src/mutex_destructor.cpp
SOURCES += src/new.cpp
SOURCES += src/new_handler.cpp
SOURCES += src/new_helpers.cpp
SOURCES += src/optional.cpp
SOURCES += src/print.cpp
SOURCES += src/random.cpp
SOURCES += src/random_shuffle.cpp
SOURCES += src/regex.cpp
SOURCES += src/shared_mutex.cpp
SOURCES += src/stdexcept.cpp
SOURCES += src/string.cpp
SOURCES += src/strstream.cpp
SOURCES += src/system_error.cpp
SOURCES += src/thread.cpp
SOURCES += src/typeinfo.cpp
SOURCES += src/tz.cpp
SOURCES += src/tzdb_list.cpp
SOURCES += src/valarray.cpp
SOURCES += src/variant.cpp
SOURCES += src/vector.cpp
SOURCES += src/verbose_abort.cpp

SOURCES += src/pstl/libdispatch.cpp

SOURCES += src/ryu/d2fixed.cpp
SOURCES += src/ryu/d2s.cpp
SOURCES += src/ryu/f2s.cpp

SOURCES += src/experimental/memory_resource.cpp

SOURCES += src/filesystem/directory_entry.cpp
SOURCES += src/filesystem/directory_iterator.cpp
SOURCES += src/filesystem/filesystem_clock.cpp
SOURCES += src/filesystem/filesystem_error.cpp
SOURCES += src/filesystem/int128_builtins.cpp
SOURCES += src/filesystem/operations.cpp
SOURCES += src/filesystem/path.cpp

SOURCES += src/support/ibm/mbsnrtowcs.cpp
SOURCES += src/support/ibm/wcsnrtombs.cpp
SOURCES += src/support/ibm/xlocale_zos.cpp

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	cp -v $(OUTPUT_FILENAME) ../lib/$(PROJECT).$(OUTPUT_EXT)

endif
