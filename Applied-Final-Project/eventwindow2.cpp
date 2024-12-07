#include "EventWindow2.h"

EventWindow2::EventWindow2(Customer* customer, QWidget* parent, vectorC<Events>& eventsList)
    : QDialog(parent),
    mainLayout(new QVBoxLayout(this)),
    topBarLayout(new QHBoxLayout),
    scrollArea(new QScrollArea(this)),
    scrollWidget(new QWidget),
    gridLayout(new QGridLayout(scrollWidget)),
    accountButton(new QPushButton("My Account")),
    eventsList(eventsList),  // Initialize eventsList with the passed vector
    C(customer) {           // Initialize the customer pointer
    setupUI();
    loadEvents();
}

EventWindow2::~EventWindow2() {
    while (eventsList.getSize() > 0) {
        delete eventsList.pop(); // Pop and delete all dynamically allocated events
    }
}

void EventWindow2::setupUI() {
    // Set up the top bar layout
    topBarLayout->setAlignment(Qt::AlignRight);

    accountButton->setStyleSheet(
        "background-color: #FF69B4; color: white; font-size: 18px; padding: 10px 20px;"
        "border-radius: 5px; font-weight: bold;");

    connect(accountButton, &QPushButton::clicked, [this]() {
        AccountPage* acc = new AccountPage(C);
        acc->show();
    });

    // Create the "My Tickets" button
    QPushButton* myTic = new QPushButton("My Tickets", this);
    myTic->setStyleSheet(
        "background-color: #FF69B4; color: white; font-size: 18px; padding: 10px 20px;"
        "border-radius: 5px; font-weight: bold;");
    myTic->setFixedWidth(150);

    connect(myTic, &QPushButton::clicked, [this]() {
        Reserved* reservedWindow = new Reserved(C, this);
        reservedWindow->show();
    });

    // Add both buttons to the top bar layout
    topBarLayout->addWidget(accountButton);
    topBarLayout->addWidget(myTic);

    // Add the top bar layout to the main layout
    mainLayout->addLayout(topBarLayout);

    // Set up the scroll area
    scrollArea->setWidgetResizable(true);
    gridLayout->setSpacing(30);
    gridLayout->setContentsMargins(40, 40, 40, 40);

    scrollWidget->setLayout(gridLayout);
    scrollArea->setWidget(scrollWidget);
    mainLayout->addWidget(scrollArea);

    // Set up main window properties
    setLayout(mainLayout);
    setStyleSheet("background-color: #B4E7E2; padding: 20px; color: #2F4F4F;");
}

void EventWindow2::loadEvents() {
    for (int i = 0; i < eventsList.getSize(); ++i) {
        addEventToLayout(eventsList.get(i), C, i / 2, i % 2);
    }
}

void EventWindow2::addEventToLayout(Events* event, Customer* C, int row, int col) {
    QWidget* eventWidget = new QWidget;
    eventWidget->setFixedSize(600, 600);
    eventWidget->setStyleSheet(
        "border-radius: 15px;"
        "background-color: #e6f7ff;"
        "box-shadow: 0 6px 15px rgba(0, 0, 0, 0.6);");

    QVBoxLayout* eventLayout = new QVBoxLayout(eventWidget);

    QLabel* photoLabel = new QLabel(eventWidget);
    photoLabel->setPixmap(event->getImage().scaled(580, 300, Qt::KeepAspectRatio));
    photoLabel->setAlignment(Qt::AlignCenter);
    photoLabel->setStyleSheet(
        "border-radius: 15px;"
        "border: 3px solid #FF69B4;"
        "box-shadow: 0 4px 8px rgba(0, 0, 0, 0.4);"
        "padding: 10px;");

    QLabel* titleLabel = new QLabel(event->getTitle(), eventWidget);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #333333; text-align: center; margin-top: 15px;");

    QLabel* dateLabel = new QLabel(event->getDate(), eventWidget);
    dateLabel->setStyleSheet("color: #5f6368; font-size: 18px; text-align: center; margin-bottom: 20px;");

    QHBoxLayout* timeButtonLayout = new QHBoxLayout;
    timeButtonLayout->setSpacing(15);

    QPushButton* time1 = new QPushButton("4:00", eventWidget);
    QPushButton* time2 = new QPushButton("7:00", eventWidget);
    QPushButton* time3 = new QPushButton("10:00", eventWidget);

    for (QPushButton* button : {time1, time2, time3}) {
        button->setStyleSheet(
            "background-color: #FF69B4; color: white; font-size: 18px; padding: 12px 20px;"
            "border: none; border-radius: 5px; font-weight: bold;"
            "box-shadow: 0px 0px 10px rgba(255, 105, 180, 0.5);");
        button->setFixedWidth(150);
        timeButtonLayout->addWidget(button);
    }

    connect(time1, &QPushButton::clicked, [C, event]() {
        Seats* w = new Seats(C, event, 1);
        w->show();
    });
    connect(time2, &QPushButton::clicked, [C, event]() {
        Seats* w = new Seats(C, event, 2);
        w->show();
    });
    connect(time3, &QPushButton::clicked, [C, event]() {
        Seats* w = new Seats(C, event, 3);
        w->show();
    });

    eventLayout->addWidget(photoLabel, 0, Qt::AlignCenter);
    eventLayout->addWidget(titleLabel, 0, Qt::AlignCenter);
    eventLayout->addWidget(dateLabel, 0, Qt::AlignCenter);
    eventLayout->addLayout(timeButtonLayout);
    eventLayout->setAlignment(Qt::AlignCenter);

    gridLayout->addWidget(eventWidget, row, col);
}
