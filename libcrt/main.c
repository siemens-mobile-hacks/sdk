#include <swilib.h>
#include <ep3/loader.h>

extern void __hcrt_run_initarray(void *_ex);

__attribute__((noinline))
char *getcwd(char *buf, size_t max) {
	extern Elf32_Exec __ex;
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
	extern Elf32_Exec __ex;
	__hcrt_run_initarray((void *) &__ex);
	return main(exe, fname, p1, p2);
}
