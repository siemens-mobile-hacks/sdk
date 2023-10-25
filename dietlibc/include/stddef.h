#ifndef _STDDEF_H
#define _STDDEF_H

#include <sys/cdefs.h>

__BEGIN_DECLS

/* ugh.  This is normally provided by gcc. */

#ifdef __GNUC__
typedef __PTRDIFF_TYPE__ ptrdiff_t;
typedef __SIZE_TYPE__ size_t;
#if !defined(__cplusplus)
typedef __WCHAR_TYPE__ wchar_t;
#endif
#else
typedef signed long ptrdiff_t;
typedef unsigned long size_t;
typedef int wchar_t;
#endif

#undef NULL
#if defined(__cplusplus)
#define NULL 0
#else
#define NULL (void*)0
#endif

#undef offsetof
#if defined(__GNUC__) && (__GNUC >= 3)
#define offsetof(type,member) __builtin_offsetof(type,member)
#else
#define offsetof(type,member) ((size_t) &((type*)0)->member)
#endif

#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L) \
  || (defined(__cplusplus) && __cplusplus >= 201103L)
#if !defined(_GCC_MAX_ALIGN_T) && !defined(__CLANG_MAX_ALIGN_T_DEFINED)
#define _GCC_MAX_ALIGN_T
#define __CLANG_MAX_ALIGN_T_DEFINED
/* Type whose alignment is supported in every context and is at least
   as great as that of any standard type not using alignment
   specifiers.  */
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
#endif
#endif /* C11 or C++11.  */

__END_DECLS

#endif
