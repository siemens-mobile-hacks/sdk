#pragma once

/**
 * @addtogroup Explorer
 * @brief Functions for the files explorer.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/explorer.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#include "wstring.h"
#endif

__swilib_begin

typedef enum ExplorerTransferStates ExplorerTransferStates;

typedef struct NativeExplorerData NativeExplorerData;
typedef struct REGEXPLEXT REGEXPLEXT;
typedef struct REGEXPLEXT_ARM_NEW REGEXPLEXT_ARM_NEW;

#ifdef NEWSGOLD
typedef struct REGEXPLEXT TREGEXPLEXT;
#else
typedef struct REGEXPLEXT_ARM_NEW TREGEXPLEXT;
#endif

enum ExplorerTransferStates {
	EXPLORER_TRANSFER_STATE_STOP		= 1,
	EXPLORER_TRANSFER_STATE_RUNNING		= 2,
};

/**
 * Mode of the NativeExplorer.
 * */
enum NativeExplorerMode {
	NATIVE_EXPLORER_MODE_DEFAULT,	/**< Explore files, default mode */
	NATIVE_EXPLORER_MODE_SELECT,	/**< Select file */
};

/**
 * NativeExplorer options.
 * */
struct NativeExplorerData {
	int mode;				/**< See #NativeExplorerMode */
	int dir_enum;			/**< Usually 0x26 */
	WSHDR *path_to_file;	/**< Full path to the dir or file */
	WSHDR *file_name;		/**< Scroll to the file/dir, if non-empty (Only filename) */
	int unk5;
	int is_exact_dir;		/**< Set to 1 */
	int unk7;
	int unk8;
	int unk9;
	int unk10;
	int unk11;
	WSHDR *full_filename;	/**< Full path to the dir or file */
	int unk13;
	int (*user_handler)(void *);			/**< Callback for mode=NATIVE_EXPLORER_MODE_SELECT */
	NativeExplorerData *this_struct_addr;	/**< Self-reference to this structure */
	int unk16;
	int unk17_26[10];
};

/**
 * Extension registration structure.
 * */
struct REGEXPLEXT {
#ifdef NEWSGOLD
	const char *ext;		/**< Name of the extension, example: "elf" */
	int unical_id;			/**< Uniq ID of the extension */
	char enabled_options;	/**< Enabled options, set to 0xFF */
	char obex_path_id;		/**< Path for saving files through the OBEX (set to 8 - 0:\\Misc) */
	short menu_flag;		/**< Set to #MENU_FLAG2 */
	const int *icon1;		/**< Pointer to the SMALL icons (16x16) */
	const int *icon2;		/**< Pointer to the BIG icons (32x32) */
	int Open_lgpid;			/**< Name of the "Open" item in the file menu (LGP_ID or C-string) */
	int Options_lgpid;		/**< Name of the "Options" item in the file menu (LGP_ID or C-string) */
	int Enter_lgpid;		/**< Icon for the center softkey, set to #LGP_DOIT_PIC */
	void *proc;				/**< Callback for the "Open" */
	void *altproc;			/**< Callback for the "Options" */
#else
	const char *ext;		/**< Name of the extension, example: "elf" */
	int unical_id;			/**< Uniq ID of the extension */
	char enabled_options;	/**< Enabled options, set to 0xFF */
	uint8_t obex_path_id;	/**< Path for saving files through the OBEX (set to 7 - 0:\\Misc) */
	uint16_t menu_flag;		/**< Set to #MENU_FLAG2 */
	const int *icon1;		/**< Pointer to the SMALL icons (16x16) */
	const int *icon2;		/**< Pointer to the BIG icons (32x32) */
	void *proc;				/**< Callback for the "Open" */
	void *altproc;			/**< Callback for the "Options" */
#endif
};

/**
 * Structure of the registered extension in RAM (on SGOLD).
 * Returend by #get_regextpnt_by_uid
 * */
struct REGEXPLEXT_ARM_NEW {
	int zero;
	const uint32_t *icon1;		/**< Pointer to the SMALL icons (16x16) */
	int unical_id;				/**< Uniq ID of the extension */
	char obex_path_id;			/**< Path for saving files through the OBEX */
	char unk;
	uint16_t menu_flag;			/**< Menu flags */
	char enabled_options;		/**< Options flags */
	char not_used[3];
	WSHDR *ext;					/**< Name of the extension in UTF-16 */
	void *proc;					/**< Callback for the "Open" */
	void *altproc;				/**< Callback for the "Options" */
	const uint32_t *icon2;		/**< Pointer to the BIG icons (32x32) */
};

/**
 * Register own extension in the NativeExplorer.
 * @param ext	extension definition structure, see #REGEXPLEXT
 * */
__swi_begin(0x08C)
void RegExplorerExt(const REGEXPLEXT *ext)
__swi_end(0x08C, RegExplorerExt, (ext));

/**
 * Unregister extension from the NativeExplorer.
 * @param ext	extension definition structure, see #REGEXPLEXT
 * @return number of registered extensions
 * @builtin X75, SG
 * */
__swi_begin(0x095)
int UnRegExplorerExt(const REGEXPLEXT *ext)
__swi_end(0x095, UnRegExplorerExt, (ext));

/**
 * Get a pointer to the explorer extensions.
 * @return pointer
 * @builtin ELKA, NSG, X75, SG
 * */
__swi_begin(0x81B8)
TREGEXPLEXT *EXT_TOP(void)
__swi_end(0x81B8, EXT_TOP, ());

/**
 * Get explorer extension definition by ID.
 * @param uid		ID of the registered extension.
 * @return pointer to the extension definition
 * */
__swi_begin(0x1CF)
TREGEXPLEXT *get_regextpnt_by_uid(int uid)
__swi_end(0x1CF, get_regextpnt_by_uid, (uid));

/**
 * Get the ID of the registered extension by its name.
 * @param ext		name of the extension, for example: png
 * @return ID of the extension
 * */
__swi_begin(0x1D0)
int GetExtUid_ws(const WSHDR *ext)
__swi_end(0x1D0, GetExtUid_ws, (ext));

/**
 * Get the ID of the registered extension by path to the file.
 * @param file		path to the file
 * @return ID of the extension
 * */
__swi_begin(0x2E1)
int GetExtUidByFileName_ws(const WSHDR *file)
__swi_end(0x2E1, GetExtUidByFileName_ws, (file));

/**
 * Open menu for sending file.
 * @param file	name of the file, example: "beans_recipe.jpg"
 * @param path	path to the file, example: "0:\\Pictures\\"
 * */
__swi_begin(0x2DB)
void MediaSendCSM_Open(const WSHDR *file, const WSHDR *path)
__swi_end(0x2DB, MediaSendCSM_Open, (file, path));

/**
 * Open menu for setting resource as Wallpaper, Logo, Ringtone, etc..
 * @param file_name	name of the file, example "beans_recipe.jpg"
 * @param dir		directory of the file, example "0:\\Pictures"
 * @param flag		0 or 2
 * @param open_mode	unknown param, set 0
 * @return CSM ID
 * */
__swi_begin(0x3CC)
int PersMenuCSM_Open(const WSHDR *file_name, const WSHDR *dir, int flag, int open_mode)
__swi_end(0x3CC, PersMenuCSM_Open, (file_name, dir, flag, open_mode));

/**
 * Open NativeExplorer.
 * @param data		options for the opening explorer
 * @return CSM ID
 * */
__swi_begin(0x254)
int StartNativeExplorer(NativeExplorerData *data)
__swi_end(0x254, StartNativeExplorer, (data));

/**
 * Open NativeExplorer.
 * @param data		options for the opening explorer
 * @return CSM ID
 * */
__swi_begin(0x22E)
int OpenExplorer(NativeExplorerData *data)
__swi_end(0x22E, OpenExplorer, (data));

/**
 * Get current item in open Explorer.
 * @param csm	pointer to the Explorer CSM
 * @return index of the current item
 * */
__swi_begin(0x212)
int CardExplGetCurItem(void *csm)
__swi_end(0x212, CardExplGetCurItem, (csm));

/**
 * Get filename of the item in the open Explorer.
 * @param csm				pointer to the Explorer CSM
 * @param index				index of the item
 * @param[out] filename		item filename
 * */
__swi_begin(0x213)
void CardExplGetFName(void *csm, int index, WSHDR *filename)
__swi_end(0x213, CardExplGetFName, (csm, index, filename));

/**
 * Execute file by the NativeExplorer.
 * @param filepath		path to the file
 * @param mime			mime type of the file
 * @param param			custom param for the extension handler
 * @return return code from the extension handler
 * */
__swi_begin(0x094)
int ExecuteFile(const WSHDR *filepath, const WSHDR *mime, void *param)
__swi_end(0x094, ExecuteFile, (filepath, mime, param));

/**
 * Copy file.
 * @param from			source file path
 * @param to			destination file path
 * @param overwrite		allow overwrite if exists
 * @param transfer_id	transfer ID (0 ... 31)
 * @param[out] errp		variable for error
 * @return 0 or error
 * 
 * ```
 * int transfer_id = 0; // warning: needed function for safe transfer_id allocation
 * ExplorerSetTransferState(transfer_id, EXPLORER_TRANSFER_STATE_RUNNING);
 * ExplorerCopyFile(from, to, 1, transfer_id, &err);
 * ```
 * */
__swi_begin(0x1F0)
int ExplorerCopyFile(const WSHDR *from, const WSHDR *to, int overwrite, char transfer_id, uint32_t *errp)
__swi_end(0x1F0, ExplorerCopyFile, (from, to, overwrite, transfer_id, errp));

/**
 * Set transfer state.
 * @param transfer_id	transfer ID (0 ... 31)
 * @param state			see #ExplorerTransferStates
 * @return 0 or error
 * */
__swi_begin(0x1F1)
int ExplorerSetTransferState(char transfer_id, int state)
__swi_end(0x1F1, ExplorerSetTransferState, (transfer_id, state));

/**
 * Get MIME type
 * @param uid				file uid, see #GetExtUid_ws, #GetExtUidByFileName_ws
 * @param[out] mime_type	pointer to WSHDR string
 * @param unk_0				unknown param, set to 0
 * @return 1: success, 0: error
 * */
__swi_begin(0x3C8)
int GetMimeType(int uid, WSHDR *mime_type, int unk_0)
__swi_end(0x3C8, GetMimeType, (uid, mime_type, unk_0));

__swilib_end

/** @} */
