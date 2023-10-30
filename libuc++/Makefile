PROJECT := libstdc++
LIB_VERSION := 1.2.2
LIB_SYMLINK_NAME := libuc++
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin
CXX_TYPE := uclibc++

CXXSTD := -std=gnu++98
OPT := -Os

CPPFLAGS += -mthumb -Werror
CXXFLAGS += -fvisibility-inlines-hidden

DEFINES += -D__ARM_EABI_UNWINDER__ -mthumb
INCLUDES += -Iinclude -Isrc -Isrc/include

LDLIBS += -lcrt_helper -lgcc -lc -lsupc++

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
# SOURCES += src/del_ops.cpp
SOURCES += src/del_opv.cpp
SOURCES += src/del_opvnt.cpp
# SOURCES += src/del_opvs.cpp
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
# SOURCES += src/support.cpp
# SOURCES += src/typeinfo.cpp
SOURCES += src/utility.cpp
SOURCES += src/valarray.cpp
SOURCES += src/vector.cpp

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	@rm -vf $(SDK_LIB_ROOT)/$(TARGET)/$(PROJECT).* $(SDK_LIB_ROOT)/$(PROJECT)-*
	@cp -Pv $(OUTPUT_FILENAME) $(OUTPUT_SYMLINK) $(SDK_LIB_ROOT)
endif
