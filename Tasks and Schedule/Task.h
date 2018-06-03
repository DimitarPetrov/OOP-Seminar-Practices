//
// Created by dimitar on 31.05.18.
//

#ifndef TASKS_TASK_H
#define TASKS_TASK_H


#include <iosfwd>

class Task {

public:
    virtual bool isFinished() const = 0;
    virtual void work() = 0;
    virtual double getProgress() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual Task* clone() const = 0;
    virtual void restart() = 0;

    friend std::ostream& operator<<(std::ostream& os, const Task& t){
        t.print(os);
        return os;
    }
};


#endif //TASKS_TASK_H
