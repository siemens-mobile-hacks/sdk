PROJECT := libft_server
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

OPT := -Os

CFLAGS += -mthumb
CXXFLAGS += -mthumb

LDLIBS += -lcrt_helper -lgcc -lc-1.0 -lstdc++-1.2.2 -lm-1.0 -lft-2.4.6-1

# reproductive builds
export SOURCE_DATE_EPOCH=1172750400
CFLAGS += -frandom-seed=0
CXXFLAGS += -frandom-seed=0 -fvisibility-inlines-hidden

SOURCES += src/main.cpp
SOURCES += src/ft_engine.cpp

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	cp -v $(OUTPUT_FILENAME) ../lib/$(PROJECT).$(OUTPUT_EXT)

endif
