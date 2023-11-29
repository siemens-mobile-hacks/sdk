# sdk

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
