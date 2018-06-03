//
// Created by dimitar on 31.05.18.
//

#include <iostream>
#include "Schedule.h"

Schedule::Schedule(int capacity) : capacity(capacity), current(0){
    tasks = new Task*[capacity];
}

Schedule::Schedule(const Schedule &ct) {
    Copy(ct);
}

Schedule &Schedule::operator=(const Schedule &ct) {
    if(this != &ct){
        Erase();
        Copy(ct);
    }
    return *this;
}

void Schedule::print(std::ostream &os) const {
    for(int i = 0; i < current; ++i){
        os << i + 1 << ". " << *tasks[i] << ". With progress: " << tasks[i]->getProgress() <<  std::endl;
    }
}

Schedule::~Schedule() {
    Erase();
}

std::ostream &operator<<(std::ostream &os, const Schedule &ct) {
    ct.print(os);
    return os;
}

void Schedule::Copy(const Schedule &ct) {
    capacity = ct.capacity;
    current = ct.current;
    this->tasks = new Task*[capacity];
    for(int i = 0; i < current; ++i){
        tasks[i] = ct.tasks[i]->clone();
    }
}

void Schedule::Erase() {
    for(int i = 0; i < current; ++i){
        delete tasks[i];
    }
    delete[] tasks;
}

void Schedule::work(int i) {
    if(i-1 < current && i-1 >= 0){
        tasks[i-1]->work();
    }
}

void Schedule::resize() {
    Task** tmp = tasks;
    capacity *= 2;
    tasks = new Task*[capacity];
    for(int i = 0; i < current; ++i){
        tasks[i] = tmp[i];
    }
    delete[] tmp;
}

void Schedule::addTask(Task *task) {
    if(current == capacity){
        resize();
    }
    tasks[current] = task->clone();
    ++current;
}
