#pragma once
#ifndef wrap_wpad_h
#define wrap_wpad_h

namespace wiimote
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

#endif // wrap_wpad_h