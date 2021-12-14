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
	const char * version(void);
	wiimote_t * * init(u8);
	wiimote_t * * init(u8, wii_event_cb);

	// wiimote handling
	int registerWM(wiimote_listen_t *, bd_addr *, wiimote_t * (*)(bd_addr *));
	void cleanupWM(wiimote_t * *, int);

	// bluetooth handling
	int findWM(wiimote_t * *, int, int);
	int connectWM(wiimote_t * *, int);
	void resyncWM(wiimote_t *);
	void disconnectWM(wiimote_t *);

	// gethods
	wiimote_t * getWMByID(wiimote_t * *, int, int);
	void getStatus(wiimote_t *, cmd_blk_cb);

	// sethods
	void setLEDs(wiimote_t *, u8, cmd_blk_cb);
	void setRumbleStatus(wiimote_t *, bool);
	void setSensorBarStatus(bool);
	u32 setFlags(wiimote_t *, u32, u32);
	float setSmoothingAlpha(wiimote_t *, float);
	void setBluetoothStack(wiimote_t * *, int, win_bt_stack_t);
	void setTimeout(wiimote_t * *, int, ubyte, ubyte);
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
	int pollWM(wiimote_t * *, int);

	// write methods
	bool writeData(wiimote_t *, u32, u8 *, u8, cmd_blk_cb);
	bool writeStreamData(wiimote_t *, u8 *, u8, cmd_blk_cb);
}

/*******************************************************************************
 * functions
 */

using ogcwrap::wiiuse::wiiuse_aspect_t;
using ogcwrap::wiiuse::wiiuse_ir_position_t;

const char * ogcwrap::wiiuse::version(void)
	{ return wiiuse_version(); }

wiimote_t * * ogcwrap::wiiuse::init(u8 number, wii_event_cb cb)
	{ return wiiuse_init(number, cb); }

int ogcwrap::wiiuse::registerWM(wiimote_listen_t * wml, bd_addr * bdaddr, wiimote_t * (*assign_cb)(bd_addr *))
	{ return wiiuse_register(wml, bdaddr, assign_cb); }

void ogcwrap::wiiuse::cleanupWM(wiimote_t * * wm, int wiimotes)
	{ wiiuse_cleanup(wm, wiimotes); }

int ogcwrap::wiiuse::findWM(wiimote_t * * wm, int maxWiimotes, int timeout)
	{ return wiiuse_find(wm, maxWiimotes, timeout); }

int ogcwrap::wiiuse::connectWM(wiimote_t * * wm, int wiimotes)
	{ return wiiuse_connect(wm, wiimotes); }

void ogcwrap::wiiuse::resyncWM(wiimote_t * wm)
	{ wiiuse_resync(wm); }

void ogcwrap::wiiuse::disconnectWM(wiimote_t * wm)
	{ wiiuse_disconnect(wm); }

wiimote_t * ogcwrap::wiiuse::getWMByID(wiimote_t * * wm, int wiimotes, int uid)
	{ return wiiuse_get_by_id(wm, wiimotes, uid); }

void ogcwrap::wiiuse::getStatus(wiimote_t * wm, cmd_blk_cb cb)
	{ wiiuse_status(wm, cb); }

void ogcwrap::wiiuse::setLEDs(wiimote_t * wm, u8 leds, cmd_blk_cb cb)
	{ wiiuse_set_leds(wm, leds, cb); }

void ogcwrap::wiiuse::setRumbleStatus(wiimote_t * wm, bool status)
	{ wiiuse_rumble(wm, status); }

void ogcwrap::wiiuse::setSensorBarStatus(bool status [[maybe_unused]])
	{ wiiuse_sensorbar_enable(status); }

u32 ogcwrap::wiiuse::setFlags(wiimote_t * wm, u32 enable, u32 disable)
	{ return wiiuse_set_flags(wm, enable, disable); }

float ogcwrap::wiiuse::setSmoothingAlpha(wiimote_t * wm, float alpha)
	{ return wiiuse_set_smooth_alpha(wm, alpha); }

void ogcwrap::wiiuse::setBluetoothStack(wiimote_t * * wm, int wiimotes, win_bt_stack_t unid)
	{ wiiuse_set_bluetooth_stack(wm, wiimotes, unid); }

void ogcwrap::wiiuse::setTimeout(wiimote_t * * wm, int wiimotes, u8 normal_timeout, u8 exp_timeout)
	{ wiiuse_set_timeout(wm, wiimotes, mcast(ubyte, normal_timeout), mcast(ubyte, exp_timeout)); }

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

int ogcwrap::wiiuse::pollWM(wiimote_t * * wm, int wiimotes)
	{ return wiiuse_poll(wm, wiimotes); }

bool ogcwrap::wiiuse::writeData(wiimote_t * wm, u32 addr, u8 * data, u8 len, cmd_blk_cb cb)
	{ return wiiuse_write_data(wm, addr, data, len, cb); }

bool ogcwrap::wiiuse::writeStreamData(wiimote_t * wm, u8 * data, u8 len, cmd_blk_cb cb)
	{ return wiiuse_write_streamdata(wm, data, len, cb); }