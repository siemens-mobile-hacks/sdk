PROJECT := libft_server
TARGET := NSG
BUILD_TYPE := lib
BUILD_DIR := bin
DEBUG := 1

OPT := -Os
CPPFLAGS += -mthumb -Werror -Wno-address -Wno-dangling-pointer
CXXFLAGS += -fvisibility-inlines-hidden
LDLIBS += -lcrt_helper -lgcc -lc -lc++ -lsupc++ -lm -lft

SOURCES += src/main.cpp src/ft_engine.cpp

SDK_PATH := ..
include $(SDK_PATH)/rules.mk

ifdef TARGET

install: all
	@rm -vf $(SDK_LIB_ROOT)/$(TARGET)/$(PROJECT).* $(SDK_LIB_ROOT)/$(PROJECT)-*
	@cp -Pv $(OUTPUT_FILENAME) $(OUTPUT_FILENAME_DBG) $(OUTPUT_SYMLINK) $(SDK_LIB_ROOT)

endif
