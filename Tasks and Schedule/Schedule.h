//
// Created by dimitar on 31.05.18.
//

#ifndef TASKS_COMPLEXTASK_H
#define TASKS_COMPLEXTASK_H


#include "Task.h"

class Schedule {

private:
    Task** tasks;
    int capacity;
    int current;

    void Copy(const Schedule& ct);
    void Erase();

    void resize();

public:
    Schedule(int capacity = 10);
    Schedule(const Schedule& ct);
    Schedule& operator=(const Schedule& ct);
    virtual void work(int i);
    void print(std::ostream& os) const;
    void addTask(Task* task);
    ~Schedule();

    friend std::ostream& operator<<(std::ostream& os, const Schedule& ct);
};


#endif //TASKS_COMPLEXTASK_H
