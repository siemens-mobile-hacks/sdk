#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

/**
 * @addtogroup libc
 * @brief Functions from built-in libc (firmware).
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/libc.h>`
 * 
 * @warning **For GCC:** all of these functions are **disabled** by default due to being external `libc.so` is available.
 * @warning External libc is more compatible with standarts and helpful for porting existing code.
 * @warning But you always have the option to use built-in libc functions (e.g. for smaller memory usage).
 * @warning Just add `-DSWILIB_LIBC` to your definitions and remove `-lc` from libs.
 * 
 * Also, some non-standard functions are available even if the built-in library is disabled:
 * - @ref mfree
 * - @ref malloc_adr
 * - @ref mfree_adr
 * - @ref strcmpi
 * - @ref zeromem
 * - @ref ClearMemory
 * @{
 */

#ifdef SWILIB_LIBC

#ifndef __JMPBUF_DECL
#define __JMPBUF_DECL
typedef int jmp_buf[11];
#endif

/**
 * @name Memory
 * @{
 * */

/**
 * Allocate memory block.
 * @param size		Size of the memory block, in bytes.
 * @return On success, a pointer to the memory block allocated by the function.
 * @return If the function failed to allocate the requested block of memory, a null pointer is returned.
 * */
__swi_begin(0x014)
void *malloc(size_t size)
__swi_end(0x014, malloc, (size));

/**
 * Allocate and zero-initialize array.
 * @param count		Number of elements to allocate.
 * @param size		Size of each element.
 * @return On success, a pointer to the memory block allocated by the function.
 * @return If the function failed to allocate the requested block of memory, a null pointer is returned.
 * */
__swi_begin(0x092)
void *calloc(size_t count, size_t size)
__swi_end(0x092, calloc, (count, size));

/**
 * Reallocate memory block.
 * @param ptr		Pointer to a memory block previously allocated with #malloc, #calloc or #realloc. 
 * 		Alternatively, this can be a null pointer, in which case a new block is allocated (as if malloc was called).
 * @param size		New size for the memory block, in bytes.
 * @return A pointer to the reallocated memory block, which may be either the same as ptr or a new location.
 * @return A null-pointer indicates that the function failed to allocate storage, and thus the block pointed by ptr was not modified.
 * */
__swi_begin(0x0BA)
void *realloc(void *ptr, size_t size)
__swi_end(0x0BA, realloc, (ptr, size));

/**
 * Deallocate memory block.
 * @param ptr	Pointer to a memory block previously allocated with #malloc, #calloc or #realloc.
 * */
__swi_begin(0x015)
void free(void *ptr)
__swi_end(0x015, free, (ptr));

#endif /* SWILIB_LIBC */

/* ----------------------------------------- */

/**
 * Free previously allocated memory.
 * @param ptr	pointer returned by malloc/calloc/realloc
 * */
__swi_begin(0x015)
void mfree(void *ptr)
__swi_end(0x015, mfree, (ptr));

/**
 * Pointer to the function malloc().
 * @return pointer to the function
 * */
__swi_begin(0x8014)
void *malloc_adr(void)
__swi_end(0x8014, malloc_adr, ());

/**
 * Pointer to the function free().
 * @return pointer to the function
 * */
__swi_begin(0x8015)
void *mfree_adr(void)
__swi_end(0x8015, mfree_adr, ());

/**
 * Pointer to the function realloc().
 * @return pointer to the function
 * */
__swi_begin(0x80BA)
void *realloc_adr(void)
__swi_end(0x80BA, realloc_adr, ());

/* ----------------------------------------- */

#ifdef SWILIB_LIBC

/** @} */

/**
 * @name Memory utils
 * @{
 * */

/**
 * Compare two blocks of memory.
 * @param ptr1		Pointer to block of memory.
 * @param ptr2		Pointer to block of memory.
 * @param num		Number of bytes to compare.
 * @return <0	the first byte that does not match in both memory blocks has a lower value in ptr1 than in ptr2 (if evaluated as unsigned char values)
 * @return 0	the contents of both memory blocks are equal
 * @return >0	the first byte that does not match in both memory blocks has a greater value in ptr1 than in ptr2 (if evaluated as unsigned char values)
 * */
__swi_begin(0x11C)
int memcmp(const void *ptr1, const void *ptr2, size_t num)
__swi_end(0x11C, memcmp, (ptr1, ptr2, num));

/**
 * Locate character in block of memory.
 * @param str		This is the pointer to the block of memory where the search is performed.
 * @param c			This is the value to be passed as an int, but the function performs a byte per byte search using the unsigned char conversion of this value.
 * @param num		This is the number of bytes to be analyzed.
 * @return This function returns a pointer to the matching byte or NULL if the character does not occur in the given memory area.
 * */
__swi_begin(0x03B)
void *memchr(const void *str, int c, size_t num)
__swi_end(0x03B, memchr, (str, c, num));

#endif /* SWILIB_LIBC */

/* ----------------------------------------- */

/**
 * Fill block of memory with zero.
 * @param ptr		Pointer to the block of memory to fill.
 * @param num		Number of bytes to be set to the zero.
 */
__swi_begin(0x11D)
void zeromem(void *ptr, int num)
__swi_end(0x11D, zeromem, (ptr, num));

/* ----------------------------------------- */

#ifdef SWILIB_LIBC

/**
 * @copydoc zeromem
 * @deprecated use #memset
 */
__swi_begin(0x11D)
void bzero(void *ptr, int num)
__swi_end(0x11D, bzero, (ptr, num));

/**
 * Fill block of memory with zero.
 * @param ptr		Pointer to the block of memory to fill.
 * @param val		Value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
 * @param num		Number of bytes to be set to the value.
 * @return ptr is returned.
 */
__swi_begin(0x0BB)
void *memset(void *ptr, int val, size_t num)
__swi_end(0x0BB, memset, (ptr, val, num));

/**
 * Copy block of memory.
 * @param destination	Pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
 * @param source		Pointer to the source of data to be copied, type-casted to a pointer of type const void*.
 * @param num			Number of bytes to copy.
 * @return destination is returned.
 * */
__swi_begin(0x11E)
void *memcpy(void *destination, const void *source, size_t num)
__swi_end(0x11E, memcpy, (destination, source, num));

/**
 * Move block of memory.
 * @param destination	Pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
 * @param source		Pointer to the source of data to be copied, type-casted to a pointer of type const void*.
 * @param num			Number of bytes to copy.
 * @return destination is returned.
 * */
__swi_begin(0x132)
void *memmove(void *destination, const void *source, size_t num)
__swi_end(0x132, memmove, (destination, source, num));

/** @} */

/**
 * @name Long jump
 * @{
 * */

/**
 * Save calling environment for long jump.
 * @param env	Object of type jmp_buf where the environment information is stored.
 * @return This macro may return more than once: A first time, on its direct invocation; In this case it always returns zero.
 * @return When longjmp is called with the information set to env, the macro returns again;
 * 		this time it returns the value passed to longjmp as second argument if this is different from zero, or 1 if it is zero.
 * */
__swi_begin(0x162)
int setjmp(jmp_buf env)
__swi_end(0x162, setjmp, (env));

/**
 * Long jump.
 * @param env	Object of type jmp_buf filled by a previous call to setjmp that contains information to restore the environment to that point.
 * @param val	Value to which the setjmp expression evaluates. If this is zero, the expression evaluates as 1.
 * */
__swi_noreturn_begin(0x229)
void longjmp(jmp_buf env, int val)
__swi_noreturn_end(0x229, longjmp, (env, val));

/** @} */

/**
 * @name Random
 * @{
 * */

/**
 * Initialize random number generator.
 * @param seed	An integer value to be used as seed by the pseudo-random number generator algorithm.
 * */
__swi_begin(0x206)
void srand(uint32_t seed)
__swi_end(0x206, srand, (seed));

/**
 * Generate random number.
 * @return An integer value between 0 and RAND_MAX.
 * */
__swi_begin(0x07E)
int rand(void)
__swi_end(0x07E, rand, ());

/** @} */

/**
 * @name Formatting
 * @{
 * */

/**
 * Write formatted output to sized buffer.
 * @param s			Pointer to a buffer where the resulting C-string is stored. The buffer should have a size of at least n characters.
 * @param n			Maximum number of bytes to be used in the buffer. The generated string has a length of at most n-1, leaving space for the additional terminating null character.
 * @param format	C string that contains a format string that follows the same specifications as standart format in any sprintf/printf.
 * @return The number of characters that would have been written if n had been sufficiently large, not counting the terminating null character.
 * @return If an encoding error occurs, a negative number is returned.
 * @return Notice that only when this returned value is non-negative and less than n, the string has been completely written.
 * */

#ifdef SWILIB_MODE_DIRECT
#define snprintf(_s, _n, _format, ...) \
	__swi_call(0x11B, __swi_format(printf, 3, 4) int, (char *s, size_t n, const char *format, ...), (_s, _n, _format, ## __VA_ARGS__));
#else
__swi_begin(0x11B)
int snprintf(char *s, size_t n, const char *format, ...)
__swi_end(0x11B, snprintf, (s, n, format));
#endif

/**
 * Write formatted output to buffer.
 * @param s			Pointer to a buffer where the resulting C-string is stored. The buffer should be large enough to contain the resulting string.
 * @param format	C string that contains a format string that follows the same specifications as standart format in any sprintf/printf.
 * @return The number of characters that would have been written if n had been sufficiently large, not counting the terminating null character.
 * @return If an encoding error occurs, a negative number is returned.
 * @return Notice that only when this returned value is non-negative and less than n, the string has been completely written.
 * */
#ifdef SWILIB_MODE_DIRECT
#define sprintf(_s, _format, ...) \
	__swi_call(0x016, __swi_format(printf, 2, 3) int, (char *s, const char *format, ...), (_s, _format, ## __VA_ARGS__));
#else
__swi_begin(0x016)
int sprintf(char *s, const char *format, ...)
__swi_end(0x016, sprintf, (s, format));
#endif

/**
 * Read formatted data from string.
 * @param s			C string that the function processes as its source to retrieve the data.
 * @param format	C string that contains a format string that follows the same specifications as standart format in any scanf/sscanf.
 * @return On success, the function returns the number of items in the argument list successfully filled.
 * @return This count can match the expected number of items or be less (even zero) in the case of a matching failure.
 * @return In the case of an input failure before any data could be successfully interpreted, EOF is returned.
 * */
#ifdef SWILIB_MODE_DIRECT
#define sscanf(_s, _format, ...) \
	__swi_call(0x1F5, __swi_format(printf, 2, 3) int, (const char *s, const char *format, ...), (_s, _format, ## __VA_ARGS__));
#else
__swi_begin(0x1F5)
int sscanf(const char *s, const char *format, ...)
__swi_end(0x1F5, sscanf, (s, format));
#endif

/** @} */

/**
 * @name String utils
 * @{
 * */

/**
 * Locate first occurrence of character in string.
 * @param str			C string.
 * @param character		Character to be located. It is passed as its int promotion, but it is internally converted back to char for the comparison.
 * @return A pointer to the first occurrence of character in str. If the character is not found, the function returns a null pointer.
 * */
__swi_begin(0x018)
char *strchr(const char *str, int character)
__swi_end(0x018, strchr, (str, character));

/**
 * Compare two strings.
 * @param str1		C string to be compared.
 * @param str2		C string to be compared.
 * @return <0	- the first character that does not match has a lower value in ptr1 than in ptr2
 * @return 0	- the contents of both strings are equal
 * @return >0	- the first character that does not match has a greater value in ptr1 than in ptr2
 * */
__swi_begin(0x019)
int strcmp(const char *str1, const char *str2)
__swi_end(0x019, strcmp, (str1, str2));

/**
 * Compare two strings without case sensitivity.
 * @param str1	C string to be compared.
 * @param str2	C string to be compared.
 * @return <0	- the first character that does not match has a lower value in ptr1 than in ptr2
 * @return 0	- the contents of both strings are equal
 * @return >0	- the first character that does not match has a greater value in ptr1 than in ptr2
 * */
__swi_begin(0x085)
int strcasecmp(const char *str1, const char *str2)
__swi_end(0x085, strcasecmp, (str1, str2));

#endif /* SWILIB_LIBC */

/* ----------------------------------------- */

/**
 * Compare two strings without case sensitivity.
 * @param str1	C string to be compared.
 * @param str2	C string to be compared.
 * @return <0	- the first character that does not match has a lower value in ptr1 than in ptr2
 * @return 0	- the contents of both strings are equal
 * @return >0	- the first character that does not match has a greater value in ptr1 than in ptr2
 * */
__swi_begin(0x085)
int strcmpi(const char *str1, const char *str2)
__swi_end(0x085, strcmpi, (str1, str2));

/* ----------------------------------------- */

#ifdef SWILIB_LIBC

/**
 * Get string length.
 * @param str	C string.
 * @return The length of string.
*/
__swi_begin(0x01B)
size_t strlen(const char *str)
__swi_end(0x01B, strlen, (str));

/**
 * Locate characters in string.
 * @param str1	C string to be scanned.
 * @param str2	C string containing the characters to match.
 * @return A pointer to the first occurrence in str1 of any of the characters that are part of str2,
 * 		or a null pointer if none of the characters of str2 is found in str1 before the terminating null-character.
 * @return If none of the characters of str2 is present in str1, a null pointer is returned.
*/
__swi_begin(0x113)
char *strpbrk(const char *str1, const char *str2)
__swi_end(0x113, strpbrk, (str1, str2));

/**
 * Get span until character in string.
 * @param str1	C string to be scanned.
 * @param str2	C string containing the characters to match.
 * @return The length of the initial part of str1 not containing any of the characters that are part of str2.
 * @return This is the length of str1 if none of the characters in str2 are found in str1.
 * */
__swi_begin(0x113)
size_t strcspn(const char *str1, const char *str2)
__swi_end(0x113, strcspn, (str1, str2));

/**
 * Concatenate strings.
 * @param destination	Pointer to the destination array, which should contain a C string, and be large enough to contain the concatenated resulting string.
 * @param source		C string to be appended. This should not overlap destination.
 * @return destination is returned.
 * */
__swi_begin(0x017)
char *strcat(char *destination, const char *source)
__swi_end(0x017, strcat, (destination, source));

/**
 * Append characters from string.
 * @param destination	Pointer to the destination array, which should contain a C string, and be large enough to contain the concatenated resulting string, including the additional null-character.
 * @param source		C string to be appended.
 * @param num			Maximum number of characters to be appended.
 * @return destination is returned.
 * */
__swi_begin(0x114)
char *strncat(char *destination, const char *source, size_t num)
__swi_end(0x114, strncat, (destination, source, num));

/**
 * Compare characters of two strings.
 * @param str1			C string to be compared.
 * @param str2			C string to be compared.
 * @param num			Maximum number of characters to compare.
 * @return destination is returned.
 * */
__swi_begin(0x115)
int strncmp(const char *str1, const char *str2, size_t num)
__swi_end(0x115, strncmp, (str1, str2, num));

/**
 * Copy string.
 * @param destination		Pointer to the destination array where the content is to be copied.
 * @param source			C string to be copied.
 * @return destination is returned.
 * */
__swi_begin(0x01A)
char *strcpy(char *destination, const char *source)
__swi_end(0x01A, strcpy, (destination, source));

/**
 * Copy characters from string.
 * @param destination	Pointer to the destination array where the content is to be copied.
 * @param source		C string to be copied.
 * @param num			Maximum number of characters to be copied from source.
 * @return destination is returned.
 * */
__swi_begin(0x116)
char *strncpy(char *destination, const char *source, size_t num)
__swi_end(0x116, strncpy, (destination, source, num));

/**
 * Locate last occurrence of character in string.
 * @param str			C string.
 * @param character		Character to be located. It is passed as its int promotion, but it is internally converted back to char.
 * @return A pointer to the last occurrence of character in str. If the character is not found, the function returns a null pointer.
 * */
__swi_begin(0x117)
char *strrchr(const char *str, int character)
__swi_end(0x117, strrchr, (str, character));

/**
 * Locate substring.
 * @param str1	C string to be scanned.
 * @param str2	C string containing the sequence of characters to match.
 * @return A pointer to the first occurrence in str1 of the entire sequence of characters specified in str2, or a null pointer if the sequence is not present in str1.
 * */
__swi_begin(0x118)
char *strstr(const char *str1, const char *str2)
__swi_end(0x118, strstr, (str1, str2));

/**
 * Convert string to long integer.
 * @param str		C-string beginning with the representation of an integral number.
 * @param endptr	Reference to an object of type char*, whose value is set by the function to the next character in str after the numerical value.
 * 		This parameter can also be a null pointer, in which case it is not used.
 * @param base		Numerical base (radix) that determines the valid characters and their interpretation.
 * 		If this is 0, the base used is determined by the format in the sequence (see above).
 * @return On success, the function returns the converted integral number as a long int value. If no valid conversion could be performed, a zero value is returned (0L).
 * */
__swi_begin(0x119)
long int strtol(const char *str, char **endptr, int base)
__swi_end(0x119, strtol, (str, endptr, base));

/**
 * Convert string to unsigned long integer.
 * @param str		C-string containing the representation of an integral number.
 * @param endptr	Reference to an object of type char*, whose value is set by the function to the next character in str after the numerical value.
 *		This parameter can also be a null pointer, in which case it is not used.
 * @param base		Numerical base (radix) that determines the valid characters and their interpretation.
 *		If this is 0, the base used is determined by the format in the sequence (see #strtol for details).
 * @return On success, the function returns the converted integral number as an unsigned long int value.
 *		If no valid conversion could be performed, a zero value is returned.
 * */
__swi_begin(0x11A)
unsigned long strtoul(const char *str, char **endptr, int base)
__swi_end(0x11A, strtoul, (str, endptr, base));

/** @} */

/**
 * @name Searching & sorting
 * @{
 * */

/**
 * Sorting array.
 * @param first			This is the pointer to the first element of the array to be sorted.
 * @param nitems		This is the number of elements in the array pointed by base.
 * @param size			This is the size in bytes of each element in the array.
 * @param comparator	This is the function that compares two elements.
 * */
__swi_begin(0x3AA)
void qsort(void *first, size_t nitems, size_t size, int (*comparator)(const void *, const void *))
__swi_end(0x3AA, qsort, (first, nitems, size, comparator));

/**
 * Searchign in array.
 * @param key			This is the pointer to the object that serves as key for the search, type-casted as a void*.
 * @param first			This is the pointer to the first object of the array where the search is performed, type-casted as a void*.
 * @param nitems		This is the number of elements in the array pointed by base.
 * @param size			This is the size in bytes of each element in the array.
 * @param comparator	This is the function that compares two elements.
 * @return This function returns a pointer to an entry in the array that matches the search key. If key is not found, a NULL pointer is returned.
 * */
__swi_begin(0x3AB)
void *bsearch(const void *key, const void *first, size_t nitems, size_t size, int (*comparator)(const void *, const void *))
__swi_end(0x3AB, bsearch, (key, first, nitems, size, comparator));

/** @} */

/**
 * @name Environment variables
 * @{
 * */

/**
 * Set a value for the environment variable.
 * @param name		name of the variable
 * @param value		new value for the variable
 * @param replace	allow overwriting already existing variables
 * @return 0 or error
 * @builtin ELKA, NSG, X75, SG
 * */
__swi_begin(0x2F2)
int setenv(const char *name, const char *value, int replace)
__swi_end(0x2F2, setenv, (name, value, replace));

/**
 * Remove environment variable.
 * @param name		name of the variable
 * @return 0 or error
 * @builtin ELKA, NSG, X75, SG
 * */
__swi_begin(0x2F3)
int unsetenv(const char *name)
__swi_end(0x2F3, unsetenv, (name));

/**
 * Get value for the environment variable.
 * @param name		name of the variable
 * @return C-string
 * @builtin ELKA, NSG, X75, SG
 * */
__swi_begin(0x2F4)
char *getenv(const char *name)
__swi_end(0x2F4, getenv, (name));

/**
 * Remove all environment variables.
 * @return 0 or error
 * @builtin ELKA, NSG, X75, SG
 * */
__swi_begin(0x2F5)
int clearenv(void)
__swi_end(0x2F5, clearenv, ());

/** @} */

/**
 * @name Shared libs
 * @{
 * */

/**
 * Load the dynamic shared object (.so).
 * @param name	path to the `.so` file or only name (`libNAME.so`)
 * @return 0 or error
 * @builtin ELKA, NSG, X75, SG
 * */
__swi_begin(0x2EF)
int dlopen(const char *name)
__swi_end(0x2EF, dlopen, (name));

/**
 * Get a pointer to the symbol from the previously loaded dynamic object.
 * @param handle	descriptor obtained from _dlopen
 * @param name		name of the symbol
 * @return pointer to the symbol
 * @builtin ELKA, NSG, X75, SG
 * */
__swi_begin(0x2F0)
void *dlsym(int handle, const char *name)
__swi_end(0x2F0, dlsym, (handle, name));

/**
 * Close previously loaded dynamic object.
 * @param handle	descriptor obtained from _dlopen
 * @return 0 or error
 * @builtin ELKA, NSG, X75, SG
 * */
__swi_begin(0x2F1)
int dlclose(int handle)
__swi_end(0x2F1, dlclose, (handle));

/**
 * Get a string representation of the last error in _dlopen.
 * @return C-string
 * @builtin ELKA, NSG, X75, SG
 * */
__swi_begin(0x2F7)
const char *dlerror()
__swi_end(0x2F7, dlerror, ());

/** @} */

#endif /* SWILIB_LIBC */

__swilib_end

/** @} */
