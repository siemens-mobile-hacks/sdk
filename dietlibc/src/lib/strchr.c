#include "dietfeatures.h"
#include <string.h>
#include <swihelper.h>


#ifndef __BUILDIN_FUNCTIONS
char *strchr(register const char *t, int c) {
  register char ch;

  ch = c;
  for (;;) {
    if (__unlikely(*t == ch)) break; if (__unlikely(!*t)) return 0; ++t;
#ifndef WANT_SMALL_STRING_ROUTINES
    if (__unlikely(*t == ch)) break; if (__unlikely(!*t)) return 0; ++t;
    if (__unlikely(*t == ch)) break; if (__unlikely(!*t)) return 0; ++t;
    if (__unlikely(*t == ch)) break; if (__unlikely(!*t)) return 0; ++t;
#endif
  }
  return (char*)t;
}
#else
char *strchr(register const char *t, int c)
{
    return __swi_invoke(24, strchr, t, c);
}
#endif

char *index(char *t,int c)	__attribute__((weak,alias("strchr")));
