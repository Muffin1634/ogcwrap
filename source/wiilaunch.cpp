/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "wiilaunch/wiilaunch_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::wiilaunch
{
	// subsystem management
	wii_ret_vals_t init(void);

	// return functions
	wii_ret_vals_t returnToMenu(void);
	wii_ret_vals_t returnToSettings(void);
	wii_ret_vals_t returnToSettingsPage(const char *);

	// launch functions
	wii_ret_vals_t launchTitle(u64);
//	wii_ret_vals_t launchTitleWithArgs(u64, int, ...);
	wii_ret_vals_t openURL(const char *);
}

/*******************************************************************************
 * functions
 */

using ogcwrap::wiilaunch::wii_ret_vals_t;

wii_ret_vals_t ogcwrap::wiilaunch::init(void)
	{ return mcast(wii_ret_vals_t, WII_Initialize()); }

wii_ret_vals_t ogcwrap::wiilaunch::returnToMenu(void)
	{ return mcast(wii_ret_vals_t, WII_ReturnToMenu()); }

wii_ret_vals_t ogcwrap::wiilaunch::returnToSettings(void)
	{ return mcast(wii_ret_vals_t, WII_ReturnToSettings()); }

wii_ret_vals_t ogcwrap::wiilaunch::returnToSettingsPage(const char * page)
	{ return mcast(wii_ret_vals_t, WII_ReturnToSettingsPage(page)); }

wii_ret_vals_t ogcwrap::wiilaunch::launchTitle(u64 titleID)
	{ return mcast(wii_ret_vals_t, WII_LaunchTitle(titleID)); }

/*
wii_ret_vals_t ogcwrap::wiilaunch::launchTitleWithArgs()
	{}
*/

wii_ret_vals_t ogcwrap::wiilaunch::openURL(const char * url)
	{ return mcast(wii_ret_vals_t, WII_OpenURL(url)); }