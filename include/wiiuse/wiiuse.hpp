#pragma once
#ifndef wrap_wiiuse_h
#define wrap_wiiuse_h

#include <gctypes.h>
#include <wiiuse/wiiuse.h>

#include <wiiuse/wiiuse_td.hpp>

namespace ogcwrap::wiiuse
{
	// subsystem management
//	const char * version(void);
	wiimote_t * * init(u8 number, wii_event_cb cb);

	// wiimote handling
	int registerWM(wiimote_listen_t * wml, bd_addr * bdaddr, wiimote_t * (*assign_cb)(bd_addr *));

//	void cleanupWM(wiimote_t * *, int);

	// bluetooth handling
//	int findWM(wiimote_t * *, int, int);
//	int connectWM(wiimote_t * *, int);
//	void resyncWM(wiimote_t *);
	void disconnectWM(wiimote_t * wm);

	// gethods
//	wiimote_t * getWMByID(wiimote_t * *, int, int);
	void getStatus(wiimote_t * wm, cmd_blk_cb cb);

	// sethods
	void setLEDs(wiimote_t * wm, u8 leds, cmd_blk_cb cb);
	void setRumbleStatus(wiimote_t * wm, bool status);
	#ifndef GEKKO
		void setSensorBarStatus(bool status);
	#endif
	u32 setFlags(wiimote_t * wm, u32 enabledFlags, u32 disabledFlags);
//	float setSmoothingAlpha(wiimote_t *, float);
//	void setBluetoothStack(wiimote_t * *, int, win_bt_stack_t);
//	void setTimeout(wiimote_t * *, int, ubyte, ubyte);
	void setMotionStatus(wiimote_t * wm, bool status);
	void setMotionPlusStatus(wiimote_t * wm, bool status);
	void setSpeakerStatus(wiimote_t * wm, bool status);
	void setAspectRatio(wiimote_t * wm, ScreenAspectRatio aspect);
	void setIRStatus(wiimote_t * wm, bool status);
	void setIRPosition(wiimote_t * wm, IRBarPosition position);
	void setIRVRes(wiimote_t * wm, u32 xRes, u32 yRes);
	void setIRSensitivity(wiimote_t * wm, u8 sens);
	void setIRMode(wiimote_t * wm);

	void toggleRumbleStatus(wiimote_t * wm);

	// read methods
	bool readData(wiimote_t * wm, ubyte * buffer, u32 offset, u16 length, cmd_blk_cb cb);
//	int pollWM(wiimote_t * *, int);

	// write methods
	bool writeData(wiimote_t * wm, u32 address, u8 * data, u8 length, cmd_blk_cb cb);
	bool writeStreamData(wiimote_t * wm, u8 * data, u8 length, cmd_blk_cb cb);
}

#endif // wrap_wiiuse_h