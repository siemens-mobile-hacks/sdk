GCC_VERSION := 13.2.0
GCC_URL := https://ftp.gnu.org/gnu/gcc/gcc-$(GCC_VERSION)/gcc-$(GCC_VERSION).tar.xz
BUILD_DIR := $(shell realpath build)
GCC_FILE := $(BUILD_DIR)/$(shell basename $(GCC_URL))
GCC_DIR := $(BUILD_DIR)/gcc-$(GCC_VERSION)
GCC_BUILD_DIR := $(BUILD_DIR)/gcc-$(GCC_VERSION)-build
CCACHE_DIR := $(BUILD_DIR)/gcc-$(GCC_VERSION)-cache

ARCH_FLAGS := -mcpu=arm926ej-s -msoft-float  -mlittle-endian -fshort-wchar -mthumb-interwork -frandom-seed=0 -Os
ARCH_LDFLAGS := -zmax-page-size=1

export CCACHE_DIR

# reproductive builds
export SOURCE_DATE_EPOCH := 1172750400
export GCC_FOR_TARGET := $(shell which arm-none-eabi-gcc)
export AR_FOR_TARGET := $(shell which arm-none-eabi-ar)
export AS_FOR_TARGET := $(shell which arm-none-eabi-as)
export LD_FOR_TARGET := $(shell which arm-none-eabi-ld)
export NM_FOR_TARGET := $(shell which arm-none-eabi-nm)
export OBJCOPY_FOR_TARGET := $(shell which arm-none-eabi-objcopy)
export OBJDUMP_FOR_TARGET := $(shell which arm-none-eabi-objdump)
export RANLIB_FOR_TARGET := $(shell which arm-none-eabi-ranlib)
export READELF_FOR_TARGET := $(shell which arm-none-eabi-readelf)
export STRIP_FOR_TARGET := $(shell which arm-none-eabi-strip)
export CFLAGS_FOR_TARGET := $(ARCH_FLAGS)
export LDFLAGS_FOR_TARGET := $(ARCH_LDFLAGS)

all: $(BUILD_DIR) libgcc repack

clean:
	make -C $(GCC_BUILD_DIR) -j $(shell nproc) clean
	make -C $(GCC_BUILD_DIR) -j $(shell nproc) distclean

distclean:
	rm -rf $(BUILD_DIR)

libgcc: $(GCC_FILE) $(GCC_DIR)
	mkdir -p $(GCC_BUILD_DIR) $(CACHE_DIR)
	cd $(GCC_BUILD_DIR) && $(GCC_DIR)/configure \
		--target=arm-none-eabi \
		--disable-decimal-float \
		--disable-libffi \
		--disable-libgomp \
		--disable-libmudflap \
		--disable-libquadmath \
		--disable-libssp \
		--disable-libstdcxx-pch \
		--disable-nls \
		--disable-shared \
		--disable-threads \
		--disable-tls \
		--enable-long-long \
		--without-headers \
		--enable-interwork \
		--disable-fpu \
		--disable-gcov \
		--enable-languages=c,c++
	make -C $(GCC_BUILD_DIR) -j $(shell nproc) all-gcc
	make -C $(GCC_BUILD_DIR) -j $(shell nproc) all-target-libgcc

repack:
	./repack.sh $(GCC_BUILD_DIR)/gcc/thumb/libgcc.a

$(BUILD_DIR):
	mkdir -p $@

$(GCC_DIR):
	tar -C $(BUILD_DIR) -xpf $(GCC_FILE)
	cd $(GCC_DIR) && ./contrib/download_prerequisites

$(GCC_FILE):
	wget $(GCC_URL) -O $@

.PHONY: all clean distclean libgcc repack
