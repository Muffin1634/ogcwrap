/*******************************************************************************
 * prereqs
 */

typedef unsigned int u32;

struct GXRModeObj;

typedef void (*VIRetraceCallback)(u32);
typedef void (*VIPositionCallback)(u32, u32);

extern "C"
{
	void VIDEO_Init(void);
	void* VIDEO_GetNextFramebuffer(void);
	void* VIDEO_GetCurrentFramebuffer(void);
	void VIDEO_Flush(void);
	void VIDEO_SetBlack(bool black);
	u32 VIDEO_GetNextField(void);
	u32 VIDEO_GetCurrentLine(void);
	u32 VIDEO_GetCurrentTvMode(void);
	void VIDEO_Configure(GXRModeObj *rmode);
	u32 VIDEO_GetFrameBufferSize(GXRModeObj *rmode);
	void VIDEO_ClearFrameBuffer(GXRModeObj *rmode,void *fb,u32 color);
	void VIDEO_WaitVSync(void);
	void VIDEO_SetNextFramebuffer(void *fb);
	void VIDEO_SetNextRightFramebuffer(void *fb);
	VIRetraceCallback VIDEO_SetPreRetraceCallback(VIRetraceCallback callback);
	VIRetraceCallback VIDEO_SetPostRetraceCallback(VIRetraceCallback callback);
	u32 VIDEO_HaveComponentCable(void);
	GXRModeObj * VIDEO_GetPreferredMode(GXRModeObj *mode);
}

/*******************************************************************************
 * forward function declarations
 */

namespace ogcwrap
{
	namespace video
	{
		// enums
		enum tv_mode_t
		{
			TVM_ERROR = -1,

			NTSC,
			PAL,
			MPAL,
			EuRGB60,

			DEBUG_NTSC,
			DEBUG_PAL
		};

		enum retrace_time_t
		{
			PreRetrace,
			PostRetrace
		};

		enum ds_field_pos_t
		{
			DSFP_ERROR = -1,

			TopField = 1,
			BottomField = 0
		};

		// library management
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
}

/*******************************************************************************
 * functions
 */

using ogcwrap::video::tv_mode_t;
using ogcwrap::video::retrace_time_t;
using ogcwrap::video::ds_field_pos_t;

void ogcwrap::video::init(void)
	{ VIDEO_Init(); }

GXRModeObj * ogcwrap::video::getPreferredRMode(GXRModeObj * rmode)
	{ return VIDEO_GetPreferredMode(rmode); }

tv_mode_t ogcwrap::video::getTVMode(void)
{
	switch (VIDEO_GetCurrentTvMode())
	{
		case 0: // NTSC
			return tv_mode_t::NTSC;
		case 1: // PAL
			return tv_mode_t::PAL;
		case 2: // MPAL
			return tv_mode_t::MPAL;
		case 5: // EuRGB60
			return tv_mode_t::EuRGB60;
		case 3: // DEBUG_NTSC
			return tv_mode_t::DEBUG_NTSC;
		case 4: // DEBUG_PAL
			return tv_mode_t::DEBUG_PAL;
		default:
			return tv_mode_t::TVM_ERROR;
	}
}

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
{
	switch (VIDEO_GetNextField())
	{
		case 1:
			return ds_field_pos_t::TopField;
		case 0:
			return ds_field_pos_t::BottomField;
		default:
			return ds_field_pos_t::DSFP_ERROR;
	}
}

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