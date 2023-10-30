BUILD_TYPE ?= exe
TARGETS ?= ELKA NSG SG
BUILD_TYPES ?= $(BUILD_TYPE)
SDK_PATH ?= $(PWD)/sie-dev

ifndef TARGET

CURRENT_MAKEFILE := $(abspath $(firstword $(MAKEFILE_LIST)))

.DEFAULT_GOAL := all

.DEFAULT:
	@for _TARGET in $(TARGETS); do \
		for _BUILD_TYPE in $(BUILD_TYPES); do \
			$(MAKE) -C $(CURDIR) -f $(CURRENT_MAKEFILE) $@ TARGET=$$_TARGET BUILD_TYPE=$$_BUILD_TYPE ; \
		done \
	done

else

BUILD_DIR := bin/$(TARGET)
LIB_OUT_DIR := lib/$(TARGET)

GENERATED_FILES += lib bin

include $(SDK_PATH)/rules.mk

endif
