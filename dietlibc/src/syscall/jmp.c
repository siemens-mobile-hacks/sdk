
#include <swihelper.h>
#include <stddef.h>
#include <setjmp.h>

__swi_begin(0x162)
int _swi_setjmp(jmp_buf env)
__swi_end(0x162, setjmp, (env));

__swi_noreturn_begin(0x229)
void _swi_longjmp(jmp_buf env, int val)
__swi_noreturn_end(0x229, longjmp, (env, val));


int setjmp(jmp_buf jmpbuf) {
    return _swi_setjmp(jmpbuf);
}

void longjmp(jmp_buf param1, int param2) {
    _swi_longjmp(param1, param2);
}
