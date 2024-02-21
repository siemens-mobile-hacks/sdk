#include <swilib.h>
#include <ep3/loader.h>

__attribute__((weak))
extern Elf32_Exec __ex;

typedef struct {
    void (*func)(void *);
    void *object;
    void *next;
}__cxa_atexit_struct;

__cxa_atexit_struct *__s_exit = 0, *__ex_start = 0;
int __cxa_is_killing = 0;
void *__dso_handle = 0;

static void h_kill_elf(__cxa_atexit_struct *__ex_start, int *__cxa_is_killing, void *_ex) {
	*__cxa_is_killing = 1;
	__cxa_atexit_struct *save = 0;
    
    while (__ex_start) {
		__ex_start->func(__ex_start->object);
		save = (__cxa_atexit_struct *)__ex_start->next;
		mfree(__ex_start);
		__ex_start = save;
	}
	
	elfclose(_ex);
}

static int __hcxa_atexit(void (*func)(void*), void *arg, void *__dsohandle __attribute__((unused)), __cxa_atexit_struct **__s_exit, __cxa_atexit_struct **__ex_start, int __cxa_is_killing) {
	if (__cxa_is_killing)
		return -1;
    
	__cxa_atexit_struct *cur;
	if (!*__s_exit) {
		*__s_exit = (__cxa_atexit_struct *) malloc(sizeof(__cxa_atexit_struct));
		cur = *__s_exit;
		*__ex_start = *__s_exit;
	} else {
		(*__s_exit)->next = (__cxa_atexit_struct*)malloc(sizeof(__cxa_atexit_struct));
		cur = (__cxa_atexit_struct*)(*__s_exit)->next;
	}
	
	cur->func = func;
	cur->object = arg;
	cur->next = 0;
	*__s_exit = cur;
    
	return 0;
}

void kill_elf() {
    h_kill_elf(__ex_start, &__cxa_is_killing, (void *) &__ex);
}

int __cxa_atexit(void (*func)(void *), void *arg, void *__dsohandle) {
    return __hcxa_atexit(func, arg, __dsohandle, &__s_exit, &__ex_start, __cxa_is_killing);
}

extern "C" int __aeabi_atexit(void *arg, void (*func)(void *), void *d) {
    return __cxa_atexit(func, arg, d);
}

extern "C" int atexit(void (*func)()) {
    return __cxa_atexit ((void (*)(void *))func, 0, 0);
}
