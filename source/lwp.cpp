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

void ogcwrap::lwp::thread::setPriority(lwp_t thread, u32 priority)
	{ LWP_SetPriority(thread, priority); }

void ogcwrap::lwp::thread::yield(void)
	{ LWP_YieldThread(); }

void ogcwrap::lwp::thread::reschedule(u32 priority)
	{ LWP_Reschedule(priority); }

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

// lwp::condition functions

s32 ogcwrap::lwp::condition::init(cond_t * condition)
	{ return LWP_CondInit(condition); }

s32 ogcwrap::lwp::condition::destroy(cond_t condition)
	{ return LWP_CondDestroy(condition); }

s32 ogcwrap::lwp::condition::wait(cond_t condition, mutex_t mutex)
	{ return LWP_ContWait(condition, mutex); }

s32 ogcwrap::lwp::condition::timedWait(cond_t condition, mutex_t mutex, const struct timespec * abstime)
	{ return LWP_CondTimedWait(condition, mutex, abstime); }

s32 ogcwrap::lwp::condition::signal(cond_t condition)
	{ return LWP_CondSignal(condition); }

s32 ogcwrap::lwp::condition::broadcast(cond_t condition)
	{ return LWP_CondBroadcast(condition); }

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
	{ return LWP_Unlock(mutex); }

void ogcwrap::lwp::mutex::_init(lwp_mutex * mutex, lwp_mutex_attr * attr, u32 initLock)
	{ __lwp_mutex_initialize(mutex, attr, initLock); }

u32 ogcwrap::lwp::mutex::_surrender(lwp_mutex * mutex)
	{ return __lwp_mutex_surrender(mutex); }

/*
void ogcwrap::lwp::mutex::_seize(lwp_mutex * mutex, s32 id, u8 wait, u32 timeout, u32 level)
	{ __lwp_mutex_seize(mutex, id, wait, timeout, level); }
*/

void ogcwrap::lwp::mutex::_seizeIRQBlocking(lwp_mutex * mutex, u64 timeout)
	{ __lwp_mutex_seize_irq_blocking(mutex, timeout); }

/*
void ogcwrap::lwp::mutex::_seizeIRQTryLock(lwp_mutex * mutex, u32 * status)
	{ __lwp_mutex_seize_irq_trylock(mutex, isr_level); }
*/

void ogcwrap::lwp::mutex::_flush(lwp_mutex * mutex, u32 status)
	{ __lwp_mutex_flush(mutex, status); }


// lwp::objmgr functions

void ogcwrap::lwp::objmgr::_initInfo(lwp_objinfo * info, u32 maxNodes, u32 nodeSize)
	{ __lwp_objmgr_initinfo(info, maxNodes, nodeSize); }

void ogcwrap::lwp::objmgr::_free(lwp_objinfo * info, lwp_obj * object)
	{ __lwp_objmgr_free(info, object); }

lwp_obj * ogcwrap::lwp::objmgr::_alloc(lwp_objinfo * info)
	{ return __lwp_objmgr_alloc(info); }

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

void ogcwrap::lwp::queue::_init(lwp_queue * queue, void * arg1, u32 arg2, u32 arg3)
	{ __lwp_queue_initialize(queue, arg1, arg2, arg3); }

lwp_node * ogcwrap::lwp::queue::_get(lwp_queue * queue)
	{ return __lwp_queue_get(queue); }

void ogcwrap::lwp::queue::_append(lwp_queue * queue, lwp_node * node)
	{ __lwp_queue_append(queue, node); }

void ogcwrap::lwp::queue::_extract(lwp_node * node)
	{ __lwp_queue_extract(node); }

void ogcwrap::lwp::queue::_insert(lwp_node * node0, lwp_node * node1)
	{ __lwp_queue_insert(node0, node1); }

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

void ogcwrap::lwp::watchdog::_setTimer(wd_cntrl * wd)
	{ __lwp_watchdog_settimer(wd); }

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