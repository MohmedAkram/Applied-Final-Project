#include "eventwindow1.h"
#include "ui_eventwindow1.h"
#include "customerlogin.h"
#include "registerwindow.h"
#include "customer.h"
#include "system.h"
#include <QPushButton>
#include <QMessageBox>

EventsWindow1::EventsWindow1(QWidget *parent)
    : QDialog(parent),
    movies(10),
    mainLayout(new QVBoxLayout(this)),
    topBarLayout(new QHBoxLayout),
    scrollArea(new QScrollArea(this)),
    scrollWidget(new QWidget),
    gridLayout(new QGridLayout(scrollWidget)) {

    setupUI();
    loadEvents();
}

void EventsWindow1::setupUI() {
    // Set up the top bar layout with Login and Sign Up buttons
    topBarLayout->setAlignment(Qt::AlignRight); // Align buttons to the top-right corner

    QPushButton *loginButton = new QPushButton("Login");
    QPushButton *signupButton = new QPushButton("Sign Up");

    loginButton->setStyleSheet(
        "background-color: #FF69B4; color: white; font-size: 18px; padding: 10px 20px;"
        "border-radius: 5px; font-weight: bold;"
        );
    signupButton->setStyleSheet(
        "background-color: #FF69B4; color: white; font-size: 18px; padding: 10px 20px;"
        "border-radius: 5px; font-weight: bold;"
        );

    // Create instances for the Login and Signup windows
    CustomerLogin *logins = new CustomerLogin(this);
    RegisterWindow *registerr = new RegisterWindow(this);

    QObject::connect(loginButton, &QPushButton::clicked, [logins]() {
        logins->exec();       // Show Login window
    });

    QObject::connect(signupButton, &QPushButton::clicked, [registerr]() {
        registerr->exec(); // Show Signup window
    });

    topBarLayout->addWidget(loginButton);
    topBarLayout->addWidget(signupButton);
    mainLayout->addLayout(topBarLayout); // Add top bar to the main layout

    // Set up scroll area for events
    scrollArea->setWidgetResizable(true);
    gridLayout->setSpacing(30); // Larger spacing between items
    gridLayout->setContentsMargins(40, 40, 40, 40); // Larger margins around the grid

    scrollWidget->setLayout(gridLayout);
    scrollArea->setWidget(scrollWidget);
    mainLayout->addWidget(scrollArea);

    // Set main window properties
    setLayout(mainLayout);
    setStyleSheet("background-color: #B4E7E2; padding: 20px; color: #2F4F4F;");
    setWindowTitle("Event Window 1");
    setFixedSize(1200, 800);
}

void EventsWindow1::loadEvents() {
    // Define and add events to vectorC
    QPixmap www(":/images/welad resq.jpg");
    QPixmap opp(":/images/_.jpeg");
    QPixmap bar(":/images/share.jpg");
    QPixmap morg(":/images/maxresdefault.jpg");

    Events* event1 = new Events(1, "Welad Rizk III", 2023, "Action - Comedy", 200.00, www);
    Events* event2 = new Events(2, "Barbie", 2023, "Romance - Fiction", 250.00, bar);
    Events* event3 = new Events(2, "Oppenheimer", 2023, "Thriller", 250.00, opp);
    Events* event4 = new Events(2, "Bringing Back: Morgan Ahmed Morgan", 2023, "Comedy", 250.00, morg);
    Events* event6 = new Events(1, "Welad Rizk III", 2023, "Action - Comedy", 200.00, www);
    Events* event7 = new Events(1, "Welad Rizk III", 2023, "Action - Comedy", 200.00, www);

    movies.push(event1);
    movies.push(event2);
    movies.push(event3);
    movies.push(event4);
    movies.push(event6);
    movies.push(event7);

    // Iterate through the vector and display events
    for (int i = 0; i < movies.getSize(); ++i) {
        Events *event = movies.get(i); // Use get() method to access the event
        addEventToLayout(event, i / 2, i % 2); // Add events to the grid layout
    }
}

void EventsWindow1::addEventToLayout(Events *event, int row, int col) {
    // Event container
    QWidget *eventWidget = new QWidget;
    eventWidget->setFixedSize(600, 600); // Larger size for each event box
    eventWidget->setStyleSheet(
        "border-radius: 15px;"
        "background-color: #e6f7ff;" // Cream background for the event box
        "box-shadow: 0 6px 15px rgba(0, 0, 0, 0.6);"
        );

    QVBoxLayout *eventLayout = new QVBoxLayout(eventWidget);

    // Photo
    QLabel *photoLabel = new QLabel(eventWidget);
    photoLabel->setPixmap(event->getImage().scaled(580, 300, Qt::KeepAspectRatio)); // Larger image size
    photoLabel->setAlignment(Qt::AlignCenter);
    photoLabel->setStyleSheet(
        "border-radius: 15px;"
        "border: 3px solid #FF69B4;" // Pink border around image
        "box-shadow: 0 4px 8px rgba(0, 0, 0, 0.4);"
        "padding: 10px;"
        );

    // Event details
    QLabel *titleLabel = new QLabel(event->getTitle(), eventWidget);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #333333; text-align: center; margin-top: 15px;");

    QLabel *dateLabel = new QLabel(event->getDate(), eventWidget);
    dateLabel->setStyleSheet("color: #5f6368; font-size: 18px; text-align: center; margin-bottom: 20px;");

    // Details button (pink background)
    QPushButton *detailsButton = new QPushButton("Details", eventWidget);
    detailsButton->setStyleSheet(
        "background-color: #FF69B4; color: white; font-size: 18px; padding: 12px 20px;"
        "border: none; border-radius: 5px; font-weight: bold;"
        "transition: 0.3s;"
        "box-shadow: 0px 0px 10px rgba(255, 105, 180, 0.5);"
        );

    eventLayout->addWidget(photoLabel);
    eventLayout->addWidget(titleLabel);
    eventLayout->addWidget(dateLabel);
    eventLayout->addWidget(detailsButton);
    eventWidget->setLayout(eventLayout);

    // Add the event widget to the grid
    gridLayout->addWidget(eventWidget, row, col);
}
