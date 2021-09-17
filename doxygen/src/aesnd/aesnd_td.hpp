#pragma once
#ifndef wrap_aesnd_td_h
#define wrap_aesnd_td_h

namespace ogcwrap::aesnd
{
	enum struct AESNDVoiceFormat : u8
	{
		MonoU8		= 4,
		MonoS8		= 0,
		MonoU16		= 6,
		MonoS16		= 2,

		StereoU8	= 5,
		StereoS8	= 1,
		StereoU16	= 7,
		StereoS16	= 3
	};
}

#endif // wrap_aesnd_td_h
/*! \file aesnd_td.hpp <aesnd/aesnd_td.hpp>
 *  \brief Header file containing typedefs of enum structs for <CODE>\<aesnd/aesnd.hpp\></CODE>.
 *
 *  This header contains enums in the <CODE>ogcwrap::aesnd</CODE> namespace for use with its functions.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \namespace ogcwrap::aesnd
 *  \brief Namespace containing enums and functions related to the Accelerated (Extended?) SouND subsystem.
 *
 */

/*! \enum ogcwrap::aesnd::AESNDVoiceFormat
 *  \brief Enum to specify the format of PCM samples that the DSP will use.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \var ogcwrap::aesnd::AESNDVoiceFormat::MonoU8
 *  \brief Specifies that the PCM samples only have one sound channel (mono) and that they have unsigned 8-bit values.
 *
 *  \var ogcwrap::aesnd::AESNDVoiceFormat::MonoS8
 *  \brief Specifies that the PCM samples are in mono and that they have signed 8-bit values.
 *
 *  \var ogcwrap::aesnd::AESNDVoiceFormat::MonoU16
 *  \brief Specifies that the PCM samples are in mono and that they have unsigned 16-bit values.
 *
 *  \var ogcwrap::aesnd::AESNDVoiceFormat::MonoS16
 *  \brief Specifies that the PCM samples are in mono and that they have signed 16-bit values.
 *
 *  \var ogcwrap::aesnd::AESNDVoiceFormat::StereoU8
 *  \brief Specifies that the PCM samples have two sound channels (stereo) and that they have unsigned 8-bit values.
 *
 *  \var ogcwrap::aesnd::AESNDVoiceFormat::StereoS8
 *  \brief Specifies that the PCM samples are in stereo and that they have signed 8-bit values.
 *
 *  \var ogcwrap::aesnd::AESNDVoiceFormat::StereoU16
 *  \brief Specifies that the PCM samples are in stereo and that they have unsigned 16-bit values.
 *
 *  \var ogcwrap::aesnd::AESNDVoiceFormat::StereoS16
 *  \brief Specifies that the PCM samples are in stereo and that they have signed 16-bit values.
 */