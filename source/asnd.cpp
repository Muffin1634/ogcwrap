/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap
{
	namespace asnd
	{
		// enums
		enum asnd_ret_vals_t
		{
			OK = 0,

			INVALID = -1,
			NOTAVOICE = -2,

			VOICEBUSY = 1,

			VOICEUNUSED = 2,
			VOICEWORKING = 1,
			VOICEWAITING = 3
		};

		enum asnd_voice_fmt_t
		{
			MONO_U8,
			MONO_S8,
			MONO_BE16,
			MONO_LE16,

			STEREO_U8,
			STEREO_S8,
			STEREO_BE16,
			STEREO_LE16
		};

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
		asnd_ret_vals_t setVoiceVolume(u8, u8, u8);
		asnd_ret_vals_t setVoicePitch(u8, u32);

		// sound manipulation methods
		void playSound(void);
		void pauseSound(void);

		// voice manipulation methods
		asnd_ret_vals_t addVoice(u8, void *, s32);
		asnd_ret_vals_t playVoice(u8);
		asnd_ret_vals_t pauseVoice(u8);
		asnd_ret_vals_t stopVoice(u8);
		asnd_ret_vals_t getVoiceStatus(u8);
		asnd_ret_vals_t setVoice(u8, asnd_voice_fmt_t, u32, u32, void *, u32, u8, u8, ASNDVoiceCallback);
		asnd_ret_vals_t setInfiniteVoice(u8, asnd_voice_fmt_t, u32, u32, void *, u32, u8, u8);

		// testing methods
		bool testVoiceBufferUsing(u8, void *);
		bool testVoiceBufferReady(u8);

		namespace detail
		{
			// other
			int ANote2Freq(int, int, int);

			// encode (f<-b)

			// decode (f->b)
			u8 decodeASNDVF(asnd_voice_fmt_t);
		}
	}
}

/*******************************************************************************
 * functions
 */

using ogcwrap::asnd::asnd_ret_vals_t;
using ogcwrap::asnd::asnd_voice_fmt_t;

void ogcwrap::asnd::init(void)
	{ ASND_Init(); }

void ogcwrap::asnd::deinit(void)
	{ ASND_End(); }

u32 ogcwrap::asnd::getTime(void)
	{ return ASND_GetTime(); }

bool ogcwrap::asnd::getSoundPlayStatus(void)
	{ return (ASND_Is_Paused() == 1 ); }

u32 ogcwrap::asnd::getSampleRate(void)
	{ return ASND_GetAudioRate(); }

u32 ogcwrap::asnd::getSampleCount(void)
	{ return ASND_GetSampleCounter(); }

u32 ogcwrap::asnd::getSampleRateTick(void)
	{ return ASND_GetSamplesPerTick(); }

u8 ogcwrap::asnd::getFirstUnusedVoice(void)
	{ return ((u8)(ASND_GetFirstUnusedVoice())); }

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

asnd_ret_vals_t setVoiceVolume(u8 voice, u8 left, u8 right)
	{ return (ASND_ChangeVolumeVoice(voice, left, right) == 0 ? asnd_ret_vals_t::OK : asnd_ret_vals_t::INVALID); }

asnd_ret_vals_t ogcwrap::asnd::setVoicePitch(u8 voice, u32 pitch)
	{ return (ASND_ChangePitchVoice(voice, pitch) == 0 ? asnd_ret_vals_t::OK : asnd_ret_vals_t::INVALID); }

void ogcwrap::asnd::playSound(void)
	{ ASND_Pause(0); }

void ogcwrap::asnd::pauseSound(void)
	{ ASND_Pause(1); }

asnd_ret_vals_t ogcwrap::asnd::addVoice(u8 voice, void * samples, s32 sampleCount)
{
	switch (ASND_AddVoice(voice, samples, sampleCount))
	{
		case 0: // ok
			return asnd_ret_vals_t::OK;
		case -1: // invalid
			return asnd_ret_vals_t::INVALID;
		case 1: // busy
			return asnd_ret_vals_t::VOICEBUSY;

		default:
			return asnd_ret_vals_t::INVALID;
	}
}

asnd_ret_vals_t ogcwrap::asnd::playVoice(u8 voice)
	{ return (ASND_PauseVoice(voice, 0) == 0 ? asnd_ret_vals_t::OK : asnd_ret_vals_t::INVALID); }

asnd_ret_vals_t ogcwrap::asnd::pauseVoice(u8 voice)
	{ return (ASND_PauseVoice(voice, 1) == 0 ? asnd_ret_vals_t::OK : asnd_ret_vals_t::INVALID); }

asnd_ret_vals_t ogcwrap::asnd::stopVoice(u8 voice)
	{ return (ASND_StopVoice(voice) == 0 ? asnd_ret_vals_t::OK : asnd_ret_vals_t::INVALID); }

asnd_ret_vals_t ogcwrap::asnd::getVoiceStatus(u8 voice)
{
	switch (ASND_StatusVoice(voice))
	{
		case -1: // invalid
			return asnd_ret_vals_t::INVALID;
		case 2: // voice is unused
			return asnd_ret_vals_t::VOICEUNUSED;
		case 3: // voice is working
			return asnd_ret_vals_t::VOICEWORKING;
		case 4: // voice is waiting
			return asnd_ret_vals_t::VOICEWAITING;

		default:
			return asnd_ret_vals_t::INVALID;
	}
}

asnd_ret_vals_t ogcwrap::asnd::setVoice(u8 voice, asnd_voice_fmt_t sampleFormat, u32 pitch, u32 delay, void * samples, u32 sampleSize, u8 left, u8 right, ASNDVoiceCallback cb)
	{ return (ASND_SetVoice(voice, ogcwrap::asnd::detail::decodeASNDVF(sampleFormat), pitch, delay, samples, sampleSize, left, right, cb) == 0 ? asnd_ret_vals_t::OK : asnd_ret_vals_t::INVALID); }

asnd_ret_vals_t ogcwrap::asnd::setInfiniteVoice(u8 voice, asnd_voice_fmt_t sampleFormat, u32 pitch, u32 delay, void * samples, u32 sampleSize, u8 left, u8 right)
	{ return (ASND_SetInfiniteVoice(voice, ogcwrap::asnd::detail::decodeASNDVF(sampleFormat), pitch, delay, samples, sampleSize, left, right) == 0 ? asnd_ret_vals_t::OK : asnd_ret_vals_t::INVALID); }


bool ogcwrap::asnd::testVoiceBufferUsing(u8 voice, void * buffer)
	{ return (ASND_TestPointer(voice, buffer) == 0 ? true : false); }

bool ogcwrap::asnd::testVoiceBufferReady(u8 voice)
	{ return (ASND_TestVoiceBufferReady(voice) == 0 ? true : false); }

// ogcwrap::asnd::detail

int ogcwrap::asnd::detail::ANote2Freq(int note, int freqbase, int notebase)
	{ return ANote2Freq(note, freqbase, notebase); }


u8 ogcwrap::asnd::detail::decodeASNDVF(asnd_voice_fmt_t format)
{
	switch (format)
	{
		case asnd_voice_fmt_t::MONO_U8:
			return 4;
		case asnd_voice_fmt_t::MONO_S8:
			return 0;
		case asnd_voice_fmt_t::MONO_BE16:
			return 1;
		case asnd_voice_fmt_t::MONO_LE16:
			return 5;
		case asnd_voice_fmt_t::STEREO_U8:
			return 6;
		case asnd_voice_fmt_t::STEREO_S8:
			return 2;
		case asnd_voice_fmt_t::STEREO_BE16:
			return 3;
		case asnd_voice_fmt_t::STEREO_LE16:
			return 7;

		default:
			return -1;
	}
}