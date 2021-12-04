#pragma once
#ifndef wrap_aram_h
#define wrap_aram_h

#include <gctypes.h>
#include <ogc/aram.h>
#include <ogc/arqmgr.h>

// #include "aram/aram_td.hpp"

namespace ogcwrap::aram
{
	// subsystem management
	u32 init(u32 * stackIndexArray, u32 count);
	void deinit(void);
	bool checkInit(void);

	// callbacks
	ARCallback registerCallback(ARCallback cb);

	// gethods
	u32 getDMAStatus(void);
	u32 getBaseAddress(void);
	u32 getSize(void);
	u32 getInternalSize(void);

	// dma methods
	void startDMA(u32 dir, u32 mem_addr, u32 aram_addr, u32 len);
	void startDMARead(u32 mem_addr, u32 aram_addr, u32 len);
	void startDMAWrite(u32 mem_addr, u32 aram_addr, u32 len);

	// memory methods
	u32 alloc(u32 len);
	u32 free(u32 * len);
	void clear(u32 flag);

	namespace queue
	{
		// subsystem management
		void init(u32 base_addr, s32 len);

		// gethods
		u32 getZeroBuffer(void);
		u32 getStackPointer(void);
		u32 getFreeSize(void);

		// queue management methods
		u32 push(void * buf, s32 bufsize);
		void pop(void);
	}
}

#endif // wrap_aram_h