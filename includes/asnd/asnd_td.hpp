#pragma once
#ifndef wrap_asnd_td_h
#define wrap_asnd_td_h

namespace ogcwrap
{
	namespace asnd
	{
		typedef enum asnd_ret_vals_t
		{
			OK = 0,

			INVALID = -1,
			NOTAVOICE = -2,

			VOICEBUSY = 1,

			VOICEUNUSED = 2,
			VOICEWORKING = 3,
			VOICEWAITING = 4
		} ASNDReturnValue;

		typedef enum snd_voice_fmt_t
		{
			MONO_U8,
			MONO_S8,
			MONO_BE16,
			MONO_LE16,

			STEREO_U8,
			STEREO_S8,
			STEREO_BE16,
			STEREO_LE16
		} VoiceFormat;
	}
}

using ogcwrap::asnd::ASNDReturnValue;
using ogcwrap::asnd::VoiceFormat;

#endif // wrap_asnd_td_h