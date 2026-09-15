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

#ifdef SWILIB_NAMED_IMPORTS
	#define __swi_stringify_(value) #value
	#define __swi_stringify(value) __swi_stringify_(value)
	#define __swi_import_name(number) "\"#" __swi_stringify(number) "\""

	#define __swi_begin(number)
	#define __swi_end(number, func, call) __asm__(__swi_import_name(number)) __attribute__((weak))

	#define __swi_noreturn_begin(number)
	#define __swi_noreturn_end(number, func, call) \
		__asm__(__swi_import_name(number)) __attribute__((weak, noreturn))

	#define __swi_variadic_begin(number)
	#define __swi_variadic_end(number, func, ...) \
		__asm__(__swi_import_name(number)) __attribute__((weak))
#else
	#define __swi_begin(number) static inline __attribute__((flatten))
	#define __swi_end(number, func, call) { \
		if (number < 0x8000) { \
			return ((__typeof__(&func)) __sys_switab_addres[number])call; \
		} else { \
			return ((__typeof__(func call)) __sys_switab_addres[number - 0x8000]); \
		} \
	}

	#define __swi_noreturn_begin(number) static inline __attribute__((flatten, noreturn))
	#define __swi_noreturn_end(number, func, call) { \
		((__typeof__(&func)) __sys_switab_addres[number])call; \
	}

	#define __swi_variadic_begin(number) \
		_Pragma("GCC diagnostic push") \
		_Pragma("GCC diagnostic ignored \"-Wformat-nonliteral\"") \
		static inline __attribute__((always_inline))
	#define __swi_variadic_end(number, func, ...) { \
		return ((__typeof__(&func)) __sys_switab_addres[number])(__VA_ARGS__, __builtin_va_arg_pack()); \
	} \
	_Pragma("GCC diagnostic pop")
#endif

#define __swi_format(type, ...) \
    __attribute__((format(type, ##__VA_ARGS__)))

#define __swi_invoke(number, func, ...) \
	((__typeof__(&(func))) __sys_switab_addres[number])(__VA_ARGS__)
