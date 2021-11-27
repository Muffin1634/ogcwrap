/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "debug/debug_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::debug
{
	// subsystem management
	void init(debug_device_t, u16);

	// breakpoint
	void _breakpt(void);
}

/*******************************************************************************
 * functions
 */

void ogcwrap::debug::init(debug_device_t dev, u16 port)
	{ DEBUG_Init(mcast(s32, dev), port); }

void ogcwrap::debug::_breakpt(void)
	{ _break(); }