/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::aram
{
	// subsystem management
	u32 init(u32 *, u32);
	void deinit(void);
	bool checkInit(void);

	// callbacks
	ARCallback registerCallback(ARCallback);

	// gethods
	u32 getDMAStatus(void);
	u32 getBaseAddress(void);
	u32 getSize(void);
	u32 getInternalSize(void);

	// dma methods
	void startDMA(u32, u32, u32, u32);
	void startDMARead(u32, u32, u32);
	void startDMAWrite(u32, u32, u32);

	// memory methods
	u32 alloc(u32);
	u32 free(u32 *);
	void clear(u32);

	namespace queue
	{
		// subsystem management
		u32 init(u32, s32);

		// gethods
		u32 getZeroBuffer(void);
		u32 getStackPointer(void);
		u32 getFreeSize(void);

		// queue management methods
		u32 push(void *, s32);
		void pop(void);
	}
}

/*******************************************************************************
 * functions
 */

u32 ogcwrap::aram::init(u32 * stackIndexArray, u32 count)
	{ return AR_Init(stackIndexArray, count); }

void ogcwrap::aram::deinit(void)
	{ AR_Reset(); }

bool ogcwrap::aram::checkInit(void)
	{ return mcast(bool, AR_CheckInit()); }
	// original implementation uses BOOL from
	// <gcbool.h>, which is a typedef of int

ARCallback ogcwrap::aram::registerCallback(ARCallback cb)
	{ return AR_RegisterCallback(cb); }

u32 ogcwrap::aram::getDMAStatus(void)
	{ return AR_GetDMAStatus(); }

u32 ogcwrap::aram::getBaseAddress(void)
	{ return AR_GetBaseAddress(); }

u32 ogcwrap::aram::getSize(void)
	{ return AR_GetSize(); }

u32 ogcwrap::aram::getInternalSize(void)
	{ return AR_GetSize(); }

void ogcwrap::aram::startDMA(u32 dir, u32 mem_addr, u32 aram_addr, u32 len)
	{ AR_StartDMA(dir, mem_addr, aram_addr, len); }

void ogcwrap::aram::startDMARead(u32 mem_addr, u32 aram_addr, u32 len)
	{ AR_StartDMA(1, mem_addr, aram_addr, len); }

void ogcwrap::aram::startDMAWrite(u32 mem_addr, u32 aram_addr, u32 len)
	{ AR_StartDMA(0, mem_addr, aram_addr, len); }

u32 ogcwrap::aram::alloc(u32 len)
	{ return AR_Alloc(len); }

u32 ogcwrap::aram::free(u32 * len)
	{ return AR_Free(len); }

void ogcwrap::aram::clear(u32 flag)
	{ AR_Clear(flag); }

// namespace ogcwrap::aram::queue

u32 ogcwrap::aram::queue::init(u32 buf, s32 len)
	{ return ARQM_Init(buf, len); }

u32 ogcwrap::aram::queue::getZeroBuffer(void)
	{ return ARQM_GetZeroBuffer(); }

u32 ogcwrap::aram::queue::getStackPointer(void)
	{ return ARQM_GetStackPointer(); }

u32 ogcwrap::aram::queue::getFreeSize(void)
	{ return ARQM_GetFreeSize(); }

u32 ogcwrap::aram::queue::push(void * buf, s32 bufsize)
	{ return ARQM_PushData(buf, bufsize); }

void ogcwrap::aram::queue::pop(void)
	{ ARQM_Pop(); }