/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "dvd/dvd_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::dvd
{
	// subsystem management
	void init(void);
	void reset(drive_reset_mode_t);
	void pause(void);

	// gethods
	s32 getDriveStatus(void);
	s32 getCommandBlockStatus(dvdcmdblk *);
	dvddiskid * getCurrentDiskID(void);
	dvddrvinfo * getDriveInfo(void);
	void * getUserData(dvdcmdblk *);

	s32 readDiskID(dvdcmdblk *, dvddiskid *, dvdcbcallback);

	// sethods
	u32 setAutoInvalidation(u32);
	void setUserData(dvdcmdblk *, void *);

	// mounting methods
	s32 mount(void);
	s32 mountAsync(dvdcmdblk *, dvdcbcallback);

	// drive control methods
	s32 controlDrive(dvdcmdblk *, drive_control_mode_t);
	s32 controlDriveAsync(dvdcmdblk *, drive_control_mode_t, dvdcbcallback);

	// sync methods
	s32 spinUp(dvdcmdblk *);
	s32 inquiry(dvdcmdblk *, dvddrvinfo *);
	s32 readPriority(dvdcmdblk *, void *, u32, s64, s32);
	s32 seekPriority(dvdcmdblk *, s64, s32);
	s32 setGCMOffset(dvdcmdblk *, s64);
	s32 stopStreamAtEnd(dvdcmdblk *);

	// async methods
	s32 spinUpAsync(dvdcmdblk *, dvdcbcallback);
	s32 inquiryAsync(dvdcmdblk *, dvddrvinfo *, dvdcbcallback);
	s32 readAbsAsyncPriority(dvdcmdblk *, void *, u32, s64, dvdcbcallback, s32);
	s32 readAbsAsyncForBS(dvdcmdblk *, void *, u32, s64, dvdcbcallback);
	s32 seekAbsAsyncPriority(dvdcmdblk *, s64, dvdcbcallback, s32);
	s32 setGCMOffsetAsync(dvdcmdblk *, s64, dvdcbcallback);
	s32 stopStreamAtEndAsync(dvdcmdblk *, dvdcbcallback);

	s32 cancelAllAsyncCalls(dvdcbcallback);
}

/*******************************************************************************
 * functions
 */

void ogcwrap::dvd::init(void)
	{ DVD_Init(); }

void ogcwrap::dvd::reset(drive_reset_mode_t mode)
	{ DVD_Reset(mcast(u32, mode)); }

void ogcwrap::dvd::pause(void)
	{ DVD_Pause(); }

s32 ogcwrap::dvd::getDriveStatus(void)
	{ return DVD_GetDriveStatus(); }

s32 ogcwrap::dvd::getCommandBlockStatus(dvdcmdblk * block)
	{ return DVD_GetCmdBlockStatus(block); }

dvddiskid * ogcwrap::dvd::getCurrentDiskID(void)
	{ return DVD_GetCurrentDiskID(); }

dvddrvinfo * ogcwrap::dvd::getDriveInfo(void)
	{ return DVD_GetDriveInfo(); }

void * ogcwrap::dvd::getUserData(dvdcmdblk * block)
	{ return block->usrdata; }

s32 ogcwrap::dvd::readDiskID(dvdcmdblk * block, dvddiskid * id, dvdcbcallback cb)
	{ return DVD_ReadDiskID(block, id, cb); }

u32 ogcwrap::dvd::setAutoInvalidation(u32 autoInv)
	{ return DVD_SetAutoInvalidation(autoInv); }

void ogcwrap::dvd::setUserData(dvdcmdblk * block, void * data)
	{ block->usrdata = data; }

s32 ogcwrap::dvd::mount(void)
	{ return DVD_Mount(); }

s32 ogcwrap::dvd::mountAsync(dvdcmdblk * block, dvdcbcallback cb)
	{ return DVD_MountAsync(block, cb); }

s32 ogcwrap::dvd::controlDrive(dvdcmdblk * block, drive_control_mode_t mode)
	{ return DVD_ControlDrive(block, mcast(u32, mode)); }

s32 ogcwrap::dvd::controlDriveAsync(dvdcmdblk * block, drive_control_mode_t mode, dvdcbcallback cb)
	{ return DVD_ControlDriveAsync(block, mcast(u32, mode), cb); }

s32 ogcwrap::dvd::spinUp(dvdcmdblk * block)
	{ return DVD_SpinUpDrive(block); }

s32 ogcwrap::dvd::inquiry(dvdcmdblk * block, dvddrvinfo * info)
	{ return DVD_Inquiry(block, info); }

s32 ogcwrap::dvd::readPriority(dvdcmdblk * block, void * buf, u32 bufsize, s64 offset, s32 priority)
	{ return DVD_ReadPrio(block, buf, bufsize, offset, priority); }

s32 ogcwrap::dvd::seekPriority(dvdcmdblk * block, s64 offset, s32 priority)
	{ return DVD_SeekPrio(block, offset, priority); }

s32 ogcwrap::dvd::setGCMOffset(dvdcmdblk * block, s64 offset)
	{ return DVD_SetGCMOffset(block, offset); }

s32 ogcwrap::dvd::stopStreamAtEnd(dvdcmdblk * block)
	{ return DVD_StopStreamAtEnd(block); }

s32 ogcwrap::dvd::spinUpAsync(dvdcmdblk * block, dvdcbcallback cb)
	{ return DVD_SpinUpDriveAsync(block, cb); }

s32 ogcwrap::dvd::inquiryAsync(dvdcmdblk * block, dvddrvinfo * info, dvdcbcallback cb)
	{ return DVD_InquiryAsync(block, info, cb); }

s32 ogcwrap::dvd::readAbsAsyncPriority(dvdcmdblk * block, void * buf, u32 bufsize, s64 offset, dvdcbcallback cb, s32 priority)
	{ return DVD_ReadAbsAsyncPrio(block, buf, bufsize, offset, cb, priority); }

s32 ogcwrap::dvd::readAbsAsyncForBS(dvdcmdblk * block, void * buf, u32 bufsize, s64 offset, dvdcbcallback cb)
	{ return DVD_ReadAbsAsyncForBS(block, buf, bufsize, offset, cb); }

s32 ogcwrap::dvd::seekAbsAsyncPriority(dvdcmdblk * block, s64 offset, dvdcbcallback cb, s32 priority)
	{ return DVD_SeekAbsAsyncPrio(block, offset, cb, priority); }

s32 ogcwrap::dvd::setGCMOffsetAsync(dvdcmdblk * block, s64 offset, dvdcbcallback cb)
	{ return DVD_SetGCMOffsetAsync(block, offset, cb); }

s32 ogcwrap::dvd::stopStreamAtEndAsync(dvdcmdblk * block, dvdcbcallback cb)
	{ return DVD_StopStreamAtEndAsync(block, cb); }

s32 ogcwrap::dvd::cancelAllAsyncCalls(dvdcbcallback cb)
	{ return DVD_CancelAllAsync(cb); }