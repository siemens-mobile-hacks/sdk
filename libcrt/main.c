#include <swilib.h>
#include <ep3/loader.h>

//#define LITE

char *_curent_dir = 0;
extern void __hcrt_run_initarray(void *_ex);

#ifndef LITE
__attribute__(( noinline ))
char *getcwd(char *buf, size_t max)
{
    strncpy(buf, (char*)_curent_dir, max);
    return buf;
}
#endif

static void __crt_run_initarray()
{
    extern void *__ex;
    volatile void *ex = &__ex;
    __hcrt_run_initarray((void*)ex);
}

int main(char *exe, char *fname, void *p1);

char *__argv[2] = {0};
int _start(char *exe, char *fname, void *p1)
{
#ifndef LITE
    size_t l = strlen(exe);
    _curent_dir = (char *)malloc(l+1);

    char * d = strrchr(exe, '\\');

    /* скопипастим путь к эльфу */
    size_t b = d? (unsigned long)d-(unsigned long)exe+1 : l;
    memcpy((char*)_curent_dir, exe, b);
    _curent_dir[b] = 0;
#endif

    __crt_run_initarray();

    /* выполним маин */
    return main(exe, fname, p1);
}
