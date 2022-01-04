/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
// #include "console/console_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::console
{
	// subsystem management
	void init(void *, u16, u16, u16, u16, u32);
	bool initEx(GXRModeObj *, u16, u16, u16, u16);

	// gethods
	void getMetrics(u8 *, u8 *);
	void getPosition(u8 *, u8 *);

	// gecko
	void enableGecko(u8, bool);
	void disableGecko(void);
}

/*******************************************************************************
 * functions
 */

void ogcwrap::console::init(void * fb, u16 xStart, u16 yStart, u16 xRes, u16 yRes, u32 lineStride)
	{ CON_Init(fb, xStart, yStart, xRes, yRes, lineStride); }

bool ogcwrap::console::initEx(GXRModeObj * rmode, u16 xStart, u16 yStart, u16 xRes, u16 yRes)
	{ return (CON_InitEx(rmode, xStart, yStart, xRes, yRes) == 0 ? true : false); }

void ogcwrap::console::getMetrics(u8 * rows, u8 * cols)
{
	int * rowptr, * colptr;

	CON_GetMetrics(colptr, rowptr);

	*rows = static_cast<u8>(*rowptr);
	*cols = static_cast<u8>(*colptr);
}

void ogcwrap::console::getPosition(u8 * row, u8 * col)
{
	int * rowptr, * colptr;

	CON_GetPosition(colptr, rowptr);

	*row = static_cast<u8>(*rowptr);
	*col = static_cast<u8>(*rowptr);
}

void ogcwrap::console::enableGecko(u8 channel, bool safe)
	{ CON_EnableGecko(channel, safe); }

void ogcwrap::console::disableGecko(void)
	{ CON_EnableGecko(-1, true); }