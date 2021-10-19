#pragma once
#ifndef wrap_debug_h
#define wrap_debug_h

#include <gctypes.h>
#include <debug.h>

#include "debug/debug_td.hpp"

namespace ogcwrap::debug
{
	// subsystem management
	void init(DebugDevice dev, u16 port);

	// breakpoint
	void _breakpt(void);
}

/* enable the user to write _breakpt instead of debug::_breakpt() or ogcwrap::debug::_breakpt() to reduce name size and
 * increase the effectiveness of the underscore since it will be at the beginning of the function name to better
 * indicate that it is a debugging function
 */
using ogcwrap::debug::_breakpt;

#endif // wrap_debug_h