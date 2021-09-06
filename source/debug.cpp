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
	enum struct debug_device_type_t : u8
	{
		dev_USBGecko,
		dev_BBATCP
	};

	// library management
	void init(debug_device_type_t, u16);

	// breakpoint
	void breakpt(void);
}

/*******************************************************************************
 * functions
 */

void ogcwrap::debug::init(debug_device_type_t dev, u16 port)
	{ DEBUG_Init(dev, port); }

void ogcwrap::debug::breakpt(void)
	{ _break(); }
