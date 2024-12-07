#include "reserved.h"
#include "ui_reserved.h"
#include "system.h"

Reserved::Reserved(Customer* customer, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Reserved),
    currentCustomer(customer),
    mainLayout(new QVBoxLayout(this)),
    topBarLayout(new QHBoxLayout),
    scrollArea(new QScrollArea(this)),
    scrollWidget(new QWidget),
    gridLayout(new QGridLayout(scrollWidget)) {

    ui->setupUi(this);
    setupUI();
    loadTickets();
}

Reserved::~Reserved() {
    delete ui;
}

void Reserved::setupUI() {
    // Set up the main layout
    topBarLayout->setAlignment(Qt::AlignRight);

    QPushButton *backButton = new QPushButton("Back");
    backButton->setStyleSheet(
        "background-color: #FF69B4; color: white; font-size: 18px; padding: 10px 20px;"
        "border-radius: 5px; font-weight: bold;"
        );
    QObject::connect(backButton, &QPushButton::clicked, this, &QDialog::close);

    topBarLayout->addWidget(backButton);
    mainLayout->addLayout(topBarLayout);

    // Set up the scroll area for tickets
    scrollArea->setWidgetResizable(true);
    gridLayout->setSpacing(30);
    gridLayout->setContentsMargins(40, 40, 40, 40);

    scrollWidget->setLayout(gridLayout);
    scrollArea->setWidget(scrollWidget);
    mainLayout->addWidget(scrollArea);

    // Set window properties
    setLayout(mainLayout);
    setStyleSheet("background-color: #B4E7E2; padding: 20px; color: #2F4F4F;");
    setWindowTitle("Reserved Tickets");
    setFixedSize(1200, 800);
}

void Reserved::loadTickets() {
    // Iterate through the ReservedTickets vector in Customer
    for (int i = 0; i < currentCustomer->ReservedTickets.getSize(); ++i) {
        Tickets* ticket = currentCustomer->ReservedTickets.get(i);
        addTicketToLayout(ticket, i / 2, i % 2); // Arrange tickets in grid
    }
}

void Reserved::addTicketToLayout(Tickets* ticket, int row, int col) {
    // Create the ticket container
    QWidget *ticketWidget = new QWidget;
    ticketWidget->setFixedSize(600, 600);
    ticketWidget->setStyleSheet(
        "border-radius: 15px;"
        "background-color: #e6f7ff;"
        "box-shadow: 0 6px 15px rgba(0, 0, 0, 0.6);"
        );

    QVBoxLayout *ticketLayout = new QVBoxLayout(ticketWidget);

    // Ticket
    QLabel *titleLabel;
    if (ticket->movieNum == 0) {
        titleLabel = new QLabel("Event: Welad Rizk III", ticketWidget);
    } else if (ticket->movieNum == 1) {
        titleLabel = new QLabel("Event: Barbie", ticketWidget);
    } else if (ticket->movieNum == 2) {
        titleLabel = new QLabel("Event: Oppenheimer", ticketWidget);
    } else if (ticket->movieNum == 3) {
        titleLabel = new QLabel("Event: Bringing Back: Morgan Ahmed Morgan", ticketWidget);
    }
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #333333; text-align: center;");

    QLabel *dateLabel = new QLabel("Seat Number: " + QString::number(ticket->seatNumber+1), ticketWidget);
    dateLabel->setStyleSheet("color: #5f6368; font-size: 18px; text-align: center;");

    QLabel *seatLabel;
    if (ticket->seatNumber < 20) {
        seatLabel = new QLabel(currentCustomer->IsVIP ? "Price: 40 $" : "Price: 50 $", ticketWidget);
    } else {
        seatLabel = new QLabel(currentCustomer->IsVIP ? "Price: 80 $" : "Price: 100 $", ticketWidget);
    }
    seatLabel->setStyleSheet("color: #5f6368; font-size: 18px; text-align: center;");

    // Cancel button
    QPushButton *cancelButton = new QPushButton("Cancel Ticket", ticketWidget);
    cancelButton->setStyleSheet(
        "background-color: #FF4444; color: white; font-size: 16px; font-weight: bold; "
        "padding: 10px; border-radius: 8px;"
        );

    // **Connect the cancel button to a slot function**
    connect(cancelButton, &QPushButton::clicked, this, [this, ticketWidget, ticket]() {
        this->onCancelTicketClicked(ticketWidget, ticket);
    });

    // Add components to layout
    ticketLayout->addWidget(titleLabel);
    ticketLayout->addWidget(dateLabel);
    ticketLayout->addWidget(seatLabel);
    ticketLayout->addWidget(cancelButton);

    ticketWidget->setLayout(ticketLayout);

    // Add ticket widget to grid layout
    gridLayout->addWidget(ticketWidget, row, col);
}

void Reserved::onCancelTicketClicked(QWidget *ticketWidget, Tickets* ticket) {
    // **Remove ticket from layout and delete its widget**
    ticketWidget->hide();  // Hide the widget
    gridLayout->removeWidget(ticketWidget); // Remove from the layout
    ticketWidget->deleteLater(); // Schedule it for deletion

    // **Remove the ticket from the currentCustomer's ReservedTickets list**
    for (int i = 0; i < currentCustomer->ReservedTickets.getSize(); ++i) {
        if (currentCustomer->ReservedTickets.get(i) == ticket) {
            sys.TDB[currentCustomer->ReservedTickets.get(i)->movieNum][currentCustomer->ReservedTickets.get(i)->time][currentCustomer->ReservedTickets.get(i)->seatNumber]->status = false;
            currentCustomer->ReservedTickets.remove(i);
            if (currentCustomer->IsVIP){
                if (ticket->seatNumber<20){currentCustomer->editbalance(40);}
                else{currentCustomer->editbalance(80);}}
            else
            if (ticket->seatNumber<20){currentCustomer->editbalance(50);}
            else{currentCustomer->editbalance(100);}

            break;
        }
    }
}
