PROJECT := libcrt_helper
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin
DEBUG := 1

OPT := -Os -marm

SOURCES += main.c switab.c __cxa_atexit.cpp

CPPFLAGS += -Werror -Wno-array-bounds
CFLAGS += -Wno-missing-prototypes
DEFINES += -D__NO_LIBC

LDFLAGS += --init=libcrt_helper_init

LIB_OUT_SUBDIR :=
ifeq ($(LIBCRT_STUBS),1)
	DEFINES += -DLIBCRT_STUBS
	BUILD_DIR := bin-stubs
	LIB_OUT_DIR := lib-stubs
	LIB_OUT_SUBDIR := stubs/
endif

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	cp -v $(OUTPUT_FILENAME) $(OUTPUT_FILENAME_DBG) $(SDK_LIB_ROOT)/$(LIB_OUT_SUBDIR)

endif
