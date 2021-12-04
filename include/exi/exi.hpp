#pragma once
#ifndef wrap_exi_h
#define wrap_exi_h

#include <gctypes.h>
#include <ogc/exi.h>

#include "exi/exi_td.hpp"

namespace ogcwrap::exi
{
	// callback methods
	EXICallback registerCallback(EXIChannel chan, EXICallback cb);

	// gethods
	s32 getState(EXIChannel chan);
	bool getID(EXIChannel chan, EXIDevice dev, u32 * id);

	// probing methods
	bool probe(EXIChannel chan);
	bool probeExtended(EXIChannel chan);
	void probeReset(void);

	// locking methods
	bool lock(EXIChannel chan, EXIDevice dev, EXICallback cb);
	bool unlock(EXIChannel chan);

	// selection methods
	bool select(EXIChannel chan, EXIDevice dev, EXIFrequency freq);
	bool selectSD(EXIChannel chan, EXIDevice dev, EXIFrequency freq);
	bool deselect(EXIChannel chan);

	// memory transfer methods
	bool immediate(EXIChannel chan, void * buf, u32 bufsize, TransferMode mode, EXICallback cb);
	bool immediateExtended(EXIChannel chan, void * buf, u32 bufsize, TransferMode mode);
	bool DMA(EXIChannel chan, void * buf, u32 bufsize, TransferMode mode, EXICallback cb);
	bool sync(EXIChannel chan);

	// attachment methods
	bool attach(EXIChannel chan, EXICallback cb);
	bool detach(EXIChannel chan);
}

#endif // wrap_exi_h