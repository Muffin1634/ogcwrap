#pragma once
#ifndef wrap_system_h
#define wrap_system_h

#include <gctypes.h>
#include <ogc/system.h>
#include <ogc/gx_struct.h>

#include "system/system_td.hpp"

namespace ogcwrap
{
	namespace system // not double nesting namespace here is INTENTIONAL!!!
	{
		// subsystem management
		void reset(SystemResetMode mode);

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
		u16 getWirelessID(u32 channel);
		u16 getGBSMode(void);
		void * getArena1Low(void);
		void * getArena1High(void);
		u32 getArena1Size(void);
		void * getArena2Low(void);
		void * getArena2High(void);
		u32 getArena2Size(void);
		u32 getResetButtonStatus(void);

		// sethods
		resetcallback setResetCallback(resetcallback cb);
		powercallback setPowerCallback(powercallback cb);
		void setCounterBias(u32 bias);
		void setDisplayOffsetH(s8 offset);
		void setEuRGB60(bool status);
		void setLanguage(SystemLanguage lang);
		void setProgressiveScan(bool status);
		void setAudioMode(SystemAudioMode mode);
		void setVideoMode(SystemVideoMode mode);
		void setWirelessID(u32 channel, u16 id);
		void setGBSMode(u16 mode);
		void setArena1Low(void * newval);
		void setArena1High(void * newval);
		void setArena2Low(void * newval);
		void setArena2High(void * newval);
		void setFiber(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 pc, u32 newsp);

		// miscellaneous
		void * allocateFramebuffer(GXRModeObj * rmode);
		void protectRange(u32 channel, void * addr, u32 bytes, u32 ctrl);

		// pmc
		void startPMC(u32 mcr0, u32 mcr1);
		void stopPMC(void);
		void resetPMC(void);
		void dumpPMC(void);

		// alarm
		bool createAlarm(syswd_t * alarm);
		bool removeAlarm(syswd_t alarm);
		bool setAlarm(syswd_t alarm, const timespec * time, alarmcallback cb, void * cbArgs);
		bool setPeriodicAlarm(syswd_t alarm, const timespec * time, const timespec * period, alarmcallback cb, void * cbArgs);
		bool cancelAlarm(syswd_t alarm);

		// font
		u32 initFont(sys_fontheader * font);
		u32 getFontEncoding(void);
		void getFontTexture(s32 c, void * * image, s32 * posX, s32 * posY, s32 * width);
		void getFontTexel(s32 c, void * image, s32 pos, s32 stride, s32 * width);

		// reset function
		void registerResetFunction(sys_resetinfo * info);
		void unregisterResetFunction(sys_resetinfo * info);

		namespace detail
		{
			void init(void);
		}
	}

	namespace memcast
	{
		// src addr -> dest addr
		void * Virtual_Physical(void * addr);
		void * Physical_K0(void * addr);
		void * Physical_K1(void * addr);
		void * K0_Physical(void * addr);
		void * K0_K1(void * addr);
		void * K1_Physical(void * addr);
		void * K1_K0(void * addr);
	}
}

#endif // wrap_system_h