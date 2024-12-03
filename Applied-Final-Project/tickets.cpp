#include "Tickets.h"
#include <QDebug>

// Constructor implementation
Tickets::Tickets(int seat, int movie, bool status, bool type)
    : seatNumber(seat), movieNum (movie), price(0.0), type(type), status(status) {
    // Price is not initialized yet
}

// Method to calculate ticket price
double Tickets::calculateTicketPrice() {
    // Placeholder for calculation logic
    return 50.0; // Example static price
}

// Method to generate ticket details
void Tickets::generateTicketDetails() {
    price = calculateTicketPrice();  // Calculate price only when generating details

    qDebug() << "Seat Number:" << seatNumber;
    qDebug() << "Ticket Type:" << type;
    qDebug() << "Price: $" << price;
    qDebug() << "Status:" << status;
}
//
// Method to cancel the ticket
void Tickets::cancelTicket() {
    if (status == true) {
        status = false;
        qDebug() << "Ticket" << seatNumber << "has been cancelled.";
    } else {
        qDebug() << "Ticket" << seatNumber << "cannot be cancelled (status:" << status << ").";
    }
}

// Method to check if the ticket is already booked
void Tickets::checkTicketStatus() {
    if (status == true) {
        qDebug() << "Ticket" << seatNumber << "is already booked.";
    } else {
        qDebug() << "Ticket" << seatNumber << "is not booked yet.";
    }
}
