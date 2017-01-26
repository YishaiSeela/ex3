/*
 * ThreadPool.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: adi
 */

#include "ThreadPool.h"
#include <unistd.h>
#include <iostream>
static void *startJobs(void *arg) {
    ThreadPool *pool = (ThreadPool *)arg;
    pool->doJobs();
    return NULL;
}

void ThreadPool::doJobs() {
    while (!stop) {
        pthread_mutex_lock(&lock);
        if (!jobs_queue.empty()) {
            Job* job = jobs_queue.front();
            jobs_queue.pop();
            pthread_mutex_unlock(&lock);
            job->execute();
        }
        else {
            pthread_mutex_unlock(&lock);
            sleep(1);
        }
    }
    pthread_exit(NULL);
}

void ThreadPool::addJob(Job *job) {
    jobs_queue.push(job);
}

ThreadPool::ThreadPool(int threads_num) : threads_num(threads_num), stop(false) {
    // TODO Auto-generated constructor stub
    threads = new pthread_t[5];

    pthread_mutex_init(&lock, NULL);
    for (int i = 0; i < 5; i++) {
        pthread_create(threads + i, NULL, startJobs, this);
    }
}

void ThreadPool::terminate() {
    stop = true;
}

ThreadPool::~ThreadPool() {
    // TODO Auto-generated destructor stub
    delete[] threads;
    pthread_mutex_destroy(&lock);
}

bool ThreadPool::isEmpty() {

}

