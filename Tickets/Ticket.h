//
// Created by dimitar on 10.05.18.
//

#ifndef TICKETS_TICKET_H
#define TICKETS_TICKET_H

#include <iostream>

class Ticket {

private:
    char* performance;
    double price;

    void Copy(const Ticket& t);
    void Erase();

protected:

    void print(std::ostream& os) const;
    void read(std::istream& is);

public:
    Ticket(const char* performance = nullptr, double price = 0);
    Ticket(const Ticket& t);
    Ticket& operator=(const Ticket& t);
    const char* getPerformance() const;
    double getPrice() const;
    void setPrice(double price);
    ~Ticket();

    friend std::ostream& operator<<(std::ostream& os, const Ticket& t);
    friend std::istream& operator>>(std::istream& is, Ticket& t);
};


#endif //TICKETS_TICKET_H
