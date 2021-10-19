/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "asnd/asnd_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::asnd
{
	// subsystem management
	void init(void);
	void deinit(void);

	// gethods
	u32 getTime(void);
	bool getSoundPlayStatus(void);
	int getNoteFreq(int, int, int);
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

	// sound manipulation methods
	void playSound(void);
	void pauseSound(void);

	// voice manipulation methods
	asnd_ret_vals_t addVoice(u8, void *, u32);
	asnd_ret_vals_t playVoice(u8);
	asnd_ret_vals_t pauseVoice(u8);
	asnd_ret_vals_t stopVoice(u8);
	asnd_ret_vals_t getVoiceStatus(u8);
	asnd_ret_vals_t setVoice(u8, asnd_voice_fmt_t, u32, u32, void *, u32, u8, u8, ASNDVoiceCallback);
	asnd_ret_vals_t setInfiniteVoice(u8, asnd_voice_fmt_t, u32, u32, void *, u32, u8, u8);
	asnd_ret_vals_t setVoiceVolume(u8, u8, u8);
	asnd_ret_vals_t setVoicePitch(u8, u32);

	// testing methods
	bool testVoiceBufferUsing(u8, void *);
	bool testVoiceBufferReady(u8);
}

/*******************************************************************************
 * functions
 */

using ogcwrap::asnd::asnd_ret_vals_t;

void ogcwrap::asnd::init(void)
	{ ASND_Init(); }

void ogcwrap::asnd::deinit(void)
	{ ASND_End(); }

u32 ogcwrap::asnd::getTime(void)
	{ return ASND_GetTime(); }

bool ogcwrap::asnd::getSoundPlayStatus(void)
	{ return ~ASND_Is_Paused(); }

int ogcwrap::asnd::getNoteFreq(int note, int freqbase, int notebase)
	{ return ANote2Freq(note, freqbase, notebase); }

u32 ogcwrap::asnd::getSampleRate(void)
	{ return ASND_GetAudioRate(); }

u32 ogcwrap::asnd::getSampleCount(void)
	{ return ASND_GetSampleCounter(); }

u32 ogcwrap::asnd::getSampleRateTick(void)
	{ return ASND_GetSamplesPerTick(); }

u8 ogcwrap::asnd::getFirstUnusedVoice(void)
	{ return ASND_GetFirstUnusedVoice(); }

u32 ogcwrap::asnd::getVoiceTicks(u8 voice)
	{ return ASND_GetTickCounterVoice(voice); }

u32 ogcwrap::asnd::getVoiceTime(u8 voice)
	{ return ASND_GetTimerVoice(voice); }

u8 ogcwrap::asnd::getDSPPercentUse(void)
	{ return ASND_GetDSP_PercentUse(); }

u32 ogcwrap::asnd::getDSPProcessTime(void)
	{ return ASND_GetDSP_ProcessTime(); }

void ogcwrap::asnd::setTime(u32 time)
	{ ASND_SetTime(time); }

void ogcwrap::asnd::setCallback(void (*cb)(void))
	{ ASND_SetCallback(cb); }

void ogcwrap::asnd::playSound(void)
	{ ASND_Pause(0); }

void ogcwrap::asnd::pauseSound(void)
	{ ASND_Pause(1); }

asnd_ret_vals_t ogcwrap::asnd::addVoice(u8 voice, void * samples, u32 sampleCount)
	{ return mcast(asnd_ret_vals_t, ASND_AddVoice(voice, samples, sampleCount)); }

asnd_ret_vals_t ogcwrap::asnd::playVoice(u8 voice)
	{ return mcast(asnd_ret_vals_t, ASND_PauseVoice(voice, 0)); }

asnd_ret_vals_t ogcwrap::asnd::pauseVoice(u8 voice)
	{ return mcast(asnd_ret_vals_t, ASND_PauseVoice(voice, 1)); }

asnd_ret_vals_t ogcwrap::asnd::stopVoice(u8 voice)
	{ return mcast(asnd_ret_vals_t, ASND_StopVoice(voice)); }

asnd_ret_vals_t ogcwrap::asnd::getVoiceStatus(u8 voice)
	{ return mcast(asnd_ret_vals_t, ASND_StatusVoice(voice) + 2); }

asnd_ret_vals_t ogcwrap::asnd::setVoice(u8 voice, asnd_voice_fmt_t sampleFormat, u32 pitch, u32 delay, void * samples, u32 sampleSize, u8 left, u8 right, ASNDVoiceCallback cb)
	{ return mcast(asnd_ret_vals_t, ASND_SetVoice(voice, mcast(s32, sampleFormat), pitch, delay, samples, sampleSize, left, right, cb)); }

asnd_ret_vals_t ogcwrap::asnd::setInfiniteVoice(u8 voice, asnd_voice_fmt_t sampleFormat, u32 pitch, u32 delay, void * samples, u32 sampleSize, u8 left, u8 right)
	{ return mcast(asnd_ret_vals_t, ASND_SetInfiniteVoice(voice, mcast(s32, sampleFormat), pitch, delay, samples, sampleSize, left, right)); }

asnd_ret_vals_t ogcwrap::asnd::setVoiceVolume(u8 voice, u8 left, u8 right)
	{ return mcast(asnd_ret_vals_t, ASND_ChangeVolumeVoice(voice, left, right)); }

asnd_ret_vals_t ogcwrap::asnd::setVoicePitch(u8 voice, u32 pitch)
	{ return mcast(asnd_ret_vals_t, ASND_ChangePitchVoice(voice, pitch)); }

bool ogcwrap::asnd::testVoiceBufferUsing(u8 voice, void * buffer)
	{ return ASND_TestPointer(voice, buffer); }

bool ogcwrap::asnd::testVoiceBufferReady(u8 voice)
	{ return ASND_TestVoiceBufferReady(voice); }