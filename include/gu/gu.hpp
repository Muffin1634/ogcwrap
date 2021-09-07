#pragma once
#ifndef wrap_gu_h
#define wrap_gu_h

//\cond

#include <gctypes.h>
#include <ogc/gu.h>

// #include "gu/gu_td.hpp"

//\endcond

namespace ogcwrap::gu
{
	// creating projection matrices (4x4)
	void perspective(Mtx44 matrix, f32 fovY, f32 aspect, f32 near, f32 far);
	void frustum(Mtx44 matrix, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far);
	void orthographic(Mtx44 matrix, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far);

	// creating light projection matrices (3x4)
	void lightPerspective(Mtx matrix, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT);
	void lightFrustum(Mtx, f32, f32, f32, f32, f32, f32, f32, f32, f32);
	void lightOrthographic(Mtx, f32, f32, f32, f32, f32, f32, f32, f32);

	// changing camera
	void lookAt(Mtx, guVector *, guVector *, guVector *);

	// use libgxmath for math functions cause im lazy
}

#endif // wrap_gu_h
/*! \file gu.hpp <gu/gu.hpp>
 *  \brief Header file for the gu/matrix subsystem.
 *
 *  This header contains functions in the <CODE>ogcwrap::gu</CODE> namespace for creating projection matrices, light
 *  projection matrices, and for manipulating the camera.
 *
 *  \warning This wrapper of libOGC's gu subsystem does not include the math functions; use the related <CODE>gxmath</CODE>
 *           library for an update of those functions.
 *
 *  <!--
 *  	there is intentionally no line between the endif and this block. this is to remove that newline from the
 *  	resulting source code that is generated. otherwise it looks weird. i am not going to be the person making it
 *  	look weird.
 *  -->
 */

/*! \fn void ogcwrap::gu::perspective(Mtx44 matrix, f32 fovY, f32 aspect, f32 near, f32 far)
 *  \brief Initializes a perspective-style projection matrix for use with the GX subsystem.
 *
 *  \note periverbatim from libOGC: \"<I>matrix</I> negates a point's 'z' values, so pre-transformed points should have
 *                                     negative 'z' values in eye space in order to be visible after projection.\"
 *
 *  \param[out] matrix The destination matrix that will be created; you must allocate this first.
 *  \param[in]  fovY   The field of view, in degrees, of the YZ plane (pitch).
 *  \param[in]  aspect The aspect ratio of the resulting view.
 *  \param[in]  near   The distance to the near clipping plane on the Z axis.
 *  \param[in]  far    The distance to the far clipping plane on the Z axis.
 *
 *  \return none; the result matrix is the first parameter.
 */

/*! \fn void ogcwrap::gu::frustum(Mtx44 matrix, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far)
 *  \brief Initializes a frustum-style projection matrix for use with the GX subsystem.
 *
 *  \note periverbatim from libOGC: \"<I>matrix</I> negates a point's 'z' values, so pre-transformed points should have
 *                                    negative 'z' values in eye space in order to be visible after projection.\"
 *
 *  \param[out] matrix The destination matrix that will be created; you must allocate this first.
 *  \param[in]  top    The top    edge of the view rectangle at the near clipping plane.
 *  \param[in]  bottom The bottom edge of the view rectangle at the near clipping plane.
 *  \param[in]  left   The left   edge of the view rectangle at the near clipping plane.
 *  \param[in]  right  The right  edge of the view rectangle at the near clipping plane.
 *  \param[in]  near   The distance to the near clipping plane on the Z axis.
 *  \param[in]  far    The distance to the far  clipping plane on the Z axis.
 *
 *  \return none; the result matrix is the first parameter.
 */

/*! \fn void ogcwrap::gu::orthographic(Mtx44 matrix, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far)
 *  \brief Initializes a orthographic-style projection matrix for use with the GX subsystem.
 *
 *  \note periverbatim from libOGC: \"For normal parallel projections, the axis of projection is the -z axis, so \a t =
 *                                    positive, \a b = -\a t, \a r = positive, \a l = -\a r. \a n and \a f must both be
 *                                    given as positive distances.\"
 *
 *  \param[out] matrix The destination matrix that will be created; you must allocate this first.
 *  \param[in]  top    The top    edge of the view rectangle.
 *  \param[in]  bottom The bottom edge of the view rectangle.
 *  \param[in]  left   The left   edge of the view rectangle.
 *  \param[in]  right  The right  edge of the view rectangle.
 *  \param[in]  near   The distance to the near clipping plane on the Z axis.
 *  \param[in]  far    The distance to the far  clipping plane on the Z axis.
 *
 *  \return none; the result matrix is the first parameter.
 */

/*! \fn void ogcwrap::gu::lightPerspective(Mtx matrix, f32 fovY, f32 aspect, f32 scaleS, f32 scaleT, f32 transS, f32 transT)
 *  \brief Initializes a perspective-style projection matrix for use with the GX subsystem.
 *
 *  \note periverbatim from libOGC: \"<I>matrix</I> negates a point's 'z' values, so pre-transformed points should have
 *                                     negative 'z' values in eye space in order to be visible after projection.\"
 *
 *  \param[out] matrix The destination matrix that will be created; you must allocate this first.
 *  \param[in]  fovY   The field of view, in degrees, of the YZ plane (pitch).
 *  \param[in]  aspect The aspect ratio of the resulting view.
 *  \param[in]  scaleS The distance to the near clipping plane on the Z axis.
 *  \param[in]  scaleT The distance to the far clipping plane on the Z axis.
 *  \param[in]  transS a
 *  \param[in]  transT b
 *
 *  \return none; the result matrix is the first parameter.
 */

/*! \fn void ogcwrap::gu::lightFrustum(Mtx matrix, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far)
 *  \brief Initializes a frustum-style projection matrix for use with the GX subsystem.
 *
 *  \note periverbatim from libOGC: \"<I>matrix</I> negates a point's 'z' values, so pre-transformed points should have
 *                                    negative 'z' values in eye space in order to be visible after projection.\"
 *
 *  \param[out] matrix The destination matrix that will be created; you must allocate this first.
 *  \param[in]  top    The top    edge of the view rectangle at the near clipping plane.
 *  \param[in]  bottom The bottom edge of the view rectangle at the near clipping plane.
 *  \param[in]  left   The left   edge of the view rectangle at the near clipping plane.
 *  \param[in]  right  The right  edge of the view rectangle at the near clipping plane.
 *  \param[in]  near   The distance to the near clipping plane on the Z axis.
 *  \param[in]  far    The distance to the far  clipping plane on the Z axis.
 *
 *  \return none; the result matrix is the first parameter.
 */

/*! \fn void ogcwrap::gu::lightOrthographic(Mtx matrix, f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far)
 *  \brief Initializes a orthographic-style projection matrix for use with the GX subsystem.
 *
 *  \note periverbatim from libOGC: \"For normal parallel projections, the axis of projection is the -z axis, so \a t =
 *                                    positive, \a b = -\a t, \a r = positive, \a l = -\a r. \a n and \a f must both be
 *                                    given as positive distances.\"
 *
 *  \param[out] matrix The destination matrix that will be created; you must allocate this first.
 *  \param[in]  top    The top    edge of the view rectangle.
 *  \param[in]  bottom The bottom edge of the view rectangle.
 *  \param[in]  left   The left   edge of the view rectangle.
 *  \param[in]  right  The right  edge of the view rectangle.
 *  \param[in]  near   The distance to the near clipping plane on the Z axis.
 *  \param[in]  far    The distance to the far  clipping plane on the Z axis.
 *
 *  \return none; the result matrix is the first parameter.
 */