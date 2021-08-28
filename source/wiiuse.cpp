/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap
{
	namespace wiiuse
	{
		// library management
		const char * version(void);
		struct wiimote_t * * init(int);
		struct wiimote_t * * init(int, wii_event_cb);

		// wiimote handling
		int registerWM(struct wiimote_listen_t *, struct bd_addr *, struct wiimote_t * (*)(struct bd_addr *));
		void cleanupWM(struct wiimote_t * *, int);

		// bluetooth handling
		int findWM(struct wiimote_t * *, int, int);
		int connectWM(struct wiimote_t * *, int);
		void resyncWM(struct wiimote_t *);
		void disconnectWM(struct wiimote_t *);

		// gethods
		struct wiimote_t * getWMByID(struct wiimote_t * *, int, int);
		void getStatus(struct wiimote_t *, cmd_blk_cb);

		// sethods
		void setLEDs(struct wiimote_t *, int, cmd_blk_cb);
		void setRumbleStatus(struct wiimote_t *, bool);
		void setSensorBarStatus(bool);
		int setFlags(struct wiimote_t *, int, int);
		float setSmoothingAlpha(struct wiimote_t *, float);
		void setBluetoothStack(struct wiimote_t * *, int, enum win_bt_stack_t);
		void setTimeout(struct wiimote_t * *, int, ubyte, ubyte);
		void setMotionStatus(struct wiimote_t *, bool);
		void setMotionPlusStatus(struct wiimote_t *, bool);
		void setSpeakerStatus(struct wiimote_t *, bool);
		void setAspectRatio(struct wiimote_t *, enum aspect_t);
		void setIRStatus(struct wiimote_t *, bool);
		void setIRPosition(struct wiimote_t *, enum ir_position_t);
		void setIRVRes(struct wiimote_t *, unsigned int, unsigned int);
		void setIRSensitivity(struct wiimote_t *, int);
		void setIRMode(struct wiimote_t *);

		void toggleRumbleStatus(struct wiimote_t *);

		// read methods
		int readData(struct wiimote_t *, ubyte *, unsigned int, unsigned short, cmd_blk_cb);
		int pollWM(struct wiimote_t * *, int);

		// write methods
		int writeData(struct wiimote_t *, unsigned int, ubyte *, ubyte, cmd_blk_cb);
		int writeStreamData(struct wiimote_t *, ubyte *, ubyte, cmd_blk_cb);
	}
}

/*******************************************************************************
 * functions
 */

const char * ogcwrap::wiiuse::version(void)
	{ return wiiuse_version(); }

struct wiimote_t * * ogcwrap::wiiuse::init(int number [[maybe_unused]])
{
	#ifndef GEKKO
		return wiiuse_init(number);
	#else
		#warning You must supply another argument of type wii_event_cb to this function as well. (Wii, ::init)
		return nullptr;
	#endif
}

struct wiimote_t * * ogcwrap::wiiuse::init(int number, wii_event_cb cb [[maybe_unused]])
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

int ogcwrap::wiiuse::registerWM(struct wiimote_listen_t * wml [[maybe_unused]], struct bd_addr * bdaddr [[maybe_unused]], struct wiimote_t * (*assign_cb [[maybe_unused]])(struct bd_addr *))
{
	#ifndef GEKKO
		#warning This function is not defined for the platform you are developing for. (not Wii, ::registerWM)
		return -1;
	#else
		return wiiuse_register(wml, bdaddr, assign_cb);
	#endif
}

void ogcwrap::wiiuse::cleanupWM(struct wiimote_t * * wma, int wiimotes)
	{ wiiuse_cleanup(wma, wiimotes); }

int ogcwrap::wiiuse::findWM(struct wiimote_t * * wma, int max, int timeout)
	{ return wiiuse_find(wma, max, timeout); }

int ogcwrap::wiiuse::connectWM(struct wiimote_t * * wma, int wiimotes)
	{ return wiiuse_connect(wma, wiimotes); }

void ogcwrap::wiiuse::resyncWM(struct wiimote_t * wm)
	{ wiiuse_resync(wm); }

void ogcwrap::wiiuse::disconnectWM(struct wiimote_t * wm)
	{ wiiuse_disconnect(wm); }

struct wiimote_t * ogcwrap::wiiuse::getWMByID(struct wiimote_t * * wma, int wiimotes, int uid)
	{ return wiiuse_get_by_id(wma, wiimotes, uid); }

void ogcwrap::wiiuse::getStatus(struct wiimote_t * wm, cmd_blk_cb cb)
	{ wiiuse_status(wm, cb); }

void ogcwrap::wiiuse::setLEDs(struct wiimote_t * wm, int leds, cmd_blk_cb cb)
	{ wiiuse_set_leds(wm, leds, cb); }

void ogcwrap::wiiuse::setRumbleStatus(struct wiimote_t * wm, bool status)
	{ wiiuse_rumble(wm, ((int)(status))); }

void ogcwrap::wiiuse::setSensorBarStatus(bool status [[maybe_unused]])
{
	#ifndef GEKKO
		#warning This function is not defined for the platform you are developing for. (not Wii, ::setSensorBarStatus)
	#else
		wiiuse_sensorbar_enable(((int)(status)));
	#endif
}

int ogcwrap::wiiuse::setFlags(struct wiimote_t * wm, int enable, int disable)
	{ return wiiuse_set_flags(wm, enable, disable); }

float ogcwrap::wiiuse::setSmoothingAlpha(struct wiimote_t * wm, float alpha)
	{ return wiiuse_set_smooth_alpha(wm, alpha); }

void ogcwrap::wiiuse::setBluetoothStack(struct wiimote_t * * wma, int wiimotes, enum win_bt_stack_t stack)
	{ wiiuse_set_bluetooth_stack(wma, wiimotes, stack); }

void ogcwrap::wiiuse::setTimeout(struct wiimote_t * * wma, int wiimotes, ubyte wmtime, ubyte exptime)
	{ wiiuse_set_timeout(wma, wiimotes, wmtime, exptime); }

void ogcwrap::wiiuse::setMotionStatus(struct wiimote_t * wm, bool status)
	{ wiiuse_motion_sensing(wm, ((int)(status))); }

void ogcwrap::wiiuse::setMotionPlusStatus(struct wiimote_t * wm, bool status)
	{ wiiuse_set_motion_plus(wm, ((int)(status))); }

void ogcwrap::wiiuse::setSpeakerStatus(struct wiimote_t * wm, bool status)
	{ wiiuse_set_speaker(wm, ((int)(status))); }

void ogcwrap::wiiuse::setAspectRatio(struct wiimote_t * wm, enum aspect_t aspect)
	{ wiiuse_set_aspect_ratio(wm, aspect); }

void ogcwrap::wiiuse::setIRStatus(struct wiimote_t * wm, bool status)
	{ wiiuse_set_ir(wm, ((int)(status))); }

void ogcwrap::wiiuse::setIRPosition(struct wiimote_t * wm, enum ir_position_t position)
	{ wiiuse_set_ir_position(wm, position); }

void ogcwrap::wiiuse::setIRVRes(struct wiimote_t * wm, unsigned int xres, unsigned int yres)
	{ wiiuse_set_ir_vres(wm, xres, yres); }

void ogcwrap::wiiuse::setIRSensitivity(struct wiimote_t * wm, int level)
	{ wiiuse_set_ir_sensitivity(wm, level); }

void ogcwrap::wiiuse::setIRMode(struct wiimote_t * wm)
	{ wiiuse_set_ir_mode(wm); }

void ogcwrap::wiiuse::toggleRumbleStatus(struct wiimote_t * wm)
	{ wiiuse_toggle_rumble(wm); }

int ogcwrap::wiiuse::readData(struct wiimote_t * wm, ubyte * buffer, unsigned int offset, unsigned short len, cmd_blk_cb cb)
	{ return wiiuse_read_data(wm, buffer, offset, len, cb); }

int ogcwrap::wiiuse::pollWM(struct wiimote_t * * wma, int wiimotes)
	{ return wiiuse_poll(wma, wiimotes); }

int ogcwrap::wiiuse::writeData(struct wiimote_t * wm, unsigned int addr, ubyte * data, ubyte len, cmd_blk_cb cb)
	{ return wiiuse_write_data(wm, addr, data, len, cb); }

int ogcwrap::wiiuse::writeStreamData(struct wiimote_t * wm, ubyte * data, ubyte len, cmd_blk_cb cb)
	{ return wiiuse_write_streamdata(wm, data, len, cb); }