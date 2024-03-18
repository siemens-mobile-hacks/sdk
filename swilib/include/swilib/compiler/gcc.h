#pragma once

/**
 * GCC compiler support.
 * */

#pragma weak __ex
#pragma weak __sys_switab_addres

#ifdef __cplusplus
extern "C" const int __sys_switab_addres[];
#else
extern const int __sys_switab_addres[];
#endif

#define SWILIB_MODE_DIRECT 1

/* Modern */
#ifdef __cplusplus
	#define __swilib_begin \
		_Pragma("GCC diagnostic push") \
		_Pragma("GCC diagnostic ignored \"-Wpedantic\"") \
		extern "C" {
	#define __swilib_end	} \
		_Pragma("GCC diagnostic pop")
#else
	#define __swilib_begin \
		_Pragma("GCC diagnostic push") \
		_Pragma("GCC diagnostic ignored \"-Wpedantic\"")
	#define __swilib_end	\
		_Pragma("GCC diagnostic pop")
#endif

#define __swi_begin(number) static inline __attribute__((flatten))
#define __swi_end(number, func, call) { \
    if (number < 0x8000) { \
        return ((__typeof__(&func)) __sys_switab_addres[number])call; \
    } else { \
        return ((__typeof__(func call)) __sys_switab_addres[number - 0x8000]); \
    } \
}

#define __swi_call(number, ret, signature, call) \
    (((ret (*)signature)(__sys_switab_addres[number]))call)

#define __swi_format(type, ...) \
    __attribute__((format(type, ##__VA_ARGS__)))

/* Legacy */
#define __inl static inline

#define __def(id, ret, ...) \
	{ \
		if (id >= 0x8000) { \
			return (ret)(__sys_switab_addres[id - 0x8000]); \
		} else { \
			return ((ret (*)(...))((__sys_switab_addres[id])))(__VA_ARGS__); \
		} \
	}

#define __defn(id, ...) { ((void (*)(...))((__sys_switab_addres[id])))(__VA_ARGS__); }

#define __cdef(id, ret, ...) (ret)((ret (*)(...))((__sys_switab_addres[id])))(__VA_ARGS__)
#define __cdefn(id, ...) ((void (*)(...))((__sys_switab_addres[id])))(__VA_ARGS__)

#define __nul_def(id, ret) { return ((ret (*)())((__sys_switab_addres[id])))(); }
#define __nul_defn(id) { ((void (*)())((__sys_switab_addres[id])))(); }

#define __def_noinline(id, ret, ...) \
	if (id >= 0x8000) { \
		return (ret)(__sys_switab_addres[id - 0x8000]); \
	} else { \
		return ((ret (*)(...))((__sys_switab_addres[id])))(__VA_ARGS__); \
	}
