PROJECT := libcrt
TARGET := NSG
BUILD_TYPE := archive
BUILD_DIR := bin

OPT := -Os

SOURCES += main.c
SOURCES += crt.S
SOURCES += __cxa_atexit.cpp

CPPFLAGS += -Werror
CFLAGS += -Wno-missing-prototypes
DEFINES += -D__NO_LIBC

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	cp -v $(OUTPUT_FILENAME) $(SDK_PATH)/lib/$(PROJECT).$(OUTPUT_EXT)

endif
