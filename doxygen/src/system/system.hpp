#pragma once
#ifndef wrap_system_h
#define wrap_system_h

#include <gctypes.h>
#include <ogc/system.h>
#include <ogc/gx_struct.h>

#include "system/system_td.hpp"

namespace ogcwrap
{
	namespace system
	{
		// management
		void reset(s32, u32, u32);

		// gethods
		u32 getHollywoodRevision(void);
		u64 getTime(void);
		u32 getCounterBias(void);
		s8 getDisplayOffsetH(void);
		bool getEuRGB60(void);
		SystemLanguage getLanguage(void);
		bool getProgressiveScanStatus(void);
		SystemAudioMode getAudioMode(void);
		SystemVideoMode getVideoMode(void);
		u16 getWirelessID(u32);
		u16 getGBSMode(void);
		void * getArena1Low(void);
		void * getArena1High(void);
		u32 getArena1Size(void);
		void * getArena2Low(void);
		void * getArena2High(void);
		u32 getArena2Size(void);
		u32 getResetButtonStatus(void);

		// sethods
		resetcallback setResetCallback(resetcallback);
		powercallback setPowerCallback(powercallback);
		void setCounterBias(u32);
		void setDisplayOffsetH(s8);
		void setEuRGB60(bool);
		void setLanguage(SystemLanguage);
		void setProgressiveScan(bool);
		void setAudioMode(SystemAudioMode);
		void setVideoMode(SystemVideoMode);
		void setWirelessID(u32, u16);
		void setGBSMode(u16);
		void setArena1Low(void *);
		void setArena1High(void *);
		void setArena2Low(void *);
		void setArena2High(void *);
		void setFiber(u32, u32, u32, u32, u32, u32);

		// miscellaneous
		void * allocateFramebuffer(GXRModeObj *);
		void protectRange(u32, void *, u32, u32);

		// pmc
		void startPMC(u32, u32);
		void stopPMC(void);
		void resetPMC(void);
		void dumpPMC(void);

		// alarm
		bool createAlarm(syswd_t *);
		bool removeAlarm(syswd_t);
		bool setAlarm(syswd_t, const timespec *, alarmcallback, void *);
		bool setPeriodicAlarm(syswd_t, const timespec *, const timespec *, alarmcallback, void *);
		bool cancelAlarm(syswd_t);

		// font
		u32 initFont(sys_fontheader *);
		u32 getFontEncoding(void);
		void getFontTexture(s32, void * *, s32 *, s32 *, s32 *);
		void getFontTexel(s32, void *, s32, s32, s32 *);

		// reset function
		void registerResetFunction(sys_resetinfo *);
		void unregisterResetFunction(sys_resetinfo *);
	}

	namespace memcast
	{
		// src addr -> dest addr
		void * Virtual_Physical(u32);
		void * Physical_K0(u32);
		void * Physical_K1(u32);
		void * K0_Physical(u32);
		void * K0_K1(u32);
		void * K1_Physical(u32);
		void * K1_K0(u32);
	}
}

#endif // wrap_system_h