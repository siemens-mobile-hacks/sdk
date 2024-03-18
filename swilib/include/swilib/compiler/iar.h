#pragma once

/**
 * IAR compiler support.
 * */

#ifdef __cplusplus
	#define __swilib_begin	extern "C" {
	#define __swilib_end	}
#else
	#define __swilib_begin
	#define __swilib_end
#endif

#define __swi_pragma(x) _Pragma(#x)
#define __swi_begin(number) __swi_pragma(swi_number=number) __swi __arm 
#define __swi_end(number, func, call)
