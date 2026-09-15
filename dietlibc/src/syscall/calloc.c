
#include <swihelper.h>
#include <stddef.h>


void *calloc(size_t nelem, size_t elsize)
{
    return __swi_invoke(146, calloc, nelem, elsize);
}

