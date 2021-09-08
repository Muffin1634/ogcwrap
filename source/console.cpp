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
	// library management
	void init(void *, u16, u16, u16, u16, u32);
	s32 initEx(GXRModeObj *, u16, u16, u16, u16);

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

s32 ogcwrap::console::initEx(GXRModeObj * rmode, u16 xStart, u16 yStart, u16 xRes, u16 yRes)
	{ CON_InitEx(rmode, xStart, yStart, xRes, yRes); }

void ogcwrap::console::getMetrics(u8 * rows, u8 * cols)
{
	int * rowptr, * colptr;

	CON_GetMetrics(colptr, rowptr);

	*rows = mcast(u8, *rowptr);
	*cols = mcast(u8, *colptr);
}

void ogcwrap::console::getPosition(u8 * row, u8 * col)
{
	int * rowptr, colptr;

	CON_GetPosition(colptr, rowptr);

	*rows = mcast(u8, *rowptr);
	*cols = mcast(u8, *rowptr);
}

void ogcwrap::console::enableGecko(u8 port, bool safe)
	{ CON_EnableGecko(port, safe); }

void ogcwrap::console::disableGecko(void)
	{ CON_EnableGecko(-1, true); }