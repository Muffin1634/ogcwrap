#pragma once
#ifndef wrap_wpad_td_h
#define wrap_wpad_td_h

namespace ogcwrap::wpad
{
	typedef enum struct wpad_ret_vals_t
	{
		OK,

		NoController	= -1,
		NotReady		= -2,
		Transfer		= -3,
		NoneRegistered	= -4,
		Unknown			= -5,
		BadChannel		= -6,
		QueueEmpty		= -7,
		BadValue		= -8,
		BadConf			= -9,

		StatusDisabled = 0,
		StatusEnabling,
		StatusEnabled
	} WPADReturnValue;

	typedef enum struct callback_type_t
	{
		PowerButtonCB,
		BatteryDeadCB
	} CallbackType;

	typedef enum struct wiimote_channel_t
	{
		Channel0,
		Channel1,
		Channel2,
		Channel3,
		Channel4,

		MaxChannels,
		AllChannels		= -1
	} WiimoteChannel;

	typedef enum struct data_format_t
	{
		Buttons,
		ButtonsAccel,
		ButtonsAccelIR
	} DataFormat;

	typedef enum struct button_type_t
	{
		ButtonsUp,
		ButtonsDown,
		ButtonsHeld
	} ButtonType;
}

#endif // wrap_wpad_td_h