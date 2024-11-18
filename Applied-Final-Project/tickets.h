#ifndef TICKETS_H
#define TICKETS_H

#include <string>
using namespace std;

class Tickets {
private:
    int ticketID;
    string seatNumber;
    double price;
    string status;

public:
    Tickets();
    Tickets(int id);
    Tickets(int id, string seat, double price, string status);

    void generateTicketDetails();
    void cancelTicket();
    void validateTicket();
};

#endif // TICKETS_H
