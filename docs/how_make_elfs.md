# How to use SDK - for beginners
SDK provides easy tools for creating ELF's without special skills.

All you need to do is just write code :)

The SDK uses CMake as its build system.

# Prerequisites
1. Recommended OS: OSX, BSD or Linux.
   
   \* On Windows you can use: [Windows Subsystem for Linux](https://learn.microsoft.com/en-us/windows/wsl/install) or [Cygwin](https://www.cygwin.com/) (not tested).
2. Required software:
    
    **Ubuntu/Debian/WSL**
    ```bash
    sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi cmake
    ```
    
    **OSX**
    ```bash
    brew install arm-none-eabi-binutils cmake
    ```
    
    Also, you can use the official ARM toolchains: [Arm GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)

# Get SDK and right filesystem structure
We expect file structure like this:
```
/path/to/projects/siemens-elfs <-- your dir with projects
├── sdk/          <--- this SDK at the top level
├── first-elf/    <-- your elfs
├── second-elf/
└── third-elf/
```

You can do something like this:
```bash
# Create folder for ELF projects
mkdir siemens-elfs
cd siemens-elfs

# Clone SDK
git clone https://github.com/siemens-mobile-hacks/sdk

# Create dir for your elf
mkdir hello-world
```

# Write some code
```C
// main.c
#include <swilib.h>

// This is not a classical `main()` as in Linux/Windows programs. This is only the initializer.
// At the exit of this function, ELF is still present in the memory and running.
// Params:
//   exe - path to the this ELF, example: 0:\Misc\test.elf
//   fname - path to the file which is opened by this ELF from explorer.
int main(char *exe, char *fname, void *p1) {
  // Show popup
  ShowMSG(0, (int) "Hello World!");
  
  // Kill ELF (in the background)
  kill_elf();
  
  return 0;
}
```

# Build with CMake
Minimal CMakeLists.txt for building ELF:
```cmake
cmake_minimum_required(VERSION 3.31)

# Required: Include SDK config
include(../sdk/config.cmake)

# Required: define your project
project(hello_world C)

# Required: Specify the required libs for the ELF.
# Minimum required libs for any ELF: crt crt_helper gcc
link_libraries(crt crt_helper gcc)

# Required: your sources
set(SOURCES main.c)

# =================================================================
# Required: add exectutable for ELKA
add_executable(hello_world_ELKA ${SOURCES})
# Required: set platform for this executable
target_sdk_setup(hello_world_ELKA ELKA)
# =================================================================

# =================================================================
# Required: add exectutable for NSG
add_executable(hello_world_NSG ${SOURCES})
# Required: set platform for this executable
target_sdk_setup(hello_world_NSG NSG)
# =================================================================

# =================================================================
# Required: add exectutable for SG
add_executable(hello_world_SG ${SOURCES})
# Required: set platform for this executable
target_sdk_setup(hello_world_SG SG)
# =================================================================
```

You can build your first ELF by this command:
```bash
cmake -B build
cmake --build build
```

After that you will get three files:
  - hello-world_SG.elf
  - hello-world_NSG.elf
  - hello-world_ELKA.elf

# Prepare your phone
Since the SDK uses dynamic libraries, you need to add them to your phone.
There are two ways:

**Simple**
1. Create .zip with all core libs
```
cd sdk
tools/tools/lib-pkg.sh
```
2. Unpack one of these resulting ZIP's to `0:\Zbin\lib` or `4:\Zbin\lib`
```
/tmp/tmp-ep3-libs/
├── libs_compat.zip    <-- this is required only for some old ELF's
├── libs_ELKA.zip      <-- for NewSGOLD phones: E71, EL71
├── libs_NSG.zip       <-- for NewSGOLD phones: C81, S75, SL75, S68
├── libs_SG.zip        <-- for SGOLD phones: CX75 and others old SIEMENS
```

**Manual**

Manual copy required libs from the `sdk/lib` to `0:\Zbin\lib` or `4:\Zbin\lib`

Structure and logic:
```
/path/to/sdk/lib
├── legacy/     <-- dir with legacy libs for some old ELF's
├── ELKA/       <-- dir with libs for NewSGOLD phones: E71, EL71
├── NSG/        <-- dir with libs for NewSGOLD phones: C81, S75, SL75, S68
├── SG/         <-- dir with libs for SGOLD phones: CX75 and other old SIEMENS
├── libXXX.so   <-- Platform-neutral libs for any phone
├── libYYY.so
└── ...
```

⚠️ COPY ONLY **.so** FILES! SKIP **.a** FILES OR SYMLINKS!

# Time to test
Send the right file to your phone and run your first Siemens ELF!

# See also
- Basic examples with SDK: https://github.com/siemens-mobile-hacks/elfs-examples
- Real ELF's using this SDK: https://github.com/siemens-mobile-hacks/elfloader3-elfs-archive
- Complex example with own libs and cmake:
    - https://github.com/siemens-mobile-hacks/sie_files
    - https://github.com/siemens-mobile-hacks/libsie
- Old GCC ELF's archive: https://github.com/siemens-elfloader/st_hunter/tree/master/trunk - useful for code examples
- Old IAR ELF's archive: https://github.com/siemens-mobile-hacks/svn_boba_mirror - useful for code examples
