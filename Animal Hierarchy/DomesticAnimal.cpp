//
// Created by dimitar on 03.05.18.
//

#include <cstring>
#include <iostream>
#include "DomesticAnimal.h"

void DomesticAnimal::Copy(const DomesticAnimal &da) {
    this->name = new char[strlen(da.name) + 1];
    strcpy(name, da.name);
}

void DomesticAnimal::Erase() {
    delete[] name;
}

DomesticAnimal::DomesticAnimal() : Animal(), name(nullptr) {}

DomesticAnimal::DomesticAnimal(const char *region, char gender, double weight, int age, const char *name) :
                                                                        Animal(region,gender,weight,age){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

DomesticAnimal::DomesticAnimal(const DomesticAnimal &da) : Animal(da) {
    Copy(da);
}

DomesticAnimal &DomesticAnimal::operator=(const DomesticAnimal &da) {
    if(this != &da){
        Animal::operator=(da);
        Erase();
        Copy(da);
    }
    return *this;
}

void DomesticAnimal::feed() {
    if(getWeight() < 10){
        gainWeight(1);
    } else {
        std::cout << "Too fat!";
    }
}

DomesticAnimal::~DomesticAnimal() {
    Erase();
}

void DomesticAnimal::print(std::ostream &os) const {
    Animal::print(os);
    os << " " <<  name;
}

std::ostream &operator<<(std::ostream &os, const DomesticAnimal &da) {
    da.print(os);
    return os;
}
