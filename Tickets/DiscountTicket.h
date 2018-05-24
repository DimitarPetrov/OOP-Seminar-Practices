//
// Created by dimitar on 10.05.18.
//

#ifndef TICKETS_DISCOUNTTICKET_H
#define TICKETS_DISCOUNTTICKET_H

#include <iostream>
#include "Ticket.h"

class DiscountTicket : public Ticket {

private:
    char* name;

    void Copy(const DiscountTicket& d);
    void Erase();

    void print(std::ostream& os) const;
    void read(std::istream& is);


public:
    DiscountTicket(const char* performance = nullptr, double price = 0, const char* name = nullptr);
    DiscountTicket(const DiscountTicket& d);
    DiscountTicket& operator=(const DiscountTicket& d);
    const char* getName() const;
    ~DiscountTicket();

    friend std::ostream& operator<<(std::ostream& os, const DiscountTicket& d);
    friend std::istream& operator>>(std::istream& is, DiscountTicket& d);
};


#endif //TICKETS_DISCOUNTTICKET_H
