#pragma once

/**
 * @addtogroup I2C
 * @brief Functions for working with I2C bus.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/i2c.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

typedef struct I2C_MSG I2C_MSG;

/**
 * I2C SMBUS message
 * */
struct I2C_MSG {
	uint8_t chip_addr; 			/**< 7-bit address. */
#ifdef NEWSGOLD
	char unk1;
	char unk2;
	char unk3;
	short nRegister;			/**< ID of SMBUS register. */
#else
	char unk1;
	short nRegister;			/**< ID of SMBUS register. */
	char unk2;
	uint8_t tf;
#endif
	uint16_t cb_data;			/**< Unknown. */
	int (*i2c_msg)(I2C_MSG *);	/**< Callback, which will be called at the end of the transfer. */
	void *data;					/**< Reading buffer (i2c_receive) or data for sending (i2c_transfer). */
	int size;					/**< Size of the data for reading or writing. */
};

/**
 * Read data from the I2C device (SMBUS).
 * @param msg	i2c message #I2C_MSG
 * @return 0 or error
 * */
__swi_begin(0x2EC)
int i2c_transfer(I2C_MSG *msg)
__swi_end(0x2EC, i2c_transfer, (msg));

/**
 * Write data to the I2C device (SMBUS).
 * @param msg	i2c message #I2C_MSG
 * @return 0 or error
 * */
__swi_begin(0x2ED)
int i2c_receive(I2C_MSG *msg)
__swi_end(0x2ED, i2c_receive, (msg));

__swilib_end

/** @} */
