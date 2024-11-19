#ifndef TICKETS_H
#define TICKETS_H

#include <QString> // Include for QString (Qt)
using namespace std;

class Tickets {
private:
    int ticketID;
    QString seatNumber;
    double price;
    QString status;
    QString movieName;  // Added movieName variable
    QString type;       // Added type variable

public:
    Tickets();  // Default constructor
    Tickets(int id); // Constructor with ID
    Tickets(int id, QString seat, QString movie, QString status, QString type); // Updated constructor

    double calculateTicketPrice();  // Method to calculate ticket price
    void generateTicketDetails();  // Method to generate ticket details
    void cancelTicket();           // Method to cancel the ticket
    void checkTicketStatus();      // Method to check ticket status
};

#endif // TICKETS_H
