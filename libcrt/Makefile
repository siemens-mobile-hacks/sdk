PROJECT := libcrt
TARGET := ANY
BUILD_TYPE := archive
BUILD_DIR := bin

OPT := -O2

SOURCES += main.c
SOURCES += crt.S
SOURCES += __cxa_atexit.cpp

CFLAGS += -Wno-missing-prototypes
DEFINES += -D__NO_LIBC

# reproductive builds
export SOURCE_DATE_EPOCH := 1172750400
CFLAGS += -frandom-seed=0

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

install:
	cp -v $(OUTPUT_FILENAME) ../lib/$(PROJECT).$(OUTPUT_EXT)
