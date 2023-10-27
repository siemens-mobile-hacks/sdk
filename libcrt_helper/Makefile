PROJECT := libcrt_helper
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

OPT := -Os

SOURCES += main.c switab.c
SOURCES += dump.S
SOURCES += __cxa_atexit.cpp

CPPFLAGS += -Werror -Wno-array-bounds
CFLAGS += -Wno-missing-prototypes
DEFINES += -D__NO_LIBC
LDFLAGS += --init=__onstart
LDFLAGS += --fini=__onclose

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	cp -v $(OUTPUT_FILENAME) ../lib/$(PROJECT).$(OUTPUT_EXT)

endif
