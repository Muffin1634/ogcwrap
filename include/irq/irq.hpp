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
	raw_irq_handler_t registerHandler(irq_value_t irq, raw_irq_handler_t handler, void * pCtx);
	raw_irq_handler_t freeHandler(irq_value_t irq);
	raw_irq_handler_t getHandler(irq_value_t irq);

	// mask/unmask methods
	void maskIRQ(mask_value_t mask);
	void unmaskIRQ(mask_value_t mask);
}

#endif // wrap_irq_h