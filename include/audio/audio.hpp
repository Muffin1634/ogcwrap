#pragma once
#ifndef wrap_audio_h
#define wrap_audio_h

namespace ogcwrap::audio
{
	// subsystem management
	void init(u8 * stack = NULL);

	// callback methods
	AISCallback registerStreamCallback(AISCallback cb);
	AIDCallback registerDMACallback(AIDCallback cb);

	// gethods
	u8 getStreamVolumeLeft(void);
	u8 getStreamVolumeRight(void);
	sample_rate_t getStreamSampleRate(void);
	play_state_t getStreamPlayState(void);

	u16 getDMAEnableFlag(void);
	u32 getDMABytesLeft(void);
	u32 getDMALength(void);
	u32 getDMAStartAddress(void);
	u32 getDSPSampleRate(void);

	// sethods
	void setStreamVolumeLeft(u8 volume);
	void setStreamVolumeRight(u8 volume);
	void setStreamSampleRate(sample_rate_t rate);
	void setStreamPlayState(play_state_t state);

	void setStreamTrigger(u32 count);
	void setDSPSampleRate(sample_rate_t rate);

	// dma methods
	void initDMA(void * buf, u32 bufsize);
	void startDMA(void);
	void stopDMA(void);
}

#endif // wrap_audio_h