//
// Created by dimitar on 03.05.18.
//

#include "WildAnimal.h"

WildAnimal::WildAnimal() : Animal(), dangerRating(0) {}

WildAnimal::WildAnimal(const char *region, char gender, double weight, int age, double dangerRating) :
                    Animal(region, gender,weight,age), dangerRating(dangerRating){}

void WildAnimal::print(std::ostream &os) const {
    Animal::print(os);
    os << " " << dangerRating;
}

bool WildAnimal::tameable() {
    return dangerRating < 5;
}

std::ostream &operator<<(std::ostream &os, const WildAnimal &wa) {
    wa.print(os);
    return os;
}
