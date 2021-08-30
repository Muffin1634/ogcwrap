#pragma once
#ifndef wrap_debug_td_h
#define wrap_debug_td_h

namespace ogcwrap
{
	namespace debug
	{
		typedef enum debug_device_type_t
		{
			dev_USBGecko,
			dev_BBATCP
		} DebugDevice;
	}
}

#endif // wrap_debug_td_h