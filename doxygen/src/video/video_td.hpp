#pragma once
#ifndef wrap_video_td_h
#define wrap_video_td_h

namespace ogcwrap::video
{
	enum struct TVMode
	{
		NTSC,
		PAL,
		MPAL,
		EuRGB60,

		DEBUG_NTSC,
		DEBUG_PAL
	};

	enum struct RetraceTime
	{
		PreRetrace,
		PostRetrace
	};

	enum struct DSFieldPos
	{
		TopField = 1,
		BottomField = 0
	};
}

#endif // wrap_video_td_h
/*! \file video_td.hpp <video/video_td.hpp>
 *  \brief Header file containing typedefs of enum structs for <CODE>\<video/video.hpp\></CODE>.
 *
 *  This header contains enums in the <CODE>ogcwrap::video</CODE> namespace for use with its functions.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \namespace ogcwrap::video
 *  \brief Namespace containing enums and functions related to the video subsystem in libOGC.
 */

/*! \enum ogcwrap::video::TVMode
 *  \brief Enum to specify which video standard the Wii should use.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \var ogcwrap::video::TVMode::NTSC
 *  \brief Use the NTSC standard found in North America and Japan.
 *
 *  \var ogcwrap::video::TVMode::PAL
 *  \brief Use the PAL standard found in European countries.
 *
 *  \var ogcwrap::video::TVMode::MPAL
 *  \brief Use the MPAL standard found in Brazil.
 *
 *  It is somewhat similar to the NTSC standard.
 *
 *  \var ogcwrap::video::TVMode::EuRGB60
 *  \brief Use the EuRGB60 standard found in European countries.
 *
 *  Using 480 lines and runnning at 60Hz, this format has the same aspect ratio and timing as the NTSC standard.
 *
 *  \var ogcwrap::video::TVMode::DEBUG_NTSC
 *  \brief Use the DEBUG_NTSC standard, for use with North America and Japan.
 *
 *  \note A special decoder is needed to use this standard.
 *
 *  \var ogcwrap::video::TVMode::DEBUG_PAL
 *  \brief Use the DEBUG_PAL standard, for use with European countries.
 *
 *  \note A special decoder is needed to use this standard.
 */

/*! \enum ogcwrap::video::RetraceTime
 *  \brief Enum specifying whether the <CODE>VIRetraceCallback</CODE> should be called before or after the retrace.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \var ogcwrap::video::RetraceTime::PreRetrace
 *  \brief Specify that the <CODE>VIRetraceCallback</CODE> should be called <I>before</I> the retrace occurs.
 *
 *  \var ogcwrap::video::RetraceTime::PostRetrace
 *  \brief Specify that the <CODE>VIRetraceCallback</CODE> should be called <I>after</I> the retrace occurs.
 */

/*! \enum ogcwrap::video::DSFieldPos
 *  \brief Enum specifying which field of the DS is next to be drawn.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \var ogcwrap::video::DSFieldPos::TopField
 *  \brief The top field of the DS will be drawn next.
 *
 *  \var ogcwrap::video::DSFieldPos::BottomField
 *  \brief The bottom field of the DS field will be drawn next.
 *
 *  This field has a touchscreen available.
 */