#include "admin.h"

AdminWindow::AdminWindow(QWidget* parent)
    : QDialog(parent), mainLayout(new QVBoxLayout(this)), topBarLayout(new QHBoxLayout),
    addAdminButton(new QPushButton("Add Event", this)),
    removeAdminButton(new QPushButton("Remove Event", this)),
    logoutButton(new QPushButton("Logout", this))
{
    setupUI();
}

AdminWindow::~AdminWindow() {
    // Destructor
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

    removeAdminButton->setFixedSize(300, 60);
    removeAdminButton->setStyleSheet(
        "background-color: #FF69B4; color: white; font-size: 20px; font-weight: bold; padding: 15px; border-radius: 10px;");

    logoutButton->setFixedSize(300, 60);
    logoutButton->setStyleSheet(
        "background-color: #FF69B4; color: white; font-size: 20px; font-weight: bold; padding: 15px; border-radius: 10px;");

    // Buttons layout
    QVBoxLayout* buttonLayout = new QVBoxLayout;
    buttonLayout->setAlignment(Qt::AlignCenter);
    buttonLayout->setSpacing(40); // Increased spacing for better aesthetics
    buttonLayout->addWidget(addAdminButton, 0, Qt::AlignCenter);
    buttonLayout->addWidget(removeAdminButton, 0, Qt::AlignCenter);
    buttonLayout->addWidget(logoutButton, 0, Qt::AlignCenter);

    // Add buttons to main layout
    mainLayout->addSpacing(50); // Add space between the top bar and buttons
    mainLayout->addLayout(buttonLayout);

    // Main window styling
    setLayout(mainLayout);
    setStyleSheet("background-color: #B4E7E2; padding: 20px; border-radius: 15px;");
    setWindowTitle("Admin Page");
}
