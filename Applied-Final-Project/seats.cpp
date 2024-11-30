#include "seats.h"
#include <QVBoxLayout>
#include <QMessageBox>

Seats::Seats(QWidget *parent) // Constructor for the Seats class

    : QWidget(parent), totalPrice(0.0), regularPrice(50.0), vipPrice(100.0) // initializng the prices of diff types of setas
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this); // Main vertical layout

    // Add the cinema screen at the top
    QLabel *cinemaScreen = new QLabel(this);
    cinemaScreen->setStyleSheet("background-color: black; border: 2px solid white; color: white; font-size: 20px;"); //  color of cinema screen
    cinemaScreen->setText("Cinema Screen"); //text
    cinemaScreen->setAlignment(Qt::AlignCenter); //putting the screen in the centre
    cinemaScreen->setFixedHeight(70); // Height of the cinema screen
    mainLayout->addWidget(cinemaScreen, 0, Qt::AlignTop);//cinema screen above seats

    // Create the grid layout for seat buttons
    seatLayout = new QGridLayout();
    seatLayout->setHorizontalSpacing(20); // Space between columns
    seatLayout->setVerticalSpacing(20);   // Space between rows

    // Example: Define which seats are VIP (true for VIP, false for regular)
    QVector<bool> vipSeats = {
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,    // false = regular seats
        true, true, true, true, true, true, true, true, true, true,              // true = vip seats
        true, true, true, true, true, true, true, true, true, true
    };

    // Creating the seats (e.g., 4 rows x 10 columns)
    createSeats(4, 10, vipSeats);

    // Wrap the seat layout in a container for better alignment
    QWidget *seatContainer = new QWidget(this);
    seatContainer->setLayout(seatLayout);
    mainLayout->addWidget(seatContainer, 0, Qt::AlignHCenter); // Centers the seats

    // Labels for selected seats and total price
    selectedSeatsLabel = new QLabel("Selected Seats: None"); // selected seats
    totalPriceLabel = new QLabel("Total Price: $0.00");      // the price of all (total)
    selectedSeatsLabel->setStyleSheet("font-size: 16px;");      //font
    totalPriceLabel->setStyleSheet("font-size: 16px;");         //font
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

Seats::~Seats() {}  // Function to create seats in a grid layout

void Seats::createSeats(int rows, int cols, QVector<bool> vipSeats)
{
    int seatID = 1;      // Initialize seat ID
    int vipIndex = 0;    // Index to track VIP seat status

    // Loop through rows and columns to create each seat
    for (int row = 0; row < rows; ++row) {

        for (int col = 0; col < cols; ++col) {

            QPushButton *seatButton = new QPushButton(QString::number(seatID));  // Creating button for each seat with label showing seat ID
            seatButton->setFixedSize(36, 36);

            // Determine if the seat is VIP or regular
            bool isVip = vipSeats[vipIndex++];
            if (isVip) {

                // Setting VIP seat button style (blue background)
                seatButton->setStyleSheet(
                    "background-color: blue; color: white;"
                    "margin: 2px;"   // Reduced margin
                    "padding: 0px;" // No padding for compact look
                    );
            } else {

                // Setting the regular seat button style (green background)

                seatButton->setStyleSheet(
                    "background-color: green; color: white;"
                    "margin: 2px;"   // Reduced margin
                    "padding: 0px;" // No padding for compact look
                    );
            }

            // Connecting the button's click signal to the onSeatClicked slot

            connect(seatButton, &QPushButton::clicked, this, &Seats::onSeatClicked);

            // Add button to the layout and store the button in a vector
            seatLayout->addWidget(seatButton, row, col);
            seatButtons.push_back(seatButton);

            ++seatID;    // Increment seat ID for the next button

        }
    }
}


// Slot to handle seat selection or deselection


void Seats::onSeatClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());  // Get the button that was clicked
    if (!button) return;   // Exit if the button is invalid

    QString seatNumber = button->text();


    bool isVip = button->styleSheet().contains("blue");

    // seat selection: if available, select it; if selected, deselect it

    if (button->styleSheet().contains("green") || button->styleSheet().contains("blue")) {

        // Available seat becomes selected (change color)

        button->setStyleSheet(isVip ? "background-color: cyan; color: black;" // VIP selected

                                    : "background-color: yellow; color: black;"); // Regular selected

        selectedSeats.append(seatNumber);  // Adding seat to selected seats list

        totalPrice += isVip ? vipPrice : regularPrice;   // Adding seat price to total

    } else if (button->styleSheet().contains("yellow") || button->styleSheet().contains("cyan")) {

        // selected seat as available (change color)

        button->setStyleSheet(isVip ? "background-color: blue; color: white;" // VIP available
                                    : "background-color: green; color: white;"); // Regular available

        selectedSeats.removeOne(seatNumber);   // Remove seat from selected seats list
        totalPrice -= isVip ? vipPrice : regularPrice;      // Subtract seat price from total
    }

    // Updating UI labels to show selected seats and total price

    selectedSeatsLabel->setText("Selected Seats: " + selectedSeats.join(", "));
    totalPriceLabel->setText(QString("Total Price: $%1").arg(totalPrice, 0, 'f', 2));
}

// Function to confirm the booking and finalize seat selection

void Seats::confirmBooking()
{
    // Showing warning if no seats are selected

    if (selectedSeats.isEmpty()) {
        QMessageBox::warning(this, "No Seats Selected", "Please select at least one seat.");
        return;
    }

    // Show confirmation message with booked seats and total price

    QMessageBox::information(this, "Booking Confirmed",
                             QString("You have booked the following seats:\n%1\nTotal Price: $%2")
                                 .arg(selectedSeats.join(", "))
                                 .arg(totalPrice, 0, 'f', 2));


    // Mark selected seats as booked and disable them

    for (auto *button : seatButtons) {
        if (button->styleSheet().contains("yellow") || button->styleSheet().contains("cyan")) {

            // Marking seat as booked (change color)

            button->setStyleSheet(button->styleSheet().contains("cyan")
                                  ? "background-color: darkred; color: white;" // VIP booked
                                  : "background-color: red; color: white;"); // Regular booked
            button->setEnabled(false);  // Disabling the button (can't click it again)
        }
    }

    selectedSeats.clear();  // Clearing the list of selected seats

    totalPrice = 0.0;           // Reseting the total price to 0

    selectedSeatsLabel->setText("Selected Seats: None");  // Updating the label to indicate no seats are selected

    totalPriceLabel->setText("Total Price: $0.00");  // Updating the label to show the total price is $0

}
