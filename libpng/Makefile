PROJECT := libpng-12
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

CFLAGS += -mthumb
CXXFLAGS += -mthumb

CSTD := -std=c99
OPT := -Os

CFLAGS += -mthumb -Wno-implicit-fallthrough
INCLUDES += -Isrc

LDLIBS += -lcrt_helper -lgcc -lc-1.0 -lm-1.0 -lz-1.2.5

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

ifdef TARGET

install: all
	cp -v $(OUTPUT_FILENAME) ../lib/$(PROJECT).$(OUTPUT_EXT)

endif
