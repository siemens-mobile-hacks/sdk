
#include <swilib.h>

static inline
void* __dlsym(int handle, const char *name)
{
    return __swi_invoke(0x2F0, __dlsym, handle, name);
}


void *dlsym(void *handle, const char *sym)
{
    if(!handle || !sym || !*sym) return 0;

    int d = (int )(*(int*)handle);
    return __dlsym(d, sym);
}
