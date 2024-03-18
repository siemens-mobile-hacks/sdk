#pragma once

/**
 * @addtogroup GPRS
 * @brief GPRS related functions.
 * 
 * See GprsD.elf sources for more info.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/gprs.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

typedef struct REGSOCKCEPID_DATA REGSOCKCEPID_DATA;
typedef struct CTX_NAPDEF CTX_NAPDEF;
typedef struct NAP_PARAM_CONT NAP_PARAM_CONT;
typedef struct LMAN_DATA LMAN_DATA;

/**
 * LinkManager GBS events.
 * */
enum LmanEventID {
	LMAN_CONNECT_CNF		= 0x80,
	LMAN_CONNECT_REJ_IND	= 0x81,
	LMAN_DISCONNECT_IND		= 0x82,
	LMAN_DISCONNECT_CNF		= 0x84,
	LMAN_LINK_UP_IND		= 0x89,
};

/**
 * ENIP GBS events.
 * */
enum EnipEventID {
	ENIP_BUFFER_FREE		= 0x8A,
	ENIP_BUFFER_FREE1		= 0x8B,
	ENIP_SOCK_DATA_READ		= 0x8C,
	ENIP_SOCK_CONNECTED		= 0x8D,
	ENIP_SOCK_CLOSED		= 0x8E,
	ENIP_SOCK_REMOTE_CLOSED	= 0x8F,
	ENIP_SOCK_ACCEPTED		= 0x90,
	ENIP_SOCK_ICMP_ERROR	= 0x91,
	ENIP_DNR_HOST_BY_NAME	= 0x94,
};

/**
 * CEPID registration data for sockets.
 * @warning Used on NewSGOLD.
 * */
#pragma pack(2)
struct REGSOCKCEPID_DATA {
	uint16_t _0x0080;	/**< Set to 0x0080 */
	uint16_t _0xFFFF;	/**< Set to 0xFFFF */
	uint16_t _0x0000;	/**< Set to 0x0000 */
};
#pragma pack()

/**
 * Network Access Point data.
 * @warning Used on NewSGOLD.
 * */
struct CTX_NAPDEF {
	char body[0x204];	/**< Binary data of the NAP profile */
};

/**
 * Network Access Point data container.
 * @warning Used on NewSGOLD.
 * */
struct NAP_PARAM_CONT {
	uint32_t len;
	CTX_NAPDEF *ctx_napdef;
	uint32_t zero;
	CTX_NAPDEF napdef;
};

/**
 * LinkManager data.
 * @warning Used on NewSGOLD.
 * */
struct LMAN_DATA {
#ifdef NEWSGOLD
	int zero;				/**< Set to 0 */
	void *native_profile;	/**< Set to NULL */
	char _1;				/**< Set to 1 */
	char _4;				/**< Set to 4 */
	uint16_t _0;			/**< Set to 0 */
	NAP_PARAM_CONT *NapParameterContainer;	/**< Pointer to the NAP: #NAP_PARAM_CONT */
#else
	char unk1;
	char *unk;
	char one;
	char isactivated;
#endif
};

/**
 * @name General functions
 * @{
 * */

/**
 * Check if GPRS enabled.
 * @return 1 or 0
 * */
__swi_begin(0x0A7)
char IsGPRSEnabled()
__swi_end(0x0A7, IsGPRSEnabled, ());

/**
 * Check if the GPRS session is established.
 * @return 1 or 0
 * */
__swi_begin(0x0A8)
char IsGPRSConnected()
__swi_end(0x0A8, IsGPRSConnected, ());

/**
 * Enable or disable GPRS internet.
 * @param enable	1 or 0
 * @param unk		set to 1
 * */
__swi_begin(0x18E)
void GPRS_OnOff(int enable, int unk)
__swi_end(0x18E, GPRS_OnOff, (enable, unk));

/**
 * Get an ID of the active internet profile (SGOLD only).
 * @return ID
 * */
__swi_begin(0x1A3)
int GetCurrentGPRSProfile(void)
__swi_end(0x1A3, GetCurrentGPRSProfile, ());

/**
 * Change current internet profile.
 * @param profile_id		ID of the profile
 * @return status
 * @warning SGOLD only
 * */
__swi_begin(0x23C)
int SetCurrentGPRSProfile(int profile_id)
__swi_end(0x23C, SetCurrentGPRSProfile, (profile_id));

/** @} */

/**
 * @name SGOLD-only functions
 * @{
 * */

/**
 * Activate internet profile.
 * @param cepid			current CEPID, use #GBS_GetCurCepid
 * @param profile_id	GPRS profile ID, use #GetCurrentGPRSProfile
 * @return status
 * @warning SGOLD only, call only from SUBPROC.
 * */
__swi_begin(0x1A2)
int ActivateDialUpProfile(uint32_t cepid, int profile_id)
__swi_end(0x1A2, ActivateDialUpProfile, (cepid, profile_id));

/**
 * Register CEPID for internet profile.
 * @param cepid			current CEPID, use #GBS_GetCurCepid
 * @param profile_id	GPRS profile ID, use #GetCurrentGPRSProfile
 * @param is_gprs		connection type, 1: GPRS, 0: CSD
 * @warning SGOLD only, call only from SUBPROC.
 * */
__swi_begin(0x1A5)
void RegisterCepIdForCurProfile(uint32_t cepid, int profile_id, uint32_t is_gprs)
__swi_end(0x1A5, RegisterCepIdForCurProfile, (cepid, profile_id, is_gprs));

/**
 * Get internet connection timeout for disconnect when there is no activity.
 * @return seconds
 * @warning SGOLD only
 * */
__swi_begin(0x1A4)
int GetDisconnectTime(void)
__swi_end(0x1A4, GetDisconnectTime, ());

/** @} */

/**
 * @name NewSGOLD-only functions
 * @{
 * */

/**
 * Register current CEPID for sockets.
 * @param reg	pointer to the #REGSOCKCEPID_DATA
 * @return 1: success, 0: error
 * @warning Call only from SUBPROC, NewSGOLD only.
 * */
__swi_begin(0x186)
int RegisterCepidForSocketWork(REGSOCKCEPID_DATA *reg)
__swi_end(0x186, RegisterCepidForSocketWork, (reg));

/**
 * Connect to the GPRS.
 * @param data	pointer to the #LMAN_DATA
 * @return LMAN connect ID
 * @warning Call only from SUBPROC, NewSGOLD only.
 * */
__swi_begin(0x187)
int RequestLMANConnect(LMAN_DATA *data)
__swi_end(0x187, RequestLMANConnect, (data));

/** @} */

/**
 * @name Statistic
 * @{
 * */

/**
 * Refresh the GPRS traffic counter.
 * */
__swi_begin(0x06F)
void RefreshGPRSTraffic()
__swi_end(0x06F, RefreshGPRSTraffic, ());

/**
 * Reset the GPRS traffic counter.
 * */
__swi_begin(0x0A6)
void ResetGPRSTraffic()
__swi_end(0x0A6, ResetGPRSTraffic, ());

/**
 * Get traffic used by GPRS.
 * @return pointer to the byte count
 * 
 * ```C
 * int bytes = *GetGPRSTrafficPointer();
 * ```
 * */
__swi_begin(0x070)
int *GetGPRSTrafficPointer()
__swi_end(0x070, GetGPRSTrafficPointer, ());

/** @} */

__swilib_end

/** @} */
