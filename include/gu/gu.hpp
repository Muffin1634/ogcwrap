#pragma once
#ifndef wrap_gu_h
#define wrap_gu_h

#include <gctypes.h>
#include <ogc/gu.h>

// #include "gu/gu_td.hpp"

namespace ogcwrap
{
	namespace gu
	{
		// creating projection matrices (4x4)
		void perspective(Mtx44, f32, f32, f32, f32);
		void frustum(Mtx44, f32, f32, f32, f32, f32, f32);
		void ortho(Mtx44, f32, f32, f32, f32, f32, f32);

		// creating light projection matrices (3x4)
		void lightPerspective(Mtx, f32, f32, f32, f32, f32, f32);
		void lightFrustum(Mtx, f32, f32, f32, f32, f32, f32, f32, f32, f32);
		void lightOrtho(Mtx, f32, f32, f32, f32, f32, f32, f32, f32);

		// changing camera
		void lookAt(Mtx, guVector *, guVector *, guVector *);

		// use libgxmath for math functions cause im lazy
	}
}

#endif // wrap_gu_h