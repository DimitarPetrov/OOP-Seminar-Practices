//
// Created by dimitar on 31.05.18.
//

#include "RepeatTask.h"
#include <iostream>

RepeatTask::RepeatTask() : task(nullptr), repetitions(0), progress(0) {}

RepeatTask::RepeatTask(Task *task, int repetitions) : repetitions(repetitions), progress(0) {
    this->task = task->clone();
}

bool RepeatTask::isFinished() const {
    return repetitions == progress;
}

void RepeatTask::work() {
    if(repetitions > progress) {
        if (task->isFinished()) {
            ++progress;
            task->restart();
        }
        task->work();
    }
}

double RepeatTask::getProgress() const {
    return 1 - ((repetitions - progress) / (double)repetitions) + task->getProgress() / repetitions;
}

void RepeatTask::print(std::ostream &os) const {
    task->print(os);
    os << " (Repeat task " << repetitions << " times)";
}

RepeatTask::~RepeatTask() {
    delete task;
}

std::ostream &operator<<(std::ostream &os, const RepeatTask &rt) {
    rt.print(os);
    return os;
}

Task *RepeatTask::clone() const {
    return new RepeatTask(*this);
}

void RepeatTask::restart() {
    progress = 0;
    task->restart();
}

RepeatTask::RepeatTask(const RepeatTask &r) {
    task = r.task->clone();
    repetitions = r.repetitions;
    progress = r.progress;
}

RepeatTask &RepeatTask::operator=(const RepeatTask &r) {
    if(this != &r){
        delete task;
        task = r.task->clone();
        repetitions = r.repetitions;
        progress = r.progress;
    }
    return *this;
}
