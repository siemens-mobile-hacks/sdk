#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#include "wstring.h"
#include "csm.h"
#endif

__swilib_begin

/**
 * @addtogroup MISC
 * @brief Miscellaneous phone functions.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/misc.h>`
 * @{
 */

typedef int(*shortcut_func)(void);
typedef struct shortcut shortcut;
typedef struct LIGHT_PARAM LIGHT_PARAM;

/**
 * Illumination device.
 * */
enum IlluminationDeviceID {
    ILLUMINATION_DEV_DISPLAY	= 0,	/**< LCD */
	ILLUMINATION_DEV_KEYBOARD	= 1,	/**< Keyboard */
};

/**
 * Flags for #TempLightOn
 * */
enum TempSetLightFlags {
	TEMP_SET_LIGHT_DISPLAY	= 1 << 0,	/**< Trigger LCD backlight */
	TEMP_SET_LIGHT_KEYBOARD	= 1 << 1,	/**< Trigger Keyboard backlight */
};

/**
 * Shortcuts.
 * */
struct shortcut {
	char name[16];				/**< Name of the shortcut */
	shortcut_func pointer;		/**< Function which is called by shortcut */
	void *get_status;			/**< Pointer to the function which check if this shortcut is enabled (optional) */
	int unk_1;
	int lgp_full_name;			/**< LGP ID for long title */
	int unk_2;
	int unk_3;
	int lgp_short_name;			/**< LGP ID for short title */
	int unk_4;
	int lgp_comment_msg;		/**< LGP ID for description or path to the ELF (in the patch) */
};

/**
 * Lightness settings.
 * */
struct LIGHT_PARAM {
	char timeout;		/**< Lightness off timeout */
	char unk0;			/**< Something mysterious, sometimes 0 or 5 */
	char perm_illum;	/**< It’s not entirely clear, it seems that the level that will be held when calling IllumTimeRequest is overwritten by calling SaveMaxIllumination(),
							and for some reason it is limited to 80% */
	char max_illum;		/**< Lightness level */
};

/**
 * @name Control
 * @{
 * */

/**
 * Switchoff phone.
 * */
__swi_begin(0x009)
void SwitchPhoneOff()
__swi_end(0x009, SwitchPhoneOff, ());

/**
 * Reboot phone.
 * */
__swi_begin(0x093)
void RebootPhone()
__swi_end(0x093, RebootPhone, ());

/** @} */

/**
 * @name IDLE
 * @{
 * */

/**
 * Disable the IDLE timer - the phone never goes to the IDLE screen.
 * Do not forget to call the #RestartIDLETMR to restore the original timer.
 * */
__swi_begin(0x17F)
void DisableIDLETMR(void)
__swi_end(0x17F, DisableIDLETMR, ());

/**
 * Set custom IDLE timer.
 * @param timeout	time in ms
 * @param msg		GBS message ID which will be sent after the timer expires
 * Do not forget to call the #RestartIDLETMR to restore the original timer.
 * */
__swi_begin(0x17D)
void SetIDLETMR(int timeout, int msg)
__swi_end(0x17D, SetIDLETMR, (timeout, msg));

/**
 * Restart the default idle timer.
 * */
__swi_begin(0x17E)
void RestartIDLETMR(void)
__swi_end(0x17E, RestartIDLETMR, ());

/** @} */

/**
 * @name Keyboard locking
 * @{
 * */

/**
 * Get keyboard lock status.
 * @return 0: locked, 1: unlocked
 * */
__swi_begin(0x043)
int IsUnlocked(void)
__swi_end(0x043, IsUnlocked, ());

/**
 * Lock keyboard.
 * */
__swi_begin(0x0A9)
void KbdLock()
__swi_end(0x0A9, KbdLock, ());

/**
 * Unlock keyboard.
 * */
__swi_begin(0x0B9)
void KbdUnlock()
__swi_end(0x0B9, KbdUnlock, ());

/** @} */

/**
 * @name Backlight
 * @{
 * */

/**
 * Pointer to the illumination table.
 * @return pointer
 * */
#ifdef NEWSGOLD
__swi_begin(0x8052)
char *GetIlluminationDataTable()
__swi_end(0x8052, GetIlluminationDataTable, ());
#else
__swi_begin(0x052)
char *GetIlluminationDataTable()
__swi_end(0x052, GetIlluminationDataTable, ());
#endif

/**
 * Pointer to the brightness settings.
 * @return pointer
 * */
__swi_begin(0x80D7)
LIGHT_PARAM *RamScreenBrightness(void)
__swi_end(0x80D7, RamScreenBrightness, ());

/**
 * Change illumination level for keyboard or LCD.
 * @param dev		device, see #IlluminationDeviceID
 * @param unk		set to 1
 * @param level		illumination level: 0-255
 * @param delay		delay in ms for smooth illumination change (fade-in/fade-out)
 * @return 0 or error
 * */
__swi_begin(0x008)
long SetIllumination(uint8_t dev, unsigned long unk, uint16_t level, unsigned long delay)
__swi_end(0x008, SetIllumination, (dev, unk, level, delay));

/**
 * Keep the backlight on.
 * 
 * @param time_mode		usually 1 or 4
 * @param counter		usually 3 or 1
 * 
 * Always ON:
 * ```C
 * IllumTimeRelease(4, 3); // Keep
 * IllumTimeRequest(4, 3); // Release
 * ```
 * 
 * As in "mediaplayer" (???):
 * ```C
 * IllumTimeRelease(1, 1); // Keep
 * IllumTimeRequest(1, 1); // Release
 * ```
 * */
__swi_begin(0x2DE)
void IllumTimeRequest(int time_mode, int counter)
__swi_end(0x2DE, IllumTimeRequest, (time_mode, counter));

/**
 * Allow backlight to turn off again.
 * @param time_mode		exact as in #IllumTimeRequest call
 * @param counter		exact as in #IllumTimeRequest call
 * */
__swi_begin(0x2DF)
void IllumTimeRelease(int time_mode, int counter)
__swi_end(0x2DF, IllumTimeRelease, (time_mode, counter));

/**
 * Trigger backlight (temporary set ON).
 * @param flags		bitmask, see #TempSetLightFlags
 * @param unk		unknown, set to 0x7FFF
 * */
__swi_begin(0x044)
void TempLightOn(int flags, int unk)
__swi_end(0x044, TempLightOn, (flags, unk));

/** @} */

/**
 * @name Vibration
 * @{
 * */

/**
 * Check if vibration enabled.
 * @return 1: enabled, 0: disabled
 * */
__swi_begin(0x040)
int GetVibraStatus(void)
__swi_end(0x040, GetVibraStatus, ());

/**
 * Start vibration.
 * @param power 	0-100
 * @return 1: success, 0: error
 * */
__swi_begin(0x07C)
uint32_t SetVibration(uint32_t power)
__swi_end(0x07C, SetVibration, (power));

/** @} */

/**
 * @name Clipboard
 * @{
 * */

/**
 * Get clipboard content.
 * @return pointer to the current clipboard content
 * */
__swi_begin(0x380)
WSHDR *GetClipBoard(void)
__swi_end(0x380, GetClipBoard, ());

/**
 * Copy the text to the clipboard.
 * @param text		text to be copied
 * @param pos		copy from position
 * @param len		length of the copied part
 * */
__swi_begin(0x381)
void CopyTextToClipboard(const WSHDR *text, int pos, int len)
__swi_end(0x381, CopyTextToClipboard, (text, pos, len));

/**
 * Clear clipboard content.
 * @param unk		set to 0x12
 * */
__swi_begin(0x382)
void ClearClipboard(char unk)
__swi_end(0x382, ClearClipboard, (unk));

/** @} */

/**
 * @name AlarmClock
 * @{
 * */

/**
 * Run AlarmClock ringing.
 * */
__swi_begin(0x035)
void AlarmClockRing()
__swi_end(0x035, AlarmClockRing, ());

/**
 * Get AlarmClock state.
 * @param state		unknown, set to 1
 * @return 1 - enabled, 0 - disabled
 * */
__swi_begin(0x2A0)
int GetAlarmclockState(int state)
__swi_end(0x2A0, GetAlarmclockState, (state));

/**
 * Re-read changed alarmclock.pd
 * @return 0 or error
 * */
__swi_begin(0x291)
int RefreshAlarmClock()
__swi_end(0x291, RefreshAlarmClock, ());

/** @} */

/**
 * @name Other functions
 * @{
 * */

/**
 * Get function by shortcut name.
 * @param shortcut_name		name of the shortcut, for example: "ALARM_CLOCK"
 * @return function pointer
 * 
 * ```C
 * GetFunctionPointer("ALARM_CLOCK")->pointer();
 * ```
 * */
__swi_begin(0x074)
shortcut *GetFunctionPointer(char *shortcut_name)
__swi_end(0x074, GetFunctionPointer, (shortcut_name));

/**
 * initialize Openwave browser.
 * Useful when default browser is disabled by a patch.
 * */
__swi_begin(0x2D2)
void StartNativeBrowserCore()
__swi_end(0x2D2, StartNativeBrowserCore, ());

/** @} */

__swilib_end

/** @} */
