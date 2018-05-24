//
// Created by dimitar on 10.05.18.
//

#include <cstring>
#include "DiscountTicket.h"

void DiscountTicket::Copy(const DiscountTicket &d) {
    this->name = new char[strlen(d.name) + 1];
    strcpy(this->name, d.name);
}

void DiscountTicket::Erase() {
    delete[] name;
}

void DiscountTicket::print(std::ostream &os) const {
    Ticket::print(os);
    os << " " << name;
}

void DiscountTicket::read(std::istream &is) {
    Ticket::read(is);
    if(name != nullptr){
        return;
    }
    char buffer[1024];
    is.getline(buffer,1024);
    name = new char[strlen(buffer) + 1];
    strcpy(name, buffer);
    setPrice(getPrice()/2);
}

DiscountTicket::DiscountTicket(const char *performance, double price, const char *name) : Ticket(performance,price){
    if(name == nullptr){
        this->name = nullptr;
    } else {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        setPrice(getPrice()/2);
    }
}

DiscountTicket::DiscountTicket(const DiscountTicket &d) : Ticket(d) {
    Copy(d);
}

DiscountTicket &DiscountTicket::operator=(const DiscountTicket &d) {
    if(this != &d){
        Ticket::operator=(d);
        Erase();
        Copy(d);
    }
    return *this;
}

const char *DiscountTicket::getName() const {
    return name;
}

DiscountTicket::~DiscountTicket() {
    Erase();
}

std::ostream &operator<<(std::ostream &os, const DiscountTicket &d) {
    d.print(os);
    return os;
}

std::istream &operator>>(std::istream &is, DiscountTicket &d) {
    d.read(is);
    return is;
}
