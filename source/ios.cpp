/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
#include "ios/ios_td.hpp"

using ogcwrap::ios::ios_return_value_t;

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::ios
{
	// subsystem management
	ios_return_value_t _init(void);
	ios_return_value_t _deinit(void);

	// IOS management
	ios_return_value_t _loadStartupIOS(void);
	ios_return_value_t _launchNewIOS(int version);

	ios_return_value_t getPreferredIOS(void);
	ios_return_value_t reloadIOS(int version);

	// version management
	s32 getVersion(void);
	s32 getRevision(void);
	s32 getMajorRevision(void);
	s32 getMinorRevision(void);
}

/*******************************************************************************
 * functions
 */

ios_return_value_t ogcwrap::ios::_init(void)
	{ return static_cast<ios_return_value_t>(__IOS_InitializeSubsystems()); }

ios_return_value_t ogcwrap::ios::_deinit(void)
	{ return static_cast<ios_return_value_t>(__IOS_ShutdownSubsystems()); }

ios_return_value_t ogcwrap::ios::_loadStartupIOS(void)
	{ return static_cast<ios_return_value_t>(0); }

ios_return_value_t ogcwrap::ios::_launchNewIOS(int version)
	{ return static_cast<ios_return_value_t>(__IOS_LaunchNewIOS(version)); }

ios_return_value_t getPreferredIOS(void)
	{ return static_cast<ios_return_value_t>(IOS_GetPreferredVersion()); }

ios_return_value_t reloadIOS(int version)
	{ return static_cast<ios_return_value_t>(IOS_ReloadIOS(version)); }

s32 getVersion(void)
	{ return IOS_GetVersion(); }

s32 getRevision(void)
	{ return IOS_GetRevision(); }

s32 getMajorRevision(void)
	{ return IOS_GetRevisionMajor(); }

s32 getMinorRevision(void)
	{ return IOS_GetRevisionMinor(); }