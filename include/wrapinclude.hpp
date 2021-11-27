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

// exi

// card
#include <ogc/exi.h>

// dsp

// ios
#include <ogc/ios.h>

// lwp
#include <ogc/lwp.h>
#include <ogc/lwp_config.h>
#include <ogc/lwp_heap.h>
#include <ogc/lwp_messages.h>
#include <ogc/lwp_mutex.h>
#include <ogc/lwp_objmgr.h>
#include <ogc/lwp_priority.h>
#include <ogc/lwp_queue.h>
#include <ogc/lwp_sema.h>
#include <ogc/lwp_stack.h>
#include <ogc/lwp_states.h>
#include <ogc/lwp_threadq.h>
#include <ogc/lwp_threads.h>
#include <ogc/lwp_tqdata.h>
#include <ogc/lwp_watchdog.h>
#include <ogc/lwp_wkspace.h>
#include <ogc/message.h>
#include <ogc/mutex.h>
#include <ogc/semaphore.h>

// macros
#define mcast(type, val)	((type)(val))

#endif // wrap_include_h