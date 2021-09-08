#pragma once
#ifndef wrap_cache_h
#define wrap_cache_h

#include <gctypes.h>
#include <ogc/cache.h>

// #include "cache/cache_td.hpp"

namespace ogcwrap::cache
{
	namespace l1
	{
		namespace data
		{
			// cache management
			void enable(void);
			void disable(void);
			void freeze(void);
			void unfreeze(void);

			// invalidation methods
			void invalidateCache(void);
			void invalidateRange(void *, u32);

			// synchronized version
			void flushRange(void *, u32);
			void storeRange(void *, u32);
			void zeroRange(void *, u32);
			void touchRange(void *, u32);

			// asynchronized version
			void flushRangeAsync(void *, u32);
			void storeRangeAsync(void *, u32);
		}

		namespace instruction
		{
			// cache management
			void enable(void);
			void disable(void);
			void freeze(void);
			void unfreeze(void);

			// sync method
			void sync(void);

			// invalidation methods
			void invalidateCache(void);
			void invalidateBlock(void *);
			void invalidateRange(void *, u32);
		}
	}

	namespace l2
	{
		// library management
		void enhance(void);
		void enable(void);
		void disable(void);
		void * getBase(void);

		// block functions
		void loadBlocks(void *, void *, u32);
		void storeBlocks(void *, void *, u32);

		// data functions
		u32 loadData(void *, void *, u32);
		u32 storeData(void *, void *, u32);

		// queue functions
		u32 waitInQueue(u32);
		u32 getQueueLength(void);
		void flushQueue(void);

		// allocation functions
		void allocate(void *, u32);
		void allocateNoInvalidate(void *, u32);
		void allocateOneTag(bool, void *);
		void allocateTags(bool, void *, u32);
	}
}

#endif // wrap_cache_h