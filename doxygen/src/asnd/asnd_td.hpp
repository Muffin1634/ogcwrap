#pragma once
#ifndef wrap_asnd_td_h
#define wrap_asnd_td_h

namespace ogcwrap::asnd
{
	enum struct ASNDReturnValue : s8
	{
		OK,

		Invalid,
		NotAVoice,

		VoiceBusy,

		VoiceUnused,
		VoiceWorking,
		VoiceWaiting
	};

	enum struct ASNDVoiceFormat : u8
	{
		MonoU8,
		MonoS8,
		MonoBE16,
		MonoLE16,

		StereoU8,
		StereoS8,
		StereoBE16,
		StereoLE16
	};
}

#endif // wrap_asnd_td_h
/*! \file asnd_td.hpp <asnd/asnd_td.hpp>
 *  \brief Header file containing typedefs of enum structs for <CODE>\<asnd/asnd.hpp\></CODE>.
 *
 *  This header contains enums in the <CODE>ogcwrap::asnd</CODE> namespace for use with its functions.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \namespace ogcwrap::asnd
 *  \brief Namespace containing enums and functions related to the Accelerated SouND subsystem in libOGC.
 *
 */

/*! \enum ogcwrap::asnd::ASNDReturnValue
 *  \brief Enum to specify common return values of ASND functions.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \var ogcwrap::asnd::ASNDReturnValue::OK
 *  \brief This return value is used to indicate that a function was successful.
 *
 *  \var ogcwrap::asnd::ASNDReturnValue::Invalid
 *  \brief This return value is used to indicate that an input to a function is invalid.
 */

/*! \enum ogcwrap::asnd::ASNDVoiceFormat
 *  \brief Enum to specify the format of PCM samples that the DSP will use.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \var ogcwrap::asnd::ASNDVoiceFormat::MonoU8
 *  \brief Specifies that the PCM samples only have one sound channel (mono) and that they have unsigned 8-bit values.
 *
 *  \var ogcwrap::asnd::ASNDVoiceFormat::MonoS8
 *  \brief Specifies that the PCM samples are in mono and that they have signed 8-bit values.
 *
 *  \var ogcwrap::asnd::ASNDVoiceFormat::MonoBE16
 *  \brief Specifies that the PCM samples are in mono and that they have unsigned big-endian 16-bit values.
 *
 *  \var ogcwrap::asnd::ASNDVoiceFormat::MonoLE16
 *  \brief Specifies that the PCM samples are in mono and that they have unsigned little-endian 16-bit values.
 *
 *  \var ogcwrap::asnd::ASNDVoiceFormat::StereoU8
 *  \brief Specifies that the PCM samples have two sound channels (stereo) and that they have unsigned 8-bit values.
 *
 *  \var ogcwrap::asnd::ASNDVoiceFormat::StereoS8
 *  \brief Specifies that the PCM samples are in stereo and that they have signed 8-bit values.
 *
 *  \var ogcwrap::asnd::ASNDVoiceFormat::StereoBE16
 *  \brief Specifies that the PCM samples are in stereo and that they have unsigned big-endian 16-bit values.
 *
 *  \var ogcwrap::asnd::ASNDVoiceFormat::StereoLE16
 *  \brief Specifies that the PCM samples are in stereo and that they have unsigned little-endian 16-bit values.
 */