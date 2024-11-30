#include "seats.h"
#include <QVBoxLayout>
#include <QMessageBox>

void Seats::confirmBooking(Customer* Cu, Events* Ev)
{
    if (selectedSeats.isEmpty()) {
        QMessageBox::warning(this, "No Seats Selected", "Please select at least one seat.");
        return;
    }

    if (!Ev || !Cu) {
        QMessageBox::critical(this, "Error", "Invalid Event or Customer.");
        return;
    }

    // Show the confirmation window
    ConfirmBook* confirm = new ConfirmBook(Ev, Cu, this);
    confirm->setAttribute(Qt::WA_DeleteOnClose);
    confirm->show();

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
}


Seats::Seats(Customer* customer, Events* EV, QWidget* parent)
    : QWidget(parent), C(customer), E(EV), totalPrice(0.0), regularPrice(50.0), vipPrice(100.0)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this); // Main vertical layout

    // Add the cinema screen at the top
    QLabel* cinemaScreen = new QLabel("Cinema Screen", this);
    cinemaScreen->setStyleSheet("background-color: black; border: 2px solid white; color: white; font-size: 20px;");
    cinemaScreen->setAlignment(Qt::AlignCenter);
    cinemaScreen->setFixedHeight(70);
    mainLayout->addWidget(cinemaScreen, 0, Qt::AlignTop);

    // Create the grid layout for seat buttons
    seatLayout = new QGridLayout();
    seatLayout->setHorizontalSpacing(20); // Space between columns
    seatLayout->setVerticalSpacing(20);

    // Display information about the event
    if (E) {
        QMessageBox::information(this, "Booking Confirmed", QString("Booking for Event: %1").arg(E->getTitle()));
    }

    // Define which seats are VIP (true for VIP, false for regular)
    QVector<bool> vipSeats = {
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,    // false = regular seats
        true, true, true, true, true, true, true, true, true, true,              // true = VIP seats
        true, true, true, true, true, true, true, true, true, true
    };

    // Create seats (e.g., 4 rows x 10 columns)
    createSeats(4, 10, vipSeats);

    // Wrap the seat layout in a container for better alignment
    QWidget* seatContainer = new QWidget(this);
    seatContainer->setLayout(seatLayout);
    mainLayout->addWidget(seatContainer, 0, Qt::AlignHCenter); // Centers the seats

    // Labels for selected seats and total price
    selectedSeatsLabel = new QLabel("Selected Seats: None", this);
    totalPriceLabel = new QLabel("Total Price: $0.00", this);
    selectedSeatsLabel->setStyleSheet("font-size: 16px;");
    totalPriceLabel->setStyleSheet("font-size: 16px;");
    mainLayout->addWidget(selectedSeatsLabel, 0, Qt::AlignHCenter);
    mainLayout->addWidget(totalPriceLabel, 0, Qt::AlignHCenter);

    // Confirm booking button
    QPushButton* confirmButton = new QPushButton("Confirm Booking", this);
    confirmButton->setStyleSheet("font-size: 16px; padding: 8px 16px;");
    mainLayout->addWidget(confirmButton, 0, Qt::AlignHCenter);

    // Connect the confirm button signal with a lambda function to pass parameters
    connect(confirmButton, &QPushButton::clicked, this, [this]() {
        this->confirmBooking(C, E); // Call confirmBooking with Customer* and Events*
    });

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
            seatButton->setObjectName(isVip ? "vip" : "regular");

            if (isVip) {
                // Setting VIP seat button style (blue background)
                seatButton->setStyleSheet(
                    "background-color: blue; color: white;"
                    "margin: 2px;"
                    "padding: 0px;"
                    );
            } else {
                // Setting regular seat button style (green background)
                seatButton->setStyleSheet(
                    "background-color: green; color: white;"
                    "margin: 2px;"
                    "padding: 0px;"
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


    bool isVip = (button->objectName() == "vip");

    // seat selection: if available, select it; if selected, deselect it

    if (button->styleSheet().contains("green") || button->styleSheet().contains("blue"))
    {
        // Available seat becomes selected (change color)

        button->setStyleSheet(isVip ? "background-color: cyan; color: black;" : "background-color: yellow; color: black;");

        selectedSeats.append(seatNumber);  // Adding seat to selected seats list

        totalPrice += isVip ? vipPrice : regularPrice;   // Adding seat price to total

    }   else if (button->styleSheet().contains("yellow") || button->styleSheet().contains("cyan")) {

        // Selected seat becomes available (change color)

        button->setStyleSheet(isVip ? "background-color: blue; color: white;" : "background-color: green; color: white;");

        selectedSeats.removeOne(seatNumber);   // Remove seat from selected seats list

        totalPrice -= isVip ? vipPrice : regularPrice;      // Subtract seat price from total
    }


    // Updating UI labels to show selected seats and total price

    selectedSeatsLabel->setText("Selected Seats: " + selectedSeats.join(", "));
    totalPriceLabel->setText(QString("Total Price: $%1").arg(totalPrice, 0, 'f', 2));
}

// Function to confirm the booking and finalize seat selection


