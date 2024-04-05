#pragma once

/**
 * @addtogroup GBS
 * @brief General Bus System API
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/gbs.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

typedef struct GBS_MSG GBS_MSG;
typedef struct GBSTMR GBSTMR;
typedef struct IPC_REQ IPC_REQ;
typedef struct PGROUP PGROUP;

typedef void (*GBSTMR_CALLBACK)(GBSTMR *);
typedef void (*GBS_PROC_CALLBACK)();

/**
 * GBS CEP IDs.
 * */
enum GbsCepID {
	MMI_CEPID				= 0x4209,	/**< MMI */
	LCD_DISPLAYQUEUE_CEPID	= 0x4200,	/**< LCD_DISPLAYQUEUE */
	IDM_PROCESS_CEPID		= 0x403D,	/**< IDM_PROCESS */
#ifdef NEWSGOLD
	HELPER_CEPID			= 0x440A,	/**< HELPER */
#else
	HELPER_CEPID			= 0x4407,	/**< HELPER */
#endif
};

/**
 * Common GBS message IDs.
 * */
enum GbsMsgID {
#ifdef NEWSGOLD
	/* CALLS */
	MSG_INCOMMING_CALL			= 0x6000, /**< Incoming call */
	MSG_STATE_OF_CALL			= 0x6009, /**< State of the call */
	MSG_END_CALL				= 0x600B, /**< End of the call */
	
	/* HELPER */
	MSG_HELPER_TRANSLATOR		= 0xDEAE, /**< Translated msg from HELPER to MMI */
	MSG_RECONFIGURE_REQ			= 0xDEAF, /**< Config chaged (BCFG Editor) */
	MSG_IPC						= 0xDEB0, /**< ELFs IPC message */
	
	/* SMS */
	MSG_SMS_TX					= 0x5802, /**< Outgoing SMS */
	MSG_SMS_RX					= 0x5803, /**< Incoming SMS */
	
	/* USSD */
	MSG_USSD_RX					= 0x60E2, /**< USSD result */
	MSG_AUTOUSSD_RX				= 0x60E5, /**< USSD result (???) */
	
	/* AUDIO */
	MSG_PLAYFILE_REPORT			= 0x70BC, /**< PlayFile status reporting */
	
	/* CSM */
	MSG_CSM_DESTROYED			= 0x6400, /**< CSM destroyed */
	MSG_CSM_DESTROY_NOTIFY		= 0x6402, /**< CSM will be destroyed */
	
	/* GUI */
	MSG_GUI_DESTROYED			= 0x640E, /**< GUI destroyed */
	MSG_IDLETMR_EXPIRED			= 0x6401, /**< IDLE timer expired */
#else
	/* CALLS */
	MSG_INCOMMING_CALL			= 0x08, /**< Incoming call */
	MSG_STATE_OF_CALL			= 0x0B, /**< State of the call */
	MSG_END_CALL				= 0x0D, /**< End of the call */
	
	/* HELPER */
	MSG_HELPER_TRANSLATOR		= 0x3F0, /**< Translated msg from HELPER to MMI */
	MSG_RECONFIGURE_REQ			= 0x3F1, /**< Config chaged (BCFG Editor) */
	MSG_IPC						= 0x3F2, /**< ELFs IPC message */
	
	/* SMS */
	MSG_SMS_TX					= 0xC1, /**< Outgoint SMS */
	MSG_SMS_RX					= 0xC2, /**< Incoming SMS */
	
	/* USSD */
	MSG_USSD_RX					= 0x42, /**< USSD result */
	MSG_AUTOUSSD_RX				= 0x45, /**< USSD result (???) */
	
	/* AUDIO */
#ifdef X75
	MSG_PLAYFILE_REPORT			= 0x174, /**< PlayFile status reporting */
#else
	MSG_PLAYFILE_REPORT			= 0x167, /**< PlayFile status reporting */
#endif
	
	/* CSM */
	MSG_CSM_DESTROYED			= 0x93, /**< CSM destroyed */
	MSG_CSM_DESTROY_NOTIFY		= 0x92, /**< CSM will be destroyed */
	
	/* GUI */
	MSG_GUI_DESTROYED			= 0x98, /**< GUI destroyed */
	MSG_IDLETMR_EXPIRED			= 0x95, /**< IDLE timer expired */
#endif
};

/**
 * GBS Message.
 * */
struct GBS_MSG {
#ifdef NEWSGOLD
	int pid_from;	/**< Sender cepid */
	int msg;		/**< Message ID */
#else
	short pid_from;	/**< Sender cepid */
	short msg;		/**< Message ID */
#endif
	int submess;	/**< Sub message ID */
	void *data0;	/**< Custom payload */
	void *data1;	/**< Custom payload */
};

/**
 * GBS Timer.
 * */
struct GBSTMR {
	int param0; /**< Internal timer data, do not change */
	int param1; /**< Internal timer state, do not change */
	int param2; /**< Custom user param */
	int param3; /**< Custom user param */
	int param4; /**< Custom user param */
	int param5; /**< Custom user param */
	int param6; /**< Custom user param */
};

/**
 * Message for #MSG_IPC
 * */
struct IPC_REQ {
	const char *name_to;		/**< IPC receiver */
	const char *name_from;		/**< IPC sender */
	void *data;					/**< IPC payload */
};

/**
 * Process group definition.
 * */
struct PGROUP {
#ifdef NEWSGOLD
	uint32_t id;			/**< Process group ID (first byte of CEPID) */
	char *name;				/**< Nucleus task name */
	uint16_t prio;			/**< Nucleus task priority */
	uint16_t stacksize; 	/**< Nucleus task stack size */
	uint32_t maxmembers;	/**< Maximum members in the group */
#else
	uint8_t id;				/**< Process group ID (first byte of CEPID) */
	uint8_t prio;			/**< Nucleus task priority */
	uint16_t stacksize;		/**< Nucleus task stack size */
	uint16_t maxmembers;	/**< Maximum members in the group */
#endif
};

/**
 * @name Timers
 * @{
 * */

/**
 * Get current CEPID.
 * @return cepid number
 * */
__swi_begin(0x145)
int GBS_GetCurCepid(void)
__swi_end(0x145, GBS_GetCurCepid, ());

/**
 * Start GBS timer with callback.
 * @param timer		pointer to the GBS timer
 * @param ticks		number of ticks to expire the timer (1 tick - 4.615 ms)
 * @param callback	timer expire callback
 * */
__swi_begin(0x04D)
void GBS_StartTimerProc(GBSTMR *timer, long ticks, GBSTMR_CALLBACK callback)
__swi_end(0x04D, GBS_StartTimerProc, (timer, ticks, callback));

/**
 * Start GBS timer with callback.
 * @param timer		pointer to the GBS timer
 * @param ticks		number of ticks to expire the timer (1 tick - 4.615 ms)
 * @param msg_id	ID of the GBS message that will be sent when the timer expires
 * @param unk		unknown
 * @param cepid		destination CEPID
 * */
__swi_begin(0x143)
void GBS_StartTimer(GBSTMR *timer, int ticks, int msg_id, int unk, int cepid)
__swi_end(0x143, GBS_StartTimer, (timer, ticks, msg_id, unk, cepid));

/**
 * Check if timer is not yet expired.
 * @param timer		pointer to the GBS timer
 * @return 1: not expired, 0: expired
 * */
__swi_begin(0x1A6)
int IsTimerProc(GBSTMR *timer)
__swi_end(0x1A6, IsTimerProc, (timer));

/**
 * Stop active timer.
 * @param timer		pointer to the GBS timer
 * */
__swi_begin(0x144)
void GBS_StopTimer(GBSTMR *timer)
__swi_end(0x144, GBS_StopTimer, (timer));

/**
 * Delete timer.
 * @param timer		pointer to the GBS timer
 * */
__swi_begin(0x18C)
void GBS_DelTimer(GBSTMR *timer)
__swi_end(0x18C, GBS_DelTimer, (timer));

/** @} */

/**
 * @name Messages
 * @{
 * */

/**
 * Send message to the GBS event processor.
 * You can pass up to 3 additional parameters (submsg, data0, data1 - see #GBS_MSG).
 * @param cepid		destination CEPID.
 * @param msg		ID of the message
 */
#ifdef SWILIB_MODE_DIRECT
#define GBS_SendMessage(_cepid, _msg, ...) \
	__swi_call(0x100, void, (int cepid, int msg, ...), (_cepid, _msg, ## __VA_ARGS__));
#else
__swi_begin(0x100)
void GBS_SendMessage(int cepid, int msg, ...)
__swi_end(0x100, GBS_SendMessage, (cepid, msg)); // (int cepid, int msg, int submess, void *data0, void *data1)
#endif

/**
 * Receive GBS message inside GBS processor.
 * @param msg	pointer where the received message will be stored
 * @return count of messages in the queue
 * */
__swi_begin(0x101)
int GBS_ReciveMessage(GBS_MSG *msg)
__swi_end(0x101, GBS_ReciveMessage, (msg));

/**
 * Receive a message from the queue without auto-ACK.
 * @param msg	pointer where the received message will be stored
 * @return count of messages in the queue
 * */
__swi_begin(0x153)
int GBS_RecActDstMessage(GBS_MSG *msg)
__swi_end(0x153, GBS_RecActDstMessage, (msg));

/**
 * ACK message received with #GBS_RecActDstMessage
 * */
__swi_begin(0x102)
void GBS_AcceptMessage(void)
__swi_end(0x102, GBS_AcceptMessage, ());

/**
 * NACK message received with #GBS_RecActDstMessage
 * */
__swi_begin(0x103)
void GBS_ClearMessage(void)
__swi_end(0x103, GBS_ClearMessage, ());

/**
 * Pend the message for future processing.
 * @param msg	pointer to the #GBS_MSG
 * */
__swi_begin(0x104)
void GBS_PendMessage(const GBS_MSG *msg)
__swi_end(0x104, GBS_PendMessage, (msg));

/**
 * Destroy GSB_MSG object.
 * @param msg	pointer to the #GBS_MSG
 * */
__swi_begin(0x232)
void GBS_DestroyMessage(GBS_MSG *msg)
__swi_end(0x232, GBS_DestroyMessage, (msg));

/**
 * Wait for the GBS messages.
 * @param msg_list			list of message IDs to wait for
 * @param msgs_num			count message IDs in `msg_list`
 * @param msgs				pointer where the received messages will be stored (array of `msgs_num` items)
 * @param timeout_ticks		timeout for receiving (1 tick - 4.615 ms)
 * @return number of received messages
 * */
__swi_begin(0x185)
int GBS_WaitForMsg(const int *msg_list, int msgs_num, GBS_MSG *msgs, int timeout_ticks)
__swi_end(0x185, GBS_WaitForMsg, (msg_list, msgs_num, msgs, timeout_ticks));

/** @} */

/**
 * @name Event processors
 * @{
 * */

/**
 * Create GBS Event Processor
 * @param cepid		CEPID of this event processor
 * @param name		name of the event processor
 * @param callback	callback for the message
 * @param prio		priority of the event processor
 * @param unk		set to 0
 * */
__swi_begin(0x105)
void CreateGBSproc(int cepid, const char *name, GBS_PROC_CALLBACK callback, int prio, int unk)
__swi_end(0x105, CreateGBSproc, (cepid, name, callback, prio, unk));

/**
 * Delete GBS Event Processor
 * @param cepid		CEPID of event processor for deletion
 * */
__swi_begin(0x154)
void KillGBSproc(int cepid)
__swi_end(0x154, KillGBSproc, (cepid));

/**
 * Get address of the GBS event processor.
 * @param cepid		CEPID of event processor
 * @return pointer
 * */
__swi_begin(0x385)
void* GetGBSProcAddress(short cepid)
__swi_end(0x385, GetGBSProcAddress, (cepid));

/**
 * Create new GBS Process Group.
 * @param pgroup		process group definition
 * */
__swi_begin(0x38E)
void CreateICL(PGROUP *pgroup)
__swi_end(0x38E, CreateICL, (pgroup));

/**
 * Create new GBS Process Group Resource.
 * @param mask			resource mask (???)
 * @param unk_zero		set to 0
 * @param pgroup		process group config
 * @param size			size of the resource
 * */
__swi_begin(0x38F)
void *GBS_CreateProcessGroupResource(int mask, int unk_zero, PGROUP *pgroup, int size)
__swi_end(0x38F, GBS_CreateProcessGroupResource, (mask, unk_zero, pgroup, size));

/**
 * Get current GBS task.
 * @return pointer to the GBS task
 * */
__swi_begin(0x390)
void *GBS_GetCurrentTask()
__swi_end(0x390, GBS_GetCurrentTask, ());

/**
 * Alloc memory in the given memory pool.
 * @param pool		memory pool
 * @param size		requested memory size
 * @return pointer to the allocated memory
 * */
__swi_begin(0x391)
void *MemMBPAlloc(void *pool, int size)
__swi_end(0x391, MemMBPAlloc, (pool, size));

/**
 * Free memory allocated with #MemMBPAlloc.
 * @param pool		memory pool
 * @param ptr		pointer to the allocated memory
 * */
__swi_begin(0x392)
void MemMBPFree(void *pool, void *ptr)
__swi_end(0x392, MemMBPFree, (pool, ptr));

/**
 * Pointer to the MOPI memory pool.
 * @return pointer
 * */
__swi_begin(0x8393)
void *RamMopiResourcePool()
__swi_end(0x8393, RamMopiResourcePool, ());

/** @} */

__swilib_end

/** @} */
