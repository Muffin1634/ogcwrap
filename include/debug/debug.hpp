#pragma once
#ifndef wrap_debug_h
#define wrap_debug_h

#include <gctypes.h>
#include <debug.h>

#include "debug/debug_td.hpp"

namespace ogcwrap::debug
{
	// library management
	void init(DebugDevice, u16);

	// breakpoint
	void breakpt(void);
}

#endif // wrap_debug_h