/*******************************************************************************
 * prereqs
 */

#include "wrapinclude.hpp"
// #include "lwp/lwp_td.hpp"

/*******************************************************************************
 * function forward declarations
 */

namespace ogcwrap::lwp
{
	namespace thread
	{
		// thread management
		s32 create(lwp_t *, void * (*)(void *), void *, void *, u32, u8);
		s32 suspend(lwp_t);
		s32 resume(lwp_t);
		bool isSuspended(lwp_t);
		lwp_t getSelf(void);
		void setPriority(lwp_t, u8);
		void yield(void);
		void reschedule(u8);
		s32 join(lwp_t, void * *);

		// backend methods
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
		lwp_obj* getObject(lwp_cntrl *);
		u32 _evaluateMode(void);
		void _resetTimeslice(void);
		void _tickleTimeslice(void *);
		void _delayEnded(void *);
		u32 _ISRInProgress(void);
		void _rotateReadyQueue(u32);
	}

	namespace thread_queue
	{
		// thread queue management
		s32 init(lwpq_t *);
		void close(lwpq_t);

		s32 threadSleep(lwpq_t);
		void threadSignal(lwpq_t);
		void threadBroadcast(lwpq_t);

		// backend methods
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

	namespace condition
	{
		s32 init(cond_t *);
		s32 wait(cond_t, mutex_t);
		s32 timedWait(cond_t, mutex_t, const struct timespec *);
		s32 signal(cond_t);
		s32 broadcast(cond_t);
		s32 destroy(cond_t);
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
		s32 init(mqbox_t *, u32);
		void close(mqbox_t);
		bool send(mqbox_t, mqmsg_t, u32);
		bool jam(mqbox_t, mqmsg_t, u32);
		bool receive(mqbox_t, mqmsg_t *, u32);

		// backend methods
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
		s32 init(mutex_t *, bool);
		s32 destroy(mutex_t);
		s32 lock(mutex_t);
		s32 tryLock(mutex_t);
		s32 unlock(mutex_t);

		// backend methods
		void _init(lwp_mutex *, lwp_mutex_attr *, u32);
		u32 _surrender(lwp_mutex *);
		void _seize(lwp_mutex *, s32, u8, u32, u32); // lmao this macro's sig took a bunch of digging to find
		void _seizeIRQBlocking(lwp_mutex *, u64);
		void _seizeIRQTryLock(lwp_mutex *, u32 *);
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
		s32 init(sem_t *, u32, u32);
		s32 destroy(sem_t);
		s32 wait(sem_t);
		s32 getValue(sem_t, u32 *);
		s32 post(sem_t);

		// backend methods
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

/*******************************************************************************
 * functions
 */

// lwp::thread functions

s32 ogcwrap::lwp::thread::create(
	lwp_t *	thread,
	void *	(*entry)(void *),
	void *	arg,
	void *	stackbase,
	u32		stacksize,
	u8		priority)
{
	return LWP_CreateThread(
		thread,
		entry,
		arg,
		stackbase,
		stacksize,
		priority);
}

s32 ogcwrap::lwp::thread::suspend(lwp_t thread)
	{ return LWP_SuspendThread(thread); }

s32 ogcwrap::lwp::thread::resule(lwp_t thread)
	{ return LWP_ResumeThread(thread); }

bool ogcwrap::lwp::thread::isSuspended(lwp_t thread)
	{ return (LWP_ThreadIsSuspended(thread) == 1 ? true : false); }

lwp_t ogcwrap::lwp::thread::getSelf(void)
	{ return LWP_GetSelf(); }

void ogcwrap::lwp::thread::setPriority(lwp_t thread, u8 priority)
	{ LWP_SetPriority(thread, mcast(u32, priority)); }

void ogcwrap::lwp::thread::yield(void)
	{ LWP_YieldThread(); }

void ogcwrap::lwp::thread::reschedule(u8 priority)
	{ LWP_Reschedule(mcast(u32, priority)); }

s32 ogcwrap::lwp::thread::join(lwp_t thread, void * * return_value)
	{ return LWP_JoinThread(thread, return_value); }


// lwp::thread_queue functions

s32 ogcwrap::lwp::thread_queue::init(lwpq_t * queue)
	{ return LWP_InitQueue(queue); }

void ogcwrap::lwp::thread_queue::close(lwpq_t queue)
	{ LWP_CloseQueue(queue); }

s32 ogcwrap::lwp::thread_queue::threadSleep(lwpq_t queue)
	{ return LWP_ThreadSleep(queue); }

void ogcwrap::lwp::thread_queue::threadSignal(lwpq_t queue)
	{ LWP_ThreadSignal(queue); }

void ogcwrap::lwp::thread_queue::threadBroadcast(lwpq_t queue)
	{ LWP_ThreadBroadcast(queue); }