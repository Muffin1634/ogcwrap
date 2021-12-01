#pragma once
#ifndef wrap_lwp_extras_h
#define wrap_lwp_extras_h

#include <gccore.h>

namespace ogcwrap::lwp
{
	namespace thread
	{
		u32 _init(lwp_cntrl *, void *, u32, u32, u32, bool);
		u32 _start(lwp_cntrl *, void * (*)(void *), void *);
		void _exit(void *);
		void _close(lwp_cntrl *);

		void _dispatch(void);
		void _yield(void);
		void _closeAll(void);
		void _setState(lwp_cntrl *, u32);
		void _clearState(lwp_cntrl *, u32);
		void _changePriority(lwp_cntrl *, u32, u32);
		void _setPriority(lwp_cntrl *, u32);
		void _setTransient(lwp_cntrl *);
		void _suspend(lwp_cntrl *);
		void _resume(lwp_cntrl *, u32);
		void _loadEnv(lwp_cntrl *);
		void _ready(lwp_cntrl *);
		void _startMultitasking(void);
		void _stopMultitasking(void (*)(void));
		lwp_obj * _getObject(lwp_cntrl *);
		u32 _evaluateMode(void);
		void _resetTimeslice(void);
		void _tickleTimeslice(void *);
		void _delayEnded(void *);
		u32 _ISRInProgress(void);
		void _rotateReadyQueue(u32);
	}

	namespace thread_queue
	{
		void _init(lwp_thrqueue *, u32, u32, u32);
		lwp_cntrl * _first(lwp_thrqueue *);
		void _enqueue(lwp_thrqueue *, u64);
		lwp_cntrl * _dequeue(lwp_thrqueue);
		void _flush(lwp_thrqueue *, u32);
		void _extract(lwp_thrqueue *, lwp_cntrl *);

		lwp_cntrl * _firstFIFO(lwp_thrqueue *);
		void _enqueueFIFO(lwp_thrqueue *, lwp_cntrl *, u64);
		lwp_cntrl * _dequeueFIFO(lwp_thrqueue *);
		void _extractFIFO(lwp_thrqueue *, lwp_cntrl *);

		lwp_cntrl * _firstPriority(lwp_thrqueue *);
		void _enqueuePriority(lwp_thrqueue *, lwp_cntrl *, u64);
		lwp_cntrl * _dequeuePriority(lwp_thrqueue *);
		void _extractPriority(lwp_thrqueue *, lwp_cntrl *);

		u32 _extractProxy(lwp_cntrl *);
	}

	namespace heap
	{
		u32 _init(heap_cntrl *, void *, u32, u32);
		void * _alloc(heap_cntrl *, u32);
		bool _free(heap_cntrl *, void *);
		u32 _getInfo(heap_cntrl *, heap_iblock *);
	}

	namespace message_queue
	{
		u32 _init(mq_cntrl *, mq_attr *, u32, u32);
		void _close(mq_cntrl *, u32);
		u32 _seize(mq_cntrl *, u32, void *, u32 *, u32, u64);
		u32 _submit(mq_cntrl *, u32, void *, u32, u32, u32, u64);
		u32 _broadcast(mq_cntrl *, void *, u32, u32, u32 *);
		void _messageInsert(mq_cntrl *, mq_buffercntrl *, u32);
		u32 _flush(mq_cntrl *);
		u32 _flushSupport(mq_cntrl *);
		void _flushWaitThreads(mq_cntrl *);
	}

	namespace mutex
	{
		void _init(lwp_mutex *, lwp_mutex_attr *, u32);
		u32 _surrender(lwp_mutex *);
//		void _seize(lwp_mutex *, s32, u8, u32, u32); // lmao this macro's sig took a bunch of digging to find
		void _seizeIRQBlocking(lwp_mutex *, u64);
//		void _seizeIRQTryLock(lwp_mutex *, u32 *);
		void _flush(lwp_mutex *, u32);
	}

	namespace objmgr
	{
		void _initInfo(lwp_objinfo *, u32, u32);
		void _free(lwp_objinfo *, lwp_obj *);
		lwp_obj * _alloc(lwp_objinfo *);
		lwp_obj * _get(lwp_objinfo *, u32);
		lwp_obj * _getISRDisable(lwp_objinfo *, u32, u32 *);
		lwp_obj * _getNoProtection(lwp_objinfo *, u32);
	}

	namespace priority
	{
		void _init(void);
	}

	namespace queue
	{
		void _init(lwp_queue *, void *, u32, u32);
		lwp_node * _get(lwp_queue *);
		void _append(lwp_queue *, lwp_node *);
		void _extract(lwp_node *);
		void _insert(lwp_node *, lwp_node *);
	}

	namespace semaphore
	{
		void _init(lwp_sema *, lwp_semattr *, u32);
		void _surrender(lwp_sema *, u32);
		void _seize(lwp_sema *, u32, u32, u64);
		void _flush(lwp_sema *, u32);
	}

	namespace stack
	{
		u32 _alloc(lwp_cntrl *, u32);
		void _free(lwp_cntrl *);
	}

	namespace watchdog
	{
		void _init(void);
		void _setTimer(wd_cntrl *);
		void _insert(lwp_queue *, wd_cntrl *);
		u32 _remove(lwp_queue *, wd_cntrl *);
		void _tickle(lwp_queue *);
		void _adjust(lwp_queue *, u32, s64);
	}

	namespace workspace
	{
		void _init(u32);
	}
}

#endif // wrap_lwp_extras_h