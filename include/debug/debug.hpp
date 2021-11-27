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

	static inline void _debugmsg(const char * format, ...)
	{
	#ifdef DEBUG
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		va_end();
	#endif // DEBUG
	}
}

using ogcwrap::debug::_breakpt;
using ogcwrap::debug::_debugmsg;

#endif // wrap_debug_h