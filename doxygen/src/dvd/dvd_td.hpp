#pragma once
#ifndef wrap_dvd_td_h
#define wrap_dvd_td_h

namespace ogcwrap::dvd
{
	typedef enum struct drive_reset_mode_t
	{
		HardReset,
		SoftReset,
		NoReset
	} DriveResetMode;

	typedef enum struct drive_control_mode_t
	{
		SpinDown	= (1 <<  0),
		SpinUp		= (1 <<  8),
		AcceptDisk	= (1 << 18),
		CheckDisk	= (1 << 19)
	} DriveControlMode;
}

#endif // wrap_dvd_td_h