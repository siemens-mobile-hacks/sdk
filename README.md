# sdk

# Libs
| Name | Required | Description
| --- | --- | --- |
| libcrt.a | Yes | C runtime. This lib is required for all executables (.elf). |
| libcrt_helper.so | Yes | Helper for C runtime. This lib required for both `.elf` and `.so` |
| libgcc.a | Yes | GCC helper library which is required for any code compiled by GCC. |
| libgcc-4.6.1.so | No | Legacy GCC helper library, do not use it in new projects! Used only for compatibility with old ELF's. |
| libc-1.0.so | No | Lightweight libc (dietlibc) ported for Siemens. |
| libm-1.0.so | No | Lightweight libm (openlibm). Required when you use <math.h> functions. |
| libstdc++-1.2.2.so libucsup++.a | No | uclibc++ library for the C++98 support. |
|  |
| libjpeg-62.so | No  | Library for encoding and decoding JPEG. |
| libpng-12.so | No  | Library for encoding and decoding PNG. |
| libz-1.2.5.so | No  | Library for gzip/inflate/deflate compression (zlib). |
