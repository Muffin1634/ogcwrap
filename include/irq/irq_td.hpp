#pragma once
#ifndef wrap_irq_td_h
#define wrap_irq_td_h

namespace ogcwrap::irq
{
	typedef enum struct irq_value_t
	{
		// memory-related IRQ values
		Mem0,
		Mem1,
		Mem2,
		Mem3,
		MemAddress,

		// DSP-related IRQ values
		DSP_AI,
		ARAM,
		DSP,

		// unsure; audio interrupt?
		AI,

		// EXI interface IRQ values
		Exi0_Exi,
		Exi0_TC,
		Exi0_Ext,

		Exi1_Exi,
		Exi1_TC,
		Exi1_Ext,

		Exi2_Exi,
		Exi2_TC,

		// PI(?) IRQ values
		PI_CP,
		PI_PEToken,
		PI_PEFinish,
		PI_SI,
		PI_DI,
		PI_RSW,
		PI_Error,
		PI_VI,
		PI_Debug,
		PI_HSP,
		PI_ACR,

		MaxIRQValue = 32
	} IRQValue;

	typedef enum struct mask_value_t : u32
	{
		Mem0		= 0x80000000,
		Mem1		= 0x40000000,
		Mem2		= 0x20000000,
		Mem3		= 0x10000000,
		MemAddress	= 0x08000000,
		Memory		= 0xF8000000,

		DSP_AI		= 0x04000000,
		DSP_ARAM	= 0x02000000,
		DSP_DSP		= 0x01000000,
		DSP			= 0x07000000,

		AI			= 0x00800000,

		Exi0_Exi	= 0x00400000,
		Exi0_TC		= 0x00200000,
		Exi0_Ext	= 0x00100000,
		Exi0		= 0x00700000,

		Exi1_Exi	= 0x00080000,
		Exi1_TC		= 0x00040000,
		Exi1_Ext	= 0x00020000,
		Exi1		= 0x000E0000,

		Exi2_Exi	= 0x00010000,
		Exi2_TC		= 0x00008000,
		Exi2		= 0x00018000,
		Exi			= 0x007F8000,

		PI_CP		= 0x00004000,
		PI_PEToken	= 0x00002000,
		PI_PEFinish	= 0x00001000,
		PI_SI		= 0x00000800,
		PI_DI		= 0x00000400,
		PI_RSW		= 0x00000200,
		PI_Error	= 0x00000100,
		PI_VI		= 0x00000080,
		PI_Debug	= 0x00000040,
		PI_HSP		= 0x00000020,
		PI_ACR		= 0x00000010,
		PI			= 0x00007FF0
	} MaskValue;
}

#endif // wrap_irq_td_h