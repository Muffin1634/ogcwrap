#pragma once
#ifndef wrap_video_h
#define wrap_video_h

#include <gctypes.h>
#include <ogc/video.h>

#include "video/video_td.hpp"

namespace ogcwrap::video
{
	// library management
	void init(void);

	// gethods
	GXRModeObj * getPreferredRMode(GXRModeObj * rmode);
	TVMode getTVMode(void);
	bool getComponentCableStatus(void);
	void * getCurrentFramebuffer(void);
	void * getNextFramebuffer(void);
	u32 getFramebufferSize(GXRModeObj * rmode);
	u32 getCurrentLine(void);
	DSFieldPos getNextField(void);

	// sethods
	void setConfiguration(GXRModeObj * rmode);
	VIRetraceCallback setRetraceCallback(RetraceTime time, VIRetraceCallback cb);
	void setNextFramebuffer(void * fb);
	void setNextRightFramebuffer(void * fb);
	void setBlackoutStatus(bool status);

	// write methods
	void clearFramebuffer(GXRModeObj * rmode, void * fb, u32 color);
	void flush(void);

	// other
	void waitVSync(void);
}

#endif // wrap_video_h
/*! \file video.hpp <video/video.hpp>
 *  \brief Header file for the wrapper of the video subsystem in libOGC.
 *
 *  This header contains functions in the <CODE>ogcwrap::video</CODE> namespace for initializing the video subsystem,
 *  modifying it, and other controls.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \namespace ogcwrap::video
 *  \brief Namespace containing enums and functions related to the video subsystem in libOGC.
 */

/*! \fn void ogcwrap::video::init(void)
 *  \brief Initializes the video subsystem.
 *
 *  \return none
 */

/*! \fn GXRModeObj * ogcwrap::video::getPreferredRMode(GXRModeObj *)
 *  \brief Gets the preferred render mode of the Wii, based on region and other things.
 *
 *  \param[in] rmode unknown
 *
 *  \return A GXRModeObj with the preferred render mode of the Wii.
 */

/*! \fn TVMode ogcwrap::video::getTVMode(void)
 *  \brief Gets the video standard currently being used by the Wii.
 *
 *  \return The TVMode currently being used by the Wii.
 */

/*! \fn bool ogcwrap::video::getComponentCableStatus(void)
 *  \brief Checks if there is a component cable connected to the Wii.
 *
 *  \return <CODE>true</CODE> if there is a connected component cable, <CODE>false</CODE> otherwise.
 */

/*! \fn void * ogcwrap::video::getCurrentFramebuffer(void)
 *  \brief Gets a <CODE>void *</CODE> to the current framebuffer.
 *
 *  \return A <CODE>void *</CODE> to the current framebuffer.
 */

/*! \fn void * ogcwrap::video::getNextFramebuffer(void)
 *  \brief Gets a <CODE>void *</CODE> to the next framebuffer.
 *
 *  \return A <CODE>void *</CODE> to the next framebuffer.
 */

/*! \fn u32 ogcwrap::video::getFramebufferSize(GXRModeObj * rmode)
 *  \brief Calculates a framebuffer's necessary size based on the render mode given.
 *
 *  \param[in] rmode The render mode to calculate the size with.
 *
 *  \return The necessary size of the render mode's framebuffer, in bytes.
 */

/*! \fn u32 ogcwrap::video::getCurrentLine(void)
 *  \brief Gets the current video line.
 *
 *  \return The current line.
 */

/*! \fn DSFieldPos ogcwrap::video::getNextField(void)
 *  \brief Gets the next field to draw in DS mode.
 *
 *  \return A DSFieldPos with the next field to be rendered.
 */

/*! \fn void ogcwrap::video::setConfiguration(GXRModeObj * rmode)
 *  \brief Sets the configuration of the video subsystem based on the given render mode's configuration.
 *
 *  \param[in] rmode The render mode to use to configure the video subsystem with.
 *
 *  \return none
 */

/*! \fn VIRetraceCallback ogcwrap::video::setRetraceCallback(RetraceTime time, VIRetraceCallback cb)
 *  \brief Sets the handler for either pre-retrace or post-retrace interrupts.
 *
 *  \param[in] time The time to assign the handler to.
 *  \param[in] cb   The new handler to assign.
 *
 *  \return The old VIRetraceCallback.
 */

/*! \fn void ogcwrap::video::setNextFramebuffer(void * fb)
 *  \brief Sets the next framebuffer to be used.
 *
 *  \param[in] fb A <CODE>void *</CODE> to the next framebuffer.
 *
 *  \return none
 */

/*! \fn void ogcwrap::video::setNextRightFramebuffer(void * fb)
 *  \brief Sets the next right framebuffer.
 *
 *  An example of a use of the right framebuffer would be for 3D Gloves.
 *
 *  \param[in] fb A <CODE>void *</CODE> to the next right framebuffer.
 *
 *  \return none
 */

/*! \fn void ogcwrap::video::setBlackoutStatus(bool status)
 *  \brief Enable or disable the blacking out of the subsystem.
 *
 *  \param[in] status <CODE>true</CODE> to enable the blackout; <CODE>false</CODE> otherwise.
 *
 *  \return none
 */

/*! \fn void ogcwrap::video::clearFramebuffer(GXRModeObj * rmode, void * fb, u32 color)
 *  \brief Clears the given framebuffer <CODE>fb</CODE> to a single color <CODE>color</CODE> based on settings from
 *         <CODE>rmode</CODE>.
 *
 *  \param[in] rmode The render mode to take settings from.
 *  \param[in] fb    The framebuffer to clear.
 *  \param[in] color The color to clear the framebuffer to, specified in YUYUV format.
 *
 *  \return none
 */

/*! \fn void ogcwrap::video::flush(void)
 *  \brief Flushes the registers of the video subsystem.
 *
 *  \return none
 */

/*! \fn void ogcwrap::video::waitVSync(void)
 *  \brief Waits for the next vertical retrace.
 *
 *  \return none
 */