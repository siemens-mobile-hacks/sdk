# Required variables:
# SDK_PATH	- path to the this sdk.
# PROJECT	- name of the project, for example: crack-for-jww87
# SOURCES	- list of *.c, *.cpp, *.cc, *.s, *.S files.
#
# Optional variables:
# TARGETS		- list of the siemens targets: NSG, SG, ELKA, ANY
# BUILD_TYPE	- type of project: exe (.elf), lib (.so), archive (.a)
# DEFINES		- additional defines, example: -DDEBUG=1
# INCLUDES		- additional includes, example: -I./somelib
# LDLIBS		- required libs, example: -lcrt -lcrt-helper -lgcc
#
# OPT			- optimization level (default -Os).
# CSTD			- C language standart (default -std=c11).
# CXXSTD		- C++ language standart (default -std=c++11).
#
# LIB_SONAME	- override library soname (default: $(PROJECT).so).
#
# CFLAGS		- additional gcc flags for C.
# AFLAGS		- additional gcc flags for ASM.
# CXXFLAGS		- additional gcc flags for C++.
# LDFLAGS		- additional ld flags.
# --------------------------------------------------------------------------------------------------

OPT ?= -Os
CSTD ?= -std=c11
CXXSTD ?= -std=gnu++98
BUILD_TYPE ?= exe
ARCH_FLAGS ?= -msoft-float -fshort-wchar -mlittle-endian -mcpu=arm926ej-s -mthumb-interwork
ARCH_LDFLAGS ?= -zmax-page-size=1
LIBDIRS ?=
SOURCE_ENCODING ?= utf-8

PREFIX	?= arm-none-eabi-
CC		= $(PREFIX)gcc
CXX		= $(PREFIX)g++
LD		= $(PREFIX)ld
AR		= $(PREFIX)ar

INCLUDES += -I$(SDK_PATH)/include
INCLUDES += -I$(SDK_PATH)/libuclibc++/include
INCLUDES += -I$(SDK_PATH)/libjpeg/include

BUILD_DIR ?= bin/$(TARGET)
LIB_OUT_DIR ?= lib/$(TARGET)

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

OUTPUT_EXT := elf
ifeq ($(BUILD_TYPE),lib)
	OUTPUT_EXT := so
	LIB_SONAME ?= $(PROJECT).$(OUTPUT_EXT)
	OUTPUT_FILENAME := lib/$(TARGET)/$(PROJECT).$(OUTPUT_EXT)
else ifeq ($(BUILD_TYPE),archive)
	OUTPUT_EXT := a
	OUTPUT_FILENAME := $(LIB_OUT_DIR)/$(PROJECT).$(OUTPUT_EXT)
else ifeq ($(BUILD_TYPE),exe)
	OUTPUT_FILENAME := $(PROJECT)$(OUTPUT_POSTFIX).$(OUTPUT_EXT)
endif

OBJECTS := $(SOURCES:%=$(BUILD_DIR)/%)
OBJECTS := $(OBJECTS:%.c=%.o)
OBJECTS := $(OBJECTS:%.cpp=%.o)
OBJECTS := $(OBJECTS:%.cc=%.o)
OBJECTS := $(OBJECTS:%.S=%.o)
OBJECTS := $(OBJECTS:%.s=%.o)

DEPENDS := $(OBJECTS:%.o=%.d)

# Compiler flags
ifneq ($(SOURCE_ENCODING),cp1251)
	TARGET_COMMON_FLAGS := -finput-charset=$(SOURCE_ENCODING) -fexec-charset=cp1251
endif
TARGET_COMMON_FLAGS += -fno-builtin -nodefaultlibs -nostdlib -nostdinc

TARGET_CFLAGS := $(CSTD) $(OPT) $(DEFINES) $(INCLUDES) $(ARCH_FLAGS) $(TARGET_COMMON_FLAGS)
TARGET_CFLAGS += -fno-common -ffunction-sections -fdata-sections
TARGET_CFLAGS += -Wextra -Wshadow -Wno-unused-variable -Wno-unused-parameter -Wno-strict-prototypes -Wno-main -Wimplicit-function-declaration
TARGET_CFLAGS += -Wredundant-decls -Wmissing-prototypes
TARGET_CFLAGS += $(CFLAGS)

TARGET_CXXFLAGS := $(CXXSTD) $(OPT) $(DEFINES) $(INCLUDES) $(ARCH_FLAGS) $(TARGET_COMMON_FLAGS) -nostdinc++
TARGET_CXXFLAGS += -fno-common -ffunction-sections -fdata-sections -Wno-main -Wno-unused-parameter
TARGET_CXXFLAGS += -fno-enforce-eh-specs -fno-use-cxa-get-exception-ptr -fno-non-call-exceptions -fno-exceptions
TARGET_CXXFLAGS += -Wextra -Wshadow -Wredundant-decls
TARGET_CXXFLAGS += $(CXXFLAGS)

TARGET_AFLAGS := $(OPT) $(DEFINES) $(ARCH_FLAGS) $(INCLUDES) $(AFLAGS)
TARGET_AFLAGS += $(TARGET_COMMON_FLAGS)

# Linker flags
ifeq ($(BUILD_TYPE),lib)
TARGET_LDFLAGS := $(ARCH_LDFLAGS) $(LIBDIRS)
TARGET_LDFLAGS += -shared -Bsymbolic -Bsymbolic-function -s -soname=$(LIB_SONAME)
else ifeq ($(BUILD_TYPE),exe)
TARGET_LDFLAGS := $(ARCH_LDFLAGS) $(LIBDIRS) -s -pie
else ifeq ($(BUILD_TYPE),archive)
TARGET_LDFLAGS := $(ARCH_LDFLAGS) $(LIBDIRS) -s -pie
endif
TARGET_LDFLAGS += -nostdlib --gc-sections
TARGET_LDFLAGS += $(LDFLAGS)

# AR flags
TARGET_ARFLAGS := rcsD

all: $(LIB_OUT_DIR) $(OUTPUT_FILENAME)

$(LIB_OUT_DIR):
	mkdir -p $(LIB_OUT_DIR)

$(BUILD_DIR)/%.o: %.c
	@printf "  CC\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(TARGET_CFLAGS) -MMD -MP -o $@ -c $<

$(BUILD_DIR)/%.o: %.cpp
	@printf "  CXX\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CXX) $(TARGET_CXXFLAGS) -MMD -MP -o $@ -c $<

$(BUILD_DIR)/%.o: %.cc
	@printf "  CXX\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CXX) $(TARGET_CXXFLAGS) -MMD -MP -o $@ -c $<

$(BUILD_DIR)/%.o: %.S
	@printf "  AS\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(TARGET_AFLAGS) -MMD -MP -o $@ -c $<

$(BUILD_DIR)/%.o: %.s
	@printf "  AS\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(TARGET_AFLAGS) -MMD -MP -o $@ -c $<

%.elf: $(OBJECTS)
	@printf "  LD\t$@\n"
	$(Q)$(LD) $(TARGET_LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.so: $(OBJECTS)
	@printf "  LD\t$@\n"
	$(Q)$(LD) $(TARGET_LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.a: $(OBJECTS)
	@printf "  AR\t$@\n"
	$(Q)$(AR) $(TARGET_ARFLAGS) $@ $(OBJECTS)

-include $(DEPENDS)

clean:
	rm -f $(OUTPUT_FILENAME)
	rm -rf $(BUILD_DIR) $(LIB_OUT_DIR)

.PHONY: all clean
