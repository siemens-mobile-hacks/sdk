#include <swilib.h>
#include <ep3/loader.h>

extern Elf32_Exec __ex;

/*
 * Free data without returning to the function.
 * This is part of the libcrt which moved to the shared lib for smaller memory usage.
 * */
__attribute__((naked))
void kill_data(void *p, void (*func_p)(void *)) {
	__asm__ ("bx  %1\n" :: "r"(p), "r"(func_p));
}

/*
 * Get directory from the path.
 * This is part of the libcrt which moved to the shared lib for smaller memory usage.
 * */
char *_get_folder(char *_buf) {
	if (!_buf)
		return NULL;
	char *si = _buf;
	si = strrchr(si, '\\');
	if (si <= _buf || !*si)
		return 0;
	++si;
	*si = 0;
	return _buf;
}

/*
 * Run C-constructors in the ELF.
 * This is part of the libcrt which moved to the shared lib for smaller memory usage.
 * I don't know why this is not part of the ELFLoader...
 * */
void __hcrt_run_initarray(void *_ex) {
	Elf32_Exec *ex = (Elf32_Exec *) _ex;
	
	size_t sz = ex->dyn[DT_INIT_ARRAYSZ] >> 2;
	void **arr = (void **) (ex->body + ex->dyn[DT_INIT_ARRAY] - ex->v_addr);
	
	for (size_t i = 0; i < sz; i++)
		((void (*)())arr[i])();
}

/*
 * Now we are just checking the ELFLoader version for compatibility.
 * */
__attribute__((visibility("hidden")))
void libcrt_helper_init() {
	// The new version of the ELFLoader 3.0 provides "__sys_switab_addres" by itself
	// "int __sys_switab_addres[4096]" now is deprecated and removed from this library
	if (__sys_switab_addres != __ex.switab) {
		((void (*)(int, int))(__ex.switab[0x0148]))(1, (int) "Upgrade ELFLoader! (patches.kibab.com)");
		return;
	}
}
