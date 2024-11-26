#include "mainwindow.h"
<<<<<<< HEAD
#include "system.h"
#include "customer.h"
#include "customerlogin.h"

#include <QApplication>
extern System sys;
int main(int argc, char *argv[])
{
    Customer customer(1234,"wwwerffrf","rfefr",true,"lol");
    sys.CustomerTree.insert(customer);
    sys.CustomerTree.printInOrder();

    QApplication a(argc, argv);
    CustomerLogin w;
    w.show();
    return a.exec();







=======
#include "eventss.h"
#include "vectorc.h"
#include <QApplication>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Create a vectorC to hold events
    vectorC<Eventss> movies(10);

    // Define and add events to vectorC
    QPixmap www(":/immages/welad rizk betterr.jpg");

    Eventss* event1 = new Eventss(1, "Name: Welad Rizk III", 2023, "08-2023", 200.00, www);
    Eventss* event2 = new Eventss(1, "Name: Welad Rizk III", 2023, "08-2023", 200.00, www);
    Eventss* event3 = new Eventss(1, "Name: Welad Rizk III", 2023, "08-2023", 200.00, www);
    Eventss* event4 = new Eventss(1, "Name: Welad Rizk III", 2023, "08-2023", 200.00, www);
    Eventss* event5 = new Eventss(1, "Name: Welad Rizk III", 2023, "08-2023", 200.00, www);
    Eventss* event6 = new Eventss(1, "Name: Welad Rizk III", 2023, "08-2023", 200.00, www);
    Eventss* event7 = new Eventss(1, "Name: Welad Rizk III", 2023, "08-2023", 200.00, www);
    Eventss* event8 = new Eventss(1, "Name: Welad Rizk III", 2023, "08-2023", 200.00, www);

    movies.push(event1);
    movies.push(event2);
    movies.push(event3);
    movies.push(event4);
    movies.push(event5);
    movies.push(event6);
    movies.push(event7);
    movies.push(event8);

    // Create main window and scrollable layout
    QDialog mainWindow;
    QVBoxLayout *mainLayout = new QVBoxLayout(&mainWindow);

    QScrollArea *scrollArea = new QScrollArea(&mainWindow);
    scrollArea->setWidgetResizable(true);
    QWidget *scrollWidget = new QWidget;
    QGridLayout *gridLayout = new QGridLayout(scrollWidget); // Use a grid layout for side-by-side items
    gridLayout->setSpacing(30); // Larger spacing between items
    gridLayout->setContentsMargins(40, 40, 40, 40); // Larger margins around the grid

    // Iterate through the vector and display events
    for (int i = 0; i < movies.getSize(); ++i) {
        Eventss *event = movies.get(i); // Use get() method to access the event

        // Event container
        QWidget *eventWidget = new QWidget;
        eventWidget->setFixedSize(600, 600); // Larger size for each event box
        eventWidget->setStyleSheet(
            "border-radius: 15px;"
            "background-color: #2c2c2c;" // Solid dark background
            "box-shadow: 0 6px 15px rgba(0, 0, 0, 0.6);"
            );

        QVBoxLayout *eventLayout = new QVBoxLayout(eventWidget);

        // Photo
        QLabel *photoLabel = new QLabel(eventWidget);
        photoLabel->setPixmap(event->getImage().scaled(580, 300, Qt::KeepAspectRatio)); // Larger image size
        photoLabel->setAlignment(Qt::AlignCenter);
        photoLabel->setStyleSheet(
            "border-radius: 15px;"
            "border: 3px solid #800080;"  // Add a border with purple color for better definition
            "box-shadow: 0 4px 8px rgba(0, 0, 0, 0.4);"  // Add shadow for depth effect
            "padding: 10px;"
            "QLabel:hover {"
            "  box-shadow: 0 8px 16px rgba(0, 0, 0, 0.6);" // Stronger shadow on hover
            "}"
            );

        // Event details
        QLabel *titleLabel = new QLabel(event->getTitle(), eventWidget);
        titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: white; text-align: center; margin-top: 15px;");

        QLabel *dateLabel = new QLabel(event->getDate(), eventWidget);
        dateLabel->setStyleSheet("color: #aaaaaa; font-size: 18px; text-align: center; margin-bottom: 20px;");

        // Details button (purple background)
        QPushButton *detailsButton = new QPushButton("Details", eventWidget);
        detailsButton->setStyleSheet(
            "background-color: #800080; color: white; font-size: 18px; padding: 12px 20px;"
            "border: none; border-radius: 5px; font-weight: bold;"
            "transition: 0.3s;"
            "box-shadow: 0px 0px 10px rgba(128, 0, 128, 0.5);"
            "QPushButton:hover {"
            "background-color: #800080;"  // Same purple color on hover
            "box-shadow: 0px 0px 20px rgba(160, 32, 240, 0.8);"
            "}"
            );
        detailsButton->setFixedWidth(180); // Consistent button width

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
    mainWindow.setStyleSheet("background-color: #1e1e1e; padding: 20px; color: #ffffff;"); // Dark background
    mainWindow.show();

    return a.exec();
>>>>>>> b035ea2 (karim)
}
