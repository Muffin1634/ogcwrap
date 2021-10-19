#pragma once
#ifndef wrap_console_h
#define wrap_console_h

#include <gctypes.h>
#include <ogc/consol.h>
#include <ogc/gx_struct.h>

// #include "console/console_td.hpp"

namespace ogcwrap::console
{
	// subsystem management
	void init(void * fb, u16 xStart, u16 yStart, u16 xRes, u16 yRes, u32 stride);
	s32 initEx(GXRModeObj * rmode, u16 xStart, u16 yStart, u16 xRes, u16 yRes);

	// gethods
	void getMetrics(u8 * rows, u8 * cols);
	void getPosition(u8 * row, u8 * col);

	// gecko
	void enableGecko(u8 port, bool safe);
	void disableGecko(void);
}

#endif // wrap_console_h