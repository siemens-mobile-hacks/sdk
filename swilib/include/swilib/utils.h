#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#include "wstring.h"
#endif

__swilib_begin

/**
 * @addtogroup Utils
 * @brief Miscellaneous utility functions.
 *
 * Usage: `#include <swilib.h>` or `#include <swilib/utils.h>`
 * @{
 */

/**
 * Free memory in the sequence.
 * @param data			data passed to the next_in_seq
 * @param next_in_seq	destructor
 * @param data_to_kill	pointer to be freed
 *
 * Strange function with unknown purpose.
 * ```C
 * void SEQKILLER(void *data, void(*next_in_seq)(void *), void *data_to_kill) {
 *     next_in_seq(data);
 *     mfree(data_to_kill);
 * }
 * ```
 * */
__swi_begin(0x19C)
void SEQKILLER(void *data, void (*next_in_seq)(void *), void *data_to_kill)
__swi_end(0x19C, SEQKILLER, (data, next_in_seq, data_to_kill));

/**
 * Pointer to the #SEQKILLER.
 * @return pointer
 * */
__swi_begin(0x819C)
void *SEQKILLER_ADR()
__swi_end(0x819C, SEQKILLER_ADR, ());

/**
 * @name String utils
 * @{
 * */

/**
 * Convert string to int.
 * @param s		string with number
 * @param endp	pointer to the end of the number
 * @return int
 * */
__swi_begin(0x054)
int StrToInt(const char *s, char **endp)
__swi_end(0x054, StrToInt, (s, endp));

/**
 * Convert HEX-string to int.
 * @param s		string with HEX
 * @return int
 * */
__swi_begin(0x0AF)
uint32_t HexToInt(const char *s)
__swi_end(0x0AF, HexToInt, (s));

/**
 * Convert HEX char to int.
 * @param c		HEX char
 * @return int
 * */
__swi_begin(0x081)
int HexCharToInt(char c)
__swi_end(0x081, HexCharToInt, (c));

/**
 * Convert string to int.
 * @param[out] hex_out		output for hex string (len * 2 + 1)
 * @param str				input string
 * @param len				input string length
 * */
__swi_begin(0x005)
void StrToHex(char *hex_out, const char *str, int len)
__swi_end(0x005, StrToHex, (hex_out, str, len));

/**
 * Convert string to int.
 * @param lgp_id		langpack ID
 * @param[out] str		output for LGP string value
 * */
__swi_begin(0x089)
void GetLangMesIntoWS(int lgp_id, WSHDR *str)
__swi_end(0x089, GetLangMesIntoWS, (lgp_id, str));

/** @} */

/**
 * @name Base64 encoding/decoding
 * @{
 * */

/**
 * Encode binary data to the base64 string.
 * @param inbuf			input buffer
 * @param insize		input buffer length
 * @param[out] outbuf	output string buffer for the base64-encoded string
 * @param outsize		output string buffer size (max size)
 * @return encoded string length or 0
 *
 * ```C
 * char outbuf[1024];
 * int outbuf_len = Base64Encode(inbuf, inbuf_len, outbuf, sizeof(outbuf));
 * ```
 * */
__swi_begin(0x244)
int Base64Encode(void *inbuf, int insize, void *outbuf, int outsize)
__swi_end(0x244, Base64Encode, (inbuf, insize, outbuf, outsize));

/**
 * Decode string to the binary data.
 * @param inbuf			input b64 string
 * @param insize		input b64 string size
 * @param[out] outbuf	output buffer
 * @param outsize		output buffer size (max size)
 * @param _null			set to NULL
 * @param unk5			pointer to the dummy int
 * @return decoded buffer size or 0
 *
 * ```C
 * uint8_t outbuf[1024];
 * int unk = 0;
 * int decoded_len = Base64Decode(inbuf, strlen(inbuf), outbuf, sizeof(outbuf), NULL, &unk);
 * ```
 * */
__swi_begin(0x245)
int Base64Decode(char *inbuf, int insize, void *outbuf, int outsize, char *_null, int *unk5)
__swi_end(0x245, Base64Decode, (inbuf, insize, outbuf, outsize, _null, unk5));

/** @} */

/**
 * @name Math
 * @{
 * */

/**
 * Signed int div.
 * @param divisor		the number by which we divide.
 * @param divident		the number we are dividing
 * @return divident / divisor
 * */
__swi_begin(0x0B8)
int sdiv(int divisor, int divident)
__swi_end(0x0B8, sdiv, (divisor, divident));

/**
 * Unsigned int div.
 * @param divisor		the number by which we divide.
 * @param divident		the number we are dividing
 * @return divident / divisor
 * */
__swi_begin(0x0BC)
uint32_t udiv(uint32_t divisor, uint32_t divident)
__swi_end(0x0BC, udiv, (divisor, divident));

/**
 * Signed int div by 10.
 * @param divident		the number we are dividing
 * @return divident / 10
 * */
__swi_begin(0x0BD)
int DivBy10(int divident)
__swi_end(0x0BD, DivBy10, (divident));

/** @} */

__swilib_end

/** @} */
