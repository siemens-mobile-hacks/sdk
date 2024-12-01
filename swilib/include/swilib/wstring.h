#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

/**
 * @addtogroup WSHDR
 * @brief Function for working with UTF-16 pascal-style strings.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/wstring.h>`
 * @{
 */

typedef struct WSBODY WSBODY;
typedef struct WSHDR WSHDR;

/**
 * Wide-string body.
 * */
#pragma pack(1)
struct WSBODY {
	uint16_t len;		/**< The first item is string length. */
	uint16_t data[];	/**< Other items are string characters. */
};
#pragma pack()

#define wsbody(ws) ((WSBODY *) ((ws)->wsbody))

/**
 * Wide-string header.
 * */
struct WSHDR {
	uint16_t *wsbody;			/**< wsbody[0] - len, wsbody[1] - first char */
	malloc_func_t ws_malloc;	/**< Pointer to the malloc() */
	mfree_func_t ws_mfree;		/**< Pointer to the free() */
	int isbody_allocated;		/**< 1: When a string is allocated by AllocWS or CreateWS, 0: When as string is allocated by CreateLocalWS */
	uint16_t maxlen;			/**< Maximum length of the string */
	uint16_t unk1;
};

/**
 * Create new empty WSHDR.
 * @param size	maximum length of the WSHDR
 * @return pointer to the new allocated WSHDR
 * */
__swi_begin(0x125)
WSHDR *AllocWS(int size)
__swi_end(0x125, AllocWS, (size));

/**
 * Create new empty WSHDR with custom allocator.
 * @param malloc_func	pointer to the custom malloc() function
 * @param mfree_func	pointer to the custom free() function
 * @param size			maximum length of the WSHDR
 * @return pointer to the new allocated WSHDR
 * */
__swi_begin(0x128)
WSHDR *CreateWS(malloc_func_t malloc_func, mfree_func_t mfree_func, int size)
__swi_end(0x128, CreateWS, (malloc_func, mfree_func, size));

/**
 * Initialize new empty WSHDR with static allocation.
 * @param header	pointer to storage for header
 * @param body		pointer to storage for body (size + 1)
 * @param size		maximum length of the WSHDR
 * @return pointer to the WSHDR
 * */
__swi_begin(0x127)
WSHDR *CreateLocalWS(WSHDR *header, uint16_t *body, int size)
__swi_end(0x127, CreateLocalWS, (header, body, size));

/**
 * Free WSHDR.
 * @param str	pointer to the WSHDR allocated by #AllocWS
 * */
__swi_begin(0x129)
void FreeWS(WSHDR *str)
__swi_end(0x129, FreeWS, (str));

/**
 * Truncate string.
 * @param str			pointer to the destination WSHDR
 * @param length		length to which the string should be reduced
 * */
__swi_begin(0x126)
void CutWSTR(WSHDR *str, int length)
__swi_end(0x126, CutWSTR, (str, length));

/**
 * Append a character to the end of WSHDR.
 * @param destination	pointer to the destination WSHDR
 * @param character		character to be appended
 * */
__swi_begin(0x01C)
void wsAppendChar(WSHDR *destination, int character)
__swi_end(0x01C, wsAppendChar, (destination, character));

/**
 * Get charater at the given position (safe).
 * @param str		pointer to the WSHDR 
 * @param pos		position
 * @return charater
 * */
__swi_begin(0x0A2)
uint16_t wsCharAt(const WSHDR *str, short pos)
__swi_end(0x0A2, wsCharAt, (str, pos));

/**
 * Insert a character at the given position of the WSHDR.
 * @param destination	pointer to the destination WSHDR
 * @param character		character to be inserted
 * @param position		position where to be inserted
 * @return new length of the destination WSHDR.
 * */
__swi_begin(0x01D)
int wsInsertChar(WSHDR *destination, int character, int position)
__swi_end(0x01D, wsInsertChar, (destination, character, position));

/**
 * Remove the substring range from the WSHDR.
 * @param destination	pointer to the destination WSHDR
 * @param from, to		substring range to be removed from the string
 * */
__swi_begin(0x215)
void wsRemoveChars(WSHDR *destination, int from, int to)
__swi_end(0x215, wsRemoveChars, (destination, from, to));

/**
 * Copy WSHDR.
 * @param destination		pointer to the destination WSHDR where the content is to be copied
 * @param source			string to be copied
 * @return destination is returned.
 * */
__swi_begin(0x11F)
WSHDR *wstrcpy(WSHDR *destination, WSHDR *source)
__swi_end(0x11F, wstrcpy, (destination, source));

/**
 * Copy WSHDR body.
 * @param destination		pointer to the destination WSHDR body where the content is to be copied
 * @param source			WSHDR body to be copied
 * @return destination is returned.
 * */
__swi_begin(0x110)
uint16_t *wstrcopy(uint16_t *destination, const uint16_t *source)
__swi_end(0x110, wstrcopy, (destination, source));

/**
 * Copy characters from WSHDR.
 * @param destination	pointer to the destination WSHDR where the content is to be copied
 * @param source		string to be copied
 * @param num			maximum number of characters to be copied from source
 * @return destination is returned.
 * */
__swi_begin(0x120)
WSHDR *wstrncpy(WSHDR *destination, WSHDR *source, int num)
__swi_end(0x120, wstrncpy, (destination, source, num));

/**
 * Copy characters from WSHDR.
 * @param destination	pointer to the destination WSHDR where the content is to be copied
 * @param source		string to be copied
 * @param from			offset in the source string
 * @param num			maximum number of characters to be copied from source
 * */
__swi_begin(0x214)
void wstrcpybypos(WSHDR *destination, WSHDR *source, int from, int num)
__swi_end(0x214, wstrcpybypos, (destination, source, from, num));

/**
 * Concatenate two WSHDR.
 * @param destination	pointer to the destination WSHDR, which should be large enough to contain the concatenated resulting string
 * @param source		string to be appended
 * @return destination is returned.
 * */
__swi_begin(0x121)
WSHDR *wstrcat(WSHDR *destination, WSHDR *source)
__swi_end(0x121, wstrcat, (destination, source));

/**
 * Concatenate two WSHDR.
 * @param destination	pointer to the destination WSHDR, which should be large enough to contain the concatenated resulting string
 * @param source		string to be appended
 * @param num			maximum number of characters to be appended
 * @return destination is returned.
 * */
__swi_begin(0x122)
WSHDR *wstrncat(WSHDR *destination, WSHDR *source, int num)
__swi_end(0x122, wstrncat, (destination, source, num));

/**
 * Locate first occurrence of character in WSHDR.
 * @param str			WSHDR string
 * @param start			position from which to start searching
 * @param character		character to be located
 * @return position of the found character or -1
 * */
__swi_begin(0x1DC)
short wstrchr(WSHDR *str, uint32_t start, uint32_t character)
__swi_end(0x1DC, wstrchr, (str, start, character));

/**
 * Locate last occurrence of character in WSHDR.
 * @param str			WSHDR string
 * @param rstart		position from which to start searching (from the end)
 * @param character		character to be located
 * @return position of the found character or -1
 * */
__swi_begin(0x1DD)
short wstrrchr(WSHDR *str, uint32_t rstart, uint32_t character)
__swi_end(0x1DD, wstrrchr, (str, rstart, character));

/**
 * Compare two WSHDR strings.
 * @param str1		WSHDR to be compared.
 * @param str2		WSHDR to be compared.
 * @return <0	- the first character that does not match has a lower value in ptr1 than in ptr2
 * @return 0	- the contents of both strings are equal
 * @return >0	- the first character that does not match has a greater value in ptr1 than in ptr2
 * */
__swi_begin(0x2E2)
int wstrcmp(WSHDR *str1, WSHDR *str2)
__swi_end(0x2E2, wstrcmp, (str1, str2));

/**
 * Compare two WSHDR strings, up to a specific length
 * @param ws1	WSHDR to be compared
 * @param ws2	WSHDR to be compared
 * @param n		length
 * @return <0	- the first character that does not match has a lower value in ws1 than in ws2
 * @return 0	- the contents of both strings are equal
 * @return >0	- the first character that does not match has a greater value in ws1 than in ws2
 * */
__swi_begin(0x3C9)
int wstrncmp(const WSHDR *ws1, const WSHDR *ws2, size_t n)
__swi_end(0x3C9, wstrncmp, (ws1, ws2, n));

/**
 * Get WSHDR length.
 * @param str	pointer to the WSHDR
 * @return The length of WSHDR string
*/
__swi_begin(0x123)
uint16_t wstrlen(const WSHDR *str)
__swi_end(0x123, wstrlen, (str));

/**
 * @name Formatting
 * @{
 * */

/**
 * Write formatted output to WSHDR.
 * 
 * Additional placeholders:
 *   - `%%t` - CP1251 string (cyrillic)
 *   - `%%s` - CP1252 string (latin)
 *   - `%%w` - UTF-16 string (WSHDR)
 * 
 * @param[out] s	pointer to a WSHDR where the resulting string is stored, the buffer should be large enough to contain the resulting string
 * @param format	C-string that contains a format string that follows the same specifications as standart format in any sprintf/printf (CP1252, latin)
 * 
 * @return The number of characters that would have been written if n had been sufficiently large, not counting the terminating null character.
 * @return If an encoding error occurs, a negative number is returned.
 * @return Notice that only when this returned value is non-negative and less than n, the string has been completely written.
 * */
#ifdef SWILIB_MODE_DIRECT
#define wsprintf(_s, _format, ...) \
	__swi_call(0x124, int, (WSHDR *s, const char *format, ...), (_s, _format, ## __VA_ARGS__));
#else
__swi_begin(0x124)
int wsprintf(WSHDR *s, const char *format, ...)
__swi_end(0x124, wsprintf, (s, format));
#endif

/**
 * Append formatted output to the end of WSHDR.
 * 
 * Additional placeholders:
 *   - `%%t` - CP1251 string (cyrillic)
 *   - `%%s` - CP1252 string (latin)
 *   - `%%w` - UTF-16 string (WSHDR)
 * 
 * @param[out] s	pointer to a WSHDR where the resulting string is stored, the buffer should be large enough to contain the resulting string
 * @param format	C-string that contains a format string that follows the same specifications as standart format in any sprintf/printf (CP1252, latin)
 * */
#ifdef SWILIB_MODE_DIRECT
#define wstrcatprintf(_s, _format, ...) \
	__swi_call(0x216, int, (WSHDR *s, const char *format, ...), (_s, _format, ## __VA_ARGS__));
#else
__swi_begin(0x216)
void wstrcatprintf(WSHDR *s, const char *format, ...)
__swi_end(0x216, wstrcatprintf, (s, format));
#endif

/** @} */

/**
 * @name Encoding converting
 * @{
 * */

/**
 * Convert WSHDR to the UTF-8 C-string.
 * @param source		input WSHDR to be converted to C-string
 * @param destination	pointer to the destination C-string, which should be large enough to contain the source WSHDR
 * @param new_length	pointer to which to write the length of the destination string
 * @param size			maximum number of characters to be converted
 * @return destination string length
 * */
__swi_begin(0x1E2)
int ws_2utf8(const WSHDR *source, char *destination, int *new_length, uint32_t size)
__swi_end(0x1E2, ws_2utf8, (source, destination, new_length, size));

/**
 * Convert UTF-8 C-string to WHSDR.
 * @param destination	pointer to the destination WSHDR, which should be large enough to contain the source string
 * @param source		input C-string to be converted to WSHDR
 * @param size			maximum number of characters to be converted
 * @return destination string length
 * */
__swi_begin(0x1E3)
int utf8_2ws(WSHDR *destination, const char *source, uint32_t size)
__swi_end(0x1E3, utf8_2ws, (destination, source, size));

/**
 * Convert CP1252 (Latin) C-string to WHSDR.
 * @param destination	pointer to the destination WSHDR, which should be large enough to contain the source string
 * @param source		input C-string to be converted to WSHDR
 * @param size			maximum number of characters to be converted
 * @return destination string length
 * */
__swi_begin(0x16C)
int str_2ws(WSHDR *destination, const char *source, uint32_t size)
__swi_end(0x16C, str_2ws, (destination, source, size));

/**
 * Convert WSHDR to the UTF-8 C-string with special mark.
 * @param source		input WSHDR to be converted to C-string
 * @param destination	pointer to the destination C-string, which should be large enough to contain the source WSHDR
 * @param size			maximum number of characters to be converted (+1)
 * 
 * Also, 0x1F (mark of UTF-8 string) will be added at the beginning of the string.
 * This is useful for filesystem functions.
 * */
__swi_begin(0x0A3)
void ws_2str(const WSHDR *source, char *destination, uint32_t size)
__swi_end(0x0A3, ws_2str, (source, destination, size));

/** @} */

__swilib_end

/** @} */
