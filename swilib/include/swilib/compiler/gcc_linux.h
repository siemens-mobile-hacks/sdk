#pragma once

/**
 * GCC compiler support (Linux).
 * */

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
