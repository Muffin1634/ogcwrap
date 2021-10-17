#pragma once
#ifndef wrap_aesnd_h
#define wrap_aesnd_h

#include <gctypes.h>
#include <aesndlib.h>

#include "aesnd/aesnd_td.hpp"

namespace ogcwrap::aesnd
{
	// library management
	void init(void);
	void deinit(void);
	void play(void);
	void pause(void);

	// gethods
	u32 getDSPProcessTime(void);
	f32 getDSPProcessUsage(void);

	// sethods
	AESNDAudioCallback setAudioCallback(AESNDAudioCallback cb);
	AESNDVoiceCallback setVoiceCallback(AESNDPB * voice, AESNDVoiceCallback cb);

	// voice manipulation methods
	AESNDPB * allocateVoice(AESNDVoiceCallback cb);
	void freeVoice(AESNDPB * voice);
	void setVoiceStopStatus(AESNDPB * voice, bool status);
	void setVoiceMuteStatus(AESNDPB * voice, bool status);
	void setVoiceLoopStatus(AESNDPB * voice, bool status);
	void setVoiceStreamStatus(AESNDPB * voice, bool status);
	void setVoiceFormat(AESNDPB * voice, AESNDVoiceFormat format);
	void setVoiceFrequency(AESNDPB * voice, f32 freq);
	void setVoiceVolume(AESNDPB * voice, u16 left, u16 right);
	void setVoiceDelay(AESNDPB * voice, u32 delay);
	void setVoiceBuffer(AESNDPB * voice, const void * buffer, u32 size);
	void playVoice(AESNDPB * voice, AESNDVoiceFormat format, const void * buffer, u32 size, f32 freq, u32 delay, bool statusLoop);
}

#endif // wrap_aesnd_h
/*! \file aesnd.hpp <aesnd/aesnd.hpp>
 *  \brief Header file for the wrapper of the Accelerated (Extended?) SouND subsystem.
 *
 *  This header contains functions in the <CODE>ogcwrap::aesnd</CODE> namespace for initializing the AESND subsystem,
 *  managing and gathering statistics from the Digital Sound Processor (DSP), and managing individual voices within it.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \namespace ogcwrap::aesnd
 *  \brief Namespace containing enums and functions related to the Accelerated (Extended?) SouND subsystem in libOGC.
 *
 */

/*! \fn void ogcwrap::aesnd::init(void)
 *  \brief Initializes the AESND subsystem.
 *
 *  \return none
 */

/*! \fn void ogcwrap::aesnd::deinit(void)
 *  \brief Shuts the AESND subsystem down.
 *
 *  \return none
 */

/*! \fn void ogcwrap::aesnd::play(void)
 *  \brief Begins playback of all allocated voices in the DSP.
 *
 *  \return none
 */

/*! \fn void ogcwrap::aesnd::pause(void)
 *  \brief Halts playback of all allocated voices in the DSP.
 *
 *  \return none
 */

/*! \fn u32 ogcwrap::aesnd::getDSPProcessTime(void)
 *  \brief Gets the amount of time the DSP has been processing commands, in seconds.
 *
 *  \return The amount of time the DSP has been processing commands, in seconds.
 */

/*! \fn f32 ogcwrap::aesnd::getDSPProcessUsage(void)
 *  \brief Gets the percentage of time spent processing commands to time spent powered on.
 *
 *  \return Percent of time spent processing commands.
 */

/*! \fn AESNDAudioCallback ogcwrap::aesnd::setAudioCallback(AESNDAudioCallback cb)
 *  \brief Sets the general callback function for (???).
 *
 *  The callback function given in the argument will be used whenever (???)
 *
 *  \param[in] cb Callback function to register to (???).
 *
 *  \return The last callback function that was assigned to (???).
 */

/*! \fn AESNDVoiceCallback ogcwrap::aesnd::setVoiceCallback(AESNDPB * voice, AESNDVoiceCallback cb)
 *  \brief Sets the callback function for a specific voice.
 *
 *  The callback function given in the second argument will be used whenever (???)
 *
 *  \param[in,out] voice A pointer to the AESNDPB struct belonging to the voice you want to register the callback to.
 *  \param[in]     cb    Callback function to register to the voice.
 *
 *  \return The last callback function that was assigned to this voice.
 */

/*! \fn AESNDPB * ogcwrap::aesnd::allocateVoice(AESNDVoiceCallback cb)
 *  \brief Allocates some space in memory(?) for a voice and sets the initial callback function.
 *
 *  \param[in] cb Callback function to register to the voice.
 *
 *  \return A pointer to the AESNDPB struct holding information about the newly-allocated voice.
 */

/*! \fn void ogcwrap::aesnd::freeVoice(AESNDPB * voice)
 *  \brief Frees the space in memory(?) that was allocated for the voice given by the AESNDPB pointer.
 *
 *  \param[in] voice A pointer to the AESNDPB struct holding information about the voice to free.
 *
 *  \return none
 */

/*! \fn void ogcwrap::aesnd::setVoiceStopStatus(AESNDPB * voice, bool status)
 *  \brief Sets the pause status of the given voice <CODE>voice</CODE> to <CODE>status</CODE>.
 *
 *  \param[in,out] voice  A pointer to the AESNDPB struct holding information about the voice to modify.
 *  \param[in]     status Boolean stating whether or not the voice should be stopped:
 *                        <CODE>true</CODE> if it should be stopped,
 *                        <CODE>false</CODE> otherwise.
 *
 *  \return none
 */

/*! \fn void ogcwrap::aesnd::setVoiceMuteStatus(AESNDPB * voice, bool status)
 *  \brief Sets the mute status of the given voice <CODE>voice</CODE> to <CODE>status</CODE>.
 *
 *  \param[in,out] voice  A pointer to the AESNDPB struct holding information about the voice to modify.
 *  \param[in]     status Boolean stating whether or not the voice should be muted:
 *                        <CODE>true</CODE> if it should be muted,
 *                        <CODE>false</CODE> otherwise.
 *
 *  \return none
 */

/*! \fn void ogcwrap::aesnd::setVoiceLoopStatus(AESNDPB * voice, bool status)
 *  \brief Sets the loop status of the given voice <CODE>voice</CODE> to <CODE>status</CODE>.
 *
 *  \param[in,out] voice  A pointer to the AESNDPB struct holding information about the voice to modify.
 *  \param[in]     status Boolean stating whether or not the voice should loop:
 *                        <CODE>true</CODE> if it should loop,
 *                        <CODE>false</CODE> otherwise.
 *
 *  \return none
 */

/*! \fn void ogcwrap::aesnd::setVoiceStreamStatus(AESNDPB * voice, bool status)
 *  \brief Sets the stream status of the given voice <CODE>voice</CODE> to <CODE>status</CODE>.
 *
 *  \param[in,out] voice  A pointer to the AESNDPB struct holding information about the voice to modify.
 *  \param[in]     status Boolean stating whether or not the voice should stream:
 *                        <CODE>true</CODE> if it should stream,
 *                        <CODE>false</CODE> otherwise.
 *
 *  \return none
 */

/*! \fn void ogcwrap::aesnd::setVoiceFormat(AESNDPB * voice, AESNDVoiceFormat format)
 *  \brief Sets the format of the given voice <CODE>voice</CODE>'s PCM samples to <CODE>format</CODE>.
 *
 *  \param[in,out] voice  A pointer to the AESNDPB struct holding information about the voice to modify.
 *  \param[in]     format The format that the PCM samples that will be supplied to this voice are stored in.
 *
 *  \return none
 */

/*! \fn void ogcwrap::aesnd::setVoiceFrequency(AESNDPB * voice, f32 freq)
 *  \brief Sets the frequency of the given voice <CODE>voice</CODE>'s PCM samples to <CODE>status</CODE>.
 *
 *  \note The frequency does not necessarily have to be <CODE>VOICE_FREQ32KHZ</CODE>, <CODE>VOICE_FREQ48KHZ</CODE>, or
 *        <CODE>DSP_DEFAULT_FREQ</CODE>; it could be any frequency. However, it is recommended that the PCM samples be
 *        in one of these formats to ensure compatibility.
 *
 *  \param[in,out] voice A pointer to the AESNDPB struct holding information about the voice to modify.
 *  \param[in]     freq  The frequency of the PCM samples that will be supplied to this voice.
 *
 *  \return none
 */

/*! \fn void ogcwrap::aesnd::setVoiceVolume(AESNDPB * voice, u16 left, u16 right)
 *  \brief Sets the channel volumes of the given voice <CODE>voice</CODE> to <CODE>left</CODE> and <CODE>right</CODE>,
 *         respectively.
 *
 *  \param[in,out] voice A pointer to the AESNDPB struct holding information about the voice to modify.
 *  \param[in]     left  The new volume of the left  audio channel.
 *  \param[in]     right The new volume of the right audio channel.
 *
 *  \return none
 */

/*! \fn void ogcwrap::aesnd::setVoiceDelay(AESNDPB * voice, u32 delay)
 *  \brief Sets the delay of the given voice <CODE>voice</CODE> to <CODE>delay</CODE>.
 *
 *  \param[in,out] voice A pointer to the AESNDPB struct holding information about the voice to modify.
 *  \param[in]     delay The amount of delay that the voice should have, given in (???).
 *
 *  \return none
 */

/*! \fn void ogcwrap::aesnd::setVoiceBuffer(AESNDPB * voice, const void * buffer, u32 size)
 *  \brief Sets the sample buffer of the given voice <CODE>voice</CODE>.
 *
 *  \param[in,out] voice  A pointer to the AESNDPB struct holding information about the voice to modify.
 *  \param[in]     buffer The sample buffer to assign to the voice.
 *  \param[in]     size   The size of the sample buffer.
 *
 *  \return none
 */

/*! \fn void ogcwrap::aesnd::playVoice(AESNDPB * voice, AESNDVoiceFormat format, const void * buffer, u32 size, f32 freq, u32 delay, bool statusLoop)
 *  \brief Starts playback of the given voice <CODE>voice</CODE> with the given settings.
 *
 *  \param[in,out] voice  A pointer to the AESNDPB struct holding information about the voice to start playback on.
 *  \param[in]     format The format that the PCM samples that will be supplied to this voice are stored in.
 *  \param[in]     buffer The sample buffer to assign to the voice.
 *  \param[in]     size   The size of the sample buffer.
 *  \param[in]     freq   The frequency of the PCM samples that will be supplied to this voice.
 *  \param[in]     delay  The amount of delay that the voice should have, given in (???).
 *  \param[in]     status Boolean stating whether or not the voice should loop:
 *                        <CODE>true</CODE> if it should loop,
 *                        <CODE>false</CODE> otherwise.
 *
 *  \return none
 */