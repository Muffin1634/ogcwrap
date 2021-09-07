/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::gu
{
	// creating projection matrices (4x4)
	void perspective(Mtx44, f32, f32, f32, f32);
	void frustum(Mtx44, f32, f32, f32, f32, f32, f32);
	void orthographic(Mtx44, f32, f32, f32, f32, f32, f32);

	// creating light projection matrices (3x4)
	void lightPerspective(Mtx, f32, f32, f32, f32, f32, f32);
	void lightFrustum(Mtx, f32, f32, f32, f32, f32, f32, f32, f32, f32);
	void lightOrthographic(Mtx, f32, f32, f32, f32, f32, f32, f32, f32);

	// changing camera
	void lookAt(Mtx, guVector *, guVector *, guVector *);
}

/*******************************************************************************
 * functions
 */

void ogcwrap::gu::perspective(Mtx44 mtx44, f32 fovY, f32 aspect, f32 near, f32 far)
	{ guPerspective(mtx44, fovY, aspect, near, far); }

void ogcwrap::gu::frustum(Mtx44 mtx44, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far)
	{ guFrustum(mtx44, top, bottom, left, right, near, far); }

void ogcwrap::gu::orthographic(Mtx44 mtx44, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far)
	{ guOrtho(mtx44, top, bottom, left, right, near, far); }

void ogcwrap::gu::lightPerspective(Mtx mtx34, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT)
	{ guLightPerspective(mtx34, fovY, aspect, scaleS, scaleT, transS, transT); }

void ogcwrap::gu::lightFrustum(Mtx mtx34, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 scaleS, f32 scaleT, f32 transS, f32 transT)
	{ guLightFrustum(mtx34, top, bottom, left, right, near, scaleS, scaleT, transS, transT); }

void ogcwrap::gu::lightOrthographic(Mtx mtx34, f32 top, f32 bottom, f32 left, f32 right, f32 scaleS, f32 scaleT, f32 transS, f32 transT)
	{ guLightOrtho(mtx34, top, bottom, left, right, scaleS, scaleT, transS, transT); }

void ogcwrap::gu::lookAt(Mtx mtx34, guVector * cameraPosition, guVector * cameraUpVector, guVector * cameraTarget)
	{ guLookAt(mtx34, cameraPosition, cameraUpVector, cameraTarget); }