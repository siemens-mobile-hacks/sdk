#pragma once

/**
 * @addtogroup CSM
 * @brief Functions for working with CSM.
 * CSM is something like application window.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/csm.h>`
 * @{
 */

#ifndef __IN_SWILIB__
#include "base.h"
#include "wstring.h"
#include "gbs.h"
#endif

__swilib_begin

#define NAMECSM_MAGIC1 ((malloc_func_t) 0x55AACCCC)		/**< CSM title magic for XTask */
#define NAMECSM_MAGIC2 ((mfree_func_t) 0x3333AA55)		/**< CSM title magic for XTask */

typedef struct CSM_DESC CSM_DESC;
typedef struct CSM_RAM CSM_RAM;
typedef struct CSMQ CSMQ;
typedef struct CSMROOT CSMROOT;
typedef struct MMICMD MMICMD;

/**
 * States of the CSM.
 * */
enum CSMState {
	CSM_STATE_OPEN		= 0,	/**< CSM created */
	CSM_STATE_CLOSED	= -3,	/**< CSM closed */
};

/**
 * CSM object.
 * */
struct CSM_RAM {
	void *next;			/**< Pointer to the next #CSM_RAM */
	void *prev;			/**< Pointer to the prev #CSM_RAM */
	CSM_DESC *constr;	/**< CSM description */
	int id;				/**< CSM ID */
	int state;			/**< CSM state, see #CSMState */
	int unk1;
	int unk2;
	LLQ gui_ll;			/**< Linked list of the GUI in this CSM. */
};

/**
 * CSM description.
 * */
struct CSM_DESC {
	int (*onMessage)(CSM_RAM *, GBS_MSG *);	/**< Callback for GBS messages. */
	void (*onCreate)(CSM_RAM *);				/**< CSM constructor */
#ifdef NEWSGOLD
	int zero1;		/**< Unknown, set to 0 */
	int zero2;		/**< Unknown, set to 0 */
	int zero3;		/**< Unknown, set to 0 */
	int zero4;		/**< Unknown, set to 0 */
#endif
	void (*onClose)(CSM_RAM *);				/**< CSM destructor */
	int datasize;							/**< Size of the CSM with custom payload */
	int statesize;							/**< Set to 1 */
	const int *states;						/**< Pointer to the `int minus11 = -11;` */
};

/**
 * Lists of the CSM.
 * */
#ifdef NEWSGOLD
struct CSMQ {
	int id;
	CSM_RAM *current_msg_processing_csm;	/**< Active CSM */
	LLQ csm;								/**< CSM Linked-List */
	LLQ cmd;
	LLQ csm_background;
};
#else
struct CSMQ {
	int id;
	CSM_RAM *current_msg_processing_csm;	/**< Active CSM */
	LLQ csm;								/**< CSM Linked-List */
	LLQ cmd;
	int unk;
	int unk1;
	void *methods;
	int unk2;
	void *tmr;
	short cepid;
};
#endif

/**
 * Root of the all CSM.
 * */
struct CSMROOT {
	int under_idle_id;	/**< Unknown CSM ID */
	int idle_id;		/**< Idle CMS ID */
	CSMQ *csm_q;		/**< Lists of the CSM */
};

/**
 * MMI command for safe and seq operations with CSM.
 * */
struct MMICMD {
#ifdef NEWSGOLD
	void *next;						/**< Next command */
	void *prev;						/**< Prev command */
	int flag1;
	int parent_id;					/**< Previous CSM ID or -1 */
	int prio;						/**< Command priority */
	int (*proc)(CSMQ *, void *);	/**< Command handler */
	CSMQ *csm_q;					/**< CSM queue */
	int id;							/**< CSM ID */
	int flag2;
#else
	void *next;						/**< Next command */
	void *prev;						/**< Prev command */
	char flag1;
	int parent_id;					/**< Previous CSM ID or -1 */
	int (*proc)(CSMQ *, void *);	/**< Command handler */
	CSMQ *csm_q;					/**< CSM queue */
	CSM_RAM *cmd_csm;				/**< CSM */
#endif
};

/**
 * Get the CSM root.
 * @return pointer to the root
 * */
__swi_begin(0x8106)
CSMROOT *CSM_root()
__swi_end(0x8106, CSM_root, ());

/**
 * Create new CSM.
 * @param descr		pointer to the #CSM_DESC
 * @param csm		pointer to the #CSM_RAM with default values
 * @param unk		set to 0
 * @return CSM ID
 * */
__swi_begin(0x107)
int CreateCSM(const CSM_DESC *descr, const void *csm, int unk)
__swi_end(0x107, CreateCSM, (descr, csm, unk));

/**
 * Find CSM by ID.
 * @param id	CSM ID
 * @return pointer to the CSM object or NULL
 * */
__swi_begin(0x108)
CSM_RAM *FindCSMbyID(int id)
__swi_end(0x108, FindCSMbyID, (id));

/**
 * Find CSM by ID in the given list.
 * @param csm_q		pointer to the CSM list
 * @param id		CSM ID
 * @return pointer to the CSM object or NULL
 * */
__swi_begin(0x142)
CSM_RAM *FindCSM(CSMQ *csm_q, int id)
__swi_end(0x142, FindCSM, (csm_q, id));

/**
 * Close CSM by ID.
 * @param id	CSM ID
 * */
__swi_begin(0x1FC)
void CloseCSM(int id)
__swi_end(0x1FC, CloseCSM, (id));

__swilib_end

/** @} */
