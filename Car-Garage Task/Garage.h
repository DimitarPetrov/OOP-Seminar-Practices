//
// Created by dimitar on 12.04.18.
//

#ifndef CARANDGARAGE_GARAGE_H
#define CARANDGARAGE_GARAGE_H


#include "Car.h"

class Garage {

private:
    char* name;
    Car* cars;
    int capacity;
    int current;

    void Copy(const Garage& g);
    void Erase();
    void resize();

public:
    Garage();
    Garage(const char* name);
    Garage(const Garage& g);
    Garage& operator=(const Garage& g);
    void add(const Car& c);
    void remove(const Car& c);
    int getCurrent() const;
    Car getCar(int parkNumber) const;
    void print() const;
    ~Garage();
};


#endif //CARANDGARAGE_GARAGE_H
