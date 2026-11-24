#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

/**
 * @addtogroup CONST
 * @brief Various constants.
 *
 * Usage: `#include <swilib/const.h>`
 *
 * @{
 */

/**
 * @name Langpack
 * @{
 * */

/**
 * Get the base LGP ID of the short month names.
 * @return base; the name of month m (1-12) is base + m
 * */
__swi_begin(0x80E5)
int LP_MonthsShort()
__swi_end(0x80E5, LP_MonthsShort, ());

/**
 * Get the base LGP ID of the full month names.
 * @return base; the name of month m (1-12) is base + m
 * */
__swi_begin(0x80ED)
int LP_MonthsLong()
__swi_end(0x80ED, LP_MonthsLong, ());

/**
 * Get the base LGP ID of the weekday names.
 * @return base; the name of weekday d (0 = Sunday, 6 = Saturday) is base + d
 * */
__swi_begin(0x80EE)
int LP_Weekdays()
__swi_end(0x80EE, LP_Weekdays, ());

/** @} */

/**
 * @name Icons
 * @{
 * */

/**
 * Get "big" icon: the first picture of the big clock digits.
 * @return PIT index of the digit '0'; the digits 0-9 have consecutive IDs
 * */
__swi_begin(0x80E6)
int PIT_Pic_Big()
__swi_end(0x80E6, PIT_Pic_Big, ());

/**
 * Get "little" icon: the first picture of the small digits used by idle screen patches.
 * @return PIT index of the digit '0'; the digits 0-9 have consecutive IDs
 * @note On NSG and ELKA the stock PIT has no such picture, it comes from a patch or ElfPack (`ZBin\img\<id>.png`).
 * */
__swi_begin(0x80E7)
int PIT_Pic_Little()
__swi_end(0x80E7, PIT_Pic_Little, ());

/**
 * Get "extra" icon: the first picture of the symbols used by idle screen info patches.
 * @return PIT index
 * @note The pictures come from a patch or ElfPack (`ZBin\img\<id>.png`).
 * */
__swi_begin(0x80E8)
int PIT_Pic_Extra()
__swi_end(0x80E8, PIT_Pic_Extra, ());

/**
 * Get "profiles" icon: the first picture of the profile icons.
 * @return PIT index; the icon of profile n is base + n
 * @note The pictures come from a patch or ElfPack (`ZBin\img\<id>.png`).
 * */
__swi_begin(0x80E9)
int PIT_Pic_Profiles()
__swi_end(0x80E9, PIT_Pic_Profiles, ());

/**
 * Get "vibra" icon used by idle screen patches.
 * @return PIT index
 * @note The picture comes from a patch or ElfPack (`ZBin\img\<id>.png`).
 * */
__swi_begin(0x80EA)
int PIT_Pic_Vibra()
__swi_end(0x80EA, PIT_Pic_Vibra, ());

/**
 * Get "call" icon: the missed call icon, followed by the missed SMS icon.
 * @return PIT index
 * @note On NSG and ELKA the pictures come from a patch or ElfPack (`ZBin\img\<id>.png`).
 * */
__swi_begin(0x80EB)
int PIT_Pic_Call()
__swi_end(0x80EB, PIT_Pic_Call, ());

/**
 * Get "advnet" icon: the first picture of the advanced network indicator levels.
 * @return PIT index
 * @note The pictures come from a patch or ElfPack (`ZBin\img\<id>.png`).
 * */
__swi_begin(0x80EC)
int PIT_Pic_AdvNet()
__swi_end(0x80EC, PIT_Pic_AdvNet, ());

/**
 * Get "calendar" icon: the first picture of the calendar weekday names, followed by the "today" frame.
 * @return PIT index
 * @note The pictures come from a patch or ElfPack (`ZBin\img\<id>.png`).
 * */
__swi_begin(0x80EF)
int PIT_Pic_Calendar()
__swi_end(0x80EF, PIT_Pic_Calendar, ());

/**
 * Get "accumulator" icon: the first picture of the battery temperature graph.
 * @return PIT index
 * @note The pictures come from a patch or ElfPack (`ZBin\img\<id>.png`).
 * */
__swi_begin(0x80F0)
int PIT_Pic_AccuGraph()
__swi_end(0x80F0, PIT_Pic_AccuGraph, ());

/**
 * Get "lani" icon: the first picture of the large advanced network indicator.
 * @return PIT index
 * @note The pictures come from a patch or ElfPack (`ZBin\img\<id>.png`).
 * */
__swi_begin(0x80F4)
int PIT_Pic_Lani()
__swi_end(0x80F4, PIT_Pic_Lani, ());

/** @} */

__swilib_end

/** @} */
