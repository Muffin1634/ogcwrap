/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "irq/irq_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::irq
{
	// subsystem management
	u32 disable(void);
	void restore(u32);

	// handler methods
	raw_irq_handler_t registerHandler(irq_value_t, raw_irq_handler_t, void *);
	raw_irq_handler_t freeHandler(irq_value_t);
	raw_irq_handler_t getHandler(irq_value_t);

	// (un)masking methods
	void maskIRQ(mask_value_t);
	void unmaskIRQ(mask_value_t);
}

/*******************************************************************************
 * functions
 */

u32 ogcwrap::irq::disable(void)
	{ return IRQ_Disable(); }

void ogcwrap::irq::restore(u32 level)
	{ IRQ_Restore(level); }

raw_irq_handler_t ogcwrap::irq::registerHandler(irq_value_t irq, raw_irq_handler_t handler, void * pCtx)
	{ return IRQ_Request(mcast(u32, irq), handler, pCtx); }

raw_irq_handler_t ogcwrap::irq::freeHandler(irq_value_t irq)
	{ return IRQ_Free(mcast(u32, irq)); }

raw_irq_handler_t ogcwrap::irq::getHandler(irq_value_t irq)
	{ return IRQ_GetHandler(mcast(u32, irq)); }

void ogcwrap::irq::maskIRQ(mask_value_t mask)
	{ __MaskIrq(mcast(u32, mask)); }

void ogcwrap::irq::unmaskIRQ(mask_value_t mask)
	{ __UnmaskIrq(mcast(u32, mask)); }