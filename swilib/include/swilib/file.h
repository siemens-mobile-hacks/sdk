#pragma once

/**
 * @addtogroup File
 * @brief Functions for working with filesystem.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/file.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#include "wstring.h"
#endif

__swilib_begin

typedef struct DIR_ENTRY DIR_ENTRY;
typedef struct FSTATS FSTATS;
typedef struct FILE_PROP FILE_PROP;
typedef struct TWavLen TWavLen;

/**
 * Attributes for a file or directory.
 * */
enum FileAttributes {
	FA_READONLY		= 0x0001, /*!< File is read-only */
	FA_HIDDEN		= 0x0002, /*!< File is hidden */
	FA_SYSTEM		= 0x0004, /*!< Unused */
	FA_DIRECTORY	= 0x0010, /*!< This is folder */
	FA_ARCHIVE		= 0x0020, /*!< Unused */
};

/**
 * Modes for seek()
 * */
enum FileSeekOrigin {
	S_SET	= 0, /*!< cur_offset = offset */
	S_CUR	= 1, /*!< cur_offset = cur_offset + offset */
	S_END	= 2, /*!< cur_offset = file_size - 1 */
};

/**
 * Request permissions for file operations.
 * */
enum FilePermissionMode {
	P_WRITE	= 0x100, /*!< Permission for writing */
	P_READ	= 0x080, /*!< Permission for reading */
};

/**
 * Directory entry.
 * */
#pragma pack(1)
struct DIR_ENTRY {
#ifdef NEWSGOLD
	char unk0[40];
	uint32_t file_size;				/*!< Size in bytes */
	short file_attr;				/*!< File attributes: #FileAttributes */
	uint32_t create_date_time;		/*!< File creation time in unix-time */
	char unk1[2];
	char folder_name[128];			/*!< Name of the parent dir */
	char unk2;
	char file_name[128];			/*!< Name of the file */
	char unk3[11];
	short wsfolder_name[128 + 1];	/*!< Name of the parent dir в UTF-16 */
	short wsfile_name[128 + 1];		/*!< Name of the file в UTF-16 */
#else
	char unk0[14];
	short file_attr;				/*!< File attributes#FileAttributes */
	uint32_t create_date_time;		/*!< File creation time in unix-time */
	uint32_t file_size;				/*!< Size in bytes */
	char unk1[16];
	char folder_name[128];			/*!< Name of the parent dir */
	char unk2;
	char file_name[271];			/*!< Name of the file */
#endif
};
#pragma pack()

/**
 * Information about a file or directory.
 * */
struct FSTATS {
	char unk1;
	char unk2;
	char unk3;
	char unk4;
	uint32_t size;	/*!< Size in bytes */
	char unk5[28];
	int file_attr;	/*!< File attribute: #FileAttributes */
	int unk;
};

enum FilePropTypeID {
#ifdef NEWSGOLD
	FILE_PROP_TYPE_GENERAL		= 0x0400,	/**< General info, only size */
	FILE_PROP_TYPE_VIDEO		= 0xA800,	/**< Video info */
	FILE_PROP_TYPE_PICTURE		= 0x4000,	/**< Picture info */
	FILE_PROP_TYPE_AUDIO		= 0x1000,	/**< .wav/.mid info */
	FILE_PROP_TYPE_MUSIC		= 0x1800,	/**< .mp3/.aac info */
#else
	FILE_PROP_TYPE_VIDEO		= 0x4000,	/**< Video info */
	FILE_PROP_TYPE_PICTURE		= 0x8000,	/**< Picture info */
	FILE_PROP_TYPE_AUDIO		= 0x2000,	/**< Audio info */
#endif
};

/**
 * Extended file properties.
 * @warning All WSHDR-fields must be allocated before calling #GetFileProp
 * */
struct FILE_PROP {
#ifdef NEWSGOLD
	uint32_t type; 					/**< IN:  info type, see #FilePropTypeID */
	WSHDR *filename;				/**< IN:  full path to the file */
	WSHDR *resolution_ws;			/**< OUT: Picture resolution in the human-readable format */
	int uid;						/**< IN:  ID of the extension, see: #GetExtUidByFileName_ws */
	uint16_t width;					/**< OUT: Picture resolution: width */
	uint16_t height;				/**< OUT: Picture resolution: height */
	WSHDR *duration_mp3_ws;			/**< OUT: Music duration in the human-readable format */
	uint32_t duration_mp3;			/**< OUT: Music duration in clocks (1 clock = 4.615 ms) */
	WSHDR *duration_wav_ws;			/**< OUT: Audio duration in the human-readable format */
	uint32_t duration_wav;			/**< OUT: Audio duration in clocks (1 clock = 4.615 ms) */
	WSHDR *tag_title_ws;			/**< OUT: Audio IDv3 tag: title */
	WSHDR *tag_artist_ws;			/**< OUT: Audio IDv3 tag: artist */
	WSHDR *tag_album_ws;			/**< OUT: Audio IDv3 tag: album */
	WSHDR *tag_track_ws;			/**< OUT: Audio IDv3 tag: track */
	WSHDR *tag_year_ws;				/**< OUT: Audio IDv3 tag: album year */
	WSHDR *unk_tag_2_ws;			/**< OUT: Audio IDv3 tag: ??? */
	WSHDR *bitrate_ws;				/**< OUT: Audio bitrate */
	WSHDR *audio_frequency_ws;		/**< OUT: Audio discretisation frequency */
	WSHDR *size_ws;					/**< OUT: File weight in the human-readable format */
#else
	uint16_t type;					/**< IN:  info type, see #FilePropTypeID */
	WSHDR *filename;				/**< IN:  full path to the file */
	WSHDR *resolution_ws;			/**< OUT: Picture resolution in the human-readable format */
	int uid;						/**< IN:  ID of the extension, see: #GetExtUidByFileName_ws */
	uint16_t width;					/**< OUT: Picture resolution: width */
	uint16_t height;				/**< OUT: Picture resolution: height */
	WSHDR *duration_wav_ws;			/**< OUT: Audio duration in the human-readable format */
	uint32_t duration_wav;			/**< OUT: Audio duration in clocks (1 clock = 4.615 ms) */
	WSHDR *video_ws;				/**< OUT: Video duration in the human-readable format */
	int video_len;					/**< OUT: Video duration in clocks (1 clock = 4.615 ms) */
#endif
};

/**
 * File access mode.
 * */
enum FileAccessMode {
	A_ReadOnly				= 0x0000, /*!< Read-only */
	A_WriteOnly				= 0x0001, /*!< Write-only */
	A_ReadWrite				= 0x0002, /*!< Read + Write */
	A_NoShare				= 0x0004, /*!< Unknown */
	A_Append				= 0x0008, /*!< Each write() appends data to the end of the file (atomic) */
	A_Exclusive				= 0x0010, /*!< Unknown */
	A_MMCStream				= 0x0020, /*!< Allow access to MMC (SGold) */
	A_Create				= 0x0100, /*!< Create a file, if it does not exist. */
	A_Truncate				= 0x0200, /*!< Truncate the file to 0 bytes. */
	A_FailCreateOnExist		= 0x0400, /*!< Return an error if the file was not created by this open() call */
	A_FailOnReopen			= 0x0800, /*!< Unknown */
	A_TXT					= 0x4000, /*!< Mode for text files */
	A_BIN					= 0x8000, /*!< Mode for binary files */
};

/**
 * .wav duration info.
 * */
struct TWavLen {
	unsigned short type;
	WSHDR *wfilename;	/**< IN: Path ot the .wav file */
	int unk_08;
	int unk_0C;
	int unk_10;
	int unk_14;
	long length;		/**< OUT: .wav duration in clocks (1 clock - 4.615 ms) */
	int unk_1C;
	int unk_20;
};

/**
 * Open the file.
 * @param path			path to the file
 * @param mode			bitmask from #FileAccessMode
 * @param permission	bitmask from #FilePermissionMode
 * @param err			error code
 * @return file descriptor or error (< 0)
 * */
__swi_begin(0x00A)
int sys_open(const char *path, uint32_t mode, uint32_t permission, uint32_t *err)
__swi_end(0x00A, sys_open, (path, mode, permission, err));

/**
 * Read data from a file.
 * @param fd			file descriptor
 * @param buffer		pointer to a buffer for the read data
 * @param length		maximum size for read
 * @param[out] err		error code
 * @return count of read bytes or error (< 0)
 * @builtin X75, SG
 * */
__swi_begin(0x00B)
int sys_read(int fd, void *buffer, int length, uint32_t *err)
__swi_end(0x00B, sys_read, (fd, buffer, length, err));

/**
 * Write data to a file.
 * @param fd			file descriptor
 * @param buffer		pointer to a buffer with data to be written
 * @param length		maximum size for write
 * @param[out] err		error code
 * @return count of written bytes or error (< 0)
 * @builtin X75, SG
 * */
__swi_begin(0x00C)
int sys_write(int fd, const void *buffer, int length, uint32_t *err)
__swi_end(0x00C, sys_write, (fd, buffer, length, err));

/**
 * Close file descriptor.
 * @param fd		file descriptor
 * @param[out] err	error code
 * @return 0 or error
 * */
__swi_begin(0x00D)
int sys_close(int fd, uint32_t *err)
__swi_end(0x00D, sys_close, (fd, err));

/**
 * Force write data from the OS write buffer.
 * @param fd	file descriptor
 * @param[out] err	error code
 * @return 0 or error
 * */
__swi_begin(0x00E)
int sys_fflush(int fd, uint32_t *err)
__swi_end(0x00E, sys_fflush, (fd, err));

/**
 * Move to the desired position within the file.
 * @param fd			file descriptor
 * @param offset		desired position
 * @param origin		see #FileSeekOrigin
 * @param[out] err		error code
 * @param[out] err2		error code
 * @return 0 or error
 * */
__swi_begin(0x00F)
long sys_lseek(int fd, uint32_t offset, uint32_t origin, uint32_t *err, uint32_t *err2)
__swi_end(0x00F, sys_lseek, (fd, offset, origin, err, err2));

/**
 * Create a new directory.
 * @param dirname		path of the new directory
 * @param[out] err		error code
 * @return 0 or error
 * */
__swi_begin(0x010)
int sys_mkdir(const char *dirname, uint32_t *err)
__swi_end(0x010, sys_mkdir, (dirname, err));

/**
 * @copydoc sys_mkdir
 * */
__swi_begin(0x3B7)
int sys_mkdir_ws(const WSHDR *dirname, uint32_t *err)
__swi_end(0x3B7, sys_mkdir_ws, (dirname, err));

/**
 * Remove directory.
 * @param dirname		path to the directory
 * @param[out] err		error code
 * @return 0 or error
 * */
__swi_begin(0x08F)
int sys_rmdir(const char *dirname, uint32_t *err)
__swi_end(0x08F, sys_rmdir, (dirname, err));

/**
 * Rename file or directory.
 * @param old_name		old file/dir name (full path)
 * @param new_name		new file/dir name (full path)
 * @param err			error code
 * @return 0 or error
 * */
__swi_begin(0x08E)
int sys_rename(const char *old_name, const char *new_name, uint32_t *err)
__swi_end(0x08E, sys_rename, (old_name, new_name, err));

/**
 * @copydoc sys_rename
 * */
__swi_begin(0x3B9)
int sys_rename_ws(const WSHDR *old_name, const WSHDR *new_name, uint32_t *err)
__swi_end(0x3B9, sys_rename_ws, (old_name, new_name, err));

/**
 * Remove file.
 * @param path			path to the file
 * @param[out] err		error code
 * @return 0 or error
 * */
__swi_begin(0x16B)
int sys_unlink(const char *path, uint32_t *err)
__swi_end(0x16B, sys_unlink, (path, err));

/**
 * Truncate the file to the given size.
 * @param fd			file descriptor
 * @param length		new size of the file
 * @param[out] err		error code
 * @return 0 or error
 * */
__swi_begin(0x090)
int sys_truncate(int fd, int length, uint32_t *err)
__swi_end(0x090, sys_truncate, (fd, length, err));

/**
 * Get information about the file or directory.
 * @param path		path to the file or directory.
 * @param stat 		pointer where the information will be written (#FSTATS)
 * @param[out] err	error code
 * @return 0 or error
 * */
__swi_begin(0x084)
int sys_stat(const char *path, FSTATS *stat, uint32_t *err)
__swi_end(0x084, sys_stat, (path, stat, err));

/**
 * Get information about the file or directory by fd.
 * @param fd		file descriptor
 * @param stat 		pointer where the information will be written (#FSTATS)
 * @param[out] err	error code
 * @return 0 or error
 * */
__swi_begin(0x38D)
int sys_fstat(int fd, FSTATS *stat, uint32_t *err)
__swi_end(0x38D, sys_fstat, (fd, stat, err));

/**
 * Format drive by index.
 * @param drive			drive index (0 - 0:, 1 - 1:, 2 - 2:, 3 - 4:)
 * @param[out] err		error code
 * @return 0 or error
 * */
__swi_begin(0x38C)
int sys_format(uint16_t drive, uint32_t *err)
__swi_end(0x38C, sys_format, (drive, err));

/**
 * Truncate or grow the file to the given size.
 * @param fd			file descriptor
 * @param length		new size of the file
 * @param[out] err		error code
 * @return 0 or error
 * */
__swi_begin(0x03C)
int setfilesize(int fd, uint32_t length, uint32_t *err)
__swi_end(0x03C, setfilesize, (fd, length, err));

/**
 * @copydoc sys_rename
 * @deprecated Use #sys_rename instead.
 * */
__swi_begin(0x08E)
int fmove(const char *old_name, const char *new_name, uint32_t *err)
__swi_end(0x08E, fmove, (old_name, new_name, err));

/**
 * Checking that a path is a folder.
 * @param path		the path we are checking
 * @param[out] err	error code
 * @return 1 is that folder, 0 is that file, and < 0 indicates an error.
 * */
__swi_begin(0x091)
int isdir(const char *path, uint32_t *err)
__swi_end(0x091, isdir, (path, err));

/**
 * @copydoc isdir
 * */
__swi_begin(0x3BC)
int isdir_ws(const WSHDR *path, uint32_t *err)
__swi_end(0x3BC, isdir_ws, (path, err));

/**
 * Check if a file or directory exists.
 * @param path			path to the file or directory
 * @return 1 or 0
 * */
__swi_begin(0x2E3)
int fexists(WSHDR *path)
__swi_end(0x2E3, fexists, (path));

/**
 * Get attributes of the file or directory.
 * @param path		path to the file or directory.
 * @param attr 		pointer where the attributes will be written
 * @param[out] err	error code
 * @return 0 or error
 * */
__swi_begin(0x012)
int GetFileAttrib(const char *path, uint8_t *attr, uint32_t *err)
__swi_end(0x012, GetFileAttrib, (path, attr, err));

/**
 * Set attributes for the file or directory.
 * @param path		path to the file or directory.
 * @param attr		bitmask: #FileAttributes
 * @param[out] err	error code
 * @return 0 or error
 * */
__swi_begin(0x013)
int SetFileAttrib(const char *path, uint8_t attr, uint32_t *err)
__swi_end(0x013, SetFileAttrib, (path, attr, err));

/**
 * Get extended file properties.
 * See description of #FILE_PROP for additional information.
 * @param[out] props	pointer to the extended properties structure
 * @param file			name of the file, example: "beans_recipe.jpg"
 * @param path			path to the file, example: "0:\\Pictures\\"
 * @return 1: success, 0: error
 * */
__swi_begin(0x246)
int GetFileProp(FILE_PROP *props, const WSHDR *file, const WSHDR *path)
__swi_end(0x246, GetFileProp, (props, file, path));

#ifdef NEWSGOLD
/**
 * Get duration of the .wav file.
 * @param path		path to the .wav file
 * @return length in clocks (1 tick - 4.615 ms)
 * @deprecated Different function signatures across platforms! Always use: #GetFileProp
 * */
__swi_begin(0x045)
int GetWavLen(const char *path)
__swi_end(0x045, GetWavLen, (path));
#else
/**
 * Get duration of the .wav file.
 * @param[out] wav_info		path to the #TWavLen
 * @return 1: success, 0: error
 * @deprecated Different function signatures across platforms! Always use: #GetFileProp
 * */
__swi_begin(0x045)
int GetWavLen(TWavLen *wav_info)
__swi_end(0x045, GetWavLen, (wav_info));
#endif

/**
 * Open search session and get first result.
 * #DIR_ENTRY is both a search result and an search session.
 * 
 * @param dir_entry		pointer to the search session
 * @param mask			search mask (pattern with * as wildcard)
 * @param[out] err		error code
 * @return 1: success, `dir_entry` contains first result of the search
 * @return 0: no files found
 * */
__swi_begin(0x06B)
int FindFirstFile(DIR_ENTRY *dir_entry, const char *mask, uint32_t *err)
__swi_end(0x06B, FindFirstFile, (dir_entry, mask, err));

/**
 * Continue searching for files and get next result.
 * @param dir_entry		pointer to the search session
 * @param[out] err		error code
 * @return 1: success, `dir_entry` contains next result of the search
 * @return 0: search is done
 * */
__swi_begin(0x06C)
int FindNextFile(DIR_ENTRY *dir_entry, uint32_t *err)
__swi_end(0x06C, FindNextFile, (dir_entry, err));

/**
 * Close search session
 * @param dir_entry		first found file
 * @param[out] err		error code
 * @return 0 or error
 * */
__swi_begin(0x06D)
int FindClose(DIR_ENTRY *dir_entry, uint32_t *err)
__swi_end(0x06D, FindClose, (dir_entry, err));

/**
 * Get free space on a specified disk.
 * @param drive		number of the drive: 0-4
 * @param[out] err	error code
 * @return bytes count
 * */
__swi_begin(0x08A)
int GetFreeFlexSpace(int drive, uint32_t *err)
__swi_end(0x08A, GetFreeFlexSpace, (drive, err));

/**
 * Get total space on a specified disk.
 * @param drive		number of the drive: 0-4
 * @param[out] err	error code
 * @return bytes count
 * */
__swi_begin(0x08B)
int GetTotalFlexSpace(int drive, uint32_t *err)
__swi_end(0x08B, GetTotalFlexSpace, (drive, err));

// ------------------------------------------------------
/**
 * @name Legacy names for old GCC code.
 * These functions have a bad underscore name, which is bad for the public API.
 * @{
 * */

/**
 * @copydoc sys_stat
 * @deprecated For compatibility with old GCC code. Use #sys_stat instead.
 * */
__swi_begin(0x084)
int GetFileStats(const char *path, FSTATS *stat, uint32_t *err)
__swi_end(0x084, GetFileStats, (path, stat, err));

/**
 * @copydoc sys_open
 * @deprecated For compatibility with old GCC code. Use #sys_open instead.
 * */
__swi_begin(0x00A)
int _open(const char *path, uint32_t mode, uint32_t permission, uint32_t *err)
__swi_end(0x00A, _open, (path, mode, permission, err));

/**
 * @copydoc sys_read
 * @deprecated For compatibility with old GCC code. Use #sys_read instead.
 * */
__swi_begin(0x00B)
int _read(int fd, void *buffer, int length, uint32_t *err)
__swi_end(0x00B, _read, (fd, buffer, length, err));

/**
 * @copydoc sys_write
 * @deprecated For compatibility with old GCC code. Use #sys_write instead.
 * */
__swi_begin(0x00C)
int _write(int fd, const void *buffer, int length, uint32_t *err)
__swi_end(0x00C, _write, (fd, buffer, length, err));

/**
 * @copydoc sys_close
 * @deprecated For compatibility with old GCC code. Use #sys_close instead.
 * */
__swi_begin(0x00D)
int _close(int fd, uint32_t *err)
__swi_end(0x00D, _close, (fd, err));

/**
 * @copydoc sys_fflush
 * @deprecated For compatibility with old GCC code. Use #sys_fflush instead.
 * */
__swi_begin(0x00E)
int _flush(int fd, uint32_t *err)
__swi_end(0x00E, _flush, (fd, err));

/**
 * @copydoc sys_lseek
 * @deprecated For compatibility with old GCC code. Use #sys_lseek instead.
 * */
__swi_begin(0x00F)
long _lseek(int fd, uint32_t offset, uint32_t origin, uint32_t *err, uint32_t *err2)
__swi_end(0x00F, _lseek, (fd, offset, origin, err, err2));

/**
 * @copydoc sys_mkdir
 * @deprecated For compatibility with old GCC code. Use #sys_mkdir instead.
 * */
__swi_begin(0x010)
int _mkdir(const char *dirname, uint32_t *err)
__swi_end(0x010, _mkdir, (dirname, err));

/**
 * @copydoc sys_rmdir
 * @deprecated For compatibility with old GCC code. Use #sys_rmdir instead.
 * */
__swi_begin(0x08F)
int _rmdir(const char *dirname, uint32_t *err)
__swi_end(0x08F, _rmdir, (dirname, err));

/**
 * @copydoc sys_unlink
 * @deprecated For compatibility with old GCC code. Use #sys_unlink instead.
 * */
__swi_begin(0x16B)
int _unlink(const char *path, uint32_t *err)
__swi_end(0x16B, _unlink, (path, err));

/**
 * @copydoc sys_truncate
 * @deprecated For compatibility with old GCC code. Use #sys_truncate instead.
 * */
__swi_begin(0x090)
int _truncate(int fd, int length, uint32_t *err)
__swi_end(0x090, _truncate, (fd, length, err));

/** @} */
// ------------------------------------------------------

// ------------------------------------------------------
#ifdef SWILIB_LEGACY_COMPAT
/**
 * @name Legacy names for old IAR code.
 * These functions are disabled by default, because they have ambiguous names which conflict with stdio.h api.
 * But you can always enable these functions using the `-DSWILIB_LEGACY_COMPAT` define.
 * @{
 * */

/**
 * @copydoc sys_open
 * @deprecated For compatibility with old IAR code. Use #sys_open instead.
 * */
__swi_begin(0x00A)
int fopen(const char *path, uint32_t mode, uint32_t permission, uint32_t *err)
__swi_end(0x00A, fopen, (path, mode, permission, err));

/**
 * @copydoc sys_read
 * @deprecated For compatibility with old IAR code. Use #sys_read instead.
 * */
__swi_begin(0x00B)
int fread(int fd, void *buffer, int length, uint32_t *err)
__swi_end(0x00B, fread, (fd, buffer, length, err));

/**
 * @copydoc sys_close
 * @deprecated For compatibility with old IAR code. Use #sys_close instead.
 * */
__swi_begin(0x00D)
int fclose(int fd, uint32_t *err)
__swi_end(0x00D, fclose, (fd, err));

/**
 * @copydoc sys_fflush
 * @deprecated For compatibility with old IAR code. Use #sys_fflush instead.
 * */
__swi_begin(0x00E)
int fflush(int fd, uint32_t *err)
__swi_end(0x00E, fflush, (fd, err));

/**
 * @copydoc sys_write
 * @deprecated For compatibility with old IAR code. Use #sys_write instead.
 * */
__swi_begin(0x00C)
int fwrite(int fd, const void *buffer, int length, uint32_t *err)
__swi_end(0x00C, fwrite, (fd, buffer, length, err));

/**
 * @copydoc sys_lseek
 * @deprecated For compatibility with old IAR code. Use #sys_lseek instead.
 * */
__swi_begin(0x00F)
long lseek(int fd, uint32_t offset, uint32_t origin, uint32_t *err, uint32_t *err2)
__swi_end(0x00F, lseek, (fd, offset, origin, err, err2));

/**
 * @copydoc sys_mkdir
 * @deprecated For compatibility with old IAR code. Use #sys_mkdir instead.
 * */
__swi_begin(0x010)
int mkdir(const char *dirname, uint32_t *err)
__swi_end(0x010, mkdir, (dirname, err));

/**
 * @copydoc sys_rmdir
 * @deprecated For compatibility with old IAR code. Use #sys_rmdir instead.
 * */
__swi_begin(0x08F)
int rmdir(const char *dirname, uint32_t *err)
__swi_end(0x08F, rmdir, (dirname, err));

/**
 * @copydoc sys_unlink
 * @deprecated For compatibility with old IAR code. Use #sys_unlink instead.
 * */
__swi_begin(0x16B)
int unlink(const char *path, uint32_t *err)
__swi_end(0x16B, unlink, (path, err));

/**
 * @copydoc sys_truncate
 * @deprecated For compatibility with old IAR code. Use #sys_truncate instead.
 * */
__swi_begin(0x090)
int truncate(int fd, int length, uint32_t *err)
__swi_end(0x090, truncate, (fd, length, err));

/** @} */
#endif
// ------------------------------------------------------

__swilib_end

/** @} */
