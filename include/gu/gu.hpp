#pragma once
#ifndef wrap_gu_h
#define wrap_gu_h

#include <gctypes.h>
#include <ogc/gu.h>

// #include "gu/gu_td.hpp"

namespace ogcwrap::gu
{
	// creating projection matrices (4x4)
	void perspective(Mtx44 matrix44, f32 fovY, f32 aspect, f32 near, f32 far);
	void frustum(Mtx44 matrix44, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far);
	void orthographic(Mtx44 matrix44, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far);

	// creating light projection matrices (3x4)
	void lightPerspective(Mtx matrix34, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT);
	void lightFrustum(Mtx matrix34, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 scaleS, f32 scaleT, f32 transS, f32 transT);
	void lightOrthographic(Mtx matrix34, f32 top, f32 bottom, f32 left, f32 right, f32 scaleS, f32 scaleT, f32 transS, f32 transT);

	// changing camera
	void lookAt(Mtx camera, guVector * position, guVector * upVector, guVector * target);

	// use libgxmath for math functions cause im lazy
}

#endif // wrap_gu_h