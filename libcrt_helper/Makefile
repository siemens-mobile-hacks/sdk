PROJECT := libcrt_helper
TARGET := ANY
BUILD_TYPE := lib
BUILD_DIR := bin

OPT := -Os

CFILES += main.c switab.c
AFILES += dump.S
CXXFILES += __cxa_atexit.cpp

CFLAGS += -Wno-missing-prototypes
DEFINES += -D__NO_LIBC
LDFLAGS += -Wl,--init=__onstart
LDFLAGS += -Wl,--fini=__onclose

# reproductive builds
export SOURCE_DATE_EPOCH=1172750400
CFLAGS += -frandom-seed=0

SIEDEV_DIR=..
include $(SIEDEV_DIR)/rules.mk

install:
	cp -v $(PROJECT).so ../../lib/$(PROJECT).so
