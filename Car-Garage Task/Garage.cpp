//
// Created by dimitar on 12.04.18.
//

#include <cstring>
#include <iostream>
#include "Garage.h"

void Garage::Copy(const Garage &g) {
    this->name = new char[strlen(g.name) + 1];
    strcpy(this->name, name);
    capacity = g.capacity;
    current = g.current;
    cars = new Car[capacity];
    for(int i = 0; i < current; ++i){
        cars[i] = g.cars[i];
    }
}

void Garage::Erase() {
    delete[] name;
    delete[] cars;
}

Garage::Garage() : name(nullptr), cars(nullptr), current(0), capacity(0) {}

Garage::Garage(const char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    capacity = 10;
    current = 0;
    cars = new Car[10];
}

Garage::Garage(const Garage &g) {
    Copy(g);
}

Garage &Garage::operator=(const Garage &g) {
    if(&g != this){
        Erase();
        Copy(g);
    }
    return *this;
}

void Garage::add(const Car &c) {
    if(current == capacity){
        resize();
    }
    cars[current] = c;
    ++current;
}

void Garage::remove(const Car &c) {
    for(int i = 0; i < current; ++i){
        if(!strcmp(cars[i].getSerialNumber(),c.getSerialNumber())){
            for(int j = i; j < current-1; ++j){
                cars[j] = cars[j+1];
            }
            break;
        }
    }
}

int Garage::getCurrent() const {
    return current;
}

Car Garage::getCar(int parkNumber) const {
    if(parkNumber < current){
        return cars[parkNumber];
    }
    std::cout << "Car with park number " << parkNumber << " not found!";
}

void Garage::print() const {
    for(int i = 0; i < current; ++i){
        cars[i].print();
    }
}

Garage::~Garage() {
    Erase();
}

void Garage::resize() {
    Car* tmp = cars;
    capacity *= 2;
    cars = new Car[capacity];
    for(int i = 0; i < current; ++i){
        cars[i] = tmp[i];
    }
    delete[] tmp;
}
