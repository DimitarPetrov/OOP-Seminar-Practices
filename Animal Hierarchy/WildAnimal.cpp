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

DomesticAnimal WildAnimal::tame(const char* name) const {
    if(dangerRating < 5){
        return DomesticAnimal(getRegion(), getGender(), getWeight(), getAge(), name);
    }
    std::cout << "Too dangerous!" << std::endl;
    return DomesticAnimal();
}

std::ostream &operator<<(std::ostream &os, const WildAnimal &wa) {
    wa.print(os);
    return os;
}
