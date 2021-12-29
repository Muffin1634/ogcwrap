/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "wiilaunch/wiilaunch_td.hpp"

using ogcwrap::wiilaunch::wii_return_value_t;

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::wiilaunch
{
	// subsystem management
	wii_return_value_t init(void);

	// return functions
	wii_return_value_t returnToMenu(void);
	wii_return_value_t returnToSettings(void);
	wii_return_value_t returnToSettingsPage(const char *);

	// launch functions
	wii_return_value_t launchTitle(u64);
//	wii_return_value_t launchTitleWithArgs(u64, int, ...);
	wii_return_value_t openURL(const char *);
}

/*******************************************************************************
 * functions
 */

wii_return_value_t ogcwrap::wiilaunch::init(void)
	{ return static_cast<wii_return_value_t>(WII_Initialize()); }

wii_return_value_t ogcwrap::wiilaunch::returnToMenu(void)
	{ return static_cast<wii_return_value_t>(WII_ReturnToMenu()); }

wii_return_value_t ogcwrap::wiilaunch::returnToSettings(void)
	{ return static_cast<wii_return_value_t>(WII_ReturnToSettings()); }

wii_return_value_t ogcwrap::wiilaunch::returnToSettingsPage(const char * page)
	{ return static_cast<wii_return_value_t>(WII_ReturnToSettingsPage(page)); }

wii_return_value_t ogcwrap::wiilaunch::launchTitle(u64 titleID)
	{ return static_cast<wii_return_value_t>(WII_LaunchTitle(titleID)); }

/*
wii_return_value_t ogcwrap::wiilaunch::launchTitleWithArgs()
	{}
*/

wii_return_value_t ogcwrap::wiilaunch::openURL(const char * url)
	{ return static_cast<wii_return_value_t>(WII_OpenURL(url)); }