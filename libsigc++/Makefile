PROJECT := libsigc
LIB_VERSION := 2.0
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin
DEBUG := 1

OPT := -Os

CPPFLAGS += -mthumb -Wall -Werror -Wno-unused-but-set-variable
CXXFLAGS += -fvisibility-inlines-hidden
LDLIBS += -lcrt_helper -lgcc -lc -lc++ -lsupc++

# C++ sources
SOURCES += src/connection.cc
SOURCES += src/signal.cc
SOURCES += src/signal_base.cc
SOURCES += src/slot.cc
SOURCES += src/slot_base.cc
SOURCES += src/trackable.cc

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	@rm -vf $(SDK_LIB_ROOT)/$(TARGET)/$(PROJECT).* $(SDK_LIB_ROOT)/$(PROJECT)-*
	@cp -Pv $(OUTPUT_FILENAME) $(OUTPUT_FILENAME_DBG) $(OUTPUT_SYMLINK) $(SDK_LIB_ROOT)

endif
