/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "wii/wiilaunch_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::wii
{
	// library management
	wii_return_t init(void);

	// return functions
	wii_return_t returnToMenu(void);
	wii_return_t returnToSettings(void);
	wii_return_t returnToSettingsPage(const char *);

	// launch functions
	wii_return_t launchTitle(u64);
//	wii_return_t launchTitleWithArgs(u64, int, ...);
	wii_return_t openURL(const char *);
}

/*******************************************************************************
 * functions
 */

wii_return_t ogcwrap::wii::init(void)
	{ return mcast(wii_return_t, WII_Initialize()); }

wii_return_t ogcwrap::wii::returnToMenu(void)
	{ return mcast(wii_return_t, WII_ReturnToMenu()); }

wii_return_t ogcwrap::wii::returnToSettings(void)
	{ return mcast(wii_return_t, WII_ReturnToSettings()); }

wii_return_t ogcwrap::wii::returnToSettingsPage(const char * page)
	{ return mcast(wii_return_t, WII_ReturnToSettingsPage(page)); }

wii_return_t ogcwrap::wii::launchTitle(u64 titleID)
	{ return mcast(wii_return_t, WII_LaunchTitle(titleID)); }

/*
wii_return_t ogcwrap::wii::launchTitleWithArgs()
	{}
*/

wii_return_t ogcwrap::wii::openURL(const char * url)
	{ return mcast(wii_return_t, WII_OpenURL(url)); }