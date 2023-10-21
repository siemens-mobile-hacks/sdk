PROJECT := libft-2.4.6-1
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

OPT := -O2

LDLIBS += -lcrt_helper -lgcc -lc-1.0

# reproductive builds
export SOURCE_DATE_EPOCH=1172750400
CFLAGS += -frandom-seed=0
CXXFLAGS += -frandom-seed=0 -fvisibility-inlines-hidden

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
	cp -v $(OUTPUT_FILENAME) ../lib/$(PROJECT).$(OUTPUT_EXT)

endif
