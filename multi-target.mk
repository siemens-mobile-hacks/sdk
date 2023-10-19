TARGETS ?= ELKA NSG SG
SDK_PATH ?= $(PWD)/sie-dev

BUILD_TARGETS := $(addprefix build_, $(TARGETS))
CLEAN_TARGETS := $(addprefix clean_, $(TARGETS))
INSTALL_TARGETS := $(addprefix install_, $(TARGETS))

ifndef TARGET

all: $(BUILD_TARGETS)
install: $(INSTALL_TARGETS)
clean: $(CLEAN_TARGETS)
	rm -rf bin

build_ELKA:
	@$(MAKE) TARGET=ELKA
build_NSG:
	@$(MAKE) TARGET=NSG
build_SG:
	@$(MAKE) TARGET=SG

clean_ELKA:
	@$(MAKE) TARGET=ELKA clean
clean_NSG:
	@$(MAKE) TARGET=NSG clean
clean_SG:
	@$(MAKE) TARGET=SG clean

install_ELKA:
	@$(MAKE) TARGET=ELKA install
install_NSG:
	@$(MAKE) TARGET=NSG install
install_SG:
	@$(MAKE) TARGET=SG install

.PHONY: all clean build_ELKA build_NSG build_SG clean_ELKA clean_NSG clean_SG install_ELKA install_NSG install_SG

else

include $(SDK_PATH)/rules.mk

endif
