#pragma once
#ifndef wrap_system_td_h
#define wrap_system_td_h

namespace ogcwrap::system
{
	typedef enum struct sys_reset_mode_t
	{
		PowerOff		= 4,
		PowerOffIdle	= 6,
		PowerOffStandby	= 5,
		Shutdown		= 2,

		Restart			= 0,
		HotReset,
		ReturnToMenu	= 3
	} SystemResetMode;

	typedef enum struct sys_language_t
	{
		English,
		German,
		French,
		Spanish,
		Italian,
		Dutch
	} SystemLanguage;

	typedef enum struct sys_audio_mode_t
	{
		Mono,
		Stereo
	} SystemAudioMode;

	typedef enum struct sys_video_mode_t
	{
		NTSC,
		PAL,
		MPAL
	} SystemVideoMode;
}

#endif // wrap_system_td_h
