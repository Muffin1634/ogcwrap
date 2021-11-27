#pragma once
#ifndef wrap_ios_h
#define wrap_ios_h

#include <gctypes.h>
#include <ogc/ios.h>

#include "ios/ios_td.hpp"

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

#endif // wrap_ios_h

/*  Notes
 *
 *  1. _init() and _deinit() are for managing the important subsystems in an IOS like ES and STM, not an actual
 *     subsystem for managing IOSes. These functions are only meant to be called when loading and unloading an IOS,
 *     respectively.
 *
 *  2. _load() actually just returns 0 don't use it. TODO: add deprecated tag in Doxygen when writing it
 *
 */