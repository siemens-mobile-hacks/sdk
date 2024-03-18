#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#include "csm.h"
#endif

__swilib_begin

/**
 * @addtogroup IDLE
 * @brief Functions for working with IDLE.
 * 
 * Usage: `#include <swilub.h>` or `#include <swilib/idle.h>`
 * @{
 */

typedef struct SS_RAM SS_RAM;

/**
 * Screensaver CSM.
 * */
struct SS_RAM {
	CSM_RAM ss_csm;			/**< Base CSM */
	void *unk;
	int ss_gui_id;			/**< GUI ID of the screensaver */
	int keylock_gui_id;		/**< GUI ID of the keylock */
};

/**
 * Go to the IDLE screen.
 * */
__swi_begin(0x109)
void DoIDLE(void)
__swi_end(0x109, DoIDLE, ());

/**
 * Redraw IDLE screen.
 * */
__swi_begin(0x01F)
void DrawMainScreen()
__swi_end(0x01F, DrawMainScreen, ());

/**
 * Check if the screensaver is currently displayed.
 * @return 1 or 0
 * */
__swi_begin(0x042)
int IsScreenSaver(void)
__swi_end(0x042, IsScreenSaver, ());

/**
 * Go to the screensaver screen.
 * */
__swi_begin(0x020)
void DrawScreenSaver()
__swi_end(0x020, DrawScreenSaver, ());

/**
 * Close screensaver screen.
 * */
__swi_begin(0x09C)
void CloseScreensaver()
__swi_end(0x09C, CloseScreensaver, ());

/**
 * Get screensaver CSM.
 * @return pointer to the screensaver CSM
 * */
__swi_begin(0x068)
SS_RAM *GetScreenSaverRAM(void)
__swi_end(0x068, GetScreenSaverRAM, ());

__swilib_end

/** @} */