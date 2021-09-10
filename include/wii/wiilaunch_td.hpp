#pragma once
#ifndef wrap_wii_td_h
#define wrap_wii_td_h

namespace ogcwrap::wii
{
	typedef enum struct wii_ret_vals_t
	{
		WII_ENONE,

		WII_ENOTINIT	= -0x9001,
		WII_EINTERNAL	= -0x9002,
		WII_ECHECKSUM	= -0x9003,
		WII_EINSTALL	= -0x9004,
		WII_E2BIG		= -0x9004
	} WIIReturnValue;
}

#endif // wrap_wii_td_h