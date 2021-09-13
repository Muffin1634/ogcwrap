/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "aesnd/aesnd_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::aesnd
{
	// library management
	void init(void);
	void deinit(void);
	void play(void);
	void pause(void);

	// gethods
	u32 getDSPProcessTime(void);
	f32 getDSPProcessUsage(void);

	// sethods
	AESNDAudioCallback setAudioCallback(AESNDAudioCallback);
	AESNDVoiceCallback setVoiceCallback(AESNDPB *, AESNDVoiceCallback);

	// voice manipulation methods
	AESNDPB * allocateVoice(AESNDVoiceCallback);
	void freeVoice(AESNDPB *);
	void setVoiceStopStatus(AESNDPB *, bool);
	void setVoiceMuteStatus(AESNDPB *, bool);
	void setVoiceLoopStatus(AESNDPB *, bool);
	void setVoiceStreamStatus(AESNDPB *, bool);
	void setVoiceFormat(AESNDPB *, aesnd_voice_format_t);
	void setVoiceFrequency(AESNDPB *, f32);
	void setVoiceVolume(AESNDPB *, u16, u16);
	void setVoiceDelay(AESNDPB *, u32);
	void setVoiceBuffer(AESNDPB *, const void *, u32);
	void playVoice(AESNDPB *, aesnd_voice_format_t, const void *, u32, f32, u32, bool);
}

/*******************************************************************************
 * functions
 */

void ogcwrap::aesnd::init(void)
	{ AESND_Init(); }

void ogcwrap::aesnd::deinit(void)
	{ AESND_Reset(); }

void ogcwrap::aesnd::play(void)
	{ AESND_Pause(false); }

void ogcwrap::aesnd::pause(void)
	{ AESND_Pause(true); }

u32 ogcwrap::aesnd::getDSPProcessTime(void)
	{ return AESND_GetDSPProcessTime(); }

f32 ogcwrap::aesnd::getDSPProcessUsage(void)
	{ return AESND_GetDSPProcessUsage(); }

AESNDAudioCallback ogcwrap::aesnd::setAudioCallback(AESNDAudioCallback cb)
	{ return AESND_RegisterAudioCallback(cb); }

AESNDVoiceCallback ogcwrap::aesnd::setVoiceCallback(AESNDPB * voice, AESNDVoiceCallback cb)
	{ return AESND_RegisterVoiceCallback(voice, cb); }

AESNDPB * ogcwrap::aesnd::allocateVoice(AESNDVoiceCallback cb)
	{ return AESND_AllocateVoice(cb); }

void ogcwrap::aesnd::freeVoice(AESNDPB * voice)
	{ AESND_FreeVoice(voice); }

void ogcwrap::aesnd::setVoiceStopStatus(AESNDPB * voice, bool status)
	{ AESND_SetVoiceStop(voice, status); }

void ogcwrap::aesnd::setVoiceMuteStatus(AESNDPB * voice, bool status)
	{ AESND_SetVoiceMute(voice, status); }

void ogcwrap::aesnd::setVoiceLoopStatus(AESNDPB * voice, bool status)
	{ AESND_SetVoiceLoop(voice, status); }

void ogcwrap::aesnd::setVoiceStreamStatus(AESNDPB * voice, bool status)
	{ AESND_SetVoiceStream(voice, status); }

void ogcwrap::aesnd::setVoiceFormat(AESNDPB * voice, aesnd_voice_format_t format)
	{ AESND_SetVoiceFormat(voice, mcast(u32, format)); }

void ogcwrap::aesnd::setVoiceFrequency(AESNDPB * voice, f32 freq)
	{ AESND_SetVoiceFrequency(voice, freq); }

void ogcwrap::aesnd::setVoiceVolume(AESNDPB * voice, u16 left, u16 right)
	{ AESND_SetVoiceVolume(voice, left, right); }

void ogcwrap::aesnd::setVoiceDelay(AESNDPB * voice, u32 delay)
	{ AESND_SetVoiceDelay(voice, delay); }

void ogcwrap::aesnd::setVoiceBuffer(AESNDPB * voice, const void * buffer, u32 size)
	{ AESND_SetVoiceBuffer(voice, buffer, size); }

void ogcwrap::aesnd::playVoice(AESNDPB * voice, aesnd_voice_format_t format, const void * buffer, u32 size, f32 freq, u32 delay, bool statusLoop)
	{ AESND_PlayVoice(voice, mcast(u32, format), buffer, size, freq, delay, statusLoop); }