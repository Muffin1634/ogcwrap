/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap
{
	namespace aesnd
	{
		// enums
		enum aesnd_voice_fmt_t
		{
			MONO_U8,
			MONO_S8,
			MONO_U16,
			MONO_S16,

			STEREO_U8,
			STEREO_S8,
			STEREO_U16,
			STEREO_S16
		};

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
		AESNDVoiceCallback setVoiceCallback(AESNDPB *, AESNDVoiceCallback);

		// voice manipulation methods
		AESNDPB * allocateVoice(AESNDVoiceCallback cb);
		void freeVoice(AESNDPB *);
		void setVoiceStopStatus(AESNDPB *, bool);
		void setVoiceMuteStatus(AESNDPB *, bool);
		void setVoiceLoopStatus(AESNDPB *, bool);
		void setVoiceStreamStatus(AESNDPB *, bool);
		void setVoiceFormat(AESNDPB *, aesnd_voice_fmt_t);
		void setVoiceFrequency(AESNDPB *, f32);
		void setVoiceVolume(AESNDPB *, u16, u16);
		void setVoiceDelay(AESNDPB *, u32);
		void setVoiceBuffer(AESNDPB *, const void *, u32);
		void playVoice(AESNDPB *, aesnd_voice_fmt_t, const void *, u32, f32, u32, bool);

		// detail
		namespace detail
		{
			// encode (f<-b)

			// decode (f->b)
			u32 decodeAESNDVF(aesnd_voice_fmt_t);
		}
	}
}

/*******************************************************************************
 * functions
 */

using ogcwrap::aesnd::aesnd_voice_fmt_t;

using namespace ogcwrap::aesnd::detail;

void ogcwrap::aesnd::init(void)
	{ AESND_Init(); }

void ogcwrap::aesnd::reinit(void)
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

void ogcwrap::aesnd::setVoiceFormat(AESNDPB * voice, aesnd_voice_fmt_t format)
	{ AESND_SetVoiceFormat(voice, detail::decodeAESNDVF(format)); }

void ogcwrap::aesnd::setVoiceFrequency(AESNDPB * voice, f32 freq)
	{ AESND_SetVoiceFrequency(voice, freq); }

void ogcwrap::aesnd::setVoiceVolume(AESNDPB * voice, u16 left, u16 right)
	{ AESND_SetVoiceVolume(voice, left, right); }

void ogcwrap::aesnd::setVoiceDelay(AESNDPB * voice, u32 delay)
	{ AESND_SetVoiceDelay(voice, delay); }

void ogcwrap::aesnd::setVoiceBuffer(AESNDPB * voice, const void * buffer, u32 size)
	{ AESND_SetVoiceBuffer(voice, buffer, size); }

void ogcwrap::aesnd::playVoice(AESNDPB * voice, aesnd_voice_fmt_t format, const void * buffer, u32 size, f32 freq, u32 delay, bool statusLoop)
	{ AESND_PlayVoice(voice, detail::decodeAESNDVF(format), buffer, size, freq, delay, statusLoop); }

// ogcwrap::aesnd::detail

u32 ogcwrap::aesnd::detail::decodeAESNDVF(aesnd_voice_fmt_t format)
{
	switch (format)
	{
		case aesnd_voice_fmt_t::MONO_U8:
			return 4;
		case aesnd_voice_fmt_t::MONO_S8:
			return 0;
		case aesnd_voice_fmt_t::MONO_U16:
			return 6;
		case aesnd_voice_fmt_t::MONO_S16:
			return 2;
		case aesnd_voice_fmt_t::STEREO_U8:
			return 5;
		case aesnd_voice_fmt_t::STEREO_S8:
			return 1;
		case aesnd_voice_fmt_t::STEREO_U16:
			return 7;
		case aesnd_voice_fmt_t::STEREO_S16:
			return 3;

		default:
			return -1;
	}
}