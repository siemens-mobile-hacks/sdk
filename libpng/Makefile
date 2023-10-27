PROJECT := libpng
LIB_VERSION := 12
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

CPPFLAGS += -mthumb -Werror -Wno-implicit-fallthrough -Wno-dangling-pointer

CSTD := -std=c99
OPT := -Os

INCLUDES += -Isrc
LDLIBS += -lcrt_helper -lgcc -lc -lm -lz

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
	@rm -vf ../lib/$(TARGET)/$(PROJECT).* ../lib/$(PROJECT)-*
	@cp -Pv $(OUTPUT_FILENAME) $(OUTPUT_SYMLINK) ../lib

endif
