//
// Created by dimitar on 10.05.18.
//

#ifndef TICKETS_GROUPTICKET_H
#define TICKETS_GROUPTICKET_H

#include "Ticket.h"

class GroupTicket : public Ticket{

private:
    int groupSize;

    void print(std::ostream& os) const;
    void read(std::istream& is);

public:
    GroupTicket(const char* performance = nullptr, double price = 0, int groupSize = 0);
    int getGroupSize() const;

    friend std::ostream& operator<<(std::ostream& os, const GroupTicket& g);
    friend std::istream& operator>>(std::istream& is, GroupTicket& g);
};


#endif //TICKETS_GROUPTICKET_H
