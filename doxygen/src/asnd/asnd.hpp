#pragma once
#ifndef wrap_asnd_h
#define wrap_asnd_h

#include <gctypes.h>
#include <asndlib.h>

#include "asnd/asnd_td.hpp"

namespace ogcwrap::asnd
{
	// library management
	void init(void);
	void deinit(void);

	// gethods
	u32 getTime(void);
	bool getSoundPlayStatus(void);
	int getNoteFreq(int note, int freqbase, int notebase);
	u32 getSampleRate(void);
	u32 getSampleCount(void);
	u32 getSampleRateTick(void);
	u8 getFirstUnusedVoice(void);
	u32 getVoiceTicks(u8 voice);
	u32 getVoiceTime(u8 voice);
	u8 getDSPPercentUse(void);
	u32 getDSPProcessTime(void);

	// sethods
	void setTime(u32 time);
	void setCallback(void (*cb)(void));

	// sound manipulation methods
	void playSound(void);
	void pauseSound(void);

	// voice manipulation methods
	ASNDReturnValue setVoice(u8 voice, ASNDVoiceFormat format, u32 pitch, u32 delay, void * samples, u32 samplesize, u8 left, u8 right, ASNDVoiceCallback cb);
	ASNDReturnValue setInfiniteVoice(u8 voice, ASNDVoiceFormat format, u32 patch, u32 delay, void * samples, u32 samplesize, u8 left, u8 right);
	ASNDReturnValue addVoice(u8 voice, void * samples, u32 samplesize);
	ASNDReturnValue playVoice(u8 voice);
	ASNDReturnValue pauseVoice(u8 voice);
	ASNDReturnValue stopVoice(u8 voice);
	ASNDReturnValue getVoiceStatus(u8 voice);
	ASNDReturnValue setVoiceVolume(u8 voice, u8 left, u8 right);
	ASNDReturnValue setVoicePitch(u8 voice, u32 pitch);

	// testing methods
	bool testVoiceBufferUsing(u8 voice, void * buffer);
	bool testVoiceBufferReady(u8 voice);
}

#endif // wrap_asnd_h
/*! \file asnd.hpp <asnd/asnd.hpp>
 *  \brief Header file for the wrapper of the Accelerated SouND subsystem.
 *
 *  This header contains functions in the <CODE>ogcwrap::asnd</CODE> namespace for initializing the ASND subsystem,
 *  managing and gathering statistics from tho Digital Signal Processor (DSP), managing individual voices, and testing
 *  sample buffers.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \namespace ogcwrap::asnd
 *  \brief Namespace containing enums and functions related to the Accelerated SouND subsystem in libOGC.
 *
 */

/*! \fn void ogcwrap::asnd::init(void)
 *  \brief Initializes the ASND subsystem.
 *
 *  \return none
 */

/*! \fn void ogcwrap::asnd::deinit(void)
 *  \brief Shuts the ASND subsystem down.
 *
 *  \return none
 */

/*! \fn u32 ogcwrap::asnd::getTime(void)
 *  \brief Gets the current system time
 *
 *  \warning note to self: is this even system time? SYS_GetTime() returns a u64 but this returns a u32???
 *
 *  \return The system time, in milliseconds since 2000.
 */

/*! \fn bool ogcwrap::asnd::getSoundPlayStatus(void)
 *  \brief Checks whether sound is playing or not.
 *
 *  \note <CODE>true</CODE> does not necessarily mean sound is playing; it just means that the sound is in play mode
 *        rather than pause mode. Voices may not have any samples to play and therefore may not be playing anything.
 *
 *  \return <CODE>true</CODE> if sound is playing, <CODE>false</CODE> otherwise
 */

/*! \fn int ogcwrap::asnd::getNoteFreq(int note, int freqbase, int notebase)
 *  \brief Does some math to get a note frequency, i think
 *
 *  not sure
 *
 *  \param[in] note     Note to play (see the <A HREF="https://libogc.devkitpro.org/group__notecode.html#gaecdf46a919e14720bd2843c6c191de8f">NOTE()</A>
 *                      macro here).
 *  \param[in] freqbase frequency base of the sample
 *  \param[in] notebase notecode of the sample (see <A HREF="https://libogc.devkitpro.org/group__notecode.html#">these enums</A>
 *                      here).
 *
 *  \return Frequency (of what? new note?)
 */

/*! \fn u32 ogcwrap::asnd::getSampleRate(void)
 *  \brief Gets the sample rate of the audio.
 *
 *  \deprecated This function is for backwards compatibility with ASND_GetAudioRate(), which itself is for compatibility
 *              with the original SNDLIB.
 *
 *  \return The unsigned integer 48,000. This return value is constant.
 */

/*! \fn u32 ogcwrap::asnd::getSampleCount(void)
 *  \brief Gets the number of samples that have (been processed?)
 *
 *  \return The number of samples that have (been processed?)
 */

/*! \fn u32 ogcwrap::asnd::getSampleRateTick(void)
 *  \brief Gets the amount of samples sent in one tick.
 *
 *  \return The amount of samples that are sent in one tick
 */

/*! \fn u8 ogcwrap::asnd::getFirstUnusedVoice(void)
 *  \brief Gets the first available voice that is not being used.
 *
 *  \return The first unused voice.
 */

/*! \fn u32 ogcwrap::asnd::getVoiceTicks(u8 voice)
 *  \brief Gets the amount of (ticks the specified voice has been active for?)
 *
 *  \param[in] voice The voice to specify.
 *
 *  \return The amount of (ticks the voice has been active for?)
 */

/*! \fn u32 ogcwrap::asnd::getVoiceTime(u8 voice)
 *  \brief Gets the (amount of time this voice has been active for?)
 *
 *  \param[in] voice The voice to specify.
 *
 *  \return The (amount of time this voice has been active for?)
 */

/*! \fn u8 ogcwrap::asnd::getDSPPercentUse(void)
 *  \brief Gets the percentage of activity the DSP (Digital Signal Processor) has been used for(?)
 *
 *  \return An integer percentage, out of the program's total running time(?)
 */

/*! \fn u32 ogcwrap::asnd::getDSPProcessTime(void)
 *  \brief Gets the (amount of time the DSP has been active?)
 *
 *  \return The (amount of time the DSP has been active?)
 */

/*! \fn void ogcwrap::asnd::setTime(u32 time)
 *  \brief Sets the system time.
 *
 *  \param[in] time The amount of milliseconds since 2000.
 *
 *  \return none
 */

/*! \fn void ogcwrap::asnd::setCallback(void (*cb)(void))
 *  \brief Sets a callback function (for what?)
 *
 *  \param[in] cb Callback function pointer, taking no arguments and returning <CODE>void</CODE>.
 *
 *  \return none
 */

/*! \fn void ogcwrap::asnd::playSound(void)
 *  \brief Begins playback of all voices.
 *
 *  \return none
 */

/*! \fn void ogcwrap::asnd::pauseSound(void)
 *  \brief Stops playback of all voices.
 *
 *  \return none
 */

/*! \fn ASNDReturnValue ogcwrap::asnd::setVoice(u8 voice, ASNDVoiceFormat format, u32 pitch, u32 delay, void * samples, u32 samplesize, u8 left, u8 right, ASNDVoiceCallback cb)
 *  \brief Sets up a voice with the given arguments and starts playing after the time specified in <CODE>delay</CODE> has passed.
 *
 *  \note All voices play audio in 16-bit stereo, regardless of the format they receive.
 *
 *  \note Periverbatim from libASND: "<i>callback<i> is used to implement a double buffer. When the second buffer is
 *  empty, the callback function is called with the voice number as an argument. You can use <tt>void <i>callback</i>
 *  (s32 voice)</tt> to call ASND_AddVoice() and add one voice to the second buffer. When the callback is non-NULL, the
 *  voice never stops and returns SND_WAITING if successful on timeout condition."
 *
 *  \param[in] voice      Voice slot to use.
 *  \param[in] format     Format of the samples in <CODE>samples</CODE>, as specified in \ref ASNDVoiceFormat.
 *  \param[in] pitch      Pitch to use for the voice, in Hz.
 *  \param[in] delay      Amount of milliseconds to wait before the voice should start playing.
 *  \param[in] samples    Buffer of sound samples. Must be aligned and padded to 32 bytes.
 *  \param[in] samplesize The size of the <CODE>samples</CODE> buffer, in bytes.
 *  \param[in] left       Volume of the left stereo channel.
 *  \param[in] right      Volume of the right stereo channel.
 *  \param[in] cb         Callback for (that double buffer thing?)
 *
 *  \return <CODE>::Invalid</CODE> if either of the following is true:<br />
 *              <CODE>voice</CODE> is not a valid voice slot<br />
 *              <CODE>samplesize</CODE> is less than 1 (0 or negative)<br />
 *          <br />
 *          <CODE>::OK</CODE> otherwise.
 */

/*! \fn ASNDReturnValue ogcwrap::asnd::setInfiniteVoice(u8 voice, ASNDVoiceFormat format, u32 pitch, u32 delay, void * samples, u32 samplesize, u8 left, u8 right)
 *  \brief Sets up a voice with the given arguments and starts looping indefinitely after the time specified in <CODE>delay</CODE> has passed.
 *
 *  \note All voices play audio in 16-bit stereo, regardless of the format they receive.
 *
 *  \param[in] voice      Voice slot to use.
 *  \param[in] format     Format of the samples in <CODE>samples</CODE>, as specified in \ref ASNDVoiceFormat.
 *  \param[in] pitch      Pitch to use for the voice, in Hz.
 *  \param[in] delay      Amount of milliseconds to wait before the voice should start playing.
 *  \param[in] samples    Buffer of sound samples. Must be aligned and padded to 32 bytes.
 *  \param[in] samplesize The size of the <CODE>samples</CODE> buffer, in bytes.
 *  \param[in] left       Volume of the left stereo channel.
 *  \param[in] right      Volume of the right stereo channel.
 *
 *  \return <CODE>::Invalid</CODE> if either of the following is true:<br />
 *              <CODE>voice</CODE> is not a valid voice slot<br />
 *              <CODE>samplesize</CODE> is less than 1 (0 or negative)<br />
 *          <br />
 *          <CODE>::OK</CODE> otherwise.
 */

/*! \fn ASNDReturnValue ogcwrap::asnd::addVoice(u8 voice, void * samples, u32 samplesize)
 *  \brief Add samples to a voice through the use of a second buffer.
 *
 *  \param[in] voice      Voice slot to use.
 *  \param[in] samples    Buffer of sound samples. Must be aligned and padded to 32 bytes and have the same sample
 *                        format as the first buffer.
 *  \param[in] samplesize The size of the <CODE>samples</CODE> buffer, in bytes.
 *
 *  \return <CODE>::Invalid</CODE> if any of the following is true:<br />
 *              <CODE>voice</CODE> is not a valid voice slot<br />
 *              <CODE>samplesize</CODE> is less than 1 (0 or negative)<br />
 *              <CODE>(sound_data[voice].flags & (VOICE_UPDATE | VOICE_UPDATEADD)) || !(sound_data[voice].flags>>16)</CODE> todo: decipher later<br />
 *          <br />
 *          <CODE>::VoiceBusy</CODE> if the voice is busy,<br />
 *          <CODE>::OK</CODE> otherwise.
 */

/*! \fn ASNDReturnValue ogcwrap::asnd::playVoice(u8 voice)
 *  \brief Plays the specified voice.
 *
 *  \param[in] voice Voice to play.
 *
 *  \return <CODE>::Invalid</CODE> if <CODE>voice</CODE> is not a valid voice slot; <CODE>::OK</CODE> otherwise
 */

/*! \fn ASNDReturnValue ogcwrap::asnd::pauseVoice(u8 voice)
 *  \brief Pauses the specified voice.
 *
 *  \param[in] voice Voice to pause.
 *
 *  \return <CODE>::Invalid</CODE> if <CODE>voice</CODE> is not a valid voice slot; <CODE>::OK</CODE> otherwise
 */

/*! \fn ASNDReturnValue ogcwrap::asnd::stopVoice(u8 voice)
 *  \brief Pauses the specified voice and removes all of its samples, effectively stopping it until given another buffer of samples.
 *
 *  \param[in] voice Voice to stop.
 *
 *  \return <CODE>::Invalid</CODE> if <CODE>voice</CODE> is not a valid voice slot; <CODE>::OK</CODE> otherwise
 */

/*! \fn ASNDReturnValue ogcwrap::asnd::getVoiceStatus(u8 voice)
 *  \brief Gets the status of the specified voice.
 *
 *  \param[in] voice Voice to get the status of.
 *
 *  \return <CODE>::Invalid</CODE> if <CODE>voice</CODE> is not a valid voice slot; the status of the voice otherwise
 */

/*! \fn ASNDReturnValue ogcwrap::asnd::setVoiceVolume(u8 voice, u8 left, u8 right)
 *  \brief Sets the volume of the left and right channels of the specified voice.
 *
 *  \param[in] voice Voice to get the status of.
 *  \param[in] left  Value to set the left channel's volume to.
 *  \param[in] right Value to set the right channel's volume to.
 *
 *  \return <CODE>::Invalid</CODE> if <CODE>voice</CODE> is not a valid voice slot; <CODE>::OK</CODE> otherwise
 */

/*! \fn ASNDReturnValue ogcwrap::asnd::setVoicePitch(u8 voice, u32 pitch)
 *  \brief Gets the status of the specified voice.
 *
 *  \param[in] voice Voice to get the status of.
 *  \param[in] pitch Frequency of the voice's new pitch, in Hz.
 *
 *  \return <CODE>::Invalid</CODE> if <CODE>voice</CODE> is not a valid voice slot; <CODE>::OK</CODE> otherwise
 */

/*! \fn bool ogcwrap::asnd::testVoiceBufferUsing(u8 voice, void * buffer)
 *  \brief Checks whether the specified voice is currently using the specified buffer.
 *
 *  \param[in] voice  Voice to test.
 *  \param[in] buffer Sample buffer to test.
 *
 *  \return <CODE>true</CODE> if the specified voice is using the specified buffer; <CODE>false</CODE> otherwise
 */

/*! \fn bool ogcwrap::asnd::testVoiceBufferReady(u8 voice)
 *  \brief Checks whether the specified voice is ready to recieve a new buffer of samples.
 *
 *  \param[in] voice Voice to test.
 *
 *  \return <CODE>true</CODE> if the specified voice is ready to accept a new buffer; <CODE>false</CODE> otherwise
 */