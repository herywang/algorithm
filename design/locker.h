#ifndef _LOCKER_H_
#define _LOCKER_H_
#include <pthread.h>
#ifdef __APPLE__
#include <dispatch/dispatch.h>
#else
#include <semaphore.h>
#endif

#include <exception>

class locker {
private:
    pthread_mutex_t mutex;

public:
    locker() {
        if (pthread_mutex_init(&(this->mutex), nullptr) != 0) {
            throw std::exception();
        }
    }
    ~locker() {
        pthread_mutex_destroy(&(this->mutex));
    }
    bool lock() {
        return pthread_mutex_lock(&(this->mutex)) == 0;
    }
    bool unlock() {
        return pthread_mutex_unlock(&(this->mutex)) == 0;
    }
};

class sem {
public:
    sem() {
#ifdef __APPLE__
        m_sem = dispatch_semaphore_create(0);
#else
        if (sem_init(&m_sem, 0, 0) != 0) {
            throw std::exception();
        }
#endif
    }
    sem(int init_num) {
#ifdef __APPLE__
        m_sem = dispatch_semaphore_create(init_num);
#else
        if (sem_init(&(this->m_sem), 0, init_num) != 0) {
            throw std::exception();
        }
#endif
    }
    ~sem() {
#ifdef __APPLE__

#else
        sem_destroy(&m_sem);
#endif
    }

    bool wait() {
#ifdef __APPLE__
        return dispatch_semaphore_wait(m_sem, DISPATCH_TIME_FOREVER) == 0;
#else
        return sem_wait(&(this->m_sem)) == 0;
#endif
    }

    bool post() {
#ifdef __APPLE__
        return dispatch_semaphore_signal(m_sem) == 0;
#else
        return sem_post(&(this->m_sem)) == 0;
#endif
    }

private:
#ifdef __APPLE__
    dispatch_semaphore_t m_sem;
#else
    sem_t m_sem;
#endif
};

#endif