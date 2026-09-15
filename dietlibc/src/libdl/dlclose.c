
#include <swilib.h>
#include <stdlib.h>


static inline
int __dlclose(int handle)
{
    return __swi_invoke(0x2F1, __dlclose, handle);
}

int dlclose(void * handle)
{
    if(handle)
    {
        int d = (int )(*(int*)handle);
        int ret = __dlclose(d);
        free(handle);
        return ret;
    }
    return -1;
}
