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

namespace debug
{
	void init(u8, u16);
	void breakpt(void);
}

/*******************************************************************************
 * functions
 */

void debug::init(u8 dev, u16 port)
	{ DEBUG_Init(((s32)(dev)), ((s32)(port))); }

void debug::breakpt(void)
	{ _break(); }