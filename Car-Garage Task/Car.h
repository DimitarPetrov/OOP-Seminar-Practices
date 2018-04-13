//
// Created by dimitar on 12.04.18.
//

#ifndef CARANDGARAGE_CAR_H
#define CARANDGARAGE_CAR_H


class Car {

private:
    char* model;
    int maxSpeed;
    int year;
    char* serialNumber;

    void Copy(const Car& c);
    void Erase();

public:
    Car();
    Car(const char* model, int maxSpeed, int year, const char* serialNumber);
    Car(const Car& c);
    Car& operator=(const Car& c);
    const char* getModel() const;
    int getMaxSpeed() const;
    int getYear() const;
    const char* getSerialNumber() const;
    int comparator(const Car& c) const;
    void print() const;
    void read();
    ~Car();

};


#endif //CARANDGARAGE_CAR_H
