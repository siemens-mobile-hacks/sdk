#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

/**
 * @addtogroup ZLIB
 * @brief Built-in zlib functions.
 * See zlib 1.2.1 docs for more information.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/zlib.h>`
 * 
 * @note **For GCC:** These functions is available only when define `-DSWILIB_ZLIB` is specified in compiler flags.
 * @note Alternatively, you can include these functions directly by `#include <swilib/zlib.h>`
 * @{
 */

#if !defined(__IN_SWILIB__) || defined(SWILIB_ZLIB)

#include "../builtin/zlib.h"

/**
 * Initialize the decompression system.
 * @param strm			allocated z_stream object
 * @param windowBits	a base 2 logarithm of the maximum window size to use, and shall be a value between 8 and 15
 * @param version		library version, set to `ZLIB_VERSION`
 * @param stream_size	sizeof(z_stream)
 * @return `Z_OK` or error
 * */
__swi_begin(0x19F)
int inflateInit2_(z_streamp strm, int windowBits, const char *version, int stream_size)
__swi_end(0x19F, inflateInit2_, (strm, windowBits, version, stream_size));

/**
 * Attempt to decompress data until either the input buffer is empty or the output buffer is full.
 * @param strm			allocated z_stream object
 * @param flush			Z_NO_FLUSH / Z_SYNC_FLUSH / Z_BLOCK / Z_FINISH
 * @return `Z_OK` or error
 * */
__swi_begin(0x1A0)
int inflate(z_streamp strm, int flush)
__swi_end(0x1A0, inflate, (strm, flush));

/**
 * Free all allocated state information referenced by stream.
 * @param strm			allocated z_stream object
 * @return `Z_OK` or error
 * */
__swi_begin(0x1A1)
int inflateEnd(z_streamp strm)
__swi_end(0x1A1, inflateEnd, (strm));

#endif /* SWILIB_ZLIB */

__swilib_end

/** @} */
