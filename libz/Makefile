PROJECT := libz
LIB_VERSION := 1.2.5
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

CSTD := -std=c99
OPT := -Os

CPPFLAGS += -mthumb -Werror -Wno-implicit-fallthrough
INCLUDES += -Isrc

LDLIBS += -lcrt_helper -lgcc -lc

# C sources
SOURCES += src/adler32.c
SOURCES += src/compress.c
SOURCES += src/crc32.c
SOURCES += src/deflate.c
SOURCES += src/gzclose.c
SOURCES += src/gzlib.c
SOURCES += src/gzread.c
SOURCES += src/gzwrite.c
SOURCES += src/infback.c
SOURCES += src/inffast.c
SOURCES += src/inflate.c
SOURCES += src/inftrees.c
SOURCES += src/trees.c
SOURCES += src/uncompr.c
SOURCES += src/zutil.c

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	@rm -vf $(SDK_LIB_ROOT)/$(TARGET)/$(PROJECT).* $(SDK_LIB_ROOT)/$(PROJECT)-*
	@cp -Pv $(OUTPUT_FILENAME) $(OUTPUT_SYMLINK) $(SDK_LIB_ROOT)

endif
