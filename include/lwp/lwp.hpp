#pragma once
#ifndef wrap_lwp_h
#define wrap_lwp_h

#include <gctypes.h>
#include <ogc/lwp.h>
#include <ogc/message.h>
#include <ogc/mutex.h>
#include <ogc/semaphore.h>
#include <ogc/cond.h>

namespace ogcwrap::lwp
{
	namespace thread
	{
		// thread management
		s32 create(lwp_t * thread, void * (*entry)(void *), void * arg, void * stackbase, u32 stacksize, u8 priority);
		s32 suspend(lwp_t thread);
		s32 resume(lwp_t thread);
		bool isSuspended(lwp_t thread);
		lwp_t getSelf(void);
		void setPriority(lwp_t thread, u32 priority);
		void yield(void);
		void reschedule(u32 priority);
		s32 join(lwp_t thread, void * * return_value);
	}

	namespace thread_queue
	{
		// thread queue management
		s32 init(lwpq_t * queue);
		void close(lwpq_t queue);

		s32 threadSleep(lwpq_t queue);
		void threadSignal(lwpq_t queue);
		void threadBroadcast(lwpq_t queue);
	}

	namespace message_queue
	{
		s32 init(mqbox_t * box, u32 msgCount);
		void close(mqbox_t box);
		bool send(mqbox_t box, mqmsg_t msg, u32 flags);
		bool jam(mqbox_t box, mqmsg_t msg, u32 flags);
		bool receive(mqbox_t box, mqmsg_t * msg, u32 flags);
	}

	namespace mutex
	{
		s32 init(mutex_t * mutex, bool useRecursive);
		s32 destroy(mutex_t mutex);
		s32 lock(mutex_t mutex);
		s32 tryLock(mutex_t mutex);
		s32 unlock(mutex_t mutex);
	}

	namespace semaphore
	{
		s32 init(sem_t * semaphore, u32 startCount, u32 maxCount);
		s32 destroy(sem_t semaphore);
		s32 wait(sem_t semaphore);
		s32 getValue(sem_t semaphore, u32 * value);
		s32 post(sem_t semaphore);
	}

	namespace condition
	{
		s32 init(cond_t * condition);
		s32 destroy(cond_t condition);
		s32 wait(cond_t condition, mutex_t mutex);
		s32 timedWait(cond_t condition, mutex_t mutex, const struct timespec * abstime);
		s32 signal(cond_t condition);
		s32 broadcast(cond_t condition);
	}
}

#endif // wrap_lwp_h