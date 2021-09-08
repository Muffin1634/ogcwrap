#pragma once
#ifndef wrap_debug_td_h
#define wrap_debug_td_h

#include <gctypes.h>

namespace ogcwrap::debug
{
	// enum
	enum struct DebugDevice : u8
	{
		dev_USBGecko,
		dev_BBATCP
	};
}

#endif // wrap_debug_td_h
/*! \file debug_td.hpp <debug/debug_td.hpp>
 *  \brief Header file containing typedefs of enum structs for <CODE>\<debug/debug.hpp\></CODE>.
 *
 *  This header contains enums in the <CODE>ogcwrap::debug</CODE> namespace for use with its functions.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \namespace ogcwrap::debug
 *  \brief Namespace containing enums and functions related to the debugging stub included in libOGC.
 *
 *  \warning The debugging stub does not currently work at this time. This documentation is only included for the
 *           purposes of completely documenting the wrapper. Do not use this namespace's functions; you will get linker
 *           errors as the original functions are not currently included in libOGC.
 */

/*! \enum ogcwrap::debug::DebugDevice
 *  \brief Enum to choose which device to use the debugger with.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \var ogcwrap::debug::DebugDevice::dev_USBGecko
 *  \brief Use the USB Gecko to interface with the debugger.
 *
 *  \var ogcwrap::debug::DebugDevice::dev_BBATCP
 *  \brief Use BBA-TCP       to interface with the debugger.
 */