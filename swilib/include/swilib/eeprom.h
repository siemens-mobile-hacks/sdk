#pragma once

/**
 * @addtogroup EEPROM
 * @brief Functions for working with EELITE and EEFULL.
 * Also, this function is useful for the `crack.elf`
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/eeprom.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

/**
 * @name EELITE
 * @{
 * */

/**
 * EELITE write-operation completion callback.
 * @param status operation status; zero indicates success
 * */
typedef void (*EELiteCallback)(int status);

/**
 * Get the last ID of the EELITE blocks.
 * @return ID
 * */
__swi_begin(0x028)
uint32_t GetEELiteMaxID(void)
__swi_end(0x028, GetEELiteMaxID, ());

/**
 * Get info about the EELITE block.
 * @param block			EELITE block number
 * @param[out] size		block size
 * @param[out] version	block version
 * @return 0 or error
 * */
__swi_begin(0x02B)
int GetEELiteBlockSizeVersion(uint32_t block, int *size, char *version)
__swi_end(0x02B, GetEELiteBlockSizeVersion, (block, size, version));

/**
 * Get a pointer to the EELITE block data.
 * @param block		EELITE block number
 * @return pointer to the block data
 * */
__swi_begin(0x02A)
void *GetEELiteBlockAddress(short block)
__swi_end(0x02A, GetEELiteBlockAddress, (block));

/**
 * Begin writing to the EELITE block.
 * @param block		EELITE block number
 * @param size		size of writing
 * @param version	block version; only the low byte is stored
 * @param callback	optional completion callback
 * @return 0 or error
 * */
__swi_begin(0x02D)
int StartWriteEELiteBlock(uint32_t block, uint32_t size, uint32_t version, EELiteCallback callback)
__swi_end(0x02D, StartWriteEELiteBlock, (block, size, version, callback));

/**
 * Write data to the EELITE block.
 * @param block			EELITE block number
 * @param buf			new block data
 * @param offset		offset in the block
 * @param size			size to the write
 * @param callback	optional completion callback
 * @return 0 or error
 * */
__swi_begin(0x030)
int WriteEELiteBlock(uint32_t block, const void *buf, uint32_t offset, uint32_t size, EELiteCallback callback)
__swi_end(0x030, WriteEELiteBlock, (block, buf, offset, size, callback));

/**
 * Finish writing to the EELITE block.
 * @param block		EELITE block number
 * @param callback	optional completion callback
 * @return 0 or error
 * */
__swi_begin(0x02E)
int FinishWriteEELiteBlock(uint32_t block, EELiteCallback callback)
__swi_end(0x02E, FinishWriteEELiteBlock, (block, callback));

/**
 * Delete block in the EELITE.
 * @param block			EELITE block number
 * @param callback	optional completion callback
 * @return 0 or error
 * */
__swi_begin(0x02F)
int DeleteEELiteBlock(uint32_t block, EELiteCallback callback)
__swi_end(0x02F, DeleteEELiteBlock, (block, callback));

/** @} */

/**
 * @name EEFULL
 * @{
 * */

/**
 * Get the last ID of the EEFULL blocks.
 * @return ID
 * */
__swi_begin(0x029)
uint32_t GetEEFullMaxID(void)
__swi_end(0x029, GetEEFullMaxID, ());

/**
 * Get info about the EEFULL block.
 * @param block			EEFULL block number
 * @param[out] size		block size
 * @param[out] version	block version
 * @return 0 or error
 * */
__swi_begin(0x02C)
int EEFullGetBlockInfo(uint32_t block, int *size, char *version)
__swi_end(0x02C, EEFullGetBlockInfo, (block, size, version));

/**
 * Read block from the EEFULL.
 * @param block			EEFULL block number
 * @param[out] buf		output buffer for block data
 * @param offset		offset in the block data
 * @param size			size to the read
 * @param cepid			CEPID, set to 0xFFFF
 * @param msg			GBS message ID, set to 0
 * */
__swi_begin(0x086)
void EEFullReadBlock(int block, void *buf, int offset, int size, int cepid, int msg)
__swi_end(0x086, EEFullReadBlock, (block, buf, offset, size, cepid, msg));

/**
 * Update block in the EEFULL.
 * @param block			EEFULL block number
 * @param buf			new block data
 * @param offset		offset in the block
 * @param size			size to the write
 * @param cepid			CEPID, set to 0xFFFF
 * @param msg			GBS message ID, set to 0
 * */
__swi_begin(0x087)
void EEFullWriteBlock(int block, const void *buf, int offset, int size, int cepid, int msg)
__swi_end(0x087, EEFullWriteBlock, (block, buf, offset, size, cepid, msg));

/**
 * Delete block in the EEFULL.
 * @param block			EEFULL block number
 * @param cepid			CEPID, set to 0xFFFF
 * @param msg			GBS message ID, set to 0
 * @return 0 or error
 * */
__swi_begin(0x239)
int EEFullDeleteBlock(uint32_t block, int cepid, int msg)
__swi_end(0x239, EEFullDeleteBlock, (block, cepid, msg));

/**
 * Create new block in the EEFULL.
 * @param block			EEFULL block number
 * @param size			block size
 * @param version		block version
 * @param cepid			CEPID, set to 0xFFFF
 * @param msg			GBS message ID, set to 0
 * @return 0 or error
 * */
__swi_begin(0x23A)
int EEFullCreateBlock(uint32_t block, int size, int version, int cepid, int msg)
__swi_end(0x23A, EEFullCreateBlock, (block, size, version, cepid, msg));

/** @} */

__swilib_end

/** @} */
