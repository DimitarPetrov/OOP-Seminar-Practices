//
// Created by dimitar on 03.05.18.
//

#ifndef ANIMALS_ANIMAL_H
#define ANIMALS_ANIMAL_H

#include <iostream>
#include "Creature.h"


class Animal : public Creature {
private:
    char* region;
    char gender;
    double weight;
    int age;

    void Copy(const Animal& a);
    void Erase();

protected:
    void gainWeight(double amount);
    virtual void print(std::ostream& os) const;

public:
    Animal();
    Animal(const char* region, char gender, double weight, int age);
    Animal(const Animal& a);
    Animal& operator=(const Animal& a);
    char getGender() const;
    double getWeight() const;
    int getAge() const;
    const char* getRegion() const;
    virtual Creature* clone() const;
    virtual ~Animal();

    friend std::ostream& operator<<(std::ostream& os, const Animal& a);
};


#endif //ANIMALS_ANIMAL_H
