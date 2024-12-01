#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#include "libc.h"
#endif

__swilib_begin

/**
 * @addtogroup PNG
 * @brief Built-in libpng. See libpng docs for more info.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/png.h>`
 * 
 * @note **For GCC:** These functions is available only when define `-DSWILIB_LIBPNG` is specified in compiler flags.
 * @note Alternatively, you can include these functions directly by `#include <swilib/png.h>`
 * @{
 */

#include "../builtin/png.h"

__swi_begin(0x155)
png_structp png_create_read_struct(png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn)
__swi_end(0x155, png_create_read_struct, (user_png_ver, error_ptr, error_fn, warn_fn));

__swi_begin(0x156)
png_infop png_create_info_struct(png_structp png_ptr)
__swi_end(0x156, png_create_info_struct, (png_ptr));

__swi_begin(0x157)
void png_destroy_read_struct(png_structpp png_ptr_ptr, png_infopp info_ptr_ptr, png_infopp end_info_ptr_ptr)
__swi_end(0x157, png_destroy_read_struct, (png_ptr_ptr, info_ptr_ptr, end_info_ptr_ptr));

__swi_begin(0x158)
void png_set_sig_bytes(png_structp png_ptr, int num_bytes)
__swi_end(0x158, png_set_sig_bytes, (png_ptr, num_bytes));

__swi_begin(0x159)
void png_read_info(png_structp png_ptr, png_infop info_ptr)
__swi_end(0x159, png_read_info, (png_ptr, info_ptr));

__swi_begin(0x15A)
png_uint_32 png_get_IHDR(png_structp png_ptr,png_infop info_ptr, png_uint_32 *width, png_uint_32 *height,
	int *bit_depth, int *color_type, int *interlace_method, int *compression_method, int *filter_method)
__swi_end(0x15A, png_get_IHDR, (png_ptr, info_ptr, width, height, bit_depth, color_type, interlace_method, compression_method, filter_method));

__swi_begin(0x15B)
png_voidp png_malloc(png_structp png_ptr, png_uint_32 size)
__swi_end(0x15B, png_malloc, (png_ptr, size));

__swi_begin(0x15C)
void png_read_image(png_structp png_ptr, png_bytepp image)
__swi_end(0x15C, png_read_image, (png_ptr, image));

__swi_begin(0x15D)
void png_read_end(png_structp png_ptr, png_infop info_ptr)
__swi_end(0x15D, png_read_end, (png_ptr, info_ptr));

__swi_begin(0x15E)
png_voidp png_get_io_ptr(png_structp png_ptr)
__swi_end(0x15E, png_get_io_ptr, (png_ptr));

__swi_begin(0x15F)
png_uint_32 png_get_rowbytes(png_structp png_ptr, png_infop info_ptr)
__swi_end(0x15F, png_get_rowbytes, (png_ptr, info_ptr));

__swi_begin(0x160)
void png_read_row(png_structp png_ptr, png_bytep row, png_bytep dsp_row)
__swi_end(0x160, png_read_row, (png_ptr, row, dsp_row));

__swi_begin(0x161)
void png_init_io(png_structp png_ptr, int fp)
__swi_end(0x161, png_init_io, (png_ptr, fp));

__swi_begin(0x1A8)
png_structp png_create_read_struct_2(png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn,
	png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn)
__swi_end(0x1A8, png_create_read_struct_2, (user_png_ver, error_ptr, error_fn, warn_fn, mem_ptr, malloc_fn, free_fn));

__swi_begin(0x1A9)
void png_set_read_fn(png_structp png_ptr, png_voidp io_ptr, png_rw_ptr read_data_fn)
__swi_end(0x1A9, png_set_read_fn, (png_ptr, io_ptr, read_data_fn));

__swi_begin(0x1AA)
void png_read_update_info(png_structp png_ptr, png_info *info_ptr)
__swi_end(0x1AA, png_read_update_info, (png_ptr, info_ptr));

__swi_begin(0x1AB)
void png_set_palette_to_rgb(png_structp png_ptr)
__swi_end(0x1AB, png_set_palette_to_rgb, (png_ptr));

__swi_begin(0x1AC)
png_uint_32 png_get_valid(png_structp png_ptr,png_infop info_ptr, png_uint_32 flag)
__swi_end(0x1AC, png_get_valid, (png_ptr, info_ptr, flag));

__swi_begin(0x1AD)
void png_set_tRNS_to_alpha(png_structp png_ptr)
__swi_end(0x1AD, png_set_tRNS_to_alpha, (png_ptr));

__swi_begin(0x1AE)
void png_set_filler(png_structp png_ptr, png_uint_32 filler, int flags)
__swi_end(0x1AE, png_set_filler, (png_ptr, filler, flags));

__swi_begin(0x1AF)
void png_set_strip_16(png_structp png_ptr)
__swi_end(0x1AF, png_set_strip_16, (png_ptr));

__swi_begin(0x1B0)
void png_set_packing(png_structp png_ptr)
__swi_end(0x1B0, png_set_packing, (png_ptr));

__swi_begin(0x1B1)
void png_set_gray_to_rgb(png_structp png_ptr)
__swi_end(0x1B1, png_set_gray_to_rgb, (png_ptr));

__swi_begin(0x1B2)
int png_check_sig(png_bytep sig, int num)
__swi_end(0x1B2, png_check_sig, (sig, num));

__swi_begin(0x1D6)
void png_set_gray_1_2_4_to_8(png_structp png_ptr)
__swi_end(0x1D6, png_set_gray_1_2_4_to_8, (png_ptr));

__swi_begin(0x1D7)
void png_set_invert_mono(png_structp png_ptr)
__swi_end(0x1D7, png_set_invert_mono, (png_ptr));

__swilib_end

/** @} */
