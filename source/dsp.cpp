/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
// #include "dsp/dsp_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::dsp
{
	// subsystem management
	void init(void);
	void reset(void);
	void halt(void);
	void unhalt(void);

	// callback methods
	DSPCallback registerCallback(DSPCallback);

	// gethods
	u32 getDMAStatus(void);

	// methods
	void assertInterrupt(void);

	// task methods
	dsptask_t * addTask(dsptask_t *);
	dsptask_t * assertTask(dsptask_t *);
	void cancelTask(dsptask_t *);

	// mail methods
	bool checkIncomingMail(void);
	bool checkOutgoingMail(void);

	u32 readIncomingMail(void);
	u32 readOutgoingMail(void);

	void sendMail(u32);
}

/*******************************************************************************
 * functions
 */

void ogcwrap::dsp::init(void)
	{ DSP_Init(); }

void ogcwrap::dsp::reset(void)
	{ DSP_Reset(); }

void ogcwrap::dsp::halt(void)
	{ DSP_Halt(); }

void ogcwrap::dsp::unhalt(void)
	{ DSP_Unhalt(); }

DSPCallback ogcwrap::dsp::registerCallback(DSPCallback cb)
	{ return DSP_RegisterCallback(cb); }

u32 ogcwrap::dsp::getDMAStatus(void)
	{ return DSP_GetDMAStatus(); }

void ogcwrap::dsp::assertInterrupt(void)
	{ DSP_AssertInt(); }

dsptask_t * ogcwrap::dsp::addTask(dsptask_t * task)
	{ return DSP_AddTask(task); }

dsptask_t * ogcwrap::dsp::assertTask(dsptask_t * task)
	{ return DSP_AssertTask(task); }

void ogcwrap::dsp::cancelTask(dsptask_t * task)
	{ DSP_CancelTask(task); }

bool ogcwrap::dsp::checkIncomingMail(void)
	{ return DSP_CheckMailTo(); }

bool ogcwrap::dsp::checkOutgoingMail(void)
	{ return DSP_CheckMailFrom(); }

u32 ogcwrap::dsp::readIncomingMail(void)
	{ return DSP_ReadCPUtoDSP(); }

u32 ogcwrap::dsp::readOutgoingMail(void)
	{ return DSP_ReadMailFrom(); }

void ogcwrap::dsp::sendMail(u32 mail)
	{ DSP_SendMailTo(mail); }