PROJECT := libcrt_helper
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

OPT := -Os

SOURCES += main.c switab.c
SOURCES += dump.S
SOURCES += __cxa_atexit.cpp

CFLAGS += -Wno-missing-prototypes
DEFINES += -D__NO_LIBC
LDFLAGS += --init=__onstart
LDFLAGS += --fini=__onclose

# reproductive builds
export SOURCE_DATE_EPOCH=1172750400
CFLAGS += -frandom-seed=0

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	cp -v $(OUTPUT_FILENAME) ../lib/$(PROJECT).$(OUTPUT_EXT)

endif
