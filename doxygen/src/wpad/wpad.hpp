#pragma once
#ifndef wrap_wpad_h
#define wrap_wpad_h

#include <gctypes.h>
#include <wiiuse/wpad.h>

namespace ogcwrap::wpad
{
	// library management
	WPADReturnValue init(void);
	void shutdown(void);

	// sethods
	void setCallback(CallbackType cbtype, WPADShutdownCallback cb);
	void setDataFormat(WiimoteChannel channel, DataFormat format);
	void setMotionPlus(WiimoteChannel channel, bool status);
	void setVRes(WiimoteChannel channel, u16 xRes, u16 yRes);
	void setEventBuffers(WiimoteChannel channel, WPADData * bufs, u32 count);
	void setIdleTimeout(u32 seconds);
	void setIdleThresholds(WiimoteChannel channel, s32 buttons, s32 ir, s32 accel, s32 js, s32 wb, s32 mp);

	// gethods
	WPADReturnValue getStatus(void);
	WPADReturnValue getSpeakerStatus(WiimoteChannel channel);
	s32 getDroppedEventCount(WiimoteChannel channel);
	u8 getBatteryLevel(WiimoteChannel channel);

	// write methods + encode
	void encodeData(WPADEncStatus * info, u32 flags, const s16 * PCMSamples, s32 count, u8 * data);
	WPADReturnValue writeRumbleStatus(WiimoteChannel channel, bool status);
	WPADReturnValue writeSpeakerStatus(WiimoteChannel channel, bool status);
	WPADReturnValue writeStreamData(WiimoteChannel channel, void * buffer, u32 size);
	void flush(WiimoteChannel channel);

	// read event methods
	void readEvents(WiimoteChannel channel, WPADData * data);
	u32 readPendingEvents(WiimoteChannel channel, WPADDataCallback cb);
	bool probe(WiimoteChannel channel, u32 * type);

	// read input methods
	void scan(void);
	WPADData * readWPADData(WiimoteChannel channel);
	u32 readButtonStatus(WiimoteChannel channel, ButtonType type);
	void readIR(WiimoteChannel channel, ir_t * ir);
	void readOrientation(WiimoteChannel channel, orient_t * orient);
	void readGForce(WiimoteChannel channel, gforce_t * gforce);
	void readAcceleration(WiimoteChannel channel, vec3w_t * accel);
	void readExpansion(WiimoteChannel channel, expansion_t * exp);
}

#endif // wrap_wpad_h