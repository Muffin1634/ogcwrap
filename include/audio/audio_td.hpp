#pragma once
#ifndef wrap_audio_td_h
#define wrap_audio_td_h

namespace ogcwrap::audio
{
	typedef enum struct sample_rate_t
	{
		Freq32KHz,
		Freq48Khz
	} AudioSampleRate;

	typedef enum struct play_state_t
	{
		Stopped,
		Started
	} AudioPlayState;
}

using ogcwrap::audio::AudioSampleRate;
using ogcwrap::audio::AudioPlayState;

#endif // wrap_audio_td_h