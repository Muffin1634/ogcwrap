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
		void setPriority(lwp_t, u32);
		void yield(void);
		void reschedule(u32);
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
		void _changePriority(lwp_cntrl *, u32, bool);
		void _setPriority(lwp_cntrl *, u32);
		void _setTransient(lwp_cntrl *);
		void _suspend(lwp_cntrl *);
		void _resume(lwp_cntrl *, bool);
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
		lwp_cntrl * _dequeue(lwp_thrqueue *);
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
		s32 destroy(cond_t);
		s32 wait(cond_t, mutex_t);
		s32 timedWait(cond_t, mutex_t, const struct timespec *);
		s32 signal(cond_t);
		s32 broadcast(cond_t);
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
	void *	args,
	void *	stackBase,
	u32		stackSize,
	u8		priority)
{
	return LWP_CreateThread(
		thread,
		entry,
		args,
		stackBase,
		stackSize,
		priority);
}

s32 ogcwrap::lwp::thread::suspend(lwp_t thread)
	{ return LWP_SuspendThread(thread); }

s32 ogcwrap::lwp::thread::resume(lwp_t thread)
	{ return LWP_ResumeThread(thread); }

bool ogcwrap::lwp::thread::isSuspended(lwp_t thread)
	{ return (LWP_ThreadIsSuspended(thread) == 1 ? true : false); }

lwp_t ogcwrap::lwp::thread::getSelf(void)
	{ return LWP_GetSelf(); }

void ogcwrap::lwp::thread::setPriority(lwp_t thread, u32 priority)
	{ LWP_SetThreadPriority(thread, priority); }

void ogcwrap::lwp::thread::yield(void)
	{ LWP_YieldThread(); }

void ogcwrap::lwp::thread::reschedule(u32 priority)
	{ LWP_Reschedule(priority); }

s32 ogcwrap::lwp::thread::join(lwp_t thread, void * * return_value)
	{ return LWP_JoinThread(thread, return_value); }

u32 ogcwrap::lwp::thread::_init(lwp_cntrl * thread, void * stackBase, u32 stackSize, u32 priority, u32 isrLevel, bool preemptible)
	{ return __lwp_thread_init(thread, stackBase, stackSize, priority, isrLevel, preemptible); }

u32 ogcwrap::lwp::thread::_start(lwp_cntrl * thread, void * (*entry)(void *), void * args)
	{ return __lwp_thread_start(thread, entry, args); }

void ogcwrap::lwp::thread::_exit(void * retval)
	{ __lwp_thread_exit(retval); }

void ogcwrap::lwp::thread::_close(lwp_cntrl * thread)
	{ __lwp_thread_close(thread); }

void ogcwrap::lwp::thread::_dispatch(void)
	{ __thread_dispatch(); }

void ogcwrap::lwp::thread::_yield(void)
	{ __lwp_thread_yield(); }

void ogcwrap::lwp::thread::_closeAll(void)
	{ __lwp_thread_closeall(); }

void ogcwrap::lwp::thread::_setState(lwp_cntrl * thread, u32 state)
	{ __lwp_thread_setstate(thread, state); }

void ogcwrap::lwp::thread::_clearState(lwp_cntrl * thread, u32 state)
	{ __lwp_thread_clearstate(thread, state); }

void ogcwrap::lwp::thread::_changePriority(lwp_cntrl * thread, u32 priority, bool prepend)
	{ __lwp_thread_changepriority(thread, priority, static_cast<u32>(prepend)); }

void ogcwrap::lwp::thread::_setPriority(lwp_cntrl * thread, u32 priority)
	{ __lwp_thread_setpriority(thread, priority); }

void ogcwrap::lwp::thread::_setTransient(lwp_cntrl * thread)
	{ __lwp_thread_settransient(thread); }

void ogcwrap::lwp::thread::_suspend(lwp_cntrl * thread)
	{ __lwp_thread_suspend(thread); }

void ogcwrap::lwp::thread::_resume(lwp_cntrl * thread, bool force)
	{ __lwp_thread_resume(thread, static_cast<u32>(force)); }

void ogcwrap::lwp::thread::_loadEnv(lwp_cntrl * thread)
	{ __lwp_thread_loadenv(thread); }

void ogcwrap::lwp::thread::_ready(lwp_cntrl * thread)
	{ __lwp_thread_ready(thread); }

void ogcwrap::lwp::thread::_startMultitasking(void)
	{ __lwp_thread_startmultitasking(); }

void ogcwrap::lwp::thread::_stopMultitasking(void (*exit)(void))
	{ __lwp_thread_stopmultitasking(exit); }

#ifdef UNDEFINED_REFERENCES
lwp_obj * ogcwrap::lwp::thread::_getObject(lwp_cntrl * thread)
	{ return __lwp_thread_getobject(thread); }
#endif // UNDEFINED_REFERENCES

u32 ogcwrap::lwp::thread::_evaluateMode(void)
	{ return __lwp_evaluatemode(); }

void ogcwrap::lwp::thread::_resetTimeslice(void)
	{ __lwp_thread_resettimeslice(); }

void ogcwrap::lwp::thread::_tickleTimeslice(void * arg)
	{ __lwp_thread_tickle_timeslice(arg); }

void ogcwrap::lwp::thread::_delayEnded(void * arg)
	{ __lwp_thread_delayended(arg); }

u32 ogcwrap::lwp::thread::_ISRInProgress(void)
	{ return __lwp_isr_in_progress(); }

void ogcwrap::lwp::thread::_rotateReadyQueue(u32 priority)
	{ __lwp_rotate_readyqueue(priority); }

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

void ogcwrap::lwp::thread_queue::_init(lwp_thrqueue * queue, u32 mode, u32 state, u32 timeoutState)
	{ __lwp_threadqueue_init(queue, mode, state, timeoutState); }

lwp_cntrl * ogcwrap::lwp::thread_queue::_first(lwp_thrqueue * queue)
	{ return __lwp_threadqueue_first(queue); }

void ogcwrap::lwp::thread_queue::_enqueue(lwp_thrqueue * queue, u64 timeout)
	{ __lwp_threadqueue_enqueue(queue, timeout); }

lwp_cntrl * ogcwrap::lwp::thread_queue::_dequeue(lwp_thrqueue * queue)
	{ return __lwp_threadqueue_dequeue(queue); }

void ogcwrap::lwp::thread_queue::_flush(lwp_thrqueue * queue, u32 status)
	{ __lwp_threadqueue_flush(queue, status); }

void ogcwrap::lwp::thread_queue::_extract(lwp_thrqueue * queue, lwp_cntrl * thread)
	{ __lwp_threadqueue_extract(queue, thread); }

lwp_cntrl * ogcwrap::lwp::thread_queue::_firstFIFO(lwp_thrqueue * queue)
	{ return __lwp_threadqueue_firstfifo(queue); }

void ogcwrap::lwp::thread_queue::_enqueueFIFO(lwp_thrqueue * queue, lwp_cntrl * thread, u64 timeout)
	{ __lwp_threadqueue_enqueuefifo(queue, thread, timeout); }

lwp_cntrl * ogcwrap::lwp::thread_queue::_dequeueFIFO(lwp_thrqueue * queue)
	{ return __lwp_threadqueue_dequeuefifo(queue); }

void ogcwrap::lwp::thread_queue::_extractFIFO(lwp_thrqueue * queue, lwp_cntrl * thread)
	{ __lwp_threadqueue_extractfifo(queue, thread); }

lwp_cntrl * ogcwrap::lwp::thread_queue::_firstPriority(lwp_thrqueue * queue)
	{ return __lwp_threadqueue_firstpriority(queue); }

void ogcwrap::lwp::thread_queue::_enqueuePriority(lwp_thrqueue * queue, lwp_cntrl * thread, u64 timeout)
	{ __lwp_threadqueue_enqueuepriority(queue, thread, timeout); }

lwp_cntrl * ogcwrap::lwp::thread_queue::_dequeuePriority(lwp_thrqueue * queue)
	{ return __lwp_threadqueue_dequeuepriority(queue); }

void ogcwrap::lwp::thread_queue::_extractPriority(lwp_thrqueue * queue, lwp_cntrl * thread)
	{ __lwp_threadqueue_extractpriority(queue, thread); }

u32 ogcwrap::lwp::thread_queue::_extractProxy(lwp_cntrl * thread)
	{ return __lwp_threadqueue_extractproxy(thread); }

// lwp::condition functions

s32 ogcwrap::lwp::condition::init(cond_t * condition)
	{ return LWP_CondInit(condition); }

s32 ogcwrap::lwp::condition::destroy(cond_t condition)
	{ return LWP_CondDestroy(condition); }

s32 ogcwrap::lwp::condition::wait(cond_t condition, mutex_t mutex)
	{ return LWP_CondWait(condition, mutex); }

s32 ogcwrap::lwp::condition::timedWait(cond_t condition, mutex_t mutex, const struct timespec * abstime)
	{ return LWP_CondTimedWait(condition, mutex, abstime); }

s32 ogcwrap::lwp::condition::signal(cond_t condition)
	{ return LWP_CondSignal(condition); }

s32 ogcwrap::lwp::condition::broadcast(cond_t condition)
	{ return LWP_CondBroadcast(condition); }

// lwp::heap functions

u32 ogcwrap::lwp::heap::_init(heap_cntrl * heap, void * start_addr, u32 heapSize, u32 pageSize)
	{ return __lwp_heap_init(heap, start_addr, heapSize, pageSize); }

void * ogcwrap::lwp::heap::_alloc(heap_cntrl * heap, u32 size)
	{ return __lwp_heap_allocate(heap, size); }

bool ogcwrap::lwp::heap::_free(heap_cntrl * heap, void * ptr)
	{ return __lwp_heap_free(heap, ptr); }

u32 ogcwrap::lwp::heap::_getInfo(heap_cntrl * heap, heap_iblock * info)
	{ return __lwp_heap_getinfo(heap, info); }

// lwp::message_queue functions

s32 ogcwrap::lwp::message_queue::init(mqbox_t * box, u32 msgCount)
	{ return MQ_Init(box, msgCount); }

void ogcwrap::lwp::message_queue::close(mqbox_t box)
	{ MQ_Close(box); }

bool ogcwrap::lwp::message_queue::send(mqbox_t box, mqmsg_t msg, u32 flags)
	{ return (MQ_Send(box, msg, flags) == 1 ? true : false); }

bool ogcwrap::lwp::message_queue::jam(mqbox_t box, mqmsg_t msg, u32 flags)
	{ return (MQ_Jam(box, msg, flags) == 1 ? true : false); }

bool ogcwrap::lwp::message_queue::receive(mqbox_t box, mqmsg_t * msg, u32 flags)
	{ return (MQ_Receive(box, msg, flags) == 1 ? true : false); }

u32 ogcwrap::lwp::message_queue::_init(mq_cntrl * queue, mq_attr * attrs, u32 maxPendingMsgs, u32 maxMsgSize)
	{ return __lwpmq_initialize(queue, attrs, maxPendingMsgs, maxMsgSize); }

void ogcwrap::lwp::message_queue::_close(mq_cntrl * queue, u32 status)
	{ __lwpmq_close(queue, status); }

u32 ogcwrap::lwp::message_queue::_seize(mq_cntrl * queue, u32 id, void * buf, u32 * size, u32 wait, u64 timeout)
	{ return __lwpmq_seize(queue, id, buf, size, wait, timeout); }

u32 ogcwrap::lwp::message_queue::_submit(mq_cntrl * queue, u32 id, void * buf, u32 size, u32 type, u32 wait, u64 timeout)
	{ return __lwpmq_submit(queue, id, buf, size, type, wait, timeout); }

u32 ogcwrap::lwp::message_queue::_broadcast(mq_cntrl * queue, void * buf, u32 size, u32 id, u32 * count)
	{ return __lwpmq_broadcast(queue, buf, size, id, count); }

void ogcwrap::lwp::message_queue::_messageInsert(mq_cntrl * queue, mq_buffercntrl * msg, u32 type)
	{ __lwpmq_msg_insert(queue, msg, type); }

u32 ogcwrap::lwp::message_queue::_flush(mq_cntrl * queue)
	{ return __lwpmq_flush(queue); }

u32 ogcwrap::lwp::message_queue::_flushSupport(mq_cntrl * queue)
	{ return __lwpmq_flush_support(queue); }

void ogcwrap::lwp::message_queue::_flushWaitThreads(mq_cntrl * queue)
	{ __lwpmq_flush_waitthreads(queue); }

// lwp::mutex functions

s32 ogcwrap::lwp::mutex::init(mutex_t * mutex, bool useRecursive)
	{ return LWP_MutexInit(mutex, useRecursive); }

s32 ogcwrap::lwp::mutex::destroy(mutex_t mutex)
	{ return LWP_MutexDestroy(mutex); }

s32 ogcwrap::lwp::mutex::lock(mutex_t mutex)
	{ return LWP_MutexLock(mutex); }

s32 ogcwrap::lwp::mutex::tryLock(mutex_t mutex)
	{ return LWP_MutexTryLock(mutex); }

s32 ogcwrap::lwp::mutex::unlock(mutex_t mutex)
	{ return LWP_MutexUnlock(mutex); }

void ogcwrap::lwp::mutex::_init(lwp_mutex * mutex, lwp_mutex_attr * attr, u32 initLock)
	{ __lwp_mutex_initialize(mutex, attr, initLock); }

u32 ogcwrap::lwp::mutex::_surrender(lwp_mutex * mutex)
	{ return __lwp_mutex_surrender(mutex); }

#ifdef USES_UNDEFINED_REFERENCES
void ogcwrap::lwp::mutex::_seize(lwp_mutex * mutex, s32 id, u8 wait, u32 timeout, u32 level)
	{ __lwp_mutex_seize(mutex, id, wait, timeout, level); }
#endif // USES_UNDEFINED_REFERENCES

void ogcwrap::lwp::mutex::_seizeIRQBlocking(lwp_mutex * mutex, u64 timeout)
	{ __lwp_mutex_seize_irq_blocking(mutex, timeout); }

#ifdef UNDEFINED_REFERENCES
void ogcwrap::lwp::mutex::_seizeIRQTryLock(lwp_mutex * mutex, u32 * status)
	{ __lwp_mutex_seize_irq_trylock(mutex, status); }
#endif // UNDEFINED_REFERENCES

void ogcwrap::lwp::mutex::_flush(lwp_mutex * mutex, u32 status)
	{ __lwp_mutex_flush(mutex, status); }


// lwp::objmgr functions

void ogcwrap::lwp::objmgr::_initInfo(lwp_objinfo * info, u32 maxNodes, u32 nodeSize)
	{ __lwp_objmgr_initinfo(info, maxNodes, nodeSize); }

void ogcwrap::lwp::objmgr::_free(lwp_objinfo * info, lwp_obj * object)
	{ __lwp_objmgr_free(info, object); }

lwp_obj * ogcwrap::lwp::objmgr::_alloc(lwp_objinfo * info)
	{ return __lwp_objmgr_allocate(info); }

lwp_obj * ogcwrap::lwp::objmgr::_get(lwp_objinfo * info, u32 id)
	{ return __lwp_objmgr_get(info, id); }

lwp_obj * ogcwrap::lwp::objmgr::_getISRDisable(lwp_objinfo * info, u32 id, u32 * p_level)
	{ return __lwp_objmgr_getisrdisable(info, id, p_level); }

lwp_obj * ogcwrap::lwp::objmgr::_getNoProtection(lwp_objinfo * info, u32 id)
	{ return __lwp_objmgr_getnoprotection(info, id); }

// lwp::priority functions

void ogcwrap::lwp::priority::_init(void)
	{ __lwp_priority_init(); }

// lwp::queue functions

void ogcwrap::lwp::queue::_init(lwp_queue * queue, void * start_addr, u32 nodeCount, u32 nodeSize)
	{ __lwp_queue_initialize(queue, start_addr, nodeCount, nodeSize); }

lwp_node * ogcwrap::lwp::queue::_get(lwp_queue * queue)
	{ return __lwp_queue_get(queue); }

void ogcwrap::lwp::queue::_append(lwp_queue * queue, lwp_node * node)
	{ __lwp_queue_append(queue, node); }

void ogcwrap::lwp::queue::_extract(lwp_node * node)
	{ __lwp_queue_extract(node); }

void ogcwrap::lwp::queue::_insert(lwp_node * after, lwp_node * node)
	{ __lwp_queue_insert(after, node); }

// lwp::semaphore functions

s32 ogcwrap::lwp::semaphore::init(sem_t * semaphore, u32 startCount, u32 maxCount)
	{ return LWP_SemInit(semaphore, startCount, maxCount); }

s32 ogcwrap::lwp::semaphore::destroy(sem_t semaphore)
	{ return LWP_SemDestroy(semaphore); }

s32 ogcwrap::lwp::semaphore::wait(sem_t semaphore)
	{ return LWP_SemWait(semaphore); }

s32 ogcwrap::lwp::semaphore::getValue(sem_t semaphore, u32 * value)
	{ return LWP_SemGetValue(semaphore, value); }

s32 ogcwrap::lwp::semaphore::post(sem_t semaphore)
	{ return LWP_SemPost(semaphore); }

void ogcwrap::lwp::semaphore::_init(lwp_sema * semaphore, lwp_semattr * attributes, u32 initCount)
	{ __lwp_sema_initialize(semaphore, attributes, initCount); }

void ogcwrap::lwp::semaphore::_surrender(lwp_sema * semaphore, u32 id)
	{ __lwp_sema_surrender(semaphore, id); }

void ogcwrap::lwp::semaphore::_seize(lwp_sema * semaphore, u32 id, u32 wait, u64 timeout)
	{ __lwp_sema_seize(semaphore, id, wait, timeout); }

void ogcwrap::lwp::semaphore::_flush(lwp_sema * semaphore, u32 status)
	{ __lwp_sema_flush(semaphore, status); }

// lwp::stack functions

u32 ogcwrap::lwp::stack::_alloc(lwp_cntrl * control, u32 size)
	{ return __lwp_stack_allocate(control, size); }

void ogcwrap::lwp::stack::_free(lwp_cntrl * control)
	{ __lwp_stack_free(control); }

// lwp::watchdog functions

void ogcwrap::lwp::watchdog::_init(void)
	{ __lwp_watchdog_init(); }

#ifdef UNDEFINED_REFERENCES
void ogcwrap::lwp::watchdog::_setTimer(wd_cntrl * wd)
	{ __lwp_watchdog_settimer(wd); }
#endif // UNDEFINED_REFERENCES

void ogcwrap::lwp::watchdog::_insert(lwp_queue * header, wd_cntrl * wd)
	{ __lwp_wd_insert(header, wd); }

u32 ogcwrap::lwp::watchdog::_remove(lwp_queue * header, wd_cntrl * wd)
	{ return __lwp_wd_remove(header, wd); }

void ogcwrap::lwp::watchdog::_tickle(lwp_queue * queue)
	{ __lwp_wd_tickle(queue); }

void ogcwrap::lwp::watchdog::_adjust(lwp_queue * queue, u32 dir, s64 interval)
	{ __lwp_wd_adjust(queue, dir, interval); }

// lwp::workspace functions

void ogcwrap::lwp::workspace::_init(u32 size)
	{ __lwp_wkspace_init(size); }