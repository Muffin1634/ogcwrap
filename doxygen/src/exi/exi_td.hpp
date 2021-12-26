#pragma once
#ifndef wrap_exi_td_h
#define wrap_exi_td_h

namespace ogcwrap::exi
{
	typedef enum struct exi_channel_t
	{
		Channel0,
		Channel1,
		Channel2,

		MaxChannels
	} EXIChannel;

	typedef enum struct exi_device_t
	{
		Device0,
		Device1,
		Device2,

		MaxDevices
	} EXIDevice;

	typedef enum exi_frequency_t
	{
		Freq1MHz,
		Freq2MHz,
		Freq4MHz,
		Freq8MHz,
		Freq16MHz,
		Freq32MHz
	} EXIFrequency;

	typedef enum exi_transfer_mode_t
	{
		Read,
		Write,
		ReadWrite
	} EXIDataTransferMode;
}

#endif // wrap_exi_td_h