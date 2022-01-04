/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "exi/exi_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::exi
{
	// subsystem management
	// fun fact: this subsystem doesn't have any management functions! how odd

	// callback methods
	EXICallback registerCallback(exi_channel_t, EXICallback);

	// gethods
	s32 getState(exi_channel_t);
	bool getID(exi_channel_t, exi_device_t, u32 *);

	// probing methods
	bool probe(exi_channel_t);
	bool probeExtended(exi_channel_t);
	void probeReset(void);

	// locking methods
	bool lock(exi_channel_t, exi_device_t, EXICallback);
	bool unlock(exi_channel_t);

	// selection methods
	bool select(exi_channel_t, exi_device_t, exi_frequency_t);
	bool selectSD(exi_channel_t, exi_device_t, exi_frequency_t);
	bool deselect(exi_channel_t);

	// memory transfer methods
	bool immediate(exi_channel_t, void *, u32, exi_transfer_mode_t, EXICallback);
	bool immediateExtended(exi_channel_t, void *, u32, exi_transfer_mode_t);
	bool DMA(exi_channel_t, void *, u32, exi_transfer_mode_t, EXICallback);
	bool sync(exi_channel_t);

	// attachment methods
	bool attach(exi_channel_t, EXICallback);
	bool detach(exi_channel_t);
}

/*******************************************************************************
 * functions
 */

EXICallback ogcwrap::exi::registerCallback(exi_channel_t chan, EXICallback cb)
	{ return EXI_RegisterEXICallback(static_cast<s32>(chan), cb); }

s32 ogcwrap::exi::getState(exi_channel_t chan)
	{ return EXI_GetState(static_cast<s32>(chan)); }

bool ogcwrap::exi::getID(exi_channel_t chan, exi_device_t dev, u32 * id)
	{ return EXI_GetID(static_cast<s32>(chan), static_cast<s32>(dev), id); }

bool ogcwrap::exi::probe(exi_channel_t chan)
	{ return EXI_Probe(static_cast<s32>(chan)); }

bool ogcwrap::exi::probeExtended(exi_channel_t chan)
	{ return EXI_ProbeEx(static_cast<s32>(chan)); }

void ogcwrap::exi::probeReset(void)
	{ EXI_ProbeReset(); }

bool ogcwrap::exi::lock(exi_channel_t chan, exi_device_t dev, EXICallback cb)
	{ return EXI_Lock(static_cast<s32>(chan), static_cast<s32>(dev), cb); }

bool ogcwrap::exi::unlock(exi_channel_t chan)
	{ return EXI_Unlock(static_cast<s32>(chan)); }

bool ogcwrap::exi::select(exi_channel_t chan, exi_device_t dev, exi_frequency_t freq)
	{ return EXI_Select(static_cast<s32>(chan), static_cast<s32>(dev), static_cast<s32>(freq)); }

bool ogcwrap::exi::selectSD(exi_channel_t chan, exi_device_t dev, exi_frequency_t freq)
	{ return EXI_SelectSD(static_cast<s32>(chan), static_cast<s32>(dev), static_cast<s32>(freq)); }

bool ogcwrap::exi::deselect(exi_channel_t chan)
	{ return EXI_Deselect(static_cast<s32>(chan)); }

bool ogcwrap::exi::immediate(exi_channel_t chan, void * buf, u32 bufsize, exi_transfer_mode_t mode, EXICallback cb)
	{ return EXI_Imm(static_cast<s32>(chan), buf, bufsize, static_cast<u32>(mode), cb); }

bool ogcwrap::exi::immediateExtended(exi_channel_t chan, void * buf, u32 bufsize, exi_transfer_mode_t mode)
	{ return EXI_ImmEx(static_cast<s32>(chan), buf, bufsize, static_cast<u32>(mode)); }

bool ogcwrap::exi::DMA(exi_channel_t chan, void * buf, u32 bufsize, exi_transfer_mode_t mode, EXICallback cb)
	{ return EXI_Dma(static_cast<s32>(chan), buf, bufsize, static_cast<u32>(mode), cb); }

bool ogcwrap::exi::sync(exi_channel_t chan)
	{ return EXI_Sync(static_cast<s32>(chan)); }

bool ogcwrap::exi::attach(exi_channel_t chan, EXICallback cb)
	{ return EXI_Attach(static_cast<s32>(chan), cb); }

bool ogcwrap::exi::detach(exi_channel_t chan)
	{ return EXI_Detach(static_cast<s32>(chan)); }