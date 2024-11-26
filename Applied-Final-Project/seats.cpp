#include "seats.h"
#include <QVBoxLayout>
#include <QMessageBox>

Seats::Seats(QWidget *parent)
    : QWidget(parent), totalPrice(0.0), regularPrice(50.0), vipPrice(100.0)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this); // Main vertical layout

    // Add the cinema screen at the top
    QLabel *cinemaScreen = new QLabel(this);
    cinemaScreen->setStyleSheet("background-color: black; border: 2px solid white; color: white; font-size: 20px;");
    cinemaScreen->setText("Cinema Screen");
    cinemaScreen->setAlignment(Qt::AlignCenter);
    cinemaScreen->setFixedHeight(100); // Height of the cinema screen
    mainLayout->addWidget(cinemaScreen, 0, Qt::AlignTop);

    // Create the grid layout for seat buttons
    seatLayout = new QGridLayout();
    seatLayout->setHorizontalSpacing(20); // Space between columns
    seatLayout->setVerticalSpacing(20);   // Space between rows

    // Example: Define which seats are VIP (true for VIP, false for regular)
    QVector<bool> vipSeats = {
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        true, true, true, true, true, true, true, true, true, true,
        true, true, true, true, true, true, true, true, true, true
    };

    // Create seats (e.g., 4 rows x 10 columns)
    createSeats(4, 10, vipSeats);

    // Wrap the seat layout in a container for better alignment
    QWidget *seatContainer = new QWidget(this);
    seatContainer->setLayout(seatLayout);
    mainLayout->addWidget(seatContainer, 0, Qt::AlignHCenter); // Center the seat container

    // Labels for selected seats and total price
    selectedSeatsLabel = new QLabel("Selected Seats: None");
    totalPriceLabel = new QLabel("Total Price: $0.00");
    selectedSeatsLabel->setStyleSheet("font-size: 16px;");
    totalPriceLabel->setStyleSheet("font-size: 16px;");
    mainLayout->addWidget(selectedSeatsLabel, 0, Qt::AlignHCenter);
    mainLayout->addWidget(totalPriceLabel, 0, Qt::AlignHCenter);

    // Confirm booking button
    QPushButton *confirmButton = new QPushButton("Confirm Booking");
    confirmButton->setStyleSheet("font-size: 16px; padding: 8px 16px;");
    mainLayout->addWidget(confirmButton, 0, Qt::AlignHCenter);

    // Connect the confirm button signal
    connect(confirmButton, &QPushButton::clicked, this, &Seats::confirmBooking);

    // Set the main layout for the widget
    setLayout(mainLayout);
}

Seats::~Seats() {}

void Seats::createSeats(int rows, int cols, QVector<bool> vipSeats)
{
    int seatID = 1;
    int vipIndex = 0;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            QPushButton *seatButton = new QPushButton(QString::number(seatID));
            seatButton->setFixedSize(36, 36); // Reduced size for compact spacing

            // Determine if the seat is VIP or regular
            bool isVip = vipSeats[vipIndex++];
            if (isVip) {
                seatButton->setStyleSheet(
                    "background-color: blue; color: white;"
                    "margin: 2px;"   // Reduced margin
                    "padding: 0px;" // No padding for compact look
                    );
            } else {
                seatButton->setStyleSheet(
                    "background-color: green; color: white;"
                    "margin: 2px;"   // Reduced margin
                    "padding: 0px;" // No padding for compact look
                    );
            }

            // Connect button to slot
            connect(seatButton, &QPushButton::clicked, this, &Seats::onSeatClicked);

            // Add button to layout and vector
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

    // Determine seat type based on color
    bool isVip = button->styleSheet().contains("blue");

    // Toggle selection
    if (button->styleSheet().contains("green") || button->styleSheet().contains("blue")) {
        // Available seat becomes selected
        button->setStyleSheet(isVip ? "background-color: cyan; color: black;" // VIP selected
                                    : "background-color: yellow; color: black;"); // Regular selected
        selectedSeats.append(seatNumber);
        totalPrice += isVip ? vipPrice : regularPrice;
    } else if (button->styleSheet().contains("yellow") || button->styleSheet().contains("cyan")) {
        // Selected seat becomes available
        button->setStyleSheet(isVip ? "background-color: blue; color: white;" // VIP available
                                    : "background-color: green; color: white;"); // Regular available
        selectedSeats.removeOne(seatNumber);
        totalPrice -= isVip ? vipPrice : regularPrice;
    }

    // Update labels
    selectedSeatsLabel->setText("Selected Seats: " + selectedSeats.join(", "));
    totalPriceLabel->setText(QString("Total Price: $%1").arg(totalPrice, 0, 'f', 2));
}

void Seats::confirmBooking()
{
    if (selectedSeats.isEmpty()) {
        QMessageBox::warning(this, "No Seats Selected", "Please select at least one seat.");
        return;
    }

    QMessageBox::information(this, "Booking Confirmed",
                             QString("You have booked the following seats:\n%1\nTotal Price: $%2")
                                 .arg(selectedSeats.join(", "))
                                 .arg(totalPrice, 0, 'f', 2));

    // Mark seats as booked and reset selection
    for (auto *button : seatButtons) {
        if (button->styleSheet().contains("yellow") || button->styleSheet().contains("cyan")) {
            button->setStyleSheet(button->styleSheet().contains("cyan")
                                  ? "background-color: darkred; color: white;" // VIP booked
                                  : "background-color: red; color: white;"); // Regular booked
            button->setEnabled(false); // Disable booked seat
        }
    }

    selectedSeats.clear();
    totalPrice = 0.0;
    selectedSeatsLabel->setText("Selected Seats: None");
    totalPriceLabel->setText("Total Price: $0.00");
}
