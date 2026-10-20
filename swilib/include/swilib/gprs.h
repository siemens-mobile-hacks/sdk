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
 * Check if GPRS available in the current network.
 * @return 1 or 0
 * */
__swi_begin(0x284)
char IsGPRSAvailable()
__swi_end(0x284, IsGPRSAvailable, ());

/**
 * Check if EDGE available in the current network.
 * @return 1 or 0
 * */
__swi_begin(0x285)
char IsEDGEAvailable()
__swi_end(0x285, IsEDGEAvailable, ());

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
 * Get an ID of the active internet profile.
 * @return ID
 * @platforms X75, SG
 * @warning SGOLD only
 * */
__swi_begin(0x1A3)
int GetCurrentGPRSProfile(void)
__swi_end(0x1A3, GetCurrentGPRSProfile, ());

/**
 * Change current internet profile.
 * @param profile_id		ID of the profile
 * @return status
 * @platforms X75, SG
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
 * @platforms X75, SG
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
 * @platforms X75, SG
 * @warning SGOLD only, call only from SUBPROC.
 * */
__swi_begin(0x1A5)
void RegisterCepIdForCurProfile(uint32_t cepid, int profile_id, uint32_t is_gprs)
__swi_end(0x1A5, RegisterCepIdForCurProfile, (cepid, profile_id, is_gprs));

/**
 * Get internet connection timeout for disconnect when there is no activity.
 * @return seconds
 * @platforms X75, SG
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

#ifdef ELKA

/**
 * Request disconnection of a native LMAN context.
 * @param req		two request bytes: context ID, then disconnect cause
 * @return 1 if handled, 0 if rejected. Call from a process registered for socket work
 * */
__swi_begin(0x43B)
int RequestLMANDisconnect(const uint8_t *req)
__swi_end(0x43B, RequestLMANDisconnect, (req));

/**
 * Find the socket-registration slot for a CEPID.
 * @param cepid		GBS process identifier
 * @return registration index 0..13, or 0xFFFF if not registered
 * */
__swi_begin(0x43C)
unsigned GetSocketRegIndex(unsigned cepid)
__swi_end(0x43C, GetSocketRegIndex, (cepid));

/**
 * Get the process identifier assigned to a native service.
 * @param service		firmware service index; 3 selects the Java service
 * @return service CEPID, or 0 if unavailable
 * */
__swi_begin(0x43D)
unsigned GetServiceCepid(unsigned service)
__swi_end(0x43D, GetServiceCepid, (service));

/**
 * Allocate a native LMAN context.
 * @param bearer		native bearer kind; 1 selects GPRS
 * @param type		context subtype
 * @return context index 0..7. Check for a free context before calling; a full table asserts
 * */
__swi_begin(0x43E)
unsigned LMAN_AllocContext(unsigned bearer, uint8_t type)
__swi_end(0x43E, LMAN_AllocContext, (bearer, type));

/**
 * Copy a NAP profile into an allocated LMAN context.
 * @param cid		context index 0..7
 * @param profile		profile with a terminated name and native bearer settings
 * */
__swi_begin(0x43F)
void LMAN_SetProfile(unsigned cid, const CTX_NAPDEF *profile)
__swi_end(0x43F, LMAN_SetProfile, (cid, profile));

/**
 * Attach or detach a registered process from an LMAN context.
 * @param reg_index	socket-registration index 0..13
 * @param cid		context index 0..7
 * @param on		1 to attach, 0 to detach
 * */
__swi_begin(0x440)
void LMAN_SetRef(unsigned reg_index, unsigned cid, int on)
__swi_end(0x440, LMAN_SetRef, (reg_index, cid, on));

/**
 * Change a native LMAN context state and notify its registered owners.
 * @param cid		context index 0..7
 * @param state		native state value; 4 means connected
 * */
__swi_begin(0x441)
void LMAN_SetState(unsigned cid, int state)
__swi_end(0x441, LMAN_SetState, (cid, state));

/**
 * Reset and release a native LMAN context without disconnecting a physical bearer.
 * @param cid		context index 0..7
 * */
__swi_begin(0x442)
void LMAN_FreeContext(unsigned cid)
__swi_end(0x442, LMAN_FreeContext, (cid));

/**
 * Get the native LMAN context table.
 * @return pointer to 8 context entries, 0x70 bytes each
 * */
__swi_begin(0x8444)
uint8_t *RamLmanContexts(void)
__swi_end(0x8444, RamLmanContexts, ());

/**
 * Get the LMAN process-to-context reference table.
 * @return 14 rows of 8 reference words, indexed by registration slot and context ID
 * */
__swi_begin(0x8445)
uint32_t *RamLmanRefs(void)
__swi_end(0x8445, RamLmanRefs, ());

/**
 * Get the native socket-registration table.
 * @return pointer to 14 registration entries, 0x14 bytes each
 * */
__swi_begin(0x8446)
void *RamSocketRegs(void)
__swi_end(0x8446, RamSocketRegs, ());

/**
 * Get a WSP object.
 * @param id		object ID, 0x17: preferences, 0x18: network policy
 * @return pointer to the object or NULL
 * */
__swi_begin(0x44D)
void *WSP_GetObject(unsigned id)
__swi_end(0x44D, WSP_GetObject, (id));

/**
 * Read a WSP property.
 * @param key		property name
 * @param value		output buffer
 * @param length	buffer size, receives the value length
 * @return 1: success, 0: error
 * */
__swi_begin(0x44E)
int WSP_ReadProperty(const char *key, void *value, unsigned *length)
__swi_end(0x44E, WSP_ReadProperty, (key, value, length));

/**
 * Get the WSP connection state.
 * @param bearer	bearer ID
 * @param nap		NAP profile ID
 * @return connection state, 2: connected
 * */
__swi_begin(0x44F)
uint8_t WSP_GetConnectionState(int bearer, int nap)
__swi_end(0x44F, WSP_GetConnectionState, (bearer, nap));

#endif

/** @} */

/**
 * @name Profile
 * @{
 * */

/**
 * Get name of the current internet profile.
 * @return C-string
 * */
__swi_begin(0x828E)
const char *RamActiveGPRSProfileName()
__swi_end(0x828E, RamActiveGPRSProfileName, ());

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
