
#include "seats.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include "confirmbook.h"


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
        if (button->styleSheet().contains("yellow") || button->styleSheet().contains("cyan")) {
            button->setStyleSheet(button->styleSheet().contains("cyan")
                                  ? "background-color: darkred; color: white;"
                                  : "background-color: red; color: white;");
            button->setEnabled(false);
        }
    }

    // Reset selection and UI
    selectedSeats.clear();
    totalPrice = 0.0;
    selectedSeatsLabel->setText("Selected Seats: None");
    totalPriceLabel->setText("Total Price: $0.00");

    qDebug() << "Seat selection reset and UI updated.";
}

Seats::Seats(Customer* customer, Events* EV, QWidget* parent)
    : QWidget(parent), C(customer), E(EV), totalPrice(0.0), regularPrice(50.0), vipPrice(100.0)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QLabel* cinemaScreen = new QLabel("Cinema Screen", this);
    cinemaScreen->setStyleSheet("background-color: black; border: 2px solid white; color: white; font-size: 20px;");
    cinemaScreen->setAlignment(Qt::AlignCenter);
    cinemaScreen->setFixedHeight(70);
    mainLayout->addWidget(cinemaScreen, 0, Qt::AlignTop);

    seatLayout = new QGridLayout();
    seatLayout->setHorizontalSpacing(20);
    seatLayout->setVerticalSpacing(20);


    QVector<bool> vipSeats = {
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        true, true, true, true, true, true, true, true, true, true,
        true, true, true, true, true, true, true, true, true, true
    };

    createSeats(4, 10, vipSeats);

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

void Seats::createSeats(int rows, int cols, QVector<bool> vipSeats)
{
    int seatID = 1;
    int vipIndex = 0;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            QPushButton *seatButton = new QPushButton(QString::number(seatID));
            seatButton->setFixedSize(36, 36);

            bool isVip = vipSeats[vipIndex++];
            seatButton->setObjectName(isVip ? "vip" : "regular");

            seatButton->setStyleSheet(isVip
                                          ? "background-color: blue; color: white; margin: 2px; padding: 0px;"
                                          : "background-color: green; color: white; margin: 2px; padding: 0px;");

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

    QString seatNumber = button->text();
    bool isVip = (button->objectName() == "vip");

    if (button->styleSheet().contains("green") || button->styleSheet().contains("blue")) {
        button->setStyleSheet(isVip ? "background-color: cyan; color: black;" : "background-color: yellow; color: black;");
        selectedSeats.append(seatNumber);
        totalPrice += isVip ? vipPrice : regularPrice;
    } else if (button->styleSheet().contains("yellow") || button->styleSheet().contains("cyan")) {
        button->setStyleSheet(isVip ? "background-color: blue; color: white;" : "background-color: green; color: white;");
        selectedSeats.removeOne(seatNumber);
        totalPrice -= isVip ? vipPrice : regularPrice;
    }

    selectedSeatsLabel->setText("Selected Seats: " + selectedSeats.join(", "));
    totalPriceLabel->setText(QString("Total Price: $%1").arg(totalPrice, 0, 'f', 2));

    qDebug() << "Updated selected seats:" << selectedSeats;
    qDebug() << "Updated total price:" << totalPrice;
}
