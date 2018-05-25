//
// Created by dimitar on 03.05.18.
//

#include <cstring>
#include "Animal.h"

void Animal::Copy(const Animal &a) {
    this->region = new char[strlen(a.region) + 1];
    strcpy(region, a.region);
    gender = a.gender;
    weight = a.weight;
    age = a.age;
}

void Animal::Erase() {
    delete[] region;
}

Animal::Animal(const char *region, char gender, double weight, int age) : gender(gender), weight(weight), age(age) {
    this->region = new char[strlen(region) + 1];
    strcpy(this->region,region);
}

Animal::Animal(const Animal &a) {
    Copy(a);
}

Animal &Animal::operator=(const Animal &a) {
    if(this != &a){
        Erase();
        Copy(a);
    }
    return *this;
}

char Animal::getGender() const {
    return gender;
}

double Animal::getWeight() const {
    return weight;
}

int Animal::getAge() const {
    return age;
}

const char *Animal::getRegion() const {
    return region;
}

void Animal::gainWeight(double amount) {
    weight += amount;
}

Animal::~Animal() {
    Erase();
}

void Animal::print(std::ostream &os) const {
    os << region << " " << gender << " " << weight << " " << age;
}

std::ostream &operator<<(std::ostream &os, const Animal &a) {
    a.print(os);
    return os;
}

Animal::Animal() : region(nullptr) , gender('?'), weight(0), age(0) {}

Creature *Animal::clone() const {
    return new Animal(*this);
}
