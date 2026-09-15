#include <string.h>
#include "dietfeatures.h"
#include <swihelper.h>



#ifndef __BUILDIN_FUNCTIONS
char *strrchr(const char *t, int c) {
  register char ch;
  register const char *l=0;

  ch = c;
  for (;;) {
    if (__unlikely(*t == ch)) l=t; if (__unlikely(!*t)) return (char*)l; ++t;
#ifndef WANT_SMALL_STRING_ROUTINES
    if (__unlikely(*t == ch)) l=t; if (__unlikely(!*t)) return (char*)l; ++t;
    if (__unlikely(*t == ch)) l=t; if (__unlikely(!*t)) return (char*)l; ++t;
    if (__unlikely(*t == ch)) l=t; if (__unlikely(!*t)) return (char*)l; ++t;
#endif
  }
  return (char*)l;
}
#else
char *strrchr(const char *t, int c)
{
    return __swi_invoke(0x0117, strrchr, t, c);
}

#endif

char *rindex(const char *t,int c)	__attribute__((weak,alias("strrchr")));
