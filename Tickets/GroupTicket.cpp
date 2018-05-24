//
// Created by dimitar on 10.05.18.
//

#include "GroupTicket.h"

void GroupTicket::print(std::ostream &os) const {
    Ticket::print(os);
    os << " " << groupSize;
}

void GroupTicket::read(std::istream &is) {
    Ticket::read(is);
    is >> groupSize;
    is.ignore();
    if(groupSize > 20) {
        setPrice(getPrice() - (groupSize - 20) * 2);
    }
    if(getPrice() < 0){
        setPrice(0);
    }
}

GroupTicket::GroupTicket(const char *performance, double price, int groupSize) : Ticket(performance, price), groupSize(groupSize) {
    if(groupSize > 20) {
        setPrice(getPrice() - (groupSize - 20) * 2);
    }
    if(getPrice() < 0){
        setPrice(0);
    }
}

int GroupTicket::getGroupSize() const {
    return groupSize;
}

std::ostream &operator<<(std::ostream &os, const GroupTicket &g) {
    g.print(os);
    return os;
}

std::istream &operator>>(std::istream &is, GroupTicket &g) {
    g.read(is);
    return is;
}
