#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#include "wstring.h"
#endif

__swilib_begin

/**
 * @addtogroup Player
 * @brief Functions for working with builtin media player.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/player.h>`
 * @{
 */

/**
 * Pointer to the magic value for controlling media player.
 * @return pointer
 * 
 * ```C
 * uint32_t ctrl_code = *RamMPlayer_CtrlCode();
 * ```
 * */
__swi_begin(0x80E1)
uint32_t *RamMPlayer_CtrlCode()
__swi_end(0x80E1, RamMPlayer_CtrlCode, ());

/**
 * Play previous song in standart media player.
 * */
__swi_begin(0x1FF)
void MEDIA_PLAYLAST()
__swi_end(0x1FF, MEDIA_PLAYLAST, ());

/**
 * Get the filename of the last audio track in the media player.
 * @return pointer to the WSHDR
 * */
__swi_begin(0x082)
const WSHDR *GetLastAudioTrackFilename()
__swi_end(0x082, GetLastAudioTrackFilename, ());

/**
 * Get the directory of the last audio track in media player.
 * @return pointer to the WSHDR
 * */

__swi_begin(0x083)
const WSHDR *GetLastAudioTrackDir()
__swi_end(0x083, GetLastAudioTrackDir, ());

__swilib_end

/** @} */
