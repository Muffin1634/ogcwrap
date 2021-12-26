#pragma once
#ifndef wrap_wiilaunch_h
#define wrap_wiilaunch_h

#include <gctypes.h>
#include <ogc/wiilaunch.h>

#include "wiilaunch/wiilaunch_td.hpp"

namespace ogcwrap::wiilaunch
{
	// subsystem management
	WLReturnValue init(void);

	// return functions
	WLReturnValue returnToMenu(void);
	WLReturnValue returnToSettings(void);
	WLReturnValue returnToSettingsPage(const char * page); // note 1

	// launch functions
	WLReturnValue launchTitle(u64 titleID);
//	WLReturnValue launchTitleWithArgs(u64 titleID, int launchcode, ...) // note 2
	WLReturnValue openURL(const char * url);
}

#endif // wrap_wiilaunch_h

/*  Notes
 *
 *  1. For valid arguments to returnToSettingsPage(), see lines 53-59 of <ogc/wiilaunch.h>:
 *
 *  #define SETTINGS_CALENDAR	"Calendar/Calendar_index.html"
 *  #define SETTINGS_DISPLAY	"Display/Display_index.html"
 *  #define SETTINGS_SOUND		"Sound/Sound_index.html"
 *  #define SETTINGS_PARENTAL	"Parental_Control/Parental_Control_index.html"
 *  #define SETTINGS_INTERNET	"Internet/Internet_index.html"
 *  #define SETTINGS_WC24		"WiiConnect24/Wiiconnect24_index.html"
 *  #define SETTINGS_UPDATE		"Update/Update_index.html"
 *
 *  2. Due to certain circumstances regarding variadic arguments of functions, launchTitleWithArgs() cannot be wrapped.
 *     Please use the original.
 *
 */
