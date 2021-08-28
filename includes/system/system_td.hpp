#pragma once
#ifndef wrap_system_td_h
#define wrap_system_td_h

namespace ogcwrap
{
	namespace system
	{
		typedef enum sys_language_t
		{
			English,
			German,
			French,
			Spanish,
			Italian,
			Dutch
		} SystemLanguage;

		typedef enum sys_audio_mode_t
		{
			Mono,
			Stereo
		} SystemAudioMode;

		typedef enum sys_video_mode_t
		{
			NTSC,
			PAL,
			MPAL
		} SystemVideoMode;
	}
}

using ogcwrap::system::SystemLanguage;
using ogcwrap::system::SystemAudioMode;
using ogcwrap::system::SystemVideoMode;

#endif // wrap_system_td_h
