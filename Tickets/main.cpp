#include <iostream>
#include "Ticket.h"
#include "DiscountTicket.h"
#include "GroupTicket.h"

double getTicketsCost(Ticket* tickets, int n){
    double price;
    for(int i = 0; i < n; ++i){
        price += tickets[i].getPrice();
    }
    return price;
}

int main() {
    Ticket tickets[3];
    tickets[0] = Ticket("perf", 5);
    tickets[1] = DiscountTicket("perf", 7, "Pe6o");
    tickets[2] = GroupTicket("perf", 15, 5);
    std::cout << getTicketsCost(tickets,3);
    return 0;
}