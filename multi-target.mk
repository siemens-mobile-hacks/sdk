TARGETS ?= ELKA NSG SG
SIEDEV_DIR ?= $(PWD)/sie-dev

BUILD_TARGETS := $(addprefix build_, $(TARGETS))
CLEAN_TARGETS := $(addprefix clean_, $(TARGETS))

ifndef TARGET

all: $(BUILD_TARGETS)
clean: $(CLEAN_TARGETS)
	rm -rf bin

build_ANY:
	@$(MAKE) TARGET=ANY
build_ELKA:
	@$(MAKE) TARGET=ELKA OUTPUT_POSTFIX=_ELKA
build_NSG:
	@$(MAKE) TARGET=NSG OUTPUT_POSTFIX=_NSG
build_SG:
	@$(MAKE) TARGET=SG OUTPUT_POSTFIX=_SG

clean_ANY:
	@$(MAKE) TARGET=ANY clean
clean_ELKA:
	@$(MAKE) TARGET=ELKA OUTPUT_POSTFIX=_ELKA clean
clean_NSG:
	@$(MAKE) TARGET=NSG OUTPUT_POSTFIX=_NSG clean
clean_SG:
	@$(MAKE) TARGET=SG OUTPUT_POSTFIX=_SG clean

.PHONY: all clean build_ELKA build_NSG build_SG clean_ELKA clean_NSG clean_SG

else

include $(SIEDEV_DIR)/rules.mk

endif
