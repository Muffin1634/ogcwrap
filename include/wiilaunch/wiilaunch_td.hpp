#pragma once
#ifndef wrap_wiilaunch_td_h
#define wrap_wiilaunch_td_h

namespace ogcwrap::wiilaunch
{
	typedef enum struct wii_ret_vals_t
	{
		OK,

		NotInit		= -0x9001,
		InternalErr	= -0x9002,
		BadChecksum	= -0x9003,
		Install		= -0x9004,
		TooBig		= -0x9005
	} WIIReturnValue;
}

#endif // wrap_wiilaunch_td_h