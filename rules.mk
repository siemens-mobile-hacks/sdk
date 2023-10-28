# Required variables:
# SDK_PATH	- path to the this sdk.
# PROJECT	- name of the project, for example: crack-for-jww87
# SOURCES	- list of *.c, *.cpp, *.cc, *.s, *.S files.
#
# Optional variables:
# TARGETS		- list of the siemens targets: NSG, SG, ELKA
# BUILD_TYPE	- type of project: exe (.elf), lib (.so), archive (.a)
# DEFINES		- additional defines, example: -DDEBUG=1
# INCLUDES		- additional includes, example: -I./somelib
# LDLIBS		- required libs, example: -lcrt -lcrt-helper -lgcc
#
# OPT			- optimization level (default -Os).
# CSTD			- C language standart (default -std=c11).
# CXXSTD		- C++ language standart (default -std=c++11).
# CXX_TYPE		- Type of C++ library: uclibc++ or libcxx
#
# LIB_VERSION	- version of library
#
# CPPFLAGS		- additional gcc flags for C/ASM/C++.
# CFLAGS		- additional gcc flags for C.
# AFLAGS		- additional gcc flags for ASM.
# CXXFLAGS		- additional gcc flags for C++.
# LDFLAGS		- additional ld flags.
#
# Development variables:
# NO_DEFAULT_RULES - Don't define "all" and "clean" recipes.
# --------------------------------------------------------------------------------------------------

OPT ?= -Os
CSTD ?= -std=c11
BUILD_TYPE ?= exe
LIBDIRS ?=
SOURCE_ENCODING ?= utf-8
CXX_TYPE ?= libcxx

LIB_VERSION ?= 
WARNINGS ?= -Wall -Wno-main

# Be silent by default, but 'make V=1' will show all compiler calls.
# If you're insane, V=99 will print out all sorts of things.
V?=0
ifeq ($(V),0)
	Q := @
endif

# Toolchain
PREFIX ?= arm-none-eabi-
CC := $(PREFIX)gcc
CXX := $(PREFIX)g++
LD := $(PREFIX)ld
AR := $(PREFIX)ar

# Output directories
ifeq ($(USE_EMULATOR),1)
	BUILD_DIR ?= bin-emulator
	LIB_OUT_DIR ?= lib-emulator
else
	BUILD_DIR ?= bin
	LIB_OUT_DIR ?= lib
endif

# Default includes & defines
ifeq ($(CXX_TYPE),libcxx)
	CXXSTD ?= -std=gnu++11
	INCLUDES += -I$(SDK_PATH)/libc++/abi/include
	INCLUDES += -I$(SDK_PATH)/libc++/include
else ifeq ($(CXX_TYPE),uclibc++)
	CXXSTD ?= -std=gnu++11
	INCLUDES += -I$(SDK_PATH)/libuc++/include
endif

INCLUDES += -I$(SDK_PATH)/include
INCLUDES += -I$(SDK_PATH)/dietlibc/include
INCLUDES += -I$(SDK_PATH)/libjpeg/include

DEFINES += -D__arm__
DEFINES += -D__ARM_EABI__

# Target specific settings
ifeq ($(TARGET),ELKA)
	DEFINES += -DNEWSGOLD -DELKA
	LIBDIRS += -L$(SDK_PATH)/lib/ELKA -L$(SDK_PATH)/lib/NSG
	OUTPUT_POSTFIX ?= _ELKA
else ifeq ($(TARGET),NSG)
	DEFINES += -DNEWSGOLD
	LIBDIRS += -L$(SDK_PATH)/lib/NSG
	OUTPUT_POSTFIX ?= _NSG
else ifeq ($(TARGET),SG)
	DEFINES += -DSGOLD
	LIBDIRS += -L$(SDK_PATH)/lib/SG
	OUTPUT_POSTFIX ?= _SG
endif
LIBDIRS += -L$(SDK_PATH)/lib

# Build type specific settings
OUTPUT_EXT := elf
ifeq ($(BUILD_TYPE),lib)
	OUTPUT_EXT := so
	
	ifeq ($(LIB_VERSION),)
		SONAME := $(PROJECT).$(OUTPUT_EXT)
		OUTPUT_FILENAME := $(LIB_OUT_DIR)/$(SONAME)
	else
		SONAME := $(PROJECT)-$(LIB_VERSION).$(OUTPUT_EXT)
		OUTPUT_FILENAME := $(LIB_OUT_DIR)/$(SONAME)
		
		ifneq ($(LIB_SYMLINK_NAME),)
			OUTPUT_SYMLINK := $(LIB_OUT_DIR)/$(LIB_SYMLINK_NAME).$(OUTPUT_EXT)
		else
			OUTPUT_SYMLINK := $(LIB_OUT_DIR)/$(PROJECT).$(OUTPUT_EXT)
		endif
	endif
else ifeq ($(BUILD_TYPE),archive)
	OUTPUT_EXT := a
	OUTPUT_FILENAME := $(LIB_OUT_DIR)/$(PROJECT).$(OUTPUT_EXT)
else ifeq ($(BUILD_TYPE),exe)
	OUTPUT_FILENAME := $(PROJECT)$(OUTPUT_POSTFIX).$(OUTPUT_EXT)
endif

# --------------------------------------------------------------------------------------------------

# Reproductive builds
export SOURCE_DATE_EPOCH := 1172750400
CPPFLAGS += -frandom-seed=0

# Common flags
TARGET_COMMON_FLAGS := -msoft-float -fshort-wchar -mlittle-endian -mcpu=arm926ej-s -mthumb-interwork
TARGET_COMMON_FLAGS += -fno-builtin -nodefaultlibs -nostdlib -nostdinc $(WARNINGS) $(CPPFLAGS)
ifneq ($(SOURCE_ENCODING),cp1251)
	TARGET_COMMON_FLAGS += -finput-charset=$(SOURCE_ENCODING) -fexec-charset=cp1251
endif

# C flags
TARGET_CFLAGS := $(CSTD) $(OPT) $(DEFINES) $(INCLUDES) $(TARGET_COMMON_FLAGS)
TARGET_CFLAGS += -fno-common -ffunction-sections -fdata-sections
TARGET_CFLAGS += $(CFLAGS)

# C++ flags
TARGET_CXXFLAGS := $(CXXSTD) $(OPT) $(DEFINES) $(INCLUDES) $(TARGET_COMMON_FLAGS) -nostdinc++
TARGET_CXXFLAGS += -fno-common -ffunction-sections -fdata-sections
TARGET_CXXFLAGS += -fno-enforce-eh-specs -fno-use-cxa-get-exception-ptr -fno-non-call-exceptions -fno-exceptions -fpermissive
TARGET_CXXFLAGS += $(CXXFLAGS)

# ASM flags
TARGET_AFLAGS := $(OPT) $(DEFINES) $(INCLUDES) $(AFLAGS)
TARGET_AFLAGS += $(TARGET_COMMON_FLAGS)

# Linker flags
ifeq ($(USE_EMULATOR),1)
	TARGET_LDFLAGS := --defsym=__dso_handle=0 --dynamic-linker=/usr/arm-linux-gnueabi/lib/ld-linux.so.3 -g
else
	TARGET_LDFLAGS := --defsym=__dso_handle=0 -zmax-page-size=1 -s
endif

ifeq ($(BUILD_TYPE),lib)
	TARGET_LDFLAGS += $(LIBDIRS)
	TARGET_LDFLAGS += -shared -Bsymbolic -Bsymbolic-function -soname=$(SONAME)
else ifeq ($(BUILD_TYPE),exe)
	TARGET_LDFLAGS += $(LIBDIRS) -pie
else ifeq ($(BUILD_TYPE),archive)
	TARGET_LDFLAGS += $(LIBDIRS) -pie
endif

TARGET_LDFLAGS += -nostdlib --gc-sections
TARGET_LDFLAGS += $(LDFLAGS)

# AR flags
TARGET_ARFLAGS := rcsD

# Generated files for clean
GENERATED_FILES += $(OUTPUT_FILENAME) $(BUILD_DIR) $(LIB_OUT_DIR)

# --------------------------------------------------------------------------------------------------

OBJECTS := $(SOURCES:%=$(BUILD_DIR)/%)
OBJECTS := $(OBJECTS:%.c=%.o)
OBJECTS := $(OBJECTS:%.cpp=%.o)
OBJECTS := $(OBJECTS:%.cc=%.o)
OBJECTS := $(OBJECTS:%.S=%.o)
OBJECTS := $(OBJECTS:%.s=%.o)

DEPENDS := $(OBJECTS:%.o=%.d)

.SECONDARY: $(OBJECTS)

ifndef NO_DEFAULT_RULES

all: target_compile
clean: target_clean
.PHONY: all clean

endif

target_message:
	@echo "Building $(BUILD_TYPE) for $(TARGET) -> $(OUTPUT_FILENAME)"

target_compile: $(OUTPUT_FILENAME)

%.elf: $(OBJECTS)
	@printf "  LD\t$@\n"
	$(Q)$(LD) $(TARGET_LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.so: $(OBJECTS)
	@printf "  LD\t$@\n"
	@mkdir -p $(LIB_OUT_DIR)
	$(Q)$(LD) $(TARGET_LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@
	@[ -z "$(OUTPUT_SYMLINK)" ] || ln -sf $(SONAME) $(OUTPUT_SYMLINK)

%.a: $(OBJECTS)
	@printf "  AR\t$@\n"
	@mkdir -p $(LIB_OUT_DIR)
	$(Q)$(AR) $(TARGET_ARFLAGS) $@ $(OBJECTS)

-include $(DEPENDS)

$(BUILD_DIR)/%.o: %.c
	@printf "  CC\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(TARGET_CFLAGS) -c $< -o $@ -MMD -MP

$(BUILD_DIR)/%.o: %.cpp
	@printf "  CXX\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CXX) $(TARGET_CXXFLAGS) -c $< -o $@ -MMD -MP

$(BUILD_DIR)/%.o: %.cc
	@printf "  CXX\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CXX) $(TARGET_CXXFLAGS) -c $< -o $@ -MMD -MP

$(BUILD_DIR)/%.o: %.S
	@printf "  AS\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(TARGET_AFLAGS) -c $< -o $@ -MMD -MP

$(BUILD_DIR)/%.o: %.s
	@printf "  AS\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(TARGET_AFLAGS) -c $< -o $@ -MMD -MP

target_clean:
	@rm -rf $(GENERATED_FILES)

.PHONY: target_compile target_clean target_message
