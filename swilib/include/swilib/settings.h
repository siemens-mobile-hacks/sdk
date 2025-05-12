#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#include "date.h"
#include "wstring.h"
#endif

__swilib_begin

/**
 * @addtogroup Settings
 * @brief Functions for working with phone settings.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/settings.h>`
 * @{
 * */
 
typedef void (*SettingsAE_ListenerProc)(int set, const char *entry, const char *keyword);

/**
 * IDs of the settings files.
 * */
enum SettingsID {
	SETTINGS_ID_FAK,				/**< fak.pd */
	SETTINGS_ID_MYMENU,				/**< mymenu.pd */
	SETTINGS_ID_VIBRALIGHT,			/**< vibralight.pd */
	SETTINGS_ID_USERPROFILES,		/**< userprofiles.pd */
	SETTINGS_ID_SETUP,				/**< setup.pd */
	SETTINGS_ID_DEVELOPER_MENU,		/**< developer_menu.pd */
	SETTINGS_ID_APIDC_SETUP,		/**< apidc_setup.pd */
	SETTINGS_ID_MEDIAPLAYER,		/**< mediaplayer.pd */
	SETTINGS_ID_SOUNDRECORDER,		/**< soundrecorder.pd */
	SETTINGS_ID_FRDB,				/**< frdb.pd */
	SETTINGS_ID_AVATAR,				/**< avatar.pd */
	SETTINGS_ID_RADIO,				/**< radio.pd */
	SETTINGS_ID_ORANGEHOMESCREEN,	/**< orangehomescreen.pd */
};

/**
 * Types of the profile volume.
 * */
enum ProfileVolumeTypeID {
	PROFILE_VOLUME_TYPE_MAIN		= 0x12,	/**< Main phone volume */
	PROFILE_VOLUME_TYPE_ALARMCLOCK	= 0xD,	/**< AlarmClock volume */
	PROFILE_VOLUME_TYPE_INCALL		= 2,	/**< Incall volume */
};

/**
 * @name Date
 * @{
 * */

/**
 * Update phone date and time.
 * @param date	new date
 * @param time	new time
 * */
__swi_begin(0x241)
void SetDateTime(const TDate *date, const TTime *time)
__swi_end(0x241, SetDateTime, (date, time));

/** @} */

/**
 * @name Backlight
 * @{
 * */

/**
 * Change maximum backlight level.
 * This function updates DISPLAY_ILLUMINATION in setup.pd
 * @param level		0-100
 * */
__swi_begin(0x2DC)
void SaveMaxIllumination(int level)
__swi_end(0x2DC, SaveMaxIllumination, (level));

/**
 * Change the backlight timeout (time to OFF).
 * This function updates DISPLAY_ILLUMINATION_TIMEOUT in setup.pd
 * @param timeout		time in seconds
 * */
__swi_begin(0x2DD)
void SetIlluminationoffTimeout(int timeout)
__swi_end(0x2DD, SetIlluminationoffTimeout, (timeout));

/** @} */

/**
 * @name SettingsAE
 * 
 * Functions for working with settings in `.pd` file format.
 * 
 * The ".pd" file format is a plain analog of the.ini files:
 * - Settings are grouped by entries. This is identical to the `[section]` in `.ini`.
 * - Each entry contains pairs of the keyword=value.
 * - There is a global section (when the `entry` is an empty string).
 * 
 * For example, `.ini` analog:
 * ```ini
 * keyword=value
 * 
 * [entry]
 * keyword=value
 * ```
 * 
 * As a ".pd" file, it will look like this:
 * ```ini
 * 000022:T:keyword=value1
 * 000028:T:entry.keyword=value2
 * ```
 * 
 * These values can be accessed like this:
 * ```C
 * SettingsAE_Read_ws(ws, SETTINGS_ID_FAK, "", "keyword"); // value1
 * SettingsAE_Read_ws(ws, SETTINGS_ID_FAK, "entry", "keyword"); // value2
 * ```
 * 
 * @{
 * */

/**
 * Get the setting value (flag 1 or 0).
 * @param value		pointer where the result will be written
 * @param set_id	settings file id (#SettingsID)
 * @param entry		entry id
 * @param keyword	key
 * @return 0 or error
 * */
__swi_begin(0x2E7)
int SettingsAE_GetFlag(int *value, int set_id, char *entry, char *keyword)
__swi_end(0x2E7, SettingsAE_GetFlag, (value, set_id, entry, keyword));

/**
 * Get the setting value (int).
 * @param value		pointer where the result will be written
 * @param set_id	settings file id (#SettingsID)
 * @param entry		entry id
 * @param keyword	key
 * @return 0 or error
 * */
__swi_begin(0x2E9)
int SettingsAE_Read(int *value, int set_id, char *entry, char *keyword)
__swi_end(0x2E9, SettingsAE_Read, (value, set_id, entry, keyword));

/**
 * Get a list of record IDs in a settings file
 * @param set_id	settings file id (#SettingsID)
 * @return pointer to the array of C strings
 * */
__swi_begin(0x2EA)
char **SettingsAE_GetEntryList(int set_id)
__swi_end(0x2EA, SettingsAE_GetEntryList, (set_id));

/**
 * Get the setting value (WSHDR).
 * @param value		pointer where the result will be written
 * @param set_id	settings file id (#SettingsID)
 * @param entry		entry id
 * @param keyword	key
 * @return 0 or error
 * */
__swi_begin(0x2E5)
int SettingsAE_Read_ws(WSHDR *value, int set_id, char *entry, char *keyword)
__swi_end(0x2E5, SettingsAE_Read_ws, (value, set_id, entry, keyword));

/**
 * Set the setting value (int).
 * @param value		new value
 * @param set_id	settings file id (#SettingsID)
 * @param entry		entry id
 * @param keyword	key
 * @return 0 or error
 * */
__swi_begin(0x2E8)
int SettingsAE_Update(int value, int set_id, char *entry, char *keyword)
__swi_end(0x2E8, SettingsAE_Update, (value, set_id, entry, keyword));

/**
 * Set the setting value (WSHDR).
 * @param value		new value
 * @param set_id	settings file id (#SettingsID)
 * @param entry		entry id
 * @param keyword	key
 * @return 0 or error
 * */
__swi_begin(0x2E4)
int SettingsAE_Update_ws(WSHDR *value, int set_id, char *entry, char *keyword)
__swi_end(0x2E4, SettingsAE_Update_ws, (value, set_id, entry, keyword));

/**
 * Set the setting value (flag 1 or 0).
 * @param value		new value
 * @param set_id	settings file id (#SettingsID)
 * @param entry		entry id
 * @param keyword	key
 * @return 0 or error
 * */
__swi_begin(0x2E6)
int SettingsAE_SetFlag(int value, int set_id, char *entry, char *keyword)
__swi_end(0x2E6, SettingsAE_SetFlag, (value, set_id, entry, keyword));

/**
 * Delete an entry and all its values.
 * @param set_id	settings file id (#SettingsID)
 * @param entry		entry id
 * @param flag		unknown
 * @return 0 or error
 * */
__swi_begin(0x2EB)
int SettingsAE_RemoveEntry(int set_id, char *entry, int flag)
__swi_end(0x2EB, SettingsAE_RemoveEntry, (set_id, entry, flag));

/**
 * Register SettingsAE changes listener.
 * @param proc		callback
 * @param set_id	settings file id (#SettingsID)
 * @param entry		entry id
 * @param keyword	key
 * */
__swi_begin(0x3B0)
void SettingsAE_RegisterListener(SettingsAE_ListenerProc proc, int set_id, const char *entry, const char *keyword)
__swi_end(0x3B0, SettingsAE_RegisterListener, (proc, set_id, entry, keyword));

/**
 * Unregister SettingsAE changes listener.
 * @param proc		callback
 * @param set_id	settings file id (#SettingsID)
 * @param entry		entry id
 * @param keyword	key
 * */
__swi_begin(0x3B1)
void SettingsAE_DeregisterListener(SettingsAE_ListenerProc proc, int set_id, const char *entry, const char *keyword)
__swi_end(0x3B1, SettingsAE_DeregisterListener, (proc, set_id, entry, keyword));

/** @} */

/**
 * @name Registry
 * @{
 * */

/**
 * Converting string key to the HMI key ID.
 * @param key		string like "Wallpaper", "Screensaver", ...
 * @return id
 * */
__swi_begin(0x038)
int Registry_GetHMIKeyID(char *key)
__swi_end(0x038, Registry_GetHMIKeyID, (key));

/**
 * Get resource path from the registry.
 * @param hmi_key_id	HMID key ID, see #Registry_GetHMIKeyID
 * @param start_prio	initial priority for searching in registry
 * @param[out] prio		actual priority of the founded resource path
 * @param[out] path		founded resource path
 * @return 0 or error
 * */
__swi_begin(0x03E)
int Registry_GetResourcePathFromLevel(int hmi_key_id, int start_prio, int *prio, WSHDR *path)
__swi_end(0x03E, Registry_GetResourcePathFromLevel, (hmi_key_id, start_prio, prio, path));

/**
 * Set a path to the resource with priority.
 * @param hmi_key_id	HMID key ID, see #Registry_GetHMIKeyID
 * @param prio			priority of this resource path
 * @param path			path to the resource
 * @return 0 or error
 * */
__swi_begin(0x039)
int Registry_SetResourcePath(int hmi_key_id, int prio, const WSHDR *path)
__swi_end(0x039, Registry_SetResourcePath, (hmi_key_id, prio, path));

/**
 * Remove the path with given priority from the registry.
 * @param hmi_key_id	HMID key ID, see #Registry_GetHMIKeyID
 * @param prio			priority of resource path
 * @return 0 or error
 * */
__swi_begin(0x03A)
int Registry_DeleteResourcePath(int hmi_key_id, int prio)
__swi_end(0x03A, Registry_DeleteResourcePath, (hmi_key_id, prio));

/**
 * Get the setting value from PD file.
 * @param file_id		unique file id
 * @param key			keyword
 * @param[out] value	pointer where the result will be written
 * @param size			max length, read size will be written in variable
 * @return 0 or error
 * */
__swi_begin(0x3DD)
uint32_t ReadValueFromPDFile(uint32_t file_id, const char *key, char *value, uint32_t *size)
__swi_end(0x3DD, ReadValueFromPDFile, (file_id, key, value, size));

/** @} */

/**
 * @name Profiles
 * @{
 * */

/**
 * Get ID of the active profile.
 * @return ID
 * */
__swi_begin(0x0B6)
char GetProfile()
__swi_end(0x0B6, GetProfile, ());

/**
 * Get ID of the active profile.
 * @return pointer to the ID
 * @deprecated use #GetProfile
 * */
__swi_begin(0x80E3)
char *RamProfileNum()
__swi_end(0x80E3, RamProfileNum, ());

/**
 * Change profile.
 * @param profile_id	profile ID
 * @return 0 or error
 * */
__swi_begin(0x0B7)
char SetProfile(char profile_id)
__swi_end(0x0B7, SetProfile, (profile_id));

/**
 * Get profile name by ID.
 * @param[out] name		profile name
 * @param profile_id	profile ID
 * @param unk			set to 0
 * */
__swi_begin(0x296)
void getProfileNameByN(WSHDR *name, int profile_id, int unk)
__swi_end(0x296, getProfileNameByN, (name, profile_id, unk));

/**
 * Get current profile name.
 * @param[out] name		profile name
 * */
__swi_begin(0x08D)
void getCurrentProfileName(WSHDR *name)
__swi_end(0x08D, getCurrentProfileName, (name));

/**
 * Get volume from the profile.
 * @param profile_id	profile ID
 * @param type			volume type, see #ProfileVolumeTypeID
 * */
__swi_begin(0x2C4)
int GetProfileVolumeSetting(int profile_id, int type)
__swi_end(0x2C4, GetProfileVolumeSetting, (profile_id, type));

/** @} */

/**
 * @name Ringtones
 * @{
 * */

/**
 * Set ringtones state.
 * @param state		1 - on, 0 - off
 * */
__swi_begin(0x0037)
void Ringtones_SetState(uint8_t state)
__swi_end(0x0037, Ringtones_SetState, (state));

/** @} */

/**
 * @name Low-level functions for settings cache.
 * @{
 * */

/**
 * Get raw setting value from cache.
 * @param value		pointer where the result will be written
 * @param maxlen	maximum size of the value buffer
 * @param set_id	settings file id (#SettingsID)
 * @param entry		entry id
 * @param keyword	key
 * @return 0 or error
 * */
__swi_begin(0x22C)
int pdcache_getval(char *value, int maxlen, int set_id, const char *entry, const char *keyword)
__swi_end(0x22C, pdcache_getval, (value, maxlen, set_id, entry, keyword));

/**
 * Set raw setting value to cache.
 * @param value		raw value
 * @param set_id	settings file id (#SettingsID)
 * @param entry		entry id
 * @param keyword	key
 * @return 0 or error
 * */
__swi_begin(0x22D)
int pdcache_setval(const char *value, int set_id, const char *entry, const char *keyword)
__swi_end(0x22D, pdcache_setval, (value, set_id, entry, keyword));

/** @} */

__swilib_end

/** @} */
