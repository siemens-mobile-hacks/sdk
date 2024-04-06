#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#include "wstring.h"
#endif

__swilib_begin

/**
 * @addtogroup Sound
 * @brief Functions for playing and controlling sound-related stuff.
 * This function is mainly used for audio hooks or playing short sounds/tones.
 * See OBS_* functions for playing audio in the normal way.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/sound.h>`
 * @{
 */

typedef struct GBS_PSOUND_MSG GBS_PSOUND_MSG;
typedef struct PLAYFILE_OPT PLAYFILE_OPT;

/**
 * GBS event (#MSG_PLAYFILE_REPORT) for the #PlayFile or #PlayMelodyInMem
 * */
#ifdef NEWSGOLD
struct GBS_PSOUND_MSG {
	int pid_from;		/**< sender cepid */
	int msg;			/**< #MSG_PLAYFILE_REPORT */
	uint16_t cmd;
	short handler;
	void *data0;
	void *data1;
};
#else
struct GBS_PSOUND_MSG {
	short pid_from;		/**< sender cepid */
	short msg;			/**< #MSG_PLAYFILE_REPORT */
	uint16_t cmd;
	short handler;
	void *data0;
	void *data1;
};
#endif

/**
 * Event IDs for the #GBS_PSOUND_MSG
 * */
enum PlaySoundEventID {
#ifdef NEWSGOLD
	M_SAE_EVENT_STARTED					= 0,
	M_SAE_EVENT_STOPPED					= 1,
	M_SAE_EVENT_DONE					= 2,
	M_SAE_EVENT_ERROR					= 3,
	M_SAE_PLAYBACK_STARTED				= 4,
	M_SAE_PLAYBACK_ERROR				= 5,
	M_SAE_PLAYBACK_NEXTCYCLE			= 6,
	M_SAE_PLAYBACK_DONE					= 7,
	M_SAE_VOLUME_UPDATED				= 8,
	M_SAE_VOLUME_ERROR					= 9,
	M_SAE_EQUALIZER_UPDATED				= 0xA,
	M_SAE_EQUALIZER_ERROR				= 0xB,
	M_SAE_3DAUDIO_UPDATED				= 0xC,
	M_SAE_3DAUDIO_ERROR					= 0xD,
	M_SAE_UNKNOWN_EVENT					= 0xE,
	M_SAE_UNKNOWN_EVENT_1				= 0xF,
	M_SAE_PLAYTIME_UPDATED				= 0x10,
	M_SAE_PLAYTIME_ERROR				= 0x11,
	M_SAE_HANDSFREE_UPDATED				= 0x12,
	M_SAE_HANDSFREE_ERROR				= 0x13,
	M_SAE_RECORD_STARTED				= 0x14,
	M_SAE_RECORD_ERROR					= 0x15,
	M_SAE_RECORD_DONE					= 0x16,
	M_SAE_STOP_OK						= 0x17,
	M_SAE_STOP_FAIL						= 0x18,
	M_SAE_CANCEL_OK						= 0x19,
	M_SAE_CANCEL_FAIL					= 0x1A,
	M_SAE_PAUSE_OK						= 0x1B,
	M_SAE_PAUSE_FAIL					= 0x1C,
	M_SAE_RESUME_OK						= 0x1D,
	M_SAE_RESUME_FAIL					= 0x1E,
	M_SAE_INFO_DATA_AVAILABLE			= 0x1F,
	M_SAE_INFO_REQUEST_FAIL				= 0x20,
	M_SAE_MAX_RECORDING_TIME_AVAILABLE	= 0x21,
	M_SAE_MAX_RECORDING_TIME_ERROR		= 0x22,
	M_SAE_UNKNOWN_EVENT_2				= 0x23,
	M_SAE_UNKNOWN_EVENT_3				= 0x24,
	M_SAE_AUDIO_EVENT_STOPPED			= 0x25,
	M_SAE_AUDIO_EVENT_PAUSED			= 0x26,
	M_SAE_AUDIO_EVENT_RESUMED			= 0x27,
	M_SAE_VISUALIZATION_STOPPED			= 0x28,
	M_SAE_VISUALIZATION_STARTED			= 0x29,
	M_SAE_UNKNOWN_EVENT_4				= 0x2A,
	M_SAE_VISUALIZATION_DATA			= 0x2B,
	M_SAE_STREAM_READY					= 0x2C,
	M_SAE_STREAM_STALLED				= 0x2D,
	M_SAE_STREAM_UNSTALLED				= 0x2E,
	M_SAE_STREAM_LOW_WATERMARK			= 0x2F,
	M_SAE_STREAM_HIGH_WATERMARK			= 0x30,
	M_SAE_BUFFER_CONSUMED				= 0x31,
	M_SAE_BUFFER_AVAILABLE				= 0x32,
	M_SAE_RESERVE_OK					= 0x33,
	M_SAE_RESERVE_FAIL					= 0x34,
	M_SAE_RELEASE_OK					= 0x35,
	M_SAE_RELEASE_FAIL					= 0x36,
	M_SAE_RELEASED						= 0x37,
	M_SAE_VOLUME_CHANGED				= 0x38,
	M_SAE_SOUNDSTATE_CHANGED			= 0x39,
	M_SAE_SOUNDSYSTEM_IDLE				= 0x3A,
	M_SAE_EVENT_IN_STACK				= 0x3B,
#else
	M_SAE_EVENT_STARTED					= 0,
	M_SAE_EVENT_STOPPED					= 1,
	M_SAE_EVENT_DONE					= 2,
	M_SAE_EVENT_ERROR					= 3,
	M_SAE_PLAYBACK_STARTED				= 4,
	M_SAE_PLAYBACK_ERROR				= 5,
	M_SAE_PLAYBACK_NEXTCYCLE			= 6,
	M_SAE_PLAYBACK_DONE					= 7,
	M_SAE_VOLUME_UPDATED				= 8,
	M_SAE_VOLUME_ERROR					= 9,
	M_SAE_PLAYTIME_UPDATED				= 0xA,
	M_SAE_PLAYTIME_ERROR				= 0xB,
	M_SAE_HANDSFREE_UPDATED				= 0xC,
	M_SAE_HANDSFREE_ERROR				= 0xD,
	M_SAE_RECORD_STARTED				= 0xE,
	M_SAE_RECORD_ERROR					= 0xF,
	M_SAE_RECORD_DONE					= 0x10,
	M_SAE_STOP_OK						= 0x11,
	M_SAE_STOP_FAIL						= 0x12,
	M_SAE_CANCEL_OK						= 0x13,
	M_SAE_CANCEL_FAIL					= 0x14,
	M_SAE_PAUSE_OK						= 0x15,
	M_SAE_PAUSE_FAIL					= 0x16,
	M_SAE_RESUME_OK						= 0x17,
	M_SAE_RESUME_FAIL					= 0x18,
	M_SAE_INFO_DATA_AVAILABLE			= 0x19,
	M_SAE_INFO_REQUEST_FAIL				= 0x1A,
	M_SAE_MAX_RECORDING_TIME_AVAILABLE	= 0x1B,
	M_SAE_MAX_RECORDING_TIME_ERROR		= 0x1C,
	M_SAE_AUDIO_EVENT_UPDATED			= 0x1D,
	M_SAE_AUDIO_EVENT_UPDATED_MS		= 0x1E,
	M_SAE_AUDIO_EVENT_STOPPED			= 0x1F,
	M_SAE_AUDIO_EVENT_PAUSED			= 0x20,
	M_SAE_AUDIO_EVENT_RESUMED			= 0x21,
#endif
};

/**
 * Job IDs for the #GBS_PSOUND_MSG
 * */
enum PlaySoundJobID {
#ifdef NEWSGOLD
	Job_NoJob					= 0,
	Job_RecFile					= 1,
	Job_RecBuffer				= 2,
	Job_PlayFile				= 3,
	Job_PlayBuffer				= 5,
	Job_GetInfo					= 0xF,
	Job_GetRecordingTimeMax		= 0x10,
#else
	Job_NoJob					= 0,
	Job_RecFile					= 1,
	Job_RecBuffer				= 2,
	Job_PlayFile				= 3,
	Job_PlayBuffer				= 4,
	Job_GetInfo					= 5,
	Job_GetRecordingTimeMax		= 6,
#endif
};

/**
 * Volume (=category) for tones (#PlaySound).
 * */
enum PlaySoundVolumeID {
	VOLUME_CALLS			= 0,
	VOLUME_SYSTEM			= 1,
	VOLUME_WALKY_TALKY		= 2,
//	VOLUME_SYSTEM			= 3,
	VOLUME_MESSAGES			= 4,
//	VOLUME_MESSAGES			= 5,
	VOLUME_CB_SERVICES		= 6,
//	VOLUME_SYSTEM			= 7,
//	VOLUME_SYSTEM			= 8,
	VOLUME_ALARM_CLOCK		= 9,
	VOLUME_ORGANISER		= 0xA,
//	VOLUME_SYSTEM			= 0xB,
	VOLUME_APPLICATIONS		= 0xC,
//	VOLUME_SYSTEM			= 0xD,
//	VOLUME_SYSTEM			= 0xE,
//	VOLUME_SYSTEM			= 0xF,
//	VOLUME_SYSTEM			= 0x10,
//	VOLUME_SYSTEM			= 0x11,
//	VOLUME_SYSTEM			= 0x12,
//	VOLUME_SYSTEM			= 0x13,
//	VOLUME_SYSTEM			= 0x14,
//	VOLUME_SYSTEM			= 0x15,
};

/**
 * Options for the #PlayFile
 * */
struct PLAYFILE_OPT {
#ifdef NEWSGOLD
	uint16_t repeat_num;		/**< Number of repeat (0: unlimited) */
	uint16_t unk;				/**< Unknown, set to 0 */
	int time_between_play;		/**< Delay between each repeat */
	int play_first;				/**< Unknown, set to 0 */
	int volume;					/**< Volume level (1-15) */
	int unk5;					/**< Unknown, set to 0 */
	int unk6;					/**< Unknown, set to 0 */
	int unk7;					/**< Unknown, set to 0 */
	int unk8;					/**< Unknown, set to 0 */
	int unk9;					/**< Unknown, set to 0 */
#else
#ifdef X75
	uint16_t repeat_num;		/**< Number of repeat (0: unlimited) */
	uint16_t unk;
	int time_between_play;		/**< Delay between each repeat */
	int play_first;				/**< Unknown, set to 0 */
	int volume;					/**< Volume level (1-5) */
	int unk4;					/**< Unknown, set to 0x80000000 */
	int unk5;					/**< Unknown, set to 1 */
	int unk6;					/**< Unknown, set to 0 */
	int unk7;					/**< Unknown, set to 0 */
#else
	uint16_t repeat_num;		/**< Number of repeat (0: unlimited) */
	uint16_t unk;				/**< Unknown, set to 0 */
	int time_between_play;		/**< Delay between each repeat */
	int play_first;				/**< Unknown, set to 0 */
	int volume;					/**< Volume level (1-5) */
	int unk5;					/**< Unknown, set to 0 */
	int unk6;					/**< Unknown, set to 0 */
#endif
#endif
};

/**
 * Get current volume level.
 * @return volume level
 * */
__swi_begin(0x81FA)
char *RamVolumeLevel()
__swi_end(0x81FA, RamVolumeLevel, ());

/**
 * Checking if any sound is currently played
 * @return pointer to the value of an unknown PASIC register
 * @return SG: RamMediaIsPlaying() != 2 // sound is playing
 * @return NSG: RamMediaIsPlaying() != 0 // sound is playing
 * @warning Result varies across platforms.
 * */
__swi_begin(0x81FB)
char *RamMediaIsPlaying()
__swi_end(0x81FB, RamMediaIsPlaying, ());

/**
 * Check if the radio or player is active.
 * @return 1 or 0
 * */
__swi_begin(0x07F)
int IsPlayerOn()
__swi_end(0x07F, IsPlayerOn, ());

/**
 * Get status of the MediaPlayer.
 * @return unknown values
 * */
__swi_begin(0x1F8)
int GetPlayStatus(void)
__swi_end(0x1F8, GetPlayStatus, ());

/**
 * Play tone by id.
 * @param volume		category of the tone, see: #PlaySoundVolumeID
 * @param cepid			target cepid, set to #MMI_CEPID
 * @param unk1			unknown, set to 0
 * @param tone_type		1-118
 * @param unk2			unknown, set to 0
 * */
__swi_begin(0x032)
void PlaySound(long volume, long cepid, long unk1, long tone_type, long unk2)
__swi_end(0x032, PlaySound, (volume, cepid, unk1, tone_type, unk2));

/**
 * Play melody from memory.
 * @param unk1			unknown, set to 0x11
 * @param buffer		pointer to the melody buffer
 * @param size			size of the melody buffer
 * @param cepid			target cepid, set MMI_CEPID
 * @param msg			GBS message ID for the events, set to #MSG_PLAYFILE_REPORT or 0
 * @param unk2			unknown, set to 0
 * @return play object handle
 * @note Useful for audiohook.
 * */
__swi_begin(0x099)
int PlayMelodyInMem(char unk1, const void *buffer, int size, int cepid, int msg, int unk2)
__swi_end(0x099, PlayMelodyInMem, (unk1, buffer, size, cepid, msg, unk2));

/**
 * Change the volume of the playing melody.
 * @param handle	play object handle
 * @param volume	volume level (nsg: 1-15, sg: 1-5)
 * @return 1 if success, 0 if error
 * */
__swi_begin(0x225)
int PlayMelody_ChangeVolume(int handle, int volume)
__swi_end(0x225, PlayMelody_ChangeVolume, (handle, volume));

/**
 * Stop the playback of the melody.
 * @param handle	play object handle
 * @return 1 if success, 0 if error
 * */
__swi_begin(0x226)
int PlayMelody_StopPlayback(int handle)
__swi_end(0x226, PlayMelody_StopPlayback, (handle));

/**
 * Pause the playback of the melody.
 * @param handle	play object handle
 * @return 1 if success, 0 if error
 * */
__swi_begin(0x227)
int PlayMelody_PausePlayback(int handle)
__swi_end(0x227, PlayMelody_PausePlayback, (handle));

/**
 * Resume the playback of the melody.
 * @param handle	play object handle
 * @return 1 if success, 0 if error
 * */
__swi_begin(0x228)
int PlayMelody_ResumePlayBack(int handle)
__swi_end(0x228, PlayMelody_ResumePlayBack, (handle));

/**
 * Set the position of the playing melody.
 * @param handle	play object handle
 * @param position	position in ms
 * @return 1 if success, 0 if error
 * */
__swi_begin(0x24D)
int PlayMelody_SetPosition(int handle, int position)
__swi_end(0x24D, PlayMelody_SetPosition, (handle, position));

/**
 * Get a pointer to the PlayObject by PlayObject handle.
 * @param handle			play object handle
 * @return pointer or NULL
 * */
__swi_begin(0x24E)
void *GetPlayObjById(int handle)
__swi_end(0x24E, GetPlayObjById, (handle));

/**
 * Get the current position from Obs or PlayObj (generic).
 * @param obj				Obs or PlayObj pointer
 * @param[out] position		position in ms
 * @return 1 if success, 0 if error
 * */
__swi_begin(0x24F)
int GetPlayObjPosition(void *obj, int *position)
__swi_end(0x24F, GetPlayObjPosition, (obj, position));

/**
 * Get the duration of from Obs or PlayObj (generic).
 * @param obj				Obs or PlayObj pointer
 * @param[out] duration		duration in ms
 * @return 1 if success, 0 if error
 * */
__swi_begin(0x250)
int GetPlayObjDuration(void *obj, int *duration)
__swi_end(0x250, GetPlayObjDuration, (obj, duration));

/**
 * Get the current position of the playing melody.
 * @param handle			play object handle
 * @param[out] position		position in ms
 * @return 1 if success, 0 if error
 * */
static inline int PlayMelody_GetPosition(int handle, int *position) {
	return GetPlayObjPosition(GetPlayObjById(handle), position);
}

/**
 * Get the duration of the playing melody.
 * @param handle			play object handle
 * @param[out] duration		duration in ms
 * @return 1 if success, 0 if error
 * */
static inline int PlayMelody_GetDuration(int handle, int *duration) {
	return GetPlayObjPosition(GetPlayObjById(handle), duration);
}

#ifdef X75
/**
 * Play file from filesystem (path=folder\\file).
 * @param flags		unknown flags
 * @param folder	path to directory with file
 * @param file		filename
 * @param zero		unknown, set to zero
 * @param cepid		target cepid, set to #GBS_GetCurCepid
 * @param msgid		GBS message for events, set to MSG_PLAYFILE_REPORT
 * @param sfo		pointer to the options: #PLAYFILE_OPT
 * @return 1 if success, 0 if error
 * 
 * @warning Different function signatures across platforms!
 * */
__swi_begin(0x04A)
short PlayFile(int flags, const WSHDR *folder, const WSHDR *file, int zero, int cepid, int msgid, const PLAYFILE_OPT *sfo)
__swi_end(0x04A, PlayFile, (flags, folder, file, zero, cepid, msgid, sfo));
#else
/**
 * Play file from filesystem (path=folder\\file).
 * @param flags		unknown flags
 * @param folder	path to directory with file
 * @param file		filename
 * @param cepid		target cepid, set to #GBS_GetCurCepid
 * @param msgid		GBS message for events, set to MSG_PLAYFILE_REPORT
 * @param sfo		pointer to the options: #PLAYFILE_OPT
 * @return 1 if success, 0 if error
 * 
 * @warning Different function signatures across platforms!
 * */
__swi_begin(0x04A)
short PlayFile(int flags, const WSHDR *folder, const WSHDR *file, int cepid, int msgid, const PLAYFILE_OPT *sfo)
__swi_end(0x04A, PlayFile, (flags, folder, file, cepid, msgid, sfo));
#endif



/**
 * Get current audio path.
 * @return id
 * */
__swi_begin(0x288)
int Audio_GetCurrAudioPath()
__swi_end(0x288, Audio_GetCurrAudioPath, ());

/**
 * Get current object handle.
 * @return object handle
 * */
__swi_begin(0x29B)
int Audio_GetObjectHandle()
__swi_end(0x29B, Audio_GetObjectHandle, ());

/**
 * Change audio output.
 * @param oh				object handle, use #Audio_GetObjectHandle
 * @param type_and_conn		conn << 16 | type
 * @return 0 or error
 * */
__swi_begin(0x29A)
int AACC_AudioTransferReq(int oh, uint32_t type_and_conn)
__swi_end(0x29A, AACC_AudioTransferReq, (oh, type_and_conn));

/**
 * Play vibra tone (???).
 * @param unk1			unknown, set to 0x2F
 * @param unk2			unknown, set to 1
 * @param duration		duration in ms
 * @warning Untested function that is not found in any ELF's.
 * */
__swi_begin(0x034)
void PlaySoundLoop(int unk1, int unk2, int duration)
__swi_end(0x034, PlaySoundLoop, (unk1, unk2, duration));

/**
 * Change volume (unknown function).
 * @param volume		volume level
 * @return unknown
 * @warning Untested function that is not found in any ELF's.
 * */
__swi_begin(0x09A)
int ChangeVolume(uint8_t volume)
__swi_end(0x09A, ChangeVolume, (volume));

/**
 * Play custom sound.
 * @param event_id		event ID
 * @param cepid			GBS message CEPID
 * @param msg_id		GBS message ID
 * @param folder		folder for custom sound, can be NULL
 * @param file			file for custom sound, can be NULL
 * @return 0 or error
 * @warning Untested function that is not found in any ELF's.
 * */
__swi_begin(0x033)
short SoundAE_PlayFileAsEvent(int event_id, int cepid, int msg_id, const WSHDR *folder, const WSHDR *file)
__swi_end(0x033, SoundAE_PlayFileAsEvent, (event_id, cepid, msg_id, folder, file));

/**
 * Pointer to the AudioHook.
 * @return implementation specific
 * */
__swi_begin(0x838A)
void *RamAudioHook()
__swi_end(0x838A, RamAudioHook, ());

/**
 * Check if active recording of the sound.
 * @return pointer to 1 or 0
 * */
__swi_begin(0x8297)
char *RamIsSoundRecordingActive()
__swi_end(0x8297, RamIsSoundRecordingActive, ());

/**
 * Quality of the current sound recording.
 * @return pointer to 1 or 0
 * */
__swi_begin(0x8298)
char *RamSoundRecordingQuality()
__swi_end(0x8298, RamSoundRecordingQuality, ());

__swilib_end

/** @} */
