#pragma once
#ifndef wrap_wiiuse_h
#define wrap_wiiuse_h

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

#endif // wrap_wiiuse_h