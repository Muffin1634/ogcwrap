#pragma once
#ifndef wrap_video_td_h
#define wrap_video_td_h

namespace ogcwrap
{
	namespace video
	{
		typedef enum tv_mode_t
		{
			TVM_ERROR = -1,

			NTSC,
			PAL,
			MPAL,
			EuRGB60,

			DEBUG_NTSC,
			DEBUG_PAL
		} TVMode;

		typedef enum retrace_time_t
		{
			PreRetrace,
			PostRetrace
		} RetraceTime;

		typedef enum ds_field_pos_t
		{
			DSFP_ERROR = -1,

			TopField = 1,
			BottomField = 0
		} DSFieldPos;
	}
}

using ogcwrap::video::TVMode;
using ogcwrap::video::RetraceTime;
using ogcwrap::video::DSFieldPos;

#endif // wrap_video_td_h