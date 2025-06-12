# Just for example
cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 99)

project(dietlibc C ASM)
include(../cmake/config.cmake)

set(SOURCES
	# ASM sources
	src/errlist.S
	
	# C sources
	main.c
	src/lib/assert_fail.c
	src/lib/atexit.c
	src/lib/atof.c
	src/lib/atol.c
	src/lib/abs.c
	src/lib/labs.c
	src/lib/llabs.c
	src/libc.c
	src/libc_init.c
	src/lib/closedir.c
#	src/lib/__dtostr.c
	src/lib/__isnan.c
	src/lib/errlistu.c
	src/lib/errno_location.c
	src/lib/getopt.c
	src/lib/isalnum.c
	src/lib/isalpha.c
	src/lib/isascii.c
	src/lib/isblank.c
	src/lib/isdigit.c
	src/lib/isgraph.c
	src/lib/__isinf.c
	src/lib/islower.c
	src/lib/isprint.c
	src/lib/ispunct.c
	src/lib/isspace.c
	src/lib/isupper.c
	src/lib/isxdigit.c
	src/lib/latin1-iscntrl.c
	src/lib/__lltostr.c
	src/lib/lseek64.c
	src/lib/__ltostr.c
	src/lib/memccpy.c
	src/lib/memchr.c
	src/lib/memcmp.c
	src/lib/memcpy.c
	src/lib/memmove.c
	src/lib/memset.c
	src/lib/opendir.c
	src/lib/perror.c
	src/lib/qsort.c
	src/lib/rand48.c
	src/lib/rand.c
	src/lib/rand_r.c
	src/lib/readdir.c
	src/lib/remove.c
	src/lib/rewind.c
	src/libshell/fnmatch.c
	src/lib/snprintf.c
	src/lib/sprintf.c
	src/lib/sscanf.c
	src/lib/strcasecmp.c
	src/lib/strcat.c
	src/lib/strchr.c
	src/lib/strcmp.c
	src/lib/strcpy.c
	src/lib/strcspn.c
	src/lib/strdup.c
	src/lib/strerror.c
	src/lib/strlcat.c
	src/lib/strlcpy.c
	src/lib/strlen.c
	src/lib/strncasecmp.c
	src/lib/strncat.c
	src/lib/strncmp.c
	src/lib/strncpy.c
	src/lib/strpbrk.c
	src/lib/strrchr.c
	src/lib/strsep.c
	src/lib/strspn.c
	src/lib/strstr.c
	src/lib/strtod.c
	src/lib/strtof.c
	src/lib/strtok.c
	src/lib/strtok_r.c
	src/lib/strtol.c
	src/lib/strtold.c
	src/lib/strtoll.c
	src/lib/strtoul.c
	src/lib/strtoull.c
	src/lib/strxfrm.c
	src/lib/swab.c
	src/lib/tolower.c
	src/lib/toupper.c
	src/lib/uname.c
	src/lib/__v_printf.c
	src/lib/__v_scanf.c
	src/lib/vsnprintf.c
	src/lib/vsprintf.c
	src/lib/vsscanf.c
#	src/lib/iswalnum.c
#	src/lib/iswalpha.c
#	src/lib/iswblank.c
#	src/lib/iswcntrl.c
#	src/lib/iswdigit.c
#	src/lib/iswgraph.c
#	src/lib/iswlower.c
#	src/lib/iswprint.c
#	src/lib/iswpunct.c
#	src/lib/iswspace.c
#	src/lib/iswupper.c
#	src/lib/iswxdigit.c

	src/libcompat/mempcpy.c
	src/libcompat/stpcpy.c
	src/libcompat/stpncpy.c
	src/libcompat/strnlen.c
	src/libcompat/toascii.c

	src/libcruft/bindtextdomain.c
	src/libcruft/dcgettext.c
	src/libcruft/getopt_data.c
	src/libcruft/inet_ntoa.c
	src/libcruft/inet_ntoa_r.c
	src/libcruft/lc_ctype.c
	src/libcruft/localeconv.c
	src/libcruft/mkstemp.c
	src/libcruft/mktemp.c
	src/libcruft/nl_langinfo.c
	src/libcruft/setlocale.c
	src/libcruft/textdomain.c
	src/libcruft/tmpnam.c

	src/libdl/dlclose.c
	src/libdl/dlerror.c
	src/libdl/dlopen.c
	src/libdl/dlsym.c

	src/libstdio/clearerr.c
	src/libstdio/fclose.c
	src/libstdio/fdglue2.c
	src/libstdio/fdglue.c
	src/libstdio/fdopen.c
	src/libstdio/fdprintf.c
	src/libstdio/feof.c
	src/libstdio/ferror.c
	src/libstdio/fflush.c
	src/libstdio/fgetc_unlocked.c
	src/libstdio/fgetpos.c
	src/libstdio/fgets.c
	src/libstdio/fileno.c
	src/libstdio/fopen.c
	src/libstdio/fprintf.c
	src/libstdio/fputc_unlocked.c
	src/libstdio/fputs.c
	src/libstdio/fread.c
	src/libstdio/freopen.c
	src/libstdio/fscanf.c
	src/libstdio/fseek.c
	src/libstdio/fseeko64.c
	src/libstdio/fseeko.c
	src/libstdio/fsetopen.c
	src/libstdio/fsetpos.c
	src/libstdio/ftell.c
	src/libstdio/ftello64.c
	src/libstdio/ftello.c
	src/libstdio/fwrite.c
	src/libstdio/printf.c
	src/libstdio/putchar.c
	src/libstdio/puts.c
	src/libstdio/scanf.c
	src/libstdio/setvbuf.c
	src/libstdio/stderr.c
	src/libstdio/stdin.c
	src/libstdio/stdout.c
	src/libstdio/tmpfile.c
	src/libstdio/ungetc.c
	src/libstdio/vfdprintf.c
	src/libstdio/vfprintf.c
	src/libstdio/vfscanf.c
	src/libstdio/vprintf.c
	src/libstdio/vscanf.c

	src/libugly/asctime.c
	src/libugly/asctime_r.c
	src/libugly/ctime.c
	src/libugly/ctime_r.c
	src/libugly/difftime.c
	src/libugly/ftime.c
	src/libugly/gmtime.c
	src/libugly/gmtime_r.c
	src/libugly/grantpt.c
	src/libugly/isleap.c
	src/libugly/localtime.c
	src/libugly/localtime_r.c
	src/libugly/mktime.c
	src/libugly/strftime.c
	src/libugly/strndup.c
	src/libugly/strptime.c
	src/libugly/timegm.c
	src/libugly/time_table_spd.c
	src/libugly/timezone.c
	src/libugly/tzfile.c
	src/libugly/vasprintf.c
	src/libugly/asprintf.c
#	src/libugly/wctype.c
#	src/libugly/wmemcmp.c
#	src/libugly/wmemcpy.c
#	src/libugly/wmemmove.c
#	src/libugly/wmemset.c

	src/stubs/abort.c
	src/stubs/chdir.c
	src/stubs/chmod.c
	src/stubs/chroot.c
	src/stubs/dup2.c
	src/stubs/dup.c
	src/stubs/env.c
	src/stubs/fchdir.c
	src/stubs/fchown.c
	src/stubs/fstat64.c
	src/stubs/ftruncate64.c
	src/stubs/getgrnam.c
	src/stubs/getopt.c
	src/stubs/getpid.c
	src/stubs/getpwuid.c
	src/stubs/lstat64.c
	src/stubs/open64.c
	src/stubs/pclose.c
	src/stubs/popen.c
	src/stubs/ptsname.c
	src/stubs/readdir64.c
	src/stubs/readlink.c
	src/stubs/signal.c
	src/stubs/symlink.c
	src/stubs/umask.c
	src/stubs/unlockpt.c
	src/stubs/utime.c

	src/syscall/access.c
	src/syscall/calloc.c
	src/syscall/__clear_cache.c
	src/syscall/clock.c
	src/syscall/close.c
	src/syscall/environment.c
	src/syscall/free.c
	src/syscall/fstat.c
	src/syscall/ftruncate.c
	src/syscall/gettimeofday.c
	src/syscall/isatty.c
	src/syscall/jmp.c
	src/syscall/lseek.c
	src/syscall/malloc.c
	src/syscall/mkdir.c
	src/syscall/mmap.c
	src/syscall/munmap.c
	src/syscall/open.c
	src/syscall/read.c
	src/syscall/realloc.c
	src/syscall/rename.c
	src/syscall/rmdir.c
	src/syscall/time.c
	src/syscall/truncate.c
	src/syscall/unlink.c
	src/syscall/write.c

	src/wchar/mbrtowc.c
	src/wchar/mbsrtowcs.c
	src/wchar/mbstowcs.c
	src/wchar/wchar.c
	src/wchar/wcscat.c
	src/wchar/wcschr.c
	src/wchar/wcscmp.c
	src/wchar/wcscpy.c
	src/wchar/wcslen.c
	src/wchar/wcsncat.c
	src/wchar/wcsncmp.c
	src/wchar/wcsncpy.c
	src/wchar/wcspbrk.c
	src/wchar/wcsrchr.c
	src/wchar/wcsstr.c
)

add_compile_options(-Wall -Os -mthumb -fomit-frame-pointer)
include_directories(PUBLIC src)
link_libraries(crt_helper gcc)

# NSG
add_library(libc_nsg SHARED ${SOURCES})
target_sdk_setup(libc_nsg NSG)
set_target_properties(libc_nsg PROPERTIES LIBRARY_OUTPUT_NAME c-1.0)
target_link_options(libc_nsg PUBLIC "-Wl,-init,_init -Wl,-fini,_fini")
install(TARGETS libc_nsg LIBRARY DESTINATION "${SDK_PATH}/lib/NSG")

# SG
add_library(libc_sg SHARED ${SOURCES})
target_sdk_setup(libc_sg SG)
set_target_properties(libc_sg PROPERTIES LIBRARY_OUTPUT_NAME c-1.0)
target_link_options(libc_sg PUBLIC "-Wl,-init,_init -Wl,-fini,_fini")
install(TARGETS libc_nsg LIBRARY DESTINATION "${SDK_PATH}/lib/SG")
