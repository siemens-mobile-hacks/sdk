PROJECT := libft
LIB_VERSION := 2.4.6-1
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

OPT := -Os

CPPFLAGS += -mthumb -Werror -Wno-address -Wno-dangling-pointer
CXXFLAGS += -fvisibility-inlines-hidden

LDLIBS += -lcrt_helper -lgcc -lc

SOURCES += main.c
SOURCES += src/autofit/afangles.c
SOURCES += src/autofit/afcjk.c
SOURCES += src/autofit/afdummy.c
SOURCES += src/autofit/afglobal.c
SOURCES += src/autofit/afhints.c
SOURCES += src/autofit/afindic.c
SOURCES += src/autofit/aflatin.c
SOURCES += src/autofit/afloader.c
SOURCES += src/autofit/afmodule.c
SOURCES += src/autofit/afpic.c
SOURCES += src/autofit/afwarp.c
SOURCES += src/base/ftbase.c
SOURCES += src/base/ftbitmap.c
SOURCES += src/base/ftglyph.c
SOURCES += src/base/ftinit.c
SOURCES += src/base/ftsystem.c
# SOURCES += src/cache/ftcache.c
# SOURCES += src/gxvalid/gxvalid.c
# SOURCES += src/lzw/ftlzw.c
# SOURCES += src/otvalid/otvalid.c
SOURCES += src/raster/raster.c
SOURCES += src/sfnt/sfnt.c
SOURCES += src/smooth/smooth.c
SOURCES += src/truetype/truetype.c

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	@rm -vf ../lib/$(TARGET)/$(PROJECT).* ../lib/$(PROJECT)-*
	@cp -Pv $(OUTPUT_FILENAME) $(OUTPUT_SYMLINK) ../lib

endif
