/*
 * MyTask.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: Adi
 */

#include "MyTask.h"
#include <iostream>
#include <unistd.h>
using namespace std;

MyTask::MyTask(int task_id, int *counter, pthread_mutex_t *lock) : task_id(task_id), isStopped(false), counter(counter),
                                                                   lock(lock) {
    // TODO Auto-generated constructor stub

}

void MyTask::incrementCounter() {
    for (int i = 0; i < 10000000; i++) {
        pthread_mutex_lock(lock);
        (*counter)++;
        pthread_mutex_unlock(lock);
    }
}

static void *increment(void *arg) {
    MyTask *task = (MyTask *)arg;
    task->incrementCounter();
}

static void *print(void *arg) {
    MyTask *task = (MyTask *)arg;

    for (int i = 1; i <= 10 && !task->getIsStopped(); i++) {
        cout << "Task " << task->getTaskId()<< ": " << i << endl;
        sleep(1);
    }
}

void MyTask::start() {
    //pthread_create(&thread_id, NULL, print, this);
    pthread_create(&thread_id, NULL, increment, this);
}

void MyTask::join() {
    pthread_join(thread_id, NULL);
}

void MyTask::stop() {
    isStopped = true;
    //pthread_cancel(thread_id);
}

MyTask::~MyTask() {
    // TODO Auto-generated destructor stub
}

