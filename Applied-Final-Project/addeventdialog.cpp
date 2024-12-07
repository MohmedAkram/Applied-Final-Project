#include "AddEventDialog.h"
#include <QFileDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QPixmap>
#include "eventwindow1.h"
#include "movies.h"

AddEventDialog::AddEventDialog(QWidget *parent)
    : QDialog(parent),
    titleLineEdit(new QLineEdit(this)),
    durationSpinBox(new QSpinBox(this)),
    dateLineEdit(new QLineEdit(this)),
    priceSpinBox(new QDoubleSpinBox(this)),
    selectImageButton(new QPushButton("Select Image", this)),
    addEventButton(new QPushButton("Add Event", this)),
    logoutButton(new QPushButton("Logout", this))  // Add the Logout button
{
    // Layout setup
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Set background color and padding
    this->setStyleSheet("background-color: #B4E7E2; padding: 20px; color: #2F4F4F;");

    // Event title
    layout->addWidget(new QLabel("Event Title:"));
    layout->addWidget(titleLineEdit);

    // Event duration
    layout->addWidget(new QLabel("Duration (minutes):"));
    layout->addWidget(durationSpinBox);

    // Event date
    layout->addWidget(new QLabel("Event Date:"));
    layout->addWidget(dateLineEdit);

    // Event price
    layout->addWidget(new QLabel("Price:"));
    layout->addWidget(priceSpinBox);

    // Select image button
    layout->addWidget(selectImageButton);

    // Add event button
    layout->addWidget(addEventButton);

    // Logout button
    layout->addWidget(logoutButton);

    // Set button and input field styles
    QString textFieldStyle = R"(
        border-radius: 10px;
        background-color: #e6f7ff;
        padding: 2px 2px;
        font-size: 10px;
        font-family: Arial, sans-serif;
        border: 1px solid #FF69B4;
    )";
    titleLineEdit->setStyleSheet(textFieldStyle);
    dateLineEdit->setStyleSheet(textFieldStyle);
    durationSpinBox->setStyleSheet(textFieldStyle);
    priceSpinBox->setStyleSheet(textFieldStyle);

    QString buttonStyle = R"(
        background-color: #FF69B4;
        color: white;
        font-size: 14px;
        font-family: Arial, sans-serif;
        padding: 10px 20px;
        border-radius: 10px;
        font-weight: bold;
        box-shadow: 0px 0px 10px rgba(255, 105, 180, 0.5);
    )";
    selectImageButton->setStyleSheet(buttonStyle);
    addEventButton->setStyleSheet(buttonStyle);
    logoutButton->setStyleSheet(buttonStyle); // Style for Logout button

    // Connect buttons
    connect(selectImageButton, &QPushButton::clicked, this, &AddEventDialog::selectImage);
    connect(addEventButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(logoutButton, &QPushButton::clicked, this, &AddEventDialog::logout); // Connect Logout button
}

void AddEventDialog::logout() {
    // Close the current dialog and return to the EventsWindow
    this->close();  // Close the AddEventDialog

    // Create a new instance of EventsWindow1 and show it
    EventsWindow1 *eventsWindow = new EventsWindow1(nullptr,movies ); // Ensure you pass the necessary parameters to create the window
    eventsWindow->show();
}

QString AddEventDialog::getTitle() const {
    return titleLineEdit->text();
}

int AddEventDialog::getDuration() const {
    return durationSpinBox->value();
}

QString AddEventDialog::getDate() const {
    return dateLineEdit->text();
}

double AddEventDialog::getPrice() const {
    return priceSpinBox->value();
}

QPixmap AddEventDialog::getImage() const {
    return selectedImage;
}

void AddEventDialog::selectImage() {
    QString imagePath = QFileDialog::getOpenFileName(this, "Select Image", QString(), "Images (*.png *.jpg *.jpeg *.bmp)");
    if (!imagePath.isEmpty()) {
        selectedImage = QPixmap(imagePath);
    }
}
