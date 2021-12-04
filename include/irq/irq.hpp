#pragma once
#ifndef wrap_irq_h
#define wrap_irq_h

#include <gctypes.h>
#include <ogc/irq.h>

#include "irq/irq_td.hpp"

namespace ogcwrap::irq
{
	// subsystem management
	u32 disable(void);
	void restore(u32 level);

	// handler methods
	raw_irq_handler_t registerHandler(IRQValue irq, raw_irq_handler_t handler, void * pCtx);
	raw_irq_handler_t freeHandler(IRQValue irq);
	raw_irq_handler_t getHandler(IRQValue irq);

	// mask/unmask methods
	void maskIRQ(IRQMask mask);
	void unmaskIRQ(IRQMask mask);
}

#endif // wrap_irq_h