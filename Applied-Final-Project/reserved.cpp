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
    if (ui) {
        delete ui;
        ui = nullptr;
    }
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
    ticketWidget->setFixedSize(600, 650); // Increased height to fit all elements
    ticketWidget->setStyleSheet(
        "border-radius: 15px;"
        "background-color: #e6f7ff;"
        "box-shadow: 0 6px 15px rgba(0, 0, 0, 0.6);"
        );

    QVBoxLayout *ticketLayout = new QVBoxLayout(ticketWidget);

    // Ticket Title
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
    else {titleLabel = new QLabel("Event: Unknown ", ticketWidget);}
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #333333; text-align: center;");

    // Seat Number
    QLabel *seatLabel = new QLabel("Seat Number: " + QString::number(ticket->seatNumber + 1), ticketWidget);
    seatLabel->setStyleSheet("color: #5f6368; font-size: 18px; text-align: center;");

    // Price Information
    QLabel *priceLabel;
    if (ticket->seatNumber < 20) {
        priceLabel = new QLabel(currentCustomer->IsVIP ? "Price: 40 $" : "Price: 50 $", ticketWidget);
    } else {
        priceLabel = new QLabel(currentCustomer->IsVIP ? "Price: 80 $" : "Price: 100 $", ticketWidget);
    }
    priceLabel->setStyleSheet("color: #5f6368; font-size: 18px; text-align: center;");

    // **Time Label**
    QLabel *timeLabel = new QLabel("Time: " + getTimeFromIndex(ticket->time), ticketWidget);
    timeLabel->setStyleSheet("color: #5f6368; font-size: 18px; text-align: center;");

    // Cancel button
    QPushButton *cancelButton = new QPushButton("Cancel Ticket", ticketWidget);
    cancelButton->setStyleSheet(
        "background-color: #FF4444; color: white; font-size: 16px; font-weight: bold; "
        "padding: 10px; border-radius: 8px;"
        );

    // Connect the cancel button to a slot function
    connect(cancelButton, &QPushButton::clicked, this, [this, ticketWidget, ticket]() {
        this->onCancelTicketClicked(ticketWidget, ticket);
    });

    // Add components to layout
    ticketLayout->addWidget(titleLabel);
    ticketLayout->addWidget(seatLabel);
    ticketLayout->addWidget(priceLabel);
    ticketLayout->addWidget(timeLabel);
    ticketLayout->addWidget(cancelButton);

    ticketWidget->setLayout(ticketLayout);

    // Add ticket widget to grid layout
    gridLayout->addWidget(ticketWidget, row, col);
}

void Reserved::onCancelTicketClicked(QWidget *ticketWidget, Tickets* ticket) {
    ticketWidget->hide();
    gridLayout->removeWidget(ticketWidget);
    ticketWidget->deleteLater();
    ticket->status=false;
    for(int i= 0;i<currentCustomer->ReservedTickets.currentSize;i++){
        if (currentCustomer->ReservedTickets.get(i)==ticket){currentCustomer->ReservedTickets.remove(i);}}
    if (currentCustomer->IsVIP) {
        if (ticket->seatNumber < 20) { currentCustomer->editbalance(40); }
        else { currentCustomer->editbalance(80); }
    } else {
        if (ticket->seatNumber < 20) { currentCustomer->editbalance(50); }
        else { currentCustomer->editbalance(100); }}
}
// Helper function to convert time index to readable time string
QString Reserved::getTimeFromIndex(int timeIndex) {
    switch (timeIndex) {
    case 0: return "10:00 PM";
    case 1: return "4:00 PM";
    case 2: return "7:00 PM";
    case 3: return "10:00 PM";
default:
    qDebug() << "Invalid time index: " << timeIndex;  // Log for debugging
    return "Invalid Time";}

}
