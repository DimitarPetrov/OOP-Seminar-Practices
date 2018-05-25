//
// Created by dimitar on 24.05.18.
//

#include <cstring>
#include "Habitat.h"

void Habitat::Copy(const Habitat &h) {
    this->capacity = h.capacity;
    this->creatures = new Creature*[capacity];
    this->current = h.current;
    for(int i = 0; i < current; ++i){
        creatures[i] = h.creatures[i]->clone();
    }
}

void Habitat::Erase() {
    for(int i = 0; i < current; ++i){
        delete creatures[i];
    }
    delete[] creatures;
}

void Habitat::resize() {
    Creature** tmp = creatures;
    capacity *= 2;
    creatures = new Creature*[capacity];
    for(int i = 0; i < current; ++i){
        creatures[i] = tmp[i];
    }
    delete[] tmp;
}

void Habitat::print(std::ostream &os) const {
    for(int i = 0; i < current; ++i){
        os << i+1 << ". " << *creatures[i] << std::endl;
    }
}

Habitat::Habitat(int capacity) {
    this->capacity = capacity;
    creatures = new Creature*[capacity];
    current = 0;
}

Habitat::Habitat(const Habitat &h) {
    Copy(h);
}

Habitat &Habitat::operator=(const Habitat &h) {
    if(this != &h){
        Erase();
        Copy(h);
    }
    return *this;
}

void Habitat::add(Creature *c) {
    if(current == capacity){
        resize();
    }
    creatures[current] = c->clone();
    ++current;
}

Habitat::~Habitat() {
    Erase();
}

std::ostream &operator<<(std::ostream &os, const Habitat &h) {
    h.print(os);
    return os;
}
