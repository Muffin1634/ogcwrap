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
			void invalidateRange(void * start_addr, u32 length);

			// synchronized version
			void flushRange(void * start_addr, u32 length);
			void storeRange(void * start_addr, u32 length);
			void zeroRange(void * start_addr, u32 length);
			void touchRange(void * start_addr, u32 length);

			// asynchronized version
			void flushRangeAsync(void * start_addr, u32 length);
			void storeRangeAsync(void * start_addr, u32 length);
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
			void invalidateBlock(void * start_addr);
			void invalidateRange(void * start_addr, u32 length);
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
		void loadBlocks(void * src_addr, void * dst_addr, u32 length);
		void storeBlocks(void * src_addr, void * dst_addr, u32 length);

		// data functions
		u32 length loadData(void * src_addr, void * dst_addr, u32 length);
		u32 length storeData(void * src_addr, void * dst_addr, u32 length);

		// queue functions
		u32 length waitInQueue(u32 length);
		u32 length getQueueLength(void);
		void flushQueue(void);

		// allocation functions
		void allocate(void * start_addr, u32 length);
		void allocateNoInvalidate(void * start_addr, u32 length);
		void allocateOneTag(bool arg0, void * arg1);
		void allocateTags(bool arg0, void * arg, u32 arg2);
	}
}

#endif // wrap_cache_h