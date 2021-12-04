#pragma once
#ifndef wrap_ios_td_h
#define wrap_ios_td_h

namespace ogcwrap::ios
{
	typedef enum struct ios_return_value_t
	{
		OK,

		Invalid			= -0x3004,
		BadVersion		= -0x3100,
		TooManyViews	= -0x3101,
		Mismatch		= -0x3102
	} IOSReturnValue;
}

using ogcwrap::ios::IOSReturnValue;

#endif // wrap_ios_td_h