/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "audio/audio_td.hpp"

using ogcwrap::audio::sample_rate_t;
using ogcwrap::audio::play_state_t;

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::audio
{
	// subsystem management
	void init(u8 * = NULL);

	// callback methods
	AISCallback registerStreamCallback(AISCallback);
	AIDCallback registerDMACallback(AIDCallback);

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
	void setStreamVolumeLeft(u8);
	void setStreamVolumeRight(u8);
	void setStreamSampleRate(sample_rate_t);
	void setStreamPlayState(play_state_t);

	void setStreamTrigger(u32);
	void setDSPSampleRate(sample_rate_t);

	// dma methods
	void initDMA(void *, u32);
	void startDMA(void);
	void stopDMA(void);
}

/*******************************************************************************
 * functions
 */

void ogcwrap::audio::init(u8 * stack)
	{ AUDIO_Init(stack); }

AISCallback ogcwrap::audio::registerStreamCallback(AISCallback cb)
	{ return AUDIO_RegisterStreamCallback(cb); }

AIDCallback ogcwrap::audio::registerDMACallback(AIDCallback cb)
	{ return AUDIO_RegisterDMACallback(cb); }

u8 ogcwrap::audio::getStreamVolumeLeft(void)
	{ return AUDIO_GetStreamVolLeft(); }

u8 ogcwrap::audio::getStreamVolumeRight(void)
	{ return AUDIO_GetStreamVolRight(); }

sample_rate_t ogcwrap::audio::getStreamSampleRate(void)
	{ return static_cast<sample_rate_t>(AUDIO_GetStreamSampleRate()); }

play_state_t ogcwrap::audio::getStreamPlayState(void)
	{ return static_cast<play_state_t>(AUDIO_GetStreamPlayState()); }

u16 ogcwrap::audio::getDMAEnableFlag(void)
	{ return AUDIO_GetDMAEnableFlag(); }

u32 ogcwrap::audio::getDMABytesLeft(void)
	{ return AUDIO_GetDMABytesLeft(); }

u32 ogcwrap::audio::getDMALength(void)
	{ return AUDIO_GetDMALength(); }

u32 ogcwrap::audio::getDMAStartAddress(void)
	{ return AUDIO_GetDMAStartAddr(); }

u32 ogcwrap::audio::getDSPSampleRate(void)
	{ return AUDIO_GetDSPSampleRate(); }

void ogcwrap::audio::setStreamVolumeLeft(u8 volume)
	{ AUDIO_SetStreamVolLeft(volume); }

void ogcwrap::audio::setStreamVolumeRight(u8 volume)
	{ AUDIO_SetStreamVolRight(volume); }

void ogcwrap::audio::setStreamSampleRate(sample_rate_t rate)
	{ AUDIO_SetStreamSampleRate(static_cast<u32>(rate)); }

void ogcwrap::audio::setStreamPlayState(play_state_t state)
	{ AUDIO_SetStreamPlayState(static_cast<u32>(state)); }

void ogcwrap::audio::setStreamTrigger(u32 count)
	{ AUDIO_SetStreamTrigger(count); }

void ogcwrap::audio::setDSPSampleRate(sample_rate_t rate)
	{ AUDIO_SetDSPSampleRate(static_cast<u32>(rate)); }

void ogcwrap::audio::initDMA(void * buf, u32 bufsize)
	{ AUDIO_InitDMA(static_cast<u32>(buf), bufsize); }

void ogcwrap::audio::startDMA(void)
	{ AUDIO_StartDMA(); }

void ogcwrap::audio::stopDMA(void)
	{ AUDIO_StopDMA(); }