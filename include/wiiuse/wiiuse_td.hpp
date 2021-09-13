#pragma once
#ifndef wrap_wiiuse_td_h
#define wrap_wiiuse_td_h

namespace ogcwrap::wiiuse
{
	typedef enum struct wiiuse_aspect_t
	{
		Aspect4by3,
		Aspect16by9
	} ScreenAspectRatio;

	typedef enum struct wiiuse_ir_position_t
	{
		AboveTV,
		BelowTV
	} IRBarPosition;
}

#endif // wrap_wiiuse_td_h