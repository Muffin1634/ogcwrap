/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap
{
	namespace system
	{
		// enums

		enum sys_language_t
		{
			English,
			German,
			French,
			Spanish,
			Italian,
			Dutch
		};

		enum sys_audio_mode_t
		{
			Mono,
			Stereo
		};

		enum sys_video_mode_t
		{
			NTSC,
			PAL,
			MPAL
		};

		// management
		void reset(s32, u32, u32);

		// gethods
		u32 getHollywoodRevision(void);
		u64 getTime(void);
		u32 getCounterBias(void);
		s8 getDisplayOffsetH(void);
		bool getEuRGB60(void);
		sys_language_t getLanguage(void);
		bool getProgressiveScanStatus(void);
		sys_audio_mode_t getAudioMode(void);
		sys_video_mode_t getVideoMode(void);
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
		void setLanguage(sys_language_t);
		void setProgressiveScan(bool);
		void setAudioMode(sys_audio_mode_t);
		void setVideoMode(sys_video_mode_t);
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

		// detail
		namespace detail
		{
			/* apparently this is not supposed to be called by the program since
			 * it is already called by something else so here it is in detail
			 */
			void init(void);

			// encode (f<-b)
			sys_language_t encodeL(u8);
			sys_audio_mode_t encodeAM(u8);
			sys_video_mode_t encodeVM(u8);

			// decode (f->b)
			u8 decodeL(sys_language_t);
			u8 decodeAM(sys_audio_mode_t);
			u8 decodeVM(sys_video_mode_t);
		}
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

/*******************************************************************************
 * functions
 */

using ogcwrap::system::sys_language_t;
using ogcwrap::system::sys_audio_mode_t;
using ogcwrap::system::sys_video_mode_t;

using namespace ogcwrap::system::detail;

void ogcwrap::system::reset(s32 reset, u32 resetcode, u32 forcemenu)
	{ SYS_ResetSystem(reset, resetcode, forcemenu); }

u32 ogcwrap::system::getHollywoodRevision(void)
	{ return SYS_GetHollywoodRevision(); }

u64 ogcwrap::system::getTime(void)
	{ return SYS_Time(); }

u32 ogcwrap::system::getCounterBias(void)
	{ return SYS_GetCounterBias(); }

s8 ogcwrap::system::getDisplayOffsetH(void)
	{ return SYS_GetDisplayOffsetH(); }

bool ogcwrap::system::getEuRGB60(void)
	{ return (SYS_GetEuRGB60() == 1 ? true : false); }

sys_language_t ogcwrap::system::getLanguage(void)
	{ return detail::encodeL(SYS_GetLanguage()); }

bool ogcwrap::system::getProgressiveScanStatus(void)
	{ return (SYS_GetProgressiveScan() == 1 ? true : false); }

sys_audio_mode_t ogcwrap::system::getAudioMode(void)
	{ return detail::encodeAM(SYS_GetSoundMode()); }

sys_video_mode_t ogcwrap::system::getVideoMode(void)
	{ return detail::encodeVM(SYS_GetVideoMode()); }

u16 ogcwrap::system::getWirelessID(u32 channel)
	{ return SYS_GetWirelessID(channel); }

u16 ogcwrap::system::getGBSMode(void)
	{ return SYS_GetGBSMode(); }

void * ogcwrap::system::getArena1Low(void)
	{ return SYS_GetArena1Lo(); }

void * ogcwrap::system::getArena1High(void)
	{ return SYS_GetArena1Hi(); }

u32 ogcwrap::system::getArena1Size(void)
	{ return SYS_GetArena1Size(); }

void * ogcwrap::system::getArena2Low(void)
	{ return SYS_GetArena2Lo(); }

void * ogcwrap::system::getArena2High(void)
	{ return SYS_GetArena2Hi(); }

u32 ogcwrap::system::getArena2Size(void)
	{ return SYS_GetArena2Size(); }

u32 ogcwrap::system::getResetButtonStatus(void)
	{ return SYS_ResetButtonDown(); }

resetcallback ogcwrap::system::setResetCallback(resetcallback cb)
	{ return SYS_SetResetCallback(cb); }

powercallback ogcwrap::system::setPowerCallback(powercallback cb)
	{ return SYS_SetPowerCallback(cb); }

void ogcwrap::system::setCounterBias(u32 bias)
	{ SYS_SetCounterBias(bias); }

void ogcwrap::system::setDisplayOffsetH(s8 offset)
	{ SYS_SetDisplayOffsetH(offset); }

void ogcwrap::system::setEuRGB60(bool status)
	{ SYS_SetEuRGB60(((u8)(status))); }

void ogcwrap::system::setLanguage(sys_language_t lang)
	{ SYS_SetLanguage(detail::decodeL(lang)); }

void ogcwrap::system::setProgressiveScan(bool status)
	{ SYS_SetProgressiveScan(status); }

void ogcwrap::system::setAudioMode(sys_audio_mode_t mode)
	{ SYS_SetSoundMode(detail::decodeAM(mode)); }

void ogcwrap::system::setVideoMode(sys_video_mode_t mode)
	{ SYS_SetVideoMode(detail::decodeVM(mode)); }

void ogcwrap::system::setWirelessID(u32 channel, u16 id)
	{ SYS_SetWirelessID(channel, id); }

void ogcwrap::system::setGBSMode(u16 mode)
	{ SYS_SetGBSMode(mode); }

void ogcwrap::system::setArena1Low(void * newval)
	{ SYS_SetArena1Lo(newval); }

void ogcwrap::system::setArena1High(void * newval)
	{ SYS_SetArena1Hi(newval); }

void ogcwrap::system::setArena2Low(void * newval)
	{ SYS_SetArena2Lo(newval); }

void ogcwrap::system::setArena2High(void * newval)
	{ SYS_SetArena2Hi(newval); }

void ogcwrap::system::setFiber(u32 a0, u32 a1, u32 a2, u32 a3, u32 pc, u32 newsp)
	{ SYS_SwitchFiber(a0, a1, a2, a3, pc, newsp); }

void * ogcwrap::system::allocateFramebuffer(GXRModeObj * rmode)
	{ return SYS_AllocateFramebuffer(rmode); }

void ogcwrap::system::protectRange(u32 channel, void * addr, u32 bytes, u32 ctrl)
	{ SYS_ProtectRange(channel, addr, bytes, ctrl); }

void ogcwrap::system::startPMC(u32 mcr0, u32 mcr1)
	{ SYS_StartPMC(mcr0, mcr1); }

void ogcwrap::system::stopPMC(void)
	{ SYS_StopPMC(); }

void ogcwrap::system::resetPMC(void)
	{ SYS_ResetPMC(); }

void ogcwrap::system::dumpPMC(void)
	{ SYS_DumpPMC(); }

bool ogcwrap::system::createAlarm(syswd_t * alarm)
	{ return (SYS_CreateAlarm(alarm) == 0 ? true : false); }

bool ogcwrap::system::removeAlarm(syswd_t alarm)
	{ return (SYS_RemoveAlarm(alarm) == 0 ? true : false); }

bool ogcwrap::system::setAlarm(syswd_t alarm, const timespec * time, alarmcallback cb, void * cbArgs)
	{ return (SYS_SetAlarm(alarm, time, cb, cbArgs) == 0 ? true : false); }

bool ogcwrap::system::setPeriodicAlarm(syswd_t alarm, const timespec * time, const timespec * period, alarmcallback cb, void * cbArgs)
	{ return (SYS_SetPeriodicAlarm(alarm, time, period, cb, cbArgs) == 0 ? true : false); }

bool ogcwrap::system::cancelAlarm(syswd_t alarm)
	{ return (SYS_CancelAlarm(alarm) == 0 ? true : false); }

u32 ogcwrap::system::initFont(sys_fontheader * font)
	{ return SYS_InitFont(font); }

u32 ogcwrap::system::getFontEncoding(void)
	{ return SYS_GetFontEncoding(); }

void ogcwrap::system::getFontTexture(s32 c, void * * image, s32 * posX, s32 *posY, s32 * width)
	{ SYS_GetFontTexture(c, image, posX, posY, width); }

void ogcwrap::system::getFontTexel(s32 c, void * image, s32 pos, s32 stride, s32 * width)
	{ SYS_GetFontTexel(c, image, pos, stride, width); }

void ogcwrap::system::registerResetFunction(sys_resetinfo * info)
	{ SYS_RegisterResetFunc(info); }

void ogcwrap::system::unregisterResetFunction(sys_resetinfo * info)
	{ SYS_UnregisterResetFunc(info); }

// ogcwrap:::memcast

void * ogcwrap::memcast::Virtual_Physical(u32 addr)
	{ return ((void *)(addr & 0x3FFFFFFF)); }

void * ogcwrap::memcast::Physical_K0(u32 addr)
	{ return ((void *)(addr + 0x80000000)); }

void * ogcwrap::memcast::Physical_K1(u32 addr)
	{ return ((void *)(addr + 0xC0000000)); }

void * ogcwrap::memcast::K0_Physical(u32 addr)
	{ return ((void *)(addr - 0x80000000)); }

void * ogcwrap::memcast::K0_K1(u32 addr)
	{ return ((void *)(addr + 0x40000000)); }

void * ogcwrap::memcast::K1_Physical(u32 addr)
	{ return ((void *)(addr - 0xC0000000)); }

void * ogcwrap::memcast::K1_K0(u32 addr)
	{ return ((void *)(addr - 0x40000000)); }

// ogcwrap::system::detail

void ogcwrap::system::detail::init(void)
	{ SYS_Init(); }

sys_language_t ogcwrap::system::detail::encodeL(u8 lang)
{
	switch (lang)
	{
		case 0: // English
			return sys_language_t::English;
		case 1: // German
			return sys_language_t::German;
		case 2: // rench
			return sys_language_t::French;
		case 3: // Spanish
			return sys_language_t::Spanish;
		case 4: // Italian
			return sys_language_t::Italian;
		case 5: // Dutch
			return sys_language_t::Dutch;
		default:
			return sys_language_t::English;
	}
}

sys_audio_mode_t ogcwrap::system::detail::encodeAM(u8 amode)
{
	switch (amode)
	{
		case 0: // Mono
			return sys_audio_mode_t::Mono;
		case 1: // Stereo
			return sys_audio_mode_t::Stereo;
		default:
			return sys_audio_mode_t::Mono;

	}
}
sys_video_mode_t ogcwrap::system::detail::encodeVM(u8 vmode)
{
	switch (vmode)
	{
		case 0: // NTSC
			return sys_video_mode_t::NTSC;
		case 1: // PAL
			return sys_video_mode_t::PAL;
		case 2: // MPAL
			return sys_video_mode_t::MPAL;
		default:
			return sys_video_mode_t::NTSC;
	}
}

u8 ogcwrap::system::detail::decodeL(sys_language_t lang)
{
	switch (lang)
	{
		case sys_language_t::English:
			return 0;
		case sys_language_t::German:
			return 1;
		case sys_language_t::French:
			return 2;
		case sys_language_t::Spanish:
			return 3;
		case sys_language_t::Italian:
			return 4;
		case sys_language_t::Dutch:
			return 5;
		default:
			return 0;
	}
}

u8 ogcwrap::system::detail::decodeAM(sys_audio_mode_t amode)
{
	switch (amode)
	{
		case sys_audio_mode_t::Mono:
			return 0;
		case sys_audio_mode_t::Stereo:
			return 1;
		default:
			return 0;
	}
}

u8 ogcwrap::system::detail::decodeVM(sys_video_mode_t vmode)
{
	switch (vmode)
	{
		case sys_video_mode_t::NTSC:
			return 0;
		case sys_video_mode_t::PAL:
			return 1;
		case sys_video_mode_t::MPAL:
			return 2;
		default:
			return 0;
	}
}