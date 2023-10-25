PROJECT := libsigc-2.0
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

CFLAGS += -mthumb
CXXFLAGS += -mthumb

CXXSTD := -std=gnu++98
OPT := -O2

LDLIBS += -lcrt_helper -lgcc -lc-1.0 -lstdc++-1.2.2

# reproductive builds
export SOURCE_DATE_EPOCH=1172750400
CFLAGS += -frandom-seed=0
CXXFLAGS += -frandom-seed=0 -fvisibility-inlines-hidden

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
	cp -v $(OUTPUT_FILENAME) ../lib/$(PROJECT).$(OUTPUT_EXT)

endif
