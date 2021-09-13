#pragma once
#ifndef wrap_asnd_h
#define wrap_asnd_h

#include <gctypes.h>
#include <asndlib.h>

#include "asnd/asnd_td.hpp"

namespace ogcwrap::asnd
{
	// library management
	void init(void);
	void deinit(void);

	// gethods
	u32 getTime(void);
	bool getSoundPlayStatus(void);
	int getNoteFreq(int note, int freqbase, int notebase);
	u32 getSampleRate(void);
	u32 getSampleCount(void);
	u32 getSampleRateTick(void);
	u8 getFirstUnusedVoice(void);
	u32 getVoiceTicks(u8 voice);
	u32 getVoiceTime(u8 voice);
	u8 getDSPPercentUse(void);
	u32 getDSPProcessTime(void);

	// sethods
	void setTime(u32 time);
	void setCallback(void (*cb)(void));

	// sound manipulation methods
	void playSound(void);
	void pauseSound(void);

	// voice manipulation methods
	ASNDReturnValue addVoice(u8 voice, void * samples, u32 samplesize);
	ASNDReturnValue playVoice(u8 voice);
	ASNDReturnValue pauseVoice(u8 voice);
	ASNDReturnValue stopVoice(u8 voice);
	ASNDReturnValue getVoiceStatus(u8 voice);
	ASNDReturnValue setVoice(u8 voice, ASNDVoiceFormat format, u32 pitch, u32 delay, void * samples, u32 samplesize, u8 left, u8 right, ASNDVoiceCallback cb);
	ASNDReturnValue setInfiniteVoice(u8 voice, ASNDVoiceFormat format, u32 patch, u32 delay, void * samples, u32 samplesize, u8 left, u8 right);
	ASNDReturnValue setVoiceVolume(u8 voice, u8 left, u8 right);
	ASNDReturnValue setVoicePitch(u8 voice, u32 pitch);

	// testing methods
	bool testVoiceBufferUsing(u8 voice, void * buffer);
	bool testVoiceBufferReady(u8 voice);
}

#endif // wrap_asnd_h