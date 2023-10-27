PROJECT := libsigc
LIB_VERSION := 2.0
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

CXXSTD := -std=gnu++98
OPT := -Os

CPPFLAGS += -mthumb -Wall -Werror -Wno-unused-but-set-variable
CXXFLAGS += -fvisibility-inlines-hidden
LDLIBS += -lcrt_helper -lgcc -lc -lucsupc++ -lstdc++

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
	@rm -vf ../lib/$(TARGET)/$(PROJECT).* ../lib/$(PROJECT)-*
	@cp -Pv $(OUTPUT_FILENAME) $(OUTPUT_SYMLINK) ../lib

endif
