# EPK packaging

An EPK package is a regular ZIP archive with a `.PKGINFO` file inside.
The format is inspired by [ALPM](https://man.archlinux.org/man/alpm.7.en).

You do not need to create the archive or `.PKGINFO` yourself.
The SDK provides a simple CMake API for building packages.

## Minimal package

```cmake
cmake_minimum_required(VERSION 3.31)
include(../sdk/config.cmake)
project(example VERSION 1.0 LANGUAGES C)

add_executable(example main.c)
target_sdk_setup(example NSG)
target_link_libraries(example PRIVATE crt crt_helper gcc)

epk_install(TARGET example DESTINATION ZBin/Example RENAME Example.elf)
epk_package(
	TARGET example
	NAME example
	PLATFORMS NSG ELKA
	DEPENDS libcrt_helper
)
```

Run `cmake -B build` and `cmake --build build` to create `build/example_1.0-NSG+ELKA.epk`.

## Package with files and a hook

Project files:

```text
example/
├── CMakeLists.txt
├── main.c
├── settings.ini
└── assets/
    ├── url_big.png
    └── url_small.png
```

```cmake
cmake_minimum_required(VERSION 3.31)
include(../sdk/config.cmake)
project(example VERSION 1.0 LANGUAGES C)

add_executable(example main.c)
target_sdk_setup(example NSG)
target_link_libraries(example PRIVATE crt crt_helper gcc)

# Add the executable as ZBin/Example/Example.elf
epk_install(TARGET example DESTINATION ZBin/Example RENAME Example.elf)

# Add settings.ini to ZBin/Example
epk_install(TARGET example FILES settings.ini DESTINATION ZBin/Example)

# Add assets as ZBin/Example/assets
epk_install(TARGET example DIRECTORIES assets DESTINATION ZBin/Example)

# Or add only its contents to ZBin/Example/icons
# epk_install(TARGET example DIRECTORIES assets/ DESTINATION ZBin/Example/icons)

# Register .url files to open with Example.elf
epk_hook(
	TARGET example
	MODULE regext
	FIELDS
		EXTENSION=url
		RUN=ZBin/Example/Example.elf
		BIG=ZBin/Example/assets/url_big.png
		SMALL=ZBin/Example/assets/url_small.png
)

# Define the EPK package
epk_package(
	TARGET example
	NAME example
	PLATFORMS NSG ELKA
	DEPENDS libcrt_helper
	BACKUPS ZBin/Example/settings.ini
)
```

The build creates `build/example_1.0-NSG+ELKA.epk`.

After installation on `0:` (excluding dependencies):

```text
0:\
└── ZBin\
    ├── Example\
    │   ├── Example.elf
    │   ├── settings.ini
    │   └── assets\
    │       ├── url_big.png
    │       └── url_small.png
    └── etc\
        ├── extensions.cfg      # [url] added or updated by regext hook
        └── packages\
            └── example.pkg     # package manager database record
```

## API

`epk_install()` adds files or directories to the package.
Without `FILES` or `DIRECTORIES`, it adds the target's output.

| Field | Description |
| --- | --- |
| `TARGET` | CMake target. |
| `DESTINATION` | Path on the phone, without a leading `/` or drive prefix. |
| `FILES` | Files to copy. Relative paths start next to `CMakeLists.txt`. |
| `DIRECTORIES` | Directories to copy. A trailing `/` copies their contents only. Cannot be combined with `FILES`. |
| `RENAME` | Rename target output or one file. Not valid with `DIRECTORIES`. |

`epk_hook()` adds an action to run when the package is installed, updated, or removed.

| Field | Description |
| --- | --- |
| `TARGET` | CMake target. |
| `MODULE` | Hook module, such as `regext`. |
| `FIELDS` | Module-specific `KEY=VALUE` fields. |

`epk_package()` defines the EPK package.
Call it after all other `epk_*()` functions.

| Field | Description |
| --- | --- |
| `TARGET` | CMake target. |
| `NAME` | Required package name. |
| `RELEASE` | Positive package revision, appended to the version as `-N` (for example, `1.0-2`). |
| `PLATFORMS` | Compatible platforms. Defaults to the target platform. Use `SG`, `X75`, `NSG`, `ELKA`, or `all`. |
| `AUTHOR` | Package author. |
| `DESCRIPTION` | Short description. |
| `GROUPS` | Package groups. |
| `DEPENDS` | Dependencies, optionally with a version constraint such as `libc>=1.0`. |
| `CONFLICTS` | Conflicting packages. Uses the same syntax as `DEPENDS`. |
| `BACKUPS` | Packaged configuration files whose local changes are preserved. |
| `OWNED_DIRECTORIES` | Directories owned recursively by the package. |

## Hooks

### regext

This hook registers a file extension in `ZBin/etc/extensions.cfg`.

```cmake
epk_hook(
	TARGET example
	MODULE regext
	FIELDS
		EXTENSION=url
		RUN=ZBin/Example/Example.elf
		BIG=ZBin/Example/assets/url_big.png
		SMALL=ZBin/Example/assets/url_small.png
)
```

| Field | Description |
| --- | --- |
| `EXTENSION` | Required file extension without a dot, such as `url`. |
| `RUN` | Required path to the program associated with the extension (default action). |
| `ALTRUN` | Optional path to the program for the edit action. |
| `BIG` | Optional large icon path. |
| `SMALL` | Optional small icon path. |

Paths are relative to the installation volume.
Do not include volume (for e.g. `0:`).

The package manager removes its registration when the package is removed.

## Version

By default, the package uses the version set by `project(... VERSION ...)`.

## Backups

`BACKUPS` lists packaged files whose local edits should be preserved.

In the example above, it protects `settings.ini`:

- An unchanged file is replaced on update and deleted when the package is removed.
- On update, the package manager keeps local edits and saves a conflicting new version as `.epknew`.
- On package removal, an edited file is saved as `.epksave`.

If a new default conflicts with local edits, the directory contains:

```text
0:\ZBin\Example\
├── settings.ini          # local edits
└── settings.ini.epknew   # new package default
```

## Regular directories

Removing a package deletes its files but leaves other files in regular directories.
Directories created during installation are removed only if empty.
Existing directories remain.

## Shared directories

Multiple packages can install different files into the same directory.
Examples of shared directories:

- Libraries from different packages in `ZBin/lib`.
- Daemons from different packages in `ZBin/daemons`.
- Plugins from separate packages for an existing app in `ZBin/Example/plugins`.

Removing one package does not remove files installed by other packages.

## Owned directories

The package owns everything inside the directories listed in `OWNED_DIRECTORIES`, including files added later.

To own the `assets` directory from the example above:

```cmake
epk_package(
	TARGET example
	NAME example
	PLATFORMS NSG ELKA
	DEPENDS libcrt_helper
	BACKUPS ZBin/Example/settings.ini
	OWNED_DIRECTORIES ZBin/Example/assets
)
```

- Updating the package deletes files absent from the new archive.
- Removing the package deletes the directory contents, except declared `BACKUPS` and their `.epknew`/`.epksave` files.
- Each owned directory must contain at least one file from the archive and cannot overlap another owned directory.
- Never list a shared directory such as `ZBin/lib` here.
- `epk_install(DIRECTORIES ...)` only copies files. It does not make the package own the directory.
