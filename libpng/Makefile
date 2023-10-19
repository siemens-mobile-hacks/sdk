PROJECT := libpng-1.0
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

CSTD := -std=c99
OPT := -Os

CFLAGS += -mthumb -Wno-implicit-fallthrough
INCLUDES += -Isrc

LDLIBS += -lcrt -lcrt_helper -lgcc -lc-1.0

# reproductive builds
export SOURCE_DATE_EPOCH=1172750400
CFLAGS += -frandom-seed=0

# C sources
SOURCES += src/png.c
SOURCES += src/pngerror.c
SOURCES += src/pnggccrd.c
SOURCES += src/pngget.c
SOURCES += src/pngmem.c
SOURCES += src/pngpread.c
SOURCES += src/pngread.c
SOURCES += src/pngrio.c
SOURCES += src/pngrtran.c
SOURCES += src/pngrutil.c
SOURCES += src/pngset.c
SOURCES += src/pngtrans.c
SOURCES += src/pngvcrd.c
SOURCES += src/pngwio.c
SOURCES += src/pngwrite.c
SOURCES += src/pngwtran.c
SOURCES += src/pngwutil.c

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

install:
	cp -v $(OUTPUT_FILENAME) ../lib/$(PROJECT).$(OUTPUT_EXT)
