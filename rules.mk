# Required variables:
# SIE_DEV	- path to the sie-dev submodule.
# PROJECT	- name of the project, for example: crack-for-jww87
# SOURCES	- list of *.c, *.cpp, *.cc, *.s, *.S files.
#
# Optional variables:
# TARGETS		- list of the siemens targets: NSG, SG, ELKA, ANY
# BUILD_TYPE	- type of project: exe (.elf), lib (.so), archive (.a)
# DEFINES		- additional defines, example: -DDEBUG=1
# INCLUDES		- additional includes, example: -I./somelib
# LDLIBS		- required libs, example: -lcrt-1.0 -lcrt-helper
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
CXXSTD ?= -std=c++11
BUILD_TYPE ?= exe
ARCH_FLAGS ?= -msoft-float -fshort-wchar -mlittle-endian -mcpu=arm926ej-s -zmax-page-size=1

PREFIX	?= arm-none-eabi-
CC		= $(PREFIX)gcc
CXX		= $(PREFIX)g++
LD		= $(PREFIX)gcc
AR		= $(PREFIX)ar

SIEDEV_INC = $(SIEDEV_DIR)/include
INCLUDES += $(patsubst %,-I%, . $(SIEDEV_INC))

OUTPUT_EXT := elf
ifeq ($(BUILD_TYPE),lib)
	OUTPUT_EXT := so
	LIB_SONAME ?= $(PROJECT).$(OUTPUT_EXT)
else ifeq ($(BUILD_TYPE),archive)
	OUTPUT_EXT := a
endif

OUTPUT_NAME := $(PROJECT)$(OUTPUT_POSTFIX)
BUILD_DIR ?= bin/$(TARGET)

OBJECTS := $(SOURCES:%=$(BUILD_DIR)/%)
OBJECTS := $(OBJECTS:%.c=%.o)
OBJECTS := $(OBJECTS:%.cpp=%.o)
OBJECTS := $(OBJECTS:%.cc=%.o)
OBJECTS := $(OBJECTS:%.S=%.o)

ifeq ($(TARGET),ELKA)
DEFINES += -DNEWSGOLD -DELKA
else ifeq ($(TARGET),NSG)
DEFINES += -DNEWSGOLD
else ifeq ($(TARGET),SG)
DEFINES += -DSGOLD
endif

# Compiler flags
TARGET_COMMON_FLAGS := -finput-charset=UTF-8 -fexec-charset=cp1251
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
TARGET_LDFLAGS := $(ARCH_FLAGS) -L$(SIEDEV_DIR)/lib -nostartfiles
TARGET_LDFLAGS += -Wl,-shared -Wl,-Bsymbolic -Wl,-Bsymbolic-function -Wl,-s -Wl,-soname=$(LIB_SONAME)
else ifeq ($(BUILD_TYPE),exe)
TARGET_LDFLAGS := $(ARCH_FLAGS) -L$(SIEDEV_DIR)/lib -nostartfiles
TARGET_LDFLAGS += $(ARCH_FLAGS) -Wl,-s -Wl,-pie
else ifeq ($(BUILD_TYPE),archive)
TARGET_LDFLAGS := $(ARCH_FLAGS) -L$(SIEDEV_DIR)/lib -nostartfiles
TARGET_LDFLAGS += $(ARCH_FLAGS) -Wl,-s -Wl,-pie
endif
TARGET_LDFLAGS += -fno-builtin -nostdlib -nodefaultlibs -Wl,--gc-sections
TARGET_LDFLAGS += $(LDFLAGS)

# AR flags
TARGET_ARFLAGS := rcsD

all: $(OUTPUT_NAME).$(OUTPUT_EXT)

$(BUILD_DIR)/%.o: %.c
	@printf "  CC\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(TARGET_CFLAGS) -o $@ -c $<

$(BUILD_DIR)/%.o: %.cpp
	@printf "  CXX\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CXX) $(TARGET_CXXFLAGS) -o $@ -c $<

$(BUILD_DIR)/%.o: %.cc
	@printf "  CXX\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CXX) $(TARGET_CXXFLAGS) -o $@ -c $<

$(BUILD_DIR)/%.o: %.S
	@printf "  AS\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(TARGET_AFLAGS) -o $@ -c $<

$(OUTPUT_NAME).elf: $(OBJECTS)
	@printf "  LD\t$@\n"
	$(Q)$(LD) $(TARGET_LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

$(OUTPUT_NAME).so: $(OBJECTS)
	@printf "  LD\t$@\n"
	$(Q)$(LD) $(TARGET_LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

$(OUTPUT_NAME).a: $(OBJECTS)
	@printf "  AR\t$@\n"
	$(Q)$(AR) $(TARGET_ARFLAGS) $@ $(OBJECTS)

clean:
	rm -f $(OUTPUT_NAME).$(OUTPUT_EXT)
	rm -rf $(BUILD_DIR)

.PHONY: all clean
