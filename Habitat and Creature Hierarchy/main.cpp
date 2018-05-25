#include <iostream>
#include "DomesticAnimal.h"
#include "WildAnimal.h"
#include "Habitat.h"

int main() {
    Creature* arr[3];
    arr[0] = new Animal("savana", 'm', 100, 5);
    arr[1] = new DomesticAnimal("Sofia", 'm', 5, 12, "ivan");
    arr[2] = new WildAnimal("savana", 'm', 41,5,4);
    Habitat h(1);
    for(int i = 0; i < 3; ++i){
        h.add(arr[i]);
    }
    std::cout << h << std::endl;
    Habitat g = h;
    std::cout << g << std::endl;
    Habitat l;
    l = g;
    std::cout << l << std::endl;
    return 0;
}