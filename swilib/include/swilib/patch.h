#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

/**
 * @addtogroup PATCH
 * @brief Functions from patches.
 * 
 * Usage: `#include <swilib/patch.h>`
 * 
 * @warning Don't use in ELF's.
 * @{
 */

typedef struct CHAN_BAN_Q CHAN_BAN_Q;
typedef struct SFN_DATA SFN_DATA;

/**
 * GSM Channel item.
 * */
struct CHAN_BAN_Q {
	CHAN_BAN_Q *next;							/**< Pointer to the next channel */
	uint32_t (*proc)(int chan, uint32_t lvl);	/**< Get RX level */
};

/**
 * Channels list container.
 * */
struct SFN_DATA {
	CHAN_BAN_Q *ChanBannerQ;	/**< Channels list */
};

/**
 * Get list of the GSM channels RX levels.
 * @warning Function from the patch "Channel Banner", see: https://patches.kibab.com/patches/search.php5?action=search&kw=channel+banner
 * @return pointer
 * */
__swi_begin(0x81BB)
SFN_DATA *DATA_N_SFB(void)
__swi_end(0x81BB, DATA_N_SFB, ());

/**
 * Pointer to the free memory for MasterPatch patches.
 * @warning Don't use in ELF's.
 * @return pointer
 * */
__swi_begin(0x80E4)
void *FreeRAM()
__swi_end(0x80E4, FreeRAM, ());

/**
 * [MasterPatch] Get memory buffer for the patch by ID.
 * @param patch_id	uniq patch ID                        
 * @warning Don't use in ELF's.
 * */
__swi_begin(0x0C4)
void *GetBuffer(int patch_id)
__swi_end(0x0C4, GetBuffer, (patch_id));

/**
 * Spell current time.
 * @warning Function from the patch "Talking phone", see: https://patches.kibab.com/patches/search.php5?action=search&kw=talking+phone
 * */
__swi_begin(0x0BF)
void SpellTime()
__swi_end(0x0BF, SpellTime, ());

/**
 * Unknown function.
 * @warning Function from the patch "BoBaPack", see: https://patches.kibab.com/patches/search.php5?action=search&kw=BoBaPack
 * */
__swi_begin(0x010A)
void *GetConfig(uint32_t id)
__swi_end(0x010A, GetConfig, (id));

/**
 * Do vibration.
 * @param power			power of vibration
 * @param duration		duration of the vibration
 * @warning Function from the patch "BoBaPack", see: https://patches.kibab.com/patches/search.php5?action=search&kw=BoBaPack
 * */
__swi_begin(0x010E)
void Vibration(uint32_t power, uint32_t duration)
__swi_end(0x010E, Vibration, (power, duration));

/**
 * Unknown function.
 * @warning Function from the patch "BoBaPack", see: https://patches.kibab.com/patches/search.php5?action=search&kw=BoBaPack
 * */
__swi_begin(0x810B)
void *GetMinAdrScan()
__swi_end(0x810B, GetMinAdrScan, ());

/**
 * Unknown function.
 * @warning Function from the patch "BoBaPack", see: https://patches.kibab.com/patches/search.php5?action=search&kw=BoBaPack
 * */
__swi_begin(0x810C)
void *GetMaxAdrScan()
__swi_end(0x810C, GetMaxAdrScan, ());

__swilib_end

/** @} */
