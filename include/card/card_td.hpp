#pragma once
#ifndef wrap_card_td_h
#define wrap_card_td_h

namespace ogcwrap::card
{
	typedef enum struct card_return_value_t : s32
	{
		Unlocked	=    1,
		Ready		=    0,
		Busy		=   -1,
		WrongDevice	=   -2,
		NoCard		=   -3,
		NoFile		=   -4,
		IOError		=   -5,
		Broken		=   -6,
		Exists		=   -7,
		NoEnt		=   -8,
		InsSpace	=   -9,
		NoPerm		=  -10,
		Limit		=  -11,
		NameTooLong	=  -12,
		Encoding	=  -13,
		Canceled	=  -14,
		FATAL_ERROR	= -128
	} CardReturnValue;

	typedef enum struct banner_format_t
	{
		None,
		CI,
		RGB,

		Mask
	} BannerFormat;

	typedef enum struct icon_format_t : u16
	{
		None,
		CI,
		RGB,

		Mask
	} IconFormat;

	typedef enum struct icon_speed_t : u16
	{
		End,
		Slow	= 3,
		Middle	= 2,
		Fast	= 1,

		Mask	= 3
	} IconSpeed;
}

#endif // wrap_card_td_h