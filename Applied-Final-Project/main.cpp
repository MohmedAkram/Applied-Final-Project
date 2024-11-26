#include "mainwindow.h"
#include "events.h"
#include "vectorc.h"
#include <QApplication>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include "customerlogin.h"
#include "registerwindow.h"
#include "seats.h"

class LoginWindow : public QDialog {
public:
    LoginWindow(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Login");
        setFixedSize(400, 300);
        QLabel *label = new QLabel("This is the Login window.", this);
        label->setAlignment(Qt::AlignCenter);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(label);
        setLayout(layout);
    }
};

class SignupWindow : public QDialog {
public:
    SignupWindow(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Sign Up");
        setFixedSize(400, 300);
        QLabel *label = new QLabel("This is the Sign Up window.", this);
        label->setAlignment(Qt::AlignCenter);
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(label);
        setLayout(layout);
    }
};

int main(int argc, char *argv[]) {
    QApplication EventWindow(argc, argv);

    QApplication a(argc, argv);
    Seats w;
    w.show();
    // Create a vectorC to hold events
    vectorC<Events> movies(10);

    // Define and add events to vectorC
    QPixmap www(":/images/welad resq.jpg");
    QPixmap opp(":/images/_.jpeg");
    QPixmap bar(":/images/share.jpg");
    QPixmap morg(":/images/maxresdefault.jpg");

    Events* event1 = new Events(1, "Welad Rizk III", 2023, "Action - Comedy", 200.00, www);
    Events* event2 = new Events(2, "Barbie", 2023, "Romance - Fiction", 250.00, bar);
    Events* event3 = new Events(2, "Oppenheimer", 2023, "Thriller", 250.00, opp);
    Events* event4 = new Events(2, "Bringing Back: Morgan Ahmed Morgan", 2023, "Comedy", 250.00, morg);
    // Add more events here...

    movies.push(event1);
    movies.push(event2);
    movies.push(event3);
    movies.push(event4);
    // Add more events to the vector...

    // Create main window and scrollable layout
    QDialog mainWindow;
    QVBoxLayout *mainLayout = new QVBoxLayout(&mainWindow);

    // Top bar with buttons
    QHBoxLayout *topBarLayout = new QHBoxLayout;
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
    CustomerLogin login;
    RegisterWindow registerr;

    QObject::connect(loginButton, &QPushButton::clicked, [&login]() {
        login.exec(); // Show Login window
    });

    QObject::connect(signupButton, &QPushButton::clicked, [&registerr]() {
        registerr.exec(); // Show Signup window
    });

    topBarLayout->addWidget(loginButton);
    topBarLayout->addWidget(signupButton);
    mainLayout->addLayout(topBarLayout); // Add top bar to the main layout

    QScrollArea *scrollArea = new QScrollArea(&mainWindow);
    scrollArea->setWidgetResizable(true);
    QWidget *scrollWidget = new QWidget;
    QGridLayout *gridLayout = new QGridLayout(scrollWidget); // Use a grid layout for side-by-side items
    gridLayout->setSpacing(30); // Larger spacing between items
    gridLayout->setContentsMargins(40, 40, 40, 40); // Larger margins around the grid

    // Iterate through the vector and display events
    for (int i = 0; i < movies.getSize(); ++i) {
        Events *event = movies.get(i); // Use get() method to access the event

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
        detailsButton->setFixedWidth(180); // Consistent button width

        // Connect the "Details" button to show event details in a message box when clicked
        QObject::connect(detailsButton, &QPushButton::clicked, [event]() {
            QMessageBox::information(nullptr, "Event Details", event->getDetails());
        });

        // Add widgets to event layout
        eventLayout->addWidget(photoLabel, 0, Qt::AlignCenter);
        eventLayout->addWidget(titleLabel, 0, Qt::AlignCenter);
        eventLayout->addWidget(dateLabel, 0, Qt::AlignCenter);
        eventLayout->addWidget(detailsButton, 0, Qt::AlignCenter);
        eventLayout->setAlignment(Qt::AlignCenter);

        // Add event widget to grid layout
        gridLayout->addWidget(eventWidget, i / 2, i % 2); // Arrange items in a grid (2 items per row)
    }

    // Finalize scroll area
    scrollWidget->setLayout(gridLayout);
    scrollArea->setWidget(scrollWidget);
    mainLayout->addWidget(scrollArea);

    // Set main window properties
    mainWindow.setLayout(mainLayout);
    mainWindow.setStyleSheet("background-color: #B4E7E2; padding: 20px; color: #2F4F4F;"); // Teal background for the window
    mainWindow.show();


    return EventWindow.exec();
}
