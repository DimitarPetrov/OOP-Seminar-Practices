//
// Created by dimitar on 31.05.18.
//

#ifndef TASKS_SIMPLETASK_H
#define TASKS_SIMPLETASK_H


#include "Task.h"

class SimpleTask : public Task{

private:
    char* description;
    int size;
    int progress;

    void Copy(const SimpleTask& s);
    void Erase();

public:
    SimpleTask();
    SimpleTask(const char* description, int size = 1);
    SimpleTask(const SimpleTask& s);
    SimpleTask& operator=(const SimpleTask& s);
    virtual bool isFinished() const;
    virtual void work();
    virtual double getProgress() const;
    virtual void print(std::ostream& os) const;
    virtual Task* clone() const;
    virtual void restart();
    virtual ~SimpleTask();

    friend std::ostream& operator<<(std::ostream& os, const SimpleTask& s);
};


#endif //TASKS_SIMPLETASK_H
