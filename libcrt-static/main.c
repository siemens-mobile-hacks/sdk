#include <swilib.h>
#include <ep3/loader.h>

extern Elf32_Exec __ex;

/*
 * Free data without returning to the function.
 * */
__attribute__((naked))
void kill_data(void *p, void (*func_p)(void *)) {
	__asm__ ("bx  %1\n" :: "r"(p), "r"(func_p));
}

/*
 * Run C-constructors in the ELF.
 * */
void __hcrt_run_initarray(void *_ex) {
	Elf32_Exec *ex = (Elf32_Exec *) _ex;
	
	size_t sz = ex->dyn[DT_INIT_ARRAYSZ] >> 2;
	void **arr = (void **) (ex->body + ex->dyn[DT_INIT_ARRAY] - ex->v_addr);
	
	for (size_t i = 0; i < sz; i++)
		((void (*)())arr[i])();
}

/*
 * getcwd implementation.
 * */
char *getcwd(char *buf, size_t max) {
	if (__ex.fname) {
		const char *last_separator = strrchr(__ex.fname, '\\');
		if (last_separator) {
			size_t new_len = (uint32_t) (last_separator - __ex.fname + 1);
			if (new_len < max)
				max = new_len;
		}
	}
	strncpy(buf, __ex.fname ?: "", max);
	return buf;
}

int main(const char *exe, const char *fname, void *p1, void *p2);

int _start(const char *exe, const char *fname, void *p1, void *p2) {
    if (__sys_switab_addres != __ex.switab) {
		((void (*)(int, int))(__ex.switab[0x0148]))(1, (int) "Upgrade ELFLoader! (patches.kibab.com)");
		return -1;
	}
	__hcrt_run_initarray((void *) &__ex);
	return main(exe, fname, p1, p2);
}
