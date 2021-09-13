#pragma once
#ifndef wrap_aesnd_h
#define wrap_aesnd_h

#include <gctypes.h>
#include <aesndlib.h>

#include "aesnd/aesnd_td.hpp"

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
	AESNDAudioCallback setAudioCallback(AESNDAudioCallback cb);
	AESNDVoiceCallback setVoiceCallback(AESNDPB * voice, AESNDVoiceCallback cb);

	// voice manipulation methods
	AESNDPB * allocateVoice(AESNDVoiceCallback cb);
	void freeVoice(AESNDPB * voice);
	void setVoiceStopStatus(AESNDPB * voice, bool status);
	void setVoiceMuteStatus(AESNDPB * voice, bool status);
	void setVoiceLoopStatus(AESNDPB * voice, bool status);
	void setVoiceStreamStatus(AESNDPB * voice, bool status);
	void setVoiceFormat(AESNDPB * voice, aesnd_voice_format_t format);
	void setVoiceFrequency(AESNDPB * voice, f32 freq);
	void setVoiceVolume(AESNDPB * voice, u16 left, u16 right);
	void setVoiceDelay(AESNDPB * voice, u32 delay);
	void setVoiceBuffer(AESNDPB * voice, const void * buffer, u32 size);
	void playVoice(AESNDPB * voice, aesnd_voice_format_t format, const void * buffer, u32 size, f32 freq, u32 delay, bool statusLoop);
}

#endif // wrap_aesnd_h