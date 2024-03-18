#pragma once

/**
 * @addtogroup Info
 * @brief Getting miscellaneous phone info.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/info.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

/**
 * Phone info indexes for the #Get_Phone_Info.
 * */
enum PhoneInfoID {
	PI_BASE_INFO1	= 0, /**< Example: ch_x75idbi14 */
	PI_BASE_INFO2	= 1, /**< Example: m75i14#main_1.0_V79.27.1 */
	PI_BASE_INFO3	= 2, /**< Example: M_x75plat_MP_main_1.0 */
	PI_BASE_INFO4	= 3, /**< Example: M_minosemea_TH */
	PI_BUILD		= 4, /**< Example: OFFICIAL */
	PI_DATETIME1	= 5, /**< Firmware 1-st build time. */
	PI_DATETIME2	= 6, /**< Firmware 2-nd build time. */
	PI_SW_NUMBER	= 7, /**< Example: 51 */
	PI_VENDOR		= 8, /**< Example: SIEMENS */
	PI_MODEL		= 9, /**< Example: S75 */
	PI_LG			= 10, /**< Example: lg01 */
	PI_T9			= 11, /**< T9 */
};

/**
 * Accessory types.
 * */
enum AccessoryTypeID {
	ACC_TYPE_SERIAL_CABLE	= 15,	/**< DCA-510 */
};

/**
 * Battery charhing state.
 * */
enum BatCharhingStateID {
	BAT_STATE_DISCHARGING	= 0,
	BAT_STATE_UNKNOWN		= 1,
	BAT_STATE_CHARGING		= 2,
	BAT_STATE_FULLY_CHARGED	= 3,
};

/**
 * Get free RAM.
 * @return free RAM in bytes
 * */
__swi_begin(0x05F)
int GetFreeRamAvail()
__swi_end(0x05F, GetFreeRamAvail, ());

/**
 * Get memory used by MMI.
 * @return used RAM in bytes
 * */
__swi_begin(0x05E)
uint32_t GetMMIMemUsed()
__swi_end(0x05E, GetMMIMemUsed, ());

/**
 * Get basic phone info.
 * @param index		info index, see #PhoneInfoID
 * @return string with information
 * */
__swi_begin(0x1D5)
char *Get_Phone_Info(int index)
__swi_end(0x1D5, Get_Phone_Info, (index));

/**
 * @name Language
 * @{
 * */

/**
 * Get the phone's language.
 * @return iso code, example: ru, en
 * */
__swi_begin(0x0AA)
char *GetCurrentLocale()
__swi_end(0x0AA, GetCurrentLocale, ());

/**
 * Get the phone's language.
 * @return pointer to the language ID
 * 
 * ```C
 * int lang_id = *RamDisplayLanguage();
 * ```
 * @deprecated Always use #GetCurrentLocale
 * */
__swi_begin(0x829D)
char *RamDisplayLanguage()
__swi_end(0x829D, RamDisplayLanguage, ());

/**
 * Get the phone's input language.
 * @return pointer to the language ID

 * ```C
 * int lang_id = *RamInputLanguage();
 * ```
 * */
__swi_begin(0x829C)
char *RamInputLanguage()
__swi_end(0x829C, RamInputLanguage, ());

/** @} */

/**
 * @name Charging and battery
 * @{
 * */

/**
 * Get ADC values.
 * 
 * Examples:
 * - GetAkku(1, 3) - Get phone temperature. Convert to celsium: `(value - 0xAAA + 15) / 10`.
 * - GetAkku(0, 9) - Get battery voltage (mV).
 * 
 * @param param1, param2	- unknown magic values
 * @return ADC value in mV
 * */
__swi_begin(0x006)
int GetAkku(int param1, int param2)
__swi_end(0x006, GetAkku, (param1, param2));

/**
 * Get the current battery level.
 * @return 0-100
 * */
__swi_begin(0x0C6)
char GetAkkuCapacity()
__swi_end(0x0C6, GetAkkuCapacity, ());

/**
 * Get pointer to the current battery level.
 * 
 * ```C
 * int capacity = *RamCap(); // 0-100
 * ```
 * @return pointer
 * @deprecated Always use #GetAkkuCapacity
 * */
__swi_begin(0x80C8)
uint16_t *RamCap()
__swi_end(0x80C8, RamCap, ());

/**
 * Get pointer to the charging state of the battery.
 * @return see #BatCharhingStateID
 * 
 * ```C
 * int charging_state = *RamLS();
 * ```
 * */
__swi_begin(0x80C9)
uint16_t *RamLS()
__swi_end(0x80C9, RamLS, ());

/** @} */

/**
 * @name Acessories
 * @{
 * */

/**
 * Get a pointer to the current accessory connected to the phone.
 * @return pointer to the unknown structure
 * */
__swi_begin(0x80D0)
void *RamAccPoint(void)
__swi_end(0x80D0, RamAccPoint, ());

/**
 * Get the type of current accessory connected to the phone.
 * @return see #AccessoryTypeID
 * */
__swi_begin(0x088)
char GetAccessoryType(void)
__swi_end(0x088, GetAccessoryType, ());

/**
 * Get the state of the various peripheries.
 * @param device	ID of the periphery: 4-gprs, 0-BT, 1-irda, 2-COM ?
 * @param check		which state to check: 4-IsActive, (1|2)-IsOn  
 * */
__swi_begin(0x24C)
int GetPeripheryState(int device, int check)
__swi_end(0x24C, GetPeripheryState, (device, check));

/** @} */

/**
 * @name Other functions
 * @{
 * */

/**
 * Get a pointer to the camera state.
 * @return state
 * 
 * ```C
 * int camera_state = *RamExtendedCameraState();
 * ```
 * */
__swi_begin(0x8299)
char *RamExtendedCameraState()
__swi_end(0x8299, RamExtendedCameraState, ());

/**
 * Pointer to the ringtone sound status.
 * 
 * @return pointer
 * 
 * ```C
 * int sounds_on = *RamRingtoneStatus();
 * ```
 * */
__swi_begin(0x80CB)
char *RamRingtoneStatus()
__swi_end(0x80CB, RamRingtoneStatus, ());

/** @} */

__swilib_end

/** @} */
