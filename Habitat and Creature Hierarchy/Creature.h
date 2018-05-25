//
// Created by dimitar on 24.05.18.
//

#ifndef ANIMALS_CREATURE_H
#define ANIMALS_CREATURE_H

#include <iostream>

class Creature {

public:
    virtual void print(std::ostream& os) const = 0;
    virtual Creature* clone() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Creature& c) {
        c.print(os);
        return os;
    }
};


#endif //ANIMALS_CREATURE_H
