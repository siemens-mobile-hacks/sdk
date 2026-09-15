
#include <swihelper.h>
#include <stddef.h>


void *malloc(size_t size)
{
    return __swi_invoke(20, malloc, size);
}
