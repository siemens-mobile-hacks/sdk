# Siemens ELF's SDK
This SDK is an attempt to unify tools and the environment for creating ELF's for Siemens mobile phones.

SDK mainly focused on ELFLoader 3.0+, shared libs and ARM GCC as the compiler.

Main features:
- We use modern and open-source tools for building.
- A lot of shared libs are available by default.
- CMake-based build system.
- Easy to use.
- Compiler-neutral swilib. You can still use some parts of this SDK with IAR (coming soon).

# Docs
- SDK:
    - [How to use SDK - for beginners](https://github.com/siemens-mobile-hacks/sdk/blob/master/docs/how_make_elfs.md)
    - [SWILIB - functions from the firmware](https://github.com/siemens-mobile-hacks/sdk/blob/master/swilib/README.md)
    - [Available shared libs](https://github.com/siemens-mobile-hacks/sdk#available-shared-libs)

- Building
    - [Advanced options for CMake](https://github.com/siemens-mobile-hacks/sdk#advanced-options-for-cmake)
- General examples
    - [Hello World in C](https://github.com/siemens-mobile-hacks/elfs-examples/tree/master/without-shared-libs), without **ANY** shared libs
    - [Hello World in C](https://github.com/siemens-mobile-hacks/elfs-examples/tree/master/hello-world-c), without libc, with libcrt_helper.so
    - [Hello World in C++](https://github.com/siemens-mobile-hacks/elfs-examples/tree/master/hello-world-cpp), without libc, with libcrt_helper.so
    - [Example with libc + libm](https://github.com/siemens-mobile-hacks/elfs-examples/tree/master/example-libc-libm)
    - [Canvas](https://github.com/siemens-mobile-hacks/elfs-examples/tree/master/canvas)

# SDK structure
```
sdk/
├── lib/         <-- compilled shared libs
│   ├── legacy/      <-- dir with legacy libs for some old ELF's
│   ├── ELKA/        <-- dir with libs for NewSGOLD phones: E71, EL71
│   ├── NSG/         <-- dir with libs for NewSGOLD phones: C81, S75, SL75, S68
│   ├── X75/         <-- dir with platform overrides for SGOLD X75 phones
│   ├── SG/          <-- dir with libs for SGOLD phones
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

# Advanced options for CMake

**Properties:**
| Option | Description | Default |
| --- | --- | --- |
| TOOLCHAIN | Toolchain prefix | arm-none-eabi |
| SOURCE_ENCODING | Encoding of your sources. Used as argument for `-finput-charset`. | utf-8 |
| OUTPUT_ENCODING | Target encoding of your sources. Used as argument for `-fexec-charset`. | cp1251 |
| CXX_TYPE | Type of C++ library: uclibc++ or libcxx | libcxx |

**Important:** set these properties before `config.cmake` inclusion.

**Functions:**
| Function | Description |
| --- | --- |
| `target_sdk_setup(target, platform)` | Set platform type (SG/SGOLD, SG_X75/X75, NSG/NEWSGOLD, NSG_ELKA/ELKA) and prepare the final ELF or library.<br>Example: `target_sdk_setup(hello_world, NSG)`|
| `target_sdk_postprocess(target)` | Prepare a target without platform setup and create its debug companion. |

# AI-assisted contributions

We are not against AI. We are against vibe coding, AI slop, and attempts to offload engineering work to a model. This project prioritizes quality, not development speed or results at any cost.

1. **Do not use AI-generated text in human-to-human communication.**

   Write comments, discussions, PR descriptions, and responses to reviewers yourself.

2. **Do not let AI submit PRs or commits.**

   The author must always be a human who has personally reviewed the changes and takes responsibility for them.

4. **Do not submit code primarily designed or written by AI.**

   Architecture, algorithms, code organization, and the final implementation must be decided by a human. AI may only be used as an auxiliary tool.

6. **You must understand all the code you submit.**

   You must be able to explain every change, justify your decisions, and fix any problems yourself. If you do not understand the code, open a feature request instead of a PR.

8. **Code must be simple, clear, and tested.**

   Follow KISS, the project's coding style, and its existing architecture. Do not introduce unnecessary abstractions, dependencies, or untested changes.

AI slop PRs will be closed without review.
