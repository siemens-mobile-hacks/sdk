#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#include "date.h"
#include "gui.h"
#include "wstring.h"
#include "gbs.h"
#endif

__swilib_begin

/**
 * @addtogroup LEGACY
 * @brief Legacy or bad functions, usually used in the patches.
 * 
 * Usage: `#include <swilib/legacy.h>`
 * 
 * @warning Don't use in ELF's.
 * @{
 */

typedef struct RAM_DATETIME RAM_DATETIME;

/**
 * RAM copy of the RTC calendar.
 * */
struct RAM_DATETIME {
	uint16_t sec;			/**< Seconds */
	uint16_t min;			/**< Minutes */
	uint16_t hour;			/**< Hours */
	uint16_t day;			/**< Day of the month */
	uint16_t month;			/**< Month (1-12) */
	uint16_t year;			/**< Year */
};

/**
 * @copydoc memcmp
 * @deprecated use #memcmp
 * */
__swi_begin(0x053)
int memcmp_2(const void *ptr1, const void *ptr2, size_t num)
__swi_end(0x053, memcmp_2, (ptr1, ptr2, num));

/**
 * @copydoc memcpy
 * @deprecated use #memcpy
 * */
__swi_begin(0x059)
void *memcpy_2(void *destination, const void *source, size_t num)
__swi_end(0x059, memcpy_2, (destination, source, num));

/**
 * @copydoc strrchr
 * @deprecated use #strrchr
 * */
__swi_begin(0x031)
char *strrchr_2(const char *str, int character)
__swi_end(0x031, strrchr_2, (str, character));

/**
 * @copydoc wsprintf
 * @deprecated use #wsprintf
 * */
__swi_variadic_begin(0x0A0)
int wsprintf_2(WSHDR *s, const char *format, ...)
__swi_variadic_end(0x0A0, wsprintf_2, s, format);

/**
 * @copydoc AllocWS
 * @deprecated use #AllocWS
 * */
__swi_begin(0x0A4)
WSHDR *AllocWS_2(int size)
__swi_end(0x0A4, AllocWS_2, (size));

/**
 * @copydoc FreeWS
 * @deprecated use #FreeWS
 * */
__swi_begin(0x0A5)
void FreeWS_2(WSHDR *str)
__swi_end(0x0A5, FreeWS_2, (str));

/**
 * @copydoc wstrcpy
 * @deprecated use #wstrcpy
 * */
__swi_begin(0x0A1)
WSHDR *wstrcpy_2(WSHDR *destination, WSHDR *source)
__swi_end(0x0A1, wstrcpy_2, (destination, source));

/**
 * @copydoc zeromem
 * @deprecated use #memset
 */
__swi_begin(0x058)
void ClearMemory(void *ptr, int num)
__swi_end(0x058, ClearMemory, (ptr, num));

/**
 * @copydoc GetPaletteAdrByColorIndex
 * @deprecated use #GetPaletteAdrByColorIndex
 * */
__swi_begin(0x03F)
char *GetPaletteAdrByColorIndex_2(int index)
__swi_end(0x03F, GetPaletteAdrByColorIndex_2, (index));

/**
 * @copydoc IsTimerProc
 * @deprecated use #IsTimerProc
 * */
__swi_begin(0x057)
int IsTimerProc_2(GBSTMR *timer)
__swi_end(0x057, IsTimerProc_2, (timer));

/**
 * @copydoc LockSched
 * @deprecated use #LockSched
 * */
__swi_begin(0x069)
void LockSched_2(void)
__swi_end(0x069, LockSched_2, ());

/**
 * @copydoc UnlockSched
 * @deprecated use #UnlockSched
 * */
__swi_begin(0x06A)
void UnlockSched_2(void)
__swi_end(0x06A, UnlockSched_2, ());

/**
 * @copydoc DrawImg
 * @deprecated use #DrawImg
 * */
__swi_begin(0x024)
void DrawImg_2(int x, int y, int picture)
__swi_end(0x024, DrawImg_2, (x, y, picture));

/**
 * @copydoc DrawRoundedFrame
 * @deprecated use #DrawRoundedFrame
 * */
__swi_begin(0x071)
void DrawRoundedFrame_2(int x1, int y1, int x2, int y2, int x_round, int y_round, int flags, const char *pen, const char *brush)
__swi_end(0x071, DrawRoundedFrame_2, (x1, y1, x2, y2, x_round, y_round, flags, pen, brush));

/**
 * @copydoc DrawRectangle
 * @deprecated use #DrawRectangle
 * */
__swi_begin(0x09F)
void DrawRectangle_2(int x1, int y1, int x2, int y2, int flags, const char *pen, const char *brush)
__swi_end(0x09F, DrawRectangle_2, (x1, y1, x2, y2, flags, pen, brush));

/**
 * @copydoc DrwObj_SetColor
 * @deprecated use #DrwObj_SetColor
 * */
__swi_begin(0x077)
void DrwObj_SetColor_2(DRWOBJ *drwobj, const char *pen, const char *brush)
__swi_end(0x077, DrwObj_SetColor_2, (drwobj, pen, brush));

/**
 * @copydoc GeneralFuncF1
 * @deprecated use #GeneralFuncF1
 * */
__swi_begin(0x064)
void GeneralFuncF1_2(int cmd)
__swi_end(0x064, GeneralFuncF1_2, (cmd));

/**
 * Get date&time format from settings.
 * @deprecated use #RamDateTimeSettings
 * */
__swi_begin(0x078)
int GetTimeFormat()
__swi_end(0x078, GetTimeFormat, ());

/**
 * Parse the header of an IMA ADPCM .wav file (mono, 4 bits, 8000 or 16000 Hz).
 * @param data				pointer to the pointer to the .wav file bytes, starting with "RIFF"
 * @param riff_size			RIFF chunk size (32-bit value at offset 4 of the file)
 * @param[out] info			buffer of 0xD8 bytes
 * @return 0x11 on success, other values on error
 * @note info: +0x00 status (uint16_t), +0x14 audio data offset (uint32_t), +0x18 duration in ms (uint32_t).
 * @platforms NSG, ELKA
 * @deprecated Always use: #GetFileProp
 * */
__swi_begin(0x096)
short GetWavLenByContent(const uint8_t **data, uint32_t riff_size, void *info)
__swi_end(0x096, GetWavLenByContent, (data, riff_size, info));

/**
 * Pointer to the current track in MediaPlayer.
 * @return unknown
 * */
__swi_begin(0x80DD)
void *RamCurrentTrack()
__swi_end(0x80DD, RamCurrentTrack, ());

/**
 * Pointer to the audio params (unknown).
 * @return unknown
 * @platforms X75, SG
 * */
__swi_begin(0x809B)
void *RamAudioParamsAddr(void)
__swi_end(0x809B, RamAudioParamsAddr, ());

/**
 * Pointer to the current date and time.
 * @return pointer to the RAM copy of the RTC calendar
 * @note The time fields may not be updated on every platform, use #GetDateTime.
 * */
__swi_begin(0x80CE)
RAM_DATETIME *RamDateTime()
__swi_end(0x80CE, RamDateTime, ());

/**
 * Pointer to the current pressed key.
 * @return pointer to the keycode
 * @deprecated use #RamPressedKey
 * */
__swi_begin(0x80E2)
char *RamKeyBuffer(void)
__swi_end(0x80E2, RamKeyBuffer, ());

/**
 * Check if user typing phone number.
 * @return pointer to a byte that is 1 while a phone number is being entered and 0 otherwise
 * @platforms NSG, ELKA
 * */
__swi_begin(0x828F)
char *RamIsNumberTyping(void)
__swi_end(0x828F, RamIsNumberTyping, ());

/**
 * Unknown.
 * @return unknown
 * */
__swi_begin(0x80D9)
void *RamShutdownMode()
__swi_end(0x80D9, RamShutdownMode, ());

/**
 * Unknown.
 * @return unknown
 * */
__swi_begin(0x8251)
void *RamSizeOfPart()
__swi_end(0x8251, RamSizeOfPart, ());

/**
 * Get size of the recevied or sent file.
 * @return size
 * */
__swi_begin(0x8252)
int *RamSizeOfReceivedOrSentFile()
__swi_end(0x8252, RamSizeOfReceivedOrSentFile, ());

/**
 * Get size of the recevied or sent file.
 * @return size
 * */
__swi_begin(0x8256)
const char *RamNameOfReceivedOrSentFile()
__swi_end(0x8256, RamNameOfReceivedOrSentFile, ());

/**
 * Check if currently sending or receiving file by BT.
 * @return unknown
 * */
__swi_begin(0x8257)
int *RamIsSendingOrReceivingFileByBT()
__swi_end(0x8257, RamIsSendingOrReceivingFileByBT, ());

/**
 * Check if the IDLE is NOT currently displayed.
 * @return pointer to 1 or 0
 * @deprecated strange function, use #IsIdleUiOnTop
 * */
__swi_begin(0x80DB)
int *RamIsNotOnMainscreen()
__swi_end(0x80DB, RamIsNotOnMainscreen, ());

/**
 * Unknown.
 * */
__swi_begin(0x03D)
void editOrNewTXTModule(const char *file)
__swi_end(0x03D, editOrNewTXTModule, (file));

/**
 * Toggle vibration for the current profile.
 * @platforms X75, SG
 * */
__swi_begin(0x055)
void SwitchVibraOnOff(void)
__swi_end(0x055, SwitchVibraOnOff, ());

/**
 * Unknown.
 * @param profile_id profile ID
 * @return unknown
 * @platforms X75, SG
 * */
__swi_begin(0x07B)
int GetProfileFilter(int profile_id)
__swi_end(0x07B, GetProfileFilter, (profile_id));

/**
 * @name Nucleus
 * @{
 * */

/**
 * @copydoc NU_Restore_Interrupts
 * @deprecated use #NU_Restore_Interrupts
 * */
__swi_begin(0x350)
void NU_Restore_Interrupts_2(void)
__swi_end(0x350, NU_Restore_Interrupts_2, ());

/**
 * @copydoc NU_Unprotect
 * @deprecated use #NU_Unprotect
 * */
__swi_begin(0x35B)
void NU_Unprotect_2(void)
__swi_end(0x35B, NU_Unprotect_2, ());

/**
 * @copydoc NU_Disable_History_Saving
 * @deprecated use #NU_Disable_History_Saving
 * */
__swi_begin(0x367)
void NU_Disable_History_Saving_2(void)
__swi_end(0x367, NU_Disable_History_Saving_2, ());

/**
 * @copydoc NU_Enable_History_Saving
 * @deprecated use #NU_Enable_History_Saving
 * */
__swi_begin(0x368)
void NU_Enable_History_Saving_2(void)
__swi_end(0x368, NU_Enable_History_Saving_2, ());

/**
 * Input language flags byte (historical address, not the language ID).
 * @return pointer to the flags byte: bit 1 = first input language is automatic, bit 4 = second one is automatic
 * @note The first input language follows this byte: index in the T9 language table (0-35).
 * @deprecated Not the input language.
 * */
__swi_begin(0x829C)
char *RamInputLanguage()
__swi_end(0x829C, RamInputLanguage, ());

/** @} */

__swilib_end

/** @} */
