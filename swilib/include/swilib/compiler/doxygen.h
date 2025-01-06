#pragma once

/**
 * Doxygen parser support.
 * */

#ifndef SWILIB_MODERN
	#define SWILIB_MODERN
#endif

#define SWILIB_LEGACY_COMPAT // for docs

#ifdef SWILIB_PARSE_FUNCTIONS
	#define __swilib_begin
	#define __swilib_end

	#define __swi_begin(number) __swi_begin
	#define __swi_end(number, func, ...) __swi_end(number, func)

	#define __swi_value_begin(number) __swi_begin
	#define __swi_value_end(number, func) __swi_end(number, func)
#else
	#define __swilib_begin
	#define __swilib_end

	#define __swi_begin(number)
	#define __swi_end(number, func, call)

	#define __swi_value_begin(number)
	#define __swi_value_end(number, func)
#endif
