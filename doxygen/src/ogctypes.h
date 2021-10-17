#pragma once
#ifndef ogctypes_h
#define ogctypes_h

// fundamental

typedef void void;
typedef bool bool;

// integers

typedef unsigned char				u8;
typedef unsigned short				u16;
typedef unsigned int				u32;
typedef unsigned long				u64;

typedef signed char					s8;
typedef signed short				s16;
typedef signed int					s32;
typedef signed long					s64;

typedef volatile unsigned char		vu8;
typedef volatile unsigned short		vu16;
typedef volatile unsigned int		vu32;
typedef volatile unsigned long		vu64;

typedef volatile signed char		vs8;
typedef volatile signed short		vs16;
typedef volatile signed int			vs32;
typedef volatile signed long		vs64;

// floating point

typedef float						f32;
typedef double						f64;

typedef volatile float				vf32;
typedef volatile double				vf64;

// fixed point

typedef u16							ufp16;
typedef u32							ufp32;
typedef s16							sfp16;
typedef s32							sfp32;

#endif ogctypes_h
/*! \file ogctypes.h
 *  \brief Header file containing typedefs from the original libOGC.
 *
 *  \note This header file does not actually exist; do not go looking for it. These typedefs are already provided in
 *        libOGC. This documentation is provided to explain more of libOGC.
 */

/*! \typedef void void
 *  \brief as a return type, no return, or as a pointer type, a generic pointer
 *
 *  \typedef bool bool
 *  \brief boolean that can hold a value of <CODE>true</CODE> or <CODE>false</CODE>
 */

/*! \typedef unsigned char u8
 *  \brief unsigned  8 bit integer
 *
 *  \typedef unsigned short u16
 *  \brief unsigned 16 bit integer
 *
 *  \typedef unsigned int u32
 *  \brief unsigned 32 bit integer
 *
 *  \typedef unsigned long u64
 *  \brief unsigned 64 bit integer
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \typedef signed char s8
 *  \brief signed  8 bit integer
 *
 *  \typedef signed short s16
 *  \brief signed 16 bit integer
 *
 *  \typedef signed int s32
 *  \brief signed 32 bit integer
 *
 *  \typedef signed long s64
 *  \brief signed 64 bit integer
 *
 *  <!-- --> <!-- -------------------------------------------------------------------------------------------------- -->
 *
 *  \typedef volatile unsigned char vu8
 *  \brief volatile unsigned  8 bit integer
 *
 *  \typedef volatile unsigned short vu16
 *  \brief volatile unsigned 16 bit integer
 *
 *  \typedef volatile unsigned int vu32
 *  \brief volatile unsigned 32 bit integer
 *
 *  \typedef volatile unsigned long vu64
 *  \brief volatile unsigned 64 bit integer
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \typedef volatile signed char vs8
 *  \brief volatile signed  8 bit integer
 *
 *  \typedef volatile signed short vs16
 *  \brief volatile signed 16 bit integer
 *
 *  \typedef volatile signed int vs32
 *  \brief volatile signed 32 bit integer
 *
 *  \typedef volatile signed long vs64
 *  \brief volatile signed 64 bit integer
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \typedef float f32
 *  \brief 32 bit IEEE-754 single-precision floating-point
 *
 *  This type is a IEEE-754 single-precision floating point number. It allocates the highest bit for the sign, the next
 *  8 bits for the exponent, and the low 23 bits for the mantissa. As such, it has 24 bits of precision, because the
 *  highest bit of the mantissa will always be 1 in binary, so it is not explicitly stored.
 *
 *  \typedef double f64
 *  \brief 64 bit IEEE-754 double-precision floating-point
 *
 *  This type is a IEEE-754 double-precision floating point number. It allocates the highest bit for the sign, the next
 *  12 bits for the exponent, and the low 52 bits for the mantissa. As such, it has 53 bits of precision, because the
 *  highest bit of the mantissa will always be 1 in binary, so it is not explicitly stored.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \typedef volatile float vf32
 *  \brief volatile 32 bit IEEE-754 single-precision floating-point
 *
 *  \typedef volatile double vf64
 *  \brief volatile 64 bit IEEE-754 double-precision floating-point
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \typedef u16 ufp16
 *  \brief unsigned 8:8 fixed-point
 *
 *  This type is two bytes wide (16 bits). It allocates the high 8 bits for the integral part of the number, and the low
 *  8 bits for the fractional part of the number.
 *
 *  \typedef u32 ufp32
 *  \brief unsigned 24:8 fixed point
 *
 *  This type is four bytes wide (32 bits). It allocates the high 24 bits for the integral part of the number, and the
 *  low 8 bits for the fractional part of the number.
 *
 *  \typedef s16 sfp16
 *  \brief signed 7:8 fixed point
 *
 *  This type is two bytes wide (16 bits). It allocates the highest bit for the sign, the next 7 bits for the integral
 *  part of the number, and the low 8 bits for the fractional part of the number.
 *
 *  \note I am not certain about this definition of <CODE>sfp16</CODE>; the original documentation simply states
 *        \"signed 8:8 fixed point\" and nothing further.
 *
 *  \typedef s32 sfp32
 *  \brief signed 23:8 fixed point
 *
 *  This type is four bytes wide (32 bits). It allocates the highest bit for the sign, the next 23 bits for the integral
 *  part of the number, and the low 8 bits for the fractional part of the number.
 *
 *  \note I am not certain about this definition of <CODE>sfp32</CODE>; the original documentation simply states
 *        \"signed 20:8 fixed point\" and nothing further.
 */