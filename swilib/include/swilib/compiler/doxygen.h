#pragma once

/**
 * Doxygen parser support.
 * */

#ifndef SWILIB_MODERN
	#define SWILIB_MODERN
#endif

#ifdef SWILIB_PARSE_FUNCTIONS
	#define __swilib_begin
	#define __swilib_end

	#define __swi_begin(number) __swi_begin
	#define __swi_end(number, func, call) __swi_end(number, func)
#else
	#define __swilib_begin
	#define __swilib_end

	#define __swi_begin(number)
	#define __swi_end(number, func, call)
#endif
