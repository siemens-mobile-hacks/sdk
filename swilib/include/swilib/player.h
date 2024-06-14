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
 * Play last song in standart media player. Always creates a new copy of media player.
 * */
__swi_begin(0x3D1)
void MediaProc_LaunchLastPlayback()
__swi_end(0x3D1, MediaProc_LaunchLastPlayback, ());

/**
 * Check if MediaPlayer in the background.
 * @return 1 or 0
 * */
__swi_begin(0x223)
int IsMediaPlayerInBackground()
__swi_end(0x223, IsMediaPlayerInBackground, ());

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
__swi_begin(0x3B2)
const WSHDR *GetLastAudioTrackDir()
__swi_end(0x3B2, GetLastAudioTrackDir, ());

/**
 * Close MediaPlayer.
 * */
__swi_begin(0x224)
void CloseMediaPlayer()
__swi_end(0x224, CloseMediaPlayer, ());

/**
 * File format of the current audio track in MediaPlayer.
 * @return 0xA - MP3, 0x8 - WAV, 0x4 - MID, 0x2 - 3GP
 * */
__swi_begin(0x8248)
char *RamMediaPlayerCurrentTrackFormat()
__swi_end(0x8248, RamMediaPlayerCurrentTrackFormat, ());

/**
 * Audio freq of the current audio track in MediaPlayer.
 * @return 0x4 - 22 kHz, 0x5 - 32 kHz, 0x7 - 44 kHz, 0x8 - 48 kHz
 * */
__swi_begin(0x8249)
char *RamMediaPlayerCurrentTrackFreq()
__swi_end(0x8249, RamMediaPlayerCurrentTrackFreq, ());

/**
 * Channels number from the current audio track in MediaPlayer.
 * @return 0x4 - 22 kHz, 0x5 - 32 kHz, 0x7 - 44 kHz, 0x8 - 48 kHz
 * */
__swi_begin(0x824A)
char *RamMediaPlayerCurrentTrackChannels()
__swi_end(0x824A, RamMediaPlayerCurrentTrackChannels, ());

__swilib_end

/** @} */
