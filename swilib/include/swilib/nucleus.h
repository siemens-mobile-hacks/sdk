#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

/**
 * @addtogroup NUCLEUS
 * @brief Functions for working with Nucleus RTOS.
 * 
 * Usage: `#include <swilib/nucleus.h>` or `#include <nu_swilib.h>`
 * @{
 */

#define NU_SWILIB_BEGIN_NUMBER	0x300

typedef unsigned long			UNSIGNED;
typedef long					SIGNED;
typedef unsigned char			DATA_ELEMENT;
typedef DATA_ELEMENT			OPTION;
typedef int						STATUS;
typedef unsigned char			UNSIGNED_CHAR;
typedef char					CHAR;
typedef int						INT;
typedef unsigned long *			UNSIGNED_PTR;
typedef unsigned char *			BYTE_PTR;
typedef DATA_ELEMENT			BOOLEAN;
typedef unsigned int			UNSIGNED_INT;

#define VOID void

/* Define constants that are target dependent and/or are used for internal
   purposes.  */

#define NU_MIN_STACK_SIZE				240
#define NU_MAX_NAME						8
#define NU_MAX_VECTORS					64
#define NU_MAX_LISRS					8

/* Sizes of the structures. */
#define NU_TASK_SIZE					42 + 4
#define NU_HISR_SIZE					22 + 4
#define NU_MAILBOX_SIZE					13 + 4
#define NU_QUEUE_SIZE					18 + 50
#define NU_PIPE_SIZE					18 + 4
#define NU_SEMAPHORE_SIZE				10 + 4
#define NU_EVENT_GROUP_SIZE				9  + 4
#define NU_PARTITION_POOL_SIZE			15 + 4
#define NU_MEMORY_POOL_SIZE				17 + 4
#define NU_TIMER_SIZE					17 + 4
#define NU_PROTECT_SIZE					2  + 4
#define NU_DRIVER_SIZE					3  + 4

typedef struct NU_TASK_STRUCT {
	UNSIGNED words[NU_TASK_SIZE];
} NU_TASK;

typedef struct NU_MAILBOX_STRUCT {
	UNSIGNED words[NU_MAILBOX_SIZE];
} NU_MAILBOX;

typedef struct NU_QUEUE_STRUCT {
	UNSIGNED words[NU_QUEUE_SIZE];
} NU_QUEUE;

typedef struct NU_PIPE_STRUCT {
	UNSIGNED words[NU_PIPE_SIZE];
} NU_PIPE;

typedef struct NU_SEMAPHORE_STRUCT {
	UNSIGNED words[NU_SEMAPHORE_SIZE];
} NU_SEMAPHORE;

typedef struct NU_EVENT_GROUP_STRUCT {
	UNSIGNED words[NU_EVENT_GROUP_SIZE];
} NU_EVENT_GROUP;

typedef struct NU_PARTITION_POOL_STRUCT {
	UNSIGNED words[NU_PARTITION_POOL_SIZE];
} NU_PARTITION_POOL;

typedef struct NU_MEMORY_POOL_STRUCT {
	UNSIGNED words[NU_MEMORY_POOL_SIZE];
} NU_MEMORY_POOL;

typedef struct NU_HISR_STRUCT {
	UNSIGNED words[NU_HISR_SIZE];
} NU_HISR;

typedef struct NU_PROTECT_STRUCT {
	UNSIGNED words[NU_PROTECT_SIZE];
} NU_PROTECT;

typedef struct NU_TIMER_STRUCT {
	UNSIGNED words[NU_TIMER_SIZE];
} NU_TIMER;

/* Define I/O driver request structures.  */

struct NU_INITIALIZE_STRUCT {
	VOID		*nu_io_address;		/* Base IO address	*/
	UNSIGNED	nu_logical_units;	/* Number of logical units  */
	VOID		*nu_memory;			/* Generic memory pointer	*/
	INT			nu_vector;			/* Interrupt vector number  */
};

struct NU_ASSIGN_STRUCT {
	UNSIGNED	nu_logical_unit;	/* Logical unit number	*/
	INT			nu_assign_info;		/* Additional assign info	*/
};

struct NU_RELEASE_STRUCT {
	UNSIGNED	nu_logical_unit;	/* Logical unit number	*/
	INT			nu_release_info;	/* Additional release info  */
};

struct NU_INPUT_STRUCT {
	UNSIGNED	nu_logical_unit;	/* Logical unit number	*/
	UNSIGNED	nu_offset;			/* Offset of input	*/
	UNSIGNED	nu_request_size;	/* Requested input size	*/
	UNSIGNED	nu_actual_size;		/* Actual input size	*/
	VOID		*nu_buffer_ptr;		/* Input buffer pointer	*/
};

struct NU_OUTPUT_STRUCT {
	UNSIGNED	nu_logical_unit;	/* Logical unit number	*/
	UNSIGNED	nu_offset;			/* Offset of output	*/
	UNSIGNED	nu_request_size;	/* Requested output size	*/
	UNSIGNED	nu_actual_size;		/* Actual output size	*/
	VOID		*nu_buffer_ptr;		/* Output buffer pointer	*/
};

struct NU_STATUS_STRUCT {
	UNSIGNED	nu_logical_unit;	/* Logical unit number	*/
	VOID		*nu_extra_status;	/* Additional status ptr	*/
};

struct NU_TERMINATE_STRUCT {
	UNSIGNED	nu_logical_unit;	/* Logical unit number	*/
};

typedef  union NU_REQUEST_INFO_UNION {
	struct NU_INITIALIZE_STRUCT	nu_initialize;
	struct NU_ASSIGN_STRUCT		nu_assign;
	struct NU_RELEASE_STRUCT	nu_release;
	struct NU_INPUT_STRUCT		nu_input;
	struct NU_OUTPUT_STRUCT		nu_output;
	struct NU_STATUS_STRUCT		nu_status;
	struct NU_TERMINATE_STRUCT	nu_terminate;
} nu_request_info_union;

typedef struct NU_DRIVER_REQUEST_STRUCT {
	INT			nu_function;			/* I/O request function	*/
	UNSIGNED	nu_timeout;				/* Timeout on request	*/
	STATUS		nu_status;				/* Status of request	*/
	UNSIGNED	nu_supplemental;		/* Supplemental information */
	VOID		*nu_supplemental_ptr;	/* Supplemental info pointer*/
	nu_request_info_union nu_request_info;
} NU_DRIVER_REQUEST;

typedef struct NU_DRIVER_STRUCT {
	UNSIGNED	words[NU_DRIVER_SIZE];	/* CS_NODE_STRUCT */
	CHAR		nu_driver_name[NU_MAX_NAME];
	VOID		*nu_info_ptr;
	UNSIGNED	nu_driver_id;
	VOID		(*nu_driver_entry)(struct NU_DRIVER_STRUCT *, NU_DRIVER_REQUEST *);
} NU_DRIVER;

/* Task suspension constants.  */
#define NU_DRIVER_SUSPEND               10
#define NU_EVENT_SUSPEND                7
#define NU_FINISHED                     11
#define NU_MAILBOX_SUSPEND              3
#define NU_MEMORY_SUSPEND               9
#define NU_PARTITION_SUSPEND            8
#define NU_PIPE_SUSPEND                 5
#define NU_PURE_SUSPEND                 1
#define NU_QUEUE_SUSPEND                4
#define NU_READY                        0
#define NU_SEMAPHORE_SUSPEND            6
#define NU_SLEEP_SUSPEND                2
#define NU_TERMINATED                   12

/* Constants for use in service parameters.  */
#define NU_AND                          2
#define NU_AND_CONSUME                  3
#define NU_DISABLE_TIMER                4
#define NU_ENABLE_TIMER                 5
#define NU_FALSE                        0
#define NU_FIFO                         6
#define NU_FIXED_SIZE                   7
#define NU_NO_PREEMPT                   8
#define NU_NO_START                     9
#define NU_NO_SUSPEND                   0
#define NU_NULL                         0
#define NU_OR                           0
#define NU_OR_CONSUME                   1
#define NU_PREEMPT                      10
#define NU_PRIORITY                     11
#define NU_START                        12
#define NU_SUSPEND                      0xFFFFFFFFUL
#define NU_TRUE                         1
#define NU_VARIABLE_SIZE                13

/* Service completion status constants.  */
#define NU_SUCCESS						0
#define NU_END_OF_LOG					-1
#define NU_GROUP_DELETED				-2
#define NU_INVALID_DELETE				-3
#define NU_INVALID_DRIVER				-4
#define NU_INVALID_ENABLE				-5
#define NU_INVALID_ENTRY				-6
#define NU_INVALID_FUNCTION				-7
#define NU_INVALID_GROUP				-8
#define NU_INVALID_HISR					-9
#define NU_INVALID_MAILBOX				-10
#define NU_INVALID_MEMORY				-11
#define NU_INVALID_MESSAGE				-12
#define NU_INVALID_OPERATION			-13
#define NU_INVALID_PIPE					-14
#define NU_INVALID_POINTER				-15
#define NU_INVALID_POOL					-16
#define NU_INVALID_PREEMPT				-17
#define NU_INVALID_PRIORITY				-18
#define NU_INVALID_QUEUE				-19
#define NU_INVALID_RESUME				-20
#define NU_INVALID_SEMAPHORE			-21
#define NU_INVALID_SIZE					-22
#define NU_INVALID_START				-23
#define NU_INVALID_SUSPEND				-24
#define NU_INVALID_TASK					-25
#define NU_INVALID_TIMER				-26
#define NU_INVALID_VECTOR				-27
#define NU_MAILBOX_DELETED				-28
#define NU_MAILBOX_EMPTY				-29
#define NU_MAILBOX_FULL					-30
#define NU_MAILBOX_RESET				-31
#define NU_NO_MEMORY					-32
#define NU_NO_MORE_LISRS				-33
#define NU_NO_PARTITION					-34
#define NU_NOT_DISABLED					-35
#define NU_NOT_PRESENT					-36
#define NU_NOT_REGISTERED				-37
#define NU_NOT_TERMINATED				-38
#define NU_PIPE_DELETED					-39
#define NU_PIPE_EMPTY					-40
#define NU_PIPE_FULL					-41
#define NU_PIPE_RESET					-42
#define NU_POOL_DELETED					-43
#define NU_QUEUE_DELETED				-44
#define NU_QUEUE_EMPTY					-45
#define NU_QUEUE_FULL					-46
#define NU_QUEUE_RESET					-47
#define NU_SEMAPHORE_DELETED			-48
#define NU_SEMAPHORE_RESET				-49
#define NU_TIMEOUT						-50
#define NU_UNAVAILABLE					-51
#define NU_INVALID_DESCRIPTION			-52
#define NU_INVALID_REGION				-53
#define NU_MEMORY_CORRUPT				-54
#define NU_INVALID_DEBUG_ALLOCATION		-55
#define NU_EMPTY_DEBUG_ALLOCATION_LIST  -56

/* System errors.  */
#define NU_ERROR_CREATING_TIMER_HISR	1
#define NU_ERROR_CREATING_TIMER_TASK	2
#define NU_STACK_OVERFLOW				3
#define NU_UNHANDLED_INTERRUPT			4

/* I/O driver constants.  */
#define NU_IO_ERROR					-1
#define NU_INITIALIZE				1
#define NU_ASSIGN					2
#define NU_RELEASE					3
#define NU_INPUT					4
#define NU_OUTPUT					5
#define NU_STATUS					6
#define NU_TERMINATE				7

/* History entry IDs.  */
#define NU_USER_ID						1
#define NU_CREATE_TASK_ID				2
#define NU_DELETE_TASK_ID				3
#define NU_RESET_TASK_ID				4
#define NU_TERMINATE_TASK_ID			5
#define NU_RESUME_TASK_ID				6
#define NU_SUSPEND_TASK_ID				7
#define NU_RELINQUISH_ID				8
#define NU_SLEEP_ID						9
#define NU_CHANGE_PRIORITY_ID			10
#define NU_CHANGE_PREEMPTION_ID			11
#define NU_CREATE_MAILBOX_ID			12
#define NU_DELETE_MAILBOX_ID			13
#define NU_RESET_MAILBOX_ID				14
#define NU_SEND_TO_MAILBOX_ID			15
#define NU_BROADCAST_TO_MAILBOX_ID		16
#define NU_RECEIVE_FROM_MAILBOX_ID		17
#define NU_CREATE_QUEUE_ID				18
#define NU_DELETE_QUEUE_ID				19
#define NU_RESET_QUEUE_ID				20
#define NU_SEND_TO_FRONT_OF_QUEUE_ID	21
#define NU_SEND_TO_QUEUE_ID				22
#define NU_BROADCAST_TO_QUEUE_ID		23
#define NU_RECEIVE_FROM_QUEUE_ID		24
#define NU_CREATE_PIPE_ID				25
#define NU_DELETE_PIPE_ID				26
#define NU_RESET_PIPE_ID				27
#define NU_SEND_TO_FRONT_OF_PIPE_ID		28
#define NU_SEND_TO_PIPE_ID				29
#define NU_BROADCAST_TO_PIPE_ID			30
#define NU_RECEIVE_FROM_PIPE_ID			31
#define NU_CREATE_SEMAPHORE_ID			32
#define NU_DELETE_SEMAPHORE_ID			33
#define NU_RESET_SEMAPHORE_ID			34
#define NU_OBTAIN_SEMAPHORE_ID			35
#define NU_RELEASE_SEMAPHORE_ID			36
#define NU_CREATE_EVENT_GROUP_ID		37
#define NU_DELETE_EVENT_GROUP_ID		38
#define NU_SET_EVENTS_ID				39
#define NU_RETRIEVE_EVENTS_ID			40
#define NU_CREATE_PARTITION_POOL_ID		41
#define NU_DELETE_PARTITION_POOL_ID		42
#define NU_ALLOCATE_PARTITION_ID		43
#define NU_DEALLOCATE_PARTITION_ID		44
#define NU_CREATE_MEMORY_POOL_ID		45
#define NU_DELETE_MEMORY_POOL_ID		46
#define NU_ALLOCATE_MEMORY_ID			47
#define NU_DEALLOCATE_MEMORY_ID			48
#define NU_CONTROL_SIGNALS_ID			49
#define NU_RECEIVE_SIGNALS_ID			50
#define NU_REGISTER_SIGNAL_HANDLER_ID	51
#define NU_SEND_SIGNALS_ID				52
#define NU_REGISTER_LISR_ID				53
#define NU_CREATE_HISR_ID				54
#define NU_DELETE_HISR_ID				55
#define NU_CREATE_TIMER_ID				56
#define NU_DELETE_TIMER_ID				57
#define NU_CONTROL_TIMER_ID				58
#define NU_RESET_TIMER_ID				59
#define NU_CREATE_DRIVER_ID				60
#define NU_DELETE_DRIVER_ID				61
#define NU_REQUEST_DRIVER_ID			62
#define NU_RESUME_DRIVER_ID				63
#define NU_SUSPEND_DRIVER_ID			64
#define NU_CHANGE_TIME_SLICE_ID			65
#define NU_ASSERT_ID					66
#define NU_ALLOCATE_ALIGNED_ID			67

/**
 * @name Task control functions
 * @{
 * */
__swi_begin(0x300)
int NU_Create_Task(NU_TASK *task, CHAR *name,
					void (*task_entry)(int, void *), unsigned long argc,
					void *argv, void *stack_address, unsigned long stack_size,
					OPTION priority, unsigned long time_slice,
					OPTION preempt, OPTION auto_start)
__swi_end(0x300, NU_Create_Task, (task, name, task_entry, argc, argv, stack_address, stack_size, priority, time_slice, preempt, auto_start));


__swi_begin(0x301)
int NU_Delete_Task(NU_TASK *task)
__swi_end(0x301, NU_Delete_Task, (task));


__swi_begin(0x302)
int NU_Reset_Task(NU_TASK *task, unsigned long argc, void *argv)
__swi_end(0x302, NU_Reset_Task, (task, argc, argv));


__swi_begin(0x303)
int NU_Terminate_Task(NU_TASK *task)
__swi_end(0x303, NU_Terminate_Task, (task));


__swi_begin(0x304)
int NU_Resume_Task(NU_TASK *task)
__swi_end(0x304, NU_Resume_Task, (task));


__swi_begin(0x305)
int NU_Suspend_Task(NU_TASK *task)
__swi_end(0x305, NU_Suspend_Task, (task));


__swi_begin(0x306)
void NU_Relinquish(void)
__swi_end(0x306, NU_Relinquish, ());


__swi_begin(0x307)
void NU_Sleep(unsigned long ticks)
__swi_end(0x307, NU_Sleep, (ticks));


__swi_begin(0x308)
OPTION NU_Change_Priority(NU_TASK *task, OPTION new_priority)
__swi_end(0x308, NU_Change_Priority, (task, new_priority));


__swi_begin(0x309)
OPTION NU_Change_Preemption(OPTION preempt)
__swi_end(0x309, NU_Change_Preemption, (preempt));


__swi_begin(0x30A)
unsigned long NU_Change_Time_Slice(NU_TASK *task, unsigned long time_slice)
__swi_end(0x30A, NU_Change_Time_Slice, (task, time_slice));


__swi_begin(0x30B)
unsigned long NU_Check_Stack(void)
__swi_end(0x30B, NU_Check_Stack, ());


__swi_begin(0x30C)
NU_TASK  *NU_Current_Task_Pointer(void)
__swi_end(0x30C, NU_Current_Task_Pointer, ());


__swi_begin(0x30D)
unsigned long NU_Established_Tasks(void)
__swi_end(0x30D, NU_Established_Tasks, ());


__swi_begin(0x30E)
int NU_Task_Information(NU_TASK *task, CHAR *name,
						DATA_ELEMENT *status, unsigned long *scheduled_count,
						OPTION *priority, OPTION *preempt,
						unsigned long *time_slice, void **stack_base,
						unsigned long *stack_size, unsigned long *minimum_stack)
__swi_end(0x30E, NU_Task_Information, (task, name, status, scheduled_count, priority, preempt, time_slice, stack_base, stack_size, minimum_stack));


__swi_begin(0x30F)
unsigned long NU_Task_Pointers(NU_TASK **pointer_list, unsigned long maximum_pointers)
__swi_end(0x30F, NU_Task_Pointers, (pointer_list, maximum_pointers));

/** @} */

/**
 * @name Mailbox management functions
 * @{
 * */
__swi_begin(0x310)
int NU_Create_Mailbox(NU_MAILBOX *mailbox, CHAR *name, OPTION suspend_type)
__swi_end(0x310, NU_Create_Mailbox, (mailbox, name, suspend_type));


__swi_begin(0x311)
int NU_Delete_Mailbox(NU_MAILBOX *mailbox)
__swi_end(0x311, NU_Delete_Mailbox, (mailbox));


__swi_begin(0x312)
int NU_Reset_Mailbox(NU_MAILBOX *mailbox)
__swi_end(0x312, NU_Reset_Mailbox, (mailbox));


__swi_begin(0x313)
int NU_Send_To_Mailbox(NU_MAILBOX *mailbox, void *message, unsigned long suspend)
__swi_end(0x313, NU_Send_To_Mailbox, (mailbox, message, suspend));


__swi_begin(0x314)
int NU_Broadcast_To_Mailbox(NU_MAILBOX *mailbox, void *message, unsigned long suspend)
__swi_end(0x314, NU_Broadcast_To_Mailbox, (mailbox, message, suspend));


__swi_begin(0x315)
int NU_Receive_From_Mailbox(NU_MAILBOX *mailbox, void *message,
											  unsigned long suspend)
__swi_end(0x315, NU_Receive_From_Mailbox, (mailbox, message, suspend));


__swi_begin(0x316)
unsigned long NU_Established_Mailboxes(void)
__swi_end(0x316, NU_Established_Mailboxes, ());


__swi_begin(0x317)
int NU_Mailbox_Information(NU_MAILBOX *mailbox, CHAR *name,
							OPTION *suspend_type, OPTION *message_present,
							unsigned long *tasks_waiting, NU_TASK **first_task)
__swi_end(0x317, NU_Mailbox_Information, (mailbox, name, suspend_type, message_present, tasks_waiting, first_task));


__swi_begin(0x318)
unsigned long NU_Mailbox_Pointers(NU_MAILBOX **pointer_list,  unsigned long maximum_pointers)
__swi_end(0x318, NU_Mailbox_Pointers, (pointer_list, maximum_pointers));

/** @} */

/**
 * @name Queue management functions
 * @{
 * */
__swi_begin(0x319)
int NU_Create_Queue(NU_QUEUE *queue, CHAR *name,
					void *start_address, unsigned long queue_size,
					OPTION message_type, unsigned long message_size,
					OPTION suspend_type)
__swi_end(0x319, NU_Create_Queue, (queue, name, start_address, queue_size, message_type, message_size, suspend_type));


__swi_begin(0x31A)
int NU_Delete_Queue(NU_QUEUE *queue)
__swi_end(0x31A, NU_Delete_Queue, (queue));


__swi_begin(0x31B)
int NU_Reset_Queue(NU_QUEUE *queue)
__swi_end(0x31B, NU_Reset_Queue, (queue));


__swi_begin(0x31C)
int NU_Send_To_Front_Of_Queue(NU_QUEUE *queue, void *message,
								unsigned long size, unsigned long suspend)
__swi_end(0x31C, NU_Send_To_Front_Of_Queue, (queue, message, size, suspend));


__swi_begin(0x31D)
int NU_Send_To_Queue(NU_QUEUE *queue, void *message,
						unsigned long size, unsigned long suspend)
__swi_end(0x31D, NU_Send_To_Queue, (queue, message, size, suspend));


__swi_begin(0x31E)
int NU_Broadcast_To_Queue(NU_QUEUE *queue, void *message,
							unsigned long size, unsigned long suspend)
__swi_end(0x31E, NU_Broadcast_To_Queue, (queue, message, size, suspend));


__swi_begin(0x31F)
int NU_Receive_From_Queue(NU_QUEUE *queue, void *message,
							unsigned long size, unsigned long *actual_size, unsigned long suspend)
__swi_end(0x31F, NU_Receive_From_Queue, (queue, message, size, actual_size, suspend));


__swi_begin(0x320)
unsigned long NU_Established_Queues(void)
__swi_end(0x320, NU_Established_Queues, ());


__swi_begin(0x321)
int NU_Queue_Information(NU_QUEUE *queue, CHAR *name,
							void **start_address, unsigned long *queue_size,
							unsigned long *available, unsigned long *messages,
							OPTION *message_type, unsigned long *message_size,
							OPTION *suspend_type, unsigned long *tasks_waiting,
							NU_TASK **first_task)
__swi_end(0x321, NU_Queue_Information, (queue, name, start_address, queue_size, available, messages, message_type, message_size, suspend_type, tasks_waiting, first_task));


__swi_begin(0x322)
unsigned long NU_Queue_Pointers(NU_QUEUE **pointer_list,
								unsigned long maximum_pointers)
__swi_end(0x322, NU_Queue_Pointers, (pointer_list, maximum_pointers));

/** @} */

/**
 * @name Pipe management functions
 * @{
 * */
__swi_begin(0x323)
int NU_Create_Pipe(NU_PIPE *pipe, CHAR *name,
					void *start_address, unsigned long pipe_size,
					OPTION message_type, unsigned long message_size,
					OPTION suspend_type)
__swi_end(0x323, NU_Create_Pipe, (pipe, name, start_address, pipe_size, message_type, message_size, suspend_type));


__swi_begin(0x324)
int NU_Delete_Pipe(NU_PIPE *pipe)
__swi_end(0x324, NU_Delete_Pipe, (pipe));


__swi_begin(0x325)
int NU_Reset_Pipe(NU_PIPE *pipe)
__swi_end(0x325, NU_Reset_Pipe, (pipe));


__swi_begin(0x326)
int NU_Send_To_Front_Of_Pipe(NU_PIPE *pipe, void *message, unsigned long size, unsigned long suspend)
__swi_end(0x326, NU_Send_To_Front_Of_Pipe, (pipe, message, size, suspend));


__swi_begin(0x327)
int NU_Send_To_Pipe(NU_PIPE *pipe, void *message, unsigned long size, unsigned long suspend)
__swi_end(0x327, NU_Send_To_Pipe, (pipe, message, size, suspend));


__swi_begin(0x328)
int NU_Broadcast_To_Pipe(NU_PIPE *pipe, void *message, unsigned long size, unsigned long suspend)
__swi_end(0x328, NU_Broadcast_To_Pipe, (pipe, message, size, suspend));


__swi_begin(0x329)
int NU_Receive_From_Pipe(NU_PIPE *pipe, void *message, unsigned long size, unsigned long *actual_size, unsigned long suspend)
__swi_end(0x329, NU_Receive_From_Pipe, (pipe, message, size, actual_size, suspend));


__swi_begin(0x32A)
unsigned long NU_Established_Pipes(void)
__swi_end(0x32A, NU_Established_Pipes, ());


__swi_begin(0x32B)
int NU_Pipe_Information(NU_PIPE *pipe, CHAR *name,
						void **start_address, unsigned long *pipe_size,
						unsigned long *available, unsigned long *messages,
						OPTION *message_type, unsigned long *message_size,
						OPTION *suspend_type, unsigned long *tasks_waiting,
						NU_TASK **first_task)
__swi_end(0x32B, NU_Pipe_Information, (pipe, name, start_address, pipe_size, available, messages, message_type, message_size, suspend_type, tasks_waiting, first_task));


__swi_begin(0x32C)
unsigned long NU_Pipe_Pointers(NU_PIPE **pointer_list, unsigned long maximum_pointers)
__swi_end(0x32C, NU_Pipe_Pointers, (pointer_list, maximum_pointers));

/** @} */

/**
 * @name Define Semaphore management functions
 * @{
 * */
__swi_begin(0x32D)
int NU_Create_Semaphore(NU_SEMAPHORE *semaphore, CHAR *name, unsigned long initial_count, OPTION suspend_type)
__swi_end(0x32D, NU_Create_Semaphore, (semaphore, name, initial_count, suspend_type));


__swi_begin(0x32E)
int NU_Delete_Semaphore(NU_SEMAPHORE *semaphore)
__swi_end(0x32E, NU_Delete_Semaphore, (semaphore));


__swi_begin(0x32F)
int NU_Reset_Semaphore(NU_SEMAPHORE *semaphore, unsigned long initial_count)
__swi_end(0x32F, NU_Reset_Semaphore, (semaphore, initial_count));


__swi_begin(0x330)
int NU_Obtain_Semaphore(NU_SEMAPHORE *semaphore, unsigned long suspend)
__swi_end(0x330, NU_Obtain_Semaphore, (semaphore, suspend));


__swi_begin(0x331)
int NU_Release_Semaphore(NU_SEMAPHORE *semaphore)
__swi_end(0x331, NU_Release_Semaphore, (semaphore));


__swi_begin(0x332)
unsigned long NU_Established_Semaphores(void)
__swi_end(0x332, NU_Established_Semaphores, ());


__swi_begin(0x333)
int NU_Semaphore_Information(NU_SEMAPHORE *semaphore, CHAR *name,
								unsigned long *current_count, OPTION *suspend_type,
								unsigned long *tasks_waiting, NU_TASK **first_task)
__swi_end(0x333, NU_Semaphore_Information, (semaphore, name, current_count, suspend_type, tasks_waiting, first_task));


__swi_begin(0x334)
unsigned long NU_Semaphore_Pointers(NU_SEMAPHORE **pointer_list,
									unsigned long maximum_pointers)
__swi_end(0x334, NU_Semaphore_Pointers, (pointer_list, maximum_pointers));

/** @} */

/**
 * @name Event Group management functions
 * @{
 * */
__swi_begin(0x335)
int NU_Create_Event_Group(NU_EVENT_GROUP *group, CHAR *name)
__swi_end(0x335, NU_Create_Event_Group, (group, name));


__swi_begin(0x336)
int NU_Delete_Event_Group(NU_EVENT_GROUP *group)
__swi_end(0x336, NU_Delete_Event_Group, (group));


__swi_begin(0x337)
int NU_Set_Events(NU_EVENT_GROUP *group, unsigned long events, OPTION operation)
__swi_end(0x337, NU_Set_Events, (group, events, operation));


__swi_begin(0x338)
int NU_Retrieve_Events(NU_EVENT_GROUP *group,
						unsigned long requested_flags, OPTION operation,
						unsigned long *retrieved_flags, unsigned long suspend)
__swi_end(0x338, NU_Retrieve_Events, (group, requested_flags, operation, retrieved_flags, suspend));


__swi_begin(0x339)
unsigned long NU_Established_Event_Groups(void)
__swi_end(0x339, NU_Established_Event_Groups, ());


__swi_begin(0x33A)
int NU_Event_Group_Information(NU_EVENT_GROUP *group, CHAR *name,
								unsigned long *event_flags, unsigned long *tasks_waiting,
								NU_TASK **first_task)
__swi_end(0x33A, NU_Event_Group_Information, (group, name, event_flags, tasks_waiting, first_task));


__swi_begin(0x33B)
unsigned long NU_Event_Group_Pointers(NU_EVENT_GROUP **pointer_list,
										unsigned long maximum_pointers)
__swi_end(0x33B, NU_Event_Group_Pointers, (pointer_list, maximum_pointers));

/** @} */

/**
 * @name Signal processing functions
 * @{
 * */
__swi_begin(0x33C)
unsigned long NU_Control_Signals(unsigned long signal_enable_mask)
__swi_end(0x33C, NU_Control_Signals, (signal_enable_mask));


__swi_begin(0x33D)
unsigned long NU_Receive_Signals(void)
__swi_end(0x33D, NU_Receive_Signals, ());


__swi_begin(0x33E)
STATUS NU_Register_Signal_Handler(void (*signal_handler)(unsigned long))
__swi_end(0x33E, NU_Register_Signal_Handler, (signal_handler));


__swi_begin(0x33F)
STATUS NU_Send_Signals(NU_TASK *task, unsigned long signals)
__swi_end(0x33F, NU_Send_Signals, (task, signals));

/** @} */

/**
 * @name Partition memory management functions
 * @{
 * */
__swi_begin(0x340)
int NU_Create_Partition_Pool(NU_PARTITION_POOL *pool, CHAR *name,
								void *start_address, unsigned long pool_size,
								unsigned long partition_size, OPTION suspend_type)
__swi_end(0x340, NU_Create_Partition_Pool, (pool, name, start_address, pool_size, partition_size, suspend_type));


__swi_begin(0x341)
int NU_Delete_Partition_Pool(NU_PARTITION_POOL *pool)
__swi_end(0x341, NU_Delete_Partition_Pool, (pool));


__swi_begin(0x342)
int NU_Allocate_Partition(NU_PARTITION_POOL *pool,
							void **return_pointer, unsigned long suspend)
__swi_end(0x342, NU_Allocate_Partition, (pool, return_pointer, suspend));


__swi_begin(0x343)
int NU_Deallocate_Partition(void *partition)
__swi_end(0x343, NU_Deallocate_Partition, (partition));


__swi_begin(0x344)
unsigned long NU_Established_Partition_Pools(void)
__swi_end(0x344, NU_Established_Partition_Pools, ());


__swi_begin(0x345)
int NU_Partition_Pool_Information(NU_PARTITION_POOL *pool,
									CHAR *name,
									void **start_address, unsigned long *pool_size,
									unsigned long *partition_size, unsigned long *available,
									unsigned long *allocated, OPTION *suspend_type,
									unsigned long *tasks_waiting, NU_TASK **first_task)
__swi_end(0x345, NU_Partition_Pool_Information, (pool, name, start_address, pool_size, partition_size, available, allocated, suspend_type, tasks_waiting, first_task));


__swi_begin(0x346)
unsigned long NU_Partition_Pool_Pointers(NU_PARTITION_POOL **pointer_list,
											unsigned long maximum_pointers)
__swi_end(0x346, NU_Partition_Pool_Pointers, (pointer_list, maximum_pointers));

/** @} */

/**
 * @name Dynamic memory management functions
 * @{
 * */
__swi_begin(0x347)
int NU_Create_Memory_Pool(NU_MEMORY_POOL *pool, CHAR *name,
							void *start_address, unsigned long pool_size,
							unsigned long min_allocation, OPTION suspend_type)
__swi_end(0x347, NU_Create_Memory_Pool, (pool, name, start_address, pool_size, min_allocation, suspend_type));


__swi_begin(0x348)
int NU_Delete_Memory_Pool(NU_MEMORY_POOL *pool)
__swi_end(0x348, NU_Delete_Memory_Pool, (pool));


__swi_begin(0x349)
int NU_Allocate_Memory(NU_MEMORY_POOL *pool, void **return_pointer,
						unsigned long size, unsigned long suspend)
__swi_end(0x349, NU_Allocate_Memory, (pool, return_pointer, size, suspend));


__swi_begin(0x34A)
int NU_Deallocate_Memory(void *memory)
__swi_end(0x34A, NU_Deallocate_Memory, (memory));


__swi_begin(0x34B)
unsigned long NU_Established_Memory_Pools(void)
__swi_end(0x34B, NU_Established_Memory_Pools, ());


__swi_begin(0x34C)
int NU_Memory_Pool_Information(NU_MEMORY_POOL *pool, CHAR *name,
								void **start_address, unsigned long *pool_size,
								unsigned long *min_allocation, unsigned long *available,
								OPTION *suspend_type, unsigned long *tasks_waiting,
								NU_TASK **first_task)
__swi_end(0x34C, NU_Memory_Pool_Information, (pool, name, start_address, pool_size, min_allocation, available, suspend_type, tasks_waiting, first_task));


__swi_begin(0x34D)
unsigned long NU_Memory_Pool_Pointers(NU_MEMORY_POOL **pointer_list, unsigned long maximum_pointers)
__swi_end(0x34D, NU_Memory_Pool_Pointers, (pointer_list, maximum_pointers));

/** @} */

/**
 * @name Interrupt management functions
 * @{
 * */
__swi_begin(0x34E)
int NU_Control_Interrupts(INT new_level)
__swi_end(0x34E, NU_Control_Interrupts, (new_level));


__swi_begin(0x34F)
int NU_Local_Control_Interrupts(INT new_level)
__swi_end(0x34F, NU_Local_Control_Interrupts, (new_level));


__swi_begin(0x350)
void NU_Restore_Interrupts(void)
__swi_end(0x305, NU_Restore_Interrupts, ());


__swi_begin(0x351)
void *NU_Setup_Vector(INT vector, void *new_vector)
__swi_end(0x351, NU_Setup_Vector, (vector, new_vector));


__swi_begin(0x352)
int NU_Register_LISR(INT vector, void (*new_lisr)(INT),  void (**old_lisr)(INT))
__swi_end(0x352, NU_Register_LISR, (vector, new_lisr, old_lisr));


__swi_begin(0x353)
int NU_Activate_HISR(NU_HISR *hisr)
__swi_end(0x353, NU_Activate_HISR, (hisr));


__swi_begin(0x354)
int NU_Create_HISR(NU_HISR *hisr, CHAR *name, void (*hisr_entry)(void), OPTION priority, void *stack_address, unsigned long stack_size)
__swi_end(0x354, NU_Create_HISR, (hisr, name, hisr_entry, priority, stack_address, stack_size));


__swi_begin(0x355)
int NU_Delete_HISR(NU_HISR *hisr)
__swi_end(0x355, NU_Delete_HISR, (hisr));


__swi_begin(0x356)
NU_HISR  *NU_Current_HISR_Pointer(void)
__swi_end(0x356, NU_Current_HISR_Pointer, ());


__swi_begin(0x357)
unsigned long NU_Established_HISRs(void)
__swi_end(0x357, NU_Established_HISRs, ());


__swi_begin(0x358)
int NU_HISR_Information(NU_HISR *hisr, CHAR *name,
						unsigned long *scheduled_count, DATA_ELEMENT *priority,
						void **stack_base, unsigned long *stack_size,
						unsigned long *minimum_stack)
__swi_end(0x358, NU_HISR_Information, (hisr, name, scheduled_count, priority, stack_base, stack_size, minimum_stack));


__swi_begin(0x359)
unsigned long NU_HISR_Pointers(NU_HISR **pointer_list,  unsigned long maximum_pointers)
__swi_end(0x359, NU_HISR_Pointers, (pointer_list, maximum_pointers));


__swi_begin(0x35A)
void NU_Protect(NU_PROTECT *protect_struct)
__swi_end(0x35A, NU_Protect, (protect_struct));


__swi_begin(0x35B)
void NU_Unprotect(void)
__swi_end(0x35B, NU_Unprotect, ());

/** @} */

/**
 * @name Timer management functions
 * @{
 * */
__swi_begin(0x35C)
int NU_Create_Timer(NU_TIMER *timer, CHAR *name,
					void (*expiration_routine)(unsigned long), unsigned long id,
					unsigned long initial_time, unsigned long reschedule_time,
					OPTION enable)
__swi_end(0x35C, NU_Create_Timer, (timer, name, expiration_routine, id, initial_time, reschedule_time, enable));


__swi_begin(0x35D)
int NU_Delete_Timer(NU_TIMER *timer)
__swi_end(0x35D, NU_Delete_Timer, (timer));


__swi_begin(0x35E)
int NU_Reset_Timer(NU_TIMER *timer,
					void (*expiration_routine)(unsigned long),
					unsigned long initial_time, unsigned long reschedule_timer,
					OPTION enable)
__swi_end(0x35E, NU_Reset_Timer, (timer, expiration_routine, initial_time, reschedule_timer, enable));


__swi_begin(0x35F)
int NU_Control_Timer(NU_TIMER *timer, OPTION enable)
__swi_end(0x35F, NU_Control_Timer, (timer, enable));


__swi_begin(0x360)
unsigned long  NU_Established_Timers(void)
__swi_end(0x360, NU_Established_Timers, ());


__swi_begin(0x361)
int NU_Timer_Information(NU_TIMER *timer, CHAR *name,
							OPTION *enable, unsigned long *expirations, unsigned long *id,
							unsigned long *initial_time, unsigned long *reschedule_time)
__swi_end(0x361, NU_Timer_Information, (timer, name, enable, expirations, id, initial_time, reschedule_time));


__swi_begin(0x362)
unsigned long NU_Timer_Pointers(NU_TIMER **pointer_list, unsigned long maximum_pointers)
__swi_end(0x362, NU_Timer_Pointers, (pointer_list, maximum_pointers));


__swi_begin(0x363)
void  NU_Set_Clock(unsigned long new_value)
__swi_end(0x363, NU_Set_Clock, (new_value));


__swi_begin(0x364)
unsigned long NU_Retrieve_Clock(void)
__swi_end(0x364, NU_Retrieve_Clock, ());

/** @} */

/**
 * @name Development support functions
 * @{
 * */
__swi_begin(0x365)
char *NU_Release_Information(void)
__swi_end(0x365, NU_Release_Information, ());


__swi_begin(0x366)
char *NU_License_Information(void)
__swi_end(0x366, NU_License_Information, ());


__swi_begin(0x367)
void NU_Disable_History_Saving(void)
__swi_end(0x367, NU_Disable_History_Saving, ());


__swi_begin(0x368)
void NU_Enable_History_Saving(void)
__swi_end(0x368, NU_Enable_History_Saving, ());


__swi_begin(0x369)
void NU_Make_History_Entry(unsigned long param1, unsigned long param2, unsigned long param3)
__swi_end(0x369, NU_Make_History_Entry, (param1, param2, param3));


__swi_begin(0x36A)
int NU_Retrieve_History_Entry(DATA_ELEMENT *id,
								unsigned long *param1, unsigned long *param2, unsigned long *param3,
								unsigned long *time, NU_TASK **task, NU_HISR **hisr)
__swi_end(0x36A, NU_Retrieve_History_Entry, (id, param1, param2, param3, time, task, hisr));

/** @} */

/**
 * @name Input/Output Driver functions
 * @{
 * */
__swi_begin(0x36B)
int NU_Create_Driver(NU_DRIVER *driver, CHAR *name,
						void (*driver_entry)(NU_DRIVER *, NU_DRIVER_REQUEST *))
__swi_end(0x36B, NU_Create_Driver, (driver, name, driver_entry));


__swi_begin(0x36C)
int NU_Delete_Driver(NU_DRIVER *driver)
__swi_end(0x36C, NU_Delete_Driver, (driver));


__swi_begin(0x36D)
int NU_Request_Driver(NU_DRIVER *driver,  NU_DRIVER_REQUEST *request)
__swi_end(0x36D, NU_Request_Driver, (driver, request));


__swi_begin(0x36E)
int NU_Resume_Driver(NU_TASK *task)
__swi_end(0x36E, NU_Resume_Driver, (task));


__swi_begin(0x36F)
int NU_Suspend_Driver(void (*terminate_routine)(void *), void *information, unsigned long timeout)
__swi_end(0x36F, NU_Suspend_Driver, (terminate_routine, information, timeout));


__swi_begin(0x370)
unsigned long NU_Established_Drivers(void)
__swi_end(0x370, NU_Established_Drivers, ());


__swi_begin(0x371)
unsigned long NU_Driver_Pointers(NU_DRIVER **pointer_list, unsigned long maximum_pointers)
__swi_end(0x371, NU_Driver_Pointers, (pointer_list, maximum_pointers));

/** @} */

/**
 * @name Supervisor and User mode functions
 * @{
 * */
__swi_begin(0x372)
unsigned long NU_IS_SUPERVISOR_MODE()
__swi_end(0x372, NU_IS_SUPERVISOR_MODE, ());


__swi_begin(0x373)
void NU_SUPERVISOR_MODE(unsigned long nu_svc_usr_var)
__swi_end(0x373, NU_SUPERVISOR_MODE, (nu_svc_usr_var));


__swi_begin(0x374)
void NU_USER_MODE(unsigned long nu_svc_usr_var)
__swi_end(0x374, NU_USER_MODE, (nu_svc_usr_var));

// FIXME: NU_SUPERV_USER_VARIABLES is macro...
__swi_begin(0x8375)
void *NU_SUPERV_USER_VARIABLES(void)
__swi_end(0x8375, NU_SUPERV_USER_VARIABLES, ());

/** @} */

__swilib_end

/** @} */

