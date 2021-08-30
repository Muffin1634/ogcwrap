#pragma once
#ifndef wrap_aesnd_td_h
#define wrap_aesnd_td_h

namespace ogcwrap
{
	namespace aesnd
	{
		typedef enum aesnd_voice_format_t
		{
			MONO_U8,
			MONO_S8,
			MONO_U16,
			MONO_S16,

			STEREO_U8,
			STEREO_S8,
			STEREO_U16,
			STEREO_S16
		} AESNDVoiceFormat;
	}
}

using ogcwrap::aesnd::AESNDVoiceFormat;

#endif // wrap_aesnd_td_h