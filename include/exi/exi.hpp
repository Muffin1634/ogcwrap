#pragma once
#ifndef wrap_exi_h
#define wrap_exi_h

#include <gctypes.h>
#include <ogc/exi.h>

#include "exi/exi_td.hpp"

namespace ogcwrap::exi
{
	// callback methods
	EXICallback registerCallback(exi_channel_t chan, EXICallback cb);

	// gethods
	s32 getState(exi_channel_t chan);
	bool getID(exi_channel_t chan, exi_device_t dev, u32 * id);

	// probing methods
	bool probe(exi_channel_t chan);
	bool probeExtended(exi_channel_t chan);
	void probeReset(void);

	// locking methods
	bool lock(exi_channel_t chan, exi_device_t dev, EXICallback cb);
	bool unlock(exi_channel_t chan);

	// selection methods
	bool select(exi_channel_t chan, exi_device_t dev, exi_frequency_t freq);
	bool selectSD(exi_channel_t chan, exi_device_t dev, exi_frequency_t freq);
	bool deselect(exi_channel_t chan);

	// memory transfer methods
	bool immediate(exi_channel_t chan, void * buf, u32 bufsize, exi_transfer_mode_t mode, EXICallback cb);
	bool immediateExtended(exi_channel_t chan, void * buf, u32 bufsize, exi_transfer_mode_t mode);
	bool DMA(exi_channel_t chan, void * buf, u32 bufsize, exi_transfer_mode_t mode, EXICallback cb);
	bool sync(exi_channel_t chan);

	// attachment methods
	bool attach(exi_channel_t chan, EXICallback cb);
	bool detach(exi_channel_t chan);
}

#endif // wrap_exi_h