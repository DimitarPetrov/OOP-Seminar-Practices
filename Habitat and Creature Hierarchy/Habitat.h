//
// Created by dimitar on 24.05.18.
//

#ifndef ANIMALS_HABITAT_H
#define ANIMALS_HABITAT_H


#include "Creature.h"

class Habitat {

private:
    Creature** creatures;
    int capacity;
    int current;

    void Copy(const Habitat& h);
    void Erase();

    void resize();

    void print(std::ostream& os) const;

public:
    Habitat(int capacity = 10);
    Habitat(const Habitat& h);
    Habitat& operator=(const Habitat& h);
    void add(Creature* c);
    ~Habitat();

    friend std::ostream& operator<<(std::ostream& os, const Habitat& h);
};


#endif //ANIMALS_HABITAT_H
