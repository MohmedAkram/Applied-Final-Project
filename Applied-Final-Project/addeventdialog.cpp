#include "AddEventDialog.h"

AddEventDialog::AddEventDialog(QWidget *parent)
    : QDialog(parent), titleEdit(new QLineEdit(this)), dateEdit(new QLineEdit(this)),
    durationSpinBox(new QSpinBox(this)), priceSpinBox(new QDoubleSpinBox(this)),
    imagePreview(new QLabel(this)), browseButton(new QPushButton("Browse Image", this)) {

    setWindowTitle("Add New Event");
    setFixedSize(400, 400);

    // Layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Title input
    QLabel *titleLabel = new QLabel("Title:");
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(titleEdit);

    // Date input
    QLabel *dateLabel = new QLabel("Date:");
    mainLayout->addWidget(dateLabel);
    mainLayout->addWidget(dateEdit);

    // Duration input
    QLabel *durationLabel = new QLabel("Duration (minutes):");
    mainLayout->addWidget(durationLabel);
    durationSpinBox->setRange(1, 500);
    mainLayout->addWidget(durationSpinBox);

    // Price input
    QLabel *priceLabel = new QLabel("Price:");
    mainLayout->addWidget(priceLabel);
    priceSpinBox->setRange(0, 10000);
    priceSpinBox->setDecimals(2);
    mainLayout->addWidget(priceSpinBox);

    // Image selection
    QLabel *imageLabel = new QLabel("Event Image:");
    mainLayout->addWidget(imageLabel);
    QHBoxLayout *imageLayout = new QHBoxLayout();
    imageLayout->addWidget(imagePreview);
    imageLayout->addWidget(browseButton);
    mainLayout->addLayout(imageLayout);

    // Image preview setup
    imagePreview->setFixedSize(100, 100);
    imagePreview->setStyleSheet("border: 1px solid #000;");
    imagePreview->setAlignment(Qt::AlignCenter);

    connect(browseButton, &QPushButton::clicked, this, [this]() {
        QString imagePath = QFileDialog::getOpenFileName(this, "Select Image", "", "Images (*.png *.jpg *.jpeg)");
        if (!imagePath.isEmpty()) {
            eventImage.load(imagePath);
            imagePreview->setPixmap(eventImage.scaled(100, 100, Qt::KeepAspectRatio));
        }
    });

    // Confirm and cancel buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *addButton = new QPushButton("Add");
    QPushButton *cancelButton = new QPushButton("Cancel");
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);

    connect(addButton, &QPushButton::clicked, this, &AddEventDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &AddEventDialog::reject);
}

QString AddEventDialog::getTitle() const { return titleEdit->text(); }
QString AddEventDialog::getDate() const { return dateEdit->text(); }
int AddEventDialog::getDuration() const { return durationSpinBox->value(); }
double AddEventDialog::getPrice() const { return priceSpinBox->value(); }
QPixmap AddEventDialog::getImage() const { return eventImage; }
