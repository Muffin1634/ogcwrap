/*******************************************************************************
 * prereqs
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern "C"
{
	void DEBUG_Init(s32, s32);
	void _break(void);
}

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap
{
	namespace debug
	{
		// enum
		enum debug_device_type_t
		{
			dev_USBGecko,
			dev_BBATCP
		};

		// library management
		void init(u8, u16);

		// breakpoint
		void breakpt(void);

		// detail namespace
		namespace detail
		{
			// decoding (f->b)
			u8 decodeDD(debug_device_type_t);
		}
	}
}

/*******************************************************************************
 * functions
 */

void ogcwrap::debug::init(debug_device_type_t dev, u16 port)
	{ DEBUG_Init(decodeDD(dev), port); }

void ogcwrap::debug::breakpt(void)
	{ _break(); }

u8 ogcwrap::debug::detail::decodeDD(debug_device_type_t dev)
	{ return (dev == debug_device_type_t::dev_USBGecko ? 0 : 1); }