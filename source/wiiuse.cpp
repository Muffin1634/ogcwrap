/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "wiiuse/wiiuse_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::wiiuse
{
	// subsystem management
//	const char * version(void);
	wiimote_t * * init(u8);
	wiimote_t * * init(u8, wii_event_cb);

	// wiimote handling
	int registerWM(wiimote_listen_t *, bd_addr *, wiimote_t * (*)(bd_addr *));
//	void cleanupWM(wiimote_t * *, int);

	// bluetooth handling
//	int findWM(wiimote_t * *, int, int);
//	int connectWM(wiimote_t * *, int);
//	void resyncWM(wiimote_t *);
	void disconnectWM(wiimote_t *);

	// gethods
//	wiimote_t * getWMByID(wiimote_t * *, int, int);
	void getStatus(wiimote_t *, cmd_blk_cb);

	// sethods
	void setLEDs(wiimote_t *, u8, cmd_blk_cb);
	void setRumbleStatus(wiimote_t *, bool);
	void setSensorBarStatus(bool);
	u32 setFlags(wiimote_t *, u32, u32);
//	float setSmoothingAlpha(wiimote_t *, float);
//	void setBluetoothStack(wiimote_t * *, int, win_bt_stack_t);
//	void setTimeout(wiimote_t * *, int, ubyte, ubyte);
	void setMotionStatus(wiimote_t *, bool);
	void setMotionPlusStatus(wiimote_t *, bool);
	void setSpeakerStatus(wiimote_t *, bool);
	void setAspectRatio(wiimote_t *, wiiuse_aspect_t);
	void setIRStatus(wiimote_t *, bool);
	void setIRPosition(wiimote_t *, wiiuse_ir_position_t);
	void setIRVRes(wiimote_t *, u32, u32);
	void setIRSensitivity(wiimote_t *, u8);
	void setIRMode(wiimote_t *);

	void toggleRumbleStatus(wiimote_t *);

	// read methods
	bool readData(wiimote_t *, ubyte *, u32, u16, cmd_blk_cb);
//	int pollWM(wiimote_t * *, int);

	// write methods
	bool writeData(wiimote_t *, u32, u8 *, u8, cmd_blk_cb);
	bool writeStreamData(wiimote_t *, u8 *, u8, cmd_blk_cb);
}

/*******************************************************************************
 * functions
 */

using ogcwrap::wiiuse::wiiuse_aspect_t;
using ogcwrap::wiiuse::wiiuse_ir_position_t;

/*
const char * ogcwrap::wiiuse::version()
	{}
*/

wiimote_t * * ogcwrap::wiiuse::init(u8 number [[maybe_unused]])
{
	#ifndef GEKKO
		return wiiuse_init(number);
	#else
		#warning You must supply another argument of type wii_event_cb to this function as well. (Wii, ::init)
		return nullptr;
	#endif
}

wiimote_t * * ogcwrap::wiiuse::init(u8 number, wii_event_cb cb [[maybe_unused]])
{
	#ifndef GEKKO
		#ifndef warn_wiiuse_init
			#define warn_wiiuse_init
			#warning You do not need to supply the wii_event_cb as it is not required if you are not developing a program for the Wii. (not Wii, ::init)
		#endif
		return wiiuse_init(number);
	#else
		return wiiuse_init(number, cb);
	#endif
}

int ogcwrap::wiiuse::registerWM(wiimote_listen_t * wml [[maybe_unused]], bd_addr * bdaddr [[maybe_unused]], wiimote_t * (*assign_cb [[maybe_unused]])(bd_addr *))
{
	#ifndef GEKKO
		#warning This function is not defined for the platform you are developing for. (not Wii, ::registerWM)
		return -1;
	#else
		return wiiuse_register(wml, bdaddr, assign_cb);
	#endif
}

/*
void ogcwrap::wiiuse::cleanupWM()
	{}
*/

/*
int ogcwrap::wiiuse::findWM()
	{}
*/

/*
int ogcwrap::wiiuse::connectWM()
	{}
*/

/*
void ogcwrap::wiiuse::resyncWM()
	{}
*/

void ogcwrap::wiiuse::disconnectWM(wiimote_t * wm)
	{ wiiuse_disconnect(wm); }

/*
wiimote_t * ogcwrap::wiiuse::getWMByID()
	{}
*/

void ogcwrap::wiiuse::getStatus(wiimote_t * wm, cmd_blk_cb cb)
	{ wiiuse_status(wm, cb); }

void ogcwrap::wiiuse::setLEDs(wiimote_t * wm, u8 leds, cmd_blk_cb cb)
	{ wiiuse_set_leds(wm, leds, cb); }

void ogcwrap::wiiuse::setRumbleStatus(wiimote_t * wm, bool status)
	{ wiiuse_rumble(wm, status); }

void ogcwrap::wiiuse::setSensorBarStatus(bool status [[maybe_unused]])
{
	#ifndef GEKKO
		#warning This function is not defined for the platform you are developing for. (not Wii, ::setSensorBarStatus)
	#else
		wiiuse_sensorbar_enable(status);
	#endif
}

u32 ogcwrap::wiiuse::setFlags(wiimote_t * wm, u32 enable, u32 disable)
	{ return wiiuse_set_flags(wm, enable, disable); }

/*
float ogcwrap::wiiuse::setSmoothingAlpha()
	{}
*/

/*
void ogcwrap::wiiuse::setBluetoothStack()
	{}
*/

/*
void ogcwrap::wiiuse::setTimeout()
	{}
*/

void ogcwrap::wiiuse::setMotionStatus(wiimote_t * wm, bool status)
	{ wiiuse_motion_sensing(wm, status); }

void ogcwrap::wiiuse::setMotionPlusStatus(wiimote_t * wm, bool status)
	{ wiiuse_set_motion_plus(wm, status); }

void ogcwrap::wiiuse::setSpeakerStatus(wiimote_t * wm, bool status)
	{ wiiuse_set_speaker(wm, status); }

void ogcwrap::wiiuse::setAspectRatio(wiimote_t * wm, wiiuse_aspect_t aspect)
	{ wiiuse_set_aspect_ratio(wm, mcast(aspect_t, aspect)); }

void ogcwrap::wiiuse::setIRStatus(wiimote_t * wm, bool status)
	{ wiiuse_set_ir(wm, status); }

void ogcwrap::wiiuse::setIRPosition(wiimote_t * wm, wiiuse_ir_position_t position)
	{ wiiuse_set_ir_position(wm, mcast(ir_position_t, position)); }

void ogcwrap::wiiuse::setIRVRes(wiimote_t * wm, u32 xres, u32 yres)
	{ wiiuse_set_ir_vres(wm, xres, yres); }

void ogcwrap::wiiuse::setIRSensitivity(wiimote_t * wm, u8 level)
	{ wiiuse_set_ir_sensitivity(wm, level); }

void ogcwrap::wiiuse::setIRMode(wiimote_t * wm)
	{ wiiuse_set_ir_mode(wm); }

void ogcwrap::wiiuse::toggleRumbleStatus(wiimote_t * wm)
	{ wiiuse_toggle_rumble(wm); }

bool ogcwrap::wiiuse::readData(wiimote_t * wm, u8 * buffer, u32 offset, u16 len, cmd_blk_cb cb)
	{ return wiiuse_read_data(wm, buffer, offset, len, cb); }

/*
int ogcwrap::wiiuse::pollWM()
	{}
*/

bool ogcwrap::wiiuse::writeData(wiimote_t * wm, u32 addr, u8 * data, u8 len, cmd_blk_cb cb)
	{ return wiiuse_write_data(wm, addr, data, len, cb); }

bool ogcwrap::wiiuse::writeStreamData(wiimote_t * wm, u8 * data, u8 len, cmd_blk_cb cb)
	{ return wiiuse_write_streamdata(wm, data, len, cb); }