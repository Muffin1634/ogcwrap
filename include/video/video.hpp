#pragma once
#ifndef wrap_video_h
#define wrap_video_h

#include <gctypes.h>
#include <ogc/video.h>
#include <ogc/gx_struct.h>

#include "video/video_td.hpp"

namespace ogcwrap::video
{
	// subsystem management
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
	VIRetraceCallback setTraceCallback(RetraceTime rtime, VIRetraceCallback cb);
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