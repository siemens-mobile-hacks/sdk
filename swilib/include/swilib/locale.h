#pragma once

/**
 * @addtogroup Locale
 * @brief Function and constants for working with locale.
 *
 * Usage: `#include <swilib.h>` or `#include <swilib/locale.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#include "wstring.h"
#endif

__swilib_begin

/**
 * Default LGP IDs.
 * */
enum DefaultLgpID {
#ifdef NEWSGOLD
 LGP_NULL		= 0x7FFFFFFF,	/**< Empty LGP */
 LGP_DOIT_PIC	= 0x7FFFC0FB,	/**< OK icon */
 LGP_CHANGE_PIC	= 0x7FFFC10D,	/**< Change icon */
 LGP_MENU_PIC	= 0x7FFFC10E,	/**< Menu icon */
 LGP_EDIT_PIC	= 0x7FFFC10F,	/**< Edit icon */
 LGP_SAVE_PIC	= 0x7FFFC113,	/**< Save icon */
#else
 LGP_NULL		= 0x7FFF,		/**< Empty LGP */
 LGP_DOIT_PIC	= 0x4E48,		/**< OK icon */
 LGP_MENU_PIC	= 0x4E4A,		/**< Menu icon */
#endif
};

/**
*  Lgp IDs
* */
enum LgpID {
#ifdef NEWSGOLD
 LGP_SELECT			=    59,		// "Select"
 LGP_RESULT			=   122,		// "Result"
 LGP_OPTIONS		=   407,		// "Options"
 LGP_EXIT			=   655,		// "Exit"
 LGP_BACK			=  1020,		// "Back"
 LGP_SETTINGS		=  3351,		// "Settings"
 LGP_CALCULATOR		=  6132,		// "Calculator
#endif
};

/**
 * Convert string to int.
 * @param lgp_id		langpack ID
 * @param[out] str		output for LGP string value
 * */
__swi_begin(0x089)
void GetLangMesIntoWS(int lgp_id, WSHDR *str)
__swi_end(0x089, GetLangMesIntoWS, (lgp_id, str));

/**
 * Get the phone's language.
 * @return iso code, example: ru, en
 * */
__swi_begin(0x0AA)
char *GetCurrentLocale()
__swi_end(0x0AA, GetCurrentLocale, ());

/**
 * Get the phone's language.
 * @return pointer to the language ID
 *
 * ```C
 * int lang_id = *RamDisplayLanguage();
 * ```
 * @deprecated Always use #GetCurrentLocale
 * */
__swi_begin(0x829D)
char *RamDisplayLanguage()
__swi_end(0x829D, RamDisplayLanguage, ());

/**
 * Get the phone's input language.
 * @return pointer to the language ID

 * ```C
 * int lang_id = *RamInputLanguage();
 * ```
 * */
__swi_begin(0x829C)
char *RamInputLanguage()
__swi_end(0x829C, RamInputLanguage, ());

__swilib_end

/** @} */
