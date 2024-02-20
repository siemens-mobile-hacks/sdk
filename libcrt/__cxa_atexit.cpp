#include <swilib.h>
#include <ep3/loader.h>

typedef struct {
    void (*func)(void *);
    void *object;
    void *next;
}__cxa_atexit_struct;

__cxa_atexit_struct *__s_exit = 0, *__ex_start = 0;
int __cxa_is_killing = 0;
void *__dso_handle = 0;

extern void h_kill_elf(__cxa_atexit_struct *__ex_start, int *__cxa_is_killing, void *_ex);

void kill_elf() {
    extern Elf32_Exec __ex;
    h_kill_elf(__ex_start, &__cxa_is_killing, (void *) &__ex);
}

extern int __hcxa_atexit(void (*func)(void *), void *arg, void *__dsohandle, __cxa_atexit_struct **__s_exit, __cxa_atexit_struct **__ex_start, int __cxa_is_killing);

int __cxa_atexit(void (*func)(void *), void *arg, void *__dsohandle) {
    return __hcxa_atexit(func, arg, __dsohandle, &__s_exit, &__ex_start, __cxa_is_killing);
}

extern "C" int __aeabi_atexit(void *arg, void (*func)(void *), void *d) {
    return __cxa_atexit(func, arg, d);
}

extern "C" int atexit(void (*func)()) {
    return __cxa_atexit ((void (*)(void *))func, 0, 0);
}
