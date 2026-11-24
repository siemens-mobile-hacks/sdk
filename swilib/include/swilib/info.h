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
 * Battery charging state.
 * */
enum BatChargingStateID {
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
 * Get total size of the HEAP.
 * @return size
 * */
__swi_begin(0x828B)
int *RamTotalHeapSize(void)
__swi_end(0x828B, RamTotalHeapSize, ());

/**
 * Get total size of the non-perm HEAP.
 * @return size
 * */
__swi_begin(0x828C)
int *RamTemporaryHeapSize(void)
__swi_end(0x828C, RamTemporaryHeapSize, ());

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
char *GetCurrentLocale(void)
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
 * @return see #BatChargingStateID
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
 * Get the state of the various peripheries.
 * @param device	ID of the periphery: 4-gprs, 0-BT, 1-irda, 2-COM ?
 * @param check		which state to check: 4-IsActive, (1|2)-IsOn  
 * */
__swi_begin(0x24C)
int GetPeripheryState(int device, int check)
__swi_end(0x24C, GetPeripheryState, (device, check));

/** @} */

/**
 * @name Bluetooth
 * @{
 * */

/**
 * Get bluetooth visibility.
 * @return visibility
 * @platforms NSG, ELKA
 * */
__swi_begin(0x287)
int BT_GetLocVisibility(void)
__swi_end(0x287, BT_GetLocVisibility, ());

/**
 * Own bluetooth name.
 * @return C-string
 * @note Only on models with Bluetooth.
 * */
__swi_begin(0x828D)
const char *RamBluetoothDeviceName(void)
__swi_end(0x828D, RamBluetoothDeviceName, ());

/**
 * Check if bluetooth connected to the another device.
 * @return C-string
 * */
__swi_begin(0x829E)
char *RamIsBTConnected()
__swi_end(0x829E, RamIsBTConnected, ());

/**
 * Check if bluetooth connected to the headset.
 * @return pointer to the low byte of the connection handle in BT link slot 0: 0xFF if no device is connected
 * @note Any BT device in link slot 0 is reported, usually the headset.
 * */
__swi_begin(0x829F)
char *RamIsBTHeadsetConnected()
__swi_end(0x829F, RamIsBTHeadsetConnected, ());

/** @} */



/**
 * @name Events
 * @{
 * */

/**
 * Get missed events ptr.
 * @return unknown
 * */
__swi_begin(0x009D)
void *GetMissedEventsPtr(void)
__swi_end(0x009D, GetMissedEventsPtr, ());

/** @} */

/**
 * @name Other functions
 * @{
 * */

/**
 * Get slider position.
 * @return 1 if the slider is closed, 0 if it is open, 2 if the position is unknown
 * @note Always returns 2 on models without a slider.
 * */
__swi_begin(0x220)
char IsSliderClosed()
__swi_end(0x220, IsSliderClosed, ());

/**
 * Check if SIM-card is present.
 * @return pointer to the flag: nonzero while a SIM card is active, 0 if no card answered or the SIM is deactivated
 * @note The flag is nonzero during the first activation attempts at startup, until card detection finishes.
 * */
__swi_begin(0x80DE)
char *RamIsSimPresent()
__swi_end(0x80DE, RamIsSimPresent, ());

/**
 * Check if Camera is running.
 * @return 1 or 0
 * */
__swi_begin(0x8282)
char *RamIsRunCamera()
__swi_end(0x8282, RamIsRunCamera, ());

/**
 * Check if phone in shutdown process.
 * @return pointer to the flag: 1 after the power-off started by holding the end key, 0 otherwise
 * */
__swi_begin(0x80DA)
char *RamIsShutdown()
__swi_end(0x80DA, RamIsShutdown, ());

/**
 * Check if phone in standby mode.
 * @return 1 or 0
 * */
__swi_begin(0x80D3)
char *RamIsStandby()
__swi_end(0x80D3, RamIsStandby, ());

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
 * Check if camera lighter is ON.
 * @return 1 or 0
 * */
__swi_begin(0x81FE)
char *RamIsCameraLighterOn()
__swi_end(0x81FE, RamIsCameraLighterOn, ());

/**
 * Pointer to the active appointment (organizer)
 * @return 1 or 0
 * */
__swi_begin(0x8231)
void *RamActiveAppointment()
__swi_end(0x8231, RamActiveAppointment, ());

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

/**
 * Get the state of the file-operation indicator.
 * @return pointer to firmware-owned indicator state
 * */
__swi_begin(0x828A)
void *RamIsFileCache(void)
__swi_end(0x828A, RamIsFileCache, ());

/** @} */

__swilib_end

/** @} */
