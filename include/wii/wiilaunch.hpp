#pragma once
#ifndef wrap_wii_h
#define wrap_wii_h

#include <gctypes.h>
#include <ogc/wiilaunch.h>

#include "wii/wiilaunch_td.hpp"

namespace ogcwrap::wii
{
	// library management
	ReturnValue init(void);

	// return functions
	ReturnValue returnToMenu(void);
	ReturnValue returnToSettings(void);
	ReturnValue returnToSettingsPage(const char * page); // note 1

	// launch functions
	ReturnValue launchTitle(u64 titleID);
//	ReturnValue launchTitleWithArgs(u64 titleID, int launchcode, ...) // note 2
	ReturnValue openURL(const char * url);
}

#endif // wrap_wii_h

/*  notes
 *
 *  1. For valid arguments to returnToSettingsPage(), see lines 53-59 of <ogcwiilaunch.h>:
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
 *  Please use the original.
 *
 */