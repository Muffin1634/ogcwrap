/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::debug
{
	// enum
	enum struct debug_device_t : u8
	{
		dev_USBGecko,
		dev_BBATCP
	};

	// library management
	void init(debug_device_t, u16);

	// breakpoint
	void _breakpt(void);
}

/*******************************************************************************
 * functions
 */

void ogcwrap::debug::init(debug_device_t dev, u16 port)
	{ DEBUG_Init(cast(s32, dev), port); }

void ogcwrap::debug::_breakpt(void)
	{ _break(); }
