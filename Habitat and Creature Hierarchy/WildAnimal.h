//
// Created by dimitar on 03.05.18.
//

#ifndef ANIMALS_WILDANIMAL_H
#define ANIMALS_WILDANIMAL_H


#include "Animal.h"
#include "DomesticAnimal.h"

class WildAnimal : public Animal{

private:
    double dangerRating;

    virtual void print(std::ostream& os) const;

public:

    WildAnimal();
    WildAnimal(const char* region, char gender, double weight, int age, double dangerRating);
    DomesticAnimal tame(const char* name) const;
    friend std::ostream& operator<<(std::ostream& os, const WildAnimal& wa);
    virtual Creature* clone() const;

};


#endif //ANIMALS_WILDANIMAL_H
