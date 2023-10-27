PROJECT := libjpeg
LIB_VERSION := 62
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

CSTD := -std=c99
OPT := -Os

CPPFLAGS += -mthumb -Werror -Wno-implicit-fallthrough
INCLUDES += -Isrc -isystem ./include/jpeglib

LDLIBS += -lcrt_helper -lgcc -lc

# C sources
SOURCES += src/jaricom.c
SOURCES += src/jcapimin.c
SOURCES += src/jcapistd.c
SOURCES += src/jcarith.c
SOURCES += src/jccoefct.c
SOURCES += src/jccolor.c
SOURCES += src/jcdctmgr.c
SOURCES += src/jchuff.c
SOURCES += src/jcinit.c
SOURCES += src/jcmainct.c
SOURCES += src/jcmarker.c
SOURCES += src/jcmaster.c
SOURCES += src/jcomapi.c
SOURCES += src/jcparam.c
SOURCES += src/jcprepct.c
SOURCES += src/jcsample.c
SOURCES += src/jctrans.c
SOURCES += src/jdapimin.c
SOURCES += src/jdapistd.c
SOURCES += src/jdarith.c
SOURCES += src/jdatadst.c
SOURCES += src/jdatasrc.c
SOURCES += src/jdcoefct.c
SOURCES += src/jdcolor.c
SOURCES += src/jddctmgr.c
SOURCES += src/jdhuff.c
SOURCES += src/jdinput.c
SOURCES += src/jdmainct.c
SOURCES += src/jdmarker.c
SOURCES += src/jdmaster.c
SOURCES += src/jdmerge.c
SOURCES += src/jdpostct.c
SOURCES += src/jdsample.c
SOURCES += src/jdtrans.c
SOURCES += src/jerror.c
SOURCES += src/jfdctflt.c
SOURCES += src/jfdctfst.c
SOURCES += src/jfdctint.c
SOURCES += src/jidctflt.c
SOURCES += src/jidctfst.c
SOURCES += src/jidctint.c
SOURCES += src/jmemmgr.c
SOURCES += src/jmemname.c
SOURCES += src/jquant1.c
SOURCES += src/jquant2.c
SOURCES += src/jutils.c
SOURCES += src/transupp.c

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	@rm -vf ../lib/$(TARGET)/$(PROJECT).* ../lib/$(PROJECT)-*
	@cp -Pv $(OUTPUT_FILENAME) $(OUTPUT_SYMLINK) ../lib

endif
