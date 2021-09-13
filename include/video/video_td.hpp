#pragma once
#ifndef wrap_video_td_h
#define wrap_video_td_h

namespace ogcwrap::video
{
	typedef enum struct tv_mode_t
	{
		NTSC,
		PAL,
		MPAL,
		EuRGB60,

		DEBUG_NTSC,
		DEBUG_PAL
	} TVMode;

	typedef enum struct retrace_time_t
	{
		PreRetrace,
		PostRetrace
	} RetraceTime;

	typedef enum struct ds_field_pos_t
	{
		TopField = 1,
		BottomField = 0
	} DSFieldPos;
}

#endif // wrap_video_td_h