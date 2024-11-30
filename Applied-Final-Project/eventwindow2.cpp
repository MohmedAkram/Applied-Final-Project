#include "EventWindow2.h"
#include "Seats.h" // Include the header for Seats class

EventWindow2::EventWindow2(Customer* customer,QWidget *parent)
    : QDialog(parent), mainLayout(new QVBoxLayout(this)), topBarLayout(new QHBoxLayout),
    scrollArea(new QScrollArea(this)), scrollWidget(new QWidget),
    gridLayout(new QGridLayout(scrollWidget)), accountButton(new QPushButton("My Account")),
    movies(10) {    // Initialize vector with a capacity of 10
    setupUI();
    loadEvents();
    C = customer;
}

EventWindow2::~EventWindow2() {
    while (movies.getSize() > 0) {
        delete movies.pop(); // Pop and delete all dynamically allocated events
    }
}

void EventWindow2::setupUI() {
    // Set up the top bar layout
    topBarLayout->setAlignment(Qt::AlignRight);
    accountButton->setStyleSheet(
        "background-color: #FF69B4; color: white; font-size: 18px; padding: 10px 20px;"
        "border-radius: 5px; font-weight: bold;");

    connect(accountButton, &QPushButton::clicked, [this]()
            {
        AccountPage *acc= new AccountPage(C);
        acc->show();

    });

    topBarLayout->addWidget(accountButton);
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
    // Add events to the custom vector
    movies.push(new Events(1, "Welad Rizk III", 2023, "Action - Comedy", 200.00, QPixmap(":/images/welad resq.jpg")));
    movies.push(new Events(2, "Barbie", 2023, "Romance - Fiction", 250.00, QPixmap(":/images/share.jpg")));
    movies.push(new Events(3, "Oppenheimer", 2023, "Thriller", 250.00, QPixmap(":/images/_.jpeg")));
    movies.push(new Events(4, "Bringing Back: Morgan Ahmed Morgan", 2023, "Comedy", 250.00, QPixmap(":/images/maxresdefault.jpg")));

    for (int i = 0; i < movies.getSize(); ++i) {
        addEventToLayout(movies.get(i), i / 2, i % 2);
    }
}

void EventWindow2::addEventToLayout(Events *event, int row, int col) {
    // Create event container
    QWidget *eventWidget = new QWidget;
    eventWidget->setFixedSize(600, 600);
    eventWidget->setStyleSheet(
        "border-radius: 15px;"
        "background-color: #e6f7ff;"
        "box-shadow: 0 6px 15px rgba(0, 0, 0, 0.6);");

    QVBoxLayout *eventLayout = new QVBoxLayout(eventWidget);

    // Photo
    QLabel *photoLabel = new QLabel(eventWidget);
    photoLabel->setPixmap(event->getImage().scaled(580, 300, Qt::KeepAspectRatio));
    photoLabel->setAlignment(Qt::AlignCenter);
    photoLabel->setStyleSheet(
        "border-radius: 15px;"
        "border: 3px solid #FF69B4;"
        "box-shadow: 0 4px 8px rgba(0, 0, 0, 0.4);"
        "padding: 10px;");

    // Event details
    QLabel *titleLabel = new QLabel(event->getTitle(), eventWidget);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #333333; text-align: center; margin-top: 15px;");

    QLabel *dateLabel = new QLabel(event->getDate(), eventWidget);
    dateLabel->setStyleSheet("color: #5f6368; font-size: 18px; text-align: center; margin-bottom: 20px;");

    // Book button
    QPushButton *bookButton = new QPushButton("Book", eventWidget);
    bookButton->setStyleSheet(
        "background-color: #FF69B4; color: white; font-size: 18px; padding: 12px 20px;"
        "border: none; border-radius: 5px; font-weight: bold;"
        "box-shadow: 0px 0px 10px rgba(255, 105, 180, 0.5);");
    bookButton->setFixedWidth(180);

    connect(bookButton, &QPushButton::clicked, [event]() {
        // Ensure the Seats window is being created and shown properly
        Seats* w = new Seats();  // Create a new instance of Seats window
        w->show();  // Show the window
    });

    // Add widgets to event layout
    eventLayout->addWidget(photoLabel, 0, Qt::AlignCenter);
    eventLayout->addWidget(titleLabel, 0, Qt::AlignCenter);
    eventLayout->addWidget(dateLabel, 0, Qt::AlignCenter);
    eventLayout->addWidget(bookButton, 0, Qt::AlignCenter);
    eventLayout->setAlignment(Qt::AlignCenter);

    // Add event widget to grid layout
    gridLayout->addWidget(eventWidget, row, col);
}
