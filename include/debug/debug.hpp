#pragma once
#ifndef wrap_debug_h
#define wrap_debug_h

#include <gctypes.h>
#include <debug.h>

#include "debug/debug_td.hpp"

namespace ogcwrap::debug
{
	// library management
	void init(DebugDevice dev, u16 port);

	// breakpoint
	void _breakpt(void);
}

/* enable the user to write _breakpt instead of debug::_breakpt() or ogcwrap::debug::_breakpt() to reduce name size and
 * increase the effectiveness of the underscore since it will be at the beginning of the function name to better
 * indicate that it is a debugging function
 */
using ogcwrap::debug::_breakpt;

#endif // wrap_debug_h
/*! \file debug.hpp <debug/debug.hpp>
 *  \brief Header file for the wrapper of the debugging stub included in libOGC.
 *
 *  This header contains functions in the <CODE>ogcwrap::debug</CODE> namespace for intializing the debug stub and
 *  inserting breakpoints into your code.
 *
 *  <!--
 *  	there is intentionally no line between the endif and this block. this is to remove that newline from the
 *  	resulting source code that is generated. otherwise it looks weird. i am not going to be the person making it
 *  	look weird.
 *  -->
 */

/*! \namespace ogcwrap::debug
 *  \brief Namespace containing enums and functions related to the debugging stub included in libOGC.
 */

/*! \fn void ogcwrap::debug::init(DebugDevice dev, u16 port)
 *  \brief Initializes the debugging stub and allows you to use <CODE>_breakpt()</CODE> throughout your code to create
 *         breakpoints.
 *
 *  \param[in] dev  The type of device you would like to use to interface with the debugger. This is either <CODE>dev_USBGecko</CODE>
 *                  to specify that you are using the USB Gecko to debug or <CODE>dev_BBATCP</CODE> to specify that you
 *                  are using BBA-TCP to debug.
 *  \param[in] port The port that this device is connected to. For the USB Gecko, this is either EXI port <CODE>0</CODE>
 *                  or <CODE>1</CODE> (the GameCube Memory Card slots). For BBA-TCP, this is any TCP port from <CODE>0</CODE>
 *                  to <CODE>65535</CODE> inclusive.
 *
 *  \return none
 */

/*! \fn void ogcwrap::debug::_breakpt(void)
 *  \brief Inserts a breakpoint into your code.
 *
 *  This function inserts a breakpoint into your code to let the debugging stub know that it when it reaches this
 *  function, it should halt operation of the program and pass control to the debugger for debugging. You may use this
 *  function wherever you like.
 *
 *  \return none
 */