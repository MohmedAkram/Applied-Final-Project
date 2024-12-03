#ifndef TICKETS_H
#define TICKETS_H

#include <QString> // Include for QString (Qt)
using namespace std;

class Tickets {
public:
    int seatNumber;
    double price;
    bool status;
    int movieNum;  // Added movieName variable
    bool type;       // Added type variable

    Tickets();  // Default constructor
    Tickets(int seat, int movie, bool status, bool type); // Updated constructor

    double calculateTicketPrice();  // Method to calculate ticket price
    void generateTicketDetails();  // Method to generate ticket details
    void cancelTicket();           // Method to cancel the ticket
    void checkTicketStatus();      // Method to check ticket status
};

#endif // TICKETS_H
