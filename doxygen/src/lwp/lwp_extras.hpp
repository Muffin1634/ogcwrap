#pragma once
#ifndef wrap_lwp_extras_h
#define wrap_lwp_extras_h

#include <gctypes.h>
#include <ogc/lwp_config.h>
#include <ogc/lwp_heap.h>
#include <ogc/lwp_messages.h>
#include <ogc/lwp_mutex.h>
#include <ogc/lwp_objmgr.h>
#include <ogc/lwp_priority.h>
#include <ogc/lwp_queue.h>
#include <ogc/lwp_sema.h>
#include <ogc/lwp_stack.h>
#include <ogc/lwp_states.h>
#include <ogc/lwp_threadq.h>
#include <ogc/lwp_threads.h>
#include <ogc/lwp_tqdata.h>
#include <ogc/lwp_watchdog.h>
#include <ogc/lwp_wkspace.h>

namespace ogcwrap::lwp
{
	namespace thread
	{
		u32 _init(lwp_cntrl * thread, void * stackBase, u32 stackSize, u32 priority, u32 isrLevel, bool preemptive);
		u32 _start(lwp_cntrl * thread, void * (*entry)(void *), void * args);
		void _exit(void *);
		void _close(lwp_cntrl * thread);

		void _dispatch(void);
		void _yield(void);
		void _closeAll(void);
		void _setState(lwp_cntrl * thread, u32 state);
		void _clearState(lwp_cntrl * thread, u32 state);
		void _changePriority(lwp_cntrl * thread, u32 priority, bool prepend);
		void _setPriority(lwp_cntrl * thread, u32 priority);
		void _setTransient(lwp_cntrl * thread);
		void _suspend(lwp_cntrl * thread);
		void _resume(lwp_cntrl * thread, bool force);
		void _loadEnv(lwp_cntrl * thread);
		void _ready(lwp_cntrl * thread);
		void _startMultitasking(void);
		void _stopMultitasking(void (*exit)(void));
		lwp_obj * _getObject(lwp_cntrl * thread);
		u32 _evaluateMode(void);
		void _resetTimeslice(void);
		void _tickleTimeslice(void * arg);
		void _delayEnded(void * arg);
		u32 _ISRInProgress(void);
		void _rotateReadyQueue(u32 priority);
	}

	namespace thread_queue
	{
		void _init(lwp_thrqueue * queue, u32 mode, u32 state, u32 timeoutState);
		lwp_cntrl * _first(lwp_thrqueue * queue);
		void _enqueue(lwp_thrqueue * queue, u64 timeout);
		lwp_cntrl * _dequeue(lwp_thrqueue * queue);
		void _flush(lwp_thrqueue * queue, u32 status);
		void _extract(lwp_thrqueue * queue, lwp_cntrl * thread);

		lwp_cntrl * _firstFIFO(lwp_thrqueue * queue);
		void _enqueueFIFO(lwp_thrqueue * queue, lwp_cntrl * thread, u64 timeout);
		lwp_cntrl * _dequeueFIFO(lwp_thrqueue * queue);
		void _extractFIFO(lwp_thrqueue * queue, lwp_cntrl * thread);

		lwp_cntrl * _firstPriority(lwp_thrqueue * queue);
		void _enqueuePriority(lwp_thrqueue * queue, lwp_cntrl * thread, u64 timeout);
		lwp_cntrl * _dequeuePriority(lwp_thrqueue * queue);
		void _extractPriority(lwp_thrqueue * queue, lwp_cntrl * thread);

		u32 _extractProxy(lwp_cntrl * thread);
	}

	namespace heap
	{
		u32 _init(heap_cntrl * heap, void * start_addr, u32 heapSize, u32 pageSize);
		void * _alloc(heap_cntrl * heap, u32 size);
		bool _free(heap_cntrl * heap, void * ptr);
		u32 _getInfo(heap_cntrl * heap, heap_iblock * info);
	}

	namespace message_queue
	{
		u32 _init(mq_cntrl * queue, mq_attr * attr, u32 maxPendingMsgs, u32 maxMsgSize);
		void _close(mq_cntrl * queue, u32 status);
		u32 _seize(mq_cntrl * queue, u32 id, void * buf, u32 * size, u32 wait, u64 timeout);
		u32 _submit(mq_cntrl * queue, u32 id, void * buf, u32 size, u32 type, u32 wait, u64 timeout);
		u32 _broadcast(mq_cntrl * queue, void * buf, u32 size, u32 id, u32 * count);
		void _messageInsert(mq_cntrl * queue, mq_buffercntrl * msg, u32 type);
		u32 _flush(mq_cntrl * queue);
		u32 _flushSupport(mq_cntrl * queue);
		void _flushWaitThreads(mq_cntrl * queue);
	}

	namespace mutex
	{
		void _init(lwp_mutex * mutex, lwp_mutex_attr * attr, u32 initLock);
		u32 _surrender(lwp_mutex * mutex);
//		void _seize(lwp_mutex * mutex, s32 id, u8 wait, u32 timeout, u32 level);
		void _seizeIRQBlocking(lwp_mutex * mutex, u64 timeout);
//		void _seizeIRQTryLock(lwp_mutex * mutex, u32 * status);
		void _flush(lwp_mutex * mutex, u32 status);
	}

	namespace objmgr
	{
		void _initInfo(lwp_objinfo * info, u32 maxNodes, u32 nodeSize);
		void _free(lwp_objinfo * info, lwp_obj * object);
		lwp_obj * _alloc(lwp_objinfo * info);
		lwp_obj * _get(lwp_objinfo * info, u32 id);
		lwp_obj * _getISRDisable(lwp_objinfo * info, u32 id, u32 * p_level);
		lwp_obj * _getNoProtection(lwp_objinfo * info, u32 id);
	}

	namespace priority
	{
		void _init(void);
	}

	namespace queue
	{
		void _init(lwp_queue * queue, void * start_addr, u32 nodeCount, u32 nodeSize);
		lwp_node * _get(lwp_queue * queue);
		void _append(lwp_queue * queue, lwp_node * node);
		void _extract(lwp_node * queue);
		void _insert(lwp_node * queue, lwp_node * node);
	}

	namespace semaphore
	{
		void _init(lwp_sema * semaphore, lwp_semattr * attributes, u32 initCount);
		void _surrender(lwp_sema * semaphore, u32 initCount);
		void _seize(lwp_sema * semaphore, u32 id, u32 wait, u64 timeout);
		void _flush(lwp_sema * semaphore, u32 status);
	}

	namespace stack
	{
		u32 _alloc(lwp_cntrl * control, u32 size);
		void _free(lwp_cntrl * control);
	}

	namespace watchdog
	{
		void _init(void);
		void _setTimer(wd_cntrl * wd);
		void _insert(lwp_queue * queue, wd_cntrl * wd);
		u32 _remove(lwp_queue * queue, wd_cntrl * wd);
		void _tickle(lwp_queue * queue);
		void _adjust(lwp_queue * queue, u32 dir, s64 interval);
	}

	namespace workspace
	{
		void _init(u32 size);
	}
}

#endif // wrap_lwp_extras_h