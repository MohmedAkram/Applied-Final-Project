#include "Tickets.h"
#include <QDebug>

// Constructor implementation
Tickets::Tickets(int id, QString seat, QString movie, QString status, QString type)
    : ticketID(id), seatNumber(seat), movieName(movie), status(status), type(type), price(0.0) {
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

    qDebug() << "Ticket ID:" << ticketID;
    qDebug() << "Seat Number:" << seatNumber;
    qDebug() << "Movie:" << movieName;
    qDebug() << "Ticket Type:" << type;
    qDebug() << "Price: $" << price;
    qDebug() << "Status:" << status;
}

// Method to cancel the ticket
void Tickets::cancelTicket() {
    if (status == "Booked") {
        status = "Cancelled";
        qDebug() << "Ticket" << ticketID << "has been cancelled.";
    } else {
        qDebug() << "Ticket" << ticketID << "cannot be cancelled (status:" << status << ").";
    }
}

// Method to check if the ticket is already booked
void Tickets::checkTicketStatus() {
    if (status == "Booked") {
        qDebug() << "Ticket" << ticketID << "is already booked.";
    } else {
        qDebug() << "Ticket" << ticketID << "is not booked yet.";
    }
}
