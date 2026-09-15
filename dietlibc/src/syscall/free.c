
#include <swihelper.h>
#include <stddef.h>


void free(void * data)
{
    __swi_invoke(21, free, data);
}
