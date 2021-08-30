#pragma once
#ifndef wrap_asnd_h
#define wrap_asnd_h

#include <gctypes.h>
#include <asndlib.h>

#include "asnd/asnd_td.hpp"

namespace ogcwrap
{
	namespace asnd
	{
		// library management
		void init(void);
		void deinit(void);

		// gethods
		u32 getTime(void);
		bool getSoundPlayStatus(void);
		u32 getSampleRate(void);
		u32 getSampleCount(void);
		u32 getSampleRateTick(void);
		u8 getFirstUnusedVoice(void);
		u32 getVoiceTicks(u8);
		u32 getVoiceTime(u8);
		u8 getDSPPercentUse(void);
		u32 getDSPProcessTime(void);

		// sethods
		void setTime(u32);
		void setCallback(void (*)(void));
		ASNDReturnValue setVoiceVolume(u8, u8, u8);
		ASNDReturnValue setVoicePitch(u8, u32);

		// sound manipulation methods
		void playSound(void);
		void pauseSound(void);

		// voice manipulation methods
		ASNDReturnValue addVoice(u8, void *, s32);
		ASNDReturnValue playVoice(u8);
		ASNDReturnValue pauseVoice(u8);
		ASNDReturnValue stopVoice(u8);
		ASNDReturnValue getVoiceStatus(u8);
		ASNDReturnValue setVoice(u8, ASNDVoiceFormat, u32, u32, void *, u32, u8, u8, ASNDVoiceCallback);
		ASNDReturnValue setInfiniteVoice(u8, ASNDVoiceFormat, u32, u32, void *, u32, u8, u8);

		// testing methods
		bool testVoiceBufferUsing(u8, void *);
		bool testVoiceBufferReady(u8);
	}
}

#endif // wrap_asnd_h