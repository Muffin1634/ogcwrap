#pragma once
#ifndef wrap_video_h
#define wrap_video_h

#include "video/video_td.hpp"

namespace ogcwrap
{
	namespace video
	{
		// library management
		void init(void);

		// gethods
		GXRModeObj * getPreferredRMode(GXRModeObj *);
		TVMode getTVMode(void);
		bool getComponentCableStatus(void);
		void * getCurrentFramebuffer(void);
		void * getNextFramebuffer(void);
		u32 getFramebufferSize(GXRModeObj *);
		u32 getCurrentLine(void);
		u32 getNextField(void);

		// sethods
		void setConfiguration(GXRModeObj *);
		VIRetraceCallback setTraceCallback(RetraceTime, VIRetraceCallback);
		void setNextFramebuffer(void *);
		void setNextRightFramebuffer(void *);
		void setBlackoutStatus(bool);

		// write methods
		void clearFramebuffer(GXRModeObj *, void *, u32);
		void flush(void);

		// other
		void waitVSync(void);
	}
}

#endif // wrap_video_h