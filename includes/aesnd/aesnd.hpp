#pragma once
#ifndef wrap_aesnd_h
#define wrap_aesnd_h

#include <gctypes.h>
#include <aesndlib.h>

#include "aesnd/aesnd_td.hpp"

namespace ogcwrap
{
	namespace aesnd
	{
		// library management
		void init(void);
		void reinit(void);
		void play(void);
		void pause(void);

		// gethods
		u32 getDSPProcessTime(void);
		f32 getDSPProcessUsage(void);

		// sethods
		AESNDAudioCallback setAudioCallback(AESNDAudioCallback);
		AESNDAudioCallback setVoiceCallback(AESNDPB *,AESNDAudioCallback);

		// voice manipulation methods
		AESNDPB * allocateVoice(AESNDVoiceCallback cb);
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
}

#endif // wrap_aesnd_h