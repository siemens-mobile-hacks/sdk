PROJECT := libcrt-static
TARGET := NSG
BUILD_TYPE := archive
BUILD_DIR := bin
DEBUG := 1

OPT := -Os

SOURCES += main.c __cxa_atexit.cpp

CPPFLAGS += -Werror
CFLAGS += -Wno-missing-prototypes
DEFINES += -D__NO_LIBC

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	cp -v $(OUTPUT_FILENAME) $(OUTPUT_FILENAME_DBG) $(SDK_LIB_ROOT)/

endif
