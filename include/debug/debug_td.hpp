#pragma once
#ifndef wrap_debug_td_h
#define wrap_debug_td_h

#include <gctypes.h>

namespace ogcwrap::debug
{
	// enum
	typedef enum struct debug_device_t : u8
	{
		dev_USBGecko,
		dev_BBATCP
	} DebugDevice;
}

#endif // wrap_debug_td_h