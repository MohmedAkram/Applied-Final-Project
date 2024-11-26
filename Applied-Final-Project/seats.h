#ifndef SEATS_H
#define SEATS_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QVector>

class Seats : public QWidget
{
    Q_OBJECT

public:
    Seats(QWidget *parent = nullptr);
    ~Seats();

private slots:
    void onSeatClicked();  // Slot to handle seat selection
    void confirmBooking(); // Slot to confirm booking

private:
    QGridLayout *seatLayout;  // Layout for seats
    QLabel *selectedSeatsLabel; // Label to display selected seats
    QLabel *totalPriceLabel; // Label to display total price
    QVector<QPushButton*> seatButtons; // Vector of seat buttons
    QVector<QString> selectedSeats; // Vector of selected seat IDs
    double totalPrice; // Total price for selected seats

    double regularPrice; // Price for regular seats
    double vipPrice; // Price for VIP seats

    void createSeats(int rows, int cols, QVector<bool> vipSeats); // Dynamically create seats
};

#endif // SEATS_H
