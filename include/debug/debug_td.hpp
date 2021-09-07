#pragma once
#ifndef wrap_debug_td_h
#define wrap_debug_td_h

typedef unsigned char u8;

namespace ogcwrap::debug
{
	enum struct debug_device_t : u8
	{
		dev_USBGecko,
		dev_BBATCP
	};

	typedef debug_device_t DebugDevice;
}

#endif // wrap_debug_td_h
/*! \file debug_td.hpp <debug/debug_td.hpp>
 *  \brief Header file containing typedefs of enum structs for <CODE>\<debug/debug.hpp\></CODE>.
 *
 *  This header contains enums in the <CODE>ogcwrap::debug</CODE> namespace for use with its functions.
 */

/*! \namespace ogcwrap::debug
 *  \brief Namespace containing enums and functions related to the debugging stub included in libOGC.
 */

/*! \typedef enum struct ogcwrap::debug::debug_device_t : u8 ogcwrap::debug::DebugDevice
 *  \brief Typedef of internal enum
 *
 *  further details
 */