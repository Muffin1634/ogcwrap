/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
// #include "cache/cache_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

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

/*******************************************************************************
 * functions
 */

// ogcwrap::cache::l1::data

void ogcwrap::cache::l1::data::enable(void)
	{ DCEnable(); }

void ogcwrap::cache::l1::data::disable(void)
	{ DCDisable(); }

void ogcwrap::cache::l1::data::freeze(void)
	{ DCFreeze(); }

void ogcwrap::cache::l1::data::unfreeze(void)
	{ DCUnfreeze(); }

void ogcwrap::cache::l1::data::invalidateCache(void)
	{ DCFlashInvalidate(); }

void ogcwrap::cache::l1::data::invalidateRange(void * start_addr, u32 length)
	{ DCInvalidateRange(start_addr, length); }

void ogcwrap::cache::l1::data::flushRange(void * start_addr, u32 length)
	{ DCFlushRange(start_addr, length); }

void ogcwrap::cache::l1::data::storeRange(void * start_addr, u32 length)
	{ DCStoreRange(start_addr, length); }

void ogcwrap::cache::l1::data::zeroRange(void * start_addr, u32 length)
	{ DCZeroRange(start_addr, length); }

void ogcwrap::cache::l1::data::touchRange(void * start_addr, u32 length)
	{ DCTouchRange(start_addr, length); }

void ogcwrap::cache::l1::data::flushRangeAsync(void * start_addr, u32 length)
	{ DCFlushRangeNoSync(start_addr, length); }

void ogcwrap::cache::l1::data::storeRangeAsync(void * start_addr, u32 length)
	{ DCStoreRangeNoSync(start_addr, length); }

// ogcwrap::cache::l1::instruction

void ogcwrap::cache::l1::instruction::enable(void)
	{ ICEnable(); }

void ogcwrap::cache::l1::instruction::disable(void)
	{ ICDisable(); }

void ogcwrap::cache::l1::instruction::freeze(void)
	{ ICFreeze(); }

void ogcwrap::cache::l1::instruction::unfreeze(void)
	{ ICUnfreeze(); }

void ogcwrap::cache::l1::instruction::sync(void)
	{ ICSync(); }

void ogcwrap::cache::l1::instruction::invalidateCache(void)
	{ ICFlashInvalidate(); }

void ogcwrap::cache::l1::instruction::invalidateBlock(void * start_addr)
	{ ICBlockInvalidate(start_addr); }

void ogcwrap::cache::l1::instruction::invalidateRange(void * start_addr, u32 length)
	{ ICInvalidateRange(start_addr, length); }

// ogcwrap::cache::l2

void ogcwrap::cache::l2::enhance(void)
	{ L2Enhance(); }

void ogcwrap::cache::l2::enable(void)
	{ LCEnable(); }

void ogcwrap::cache::l2::disable(void)
	{ LCDisable(); }

void * ogcwrap::cache::l2::getBase(void)
	{ return ((void *)(0xe0000000)); }

void ogcwrap::cache::l2::loadBlocks(void * src_addr, void * dst_addr, u32 length)
	{ LCLoadBlocks(src_addr, dst_addr, length); }

void ogcwrap::cache::l2::storeBlocks(void * src_addr, void * dst_addr, u32 length)
	{ LCStoreBlocks(src_addr, dst_addr, length); }

u32 ogcwrap::cache::l2::loadData(void * src_addr, void * dst_addr, u32 length)
	{ return LCLoadData(src_addr, dst_addr, length); }

u32 ogcwrap::cache::l2::storeData(void * src_addr, void * dst_addr, u32 length)
	{ return LCStoreData(src_addr, dst_addr, length); }

u32 ogcwrap::cache::l2::waitInQueue(u32 length)
	{ return LCQueueWait(length); }

u32 ogcwrap::cache::l2::getQueueLength(void)
	{ return LCQueueLength(); }

void ogcwrap::cache::l2::flushQueue(void)
	{ LCFlushQueue(); }

void ogcwrap::cache::l2::allocate(void * start_addr, u32 length)
	{ LCAlloc(start_addr, length); }

void ogcwrap::cache::l2::allocateNoInvalidate(void * start_addr, u32 length)
	{ LCAllocNoInvalidate(start_addr, length); }

void ogcwrap::cache::l2::allocateOneTag(bool arg0, void * arg1) // mode?, address?
	{ LCAllocOneTag(arg0, arg1); }

void ogcwrap::cache::l2::allocateTags(bool arg0, void * arg1, u32 arg2) // mode?, address?, length?
	{ LCAllocTags(arg0, arg1, arg2); }