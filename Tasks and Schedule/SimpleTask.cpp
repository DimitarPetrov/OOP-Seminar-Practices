//
// Created by dimitar on 31.05.18.
//

#include <cstring>
#include "SimpleTask.h"
#include <iostream>

void SimpleTask::Copy(const SimpleTask &s) {
    this->description = new char[strlen(s.description) + 1];
    strcpy(this->description, s.description);
    this->size = s.size;
    this->progress = s.progress;
}

void SimpleTask::Erase() {
    delete[] description;
}

SimpleTask::SimpleTask() : description(nullptr), size(0), progress(0) {}

SimpleTask::SimpleTask(const char *description, int size) : size(size), progress(0){
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

SimpleTask::SimpleTask(const SimpleTask &s) {
    Copy(s);
}

SimpleTask &SimpleTask::operator=(const SimpleTask &s){
    if(this != &s){
        Erase();
        Copy(s);
    }
    return *this;
}

bool SimpleTask::isFinished() const {
    return size == progress;
}

void SimpleTask::work() {
    if(size > progress){
        ++progress;
    }
}

double SimpleTask::getProgress() const {
    return 1 - ((size - progress) / (double)size);
}

void SimpleTask::print(std::ostream& os) const {
    os << description;
}

SimpleTask::~SimpleTask() {
    Erase();
}

std::ostream &operator<<(std::ostream &os, const SimpleTask &s) {
    s.print(os);
    return os;
}

Task *SimpleTask::clone() const {
    return new SimpleTask(*this);
}

void SimpleTask::restart(){
    progress = 0;
}
