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

enum ScreenSaverType {
	SCREENSAVER_PICTURE			= 0x00,
	SCREENSAVER_ANALOGUE_CLOCK	= 0x01,
	SCREENSAVER_ENERGY_SAVER	= 0x04,
	SCREENSAVER_DIGITAL_CLOCK	= 0x05,
	SCREENSAVER_OFF				= 0xFF,
};

/**
 * Go to the IDLE screen.
 * */
__swi_begin(0x109)
void DoIDLE(void)
__swi_end(0x109, DoIDLE, ());

/**
 * Check if the IDLE is currently displayed.
 * @return 1 or 0
 * */
__swi_begin(0x0C5)
int IsIdleUiOnTop(void)
__swi_end(0x0C5, IsIdleUiOnTop, ());

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
 * Get a type of the current screensaver.
 * @return #ScreenSaverType
 * */
__swi_begin(0x3D2)
int GetScreenSaverType()
__swi_end(0x3D2, GetScreenSaverType, ());

/**
 * Get screensaver CSM.
 * @return pointer to the screensaver CSM
 * */
__swi_begin(0x068)
SS_RAM *GetScreenSaverRAM(void)
__swi_end(0x068, GetScreenSaverRAM, ());

/**
 * Get screensaver CSM.
 * @return pointer to the screensaver CSM
 * @deprecated use #GetScreenSaverRAM
 * */
__swi_begin(0x80D1)
SS_RAM *RamScreenSaverCSM(void)
__swi_end(0x80D1, RamScreenSaverCSM, ());

/**
 * Return GBS command ID for refreshing screensaver.
 * @return ID
 * */
__swi_begin(0x8211)
int GBS_Cmd_4209_RefreshScreensaver()
__swi_end(0x8211, GBS_Cmd_4209_RefreshScreensaver, ());

__swilib_end

/** @} */
