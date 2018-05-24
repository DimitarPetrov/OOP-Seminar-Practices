//
// Created by dimitar on 10.05.18.
//

#include <cstring>
#include "Ticket.h"

void Ticket::Copy(const Ticket &t) {
    this->performance = new char[strlen(t.performance) + 1];
    strcpy(this->performance, t.performance);
    this->price = t.price;
}

void Ticket::Erase() {
    delete[] performance;
}

void Ticket::print(std::ostream &os) const{
    os << performance << " " << price;
}

void Ticket::read(std::istream &is) {
    if(performance != nullptr){
        return;
    }
    char buffer[1024];
    is.getline(buffer,1024);
    performance = new char[strlen(buffer) + 1];
    strcpy(performance,buffer);
    is >> price;
    is.ignore();
}

Ticket::Ticket(const char *performance, double price) : price(price) {
    if(performance == nullptr){
        this->performance = nullptr;
    } else {
        this->performance = new char[strlen(performance) + 1];
        strcpy(this->performance, performance);
    }
}

Ticket::Ticket(const Ticket &t) {
    Copy(t);
}

Ticket &Ticket::operator=(const Ticket &t) {
    if(this != &t){
        Erase();
        Copy(t);
    }
    return *this;
}

const char *Ticket::getPerformance() const {
    return performance;
}

double Ticket::getPrice() const {
    return price;
}

Ticket::~Ticket() {
    Erase();
}

std::ostream &operator<<(std::ostream &os, const Ticket &t) {
    t.print(os);
    return os;
}

std::istream &operator>>(std::istream &is, Ticket &t) {
    t.read(is);
    return is;
}

void Ticket::setPrice(double price) {
    this->price = price;
}
