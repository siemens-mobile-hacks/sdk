#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#include "wstring.h"
#endif

__swilib_begin

/**
 * @addtogroup Telephony
 * @brief SMS, calls, USSD and others.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/telephony.h>`
 * @{
 */

typedef struct RAMNET RAMNET;
typedef struct PDU PDU;
typedef struct StructUSSDStr StructUSSDStr;
typedef struct StructUSSD StructUSSD;
typedef struct GBS_USSD_MSG GBS_USSD_MSG;
typedef struct SMS_POS_INDEX_DATA SMS_POS_INDEX_DATA;
typedef struct INDEX_ID_DATA INDEX_ID_DATA;
typedef struct SMS_DATA_LIST SMS_DATA_LIST;
typedef struct SMS_DATA_LLIST SMS_DATA_LLIST;
typedef struct SMS_DATA_ROOT SMS_DATA_ROOT;
typedef struct EAM_DATA EAM_DATA;
typedef struct RAM_EMS_ADMIN RAM_EMS_ADMIN;

/**
 * USSD reply GSB message.
 * */
#ifdef NEWSGOLD
struct GBS_USSD_MSG {
	int pid_from;		/**< cepid of the sender */
	int msg;			/**< #MSG_USSD_RX */
	void *pkt;			/**< USSD reply packet */
	char unk1;
	char encoding_type;	/**< Encoding of the USSD reply packet */
	char pkt_length;	/**< Size of the USSD reply packet */
	char unk2;
	void *data1;
};
#else
struct GBS_USSD_MSG {
	short pid_from;		/**< cepid of the sender */
	short msg;			/**< #MSG_USSD_RX */
	void *pkt;			/**< USSD reply packet */
	char unk1;
	char encoding_type;	/**< Encoding of the USSD reply packet */
	char pkt_length;	/**< Size of the USSD reply packet */
	char unk2;
	void *data1;
};
#endif

/**
 * Cellular network state (http://e71.ru/publ/4-1-0-34).
 * */
struct RAMNET {
	uint16_t ch_number;	/**< GSM channel number */
	uint16_t ci;		/**< Cell Identity */
	uint16_t lac;		/**< Local Area Code */
	char power;			/**< Signal power */
	char c1;
	char c2;
	char unk;
	uint16_t unk2;
};

/**
 * SMS PDU.
 * */
struct PDU {
	char data[0xB2]; /**< Raw PDU bytes */
};

/**
 * USSD request.
 * */
struct StructUSSDStr {
	uint32_t type;		/**< Type of the USSD */
	uint32_t param2;
	uint16_t param3;
	uint16_t wstr[25];	/**< USSD number in UTF-16 */
};

/**
 * USSD request (???).
 * */
struct StructUSSD {
	void *p1;
	void *p2;
	StructUSSDStr *pussdstr;
};

/**
 * SMS position index.
 * */
struct SMS_POS_INDEX_DATA {
	char unk0;
	char unk1;
	short pos_index;
};

/**
 * SMS index data.
 * */
struct INDEX_ID_DATA {
	void *unk_proc0; // 0xA09D901D S7Cv47
	void *unk_proc1; // 0xA09D9025 S7Cv47
	short index; // 1,2,3 ...
	char unk[6];
	short unk1; // another index ?
	char cnt_all;
	char cnt_received; // =cnt0;
	uint16_t *data_id; // depend on cnt, for GetSmsPosIndex to get pos_index
	short unk2; // 0, 0x700
	short unk3; // 0
	char unk4; // 3
	char unk5; // 0, 3
	char type; // 0, in read, 1, in new, 3,sent
	char new_cnt_data; // ?
};

/**
 * Container of the SMS data.
 * */
struct SMS_DATA_LIST {
	void *next;
	void *prev;
	INDEX_ID_DATA *index_id_data;
	// short unk0; //0xB2 pdu_size ?
	// short unk1; //0x4077 SMS_SIMIF_SM_CEPID ?
	// int unk2; //0x190 ?
	// void *unk3; //a list ?
};

/**
 * Linked-List of SMS (Openwave).
 * */
struct SMS_DATA_LLIST {
	SMS_DATA_LIST *first;	/**< Pointer to the first SMS */
	SMS_DATA_LIST *last;	/**< Pointer to the last SMS */
	void *unk_proc;			// 0xA09DA18D // S7Cv47
};

/**
 * Root of the SMS list (Openwave).
 * */
struct SMS_DATA_ROOT {
	SMS_DATA_LLIST in_msg;		/**< List of the incoming SMS */
	SMS_DATA_LLIST out_msg;		/**< List of the outgoing SMS */
	short unk_0xFFFF;
	short unk_0_1;
	short cnt_msg_in_read;		/**< Count of the incoming SMS. */
	short cnt_in_new_sms_dat;	/**< Count of the unread SMS. */
	short cnt_in_new_opwv;		//? ems ?
	short cnt_sms_sent;			/**< Count of the sent SMS. */
	short cnt_sms_draft;		/**< Count of the unsent SMS (drafts). */
	short unk_0_2;
	short cnt_freespace_data;	// -0x28 == ?
	short cnt_in_data;			/**< Incoming SMS segments */
	short cnt_new_in_data;		/**< Incoming unread SMS segments */
	short cnt_sent_data;		/**< Outgoing SMS segments */
	short cnt_draft_data;		/**< Outgoing unsent SMS segments (drafts) */
	short unk_0_3;				// maybe sending box
};

/**
 * EMS Admin data.
 * */
struct EAM_DATA {
	short dat_index;
	char unk_FF[2];
	int opmsg_id; // browser killer, -1
	char unk[8];
};

/**
 * EMS Admin.
 * */
struct RAM_EMS_ADMIN {
//	char unk_FF[0x10];
	int unk;
	EAM_DATA data[101];
};

/**
 * Call the number.
 * @param number	phone number
 * @param unk1		unknown, set to 0x10
 * @param unk2		unknown, set to 0x20C0
 * @return 0 or error
 * */
__swi_begin(0x170)
int MakeVoiceCall(const char *number, int unk1, int unk2)
__swi_end(0x170, MakeVoiceCall, (number, unk1, unk2));

/**
 * Get SMS status.
 * @return 1 - send, 2 - recv, 3 - both
 * */
__swi_begin(0x286)
int GetSMSState()
__swi_end(0x286, GetSMSState, ());

/**
 * Check for new SMS.
 * @return 1: when there has new SMS
 * @return 0: no new SMS
 * */
__swi_begin(0x046)
int HasNewSMS(void)
__swi_end(0x046, HasNewSMS, ());

/**
 * Check for new flash-SMS.
 * @return 1: non-zero when there has new flash-SMS
 * @return 0: no new flash-SMS
 * */
__swi_begin(0x047)
int HasFlashSMS(void)
__swi_end(0x047, HasFlashSMS, ());

/**
 * Pointer to the for missed SMS count.
 * @return pointer to the count
 * ```C
 * int missed_sms = *RamMissedSMS();
 * ```
 * */
__swi_begin(0x80CD)
char *RamMissedSMS()
__swi_end(0x80CD, RamMissedSMS, ());

/**
 * Pointer to the for missed messages count.
 * @return pointer to the count
 * ```C
 * int missed_sms = *RamMissedMessage();
 * ```
 * */
__swi_begin(0x80D4)
char *RamMissedMessage()
__swi_end(0x80D4, RamMissedMessage, ());

/**
 * Check for missed calls.
 * @return count of the missed calls
 * */
__swi_begin(0x04C)
int GetMissedCallsCount(void)
__swi_end(0x04C, GetMissedCallsCount, ());

/**
 * Pointer to the for missed calls count.
 * @return pointer to the count
 * ```C
 * int missed_calls = *RamMissedCalls();
 * ```
 * */
__swi_begin(0x80CC)
char *RamMissedCalls()
__swi_end(0x80CC, RamMissedCalls, ());

/**
 * Checking for an active call.
 * @return count of active calls
 * */
__swi_begin(0x06E)
int IsCalling(void)
__swi_end(0x06E, IsCalling, ());

/**
 * Get current call diration.
 * @return seconds
 * */
__swi_begin(0x072)
int GetDurationFromCurrentCall(void)
__swi_end(0x072, GetDurationFromCurrentCall, ());

/**
 * Check if current call in decryption state.
 * @return 1 or 0
 * */
__swi_begin(0x289)
int isDecryption(void)
__swi_end(0x289, isDecryption, ());

/**
 * Checking if current call don't have number.
 * @return 1 or 0
 * */
__swi_begin(0x07D)
int IsIncognitoCall(void)
__swi_end(0x07D, IsIncognitoCall, ());

/**
 * Checking for an active direct call.
 * @return 1 or 0
 * */
__swi_begin(0x067)
int IsDirectCallActive(void)
__swi_end(0x067, IsDirectCallActive, ());

/**
 * State of the current call.
 * @return unknown
 * */
__swi_begin(0x8290)
char *RamCallState()
__swi_end(0x8290, RamCallState, ());

/**
 * Get type of the current call.
 * @param type	unknown, set to 1
 * @return 0 - none, 2 - outgoing, 3 - incoming
 * */
__swi_begin(0x073)
int GetTypeOfCall(int type)
__swi_end(0x073, GetTypeOfCall, (type));

/**
 * Open calls list phone UI.
 * @param list	type of the list
 * @param zero	unknown, set to 0
 * @return CSM ID of opened UI
 * */
__swi_begin(0x080)
int ShowCallList(int list, int zero)
__swi_end(0x080, ShowCallList, (list, zero));

/**
 * Cancel current call.
 * */
__swi_begin(0x065)
void EndCall(void)
__swi_end(0x065, EndCall, ());

/**
 * Cancel current call with BUSY status.
 * @param param1	unknown
 * @param param2	unknown
 * */
__swi_begin(0x066)
void EndCallBusy(int param1, int param2)
__swi_end(0x066, EndCallBusy, (param1, param2));

/**
 * Pointer to the number from the last call.
 * @return unknown
 * */
__swi_begin(0x8253)
char *RamLastCallNum()
__swi_end(0x8253, RamLastCallNum, ());

/**
 * Get IMSI of the SIM card.
 * @return pointer to the 9-bytes of IMSI
 * */
__swi_begin(0x81EB)
char *RAM_IMSI(void)
__swi_end(0x81EB, RAM_IMSI, ());

/**
 * Get cellurar operator name.
 * @return FF-terminated C-string
 * */
__swi_begin(0x81F4)
char *RamServiceProviderName(void)
__swi_end(0x81F4, RamServiceProviderName, ());

/**
 * Current cellular network state.
 * @return pointer to the network state
 * */
__swi_begin(0x80CA)
RAMNET *RamNet()
__swi_end(0x80CA, RamNet, ());

/**
 * Check if cellular network is online.
 * @return 1 or 0
 * */
__swi_begin(0x80D6)
RAMNET *RamNetOnline()
__swi_end(0x80D6, RamNetOnline, ());

/**
 * Get current network access mode.
 * @return mdoe
 * */
__swi_begin(0x0051)
int GetNetAccessMode()
__swi_end(0x0051, GetNetAccessMode, ());

/**
 * Get network roaming status.
 * @return roaming status
 * */
__swi_begin(0x2C3)
int GetRoamingState()
__swi_end(0x2C3, GetRoamingState, ());

/**
 * Get current network cell identification.
 * @return pointer to the CI.
 * 
 * ```C
 * uint16_t CI = *GetCI();
 * ```
 * */
__swi_begin(0x810D)
uint16_t *GetCI()
__swi_end(0x810D, GetCI, ());

/**
 * Get cell network MCC & MNC.
 * @return pointer to the char[5] array with BCD representation of MCC + MNC
 * */
__swi_begin(0x1A7)
char *Get_CC_NC()
__swi_end(0x1A7, Get_CC_NC, ());

/**
 * Get name of the current cellurar provider.
 * @param[out] name		name of the provider
 * @param unk			set to 0
 * @return 1: success, 0: error
 * */
__swi_begin(0x041)
char GetProvider(WSHDR *name, int unk)
__swi_end(0x041, GetProvider, (name, unk));

/**
 * Get name of the current cellurar sub-provider.
 * @param[out] name		name of the sub-provider
 * @return 1: success, 0: error
 * */
__swi_begin(0x2C2)
int GetSubprovider(WSHDR* name)
__swi_end(0x2C2, GetSubprovider, (name));

/**
 * Get type of the current USSD request.
 * @return unknown
 * */
__swi_begin(0x111)
char GetTypeUSSD()
__swi_end(0x111, GetTypeUSSD, ());

/**
 * Set current USSD request.
 * @param req	pointer to the USSD request
 * @return 1 on success, 0 on error
 * */
__swi_begin(0x112)
uint32_t SetUSSD(const StructUSSDStr *req)
__swi_end(0x112, SetUSSD, (req));

/**
 * Send auto-ACK for the current USSD.
 * */
__swi_begin(0x238)
void SendAutoUSSDack(void)
__swi_end(0x238, SendAutoUSSDack, ());

/**
 * Free current USSD request.
 * */
__swi_begin(0x10F)
void freeUSSD()
__swi_end(0x10F, freeUSSD, ());

/**
 * Send SMS.
 * @param text		text of the SMS
 * @param number	receiver number
 * @param cepid		set to #MMI_CEPID
 * @param msg		set to #MSG_SMS_TX
 * @param flag		unknown, set to 6
 * @return non-zero on success
 * */
__swi_begin(0x1DA)
int SendSMS(WSHDR *text, const char *number, int cepid, int msg, int flag)
__swi_end(0x1DA, SendSMS, (text, number, cepid, msg, flag));

/**
 * Get PDU from the received SMS message (in #MSG_SMS_RX event).
 * @return pointer to the PDU
 * */
__swi_begin(0x81DB)
PDU *IncommingPDU(void)
__swi_end(0x81DB, IncommingPDU, ());

/**
 * Remove SMS from memory (Openwave).
 * @param index				index of the SMS
 * @param[out]	del_cnt		number of deleted segments
 * @return 0x3E8 on success
 * */
__swi_begin(0x2AC)
int DeleteSMS(int index, short *del_cnt)
__swi_end(0x2AC, DeleteSMS, (index, del_cnt));

/**
 * Update SMS status (Openwave).
 * @param index			index of the SMS
 * @param status		new SMS status (1: read, 3: unread)
 * @return 0x3E8 on success
 * */
__swi_begin(0x2AD)
int SetSmsStatus(int index, int status)
__swi_end(0x2AD, SetSmsStatus, (index, status));

/**
 * Get root of the SMS list (Openwave).
 * @return pointer to #SMS_DATA_ROOT
 * */
__swi_begin(0x82B1)
SMS_DATA_ROOT *SmsDataRoot()
__swi_end(0x82B1, SmsDataRoot, ());

/**
 * Get SMS position index (#SMS_POS_INDEX_DATA) by data ID.
 * @return 1: success, 0: error
 * */
__swi_begin(0x2B2)
int GetSmsPosIndex(SMS_POS_INDEX_DATA *buf, int data_id)
__swi_end(0x2B2, GetSmsPosIndex, (buf, data_id));

/**
 * Get pointer to the EMS Admin data.
 * @return pointer to #RAM_EMS_ADMIN
 * */
__swi_begin(0x82C5)
RAM_EMS_ADMIN *RAM_EMS_Admin()
__swi_end(0x82C5, RAM_EMS_Admin, ());

/**
 * Decode GSM-encoded text.
 * @param[out] result		result of the decoding
 * @param pkt				input GSM-encoded data
 * @param len				length of the input
 * @param encoding_type		type of the encoding
 * @param malloc_fn			result of #malloc_adr()
 * @param mfree_fn			result of #mfree_adr()
 * @return 1: success, 0: error
 * */
__swi_begin(0x21D)
int GSMTXT_Decode(WSHDR *result, void *pkt, int len, int encoding_type, malloc_func_t malloc_fn, mfree_func_t mfree_fn)
__swi_end(0x21D, GSMTXT_Decode, (result, pkt, len, encoding_type, malloc_fn, mfree_fn));

/**
 * Free USSD response packet.
 * */
__swi_begin(0x22A)
void FreeGSMTXTpkt(void *pkt)
__swi_end(0x22A, FreeGSMTXTpkt, (pkt));

/**
 * Open new received SMS in SMS UI.
 * */
__swi_begin(0x048)
void ReadNewSMS()
__swi_end(0x048, ReadNewSMS, ());

/**
 * Open new received flash SMS in SMS UI.
 * */
__swi_begin(0x049)
void ReadFlashSMS()
__swi_end(0x049, ReadFlashSMS, ());

/**
 * Starts "opwvmsg:RGetAllEmail" in Openwave.
 * */
__swi_begin(0x233)
void GetAllEmail()
__swi_end(0x233, GetAllEmail, ());

__swilib_end

/** @} */
