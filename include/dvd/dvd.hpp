#pragma once
#ifndef wrap_dvd_h
#define wrap_dvd_h

#include <gctypes.h>
#include <ogc/dvd.h>

#include "dvd/dvd_td.hpp"

namespace ogcwrap::dvd
{
	// subsystem management
	void init(void);
	void reset(DriveResetMode mode);
	void pause(void);

	// gethods
	s32 getDriveStatus(void);
	s32 getCommandBlockStatus(dvdcmdblk * block);
	dvddiskid * getCurrentDiskID(void);
	dvddrvinfo * getDriveInfo(void);
	void * getUserData(dvdcmdblk * block);

	s32 readDiskID(dvdcmdblk * block, dvddiskid * id, dvdcbcallback cb);

	// sethods
	u32 setAutoInvalidation(u32 autoInv);
	void setUserData(dvdcmdblk * block, void * data);

	// mounting methods
	s32 mount(void);
	s32 mountAsync(dvdcmdblk * block, dvdcbcallback cb);

	// drive control methods
	s32 controlDrive(dvdcmdblk * block, DriveControlMode mode);
	s32 controlDriveAsync(dvdcmdblk * block, DriveControlMode mode, dvdcbcallback cb);

	// sync methods
	s32 spinUp(dvdcmdblk * block);
	s32 inquiry(dvdcmdblk * block, dvddrvinfo * info);
	s32 readPriority(dvdcmdblk * block, void * buf, u32 bufsize, s64 offset, s32 priority);
	s32 seekPriority(dvdcmdblk * block, s64 offset, s32 priority);
	s32 setGCMOffset(dvdcmdblk * block, s64 offset);
	s32 stopStreamAtEnd(dvdcmdblk * block);

	// async methods
	s32 spinUpAsync(dvdcmdblk * block, dvdcbcallback cb);
	s32 inquiryAsync(dvdcmdblk * block, dvddrvinfo * info, dvdcbcallback cb);
	s32 readAbsAsyncPriority(dvdcmdblk * block, void * buf, u32 bufsize, s64 offset, dvdcbcallback cb, s32 priority);
	s32 readAbsAsyncForBS(dvdcmdblk * block, void * buf, u32 bufsize, s64 offset, dvdcbcallback cb);
	s32 seekAbsAsyncPriority(dvdcmdblk * block, s64 offset, dvdcbcallback cb, s32 priority);
	s32 setGCMOffsetAsync(dvdcmdblk * block, s64 offset, dvdcbcallback cb);
	s32 stopStreamAtEndAsync(dvdcmdblk * block, dvdcbcallback cb);

	s32 cancelAllAsyncCalls(dvdcbcallback cb);
}

#endif // wrap_dvd_h