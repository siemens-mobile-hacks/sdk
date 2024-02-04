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
- [How to use SDK - for beginners](https://github.com/siemens-mobile-hacks/sdk/blob/master/docs/how_make_elfs.md)


# C core libs
| Name | Required | Description
| --- | --- | --- |
| -lcrt | Yes | C runtime. This lib is required for all executables (.elf). |
| -lcrt_helper | Yes | Helper for C runtime. This lib required for both `.elf` and `.so` |
| -lgcc | Yes | GCC helper library which is required for any code compiled by GCC. |
| -lc | No | Lightweight libc (dietlibc) ported for Siemens. |
| -lm | No | Lightweight libm (openlibm). Required when you use <math.h> functions. |

# C++11 core libs
| Name | Required | Description
| --- | --- | --- |
| -lc++ | Yes | LLVM libcxxx library for C++11 support. |
| -lsupc++ | Yes | C++ ABI for gcc. |

# C++98 core libs (legacy)
| Name | Required | Description |
| --- | --- | --- |
| -luc++ | Yes | uClibc++ library for C++98 support. |
| -lsupc++ | Yes | ABI for gcc. |

# Data processing libs
| Name | Required | Description |
| --- | --- | --- |
| -ljpeg | No  | Library for encoding and decoding JPEG. |
| -lpng | No  | Library for encoding and decoding PNG. |
| -lz | No  | Library for gzip/inflate/deflate compression (zlib). |
