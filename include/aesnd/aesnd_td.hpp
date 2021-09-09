#pragma once
#ifndef wrap_aesnd_td_h
#define wrap_aesnd_td_h

namespace ogcwrap::aesnd
{
	typedef enum struct aesnd_voice_format_t
	{
		MonoU8		= 4,
		MonoS8		= 0,
		MonoU16		= 6,
		MonoS16		= 2,

		StereoU8	= 5,
		StereoS8	= 1,
		StereoU16	= 7,
		StereoS16	= 3
	} AESNDVoiceFormat;
}

#endif // wrap_aesnd_td_h