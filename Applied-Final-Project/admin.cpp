#include "admin.h"
#include "AddEventDialog.h"  // Include the custom dialog header
#include "events.h"
#include "vectorc.h"
#include "movies.h"
#include "eventwindow1.h"  // Include the EventsWindow1 header

AdminWindow::AdminWindow(QWidget* parent)
    : QDialog(parent), mainLayout(new QVBoxLayout(this)), topBarLayout(new QHBoxLayout),
    addAdminButton(new QPushButton("Add Event", this)),
    logoutButton(new QPushButton("Logout", this))  // Remove removeAdminButton
{
    setupUI();

    // Connect the "Add Event" button to the slot
    connect(addAdminButton, &QPushButton::clicked, this, &AdminWindow::onAddEventClicked);

    // Connect the "Logout" button to the logout slot
    connect(logoutButton, &QPushButton::clicked, this, &AdminWindow::onLogoutClicked);
}

AdminWindow::~AdminWindow() {
    // Destructor implementation (any necessary cleanup can go here)
}

void AdminWindow::setupUI()
{
    // Set fixed size to make the window bigger
    setFixedSize(1200, 800);

    // Top bar layout
    QLabel* titleLabel = new QLabel("Admin Page", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 36px; font-weight: bold; color: white; margin: 0px;");
    topBarLayout->addWidget(titleLabel, 0, Qt::AlignCenter);

    // Top bar styling
    QWidget* topBarWidget = new QWidget(this);
    topBarWidget->setLayout(topBarLayout);
    topBarWidget->setStyleSheet("background-color: #FF69B4; padding: 20px; border-radius: 10px;");
    mainLayout->addWidget(topBarWidget);

    // Buttons styling
    addAdminButton->setFixedSize(300, 60);
    addAdminButton->setStyleSheet(
        "background-color: #FF69B4; color: white; font-size: 20px; font-weight: bold; padding: 15px; border-radius: 10px;");

    logoutButton->setFixedSize(300, 60);
    logoutButton->setStyleSheet(
        "background-color: #FF69B4; color: white; font-size: 20px; font-weight: bold; padding: 15px; border-radius: 10px;");

    // Buttons layout
    QVBoxLayout* buttonLayout = new QVBoxLayout;
    buttonLayout->setAlignment(Qt::AlignCenter);
    buttonLayout->setSpacing(40); // Increased spacing for better aesthetics
    buttonLayout->addWidget(addAdminButton, 0, Qt::AlignCenter);
    buttonLayout->addWidget(logoutButton, 0, Qt::AlignCenter);  // Remove the removeAdminButton

    // Add buttons to main layout
    mainLayout->addSpacing(50); // Add space between the top bar and buttons
    mainLayout->addLayout(buttonLayout);

    // Main window styling
    setLayout(mainLayout);
    setStyleSheet("background-color: #B4E7E2; padding: 20px; border-radius: 15px;");
    setWindowTitle("Admin Page");
}

void AdminWindow::onAddEventClicked() {
    AddEventDialog dialog(this); // Create the AddEventDialog

    // Show the dialog and wait for the user to provide the details
    if (dialog.exec() == QDialog::Accepted) {
        // Get event details from the dialog
        QString title = dialog.getTitle();
        int duration = dialog.getDuration();
        QString date = dialog.getDate();
        double price = dialog.getPrice();
        QPixmap image = dialog.getImage();

        // Create a new event
        Events* newEvent = new Events(movies.getSize() + 1, title, duration, date, price, image);

        // Add the new event to the movies vector
        movies.push(newEvent);

        // Optionally: Update the UI or notify the user that the event was added successfully
        // QMessageBox::information(this, "Event Added", "The event has been added successfully!");
    }
}

void AdminWindow::onLogoutClicked() {
    // Close the current AdminWindow
    this->close();

    // Create a new instance of EventsWindow1 and show it
    EventsWindow1 *eventsWindow = new EventsWindow1(nullptr, movies); // Assuming movies is accessible
    eventsWindow->show();
}
