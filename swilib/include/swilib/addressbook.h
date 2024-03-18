#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#include "wstring.h"
#endif

__swilib_begin

/**
 * @addtogroup Addressbook
 * @brief Functions for working with addressbook.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/addressbook.h>`
 * @{
 */

typedef struct NativeAbData NativeAbData;
typedef struct AbNumList AbNumList;
typedef struct PKT_NUM PKT_NUM;
typedef struct AB_UNPRES AB_UNPRES;
typedef struct AB_UNPRES_ITEM AB_UNPRES_ITEM;

/**
 * Item of the #AB_UNPRES
 * */
struct AB_UNPRES_ITEM {
#ifdef NEWSGOLD
	short field_0;
	char no_data;
	char item_type;
	int field_4;
	void *data;
#else
	char field_0;
	char no_data;
	char field_2;
	char item_type;
	int field_4;
	void *data;
#endif
};

/**
 * Uncompressed APO entry.
 * */
struct AB_UNPRES {
#ifdef NEWSGOLD
	short NrOfFlds;
	short number_of_records;
	short NrAllocFlds;
	short field_6;
	short NrJ;
	char field_A;
	char field_B;
	AB_UNPRES_ITEM *record_list;
	char EntTp;
	char field_11;
	short EntId;
	int field_14;
	int field_18;
#else
	short field_0;
	short field_2;
	short field_4;
	short number_of_records;
	short field_8;
	short field_A;
	AB_UNPRES_ITEM *record_list;
	char field_10;
	char field_11;
	short field_12;
	int field_14;
	int field_18;
#endif
};

/**
 * Value of the adressbook list item.
 * */
#pragma pack(1)
struct PKT_NUM {
	char _1D;
	char format;		/**< Format of the data */
	char data_size;		/**< Size of the data */
	char _0_1;
	char _0_2;
//	char _0_3;
	char data[128];		/**< Raw data */
};
#pragma pack()

/**
 * Item of the adressbook list.
 * */
struct AbNumList {
	void *next;		/**< Pointer to the next item */
	void *prev;		/**< Pointer to the prev item */
	int flag_data;	/**< Type */
	void *data;		/**< Pointer to the #PKT_NUM */
};

/**
 * Native address book data.
 * */
struct NativeAbData {
	AbNumList *first;		/**< First item */
	AbNumList *last;		/**< Last item */
	void *mfree_adr;		/**< Pointer to the #free() */
	void *unk;
};

/**
 * Open native adressbook.
 * @param type		type of AdressBook UI
 * @param unk1		unknown
 * @param unk2		unknown
 * @param data		pointer to the #NativeAbData or NULL
 * @return CSM ID
 * */
__swi_begin(0x2B9)
int OpenNativeAddressbook(int type, int unk1, int unk2, NativeAbData *data)
__swi_end(0x2B9, OpenNativeAddressbook, (type, unk1, unk2, data));

/**
 * Allocate native addressbook data.
 * @return pointer to the allocated data
 * */
__swi_begin(0x2B3)
NativeAbData *AllocNativeAbData(void)
__swi_end(0x2B3, AllocNativeAbData, ());

/**
 * Free allocated native addressbook data.
 * @param data		pointer to the allocated data
 * @return 1: success, 0: error
 * */
__swi_begin(0x2B4)
int FreeNativeAbData(NativeAbData *data)
__swi_end(0x2B4, FreeNativeAbData, (data));

/**
 * Get count of the items in #NativeAbData
 * @param data		pointer to the native addressbook data
 * @return count
 * */
__swi_begin(0x2D3)
int GetFilledNAbDataCount(NativeAbData *data)
__swi_end(0x2D3, GetFilledNAbDataCount, (data));

/**
 * Get item data from the #NativeAbData by index.
 * @param data		pointer to the native addressbook data
 * @param index		index of the item
 * @return pointer to the #PKT_NUM
 * */
__swi_begin(0x2D4)
PKT_NUM *GetDataFromNAbData(NativeAbData *data, int index)
__swi_end(0x2D4, GetDataFromNAbData, (data, index));

/**
 * Get item status from the #NativeAbData by index.
 * @param data		pointer to the native addressbook data
 * @param index		index of the item
 * @return item status
 * */
__swi_begin(0x2B7)
int GetNativeAbDataStatus(NativeAbData *data, int index)
__swi_end(0x2B7, GetNativeAbDataStatus, (data, index));

/**
 * Get item type from the #NativeAbData by index.
 * @param data		pointer to the native addressbook data
 * @param index		index of the item
 * @return item type
 * */
__swi_begin(0x2B5)
int GetNativeAbDataType(NativeAbData *data, int index)
__swi_end(0x2B5, GetNativeAbDataType, (data, index));

/**
 * Get number from the #NativeAbData
 * @param data		pointer to the native addressbook data
 * @param type		usually result of the `GetNativeAbDataType(data, 0)`
 * @param unk0		set to 0
 * @return 1: success, 0: error
 * */
__swi_begin(0x2B6)
WSHDR *GetNumFromNativeAbData(NativeAbData *data, int type, int unk0)
__swi_end(0x2B6, GetNumFromNativeAbData, (data, type, unk0));

/**
 * Set number to the #NativeAbData
 * @param data		pointer to the native addressbook data
 * @param unk		set to 0x1D
 * @param num		phone number
 * @return 1: success, 0: error
 * */
__swi_begin(0x2B8)
int SetNumToNativeAbData(NativeAbData *data, int unk, const WSHDR *num)
__swi_end(0x2B8, SetNumToNativeAbData, (data, unk, num));

/**
 * Decode #PKT_NUM for the phone number.
 * @param pkt			pointer to the #PKT_NUM
 * @param[out] buf		output buffer for the phone number
 * @param maxlen		maximum size of output buffer
 * */
__swi_begin(0x2D5)
void UnpackNumPkt(const PKT_NUM *pkt, char *buf, int maxlen)
__swi_end(0x2D5, UnpackNumPkt, (pkt, buf, maxlen));

/**
 * @name Functions for read files in `0:\\System\\apo\\addr\\`
 * @{
 * */

/**
 * Unpack entry.
 * @param[out] entry		unpacked entry
 * @param data				encoded entry data
 * @param size				size of the entry data
 * @param flags				unknown flags
 * @return 0 or error
 * */
__swi_begin(0x16D)
int UnpackABentry(AB_UNPRES *entry, const void *data, int size, int flags)
__swi_end(0x16D, UnpackABentry, (entry, data, size, flags));

/**
 * Free unpacked entry.
 * @param entry		pointer to the #AB_UNPRES
 * @param mfree_fn	result of the #mfree_adr()
 * @return 0 or error
 * */
__swi_begin(0x16E)
int FreeUnpackABentry(AB_UNPRES *entry, void *mfree_fn)
__swi_end(0x16E, FreeUnpackABentry, (entry, mfree_fn));

/**
 * Convert AB_UNPRESS.item_type to the NativeAbData item type.
 * @param item_type		input type
 * @return converted type
 * */
__swi_begin(0x16F)
int GetTypeOfAB_UNPRES_ITEM(int item_type)
__swi_end(0x16F, GetTypeOfAB_UNPRES_ITEM, (item_type));

/** @} */

__swilib_end

/** @} */
