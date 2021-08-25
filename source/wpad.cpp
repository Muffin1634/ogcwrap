/*******************************************************************************
 * prereqs
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;

struct WPADData;
struct WPADEncStatus;
struct ir_t;
struct orient_t;
struct gforce_t;
struct vec3w_t;
struct expansion_t;

typedef void (*WPADDataCallback)(s32, const WPADData *);
typedef void (*WPADShutdownCallback)(s32);

extern "C"
{
	s32 WPAD_Init(void);
	s32 WPAD_ControlSpeaker(s32, s32);
	s32 WPAD_ReadEvent(s32, WPADData *);
	s32 WPAD_DroppedEvents(s32);
	s32 WPAD_Flush(s32);
	s32 WPAD_ReadPending(s32, WPADDataCallback);
	s32 WPAD_SetDataFormat(s32, s32);
	s32 WPAD_SetMotionPlus(s32, u8);
	s32 WPAD_SetVRes(s32, u32, u32);
	s32 WPAD_GetStatus(void);
	s32 WPAD_Probe(s32, u32 *);
	s32 WPAD_SetEventBufs(s32, WPADData *, u32);
	s32 WPAD_Disconnect(s32);
	s32 WPAD_IsSpeakerEnabled(s32);
	s32 WPAD_SendStreamData(s32, void *, u32);
	void WPAD_Shutdown(void);
	void WPAD_SetIdleTimeout(u32);
	void WPAD_SetPowerButtonCallback(WPADShutdownCallback);
	void WPAD_SetBatteryDeadCallback(WPADShutdownCallback);
	s32 WPAD_ScanPads(void);
	s32 WPAD_Rumble(s32, int);
	s32 WPAD_SetIdleThresholds(s32, s32, s32, s32, s32, s32, s32);
	void WPAD_EncodeData(WPADEncStatus *, u32, const s16 *, s32, u8 *);
	WPADData * WPAD_Data(int);
	u8 WPAD_BatteryLevel(int);
	u32 WPAD_ButtonsUp(int);
	u32 WPAD_ButtonsDown(int);
	u32 WPAD_ButtonsHeld(int);
	void WPAD_IR(int, struct ir_t *);
	void WPAD_Orientation(int, struct orient_t *);
	void WPAD_GForce(int, struct gforce_t *);
	void WPAD_Accel(int, struct vec3w_t *);
	void WPAD_Expansion(int, struct expansion_t *);
}

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap
{
	namespace wpad
	{
		// library management
		bool init(void);
		void shutdown(void);

		// sethods
		void setCallback(u8, WPADShutdownCallback);
		void setDataFormat(u8, u8);
		void setMotionPlus(u8, bool);
		void setVRes(u8, u16, u16);
		void setEventBuffers(u8, WPADData *, u32);
		void setIdleTimeout(u32);
		void setIdleThresholds(u8, s32, s32, s32, s32, s32, s32);

		// gethods
		s32 getStatus(void);
		bool getSpeakerStatus(u8);
		u32 getDroppedEventCount(u8);
		u8 getBatteryLevel(u8);

		// write methods + encode
		void encodeData(WPADEncStatus *, u32, const s16 *, s32, u8 *);
		bool writeRumbleStatus(u8, bool);
		bool writeSpeakerStatus(u8, bool);
		bool writeStreamData(u8, void *, u32);
		void flush(u8);

		// read event methods
		void readEvents(u8, WPADData *);
		u32 readPendingEvents(u8, WPADDataCallback);
		bool probe(u8, u32 *);

		// read input methods
		void scan(void);
		WPADData * readWPADData(u8);
		u32 readButtonStatus(u8, u8);
		void readIR(u8, struct ir_t *);
		void readOrientation(u8, struct orient_t *);
		void readGForce(u8, struct gforce_t *);
		void readAcceleration(u8, struct vec3w_t *);
		void readExpansion(u8, struct expansion_t *);
	}
}

/*******************************************************************************
 * functions
 */

bool ogcwrap::wpad::init(void)
	{ return (WPAD_Init() == 0 ? true : false); }

void ogcwrap::wpad::shutdown(void)
	{ WPAD_Shutdown(); }

void ogcwrap::wpad::setCallback(u8 type, WPADShutdownCallback cb)
{
	switch (type)
	{
		case 0:
			WPAD_SetPowerButtonCallback(cb);
			break;
		case 1:
			WPAD_SetBatteryDeadCallback(cb);
			break;
		default:
			break;
	}
}

void ogcwrap::wpad::setDataFormat(u8 channel, u8 fmt)
	{ WPAD_SetDataFormat(((s32)(channel)), ((s32)(fmt))); }

void ogcwrap::wpad::setMotionPlus(u8 channel, bool status)
	{ WPAD_SetMotionPlus(((s32)(channel)), ((u8)(status))); }

void ogcwrap::wpad::setVRes(u8 channel, u16 xres, u16 yres)
	{ WPAD_SetVRes(((s32)(channel)), ((u32)(xres)), ((u32)(yres))); }

void ogcwrap::wpad::setEventBuffers(u8 channel, WPADData * bufs, u32 count)
	{ WPAD_SetEventBufs(((s32)(channel)), bufs, count); }

void ogcwrap::wpad::setIdleTimeout(u32 seconds)
	{ WPAD_SetIdleTimeout(seconds); }

void ogcwrap::wpad::setIdleThresholds(u8 channel, s32 buttons, s32 ir, s32 accel, s32 js, s32 wb, s32 mp)
	{ WPAD_SetIdleThresholds(((s32)(channel)), buttons, ir, accel, js, wb, mp); }

s32 ogcwrap::wpad::getStatus(void)
	{ return WPAD_GetStatus(); }

bool ogcwrap::wpad::getSpeakerStatus(u8 channel)
	{ return (WPAD_IsSpeakerEnabled(((s32)(channel))) == 1 ? true : false); }

u32 ogcwrap::wpad::getDroppedEventCount(u8 channel)
	{ return ((u32)(WPAD_DroppedEvents(((s32)(channel))))); }

u8 ogcwrap::wpad::getBatteryLevel(u8 channel)
	{ return WPAD_BatteryLevel(((int)(channel))); }

void ogcwrap::wpad::encodeData(WPADEncStatus * info, u32 flags, const s16 * PCMSamples, s32 sampleCount, u8 * data)
	{ WPAD_EncodeData(info, flags, PCMSamples, sampleCount, data); }

bool ogcwrap::wpad::writeRumbleStatus(u8 channel, bool status)
	{ return (WPAD_Rumble(((s32)(channel)), ((int)(status))) == 0 ? true : false); }

bool ogcwrap::wpad::writeSpeakerStatus(u8 channel, bool status)
	{ return (WPAD_ControlSpeaker(((s32)(channel)), ((s32)(status))) == 0 ? true : false); }

bool ogcwrap::wpad::writeStreamData(u8 channel, void * dataBuffer, u32 dataSize)
	{ return (WPAD_SendStreamData(((s32)(channel)), dataBuffer, dataSize) == 0 ? true : false); }

void ogcwrap::wpad::flush(u8 channel)
	{ WPAD_Flush(((s32)(channel))); }

void ogcwrap::wpad::readEvents(u8 channel, WPADData * data)
	{ WPAD_ReadEvent(((s32)(channel)), data); }

u32 ogcwrap::wpad::readPendingEvents(u8 channel, WPADDataCallback cb)
	{ return ((u32)(WPAD_ReadPending(((s32)(channel)), cb))); }

bool ogcwrap::wpad::probe(u8 channel, u32 * type)
	{ return (WPAD_Probe(((s32)(channel)), type) == 0 ? true : false); }

void ogcwrap::wpad::scan(void)
	{ WPAD_ScanPads(); }

WPADData * ogcwrap::wpad::readWPADData(u8 channel)
	{ return WPAD_Data(((s32)(channel))); }

u32 ogcwrap::wpad::readButtonStatus(u8 channel, u8 type)
{
	switch (type)
	{
		case 0:
			return WPAD_ButtonsUp(((s32)(channel)));
		case 1:
			return WPAD_ButtonsDown(((s32)(channel)));
		case 2:
			return WPAD_ButtonsHeld(((s32)(channel)));
		default:
			return -1;
	}
}

void ogcwrap::wpad::readIR(u8 channel, struct ir_t * ir)
	{ WPAD_IR(((s32)(channel)), ir); }

void ogcwrap::wpad::readOrientation(u8 channel, struct orient_t * orient)
	{ WPAD_Orientation(((s32)(channel)), orient); }

void ogcwrap::wpad::readGForce(u8 channel, struct gforce_t * gforce)
	{ WPAD_GForce(((s32)(channel)), gforce); }

void ogcwrap::wpad::readAcceleration(u8 channel, struct vec3w_t * accel)
	{ WPAD_Accel(((s32)(channel)), accel); }

void ogcwrap::wpad::readExpansion(u8 channel, struct expansion_t * exp)
	{ WPAD_Expansion(((s32)(channel)), exp); }