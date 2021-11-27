#pragma once
#ifndef libwrap_h
#define libwrap_h

#ifndef HW_RVL
#define HW_RVL // for everything
#endif

#ifndef GEKKO
#define GEKKO // for wiiuse
#endif

// #include "debug/debug.hpp"
#include "wpad/wpad.hpp"
#include "wiiuse/wiiuse.hpp"
#include "video/video.hpp"
#include "asnd/asnd.hpp"
#include "system/system.hpp"
#include "aesnd/aesnd.hpp"
#include "gu/gu.hpp"
#include "gx/gx.hpp"
#include "cache/cache.hpp"
#include "console/console.hpp"
#include "wiilaunch/wiilaunch.hpp"
#include "aram/aram.hpp"
#include "irq/irq.hpp"
#include "exi/exi.hpp"
#include "dvd/dvd.hpp"
#include "card/card.hpp"
#include "dsp/dsp.hpp"
#include "ios/ios.hpp"

#endif // libwrap_h