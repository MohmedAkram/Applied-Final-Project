#include "reserved.h"
#include "ui_reserved.h"

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

    // Ticket details
    QLabel *titleLabel = new QLabel("Event: " + QString::number(ticket->movieNum), ticketWidget);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #333333; text-align: center;");

    QLabel *dateLabel = new QLabel("Seat Number: " + QString::number(ticket->seatNumber), ticketWidget);
    dateLabel->setStyleSheet("color: #5f6368; font-size: 18px; text-align: center;");

    QLabel *seatLabel = new QLabel("Price: $" + QString::number(ticket->price), ticketWidget);
    seatLabel->setStyleSheet("color: #5f6368; font-size: 18px; text-align: center;");



    // Add components to layout
    ticketLayout->addWidget(titleLabel);
    ticketLayout->addWidget(dateLabel);
    ticketLayout->addWidget(seatLabel);

    ticketWidget->setLayout(ticketLayout);

    // Add ticket widget to grid layout
    gridLayout->addWidget(ticketWidget, row, col);
}
