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
}

#endif // wrap_gu_h
/*! \file gu.hpp <gu/gu.hpp>
 *  \brief Header file for the wrapper of the libOGC gu/matrix subsystem.
 *
 *  This header contains functions in the <CODE>ogcwrap::gu</CODE> namespace for creating projection matrices, light
 *  projection matrices, and for manipulating the camera.
 *
 *  \warning This wrapper of libOGC's gu subsystem does not include the math functions; use the related <CODE>gxmath</CODE>
 *           library for an update of those functions.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \namespace ogcwrap::gu
 *  \brief Namespace containing functions related to the libOGC gu/matrix subsystem.
 */

/*! \fn void ogcwrap::gu::perspective(Mtx44 matrix44, f32 fovY, f32 aspect, f32 near, f32 far)
 *  \brief Initializes a perspective-style projection matrix for use with the GX subsystem.
 *
 *  \param[out] matrix44 The destination matrix that will be created; you must allocate this first.
 *  \param[in]  fovY     The field of view, in degrees, of the YZ plane (pitch).
 *  \param[in]  aspect   The aspect ratio of the resulting view.
 *  \param[in]  near     The distance to the near clipping plane on the Z axis.
 *  \param[in]  far      The distance to the far clipping plane on the Z axis.
 *
 *  \return none; the result matrix is the first parameter.
 */

/*! \fn void ogcwrap::gu::frustum(Mtx44 matrix44, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far)
 *  \brief Initializes a frustum-style projection matrix for use with the GX subsystem.
 *
 *  \note periverbatim from libOGC: \"<I>matrix</I> negates a point's 'z' values, so pre-transformed points should have
 *                                    negative 'z' values in eye space in order to be visible after projection.\"
 *
 *  \param[out] matrix44 The destination matrix that will be created; you must allocate this first.
 *  \param[in]  top      The top    edge of the view rectangle at the near clipping plane.
 *  \param[in]  bottom   The bottom edge of the view rectangle at the near clipping plane.
 *  \param[in]  left     The left   edge of the view rectangle at the near clipping plane.
 *  \param[in]  right    The right  edge of the view rectangle at the near clipping plane.
 *  \param[in]  near     The distance to the near clipping plane on the Z axis.
 *  \param[in]  far      The distance to the far  clipping plane on the Z axis.
 *
 *  \return none; the result matrix is the first parameter.
 */

/*! \fn void ogcwrap::gu::orthographic(Mtx44 matrix44, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far)
 *  \brief Initializes a orthographic-style projection matrix for use with the GX subsystem.
 *
 *  \note periverbatim from libOGC: \"For normal parallel projections, the axis of projection is the -z axis, so \a t =
 *                                    positive, \a b = -\a t, \a r = positive, \a l = -\a r. \a n and \a f must both be
 *                                    given as positive distances.\"
 *
 *  \param[out] matrix44 The destination matrix that will be created; you must allocate this first.
 *  \param[in]  top      The top    edge of the view rectangle.
 *  \param[in]  bottom   The bottom edge of the view rectangle.
 *  \param[in]  left     The left   edge of the view rectangle.
 *  \param[in]  right    The right  edge of the view rectangle.
 *  \param[in]  near     The distance to the near clipping plane on the Z axis.
 *  \param[in]  far      The distance to the far  clipping plane on the Z axis.
 *
 *  \return none; the result matrix is the first parameter.
 */

/*! \fn void ogcwrap::gu::lightPerspective(Mtx matrix34, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT)
 *  \brief Initializes a perspective-style light matrix for use with the GX subsystem.
 *
 *  \param[out] matrix34 The destination matrix that will be created; you must allocate this first.
 *  \param[in]  fovY     The field of view, in degrees, of the YZ plane (pitch).
 *  \param[in]  aspect   The aspect ratio of the resulting view.
 *  \param[in]  scaleS   The scale       in the S direction for projected coordinates (normally 0.5).
 *  \param[in]  scaleT   The scale       in the T direction for projected coordinates (normally 0.5).
 *  \param[in]  transS   The translation in the S direction for projected coordinates (normally 0.5).
 *  \param[in]  transT   The translation in the T direction for projected coordinates (normally 0.5).
 *
 *  \return none; the result matrix is the first parameter.
 */

/*! \fn void ogcwrap::gu::lightFrustum(Mtx matrix34, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 scaleS, f32 scaleT, f32 transS, f32 transT)
 *  \brief Initializes a frustum-style light matrix for use with the GX subsystem.
 *
 *  \param[out] matrix34 The destination matrix that will be created; you must allocate this first.
 *  \param[in]  top      The top    edge of the view rectangle at the near clipping plane.
 *  \param[in]  bottom   The bottom edge of the view rectangle at the near clipping plane.
 *  \param[in]  left     The left   edge of the view rectangle at the near clipping plane.
 *  \param[in]  right    The right  edge of the view rectangle at the near clipping plane.
 *  \param[in]  near     The distance to the near clipping plane on the Z axis.
 *  \param[in]  scaleS   The scale       in the S direction for projected coordinates (normally 0.5).
 *  \param[in]  scaleT   The scale       in the T direction for projected coordinates (normally 0.5).
 *  \param[in]  transS   The translation in the S direction for projected coordinates (normally 0.5).
 *  \param[in]  transT   The translation in the T direction for projected coordinates (normally 0.5).
 *
 *  \return none; the result matrix is the first parameter.
 */

/*! \fn void ogcwrap::gu::lightOrthographic(Mtx matrix34, f32 top, f32 bottom, f32 left, f32 right, f32 scaleS, f32 scaleT, f32 transS, f32 transT)
 *  \brief Initializes a orthographic-style light matrix for use with the GX subsystem.
 *
 *  \param[out] matrix34 The destination matrix that will be created; you must allocate this first.
 *  \param[in]  top      The top    edge of the view rectangle.
 *  \param[in]  bottom   The bottom edge of the view rectangle.
 *  \param[in]  left     The left   edge of the view rectangle.
 *  \param[in]  right    The right  edge of the view rectangle.
 *  \param[in]  scaleS   The scale       in the S direction for projected coordinates (normally 0.5).
 *  \param[in]  scaleT   The scale       in the T direction for projected coordinates (normally 0.5).
 *  \param[in]  transS   The translation in the S direction for projected coordinates (normally 0.5).
 *  \param[in]  transT   The translation in the T direction for projected coordinates (normally 0.5).
 *
 *  \return none; the result matrix is the first parameter.
 */

/*! \fn void ogcwrap::gu::lookAt(Mtx camera34, guVector * position, guVector * upVector, guVector * target)
 *  \brief Resets the <CODE>camera</CODE> to be placed at <CODE>position</CODE> pointed at <CODE>target</CODE>.
 *
 *  The <CODE>upVector</CODE> parameter of the function determines the camera's roll. Normally this is (0, 1, 0) which
 *  refers to a normal upright camera. However, if you want your camera to tilt, then you can change the <CODE>upVector</CODE>.
 *
 *  \note verbatim from libOGC: \"The camera's reference viewing direction is the -z axis. The camera's reference 'up'
 *                                direction is the +y axis.\"
 *
 *  \param[out] camera34 The camera matrix to modify.
 *  \param[in]  position The camera position in world space where the camera will be.
 *  \param[in]  upVector The "up" direction of the camera; this vector affects the camera's roll.
 *  \param[in]  target   The target position in world space where the camera will be pointing.
 *
 *  \return none; the result matrix is in the first parameter.
 */