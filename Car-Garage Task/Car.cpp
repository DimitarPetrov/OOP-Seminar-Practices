//
// Created by dimitar on 12.04.18.
//

#include <cstring>
#include <iostream>
#include "Car.h"

void Car::Copy(const Car &c) {
    model = new char[strlen(c.model) + 1];
    strcpy(model, c.model);
    maxSpeed = c.maxSpeed;
    year = c.year;
    serialNumber = new char[strlen(c.serialNumber) + 1];
    stpcpy(serialNumber, c.serialNumber);
}

void Car::Erase() {
    delete[] model;
    delete[] serialNumber;
}

Car::Car() : model(nullptr), maxSpeed(0), year(0), serialNumber(nullptr) {}

Car::Car(const char *model, int maxSpeed, int year, const char *serialNumber) : maxSpeed(maxSpeed), year(year) {
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
    this->serialNumber = new char[strlen(serialNumber) + 1];
    strcpy(this->serialNumber, serialNumber);
}

Car::Car(const Car &c) {
    Copy(c);
}

Car &Car::operator=(const Car &c) {
    if(&c != this){
        Erase();
        Copy(c);
    }
    return *this;
}

const char *Car::getModel() const {
    return model;
}

int Car::getMaxSpeed() const {
    return maxSpeed;
}

int Car::getYear() const {
    return year;
}

const char *Car::getSerialNumber() const {
    return serialNumber;
}

int Car::comparator(const Car &c) const {
    return maxSpeed - c.maxSpeed;
}

void Car::print() const {
    std::cout << model << " " << maxSpeed << " " << year << " " << serialNumber << std::endl;
}

void Car::read() {
    if(model != nullptr){
        std::cout << "Already constructed valid vehicle!";
        return;
    }
    char buffer[1024];
    std::cin.getline(buffer, 1024);
    model = new char[strlen(buffer) + 1];
    strcpy(model, buffer);
    std::cin >> maxSpeed;
    std::cin >> year;
    std::cin.ignore();
    std::cin.getline(buffer, 1024);
    serialNumber = new char[strlen(buffer) + 1];
    strcpy(serialNumber, buffer);
}

Car::~Car() {
    Erase();

}
