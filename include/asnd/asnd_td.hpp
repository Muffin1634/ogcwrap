#pragma once
#ifndef wrap_asnd_td_h
#define wrap_asnd_td_h

namespace ogcwrap::asnd
{
	typedef enum struct asnd_ret_vals_t : s32
	{
		OK,

		Invalid			= -1,
		NotAVoice		= -2,

		VoiceBusy		= 1,

		VoiceUnused,
		VoiceWorking,
		VoiceWaiting
	} ASNDReturnValue;

	typedef enum struct asnd_voice_fmt_t
	{
		MonoU8			= 4,
		MonoS8			= 0,
		MonoBE16,
		MonoLE16		= 5,

		StereoU8,
		StereoS8		= 2,
		StereoBE16,
		StereoLE16		= 7
	} ASNDVoiceFormat;
}

using ogcwrap::asnd::ASNDReturnValue;

#endif // wrap_asnd_td_h