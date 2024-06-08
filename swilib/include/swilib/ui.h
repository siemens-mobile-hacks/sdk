#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#include "wstring.h"
#include "date.h"
#include "gui.h"
#endif

__swilib_begin

/**
 * @addtogroup UI
 * @brief Standart user interface.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/ui.h>`
 * @{
 */

typedef struct EDITCONTROL EDITCONTROL;
typedef struct EDITC_OPTIONS EDITC_OPTIONS;
typedef struct EDITQ EDITQ;
typedef struct INPUTDIA_DESC INPUTDIA_DESC;
typedef struct USR_MENU_ITEM USR_MENU_ITEM;
typedef struct HEADER_DESC HEADER_DESC;
typedef struct SOFTKEY_DESC SOFTKEY_DESC;
typedef struct SOFTKEYSTAB SOFTKEYSTAB;
typedef struct MENUITEM_DESC MENUITEM_DESC;
typedef struct MENU_DESC MENU_DESC;
typedef struct ML_MENU_DESC ML_MENU_DESC;
typedef struct POPUP_DESC POPUP_DESC;
typedef struct TABGUI_DESC TABGUI_DESC;
typedef struct TVIEW_DESC TVIEW_DESC;
typedef struct PBAR_DESC PBAR_DESC;

/**
 * Menu item draw callback.
 * @param gui		pointer to the Menu GUI
 * @param item_n	index of the item
 * @param item		pointer to the item
 * */
typedef void (*MENUITEM_DRAW_PROC)(void *gui, int item_n, void *item);

/**
 * Menu item select callback.
 * @param gui		pointer to the Menu GUI
 * */
typedef void (*MENUPROCS_DESC)(GUI *gui);

/**
 * GUI keys handler.
 * @param gui		pointer to the GUI
 * @param msg		keyboard message
 * @return value which passed to the GeneralFunc
 * */
typedef int (*GUI_ONKEY_CALLBACK)(GUI *gui, GUI_MSG *msg);

/**
 * GUI global hook.
 * @param gui		pointer to the GUI
 * @param cmd		command from the GeneralFunc
 * */
typedef void (*GUI_GHOOK_CALLBACK)(GUI *gui, int cmd);

/**
 * GUI locret callback (empty stub).
 * */
typedef void (*GUI_LOCRET_CALLBACK)(void);

/**
 * Menu search callback.
 * @param gui		pointer to the GUI
 * @param search	search query
 * @return -1
 * */
typedef int (*MenuSearchCallBack)(void *gui, WSHDR *search);

/**
 * Flags for #ShowMSG.
 * */
enum MsgBoxFlags {
	MSG_BOX_CANCELANLE		= 1 << 0,	/**< Allow cancel MsgBox withou waiting */
	MSG_BOX_TRANSPARENT_BG	= 1 << 1,	/**< MsgBox on the transparent background */
};

/**
 * Flags for #MsgBoxYesNo or MsgBoxOkCancel.
 * */
enum PopupDialogFlags {
	CONFITM_BOX_TRANSPARENT_BG	= 1 << 0,	/**< MsgBox on the transparent background */
};

/**
 * Softkey IDs for #SetSoftKey
 * */
enum SetSoftKeyID {
#ifdef NEWSGOLD
	SET_LEFT_SOFTKEY	= 0,	/**< Left softkey */
	SET_RIGHT_SOFTKEY	= 1,	/**< Right softkey */
	SET_MIDDLE_SOFTKEY	= 2,	/**< Middle softkey */
#else
	SET_LEFT_SOFTKEY	= 1,	/**< Left softkey */
	SET_RIGHT_SOFTKEY	= 0,	/**< Right softkey */
	SET_MIDDLE_SOFTKEY	= 2,	/**< Middle softkey */
#endif
};

#define SET_SOFT_KEY_N SET_LEFT_SOFTKEY
#define SET_SOFT_KEY_M SET_MIDDLE_SOFTKEY

#ifdef ELKA
	#define MENU_FLAG3	3		/**< Magic value */
	#define MENU_FLAG2	0x5A2	/**< Magic value */
	#define YDISP		(24)	/**< Iconbar height */
#elif defined(NEWSGOLD)
	#define MENU_FLAG3	3		/**< Magic value */
	#define MENU_FLAG2	0x59D	/**< Magic value */
	#define YDISP		(0)		/**< Iconbar height */
#else
	#define MENU_FLAG3	3		/**< Magic value */
	#define MENU_FLAG2	0x578	/**< Magic value */
	#define YDISP		(0)		/**< Iconbar height */
#endif

/**
 * Types of the EditControl.
 * */
enum EditControlTypeID {
	ECT_READ_ONLY				= 0,
	ECT_HEADER					= 1,
	ECT_NUMBER_TYPING			= 2,
	ECT_NORMAL_TEXT				= 3,
	ECT_CURSOR_STAY				= 4,
	ECT_FIXED_STR_NUM			= 5,
	ECT_NORMAL_NUM				= 6,
	ECT_COMBO_BOX				= 7,
	ECT_READ_ONLY_SELECTED		= 8,
	ECT_LINK					= 9,
	ECT_CALENDAR				= 10,
	ECT_TIME					= 11,
};

/**
 * Flags for the EditControl.
 * */
enum EditControlFlags {
	ECF_NORMAL_STR				= 0,
	ECF_SKIP					= 4,
	ECF_INVISIBLE_CURSOR		= 8,
	ECF_PASSW					= 0x10,
	ECF_DELSTR					= 0x20,
	ECF_APPEND_EOL				= 0x40,
	ECF_SET_CURSOR_END			= 0x80,
	ECF_DISABLE_NUM				= 0x100,
	ECF_DISABLE_SMALL_LETTERS	= 0x200,
	ECF_DISABLE_BIG_LETTERS		= 0x400,
	ECF_DEFAULT_BIG_LETTER		= 0x1000, /**< Enable big letter after ". " */
	ECF_DISABLE_T9				= 0x2000,
	ECF_DEFAULT_ITAP			= 0x4000,
	ECF_DEFAULT_DIGIT			= 0x8000,
	ECF_DISABLE_EOLCHAR			= 0x10000, /**< In chartable */
	ECF_DISABLE_MINUS			= 0x20000, /**< Also disable # */
	ECF_DISABLE_POINT			= 0x40000, /**< Also disable * */
	ECF_LONGDIEZ_EQ_QUESTION	= 0x80000,
	ECF_ENABLE_TEXT_FORMAT		= 0x800000,
	ECF_MARKED					= 0x2000000,
	ECF_GRAY					= 0x4000000,
};

/**
 * TextInputDialog ghook commands.
 * */
enum TextInputDialogCmdID {
	TI_CMD_CREATE			= 2,
	TI_CMD_DESTROY			= 3,
	TI_CMD_REDRAW			= 7,
	TI_CMD_UNFOCUS			= 9,
	TI_CMD_FOCUS			= 10,
	TI_CMD_SUBFOCUS_CHANGE	= 12,
	TI_CMD_COMBOBOX_FOCUS	= 13,
};

/**
 * InputDialog options.
 * */
enum InputDialogFlags {
	INPUTDIA_FLAGS_READONLY			= 0x00000002,
	INPUTDIA_FLAGS_LOCK_CURSOR		= 0x00000004,
	INPUTDIA_FLAGS_SWAP_SOFTKEYS	= 0x40000000,
};

/**
 * Menu options.
 * */
enum MenuDialogFlags {
	MENU_FLAGS_ENABLE_ICONS				= 0x00000001,
	MENU_FLAGS_ENABLE_TEXT_SCROLLING	= 0x00000010,
	MENU_FLAGS_DISABLE_SCROLLBAR		= 0x00000040,
	MENU_FLAGS_ENABLE_BIG_LETTERS		= 0x00000080,
	MENU_FLAGS_ALIGN_RIGHT				= 0x00000100,
	MENU_FLAGS_DISABLE_BREAKLINE		= 0x00000400,
	MENU_FLAGS_ENABLE_SEARCH			= 0x00010000,
};

/**
 * UI header definition.
 * */
struct HEADER_DESC {
	RECT rc;		/**< Rectangular region on the screen */
	int *icon;		/**< Pointer to the varibale with actual header icon or NULL */
	int lgp_id;		/**< Header title, LGP ID or pointer to the C-string **/
	int lgp_null;	/**< Set to #LGP_NULL */
};

/**
 * UI softkey definition.
 * */
struct SOFTKEY_DESC {
	short key1;
	short key2;
	int lgp_id;		/**< LGP ID or pointer to the C-string */
};

/**
 * List of the softkeys.
 * */
struct SOFTKEYSTAB {
	const SOFTKEY_DESC *desc;		/**< C-array of the softkeys */
	int n;							/**< Count of the softkeys in array */
};

/**
 * Linked-list of the EditControl's.
 * */
struct EDITQ {
	void *next;	/**< Next item */
	void *prev;	/**< Prev item */
	void *data;	/**< EditControl */
};

/**
 * Custom options for EditControl.
 * */
struct EDITC_OPTIONS {
	uint16_t invert;	/**< Enable invertion */
	uint16_t bitmask;
	char font;			/**< Font id, see #SystemFontID */
	char align;			/**< Text attributes, see #TextAttributesFlags */
	char pen[4];		/**< RGBA text color */
	char brush[4];		/**< RGBA background color */
};

/**
 * EditControl definition.
 * */
#pragma pack(2)
struct EDITCONTROL {
	char type;					/**< #EditControlTypeID */
	char unk2[3];
	int flag;
	char zero_cbox;				/**< If text input field: lang 0 - default, 2 - english */
	char unk5;
	EDITC_OPTIONS ed_options;	/**< Custom options */
	short maxlen;				/**< Maximum length of the value */
	short num_of_items_cbox;	/**< Number of the items in combo-box */
	short start_item_cbox;		/**< Index of the selected item in combo-box */
	short unk9;
	short unk10;
	short unk11;
	int unk12;
	WSHDR *pWS;					/**< Current value */
};
#pragma pack()

/**
 * InputDialog definition.
 * */
struct INPUTDIA_DESC {
	int one;										/**< Set to 1 */
	GUI_ONKEY_CALLBACK onKey;						/**< Key handler */
	GUI_GHOOK_CALLBACK global_hook_proc;			/**< Global hook handler (ghook) */
	GUI_LOCRET_CALLBACK locret;						/**< Pointer to the empty function */
	int zero1;										/**< Set to 0 */
	const SOFTKEYSTAB *softkeystab;					/**< Pointer to the softkeys definition */
	RECT rc;										/**< Rectangular region on the screen */
	int font;										/**< Font size, see #SystemFontID */
	int _100;										/**< Set to 100 */
	int _101;										/**< Set to 101 */
	int zero2;										/**< Set to 0 */

#ifdef SWILIB_MODERN
	int text_attrs;		/**< Text attributes, see #TextAttributesFlags (old name zero3) */
	int flags;			/**< InputDialog flags, see #InputDialogFlags (old name _0x40000000) */
#else
	union { int zero3; int text_attrs; };
	union { int _0x40000000; int flags; };
#endif
};

/**
 * Custom options menu item for InputDialog.
 * */
struct USR_MENU_ITEM {
	char type;				/**< Type of item */
	void *user_pointer;		/**< Custom user pointer */
	uint16_t cur_item;
	WSHDR *ws;				/**< Text of the menu item */
};

/**
 * Menu item.
 * */
struct MENUITEM_DESC {
	int *icon;				/**< Item icons array */
	int lgp_id_small;		/**< LGP ID or pointer to the C-string */
	int lgp_id_large;		/**< LGP ID or pointer to the C-string */
	int zero;				/**< 0 */
	const int *softkeys;	/**< Custom softkeys mapping or NULL */
	int flag1;				/**< #MENU_FLAG3 */
	int flag2;				/**< #MENU_FLAG2 */
};

/**
 * Menu definition (single-line).
 * */
struct MENU_DESC {
	int flag;								/**< 0,8 etc */
	GUI_ONKEY_CALLBACK onkey;				/**< Key handler */
	GUI_GHOOK_CALLBACK ghook;				/**< Global hook handler (ghook) */
	GUI_LOCRET_CALLBACK proc3;				/**< Pointer to the empty function */
	const int *softkeys;					/**< Softkeys mapping from softkeystab, example: {0, 1, 2} */
	const SOFTKEYSTAB *softkeystab;			/**< Pointer to the softkeys definition */
	int flags2;								/**< Menu options, see #MenuDialogFlags */
	MENUITEM_DRAW_PROC itemproc;			/** Called when draw item */
	const MENUITEM_DESC *items;				/** C-array of the default items, or NULL */
	const MENUPROCS_DESC *procs;			/**< C-array of the selection callbacks for the each item, or NULL */
	int n_items;							/**< Number of the items */
};

/**
 * Menu definition (multi-line).
 * */
struct ML_MENU_DESC {
	int flag;								/**< 0,8 etc */
	GUI_ONKEY_CALLBACK onkey;				/**< Key handler */
	GUI_GHOOK_CALLBACK ghook;				/**< Global hook handler (ghook) */
	GUI_LOCRET_CALLBACK proc3;				/**< Pointer to the empty function */
	const int *softkeys;					/**< Softkeys mapping from softkeystab, example: {0, 1, 2} */
	const SOFTKEYSTAB *softkeystab;			/**< Pointer to the softkeys definition */
	int flags2;								/**< Menu options, see #MenuDialogFlags */
	MENUITEM_DRAW_PROC itemproc;			/** Called when draw item */
	const MENUITEM_DESC *items;				/** C-array of the default items, or NULL */
	const MENUPROCS_DESC *procs;			/**< C-array of the callbacks for the each item, or NULL */
	int n_items;							/**< Number of the items */
	int n_lines;							/**< Number of the lines in selected item */
};

/**
 * Popup definition.
 * */
struct POPUP_DESC {
	int flag;								/**< 0,8 etc */
	GUI_ONKEY_CALLBACK onKey;				/**< Key handler */
	GUI_GHOOK_CALLBACK global_hook_proc;	/**< Global hook handler (ghook) */
	GUI_LOCRET_CALLBACK proc3;				/**< Pointer to the empty function */
	const int *softkeys;					/**< Softkeys mapping from softkeystab, example: {0, 1, 2} */
	const SOFTKEYSTAB *softkeystab;			/**< Pointer to the softkeys definition */
	int flags2;								/**< Popup options */
	int lgp_null;							/**< Set to #LGP_NULL */
	const int *icons;						/**< C-array of the icons (ID from PIT or pointer to IMGHDR), last item is always 0 */
	int zero0;								/** Set to 0 */
	int font;								/**< Font size, see #SystemFontID */
	int _100;								/**< Set to 100 */
	int _101;								/**< Set to 101 */
	int zero2;								/**< Set to 0 */
	int time;								/**< Show timeout in clocks (1 clock = 4.615 ms) */
};

/**
 * Popup definition.
 * */
struct TVIEW_DESC {
	int flag;								/**< ? */
	GUI_ONKEY_CALLBACK onKey;				/**< Key handler */
	GUI_GHOOK_CALLBACK global_hook_proc;	/**< Global hook handler (ghook) */
	GUI_LOCRET_CALLBACK locret;				/**< Pointer to the empty function */
	const int *softkeys;					/**< Softkeys mapping from softkeystab, example: {0, 1, 2} */
	const SOFTKEYSTAB *softkeystab;			/**< Pointer to the softkeys definition */
	RECT rc;								/**< Rectangular region on the screen */
	int font;								/**< Font size, see #SystemFontID */
	int unk1;								/**< 0x64, 0x81 */
	int unk2;								/**< 0x65, 0x82 */
	int unk3;								/**< 0 */
	int unk4;								/**< 0, 1, 2 */
};

/**
 * Tabs definition.
 * */
struct TABGUI_DESC {
	int flag;								/**< 8, a, b etc */
	GUI_ONKEY_CALLBACK onKey;				/**< Key handler */
	GUI_GHOOK_CALLBACK global_hook_proc;	/**< Global hook handler (ghook) */
	void *locret;							/**< Pointer to the empty function */
	const int *softkeys;					/**< Softkeys mapping from softkeystab, example: {0, 1, 2} */
	const SOFTKEYSTAB *softkeystab;			/**< Pointer to the softkeys definition */
};

/**
 * Progressbar deinition.
 * */
struct PBAR_DESC {
    int flag;						/**< 0, 8 */
    GUI_ONKEY_CALLBACK onkey;		/**< Key handler */
    GUI_GHOOK_CALLBACK ghook;		/**< Global hook handler (ghook) */
    void *proc3;					/**< Pointer to the function, see #GetPBarProc3() */
    const int *softkeys;			/**< Softkeys mapping from softkeystab, example: {0, 1, 2} */
    const SOFTKEYSTAB *softkeystab;	/**< Pointer to the softkeys definition */
    char zero[32];					/**< Unknown data */
};

/**
 * @name Common UI functions.
 * @{
 * */

/**
 * Get pointer to the UI header.
 * @param gui		pointer to the any #GUI
 * @return pointer
 * */
__swi_begin(0x2AE)
void *GetHeaderPointer(void *gui)
__swi_end(0x2AE, GetHeaderPointer, (gui));

/**
 * Set main text to the UI header.
 * @param header		pointer to the header (#GetHeaderPointer)
 * @param title			new title value
 * @param malloc_fn		result of #malloc_adr()
 * @param mfree_fn		result of #mfree_adr()
 * */
__swi_begin(0x2AF)
void SetHeaderText(void *header, const WSHDR *title, const void *malloc_fn, const void *mfree_fn)
__swi_end(0x2AF, SetHeaderText, (header, title, malloc_fn, mfree_fn));

/**
 * Set scolled text to the UI header.
 * @param header		pointer to the header (#GetHeaderPointer)
 * @param title			new title value
 * @param malloc_fn		result of #malloc_adr()
 * @param mfree_fn		result of #mfree_adr()
 * */
__swi_begin(0x3C6)
void SetHeaderScrollText(void *header, const WSHDR *title, const void *malloc_fn, const void *mfree_fn)
__swi_end(0x3C6, SetHeaderScrollText, (header, title, malloc_fn, mfree_fn));

/**
 * Set extra text to the UI header.
 * @param header		pointer to the header (#GetHeaderPointer)
 * @param ws			new extra title value
 * @param malloc_fn		result of #malloc_adr()
 * @param mfree_fn		result of #mfree_adr()
 * */
__swi_begin(0x3C7)
void SetHeaderExtraText(void *header, const WSHDR *ws, const void *malloc_fn, const void *mfree_fn)
__swi_end(0x3C7, SetHeaderExtraText, (header, ws, malloc_fn, mfree_fn));

/**
 * Get pointer to the UI header.
 * @param header		pointer to the header (#GetHeaderPointer)
 * @param icons			C-array of the icons (ID from PIT or pointer to IMGHDR), last item is always 0
 * @param malloc_fn		result of #malloc_adr()
 * @param mfree_fn		result of #mfree_adr()
 * */
__swi_begin(0x2BA)
void SetHeaderIcon(void *header, const int *icons, const void *malloc_fn, const void *mfree_fn)
__swi_end(0x2BA, SetHeaderIcon, (header, icons, malloc_fn, mfree_fn));

/**
 * Add softkey to the GUI.
 * @param gui			pointer to the any #GUI
 * @param softkey		pointer to the softkey definition
 * @param softkey_id	see #SetSoftKeyID
 * */
__swi_begin(0x168)
void SetSoftKey(void *gui, const SOFTKEY_DESC *softkey, int softkey_id)
__swi_end(0x168, SetSoftKey, (gui, softkey, softkey_id));

/**
 * Force refresh current GUI.
 * */
__swi_begin(0x196)
void RefreshGUI(void)
__swi_end(0x196, RefreshGUI, ());

/**
 * Set UI definition to the GUI.
 * @param gui			pointer to the any #GUI
 * @param definition	pointer to the #MENU_DESC, #ML_MENU_DESC, #TABGUI_DESC, #INPUTDIA_DESC, #POPUP_DESC, #TVIEW_DESC
 * */
__swi_begin(0x2BC)
void SetGUIDefinition(void *gui, const void *definition)
__swi_end(0x2BC, SetGUIDefinition, (gui, definition));

/**
 * Find private item in the GUI.
 * @param gui		pointer to the any #GUI
 * @param id		ID of the private item
 * @return pointer to the item structure
 * */
__swi_begin(0x14E)
void *FindItemByID(GUI *gui, int id)
__swi_end(0x14E, FindItemByID, (gui, id));

/**
 * Get data of the private item in the GUI.
 * @param gui		pointer to the any #GUI
 * @param id		ID of the private item
 * @return pointer to the item data
 * */
__swi_begin(0x14F)
void *GetDataOfItemByID(GUI *gui, int id)
__swi_end(0x14F, GetDataOfItemByID, (gui, id));

/** @} */

/**
 * @name Iconbar
 * @{
 * */

/**
 * Push icon to the iconbar (E/EL71).
 * @param pic		number of the icon in PIT table
 * @param num		poinetr to the icon index (from iconbar hook)
 * 
 * Call this function the iconbar hook.
 * 
 * @warning Depend of the patch: https://patches.kibab.com/patches/search.php5?action=search&kw=Elfs+can+add+icons+to+iconbar
 * */
__swi_begin(0x027)
void AddIconToIconBar(int pic, short* num)
__swi_end(0x027, AddIconToIconBar, (pic, num));

/**
 * Pointer to the status of iconbar (EL/E71).
 * @return 1: enabled, 0: disabled
 * @platforms ELKA
 * 
 * ```C
 * int iconbar_is_enabled = *RamIconBar();
 * ```
 * */
__swi_begin(0x8237)
char *RamIconBar()
__swi_end(0x8237, RamIconBar, ());

/**
 * Enable or disable global iconbar on EL/E71.
 * @param disable		1 for disable, 0 for enable
 * */
__swi_begin(0x23B)
void DisableIconBar(int disable)
__swi_end(0x23B, DisableIconBar, (disable));

/** @} */

/**
 * @name Popups
 * @{
 * */

/**
 * Show info popup.
 * @param flags			see #MsgBoxFlags
 * @param message		id from the langpack or pointer to the C-string
 * @return GUI ID
 * 
 * ```C
 * ShowMSG(0, (int) "Hello World!")
 * ```
 * */
__swi_begin(0x148)
int ShowMSG(int flags, int message)
__swi_end(0x148, ShowMSG, (flags, message));

/**
 * Show error popup.
 * @param flags			see #MsgBoxFlags
 * @param message		id from the langpack or pointer to the C-string
 * @return GUI ID
 * 
 * ```C
 * MsgBoxError(0, (int) "Error!")
 * ```
 * */
__swi_begin(0x04E)
int MsgBoxError(int flags, int message)
__swi_end(0x04E, MsgBoxError, (flags, message));

/**
 * Confirmation popup with Yes/No.
 * @param flags			see #PopupDialogFlags
 * @param message		id from the langpack or pointer to the C-string
 * @param callback		callback for handling popup answer
 * @return GUI ID
 * 
 * ```C
 * void erase_eeprom_handler(int canceled) {
 *		if (!canceled) { // YES
 * 			do_erase();
 * 		} else { // NO
 * 			// ...
 * 		}
 * }
 * // ...
 * MsgBoxYesNo(0, (int) "Erase EEPROM?", erase_eeprom_handler)
 * ```
 * */
__swi_begin(0x04F)
int MsgBoxYesNo(int flags, int message, void (*callback)(int canceled))
__swi_end(0x04F, MsgBoxYesNo, (flags, message, callback));

/**
 * Confirmation popup with Ok/Cancel.
 * @param flags			see #PopupDialogFlags
 * @param message		id from the langpack or pointer to the C-string
 * @param callback		callback for handling popup answer
 * @return GUI ID
 * 
 * ```C
 * void erase_eeprom_handler(int canceled) {
 *		if (!canceled) { // YES
 * 			do_erase();
 * 		} else { // NO
 * 			// ...
 * 		}
 * }
 * // ...
 * MsgBoxOkCancel(0, (int) "Erase EEPROM?", erase_eeprom_handler)
 * ```
 * */
__swi_begin(0x050)
int MsgBoxOkCancel(int flags, int message, void (*callback)(int canceled))
__swi_end(0x050, MsgBoxOkCancel, (flags, message, callback));

/**
 * Wait popup.
 * @param flags
 * @param message		id from the langpack or pointer to the C-string
 * @return GUI_ID
 * */
__swi_begin(0x3C0)
int ShowWaitBox(int flags, int message)
__swi_end(0x3C0, ShowWaitBox, (flags, message));

/**
 * Get pointer for proc3 method of #PBAR_DESC struct.
 * @return pointer
 * */
__swi_begin(0x83C5)
void *GetPBarProc3()
__swi_end(0x83C5, GetPBarProc3, ());
/**
 * Progressbar popup.
 * @param flags
 * @param message		id from the langpack or pointer to the C-string
 * @param pbar_desc		pointer to the #PBAR_DESC or NULL
 * @param initial_value	initial value 0-100
 * @param initial_ws	pointer to initial WSHDR string or NULL, don't need to free memory
 * @return GUI_ID
 * */
__swi_begin(0x3C2)
int ShowPBarBox(int flags, int message, PBAR_DESC *pbar_desc, int initial_value, WSHDR *initial_ws)
__swi_end(0x3C2, ShowPBarBox, (flags, message, pbar_desc, initial_value, initial_ws));

/**
 * Set value to progressbar popup
 * @param gui_id		progressbar GUI ID
 * @param value			value
 * @return 1: success, 0: error
 * */
__swi_begin(0x3C3)
int SetPBarValue(int gui_id, int value)
__swi_end(0x3C3, SetPBarValue, (gui_id, value));

/**
 * Set WSHDR string to progressbar popup
 * @param gui_id		progressbar GUI ID
 * @param ws			pointer to WSHDR string, don't need to free memory
 * @return 1: success, 0: error
 * */
__swi_begin(0x3C4)
int SetPBarText(int gui_id, WSHDR *ws)
__swi_end(0x3C4, SetPBarText, (gui_id, ws));

/**
 * Create custom Popup.
 * @param flags				see #PopupDialogFlags
 * @param user_pointer		custom user pointer
 * @param popup				pointer to the Popup definition
 * @param lgp_id			Popup message, LGP ID or pointer to the C-string
 * @return GUI ID
 * */
__swi_begin(0x2A9)
int CreatePopupGUI(int flags, void *user_pointer, const POPUP_DESC *popup, int lgp_id)
__swi_end(0x2A9, CreatePopupGUI, (flags, user_pointer, popup, lgp_id));

/**
 * Create custom Popup.
 * @param flags				see #PopupDialogFlags
 * @param user_pointer		custom user pointer
 * @param popup				pointer to the Popup definition
 * @param message			UTF-16 pascal-style string
 * @return GUI ID
 * */
__swi_begin(0x2AA)
int CreatePopupGUI_ws(int flags, void *user_pointer, const POPUP_DESC *popup, const WSHDR *message)
__swi_end(0x2AA, CreatePopupGUI_ws, (flags, user_pointer, popup, message));

/**
 * Get user pointer from the popup.
 * @param gui		pointer to the Popup GUI
 * @return pointer
 * */
__swi_begin(0x2AB)
void *GetPopupUserPointer(void *gui)
__swi_end(0x2AB, GetPopupUserPointer, (gui));

/** @} */

/**
 * @name InputDialog & EditControl
 * @{
 * */

/**
 * Create InputDialog GUI.
 * @param input_desc		definition of the InputDialog
 * @param header_desc		definition of the dialog header
 * @param eq				list of the edit controls
 * @param do_mfree			set to 1 if you want free `eq` data
 * @param user_pointer		custom user pointer
 * @return GUI ID
 * */
__swi_begin(0x167)
int CreateInputTextDialog(const INPUTDIA_DESC *input_desc, const HEADER_DESC *header_desc, EDITQ *eq, int do_mfree, void *user_pointer)
__swi_end(0x167, CreateInputTextDialog, (input_desc, header_desc, eq, do_mfree, user_pointer));

/**
 * Get user pointer from the InputDialog.
 * @param gui	pointer to the InputDialog GUI
 * @return pointer
 * */
__swi_begin(0x1DF)
void *EDIT_GetUserPointer(void *gui)
__swi_end(0x1DF, EDIT_GetUserPointer, (gui));

/**
 * Check if InputDialog is busy.
 * @param gui	pointer to the InputDialog GUI
 * @return 1: busy, 0: not busy
 * */
__swi_begin(0x21C)
int EDIT_IsBusy(void *gui)
__swi_end(0x21C, EDIT_IsBusy, (gui));

__swi_begin(0x1E5)
int EDIT_OpenOptionMenuWithUserItems(void *gui, void (*itemhandler)(USR_MENU_ITEM *item), void *user_pointer, int to_add)
__swi_end(0x1E5, EDIT_OpenOptionMenuWithUserItems, (gui, itemhandler, user_pointer, to_add));

/**
 * List of the edit controls.
 * @param malloc_func		result of #malloc_adr
 * @param mfree_func		result of #mfree_adr
 * @return allocated #EDITQ
 * */
__swi_begin(0x163)
EDITQ *AllocEQueue(const void *malloc_func, const void *mfree_func)
__swi_end(0x163, AllocEQueue, (malloc_func, mfree_func));

/**
 * Pre-initialize #EDITCONTROL structure.
 * @param ec	pointer to the #EDITCONTROL
 * @return bypass `ec`
 * 
 * Typical usage:
 * ```C
 * EDITQ eq = AllocEQueue(malloc_adr(), mfree_adr());
 * 
 * EDITCONTROL ec;
 * PrepareEditControl(&ec); // <--- initialize
 * 
 * // One control
 * ConstructEditControl(ec, ECT_NORMAL_TEXT, ECF_NORMAL_STR | ECF_APPEND_EOL, title, 32); // <-- construct
 * AddEditControlToEditQend(eq, ec, mallloc_adr()); // <-- copy to the list
 * 
 * // Second control
 * ConstructEditControl(ec, ECT_NORMAL_TEXT, ECF_NORMAL_STR | ECF_APPEND_EOL, title, 32); // <-- construct
 * AddEditControlToEditQend(eq, ec, mallloc_adr()); // <-- copy to the list
 * ```
 * */
__swi_begin(0x164)
EDITCONTROL *PrepareEditControl(EDITCONTROL *ec)
__swi_end(0x164, PrepareEditControl, (ec));

/**
 * Create new edit control.
 * @param ec		pointer to the #EDITCONTROL
 * @param type		edit control type, see #EditControlTypeID
 * @param flags		edit control flags, see #EditControlFlags
 * @param title		edit control title, can be `NULL`
 * @param maxlen	maximum length of the value
 * */
__swi_begin(0x165)
void ConstructEditControl(EDITCONTROL *ec, int type, int flags, const WSHDR *title, int maxlen)
__swi_end(0x165, ConstructEditControl, (ec, type, flags, title, maxlen));

/**
 * Create new edit control (ComboBox).
 * Items will be created dynamically in ghook. You need to specify only the number of items.
 * @param ec				pointer to the #EDITCONTROL
 * @param type				edit control type, see #EditControlTypeID
 * @param flags				edit control flags, see #EditControlFlags
 * @param title				edit control title, can be `NULL`
 * @param maxlen			maximum length of the value
 * @param unk_zero			set to 0
 * @param items_count		items count in the combo-box
 * @param selected_item		selected item index (from 1)
 * */
__swi_begin(0x184)
void ConstructComboBox(EDITCONTROL *ec, int type, int flags, WSHDR *title, int maxlen, int unk_zero, int items_count, int selected_item)
__swi_end(0x184, ConstructComboBox, (ec, type, flags, title, maxlen, unk_zero, items_count, selected_item));

/**
 * Create new edit control (Time).
 * Use in pair with #ConstructEditControl 
 * @param ec		pointer to the constructed edit control with type #ECT_TIME
 * @param time		default value
 * */
__swi_begin(0x20E)
int ConstructEditTime(EDITCONTROL *ec, const TTime *time)
__swi_end(0x20E, ConstructEditTime, (ec, time));

/**
 * Create new edit control (Date).
 * Use in pair with #ConstructEditControl 
 * @param ec		pointer to the constructed edit control with type #ECT_CALENDAR
 * @param date		default value
 * */
__swi_begin(0x20F)
int ConstructEditDate(EDITCONTROL *ec, const TDate *date)
__swi_end(0x20F, ConstructEditDate, (ec, date));

/**
 * Set options to the edit control.
 * @param ec			pointer to the initilaized #EDITCONTROL
 * @param options		pointer to the options
 * */
__swi_begin(0x1CE)
void CopyOptionsToEditControl(EDITCONTROL *ec, const EDITC_OPTIONS *options)
__swi_end(0x1CE, CopyOptionsToEditControl, (ec, options));

/**
 * Add edit control to the end of the list.
 * * @note This function copies #EDITCONTROL structure. You can safely for free or change it after a call.
 * @param eq			pointer to the list of the edit controls
 * @param ec			pointer to the initilaized #EDITCONTROL
 * @param malloc_func	result of #malloc_adr
 * @return 1: success, 0: error
 * */
__swi_begin(0x166)
int AddEditControlToEditQend(EDITQ *eq, const EDITCONTROL *ec, const void *malloc_func)
__swi_end(0x166, AddEditControlToEditQend, (eq, ec, malloc_func));

/**
 * Get index of the focused edit control.
 * @return index
 * */
__swi_begin(0x182)
int EDIT_GetFocus(void *gui)
__swi_end(0x182, EDIT_GetFocus, (gui));

/**
 * Get index of the previous focused edit control.
 * @return index
 * */
__swi_begin(0x183)
int EDIT_GetUnFocus(void *gui)
__swi_end(0x183, EDIT_GetUnFocus, (gui));

/**
 * Focus given edit control.
 * @param gui		pointer to the InputDialog GUI
 * @param n			index of the edit control to be focused
 * */
__swi_begin(0x19B)
void EDIT_SetFocus(void *gui, int n)
__swi_end(0x19B, EDIT_SetFocus, (gui, n));

/**
 * Remove edit control for the InputDialog.
 * @param gui		pointer to the InputDialog GUI
 * @param n			index of the edit control
 * */
__swi_begin(0x1D1)
void EDIT_RemoveEditControl(void *gui, int n)
__swi_end(0x1D1, EDIT_RemoveEditControl, (gui, n));

/**
 * Insert edit control to the InputDialog.
 * @note This function copies #EDITCONTROL structure. You can safely for free or change it after a call.
 * @param gui		pointer to the InputDialog GUI
 * @param n			index where will be inserted
 * @param ec		pointer to new #EDITCONTROL
 * */
__swi_begin(0x1D2)
void EDIT_InsertEditControl(void *gui, int n, const EDITCONTROL *ec)
__swi_end(0x1D2, EDIT_InsertEditControl, (gui, n, ec));

/**
 * Get a copy of the edit control in the InputDialog.
 * @param gui	pointer to the InputDialog GUI
 * @param n		index of control in the list
 * @param ec	pointer to #EDITCONTROL where there will be a stored copy of the extracted control
 * @return 1: success, 0: error
 * */
__swi_begin(0x169)
int ExtractEditControl(void *gui, int n, EDITCONTROL *ec)
__swi_end(0x169, ExtractEditControl, (gui, n, ec));

/**
 * Get a copy of the focused edit control in the InputDialog.
 * @param gui	pointer to the InputDialog GUI
 * @param ec	pointer to #EDITCONTROL where there will be a stored copy of the extracted control
 * */
__swi_begin(0x1C6)
void EDIT_ExtractFocusedControl(void *gui, EDITCONTROL *ec)
__swi_end(0x1C6, EDIT_ExtractFocusedControl, (gui, ec));

/**
 * Replace the edit control in the InputDialog.
 * @note This function copies #EDITCONTROL structure. You can safely for free or change it after a call.
 * @param gui	pointer to the InputDialog GUI
 * @param n		index of control in the list
 * @param ec	pointer to new #EDITCONTROL
 * @return 1: success, 0: error
 * */
__swi_begin(0x16A)
int StoreEditControl(void *gui, int n, const EDITCONTROL *ec)
__swi_end(0x16A, StoreEditControl, (gui, n, ec));

/**
 * Replace focused edit control in the InputDialog.
 * @note This function copies #EDITCONTROL structure. You can safely for free or change it after a call.
 * @param gui	pointer to the InputDialog GUI
 * @param ec	pointer to new #EDITCONTROL
 * @return 1: success, 0: error
 * */
__swi_begin(0x1C7)
int EDIT_StoreControlToFocused(void *gui, const EDITCONTROL *ec)
__swi_end(0x1C7, EDIT_StoreControlToFocused, (gui, ec));

/**
 * Set value to the focused edit control.
 * @param gui		pointer to the InputDialog GUI
 * @param value		new value
 * */
__swi_begin(0x181)
void EDIT_SetTextToFocused(void *gui, const WSHDR *value)
__swi_end(0x181, EDIT_SetTextToFocused, (gui, value));

/**
 * Set value to the given edit control.
 * @param gui		pointer to the InputDialog GUI
 * @param n			index of the edit control
 * @param value		new value
 * */
__swi_begin(0x1DE)
int EDIT_SetTextToEditControl(void *gui, int n, const WSHDR *value)
__swi_end(0x1DE, EDIT_SetTextToEditControl, (gui, n, value));

/**
 * Get item index in the focused ComboBox.
 * @param gui	pointer to the InputDialog GUI
 * @return item index, from 1
 * */
__swi_begin(0x180)
int EDIT_GetItemNumInFocusedComboBox(void *gui)
__swi_end(0x180, EDIT_GetItemNumInFocusedComboBox, (gui));

/**
 * Set date value to the edit control.
 * @param gui		pointer to the InputDialog GUI
 * @param n				index of the edit control
 * @param date		new value
 * */
__swi_begin(0x20A)
void EDIT_SetDate(void *gui, int n, const TDate *date)
__swi_end(0x20A, EDIT_SetDate, (gui, n, date));

/**
 * Set time value to the edit control.
 * @param gui		pointer to the InputDialog GUI
 * @param n				index of the edit control
 * @param time		new value
 * */
__swi_begin(0x20B)
void EDIT_SetTime(void *gui, int n, const TTime *time)
__swi_end(0x20B, EDIT_SetTime, (gui, n, time));

/**
 * Get date value from the edit control.
 * @param gui			pointer to the InputDialog GUI
 * @param n				index of the edit control
 * @param[out] date		date value
 * */
__swi_begin(0x20C)
void EDIT_GetDate(void *gui, int n, TDate *date)
__swi_end(0x20C, EDIT_GetDate, (gui, n, date));

/**
 * Get time value from the edit control.
 * @param gui			pointer to the InputDialog GUI
 * @param n				index of the edit control
 * @param[out] time		time value
 * */
__swi_begin(0x20D)
void EDIT_GetTime(void *gui, int n, TTime *time)
__swi_end(0x20D, EDIT_GetTime, (gui, n, time));

/**
 * Get cursor position in text.
 * Function working with current focused edit control.
 * @param gui			pointer to the InputDialog GUI
 * @return position
 * */
__swi_begin(0x1D3)
int EDIT_GetCursorPos(void *gui)
__swi_end(0x1D3, EDIT_GetCursorPos, (gui));

/**
 * Set cursor position in text.
 * Function working with current focused edit control.
 * @param gui			pointer to the InputDialog GUI
 * @param position		new cursor position
 * */
__swi_begin(0x1D4)
void EDIT_SetCursorPos(void *gui, int position)
__swi_end(0x1D4, EDIT_SetCursorPos, (gui, position));

/**
 * Check if text selection enabled.
 * Function working with current focused edit control.
 * @param gui			pointer to the InputDialog GUI
 * @return 1 or 0
 * */
__swi_begin(0x1D8)
int EDIT_IsMarkModeActive(void *gui)
__swi_end(0x1D8, EDIT_IsMarkModeActive, (gui));

/**
 * Get value of the selected text.
 * Function working with current focused edit control.
 * @param gui					pointer to the InputDialog GUI
 * @param[out] selected_text	value of the selected text
 * @return 1 or 0
 * */
__swi_begin(0x1D9)
int EDIT_GetMarkedText(void *gui, WSHDR *selected_text)
__swi_end(0x1D9, EDIT_GetMarkedText, (gui, selected_text));

/**
 * Invert background of the part of text.
 * Function working with current focused edit control.
 * @param gui			pointer to the InputDialog GUI
 * @param position		position in the text te be inverted
 * @param len			length of the text te be inverted
 * @return 1 or 0
 * */
__swi_begin(0x21A)
int EDIT_SetTextInvert(void *gui, int position, int len)
__swi_end(0x21A, EDIT_SetTextInvert, (gui, position, len));

/**
 * Remove text background ivertion.
 * Function working with current focused edit control.
 * @param gui			pointer to the InputDialog GUI
 * */
__swi_begin(0x21B)
void EDIT_RemoveTextInvert(void *gui)
__swi_end(0x21B, EDIT_RemoveTextInvert, (gui));

/** @} */

/**
 * @name EditControl options
 * @{
 * */

/**
 * Initialize #EDITC_OPTIONS structure.
 * @param options	pointer to the #EDITC_OPTIONS
 * @return bypass `options`
 * */
__swi_begin(0x1C8)
EDITC_OPTIONS *PrepareEditCOptions(EDITC_OPTIONS *options)
__swi_end(0x1C8, PrepareEditCOptions, (options));

/**
 * Enable background inversion.
 * @param options	pointer to the #EDITC_OPTIONS
 * @param invert	1 or 0
 * */
__swi_begin(0x1C9)
void SetInvertToEditCOptions(EDITC_OPTIONS *options, int invert)
__swi_end(0x1C9, SetInvertToEditCOptions, (options, invert));

/**
 * Change text font.
 * @param options	pointer to the #EDITC_OPTIONS
 * @param font		see #SystemFontID
 * */
__swi_begin(0x1CA)
void SetFontToEditCOptions(EDITC_OPTIONS *options, int font)
__swi_end(0x1CA, SetFontToEditCOptions, (options, font));

/**
 * Set text attributes.
 * @param options	pointer to the #EDITC_OPTIONS
 * @param flags		see #TextAttributesFlags
 * */
__swi_begin(0x1CB)
void SetTextAttrToEditCOptions(EDITC_OPTIONS *options, int flags)
__swi_end(0x1CB, SetTextAttrToEditCOptions, (options, flags));

/**
 * @copydoc SetTextAttrToEditCOptions
 * @deprecated Function with wrong name, use instead #SetTextAttrToEditCOptions
 * */
__swi_begin(0x1CB)
void SetAlignToEditCOptions(EDITC_OPTIONS *options, int flags)
__swi_end(0x1CB, SetAlignToEditCOptions, (options, flags));

/**
 * Set text color.
 * @param options	pointer to the #EDITC_OPTIONS
 * @param pen		color index, see #ThemePeletteColorID
 * */
__swi_begin(0x1CC)
void SetPenColorToEditCOptions(EDITC_OPTIONS *options, int pen)
__swi_end(0x1CC, SetPenColorToEditCOptions, (options, pen));

/**
 * Set background color.
 * @param options	pointer to the #EDITC_OPTIONS
 * @param brush		color index, see #ThemePeletteColorID
 * */
__swi_begin(0x1CD)
void SetBrushColorToEditCOptions(EDITC_OPTIONS *options, int brush)
__swi_end(0x1CD, SetBrushColorToEditCOptions, (options, brush));

/** @} */


/**
 * @name Menu
 * @{
 * */

/**
 * Create menu (list with items).
 * @param style				size of the menu (1: small, 0: big)
 * @param zero				set to 0
 * @param menu				pointer to the menu definition
 * @param header			pointer to the header definition
 * @param selected_item		index of the selected item in menu (from 0)
 * @param items_count		total count of the items
 * @param user_pointer		custom user pointer
 * @param to_remove			C-array with indexes to be removed from the menu (first array item is items count)
 * @return GUI ID
 * */
__swi_begin(0x152)
int CreateMenu(int style, int zero, const MENU_DESC *menu, const HEADER_DESC *header, int selected_item, int items_count, void *user_pointer, int *to_remove)
__swi_end(0x152, CreateMenu, (style, zero, menu, header, selected_item, items_count, user_pointer, to_remove));
/**
 * Create menu with multiline items (list with items).
 * @param style				size of the menu (1: small, 0: big)
 * @param zero				set to 0
 * @param menu				pointer to the menu definition
 * @param header			pointer to the header definition
 * @param selected_item		index of the selected item in menu (from 0)
 * @param items_count		total count of the items
 * @return GUI ID
 * */
__swi_begin(0x217)
int CreateMultiLinesMenu(int style, int zero, const ML_MENU_DESC *menu, const HEADER_DESC *header, int selected_item, int items_count)
__swi_end(0x217, CreateMultiLinesMenu, (style, zero, menu, header, selected_item, items_count));

/**
 * Get index of the selected item in menu.
 * @param gui	pointer to the Menu GUI
 * @return index
 * */
__swi_begin(0x18F)
int GetCurMenuItem(void *gui)
__swi_end(0x18F, GetCurMenuItem, (gui));

/**
 * Add icon to the list item.
 * @param gui		pointer to the Menu GUI
 * @param item_n	index of the item (from 0)
 * @param icon		ID from PIT or string with path
 * */
__swi_begin(0x195)
void SetMenuItemIcon(void *gui, int item_n, int icon)
__swi_end(0x195, SetMenuItemIcon, (gui, item_n, icon));

/**
 * Add icon to the list item (IMGHDR).
 * @param gui		pointer to the Menu GUI
 * @param item		pointer to the menu item
 * @param icon		pointer to IMGHDR
 * */
__swi_begin(0x3A3)
void SetMenuItemIconIMGHDR(void *gui, void *item, IMGHDR *icon)
__swi_end(0x3A3, SetMenuItemIconIMGHDR, (gui, item, icon));

/**
 * Dynamic allocation of the menu item. Used for menus with dynamic items.
 * @note Only for single-line menu (#CreateMenu).
 * @param gui		pointer to the Menu GUI
 * @return new allocated menu item
 * */
__swi_begin(0x197)
void *AllocMenuItem(void *gui)
__swi_end(0x197, AllocMenuItem, (gui));

/**
 * Dynamic allocation of the menu item. Used for menus with dynamic items.
 * @note Only for multi-line menu (#CreateMultiLinesMenu).
 * @param gui		pointer to the Menu GUI
 * @return new allocated menu item
 * */
__swi_begin(0x219)
void *AllocMLMenuItem(void *gui)
__swi_end(0x219, AllocMLMenuItem, (gui));

/**
 * Allocate #WSHDR for using it in #SetMenuItemText
 * @param gui		pointer to the Menu GUI
 * @param len		maximum length of the WSHDR
 * @return new allocated #WSHDR
 * */
__swi_begin(0x198)
WSHDR *AllocMenuWS(void *gui, int len)
__swi_end(0x198, AllocMenuWS, (gui, len));

/**
 * Set icon to menu item.
 * @param gui		pointer to the Menu GUI
 * @param item		pointer to the menu item
 * @param icons		C-array of the icons (ID from PIT or pointer to IMGHDR), last item is always 0
 * */
__swi_begin(0x199)
void SetMenuItemIconArray(void *gui, void *item, const int *icons)
__swi_end(0x199, SetMenuItemIconArray, (gui, item, icons));

/**
 * Set text to menu item.
 * @param gui		pointer to the Menu GUI
 * @param item		pointer to the menu item
 * @param text		#WSHDR string allocated with #AllocMenuWS
 * @param item_n	index of the `item`
 * @note Only for single-line menu (#CreateMenu).
 * */
__swi_begin(0x19A)
void SetMenuItemText(void *gui, void *item, WSHDR *text, int item_n)
__swi_end(0x19A, SetMenuItemText, (gui, item, text, item_n));

/**
 * Set text to menu item.
 * @param gui		pointer to the Menu GUI
 * @param item		pointer to the menu item
 * @param text1		#WSHDR string allocated with #AllocMenuWS
 * @param text2		#WSHDR string allocated with #AllocMenuWS
 * @param item_n	index of the `item`
 * @note Only for multi-line menu (#CreateMultiLinesMenu).
 * */
__swi_begin(0x218)
void SetMLMenuItemText(void *gui, void *item, WSHDR *text1, WSHDR *text2, int item_n)
__swi_end(0x218, SetMLMenuItemText, (gui, item, text1, text2, item_n));

/**
 * Get count of items on the menu.
 * @param gui			pointer to the Menu GUI
 * @return count
 * */
__swi_begin(0x2A8)
int GetMenuItemCount(void *gui)
__swi_end(0x2A8, GetMenuItemCount, (gui));

/**
 * Statically set items count in the menu.
 * @note Use this function only when you create a menu from scratch instead of #CreateMenu
 * @param gui			pointer to the Menu GUI
 * @param items_count	total count of the items
 * */
__swi_begin(0x1C3)
void SetMenuItemCount(void *gui, int items_count)
__swi_end(0x1C3, SetMenuItemCount, (gui, items_count));

/**
 * Dynamically set items count on the menu. You can use this function even for already created menus.
 * @param gui			pointer to the Menu GUI
 * @param items_count	total count of the items
 * */
__swi_begin(0x1E6)
void Menu_SetItemCountDyn(void *gui, int items_count)
__swi_end(0x1E6, Menu_SetItemCountDyn, (gui, items_count));

/**
 * Scroll to the given menu item.
 * @param gui		pointer to the Menu GUI
 * @param item_n	index of the item (from 0)
 * */
__swi_begin(0x1C4)
void SetCursorToMenuItem(void *gui, int item_n)
__swi_end(0x1C4, SetCursorToMenuItem, (gui, item_n));

/**
 * @copydoc SetCursorToMenuItem
 * @deprecated Use #SetCursorToMenuItem instead.
 * */
__swi_begin(0x2A3)
void UpdateMenuCursorItem(void *gui, int item_n)
__swi_end(0x2A3, UpdateMenuCursorItem, (gui, item_n));

/**
 * Set callback for the searching in the menu.
 * @param gui			pointer to the Menu GUI
 * @param callback		search callback
 * */
__swi_begin(0x24B)
void SetMenuSearchCallBack(void *gui, const MenuSearchCallBack callback)
__swi_end(0x24B, SetMenuSearchCallBack, (gui, callback));

/**
 * Add softkey to the menu.
 * @param gui			pointer to the Menu GUI
 * @param softkey		pointer to the softkey definition
 * @param softkey_id	see #SetSoftKeyID
 * @deprecated Use #SetSoftKey instead.
 * */
__swi_begin(0x2B0)
void SetMenuSoftKey(void *gui, const SOFTKEY_DESC *softkey, int softkey_id)
__swi_end(0x2B0, SetMenuSoftKey, (gui, softkey, softkey_id));

/**
 * Set header to the menu.
 * @param gui			pointer to the Menu GUI
 * @param header		pointer to the header definition
 * @param malloc_fn		pointer to the malloc() function, use result of #malloc_adr
 * */
__swi_begin(0x2A6)
void SetHeaderToMenu(void *gui, const HEADER_DESC *header, const void *malloc_fn)
__swi_end(0x2A6, SetHeaderToMenu, (gui, header, malloc_fn));

/**
 * Get custom user pointer from menu.
 * @param gui			pointer to the Menu GUI
 * @return pointer
 * */
__swi_begin(0x1E0)
void *MenuGetUserPointer(void *gui)
__swi_end(0x1E0, MenuGetUserPointer, (gui));

/**
 * Set custom user pointer to the menu.
 * @param gui			pointer to the Menu GUI
 * @param user_pointer	custom user pointer
 * */
__swi_begin(0x255)
void MenuSetUserPointer(void *gui, void *user_pointer)
__swi_end(0x255, MenuSetUserPointer, (gui, user_pointer));

/**
 * Allocate GUI for single-line menu.
 * @note Low-level function, use #CreateMenu instead.
 * @param malloc_fn		result of #malloc_adr
 * @param mfree_fn		result of #mfree_adr
 * @return new allocated GUI
 * */
__swi_begin(0x2A4)
void *GetMenuGUI(const void *malloc_fn, const void *mfree_fn)
__swi_end(0x2A4, GetMenuGUI, (malloc_fn, mfree_fn));

/**
 * Allocate GUI for multi-line menu.
 * @note Low-level function, use #CreateMenu instead.
 * @param malloc_fn		result of #malloc_adr
 * @param mfree_fn		result of #mfree_adr
 * @return new allocated GUI
 * */
__swi_begin(0x2A5)
void *GetMultiLinesMenuGUI(const void *malloc_fn, const void *mfree_fn)
__swi_end(0x2A5, GetMultiLinesMenuGUI, (malloc_fn, mfree_fn));

/**
 * Attach the menu definition to the allocated GUI (by #GetMenuGUI or #GetMultiLinesMenuGUI).
 * @param gui			pointer to the Menu GUI
 * @param menu			pointer to the #MENU_DESC or #ML_MENU_DESC
 * @note Low-level function, use #CreateMenu instead.
 * */
__swi_begin(0x2A7)
void SetMenuToGUI(void *gui, const void *menu)
__swi_end(0x2A7, SetMenuToGUI, (gui, menu));

/** @} */

/**
 * @name Tabs
 * @{
 * */

/**
 * Allocate GUI for tabs.
 * @param malloc_fn		result of #malloc_adr
 * @param mfree_fn		result of #mfree_adr
 * @return new allocated GUI
 * */
__swi_begin(0x2BB)
void *GetTabGUI(void *malloc_fn, void *mfree_fn)
__swi_end(0x2BB, GetTabGUI, (malloc_fn, mfree_fn));

/**
 * Link content gui with tab.
 * @param gui			pointer to the Tabs GUI
 * @param tab_n			index of the tab
 * @param icons			C-array of the tab icons (ID from PIT or pointer to IMGHDR), last item is always 0
 * @param content_gui	pointer to the GUI for the tab content
 * @return 1: success, 0: error
 * */
__swi_begin(0x2BD)
int SetGUIToTabGUI(void *gui, int tab_n, const int *icons, void *content_gui)
__swi_end(0x2BD, SetGUIToTabGUI, (gui, tab_n, icons, content_gui));

/**
 * Get GUI of the tab content.
 * @param gui			pointer to the Tabs GUI
 * @param tab_n			index of the tab
 * @return pointer to the GUI for the tab content
 * */
__swi_begin(0x2C1)
void *GetGuiByTab(void *gui, int tab_n)
__swi_end(0x2C1, GetGuiByTab, (gui, tab_n));

/**
 * Switch to the given tab.
 * @param gui		pointer to the Tabs GUI
 * @param tab_n		index of the tab
 * @return 1: success, 0: error
 * */
__swi_begin(0x2BE)
int SetCursorTab(void *gui, int tab_n)
__swi_end(0x2BE, SetCursorTab, (gui, tab_n));

/**
 * Get index of the active tab
 * @param gui		pointer to the Tabs GUI
 * @return index
 * */
__swi_begin(0x2C0)
int GetCursorTab(void *gui)
__swi_end(0x2C0, GetCursorTab, (gui));

/**
 * Update content of the active tab.
 * @param gui		pointer to the Tabs GUI
 * @param unk_0		set to 0
 * @return 1: success, 0: error
 * */
__swi_begin(0x2BF)
int UpdateTab1stItem(void *gui, int unk_0)
__swi_end(0x2BF, UpdateTab1stItem, (gui, unk_0));

/** @} */

/**
 * @name TextView
 * @{
 * */

/**
 * Allocate GUI for TextView.
 * @param malloc_fn		result of #malloc_adr
 * @param mfree_fn		result of #mfree_adr
 * @return new allocated GUI
 * */
__swi_begin(0x2D6)
void *TViewGetGUI(const void *malloc_fn, const void *mfree_fn)
__swi_end(0x2D6, TViewGetGUI, (malloc_fn, mfree_fn));

/**
 * Attach the TextView definition to the allocated GUI.
 * @param gui			pointer to the TextVIew GUI
 * @param tv			pointer to the #TVIEW_DESC
 * */
__swi_begin(0x2D7)
void TViewSetDefinition(void *gui, const TVIEW_DESC *tv)
__swi_end(0x2D7, TViewSetDefinition, (gui, tv));

/**
 * Set text to the TextView.
 * @param gui			pointer to the TextVIew GUI
 * @param text			text content
 * @param malloc_fn		result of #malloc_adr
 * @param mfree_fn		result of #mfree_adr
 * */
__swi_begin(0x2D8)
void TViewSetText(void *gui, const WSHDR *text, const void *malloc_fn, const void *mfree_fn)
__swi_end(0x2D8, TViewSetText, (gui, text, malloc_fn, mfree_fn));

/**
 * Set custom user pointer to the TextView.
 * @param gui			pointer to the TextView GUI
 * @param user_pointer	custom user pointer
 * */
__swi_begin(0x2D9)
void TViewSetUserPointer(void *gui, void *user_pointer)
__swi_end(0x2D9, TViewSetUserPointer, (gui, user_pointer));

/**
 * Get custom user pointer from TextView.
 * @param gui			pointer to the TextView GUI
 * @return pointer
 * */
__swi_begin(0x2DA)
void *TViewGetUserPointer(void *gui)
__swi_end(0x2DA, TViewGetUserPointer, (gui));

/** @} */

/**
 * @name RadioButtonList
 * @{
 * */

/**
 * Create radios button list.
 * @param desc				gui description
 * @param num				number of the items
 * @param unk_zero0			unknown, set to 0
 * @param unk_zero1			unknown, set to 0
 * @param selected_item		selected item index
 * @param handler			item handler
 * @param flags				unknown flags
 * @return GUI ID
 * */
__swi_begin(0x22B)
int CreateRadioButtonList(void *desc, int num, int unk_zero0, int unk_zero1, char selected_item, void (*handler)(int), int flags)
__swi_end(0x22B, CreateRadioButtonList, (desc, num, unk_zero0, unk_zero1, selected_item, handler, flags));

/** @} */

/**
 * @name Hacks
 * @{
 * */

/**
 * Pointer to the currently opened menu.
 * @return pointer
 * */
__swi_begin(0x80D8)
void *RamMenuAnywhere()
__swi_end(0x80D8, RamMenuAnywhere, ());

/** @} */

__swilib_end

/** @} */
