# Siemens ELF's SDK
This SDK is an attempt to unify tools and the environment for creating ELF's for Siemens mobile phones.

SDK mainly focused on ELFLoader 3.0+, shared libs and ARM GCC as the compiler.

Main features:
- We use modern and open-source tools for building.
- A lot of shared libs are available by default.
- Two build systems: cmake and Makefile.
- Easy to use.
- Compiler-neutral swilib. You can still use some parts of this SDK with IAR (coming soon).

# Docs
- SDK:
    - [How to use SDK - for beginners](https://github.com/siemens-mobile-hacks/sdk/blob/master/docs/how_make_elfs.md)
    - [Available shared libs](https://github.com/siemens-mobile-hacks/sdk#available-shared-libs)

- Building
    - [Advanced options for Makefile](https://github.com/siemens-mobile-hacks/sdk#advanced-options-for-makefile)
    - [Tips and Tricks for Makefile](https://github.com/siemens-mobile-hacks/sdk#tips-and-tricks-for-makefile)
    - [Advanced options for Cmake](https://github.com/siemens-mobile-hacks/sdk#advanced-options-for-cmake)

# SDK structure
```
sdk/
├── lib/         <-- compilled shared libs
│   ├── legacy/      <-- dir with legacy libs for some old ELF's
│   ├── ELKA/        <-- dir with libs for NewSGOLD phones: E71, EL71
│   ├── NSG/         <-- dir with libs for NewSGOLD phones: C81, S75, SL75, S68
│   ├── SG/          <-- dir with libs for SGOLD phones: CX75 and other old SIEMENS
│   ├── libXXX.so    <-- Platform-neutral libs for any phone
│   ├── libYYY.so
│   └── ...
├── swilib/      <-- functions library for IAR and GCC
│   ├── include/     <-- swilib headers
│   └── patterns/    <-- swilib patterns
├── include/     <-- common headers
├── libXXX/      <-- static or shared library
│   ├── src/         <-- library source
│   └── include/     <-- library headers
└── tools/       <-- tools and utils for the maintenance

```

# Available shared libs

**C core libs**
| Name | Required | Description |
| --- | --- | --- |
| -lcrt | Yes | C runtime. This lib is required for all executables (.elf). |
| -lcrt_helper | Yes | Helper for C runtime. This lib required for both `.elf` and `.so` |
| -lgcc | Yes | GCC helper library which is required for any code compiled by GCC. |
| -lc | No | Lightweight libc (dietlibc) ported for Siemens. |
| -lm | No | Lightweight libm (openlibm). Required when you use <math.h> functions. |

**C++11 core libs**
| Name | Required | Description |
| --- | --- | --- |
| -lc++ | Yes | LLVM libcxxx library for C++11 support. |
| -lsupc++ | Yes | C++ ABI for gcc. |

**C++98 core libs (legacy)**
| Name | Required | Description |
| --- | --- | --- |
| -luc++ | Yes | uClibc++ library for C++98 support. |
| -lsupc++ | Yes | ABI for gcc. |

**Data processing libs**
| Name | Required | Description |
| --- | --- | --- |
| -ljpeg | No  | Library for encoding and decoding JPEG. |
| -lpng | No  | Library for encoding and decoding PNG. |
| -lz | No  | Library for gzip/inflate/deflate compression (zlib). |

# Advanced options for Makefile

We have two variants of the Makefile buildsystem:
1. `multi-target.mk` - Build ELF for multiple platforms simultaneously.
    
    How to use:
    
    ```Makefile
    TARGETS := NSG SG ELKA
    # ... other options ...
    SDK_PATH ?= ../sdk
    include $(SDK_PATH)/multi-target.mk
    ```

    This work using recalling a Makefile by itself with different parameters.

2. `rules.mk` - Build ELF for a single platform.
    
    How to use:
    
    ```Makefile
    TARGET := NSG
    # ... other options ...
    SDK_PATH ?= ../sdk
    include $(SDK_PATH)/rules.mk
    ```

**Required options:**
| Option | Description | Example |
| --- | --- | --- |
| PROJECT | Name of the ELF or LIB | `PROJECT := crack-for-jww87` |
| SDK_PATH | Path to this sdk | `SDK_PATH := ../sdk` |
| SOURCES | List of *.c, *.cpp, *.cc, *.s, *.S files. | `SOURCES := main.c test.S` |
| LDLIBS | Required libs | `LDLIBS := -lcrt -lcrt-helper -lgcc` |
| **Only for `multi-target.mk`** |
| TARGETS | List of the Siemens targets | `TARGETS := NSG SG ELKA` |
| **Only for `rules.mk`** |
| TARGET | Build target | `TARGET := NSG` |

**Advanced options:**
| Option | Description | Default |
| --- | --- | --- |
| V | Debug level, 0-99 | 0 |
| BUILD_TYPE | Type of project: exe (.elf), lib (.so), archive (.a) | exe |
| LIB_VERSION | Version of shared lib (only for BUILD_TYPE=lib) |
| LIB_SYMLINK_NAME | Custom name of the library symlink (only if `LIB_VERSION` was set) | `$(PROJECT).so` |
| OPT | Optimization level | -Os |
| CSTD | C language standart | -std=c11 |
| CXXSTD | C++ language standart | -std=c++11 |
| CXX_TYPE | Type of C++ library: uclibc++ or libcxx | libcxx |
| INCLUDES | Additional preprocessor includes, example: `-Isome_lib` |  |
| DEFINES | Additional preprocessor defines, example: `-DDEBUG` | |
| CPPFLAGS | Additional compiler flags for C/C+/ASM |  |
| CFLAGS | Additional compiler flags for C |  |
| AFLAGS | Additional compiler flags for ASM |  |
| CXXFLAGS | Additional compiler flags for C++ |  |
| LDFLAGS | Additional linker flags |  |

**Customization:**
| Option | Description | Default |
| --- | --- | --- |
| PREFIX | Prefix of the compiler | arm-none-eabi- |
| CC | Name of the C compiler executable | `$(PREFIX)gcc` |
| CXX | Name of the C++ compiler executable | `$(PREFIX)g++` |
| LD | Name of the linker executable | `$(PREFIX)ld` |
| AR | Name of the archive tool executable | `$(PREFIX)ar` |
| LIB_OUT_DIR | Output dir for libs | lib |
| BUILD_DIR | Output dir for temporary files | bin |
| SOURCE_ENCODING | Encoding of your sources. Used as argument for `-finput-charset`. | utf-8 |
| OUTPUT_ENCODING | Target encoding of your sources. Used as argument for `-fexec-charset`. | cp1251 |
| NO_DEFAULT_RULES | Don't define `all` and `clean` recipes. Useful when you want to define your own `all` and `clean` recipes in the Makefile. You can use `target_clean` / `target_compile` instead. | 0 |

**Output variables:**
| Variable | Description | Example |
| --- | --- | --- |
| OUTPUT_FILENAME | Path to the output file | hello-world_ELKA.elf |
| OUTPUT_SYMLINK | Path to the lib symlink, if `LIB_VERSION` was set | libpng.so |

# Tips and Tricks for Makefile
1. Custom recipes.
    
    ```Makefile
    # .... other makefile contents ....
    include $(SDK_PATH)/multi-target.mk # Add any custom recipes strongly AFTER this line!
    
    ifdef TARGET # <-- Required for multi-target.mk
    
    # Install ELF to the phone
    install: all
        obexftp -b 00:XX:XX:XX:XX:XX -c Data\\Misc --put $(OUTPUT_FILENAME)
    
    endif
    ```
2. Customize options by target.
    
    ```Makefile
    # .... other makefile contents ....
    
    ifdef TARGET # <-- Required for multi-target.mk
        ifeq ($(TARGET),ELKA)
            DEFINES += -DSOME_DEFINE_ONLY_FOR_ELKA
        endif
    endif
    
    include $(SDK_PATH)/multi-target.mk # Add any options strongly BEFORE this line!
    ```
3. Own `all` and `clean` recipes.
    
    ```Makefile
    NO_DEFAULT_RULES := 1
    
    # .... other makefile contents ....
    include $(SDK_PATH)/multi-target.mk # Add any custom recipes strongly AFTER this line!
    
    ifdef TARGET # <-- Required for multi-target.mk
    
    all: target_compile
        echo "Compile!"
    clean: target_clean
        echo "Clean!"
    
    .PHONY: all clean
    
    endif
    ```

# Advanced options for Cmake

**Properties:**
| Option | Description | Default |
| --- | --- | --- |
| TOOLCHAIN | Toolchain prefix | arm-none-eabi |
| SOURCE_ENCODING | Encoding of your sources. Used as argument for `-finput-charset`. | utf-8 |
| OUTPUT_ENCODING | Target encoding of your sources. Used as argument for `-fexec-charset`. | cp1251 |
| CXX_TYPE | Type of C++ library: uclibc++ or libcxx | libcxx |
**Important:** set these properties before `config.cmake` inclusion.

**Functions:**
| Function | Description | Example |
| --- | --- | --- |
| `target_sdk_setup(target, platform)` | Set platform type (SG|NSG|ELKA) for the target executable or library | `target_sdk_setup(hello_world, NSG)` |
