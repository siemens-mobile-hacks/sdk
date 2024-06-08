#pragma once

/**
 * @addtogroup Image
 * @brief Basic function for working with images.
 *
 * Usage: `#include <swilib.h>` or `#include <swilib/images.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

typedef struct IMGHDR IMGHDR;
typedef struct EIMGHDR EIMGHDR;
typedef struct PNGLIST PNGLIST;
typedef struct DYNPNGICONLIST DYNPNGICONLIST;
typedef struct PNGTOP_DESC PNGTOP_DESC;

struct PNGLIST {
	void *next;
	char *pngname;
	IMGHDR *img;
};

struct DYNPNGICONLIST {
	void *next;
	int icon;
	IMGHDR *img;
};

struct PNGTOP_DESC {
	PNGLIST *pltop;
	char *bitmap;
	DYNPNGICONLIST *dyn_pltop;
};

/**
 * Type of IMGHDR bitmap.
 * */
enum ImghdrBitmapType {
	IMGHDR_TYPE_WB		= 1,	/**< 1-bit **/
	IMGHDR_TYPE_RGB332	= 5,	/**< 8-bit RGB332 **/
	IMGHDR_TYPE_RGB565	= 8,	/**< 16-bit RGB565 **/
	IMGHDR_TYPE_RGB8888	= 10,	/**< 32-bit RGB8888 **/
};

/**
 * Image header.
 * */
struct IMGHDR {
#ifdef ELKA
	uint16_t w;			/**< Image width */
	uint16_t h;			/**< Image height */
	int bpnum; 			/**< Bitmap type, see: #ImghdrBitmapType */
#else
	uint8_t w;			/**< Image width */
	uint8_t h;			/**< Image height */
	uint16_t bpnum;		/**< Bitmap type, see: #ImghdrBitmapType */
#endif
	uint8_t *bitmap;	/**< Raw bitmap data */
};

/**
 * Extended image header (without 255x255 limitation).
 * */
struct EIMGHDR {
	int bpnum;			/**< Bitmap type, see: #ImghdrBitmapType */
	int w;				/**< Image width */
	int h;				/**< Image height */
	int zero;
	int tp_pixel;		/**< Value of the pixel which is replaced by transparency (or -1) */
	uint8_t *bitmap;	/**< Raw bitmap data */
};

/**
 * ID of theme cache images.
 * */
enum ThemeCacheImageID {
	HEADLINE_STANDART			= 0x0,
	HEADLINE_FULLSCREEN			= 0x1,
	BODY_STANDART				= 0x2,
	BODY_TAB					= 0x3,
	BOTTOM_STANDART				= 0x4,
	BOTTOM_FULLSCREEN			= 0x5,
	POPUP_OPTIONS				= 0x6,
	POPUP_FEEDBACK				= 0x7,
	SELECTION_1_LINE			= 0x8,
	SELECTION_2_LINE			= 0x9,
	SELECTION_3_LINE			= 0xA,
	SELECTION_ICON_ONLY			= 0xB,
	POPUP_SEARCH_LINE			= 0xC,
	POPUP_QUICK_ACCESS_FIELD	= 0xD,
	PROGRESS_STATUSBAR			= 0xE,
	TAB_SELECTED				= 0xF,
	TAB_UNSELECTED				= 0x10,
	STATUSBAR_STANDART			= 0x11,
	STATUSBAR_FULLSCREEN		= 0x12,
};

#ifdef NEWSGOLD
	#define FIRST_UCS2_BITMAP 0xE12A
#else
	#define FIRST_UCS2_BITMAP 0xE137
#endif

/**
 * Get a pointer to the PNG list (PIT overrides).
 * @return pointer
 * @builtin ELKA, NSG, X75, SG
 * */
__swi_begin(0x81B9)
PNGTOP_DESC *PNG_TOP(void)
__swi_end(0x81B9, PNG_TOP, ());

/**
 * Get an image from the PIT table (images in firmware).
 * @param picture	image number
 * @return pointer to the image
 * */
__swi_begin(0x01E)
IMGHDR *GetPITaddr(int picture)
__swi_end(0x01E, GetPITaddr, (picture));

/**
 * Get the width of the image from the PIT table.
 * @param picture	image number
 * @return width
 * */
__swi_begin(0x021)
int GetImgHeight(int picture)
__swi_end(0x021, GetImgHeight, (picture));

/**
 * Get the height of the image from the PIT table.
 * @param picture	image number
 * @return height
 * */
__swi_begin(0x022)
int GetImgWidth(int picture)
__swi_end(0x022, GetImgWidth, (picture));

/**
 * Load PNG image from the filesystem.
 * @param path		path ot the filename
 * @param type		unknown, set to 0
 * @builtin ELKA, NSG, X75, SG
 * */
__swi_begin(0x1E9)
IMGHDR *CreateIMGHDRFromPngFile(const char *path, int type)
__swi_end(0x1E9, CreateIMGHDRFromPngFile, (path, type));

/**
 * Get an image from the phone theme.
 * @param index		idnex of the image, see: #ThemeCacheImageID
 * @return pointer to the image
 * */
__swi_begin(0x2E0)
IMGHDR *GetIMGHDRFromThemeCache(int index)
__swi_end(0x2E0, GetIMGHDRFromThemeCache, (index));

/**
 * Get image from U+E1XX "emoji".
 * @param symbol	unicode codepoint E1XX
 * @return number in PIT table
 * */
__swi_begin(0x1E4)
int GetPicNByUnicodeSymbol(int symbol)
__swi_end(0x1E4, GetPicNByUnicodeSymbol, (symbol));

/**
 * Calculate bitmap size by WxH and type.
 * @param w, h		size of the image
 * @param type		type of the bitmap, see #ImghdrBitmapType
 * */
__swi_begin(0x258)
int CalcBitmapSize(short w, short h, char type)
__swi_end(0x258, CalcBitmapSize, (w, h, type));

/**
 * @name Canvas
 * "Canvas" is a really meaning for standard UI background.
 * @{
 * */

/**
 * Get an image by canvas_id from cache.
 * "Canvas" is a really meaning for standard UI background.
 * @param canvas_id		ID of the "canvas"
 * @return pointer to the image
 * */
__swi_begin(0x3B3)
IMGHDR *GetIMGHDRFromCanvasCache(char canvas_id)
__swi_end(0x3B3, GetIMGHDRFromCanvasCache, (canvas_id));

/**
 * Get an image by canvas_id (low level).
 * "Canvas" is a really meaning for standard UI background.
 * @param canvas_id		ID of the "canvas"
 * @return pointer to the image
 * */
__swi_begin(0x076)
IMGHDR *GetCanvasBufferPicPtr(char canvas_id)
__swi_end(0x076, GetCanvasBufferPicPtr, (canvas_id));

/**
 * Check if canvas exists for the given `canvas_id`.
 * @return 1 or 0
 * */
__swi_begin(0x075)
int IsCanvasBufferSet(char canvas_id)
__swi_end(0x075, IsCanvasBufferSet, (canvas_id));

/**
 * Flush "canvas" in cache.
 * "Canvas" is a really meaning for standard UI background.
 * @param canvas_id		ID of the "canvas"
 * */
__swi_begin(0x063)
void MMI_CanvasBuffer_FlushV(char canvas_id)
__swi_end(0x063, MMI_CanvasBuffer_FlushV, (canvas_id));

/** @} */

/**
 * @name Dynamic icons
 * Dynamic icons - are those icons which can be used as U+E2XX unicode sequences in the standard UI.
 * XX in U+E2XX is the dynamic image slot number.
 * @{
 * */

/**
 * Get image from U+E2XX dynamic image.
 * @param symbol	unicode codepoint E2XX
 * @return pointer to the image
 * */
__swi_begin(0x1F6)
IMGHDR *GetPitAdrBy0xE200Symbol(int symbol)
__swi_end(0x1F6, GetPitAdrBy0xE200Symbol, (symbol));

/**
 * Get the maximum count of the dynamic icons.
 * Something like dynamic "emoji".
 * @return count
 * */
__swi_begin(0x1EA)
int GetMaxDynIcon(void)
__swi_end(0x1EA, GetMaxDynIcon, ());

/**
 * Check if the specified slot of the dynamic icons is used.
 * @param picture	number in the slot
 * @return 1 or 0
 * */
__swi_begin(0x1ED)
int IsDynIconBusy(int picture)
__swi_end(0x1ED, IsDynIconBusy, (picture));

/**
 * Set the image to the slot of the dynamic images.
 * @param picture	number in the slot
 * @param img		pointer to the image header
 * @param bitmap	pointer to the image bitmap
 * */
__swi_begin(0x1EF)
void SetDynIcon(int picture, IMGHDR *img, char *bitmap)
__swi_end(0x1EF, SetDynIcon, (picture, img, bitmap));

/**
 * Release the slot of the dynamic icons.
 * @param picture	number in the slot
 * */
__swi_begin(0x1EC)
void FreeDynIcon(int picture)
__swi_end(0x1EC, FreeDynIcon, (picture));

/** @} */

__swilib_end

/** @} */
