#include <iostream>
#include "Car.h"
#include "Garage.h"

void sort(Car* cars, int n){
    for(int i = 0; i < n-1; ++i){
        for(int j = 0; j < n-i-1; ++j){
            if(cars[j].getMaxSpeed() > cars[j+1].getMaxSpeed()){
                std::swap(cars[j],cars[j+1]);
            }
        }
    }
}


int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    Car* cars = new Car[n];
    for(int i = 0; i < n; ++i){
        cars[i].read();
    }
    sort(cars,n);
    Garage fast("fast");
    Garage slow("slow");
    for(int i = 0; i < n/2; ++i){
        slow.add(cars[i]);
    }
    for(int i = n/2; i < n; ++i){
        fast.add(cars[i]);
    }
    std::cout << "Fast cars are: " << std::endl;
    fast.print();
    std::cout << "Slow cars are: " << std::endl;
    slow.print();
    Garage old("old");
    for(int i = 0; i < fast.getCurrent(); ++i){
        Car tmp = fast.getCar(i);
        if (tmp.getYear() < 2005) {
            fast.remove(tmp);
            old.add(tmp);
        }
    }
    std::cout << "Old and fast cars are: " << std::endl;
    old.print();
    return 0;
}