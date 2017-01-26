/*
 * MyTask.h
 *
 *  Created on: Jan 20, 2017
 *      Author: adi
 */

#ifndef MYTASK_H_
#define MYTASK_H_

#include <pthread.h>

class MyTask {
private:
    pthread_t thread_id;
    pthread_mutex_t *lock;
    int task_id;
    bool isStopped;
    int *counter;

public:
    MyTask(int task_id, int *counter, pthread_mutex_t *lock);
    int getTaskId() const { return task_id; }
    bool getIsStopped() const {return isStopped; }
    void incrementCounter();
    void start();
    void join();
    void stop();
    virtual ~MyTask();
};

#endif /* MYTASK_H_ */
