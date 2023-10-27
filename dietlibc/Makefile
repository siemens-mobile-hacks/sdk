PROJECT := libc
LIB_VERSION := 1.0
BUILD_TYPE := lib
TARGETS := NSG SG

CSTD := -std=gnu99
OPT := -Os

CPPFLAGS += -fomit-frame-pointer
CPPFLAGS += -Werror -Wno-implicit-fallthrough -Wno-missing-prototypes -Wno-missing-attributes \
	-Wno-misleading-indentation -Wno-unused-variable -Wno-shift-count-overflow -Wno-nonnull-compare \
	-Wno-unused-but-set-variable -Wno-incompatible-pointer-types
INCLUDES += -Isrc

LDLIBS += -lgcc -lcrt_helper

LDFLAGS += --init=_init
LDFLAGS += --fini=_fini

# ASM sources
SOURCES += src/errlist.S

# C sources
SOURCES += main.c
SOURCES += src/lib/assert_fail.c
SOURCES += src/lib/atexit.c
SOURCES += src/lib/atof.c
SOURCES += src/lib/atol.c
SOURCES += src/lib/abs.c
SOURCES += src/lib/labs.c
SOURCES += src/lib/llabs.c
SOURCES += src/libc.c
SOURCES += src/libc_init.c
SOURCES += src/lib/closedir.c
SOURCES += src/lib/__dtostr.c
SOURCES += src/lib/__isnan.c
SOURCES += src/lib/errlistu.c
SOURCES += src/lib/errno_location.c
SOURCES += src/lib/getopt.c
SOURCES += src/lib/isalnum.c
SOURCES += src/lib/isalpha.c
SOURCES += src/lib/isascii.c
SOURCES += src/lib/isblank.c
SOURCES += src/lib/isdigit.c
SOURCES += src/lib/isgraph.c
SOURCES += src/lib/__isinf.c
SOURCES += src/lib/islower.c
SOURCES += src/lib/isprint.c
SOURCES += src/lib/ispunct.c
SOURCES += src/lib/isspace.c
SOURCES += src/lib/isupper.c
SOURCES += src/lib/isxdigit.c
SOURCES += src/lib/latin1-iscntrl.c
SOURCES += src/lib/__lltostr.c
SOURCES += src/lib/lseek64.c
SOURCES += src/lib/__ltostr.c
SOURCES += src/lib/memccpy.c
SOURCES += src/lib/memchr.c
SOURCES += src/lib/memcmp.c
SOURCES += src/lib/memcpy.c
SOURCES += src/lib/memmove.c
SOURCES += src/lib/memset.c
SOURCES += src/lib/opendir.c
SOURCES += src/lib/perror.c
SOURCES += src/lib/qsort.c
SOURCES += src/lib/rand48.c
SOURCES += src/lib/rand.c
SOURCES += src/lib/rand_r.c
SOURCES += src/lib/readdir.c
SOURCES += src/lib/remove.c
SOURCES += src/lib/rewind.c
SOURCES += src/libshell/fnmatch.c
SOURCES += src/lib/snprintf.c
SOURCES += src/lib/sprintf.c
SOURCES += src/lib/sscanf.c
SOURCES += src/lib/strcasecmp.c
SOURCES += src/lib/strcat.c
SOURCES += src/lib/strchr.c
SOURCES += src/lib/strcmp.c
SOURCES += src/lib/strcpy.c
SOURCES += src/lib/strcspn.c
SOURCES += src/lib/strdup.c
SOURCES += src/lib/strerror.c
SOURCES += src/lib/strlcat.c
SOURCES += src/lib/strlcpy.c
SOURCES += src/lib/strlen.c
SOURCES += src/lib/strncasecmp.c
SOURCES += src/lib/strncat.c
SOURCES += src/lib/strncmp.c
SOURCES += src/lib/strncpy.c
SOURCES += src/lib/strpbrk.c
SOURCES += src/lib/strrchr.c
SOURCES += src/lib/strsep.c
SOURCES += src/lib/strspn.c
SOURCES += src/lib/strstr.c
SOURCES += src/lib/strtod.c
SOURCES += src/lib/strtof.c
SOURCES += src/lib/strtok.c
SOURCES += src/lib/strtok_r.c
SOURCES += src/lib/strtol.c
SOURCES += src/lib/strtold.c
SOURCES += src/lib/strtoll.c
SOURCES += src/lib/strtoul.c
SOURCES += src/lib/strtoull.c
SOURCES += src/lib/strxfrm.c
SOURCES += src/lib/swab.c
SOURCES += src/lib/tolower.c
SOURCES += src/lib/toupper.c
SOURCES += src/lib/uname.c
SOURCES += src/lib/__v_printf.c
SOURCES += src/lib/__v_scanf.c
SOURCES += src/lib/vsnprintf.c
SOURCES += src/lib/vsprintf.c
SOURCES += src/lib/vsscanf.c
# SOURCES += src/lib/iswalnum.c
# SOURCES += src/lib/iswalpha.c
# SOURCES += src/lib/iswblank.c
# SOURCES += src/lib/iswcntrl.c
# SOURCES += src/lib/iswdigit.c
# SOURCES += src/lib/iswgraph.c
# SOURCES += src/lib/iswlower.c
# SOURCES += src/lib/iswprint.c
# SOURCES += src/lib/iswpunct.c
# SOURCES += src/lib/iswspace.c
# SOURCES += src/lib/iswupper.c
# SOURCES += src/lib/iswxdigit.c

SOURCES += src/libcompat/mempcpy.c
SOURCES += src/libcompat/stpcpy.c
SOURCES += src/libcompat/stpncpy.c
SOURCES += src/libcompat/strnlen.c
SOURCES += src/libcompat/toascii.c

SOURCES += src/libcruft/bindtextdomain.c
SOURCES += src/libcruft/dcgettext.c
SOURCES += src/libcruft/getopt_data.c
SOURCES += src/libcruft/inet_ntoa.c
SOURCES += src/libcruft/inet_ntoa_r.c
SOURCES += src/libcruft/lc_ctype.c
SOURCES += src/libcruft/localeconv.c
SOURCES += src/libcruft/mkstemp.c
SOURCES += src/libcruft/mktemp.c
SOURCES += src/libcruft/nl_langinfo.c
SOURCES += src/libcruft/setlocale.c
SOURCES += src/libcruft/textdomain.c
SOURCES += src/libcruft/tmpnam.c

SOURCES += src/libdl/dlclose.c
SOURCES += src/libdl/dlerror.c
SOURCES += src/libdl/dlopen.c
SOURCES += src/libdl/dlsym.c

SOURCES += src/libstdio/clearerr.c
SOURCES += src/libstdio/fclose.c
SOURCES += src/libstdio/fdglue2.c
SOURCES += src/libstdio/fdglue.c
SOURCES += src/libstdio/fdopen.c
SOURCES += src/libstdio/fdprintf.c
SOURCES += src/libstdio/feof.c
SOURCES += src/libstdio/ferror.c
SOURCES += src/libstdio/fflush.c
SOURCES += src/libstdio/fgetc_unlocked.c
SOURCES += src/libstdio/fgetpos.c
SOURCES += src/libstdio/fgets.c
SOURCES += src/libstdio/fileno.c
SOURCES += src/libstdio/fopen.c
SOURCES += src/libstdio/fprintf.c
SOURCES += src/libstdio/fputc_unlocked.c
SOURCES += src/libstdio/fputs.c
SOURCES += src/libstdio/fread.c
SOURCES += src/libstdio/freopen.c
SOURCES += src/libstdio/fscanf.c
SOURCES += src/libstdio/fseek.c
SOURCES += src/libstdio/fseeko64.c
SOURCES += src/libstdio/fseeko.c
SOURCES += src/libstdio/fsetopen.c
SOURCES += src/libstdio/fsetpos.c
SOURCES += src/libstdio/ftell.c
SOURCES += src/libstdio/ftello64.c
SOURCES += src/libstdio/ftello.c
SOURCES += src/libstdio/fwrite.c
SOURCES += src/libstdio/printf.c
SOURCES += src/libstdio/putchar.c
SOURCES += src/libstdio/puts.c
SOURCES += src/libstdio/scanf.c
SOURCES += src/libstdio/setvbuf.c
SOURCES += src/libstdio/stderr.c
SOURCES += src/libstdio/stdin.c
SOURCES += src/libstdio/stdout.c
SOURCES += src/libstdio/tmpfile.c
SOURCES += src/libstdio/ungetc.c
SOURCES += src/libstdio/vfdprintf.c
SOURCES += src/libstdio/vfprintf.c
SOURCES += src/libstdio/vfscanf.c
SOURCES += src/libstdio/vprintf.c
SOURCES += src/libstdio/vscanf.c

SOURCES += src/libugly/asctime.c
SOURCES += src/libugly/asctime_r.c
SOURCES += src/libugly/ctime.c
SOURCES += src/libugly/ctime_r.c
SOURCES += src/libugly/difftime.c
SOURCES += src/libugly/ftime.c
SOURCES += src/libugly/gmtime.c
SOURCES += src/libugly/gmtime_r.c
SOURCES += src/libugly/grantpt.c
SOURCES += src/libugly/isleap.c
SOURCES += src/libugly/localtime.c
SOURCES += src/libugly/localtime_r.c
SOURCES += src/libugly/mktime.c
SOURCES += src/libugly/strftime.c
SOURCES += src/libugly/strndup.c
SOURCES += src/libugly/strptime.c
SOURCES += src/libugly/timegm.c
SOURCES += src/libugly/time_table_spd.c
SOURCES += src/libugly/timezone.c
SOURCES += src/libugly/tzfile.c
SOURCES += src/libugly/vasprintf.c
SOURCES += src/libugly/asprintf.c
# SOURCES += src/libugly/wctype.c
# SOURCES += src/libugly/wmemcmp.c
# SOURCES += src/libugly/wmemcpy.c
# SOURCES += src/libugly/wmemmove.c
# SOURCES += src/libugly/wmemset.c

SOURCES += src/stubs/abort.c
SOURCES += src/stubs/chdir.c
SOURCES += src/stubs/chmod.c
SOURCES += src/stubs/chroot.c
SOURCES += src/stubs/dup2.c
SOURCES += src/stubs/dup.c
SOURCES += src/stubs/env.c
SOURCES += src/stubs/fchdir.c
SOURCES += src/stubs/fchown.c
SOURCES += src/stubs/fstat64.c
SOURCES += src/stubs/ftruncate64.c
SOURCES += src/stubs/getgrnam.c
SOURCES += src/stubs/getopt.c
SOURCES += src/stubs/getpid.c
SOURCES += src/stubs/getpwuid.c
SOURCES += src/stubs/lstat64.c
SOURCES += src/stubs/open64.c
SOURCES += src/stubs/pclose.c
SOURCES += src/stubs/popen.c
SOURCES += src/stubs/ptsname.c
SOURCES += src/stubs/readdir64.c
SOURCES += src/stubs/readlink.c
SOURCES += src/stubs/signal.c
SOURCES += src/stubs/symlink.c
SOURCES += src/stubs/umask.c
SOURCES += src/stubs/unlockpt.c
SOURCES += src/stubs/utime.c

SOURCES += src/syscall/access.c
SOURCES += src/syscall/calloc.c
SOURCES += src/syscall/__clear_cache.c
SOURCES += src/syscall/clock.c
SOURCES += src/syscall/close.c
SOURCES += src/syscall/environment.c
SOURCES += src/syscall/free.c
SOURCES += src/syscall/fstat.c
SOURCES += src/syscall/ftruncate.c
SOURCES += src/syscall/gettimeofday.c
SOURCES += src/syscall/isatty.c
SOURCES += src/syscall/jmp.c
SOURCES += src/syscall/lseek.c
SOURCES += src/syscall/malloc.c
SOURCES += src/syscall/mkdir.c
SOURCES += src/syscall/mmap.c
SOURCES += src/syscall/munmap.c
SOURCES += src/syscall/open.c
SOURCES += src/syscall/read.c
SOURCES += src/syscall/realloc.c
SOURCES += src/syscall/rename.c
SOURCES += src/syscall/rmdir.c
SOURCES += src/syscall/time.c
SOURCES += src/syscall/truncate.c
SOURCES += src/syscall/unlink.c
SOURCES += src/syscall/write.c

SOURCES += src/wchar/mbrtowc.c
SOURCES += src/wchar/mbsrtowcs.c
SOURCES += src/wchar/mbstowcs.c
SOURCES += src/wchar/wchar.c
SOURCES += src/wchar/wcscat.c
SOURCES += src/wchar/wcschr.c
SOURCES += src/wchar/wcscmp.c
SOURCES += src/wchar/wcscpy.c
SOURCES += src/wchar/wcslen.c
SOURCES += src/wchar/wcsncat.c
SOURCES += src/wchar/wcsncmp.c
SOURCES += src/wchar/wcsncpy.c
SOURCES += src/wchar/wcspbrk.c
SOURCES += src/wchar/wcsrchr.c
SOURCES += src/wchar/wcsstr.c

SDK_PATH := ..
include $(SDK_PATH)/multi-target.mk

ifdef TARGET

install: all
	@rm -vf ../lib/$(TARGET)/$(PROJECT).* ../lib/$(TARGET)/$(PROJECT)-*
	@cp -Pv $(OUTPUT_FILENAME) $(OUTPUT_SYMLINK) ../lib/$(TARGET)

endif
