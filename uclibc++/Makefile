PROJECT := libstdc++-1.2.2
TARGET := ANY
BUILD_TYPE := lib
BUILD_DIR := bin

CXXSTD := -std=gnu++98
OPT := -O2

DEFINES += -D__ARM_EABI__ -D__arm__ -D__ARM_EABI_UNWINDER__ -mthumb
INCLUDES += -Iinclude -Isrc -Isrc/include

LDLIBS += -lcrt -lcrt_helper -lgcc -lc-1.0

# reproductive builds
export SOURCE_DATE_EPOCH=1172750400
CFLAGS += -frandom-seed=0
CXXFLAGS += -frandom-seed=0 -fvisibility-inlines-hidden

# C sources
SOURCES += src/abi/cxa/cp-damagle.c
SOURCES += src/abi/cxa/cxa_atexit.c

# C++ sources
SOURCES += src/abi/abi.cpp
SOURCES += src/algorithm.cpp
SOURCES += src/associative_base.cpp
SOURCES += src/bitset.cpp
SOURCES += src/char_traits.cpp
SOURCES += src/complex.cpp
SOURCES += src/del_op.cpp
SOURCES += src/del_opnt.cpp
SOURCES += src/del_opv.cpp
SOURCES += src/del_opvnt.cpp
SOURCES += src/deque.cpp
SOURCES += src/eh_alloc.cpp
SOURCES += src/eh_globals.cpp
SOURCES += src/exception.cpp
SOURCES += src/fstream.cpp
SOURCES += src/func_exception.cpp
SOURCES += src/iomanip.cpp
SOURCES += src/ios.cpp
SOURCES += src/iostream.cpp
SOURCES += src/istream.cpp
SOURCES += src/iterator.cpp
SOURCES += src/limits.cpp
SOURCES += src/list.cpp
SOURCES += src/locale.cpp
SOURCES += src/map.cpp
SOURCES += src/new_handler.cpp
SOURCES += src/new_op.cpp
SOURCES += src/new_opnt.cpp
SOURCES += src/new_opv.cpp
SOURCES += src/new_opvnt.cpp
SOURCES += src/numeric.cpp
SOURCES += src/ostream.cpp
SOURCES += src/queue.cpp
SOURCES += src/set.cpp
SOURCES += src/sstream.cpp
SOURCES += src/stack.cpp
SOURCES += src/stdexcept.cpp
SOURCES += src/streambuf.cpp
SOURCES += src/string.cpp
SOURCES += src/support.cpp
SOURCES += src/utility.cpp
SOURCES += src/valarray.cpp
SOURCES += src/vector.cpp

SIEDEV_DIR=..
include $(SIEDEV_DIR)/rules.mk

install:
	cp -v $(PROJECT).so ../lib/$(PROJECT).so
