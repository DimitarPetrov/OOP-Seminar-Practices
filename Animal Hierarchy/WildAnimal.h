//
// Created by dimitar on 03.05.18.
//

#ifndef ANIMALS_WILDANIMAL_H
#define ANIMALS_WILDANIMAL_H


#include "Animal.h"

class WildAnimal : public Animal {

private:
    double dangerRating;
public:
    WildAnimal();
    WildAnimal(const char* region, char gender, double weight, int age, double dangerRating);
    void print(std::ostream& os) const;
    bool tameable();
    friend std::ostream& operator<<(std::ostream& os, const WildAnimal& wa);

};


#endif //ANIMALS_WILDANIMAL_H
