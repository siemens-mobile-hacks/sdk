#pragma once

/**
 * @addtogroup SWILIB
 * @{
 */

#define __SWILIB__

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__ICCARM__) || defined(SWILIB_INCLUDE_ALL) || defined(SWILIB_PATCH_SDK)
	#define SWILIB_LIBC
	#define SWILIB_LIBPNG
	#define SWILIB_ZLIB
	#define SWILIB_OPENSSL
#endif

#if defined(__ICCARM__) && !defined(SWILIB_MODERN) // Compatibility with IAR code.
	#define SWILIB_LEGACY_COMPAT
#endif

#if defined(SWILIB_PATCH_SDK)
	#include <swilib-values.h>

	#if defined(__GNUC__)
		#include "compiler/gcc_patch.h"
	#else
		#error Unknown compiler!
	#endif
#else
	#if defined(SWILIB_LINUX_SIMULATOR)
		#include "compiler/gcc_linux.h"
	#elif defined(DOXYGEN)
		#include "compiler/doxygen.h"
	#elif defined(__ICCARM__)
		#include "compiler/iar.h"
	#elif defined(__GNUC__)
		#include "compiler/gcc.h"
	#else
		#error Unknown compiler!
	#endif
#endif

/* Compatibility with old defines */
#ifdef __NO_LIBC
	#define SWILIB_LIBC
#endif

#ifdef __SIE_LIBZ
	#define SWILIB_ZLIB
#endif

#ifdef __SWILIB_PNG__
	#define SWILIB_LIBPNG
#endif

__swilib_begin

#define __int16 short /* ??? */

typedef void *(*malloc_func_t)(size_t size);	/**< #malloc() */
typedef void (*mfree_func_t)(void *ptr);		/**< #free() */

typedef struct LLQ LLQ;
typedef struct LLIST LLIST;

/**
 * Default LGP IDs.
 * */
enum DefaultLgpID {
#ifdef NEWSGOLD
	LGP_NULL		= 0x7FFFFFFF,	/**< Empty LGP */
	LGP_DOIT_PIC	= 0x7FFFC0FB,	/**< OK icon */
	LGP_CHANGE_PIC	= 0x7FFFC10D,	/**< Change icon */
	LGP_MENU_PIC	= 0x7FFFC10E,	/**< Menu icon */
	LGP_SAVE_PIC	= 0x7FFFC113,	/**< Save icon */
#else
	LGP_NULL		= 0x7FFF,		/**< Empty LGP */
	LGP_DOIT_PIC	= 0x4E48,		/**< OK icon */
	LGP_MENU_PIC	= 0x4E4A,		/**< Menu icon */
#endif
};

/**
 * Legacy struct fields offsets.
 * */
enum LegacyStructOffsets {
#ifdef NEWSGOLD
	#ifdef ELKA
		DISPLACE_OF_EDGUI			= 0x90,
		DISPLACE_OF_USSDREQGUI_ID	= 0x44,
		DISPLACE_OF_EDGUI_ID		= 0x4C,
		DISPLACE_OF_IDLEGUI_ID		= 0x2C,
		DISPLACE_OF_IDLECANVAS		= 0x20,
	#else
		DISPLACE_OF_EDGUI			= 0x88,
		DISPLACE_OF_USSDREQGUI_ID	= 0x44,
		DISPLACE_OF_EDGUI_ID		= 0x4C,
		DISPLACE_OF_IDLEGUI_ID		= 0x2C,
		DISPLACE_OF_IDLECANVAS		= 0x18,
	#endif
	DISPLACE_OF_INCOMMINGGUI	= 0x34,
	DISPLACE_OF_OUTGOINGGUI		= 0x30,
#else
	DISPLACE_OF_EDGUI				= 0x50,
	DISPLACE_OF_USSDREQGUI_ID		= 0x40,
	DISPLACE_OF_EDGUI_ID			= 0x4C,
	DISPLACE_OF_IDLEGUI_ID			= 0x28,
	DISPLACE_OF_IDLECANVAS			= 0x14,
	DISPLACE_OF_INCOMMINGGUI		= 0x30,
	DISPLACE_OF_OUTGOINGGUI			= 0x2C,
#endif
};

/**
 * Linked-List header.
 * */
struct LLQ {
	void *first;	/**< Pointer to the first element */
	void *last;		/**< Pointer to the last element */
	mfree_func_t data_mfree;	/**< free() for list elements */
};

/**
 * Linked-List item.
 * */
struct LLIST {
	void *next;
	void *prev;
};

__swilib_end

/** @} */
