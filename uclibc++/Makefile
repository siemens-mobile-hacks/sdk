PROJECT := libstdc++-1.2.2
TARGET := ANY
BUILD_TYPE := lib
BUILD_DIR := bin

CXXSTD := -std=gnu++98
OPT := -O2

DEFINES += -D__ARM_EABI__ -D__arm__ -D__ARM_EABI_UNWINDER__ -mthumb
INCLUDES += -Iinclude -Isrc -Isrc/include

LDLIBS += -lcrt_helper -lgcc-4.6.1 -lc-1.0

# reproductive builds
export SOURCE_DATE_EPOCH=1172750400
CFLAGS += -frandom-seed=0
CXXFLAGS += -frandom-seed=0 -fvisibility-inlines-hidden

# C sources
CFILES += src/abi/cxa/cp-damagle.c
CFILES += src/abi/cxa/cxa_atexit.c

# C++ sources
CXXFILES += src/abi/abi.cpp
CXXFILES += src/algorithm.cpp
CXXFILES += src/associative_base.cpp
CXXFILES += src/bitset.cpp
CXXFILES += src/char_traits.cpp
CXXFILES += src/complex.cpp
CXXFILES += src/del_op.cpp
CXXFILES += src/del_opnt.cpp
CXXFILES += src/del_opv.cpp
CXXFILES += src/del_opvnt.cpp
CXXFILES += src/deque.cpp
CXXFILES += src/eh_alloc.cpp
CXXFILES += src/eh_globals.cpp
CXXFILES += src/exception.cpp
CXXFILES += src/fstream.cpp
CXXFILES += src/func_exception.cpp
CXXFILES += src/iomanip.cpp
CXXFILES += src/ios.cpp
CXXFILES += src/iostream.cpp
CXXFILES += src/istream.cpp
CXXFILES += src/iterator.cpp
CXXFILES += src/limits.cpp
CXXFILES += src/list.cpp
CXXFILES += src/locale.cpp
CXXFILES += src/map.cpp
CXXFILES += src/new_handler.cpp
CXXFILES += src/new_op.cpp
CXXFILES += src/new_opnt.cpp
CXXFILES += src/new_opv.cpp
CXXFILES += src/new_opvnt.cpp
CXXFILES += src/numeric.cpp
CXXFILES += src/ostream.cpp
CXXFILES += src/queue.cpp
CXXFILES += src/set.cpp
CXXFILES += src/sstream.cpp
CXXFILES += src/stack.cpp
CXXFILES += src/stdexcept.cpp
CXXFILES += src/streambuf.cpp
CXXFILES += src/string.cpp
CXXFILES += src/support.cpp
CXXFILES += src/utility.cpp
CXXFILES += src/valarray.cpp
CXXFILES += src/vector.cpp

SIEDEV_DIR=..
include $(SIEDEV_DIR)/rules.mk

install:
	cp -v $(PROJECT).so ../../lib/$(PROJECT).so
