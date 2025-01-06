#pragma once

/**
 * GCC compiler support (Patches).
 * */

unsigned int __attribute__((warning("Function not found in swilib."))) ___bad_swi_addr___(unsigned int addr);

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

#define __swi_begin(number)
#define __swi_end(number, func, call)

#define __longcall__ __attribute__((long_call))
