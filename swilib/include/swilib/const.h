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
 * Get start index of the months short names.
 * @return LGP_ID
 * */
__swi_begin(0x80E5)
int LP_MonthsShort()
__swi_end(0x80E5, LP_MonthsShort, ());

/**
 * Get start index of the months full names.
 * @return LGP_ID
 * */
__swi_begin(0x80ED)
int LP_MonthsLong()
__swi_end(0x80ED, LP_MonthsLong, ());

/**
 * Get start index of the week days names.
 * @return LGP_ID
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
 * Get "big" icon.
 * @return PIT index
 * */
__swi_begin(0x80E6)
int PIT_Pic_Big()
__swi_end(0x80E6, PIT_Pic_Big, ());

/**
 * Get "little" icon.
 * @return PIT index
 * */
__swi_begin(0x80E7)
int PIT_Pic_Little()
__swi_end(0x80E7, PIT_Pic_Little, ());

/**
 * Get "extra" icon.
 * @return PIT index
 * */
__swi_begin(0x80E8)
int PIT_Pic_Extra()
__swi_end(0x80E8, PIT_Pic_Extra, ());

/**
 * Get "profiles" icon.
 * @return PIT index
 * */
__swi_begin(0x80E9)
int PIT_Pic_Profiles()
__swi_end(0x80E9, PIT_Pic_Profiles, ());

/**
 * Get "vibra" icon.
 * @return PIT index
 * */
__swi_begin(0x80EA)
int PIT_Pic_Vibra()
__swi_end(0x80EA, PIT_Pic_Vibra, ());

/**
 * Get "call" icon.
 * @return PIT index
 * */
__swi_begin(0x80EB)
int PIT_Pic_Call()
__swi_end(0x80EB, PIT_Pic_Call, ());

/**
 * Get "advnet" icon.
 * @return PIT index
 * */
__swi_begin(0x80EC)
int PIT_Pic_AdvNet()
__swi_end(0x80EC, PIT_Pic_AdvNet, ());

/**
 * Get "calendar" icon.
 * @return PIT index
 * */
__swi_begin(0x80EF)
int PIT_Pic_Calendar()
__swi_end(0x80EF, PIT_Pic_Calendar, ());

/**
 * Get "accumulator" icon.
 * @return PIT index
 * */
__swi_begin(0x80F0)
int PIT_Pic_AccuGraph()
__swi_end(0x80F0, PIT_Pic_AccuGraph, ());

/**
 * Get "lani" icon.
 * @return PIT index
 * */
__swi_begin(0x80F4)
int PIT_Pic_Lani()
__swi_end(0x80F4, PIT_Pic_Lani, ());

/** @} */

__swilib_end

/** @} */
