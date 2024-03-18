#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#include "image.h"
#include "wstring.h"
#include "csm.h"
#include "sound.h"
#endif

__swilib_begin

/**
 * @addtogroup OBS
 * @brief  Multifunction media framework: converting, resizing, rotating, streaming, recording and other.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/obs.h>`
 * @{
 */

typedef int HObj;
typedef struct OBSevent OBSevent;

/**
 * Event for #Obs_TranslateMessageGBS
 * */
struct OBSevent {
	int type;		/**< see #ObsEventID */
	void *func;		/**< event callback */
};

/**
 * OBS events for async mode.
 * */
enum ObsEventID {
	OBS_EV_NO_MSG				= 0x00,
	OBS_EV_GetInfoCon			= 0x01,
	OBS_EV_ConvDestroyed		= 0x05,
	OBS_EV_ParamChanged			= 0x06,
	OBS_EV_StatusChanged		= 0x08,
	OBS_EV_StatusUpdated		= 0x09,
	OBS_EV_FrameUpdate			= 0x0A,
	OBS_EV_LoopUpdate			= 0x0B,
	OBS_EV_Error				= 0x0C,
	OBS_EV_StopInd				= 0x13,
	OBS_EV_PauseInd				= 0x14,
	OBS_EV_ResumeInd			= 0x15,
	OBS_EV_StopCon				= 0x16,
	OBS_EV_PauseCon				= 0x17,
	OBS_EV_ResumeCon			= 0x18,
#ifdef ELKA
	OBS_EV_PrepareCon			= 0x35,
	OBS_EV_GetCapabilityCon		= 0x37,
	OBS_EV_EndList				= 0x66,
#elif defined(ELKA)
	OBS_EV_PrepareCon			= 0x34,
	OBS_EV_GetCapabilityCon		= 0x36,
	OBS_EV_EndList				= 0x57,
#else
	OBS_EV_EndList				= 0x2F,
#endif	
};

/**
 * Create OBS object
 * @param uid_in		UID of file type for input
 * @param uid_out		UID of file type for output
 * @param prio			priority
 * @param msg_callback	GBS message ID for async operations
 * @param emb4			unknown, set to 1
 * @param sync			1: sync mode, 0: async mode
 * @param[out] err		error code
 * @return OBS object or 0
 * */
__swi_begin(0x259)
HObj Obs_CreateObject(int uid_in, int uid_out, int prio, int msg_callback, int emb4, int sync, uint32_t *err)
__swi_end(0x259, Obs_CreateObject, (uid_in, uid_out, prio, msg_callback, emb4, sync, err));

/**
 * Destroy OBS object
 * @param obs			OBS object
 * @return 0 or error
 * */
__swi_begin(0x25A)
int Obs_DestroyObject(HObj obs)
__swi_end(0x25A, Obs_DestroyObject, (obs));

/**
 * Use the file as input.
 * @param obs		OBS object
 * @param unk		unknown, set to 0
 * @param path		path to the file
 * @return 0 or error
 * */
__swi_begin(0x25B)
int Obs_SetInput_File(HObj obs, int unk, WSHDR *path)
__swi_end(0x25B, Obs_SetInput_File, (obs, unk, path));

/**
 * Use the memory as input.
 * @param obs		OBS object
 * @param unk		unknown, set to 0
 * @param buf		pointer to the input buffer
 * @param len		size of the input buffer
 * @return 0 or error
 * */
__swi_begin(0x27A)
int Obs_SetInput_Memory(HObj obs, int unk, char *buf, int len)
__swi_end(0x27A, Obs_SetInput_Memory, (obs, unk, buf, len));

/**
 * Get the resolution of the input image.
 * @param obs			OBS object
 * @param[out] w, h		image resolution
 * @return 0 or error
 * */
__swi_begin(0x25C)
int Obs_GetInputImageSize(HObj obs, short *w, short *h)
__swi_end(0x25C, Obs_GetInputImageSize, (obs, w, h));

/**
 * Clip image.
 * @param obs			OBS object
 * @param x, y, w, h	clipping region
 * @return 0 or error
 * */
__swi_begin(0x260)
int Obs_Graphics_SetClipping(HObj obs, short x, short y, short w, short h)
__swi_end(0x260, Obs_Graphics_SetClipping, (obs, x, y, w, h));

/**
 * Set render offset.
 * @param obs			OBS object
 * @param x, y			render offset
 * @return 0 or error
 * */
__swi_begin(0x269)
int Obs_SetRenderOffset(HObj obs, short x, short y)
__swi_end(0x269, Obs_SetRenderOffset, (obs, x, y));

/**
 * Resize image.
 * @param obs			OBS object
 * @param w, h			new image resolution
 * @return 0 or error
 * */
__swi_begin(0x25D)
int Obs_SetOutputImageSize(HObj obs, short w, short h)
__swi_end(0x25D, Obs_SetOutputImageSize, (obs, w, h));

/**
 * Rotate image.
 * @param obs			OBS object
 * @param angle			rotate image using this angle (0, 90, 180, 270)
 * @return 0 or error
 * */
__swi_begin(0x261)
int Obs_SetRotation(HObj obs, int angle)
__swi_end(0x261, Obs_SetRotation, (obs, angle));

/**
 * Set scaling method.
 * @param obs			OBS object
 * @param method		set to 5
 * @return 0 or error
 * */
__swi_begin(0x263)
int Obs_SetScaling(HObj obs, int method)
__swi_end(0x263, Obs_SetScaling, (obs, method));

/**
 * Prepare before start.
 * @param obs			OBS object
 * @return 0 or error
 * */
__swi_begin(0x268)
int Obs_Prepare(HObj obs)
__swi_end(0x268, Obs_Prepare, (obs));

/**
 * Start processing.
 * @param obs			OBS object
 * @return 0 or error
 * */
__swi_begin(0x25E)
int Obs_Start(HObj obs)
__swi_end(0x25E, Obs_Start, (obs));

/**
 * Stop processing.
 * @param obs			OBS object
 * @return 0 or error
 * */
__swi_begin(0x267)
int Obs_Stop(HObj obs)
__swi_end(0x267, Obs_Stop, (obs));

/**
 * Pause processing.
 * @param obs			OBS object
 * @return 0 or error
 * */
__swi_begin(0x265)
int Obs_Pause(HObj obs)
__swi_end(0x265, Obs_Pause, (obs));

/**
 * Resume paused processing.
 * @param obs			OBS object
 * @return 0 or error
 * */
__swi_begin(0x266)
int Obs_Resume(HObj obs)
__swi_end(0x266, Obs_Resume, (obs));

/**
 * Get the #IMGHDR of the input image.
 * @param obs			OBS object
 * @param[out] img		IMGHDR pointer
 * @return 0 or error
 * */
__swi_begin(0x25F)
int Obs_Output_GetPictstruct(HObj obs, IMGHDR **img)
__swi_end(0x25F, Obs_Output_GetPictstruct, (obs, img));

/**
 * Get information from the input file.
 * @param obs		OBS object
 * @param unk		unknown, set to 1 or 0
 * @return 0 or error
 * */
__swi_begin(0x262)
int Obs_GetInfo(HObj obs, int unk)
__swi_end(0x262, Obs_GetInfo, (obs, unk));

/**
 * Process async callbacks from GBS message.
 * @param msg			message from GBS
 * @param handlers		async callbacks (array of #OBSevent)
 * @return 0 or error
 * */
__swi_begin(0x264)
int Obs_TranslateMessageGBS(const GBS_MSG *msg, const OBSevent *handlers)
__swi_end(0x264, Obs_TranslateMessageGBS, (msg, handlers));

/**
 * Set the given position for playing audio or video.
 * @param obs			OBS object
 * @param position		position in ms
 * @return 0 or error
 * */
__swi_begin(0x26A)
int Obs_SetPosition(HObj obs, int position)
__swi_end(0x26A, Obs_SetPosition, (obs, position));

/**
 * Get the current position of playing audio or video.
 * @param obs				OBS object
 * @param[out] position		position in ms
 * @return 0 or error
 * */
static inline int Obs_GetPosition(HObj obs, int *position) {
	return GetPlayObjPosition((void *) obs, position);
}

/**
 * Get the duration of playing audio or video.
 * @param obs				OBS object
 * @param[out] position		duration in ms
 * @return 0 or error
 * */
static inline int Obs_GetDuration(HObj obs, int *position) {
	return GetPlayObjDuration((void *) obs, position);
}

/**
 * Set purpose for MAM.
 * @param obs			OBS object
 * @param purpose		unknown
 * @return 0 or error
 * */
__swi_begin(0x26B)
int Obs_Mam_SetPurpose(HObj obs, char purpose)
__swi_end(0x26B, Obs_Mam_SetPurpose, (obs, purpose));

/**
 * Set purpose for Sound.
 * @param obs			OBS object
 * @param purpose		unknown
 * @return 0 or error
 * */
__swi_begin(0x26E)
int Obs_Sound_SetPurpose(HObj obs, int purpose)
__swi_end(0x26E, Obs_Sound_SetPurpose, (obs, purpose));

/**
 * Set sound volume.
 * @param obs			OBS object
 * @param volume		volume level, 0-15
 * @param delta			unknown, set to 1
 * @return 0 or error
 * */
__swi_begin(0x26C)
int Obs_Sound_SetVolumeEx(HObj obs, char volume, char delta)
__swi_end(0x26C, Obs_Sound_SetVolumeEx, (obs, volume, delta));

/**
 * Get current sound volume.
 * @param obs			OBS object
 * @param[out] volume	current volume level, 0-15
 * @return 0 or error
 * */
__swi_begin(0x26D)
int Obs_Sound_GetVolume(HObj obs, char *volume)
__swi_end(0x26D, Obs_Sound_GetVolume, (obs, volume));

/**
 * Link CSM to the OBS object.
 * @param obs		OBS object
 * @param csm		pointer to the csm
 * */
__swi_begin(0x27B)
int Obs_SetCSM(HObj obs, CSM_RAM *csm)
__swi_end(0x27B, Obs_SetCSM, (obs, csm));

/*
//  other events for elka (//NSG)
00 ObsCallback_NoMessage // e_obs_ev_no_message
01 ObsCallback_GetInfoConfirmation
02 ObsCallback_ConversionStarted
03 ObsCallback_ConversionCompleted
04 ObsCallback_ConversionAborted
05 ObsCallback_ConversionDestroyed
06 ObsCallback_ParamChanged
07 //unk //ObsCallback_ParamUpdated //unk
08 ObsCallback_StatusChanged  r0 -obs r1-live_mode = %d, r2 -err-code = %d
09 ObsCallback_StatusUpdated
0A ObsCallback_FrameUpdate
0B ObsCallback_LoopUpdate 
0C ObsCallback_Error
0D //e_obs_ev_emb_found
0E //e_obs_ev_emb_processed
0F ObsCallback_OutputReady  (must call Obs_Output_GetData);
10 ObsCallback_InputConsumed
11 ObsCallback_InputMoreData
12 ObsCallback_InputSeek  //setposition
13 Jnf_PlaybackStoppedIndication //e_obs_ev_stop_ind
14 Jnf_PlaybackPausedIndication
15 Jnf_PlaybackResumeIndication
16 Jnf_PlaybackStopConfirmation
17 Jnf_PlaybackPauseConfirmation
18 Jnf_PlaybackResumeConfirmation
19 //e_obs_ev_init_req
1A //e_obs_ev_prepare_req
1B //e_obs_ev_get_header_size
1C //e_obs_ev_data_correct
1D //e_obs_ev_get_info_req"
1E //e_obs_ev_convert_req
1F //e_obs_ev_pause_object_req
20 //e_obs_ev_resume_object_req
21 //e_obs_ev_abort_conversion_req
22 //e_obs_ev_finalise_object_req
23 //e_obs_ev_destroy_object_req
24 //e_obs_ev_stop_object_req
25 //e_obs_ev_rewind_req
26 //e_obs_ev_start_timer_req
27 //e_obs_ev_capability_req
28 //e_obs_ev_passify_object_req
29 //unk
2A //e_obs_ev_timer_ind
2B //e_obs_live_postponed

2C //-  e_obs_ev_mam_performance_ind
2D //2C e_obs_ev_abort_conversion_con
2E //2D e_obs_ev_pause_object_con
2F //2E e_obs_ev_resume_object_con
30 //2F e_obs_ev_finalise_object_con
31 //30 e_obs_ev_destroy_object_con
32 /31/e_obs_ev_stop_object_con
33 //32e_obs_ev_init_con
34 //33 e_obs_ev_cannot_process
35 //34  Jnf_PlaybackPrepareConfirmation
36 //35 e_obs_ev_convert_con
37 //36Jnf_PlaybackCapabilityConfirmation
38 //e_obs_ev_frame_done_object_con
39 //e_obs_ev_mam_prio_start
3A //e_obs_ev_mam_prio_stop
3B //e_obs_ev_mam_prio_pause
3C //e_obs_ev_mam_prio_resume
3D //e_obs_ev_mam_none_req
3E //e_obs_ev_mam_register_req
3F //e_obs_ev_mam_start_req
40 //e_obs_ev_mam_pause_req
41 //e_obs_ev_mam_stop_req
42 //e_obs_ev_mam_resume_req
43 //e_obs_ev_mam_deregister_req
44 //e_obs_ev_mam_register_grant
45 //e_obs_ev_mam_deregister_grant
46 //e_obs_ev_mam_start_grant
47 //e_obs_ev_mam_start_reject
48 //e_obs_ev_mam_start_postpone
49 //e_obs_ev_mam_pause_grant
4A //e_obs_ev_mam_resume_grant
4B //e_obs_ev_mam_resume_reject
4C //e_obs_ev_mam_resume_postpone
4D //e_obs_ev_mam_stop_grant
4E //e_obs_ev_mam_cannotprocessnow
4F //unk
50 //unk
51 //unk
52 //e_obs_ev_mm_vplayer_stop_con
53 //unk
54 //e_obs_ev_mm_vplayer_eos_reached
55 //unk
56 //e_obs_ev_mm_vplayer_init_error
57 //e_obs_ev_mm_vplayer_play_error
58 //e_obs_ev_mm_vplayer_stop_error
59 //e_obs_ev_mm_vplayer_finalise_error
5A //e_obs_ev_mm_vplayer_dec_error
5B //unk
5C //unk
5D //e_obs_ev_mm_stop_con
5E //e_obs_ev_mm_snapshot_req
5F //e_obs_ev_mm_redraw_req
60 //e_obs_ev_mm_av_input_ready
61 // 51 e_obs_ev_mm_finalise_req
62 //e_obs_ev_mm_poll_pv_scheduler_req"
63 //e_obs_ev_mm_poll_pv_scheduler_con
64 //unk
65 //e_obs_ev_tobj_change_state
66 //57 end
//sgold 2f

*/

__swilib_end

/** @} */
