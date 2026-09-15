
#include <swihelper.h>
#include <stddef.h>



void *realloc(void *ptr, size_t size)
{
    return __swi_invoke(186, realloc, ptr, size);
}
