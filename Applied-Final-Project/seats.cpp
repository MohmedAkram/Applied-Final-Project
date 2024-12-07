
#include "seats.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include "confirmbook.h"
#include "system.h"


void Seats::confirmBooking(Customer* Cu, Events* Ev,Seats* S)
{
    if (selectedSeats.isEmpty()) {
        QMessageBox::warning(this, "No Seats Selected", "Please select at least one seat.");
        return;
    }

    // Show the confirmation window
    ConfirmBook* confirm = new ConfirmBook(Ev, Cu,S, this);
    confirm->setAttribute(Qt::WA_DeleteOnClose);
    confirm->show();
    confirm->raise();
    confirm->activateWindow();

    // Mark selected seats as booked
    for (auto* button : seatButtons) {
        if (button->styleSheet().contains("cyan") || button->styleSheet().contains("blue")) {
            button->setStyleSheet(button->styleSheet().contains("cyan")
                                      ? "background-color: red; color: white;"
                                      : "background-color: red; color: white;");
            button->setEnabled(false);  // Disable the button (seat is booked)
        }
    }

    // Reset selection and UI
    totalPrice = 0.0;
    selectedSeatsLabel->setText("Selected Seats: " + QString::number(selectedSeats.size()));
    totalPriceLabel->setText("Total Price: $" + QString::number(totalPrice));
    S->close();


    qDebug() << "Seat selection reset and UI updated.";
}

Seats::Seats(Customer* customer, Events* EV, int time, QWidget* parent)
    : QWidget(parent), C(customer), E(EV), totalPrice(0.0), regularPrice(50.0), vipPrice(100.0)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    Time =time;
    QLabel* cinemaScreen = new QLabel("Cinema Screen", this);
    cinemaScreen->setStyleSheet("background-color: black; border: 2px solid white; color: white; font-size: 20px;");
    cinemaScreen->setAlignment(Qt::AlignCenter);
    cinemaScreen->setFixedHeight(70);
    mainLayout->addWidget(cinemaScreen, 0, Qt::AlignTop);

    seatLayout = new QGridLayout();
    seatLayout->setHorizontalSpacing(20);
    seatLayout->setVerticalSpacing(20);

    createSeats(4, 10, time);

    QWidget* seatContainer = new QWidget(this);
    seatContainer->setLayout(seatLayout);
    mainLayout->addWidget(seatContainer, 0, Qt::AlignHCenter);

    selectedSeatsLabel = new QLabel("Selected Seats: None", this);
    totalPriceLabel = new QLabel("Total Price: $0.00", this);
    selectedSeatsLabel->setStyleSheet("font-size: 16px;");
    totalPriceLabel->setStyleSheet("font-size: 16px;");
    mainLayout->addWidget(selectedSeatsLabel, 0, Qt::AlignHCenter);
    mainLayout->addWidget(totalPriceLabel, 0, Qt::AlignHCenter);

    QPushButton* confirmButton = new QPushButton("Confirm Booking", this);
    confirmButton->setStyleSheet("font-size: 16px; padding: 8px 16px;");
    mainLayout->addWidget(confirmButton, 0, Qt::AlignHCenter);

    connect(confirmButton, &QPushButton::clicked, this, [this]() {
        qDebug() << "Confirm button clicked.";
        this->confirmBooking(C, E,this);
    });

    setLayout(mainLayout);
    qDebug() << "Seats widget initialized.";
}

Seats::~Seats() {}

void Seats::createSeats(int rows, int cols, int Time)
{
    int seatID = 1;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            QPushButton *seatButton = new QPushButton(QString::number(seatID));
            seatButton->setFixedSize(36, 36);

            int seatNumber = seatID;

            bool isVip = sys.TDB[E->getEventID()-1][Time][seatID-1]->type;
            bool booked = sys.TDB[E->getEventID()-1][Time][seatID-1]->status;
            seatButton->setObjectName(isVip ? "vip" : "regular");

            if (isVip && !booked) {
                seatButton->setStyleSheet(
                    "background-color: gold; color: white; margin: 2px; padding: 0px;"); // Gold for VIP and Not Booked
            } else if (!isVip && !booked) {
                seatButton->setStyleSheet(
                    "background-color: gray; color: black; margin: 2px; padding: 0px;"); // Light Gray for Regular and Not Booked
            } else if (isVip && booked) {
                seatButton->setStyleSheet(
                    "background-color: red; color: white; margin: 2px; padding: 0px;"); // Red for VIP and Booked
            } else if (!isVip && booked) {
                seatButton->setStyleSheet(
                    "background-color: red; color: white; margin: 2px; padding: 0px;"); // Red for Regular and Booked
            }
            connect(seatButton, &QPushButton::clicked, this, &Seats::onSeatClicked);

            seatLayout->addWidget(seatButton, row, col);
            seatButtons.push_back(seatButton);

            ++seatID;
        }
    }
}

void Seats::onSeatClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    // Convert the seat number to integer
    int seatNumber = button->text().toInt();

    // Check if the seat is VIP or booked
    bool isVip = sys.TDB[E->getEventID()-1][Time][seatNumber-1]->type;


    // Prevent selecting booked seats
    if (button->styleSheet().contains("red")) {
        QMessageBox::warning(this, "Seat already booked", "Please choose untaken seats first.");
        return;
    }

    // Handle seat selection/deselection
    if (selectedSeats.contains(seatNumber)) {  // Check if the seat is already selected
        selectedSeats.removeOne(seatNumber);  // Deselect the seat
        if (C->IsVIP){
            totalPrice -= isVip ? vipPrice*0.8 : regularPrice*0.8;}
        else{totalPrice -= isVip ? vipPrice : regularPrice;}
        button->setStyleSheet(isVip ? "background-color: gold; color: white;" : "background-color: gray; color: black;");
    } else {  // Select the seat
        selectedSeats.append(seatNumber);  // Add the seat to the selected seats vector
        if (C->IsVIP){
            totalPrice += isVip ? vipPrice*0.8 : regularPrice*0.8;}
        else{totalPrice += isVip ? vipPrice : regularPrice;}
        button->setStyleSheet(isVip ? "background-color: cyan; color: black;" : "background-color: blue; color: black;");
    }

    // Update the UI for total price and selected seats
    selectedSeatsLabel->setText("Selected Seats: " + QString::number(selectedSeats.size()));
    totalPriceLabel->setText("Total Price: $" + QString::number(totalPrice));
}
