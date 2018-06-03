//
// Created by dimitar on 31.05.18.
//

#ifndef TASKS_REPEATTASK_H
#define TASKS_REPEATTASK_H


#include "Task.h"

class RepeatTask : public Task{

private:
    Task* task;
    int repetitions;
    int progress;

public:
    RepeatTask();
    RepeatTask(Task* task, int repetitions);
    RepeatTask(const RepeatTask& r);
    RepeatTask& operator=(const RepeatTask& r);
    virtual bool isFinished() const;
    virtual void work();
    virtual double getProgress() const;
    virtual void print(std::ostream& os) const;
    virtual Task* clone() const;
    virtual void restart();
    virtual ~RepeatTask();

    friend std::ostream& operator<<(std::ostream& os, const RepeatTask& rt);
};


#endif //TASKS_REPEATTASK_H
