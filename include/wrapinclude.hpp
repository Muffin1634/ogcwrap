#pragma once
#ifndef wrap_include_h
#define wrap_include_h

// libogc
#define HW_RVL
#include <gctypes.h>
#include <gccore.h>

// debug
#include <debug.h>

// wiiuse/wpad
#define GEKKO
#include <wiiuse/wiiuse.h>
#include <wiiuse/wpad.h>

// video

// asndlib
#include <asndlib.h>

// system

// aesndlib
#include <aesndlib.h>

// gu

// gx
#include <ogc/gx_struct.h>
#include <ogc/lwp.h>

// cache

// console

// wiilaunch

// aram/arqmgr

// irq

// macros
#define mcast(type, val)	(type)(val)

#endif // wrap_include_h