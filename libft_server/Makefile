PROJECT := libft_server
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin

OPT := -Os
CPPFLAGS += -mthumb -Werror -Wno-address -Wno-dangling-pointer
CXXFLAGS += -fvisibility-inlines-hidden
LDLIBS += -lcrt_helper -lgcc -lc -lc++ -lsupc++ -lm -lft

SOURCES += src/main.cpp src/ft_engine.cpp

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	@rm -vf $(SDK_PATH)/lib/$(TARGET)/$(PROJECT).* $(SDK_PATH)/lib/$(PROJECT)-*
	@cp -Pv $(OUTPUT_FILENAME) $(OUTPUT_SYMLINK) $(SDK_PATH)/lib

endif
