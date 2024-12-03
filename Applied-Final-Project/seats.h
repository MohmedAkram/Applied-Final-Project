#ifndef SEATS_H
#define SEATS_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QVector>
#include "customer.h"
#include "events.h"


class Seats : public QWidget
{
    Q_OBJECT

public:
    Seats(Customer* Cu, Events* Ev, int time, QWidget* parent = nullptr);
    Customer * C;
    Events *E;
    ~Seats();
    int Time;
private slots:
    void onSeatClicked();  // Slot to handle seat selection
    void confirmBooking(Customer* Cu,Events* Ev,Seats* S); // Slot to confirm booking

public:
    QGridLayout *seatLayout;  // Layout for seats
    QLabel *selectedSeatsLabel; // Label to display selected seats
    QLabel *totalPriceLabel; // Label to display total price
    QVector<QPushButton*> seatButtons; // Vector of seat buttons
    QVector<int> selectedSeats; // Vector of selected seat IDs
    double totalPrice; // Total price for selected seats
    double regularPrice; // Price for regular seats
    double vipPrice; // Price for VIP seats

    void createSeats(int rows, int cols, int Time); // Dynamically create seats
};

#endif // SEATS_H
