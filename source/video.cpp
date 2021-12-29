/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "video/video_td.hpp"

/*******************************************************************************
 * forward function declarations
 */

namespace ogcwrap::video
{
	// subsystem management
	void init(void);

	// gethods
	GXRModeObj * getPreferredRMode(GXRModeObj *);
	tv_mode_t getTVMode(void);
	bool getComponentCableStatus(void);
	void * getCurrentFramebuffer(void);
	void * getNextFramebuffer(void);
	 u32 getFramebufferSize(GXRModeObj *);
	u32 getCurrentLine(void);
	ds_field_pos_t getNextField(void);

	// sethods
	void setConfiguration(GXRModeObj *);
	VIRetraceCallback setTraceCallback(enum retrace_time_t, VIRetraceCallback);
	void setNextFramebuffer(void *);
	void setNextRightFramebuffer(void *);
	void setBlackoutStatus(bool);

	// write methods
	void clearFramebuffer(GXRModeObj *, void *, u32);
	void flush(void);

	// other
	void waitVSync(void);
}

/*******************************************************************************
 * functions
 */

using ogcwrap::video::tv_mode_t;
using ogcwrap::video::ds_field_pos_t;

void ogcwrap::video::init(void)
	{ VIDEO_Init(); }

GXRModeObj * ogcwrap::video::getPreferredRMode(GXRModeObj * rmode)
	{ return VIDEO_GetPreferredMode(rmode); }

tv_mode_t ogcwrap::video::getTVMode(void)
	{ return static_cast<tv_mode_t>(VIDEO_GetCurrentTvMode()); }

bool ogcwrap::video::getComponentCableStatus(void)
	{ return VIDEO_HaveComponentCable(); }

void * ogcwrap::video::getCurrentFramebuffer(void)
	{ return VIDEO_GetCurrentFramebuffer(); }

void * ogcwrap::video::getNextFramebuffer(void)
	{ return VIDEO_GetNextFramebuffer(); }

u32 ogcwrap::video::getFramebufferSize(GXRModeObj * rmode)
	{ return VIDEO_GetFrameBufferSize(rmode); }

u32 ogcwrap::video::getCurrentLine(void)
	{ return VIDEO_GetCurrentLine(); }

ds_field_pos_t ogcwrap::video::getNextField(void)
	{ return static_cast<ds_field_pos_t>(VIDEO_GetNextField()); }

void ogcwrap::video::setConfiguration(GXRModeObj * rmode)
	{ VIDEO_Configure(rmode); }

VIRetraceCallback ogcwrap::video::setTraceCallback(enum retrace_time_t tracetime, VIRetraceCallback cb)
{
	if (tracetime == retrace_time_t::PreRetrace)
		return VIDEO_SetPreRetraceCallback(cb);
	else if (tracetime == retrace_time_t::PostRetrace)
		return VIDEO_SetPostRetraceCallback(cb);
	else
		return nullptr;
}
void ogcwrap::video::setNextFramebuffer(void * fb)
	{ VIDEO_SetNextFramebuffer(fb); }

void ogcwrap::video::setNextRightFramebuffer(void * fb)
	{ VIDEO_SetNextRightFramebuffer(fb); }

void ogcwrap::video::setBlackoutStatus(bool status)
	{ VIDEO_SetBlack(status); }

void ogcwrap::video::clearFramebuffer(GXRModeObj * rmode, void * fb, u32 color)
	{ VIDEO_ClearFrameBuffer(rmode, fb, color); }

void ogcwrap::video::flush(void)
	{ VIDEO_Flush(); }

void ogcwrap::video::waitVSync(void)
	{ VIDEO_WaitVSync(); }