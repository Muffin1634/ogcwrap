#pragma once
#ifndef wrap_console_h
#define wrap_console_h

#include <gctypes.h>
#include <ogc/consol.h>
#include <ogc/gx_struct.h>

namespace ogcwrap::console
{
	// library management
	void init(void * fb, u16 xStart, u16 yStart, u16 xRes, u16 yRes, u32 stride);
	bool initEx(GXRModeObj * rmode, u16 xStart, u16 yStart, u16 xRes, u16 yRes);

	// gethods
	void getMetrics(u8 * rows, u8 * cols);
	void getPosition(u8 * row, u8 * col);

	// gecko
	void enableGecko(u8 channel, bool safe);
	void disableGecko(void);
}

#endif // wrap_console_h
/*! \file console.hpp <console/console.hpp>
 *  \brief Header file for the wrapper of the console subsystem in libOGC.
 *
 *  This header contains functions in the <CODE>ogcwrap::console</CODE> namespace for initializing the console and
 *  gathering statistics.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \namespace ogcwrap::console
 *  \brief Namespace containing functions related to the console subsystem in libOGC.
 */

/*! \fn void ogcwrap::console::init(void * fb, u16 xStart, u16 yStart, u16 xRes, u16 yRes, u32 stride)
 *  \brief Initializes the specified framebuffer to hold console output with the specified options.
 *
 *  \param[in,out] fb     Pointer to the framebuffer to initialize.
 *  \param[in]     xStart Horizontal offset of the console output from the left of the framebuffer, in pixels
 *  \param[in]     yStart Vertical offset of the console output from the top of the framebuffer, in pixels
 *  \param[in]     xRes   Width of the framebuffer, in pixels
 *  \param[in]     yRes   Height of the framebuffer, in pixels
 *  \param[in]     stride Size of one line of text in the framebuffer, in bytes
 *
 *  \return none
 */

/*! \fn bool ogcwrap::console::initEx(GXRModeObj * rmode, u16 xStart, u16 yStart, u16 xRes, u16 yRes)
 *  \brief Initializes the specified framebuffer to hold console output with the specified options.
 *
 *  \param[in,out] rmode  Pointer to the render mode object to initialize.
 *  \param[in]     xStart Horizontal offset of the console output from the left of the framebuffer, in pixels
 *  \param[in]     yStart Vertical offset of the console output from the top of the framebuffer, in pixels
 *  \param[in]     xRes   Width of the framebuffer, in pixels
 *  \param[in]     yRes   Height of the framebuffer, in pixels
 *
 *  \return <CODE>false</CODE> if the render mode object's framebuffer failed to allocate the required memory; <CODE>true</CODE>
 *          otherwise
 */

/*! \fn void ogcwrap::console::getMetrics(u8 * rows, u8 * cols)
 *  \brief Gets the number of rows and columns in the console framebuffer and stores them in the values pointed to by
 *         the specified pointers.
 *
 *  \param[out] rows A <CODE>u8 *</CODE> that will have the number of rows in the console framebuffer.
 *  \param[out] cols A <CODE>u8 *</CODE> that will have the number of columns in the console framebuffer.
 *
 *  \return none; the results are stored in the values pointed to by the parameters.
 */

/*! \fn void ogcwrap::console::getPosition(u8 * row, u8 * col)
 *  \brief Gets the current row and column of the console framebuffer and stores them in the values pointed to by the
 *         specified pointers.
 *
 *  \param[out] row A <CODE>u8 *</CODE> that will have the current row of the console framebuffer.
 *  \param[out] col A <CODE>u8 *</CODE> that will have the current column of the console framebuffer.
 *
 *  \return none; the results are stored in the values pointed to by the parameters.
 */

/*! \fn void ogcwrap::console::enableGecko(u8 channel, bool safe)
 *  \brief Enables console output to the USB Gecko on the specified channel.
 *
 *  \param[in] channel The EXI channel with the USB Gecko.
 *  \param[in] safe    Whether to use safe mode: wait for the other device to respond before sending any data
 *
 *  \return none
 */

/*! \fn void ogcwrap::console::disableGecko(void)
 *  \brief Disables console output to the USB Gecko.
 *
 *  \return none
 */