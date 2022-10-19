#ifndef _THREADPOOL_H
#define _THREADPOOL_H
#include <pthread.h>
#include <mutex>
#include <queue>
#include "locker.h"
#include "runnable.h"

class threadpool {
public:
    threadpool(int thread_number, int max_request);
    ~threadpool();
    bool append(std::shared_ptr<runnable> task);

private:
    int thread_number;                             // 线程数量
    pthread_t *threads;                            // 线程数量数组, 大小等于 thread_number
    int max_requests;                              // 队列中最大允许的任务数量
    std::queue<std::shared_ptr<runnable>> m_queue; // 任务队列
    sem m_sem;                                     // 任务队列存取的信号量, 值表示当前队列中剩余等待调度的任务数量
    locker m_queue_locker;                         // 队列写锁
    static void *worker(void *arg);                // c++线程执行的具体方法
    void run();
};

#endif

/**
 * @brief Construct a new threadpool::threadpool object
 * 有参 初始化线程池
 * @param thread_number 初始线程数量
 * @param max_request 最大队列数量
 */
threadpool::threadpool(int thread_number, int max_request) {
    if (thread_number <= 0 || max_request <= 0) {
        throw std::exception();
    }
    this->max_requests = max_request;
    this->threads = new pthread_t[thread_number];

    if (!this->threads) {
        throw std::exception();
    }
    for (int i = 0; i < thread_number; i++) {
        if (pthread_create(this->threads + i, nullptr, worker, this) != 0) {
            // create ans start thread failed
            delete[] this->threads;
            throw std::exception();
        }
        if (pthread_detach(this->threads[i]) != 0) {
            delete[] this->threads;
            throw std::exception();
        }
    }
}

threadpool::~threadpool() {
    delete[] this->threads;
}

/**
 * @brief 线程池执行函数体
 *
 * @param arg
 * @return void*
 */
void *threadpool::worker(void *arg) {
    threadpool *pool = (threadpool *)arg;
    pool->run();
    return pool;
}

/**
 * @brief 添加一个任务到线程池的队列中
 *
 * @param task 任务指针
 * @return true
 * @return false
 */
bool threadpool::append(std::shared_ptr<runnable> task) {
    this->m_queue_locker.lock(); // 阻塞获取锁
    if (this->m_queue.size() >= this->max_requests) {
        this->m_queue_locker.unlock();
        return false;
    }
    this->m_queue.push(task);
    this->m_queue_locker.unlock();
    this->m_sem.post();
    return true;
}

void threadpool::run() {
    while (true) {
        this->m_sem.wait();
        this->m_queue_locker.lock();
        if (this->m_queue.empty()) {
            this->m_queue_locker.unlock();
            continue;
        }
        auto task = this->m_queue.front();
        this->m_queue.pop();
        this->m_queue_locker.unlock();
        task->run();
    }
}