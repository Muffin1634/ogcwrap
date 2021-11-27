#pragma once
#ifndef wrap_dsp_h
#define wrap_dsp_h

#include <gctypes.h>
#include <ogc/dsp.h>

// #include "dsp/dsp_td.hpp"

namespace ogcwrap::dsp
{
	// subsystem management
	void init(void);
	void reset(void);
	void halt(void);
	void unhalt(void);

	// callback methods
	DSPCallback registerCallback(DSPCallback cb);

	// gethods
	u32 getDMAStatus(void);

	// methods
	void assertInterrupt(void);

	// task methods
	dsptask_t * addTask(dsptask_t * task);
	dsptask_t * assertTask(dsptask_t * task);
	void cancelTask(dsptask_t * task);

	// mail methods
	bool checkIncomingMail(void);
	bool checkOutgoingMail(void);

	u32 readIncomingMail(void);
	u32 readOutgoingMail(void);

	void sendMail(u32 mail);
}

#endif // wrap_dsp_h