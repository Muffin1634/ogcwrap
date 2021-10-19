/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "wpad/wpad_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::wpad
{
	// subsystem management
	wpad_ret_vals_t init(void);
	void shutdown(void);

	// sethods
	void setCallback(callback_type_t, WPADShutdownCallback);
	void setDataFormat(wiimote_channel_t, data_format_t);
	void setMotionPlus(wiimote_channel_t, bool);
	void setVRes(wiimote_channel_t, u16, u16);
	void setEventBuffers(wiimote_channel_t, WPADData *, u32);
	void setIdleTimeout(u32);
	void setIdleThresholds(wiimote_channel_t, s32, s32, s32, s32, s32, s32);

	// gethods
	wpad_ret_vals_t getStatus(void);
	wpad_ret_vals_t getSpeakerStatus(wiimote_channel_t);
	s32 getDroppedEventCount(wiimote_channel_t);
	u8 getBatteryLevel(wiimote_channel_t);

	// write methods + encode
	void encodeData(WPADEncStatus *, u32, const s16 *, s32, u8 *);
	wpad_ret_vals_t writeRumbleStatus(wiimote_channel_t, bool);
	wpad_ret_vals_t writeSpeakerStatus(wiimote_channel_t, bool);
	wpad_ret_vals_t writeStreamData(wiimote_channel_t, void *, u32);
	void flush(wiimote_channel_t);

	// read event methods
	void readEvents(wiimote_channel_t, WPADData *);
	s32 readPendingEvents(wiimote_channel_t, WPADDataCallback);
	wpad_ret_vals_t probe(wiimote_channel_t, u32 *);

	// read input methods
	void scan(void);
	WPADData * readWPADData(wiimote_channel_t);
	u32 readButtonStatus(wiimote_channel_t, button_type_t);
	void readIR(wiimote_channel_t, ir_t *);
	void readOrientation(wiimote_channel_t, orient_t *);
	void readGForce(wiimote_channel_t, gforce_t *);
	void readAcceleration(wiimote_channel_t, vec3w_t *);
	void readExpansion(wiimote_channel_t, expansion_t *);
}

/*******************************************************************************
 * functions
 */

using ogcwrap::wpad::wpad_ret_vals_t;

wpad_ret_vals_t ogcwrap::wpad::init(void)
	{ return mcast(wpad_ret_vals_t, WPAD_Init()); }

void ogcwrap::wpad::shutdown(void)
	{ WPAD_Shutdown(); }

void ogcwrap::wpad::setCallback(callback_type_t type, WPADShutdownCallback cb)
{
	switch (type)
	{
		case callback_type_t::PowerButtonCB:
			WPAD_SetPowerButtonCallback(cb);
			break;
		case callback_type_t::BatteryDeadCB:
			WPAD_SetBatteryDeadCallback(cb);
			break;

		default:
			break;
	}
}

void ogcwrap::wpad::setDataFormat(wiimote_channel_t channel, data_format_t format)
	{ WPAD_SetDataFormat(mcast(s32, channel), mcast(s32, format)); }

void ogcwrap::wpad::setMotionPlus(wiimote_channel_t channel, bool status)
	{ WPAD_SetMotionPlus(mcast(s32, channel), status); }

void ogcwrap::wpad::setVRes(wiimote_channel_t channel, u16 xres, u16 yres)
	{ WPAD_SetVRes(mcast(s32, channel), xres, yres); }

void ogcwrap::wpad::setEventBuffers(wiimote_channel_t channel, WPADData * bufs, u32 count)
	{ WPAD_SetEventBufs(mcast(s32, channel), bufs, count); }

void ogcwrap::wpad::setIdleTimeout(u32 seconds)
	{ WPAD_SetIdleTimeout(seconds); }

void ogcwrap::wpad::setIdleThresholds(wiimote_channel_t channel, s32 buttons, s32 ir, s32 accel, s32 js, s32 wb, s32 mp)
	{ WPAD_SetIdleThresholds(mcast(s32, channel), buttons, ir, accel, js, wb, mp); }

wpad_ret_vals_t ogcwrap::wpad::getStatus(void)
	{ return mcast(wpad_ret_vals_t, WPAD_GetStatus()); }

wpad_ret_vals_t ogcwrap::wpad::getSpeakerStatus(wiimote_channel_t channel)
	{ return mcast(wpad_ret_vals_t, WPAD_IsSpeakerEnabled(mcast(s32, channel))); }

s32 ogcwrap::wpad::getDroppedEventCount(wiimote_channel_t channel)
	{ return WPAD_DroppedEvents(mcast(s32, channel)); }

u8 ogcwrap::wpad::getBatteryLevel(wiimote_channel_t channel)
	{ return WPAD_BatteryLevel(mcast(s32, channel)); }

void ogcwrap::wpad::encodeData(WPADEncStatus * info, u32 flags, const s16 * PCMSamples, s32 sampleCount, u8 * data)
	{ WPAD_EncodeData(info, flags, PCMSamples, sampleCount, data); }

wpad_ret_vals_t ogcwrap::wpad::writeRumbleStatus(wiimote_channel_t channel, bool status)
	{ return mcast(wpad_ret_vals_t, WPAD_Rumble(mcast(s32, channel), status)); }

wpad_ret_vals_t ogcwrap::wpad::writeSpeakerStatus(wiimote_channel_t channel, bool status)
	{ return mcast(wpad_ret_vals_t, WPAD_ControlSpeaker(mcast(s32, channel), status)); }

wpad_ret_vals_t ogcwrap::wpad::writeStreamData(wiimote_channel_t channel, void * buffer, u32 size)
	{ return mcast(wpad_ret_vals_t, WPAD_SendStreamData(mcast(s32, channel), buffer, size)); }

void ogcwrap::wpad::flush(wiimote_channel_t channel)
	{ WPAD_Flush(mcast(s32, channel)); }

void ogcwrap::wpad::readEvents(wiimote_channel_t channel, WPADData * data)
	{ WPAD_ReadEvent(mcast(s32, channel), data); }

s32 ogcwrap::wpad::readPendingEvents(wiimote_channel_t channel, WPADDataCallback cb)
	{ return WPAD_ReadPending(mcast(s32, channel), cb); }

wpad_ret_vals_t ogcwrap::wpad::probe(wiimote_channel_t channel, u32 * type)
	{ return mcast(wpad_ret_vals_t, WPAD_Probe(mcast(s32, channel), type)); }

void ogcwrap::wpad::scan(void)
	{ WPAD_ScanPads(); }

WPADData * ogcwrap::wpad::readWPADData(wiimote_channel_t channel)
	{ return WPAD_Data(mcast(s32, channel)); }

u32 ogcwrap::wpad::readButtonStatus(wiimote_channel_t channel, button_type_t type)
{
	switch (type)
	{
		case button_type_t::ButtonsUp:
			return WPAD_ButtonsUp(mcast(s32, channel));
		case button_type_t::ButtonsDown:
			return WPAD_ButtonsDown(mcast(s32, channel));
		case button_type_t::ButtonsHeld:
			return WPAD_ButtonsHeld(mcast(s32, channel));

		default:
			return -1;
	}
}

void ogcwrap::wpad::readIR(wiimote_channel_t channel, ir_t * ir)
	{ WPAD_IR(mcast(s32, channel), ir); }

void ogcwrap::wpad::readOrientation(wiimote_channel_t channel, orient_t * orient)
	{ WPAD_Orientation(mcast(s32, channel), orient); }

void ogcwrap::wpad::readGForce(wiimote_channel_t channel, gforce_t * gforce)
	{ WPAD_GForce(mcast(s32, channel), gforce); }

void ogcwrap::wpad::readAcceleration(wiimote_channel_t channel, vec3w_t * accel)
	{ WPAD_Accel(mcast(s32, channel), accel); }

void ogcwrap::wpad::readExpansion(wiimote_channel_t channel, expansion_t * exp)
	{ WPAD_Expansion(mcast(s32, channel), exp); }