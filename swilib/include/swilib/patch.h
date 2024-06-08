#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#include "date.h"
#include "wstring.h"
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

/**
 * Accessory types.
 * */
enum AccessoryTypeID {
	ACC_TYPE_SERIAL_CABLE	= 15,	/**< DCA-510 */
	ACC_TYPE_IMS_700		= 29,	/**< IMS-700 */
};

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
 * Missed event types.
 * */
enum MissedEvent {
    MISSED_EVENT_ALL	= 0,
    MISSED_EVENT_CALLS	= 1,
    MISSED_EVENT_SMS	= 2,
    MISSED_EVENT_OTHER	= 3,
};

/**
 * @name MasterPatch
 * @{
 * */

/**
 * Run MasterPatch dispatcher.
 * @warning Function from the patch "MasterPatch", see: https://patches.kibab.com/patches/search.php5?action=search&kw=Master+Patch
 * */
__swi_begin(0x0C1)
void RunDispatcher()
__swi_end(0x0C1, RunDispatcher, ());

/**
 * Unknown.
 * @warning Function from the patch "MasterPatch", see: https://patches.kibab.com/patches/search.php5?action=search&kw=Master+Patch
 * */
__swi_begin(0x0C2)
void GetAllPatchesByInject()
__swi_end(0x0C2, GetAllPatchesByInject, ());

/**
 * [MasterPatch] Get memory buffer for the patch by ID.
 * @param patch_id	uniq patch ID
 * @warning Function from the patch "MasterPatch", see: https://patches.kibab.com/patches/search.php5?action=search&kw=Master+Patch
 * */
__swi_begin(0x0C4)
void *GetBuffer(int patch_id)
__swi_end(0x0C4, GetBuffer, (patch_id));

/**
 * Run MasterPatch scaner.
 * @warning Function from the patch "MasterPatch", see: https://patches.kibab.com/patches/search.php5?action=search&kw=Master+Patch
 * */
__swi_begin(0x0BE)
void RunScaner()
__swi_end(0x0BE, RunScaner, ());

/**
 * Pointer to the free memory for MasterPatch patches.
 * @warning Function from the patch "MasterPatch", see: https://patches.kibab.com/patches/search.php5?action=search&kw=Master+Patch
 * */
__swi_begin(0x80E4)
void *FreeRAM()
__swi_end(0x80E4, FreeRAM, ());

/** @} */

/**
 * @name API
 * @{
 * */

/**
 * Read file content.
 * @param path		path to the file
 * @param ram		unknown
 * @return file content
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x011)
char *OpenReadCloseFile(const char *path, void *ram)
__swi_end(0x011, OpenReadCloseFile, (path, ram));

/**
 * Get message from langpack.
 * @param lgp_id	langpack ID
 * @return message
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x007)
char *GetLP(int lgp_id)
__swi_end(0x007, GetLP, (lgp_id));

/**
 * Send cmd to the MediaPlayer.
 * @param cmd			command
 * @param substract		magic value
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * @deprecated see `mplayer.h` and `Send_MPlayer_Command`
 * */
__swi_begin(0x1F9)
void SendMP_cmd(uint16_t cmd, int16_t substract)
__swi_end(0x1F9, SendMP_cmd, (cmd, substract));

/**
 * Convert ANSI string to Unicode (1st word - len).
 * @param in			input string
 * @param out			output string
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * @deprecated use #str_2ws or #utf8_2ws
 * */
__swi_begin(0x0AD)
void StrAnsi2Uni(const char *in, uint16_t *out)
__swi_end(0x0AD, StrAnsi2Uni, (in, out));

/**
 * Convert Unicode string (1st word - len) to ANSI.
 * @param in			input string
 * @param out			output string
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * @deprecated use #ws_2str or #ws_2utf8
 * */
__swi_begin(0x0AE)
void StrUni2Ansi(const uint16_t *in, char *out)
__swi_end(0x0AE, StrUni2Ansi, (in, out));

/**
 * Draw image from the PIT table with "canvas" on background.
 * @param x, y		image coordinates
 * @param picture	image number
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x0B0)
void DrawPicWithCanvas(int x, int y, int picture)
__swi_end(0x0B0, DrawPicWithCanvas, (x, y, picture));

/**
 * Draw image from the PIT table with "canvas" on background.
 * @param x, y		image coordinates
 * @param picture	image number
 * @param pen		replace black color or NULL
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x0B1)
void DrawColorPicWithCanvas(int x, int y, int picture, const char *pen)
__swi_end(0x0B1, DrawColorPicWithCanvas, (x, y, picture, pen));

/**
 * Draw a multi-line string.
 * You can use #UnicodeControlChars for custom formatting of the text.
 * @param text			UTF-16 text
 * @param x, y			left+top coordinates
 * @param font			font ID, see #SystemFontID
 * @param w, h			drawing region size
 * @param align			align flags, see #TextAttributesFlags
 * @param pen			stroke color
 * @param brush			fill color
 * @param inversion		invert colors
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x0AC)
void DrawText(const WSHDR *text, int x, int y, int font, int w, int h, int align, const char *pen, const char *brush, int inversion)
__swi_end(0x0AC, DrawText, (text, x, y, font, w, h, align, pen, brush, inversion));

/**
 * Read all files in the specified folder and run a callback for each.
 * File content will be passed in the `text` argument of the callback.
 * @param path		folder path (example: `0:\Misc\*`)
 * @param callback	callback
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x0C3)
void ProcessFiles(const char *path, void (*callback)(const char *text))
__swi_end(0x0C3, ProcessFiles, (path, callback));

/**
 * Play vibration.
 * @param freq			frequency of the vibration 
 * @param duration		duration of the vibration
 * @param force			run vibration even if disabled in settings
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x056)
void PlayVibra(int freq, int duration, int force)
__swi_end(0x056, PlayVibra, (freq, duration, force));

/**
 * Play sound with vibration.
 * @param sound_n				sound ID (if > 0x80, plays with vibra)
 * @param vibra_freq			frequency of the vibration 
 * @param vibra_duration		duration of the vibration
 * @param vibra_force			run vibration even if disabled in settings
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x098)
void PlaySoundVibra(int sound_n, int vibra_freq, int vibra_duration, int vibra_force)
__swi_end(0x098, PlaySoundVibra, (sound_n, vibra_freq, vibra_duration, vibra_force));

/**
 * Recursive mkdir.
 * @param path			path for creation
 * @return path
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x097)
const WSHDR *CreatePath(const WSHDR *path)
__swi_end(0x097, CreatePath, (path));

/**
 * Unknown
 * @param timeval	unknown
 * @return timeval * 0x64 / 6
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x0B3)
long Seconds2iTime(int timeval)
__swi_end(0x0B3, Seconds2iTime, (timeval));

/**
 * Get file size.
 * @param path	path to the file
 * @return size in bytes
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x1F7)
long GetFileSize(const char *path)
__swi_end(0x1F7, GetFileSize, (path));

/**
 * Get the type of current accessory connected to the phone.
 * @return see #AccessoryTypeID
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x088)
char GetAccessoryType(void)
__swi_end(0x088, GetAccessoryType, ());

/**
 * Get missed events count.
 * @param Event		see #MissedEvent
 * @return count
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x009E)
int GetMissedEventCount(uint32_t Event)
__swi_end(0x009E, GetMissedEventCount, (Event));

/**
 * Convert Chinese one-byte C-string to WHSDR.
 * @param destination	pointer to the destination WSHDR, which should be large enough to contain the source string
 * @param source		input C-string to be converted to WSHDR
 * @param size			maximum number of characters to be converted
 * @warning Only for Chinese firmwares!
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x242)
void gb2ws(WSHDR *destination, const char *source, int size)
__swi_end(0x242, gb2ws, (destination, source, size));

/**
 * Convert WSHDR to the Chinese one-byte C-string.
 * @param source		input WSHDR to be converted to C-string
 * @param destination	pointer to the destination C-string, which should be large enough to contain the source WSHDR
 * @param size			maximum number of characters to be converted
 * @warning Only for Chinese firmwares!
 * @warning Function from the patch "API", see: https://patches.kibab.com/patches/search.php5?action=search&kw=API
 * */
__swi_begin(0x243)
void ws2gb(const WSHDR *source, char *destination, int size)
__swi_end(0x243, ws2gb, (source, destination, size));

/** @} */

/**
 * @name Screen Shooter
 * @{
 * */

/**
 * Make screenshot.
 * @warning Function from the patch "Screen Shooter", see: https://patches.kibab.com/patches/search.php5?action=search&kw=Screen+Shooter
 * */
__swi_begin(0x200)
void ScreenShoot()
__swi_end(0x200, ScreenShoot, ());

/** @} */

/**
 * @name Talking phone
 * @{
 * */

/**
 * Spell current time.
 * @warning Function from the patch "Talking phone", see: https://patches.kibab.com/patches/search.php5?action=search&kw=talking+phone
 * */
__swi_begin(0x0BF)
void SpellTime()
__swi_end(0x0BF, SpellTime, ());

/** @} */

/**
 * @name Channel Banner
 * @{
 * */

/**
 * Get list of the GSM channels RX levels.
 * @warning Function from the patch "Channel Banner", see: https://patches.kibab.com/patches/search.php5?action=search&kw=channel+banner
 * @return pointer
 * */
__swi_begin(0x81BB)
SFN_DATA *DATA_N_SFB(void)
__swi_end(0x81BB, DATA_N_SFB, ());

/** @} */

/**
 * @name BoBaPack
 * @{
 * */

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

/** @} */

/**
 * @name Extending PIT and Shortcuts.
 * @{
 * */

/**
 * Shortcuts table address.
 * @return address
 * */
__swi_begin(0x80FB)
void *ShortcutsTableAddr()
__swi_end(0x80FB, ShortcutsTableAddr, ());

/**
 * Picture relocation table address.
 * @return address
 * */
__swi_begin(0x80FC)
void *PictureRelocationTableAddr()
__swi_end(0x80FC, PictureRelocationTableAddr, ());

/**
 * Picture relocation base address.
 * @return address
 * */
__swi_begin(0x80FD)
uint32_t PictureRelocationBaseAddr()
__swi_end(0x80FD, PictureRelocationBaseAddr, ());

/**
 * Magic value for the next picture.
 * @return address
 * */
__swi_begin(0x80FE)
uint32_t NextPictureMagicValue()
__swi_end(0x80FE, NextPictureMagicValue, ());

/**
 * Additional PIT address.
 * @return address
 * */
__swi_begin(0x80F8)
void *Additional_PIT_address()
__swi_end(0x80F8, Additional_PIT_address, ());

/**
 * First PIT number for additional table.
 * @return address
 * */
__swi_begin(0x80F9)
uint32_t Additional_PIT_start()
__swi_end(0x80F9, Additional_PIT_start, ());

/**
 * Last PIT number for additional table.
 * @return address
 * */
__swi_begin(0x80FA)
uint32_t Additional_PIT_end()
__swi_end(0x80FA, Additional_PIT_end, ());

/** @} */

/**
 * @name MiniGPS.
 * @{
 * */

/**
 * Run MiniGPS patch.
 * @return address
 * */

__swi_begin(0x0C0)
uint32_t MiniGPS()
__swi_end(0x0C0, MiniGPS, ());

/** @} */

/**
 * @name Extra Info on ProgressBars.
 * @{
 * */

/**
 * Calculate current progress by current & total.
 * @param current		something "current" value
 * @param total			something "total" value
 * @return 0-100
 * @warning Function from the patch "Extra Info on ProgressBars", see: https://patches.kibab.com/patches/search.php5?action=search&kw=Extra+Info+on+ProgressBars
 * */
__swi_begin(0x1EE)
int ProgressCalculate(int current, int total)
__swi_end(0x1EE, ProgressCalculate, (current, total));

/** @} */

/**
 * @name Chinese patches.
 * @{
 * */

/**
 * Unknown.
 * @return unknown
 * @warning Function from the patch "GraphPatchManager", see: https://patches.kibab.com/patches/search.php5?action=search&kw=GraphPatchManager
 * */
__swi_begin(0x0B2)
void *GetBuildCanvas()
__swi_end(0x0B2, GetBuildCanvas, ());

/** @} */

/**
 * @name Chinese patches.
 * @{
 * */

/**
 * Convert normal date to the Lunar date.
 * @param date				normal date
 * @param[out] lunar_date	output for converted date
 * @return 0 or error
 * @warning Only in Chinese firmware.
 * */
__swi_begin(0x234)
int GetLunarDate(const TDate *date, TDate *lunar_date)
__swi_end(0x234, GetLunarDate, (date, lunar_date));

/**
 * Get Lunar Year ID by year
 * @param year	given year
 * @return 0-11
 * @warning Only in Chinese firmware.
 * */
__swi_begin(0x235)
int GetLunarYearID(int year)
__swi_end(0x235, GetLunarYearID, (year));

/**
 * Get Lunar Year animal picture by year
 * @param year	given year
 * @return picture number in PIT
 * @warning Only in Chinese firmware.
 * */
__swi_begin(0x236)
int GetLunarAnimal(int year)
__swi_end(0x236, GetLunarAnimal, (year));

/** @} */

/**
 * @name Unknown functions from unknown patches.
 * @{
 * */

/**
 * Unknown
 * @param func_id	unknown
 * */
__swi_begin(0x0C7)
void CallLibFunByNumber(int func_id)
__swi_end(0x0C7, CallLibFunByNumber, (func_id));

/** @} */

__swilib_end

/** @} */
