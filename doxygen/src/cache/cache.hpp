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
		u32 loadData(void * src_addr, void * dst_addr, u32 length);
		u32 storeData(void * src_addr, void * dst_addr, u32 length);

		// queue functions
		u32 waitInQueue(u32 length);
		u32 getQueueLength(void);
		void flushQueue(void);

		// allocation functions
		void allocate(void * start_addr, u32 length);
		void allocateNoInvalidate(void * start_addr, u32 length);
		void allocateOneTag(bool arg0, void * arg1);
		void allocateTags(bool arg0, void * arg, u32 arg2);
	}
}

#endif // wrap_cache_h
/*! \file cache.hpp <cache/cache.hpp>
 *  \brief Header file for the wrapper of the caching subsystem.
 *
 *  This header contains functions in the <CODE>ogcwrap::cache</CODE> namespace for initializing the cache subsystem,
 *  and managing the L1 and L2 caches.
 *
 *  <!-- ----------------------------------------------------------------------------------------------------------- -->
 *
 *  \namespace ogcwrap::cache
 *  \brief Namespace containing functions related to the cache subsystem in libOGC.
 *
 *  \namespace ogcwrap::cache::l1
 *  \brief Namespace containing functions related to the L1 cache.
 *
 *  \namespace ogcwrap::cache::l1::data
 *  \brief Namespace containing functions related to the L1 data cache.
 *
 *  \warning All <CODE>start_addr</CODE> arguments in this namespace <B>MUST be aligned on a 32-byte boundary</B>, and
 *           all <CODE>length</CODE> arguments in this namespace <B>MUST be a multiple of 32</B>, unless otherwise
 *           specified.
 */

/*! \fn void ogcwrap::cache::l1::data::enable(void)
 *  \brief Enables the L1 data cache.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::data::disable(void)
 *  \brief Disables the L1 data cache.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::data::freeze(void)
 *  \brief Freezes the data in the L1 data cache. Any cache hits here will still be served, but new data will not be fetched for this cache.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::data::unfreeze(void)
 *  \brief Unfreezes the data in the L1 data cache, allowing new data to be stored in the cache.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::data::invalidateCache(void)
 *  \brief Marks all of the data contained inside of the L1 data cache as invalidated, but doesn't write new data.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::data::invalidateRange(void * start_addr, u32 length)
 *  \brief Marks all of the data in the specified range of memory as invalidated when hit.
 *
 *  \param[in] start_addr Starting address of the range to be invalidated.
 *  \param[in] length     Length of the range to be invalidated.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::data::flushRange(void * start_addr, u32 length)
 *  \brief Flushes the data in the specified range to memory and marks it as invalidated when hit.
 *
 *  \param[in] start_addr Starting address of the range to be flushed.
 *  \param[in] length     Length of the range to be flushed.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::data::storeRange(void * start_addr, u32 length)
 *  \brief Stores the data in the specified range of memory in the cache whenever it is updated.
 *
 *  \param[in] start_addr Starting address of the range to be stored.
 *  \param[in] length     Length of the range to be stored.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::data::zeroRange(void * start_addr, u32 length)
 *  \brief Stores the data in the specified range of memory in the cache and zeroes the range(?)
 *
 *  \param[in] start_addr Starting address of the range to be zeroed.
 *  \param[in] length     Length of the range to be zeroed.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::data::touchRange(void * start_addr, u32 length)
 *  \brief Stores the data in the specified range of memory in the cache one time.
 *
 *  \param[in] start_addr Starting address of the range to be touched.
 *  \param[in] length     Length of the range to be touched.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::data::flushRangeAsync(void * start_addr, u32 length)
 *  \brief Flushes the data in the specified range to memory and marks it as invalidated when hit.
 *
 *  \details This function is asynchronous. It is not guaranteed that the range will be flushed to memory by the time
 *           this function returns, and there is no callback to run when finished.
 *
 *  \param[in] start_addr Starting address of the range to be flushed.
 *  \param[in] length     Length of the range to be flushed.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::data::storeRangeAsync(void * start_addr, u32 length)
 *  \brief Stores the data in the specified range of memory in the cache whenever it is updated.
 *
 *  \details This function is asynchronous. It is not guaranteed that the range will be flushed to memory by the time
 *           this function returns, and there is no callback to run when finished.
 *
 *  \param[in] start_addr Starting address of the range to be stored.
 *  \param[in] length     Length of the range to be stored.
 *
 *  \return none
 */

/*! \namespace ogcwrap::cache::l1::instruction
 *  \brief Namespace containing functions related to the L1 instruction cache.
 *
 *  \warning All <CODE>start_addr</CODE> arguments in this namespace <B>MUST be aligned on a 32-byte boundary</B>, and
 *           all <CODE>length</CODE> arguments in this namespace <B>MUST be a multiple of 32</B>, unless otherwise
 *           specified.
 */

/*! \fn void ogcwrap::cache::l1::instruction::enable(void)
 *  \brief Enables the L1 instruction cache.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::instruction::disable(void)
 *  \brief Disables the L1 instruction cache.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::instruction::freeze(void)
 *  \brief Freezes the instruction data in the L1 instruction cache. Any cache hits here will still be served, but new instruction data will not be fetched for this cache.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::instruction::unfreeze(void)
 *  \brief Unfreezes the instruction data in the L1 instruction cache, allowing new instruction data to be stored in the cache.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::instruction::sync(void)
 *  \brief Ensures that all of the instructions before this instruction in the instruction cache finishes before this instruction finishes.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::instruction::invalidateCache(void)
 *  \brief Marks all of the instruction data contained inside of the L1 instruction cache as invalidated, but doesn't write new instruction data.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::instruction::invalidateBlock(void * start_addr)
 *  \brief Marks all of the instruction data in the specified block of memory as invalidated when hit.
 *
 *  \param[in] start_addr Starting address of the block to be invalidated.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l1::instruction::invalidateRange(void * start_addr, u32 length)
 *  \brief Marks all of the instruction data in the specified range of memory as invalidated when hit.
 *
 *  \param[in] start_addr Starting address of the range to be invalidated.
 *  \param[in] length     Length of the range to be invalidated.
 *
 *  \return none
 */

/*! \namespace ogcwrap::cache::l2
 *  \brief Namespace containing functions related to the L2 cache.
 *
 *  \warning All <CODE>start_addr</CODE>, <CODE>src_addr</CODE> and <CODE>dst_addr</CODE> arguments in this namespace
 *           <B>MUST be aligned on a 32-byte boundary</B>, and all <CODE>length</CODE> arguments in this namespace
 *           <B>MUST be a multiple of 32</B>, unless otherwise specified.
 */

/*! \fn void ogcwrap::cache::l2::enhance(void)
 *  \brief Enhances the ablilties of the L2 cache(?)
 *
 *  \note This function is only available for Wiis (the macro <CODE>HW_RVL</CODE> is defined). This function is not
 *        available for GameCubes.
 */

/*! \fn void ogcwrap::cache::l2::enable(void)
 *  \brief Enables the L2 cache.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l2::disable(void)
 *  \brief Disables the L2 cache.
 *
 *  \return none
 */

/*! \fn void * ogcwrap::cache::l2::getBase(void)
 *  \brief Gets the base address of the L2 cache.
 *
 *  \return <CODE>void *</CODE> to the beginning address of the L2 cache.
 */

/*! \fn void ogcwrap::cache::l2::loadBlocks(void * src_addr, void * dst_addr, u32 length)
 *  \brief loadBlocks
 *
 *  \param[in] src_addr Source address.
 *  \param[in] dst_addr Destination address.
 *  \param[in] length   Length of the blocks.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l2::storeBlocks(void * src_addr, void * dst_addr, u32 length)
 *  \brief storeBlocks
 *
 *  \param[in] src_addr Source address.
 *  \param[in] dst_addr Destination address.
 *  \param[in] length   Length of the blocks.
 *
 *  \return none
 */

/*! \fn u32 ogcwrap::cache::l2::loadData(void * src_addr, void * dst_addr, u32 length)
 *  \brief loadData
 *
 *  \param[in] src_addr Source address.
 *  \param[in] dst_addr Destination address.
 *  \param[in] length   Length of the data.
 *
 *  \return loadDataReturn
 */

/*! \fn u32 ogcwrap::cache::l2::storeData(void * src_addr, void * dst_addr, u32 length)
 *  \brief storeData
 *
 *  \param[in] src_addr Source address.
 *  \param[in] dst_addr Destination address.
 *  \param[in] length   Length of the data.
 *
 *  \return storeDataReturn
 */

/*! \fn u32 ogcwrap::cache::l2::waitInQueue(u32 length)
 *  \brief waitInQueue
 *
 *  \param[in] length     Length of ?
 *
 *  \return waitInQueueReturn
 */

/*! \fn u32 ogcwrap::cache::l2::getQueueLength(void)
 *  \brief Gets the length of the cache queue.
 *
 *  \return The length of the cache queue.
 */

/*! \fn void ogcwrap::cache::l2::flushQueue(void)
 *  \brief Flushes the cache queue. (to what?)
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l2::allocate(void * start_addr, u32 length)
 *  \brief Allocates a new buffer of (?)
 *
 *  \param[in] start_addr Starting address of the buffer to be allocated.
 *  \param[in] length     Length of the buffer.
 *
 *  \return none
 */

/*! \fn void ogcwrap::cache::l2::allocateNoInvalidate(void * start_addr, u32 length)
 *  \brief Allocates a new buffer of (?) without invalidating (?)
 *
 *  \param[in] start_addr Starting address.
 *  \param[in] length     Length of the buffer.
 *
 *  \return none
 */

/*! \fn u32 ogcwrap::cache::l2::allocateOneTag(bool arg0, void * arg1)
 *  \brief allocateOneTag
 *
 *  \param[in] arg0 ???
 *  \param[in] arg1 ???
 *
 *  \return none
 */

/*! \fn u32 ogcwrap::cache::l2::allocateTags(bool arg0, void * arg1, u32 arg2)
 *  \brief allocateTags
 *
 *  \param[in] arg0 ???
 *  \param[in] arg1 ???
 *  \param[in] arg2 ???
 *
 *  \return none
 */