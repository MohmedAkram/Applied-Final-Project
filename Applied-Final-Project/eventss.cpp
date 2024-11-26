#include "eventss.h"
#include "ui_eventss.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

Eventss::Eventss(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Eventss)
{
    ui->setupUi(this);
}

Eventss::Eventss(int id, const QString &t, int d, const QString &da, double p, const QPixmap &img)
    : QDialog(nullptr), // No UI here for data-only object
    ui(nullptr),       // No UI here for data-only object
    eventId(id),
    title(t),
    duration(d),
    date(da),
    price(p),
    image(img)
{
}

Eventss::~Eventss() {
    delete ui;
}

// Move constructor
Eventss::Eventss(Eventss &&other) noexcept
    : QDialog(nullptr),
    ui(other.ui),
    eventId(other.eventId),
    title(std::move(other.title)),
    duration(other.duration),
    date(std::move(other.date)),
    price(other.price),
    image(std::move(other.image))
{
    other.ui = nullptr;
}

// Move assignment operator
Eventss& Eventss::operator=(Eventss &&other) noexcept {
    if (this != &other) {
        delete ui;

        eventId = other.eventId;
        title = std::move(other.title);
        duration = other.duration;
        date = std::move(other.date);
        price = other.price;
        image = std::move(other.image);

        other.ui = nullptr;
    }
    return *this;
}

// Getters
int Eventss::getEventID() const { return eventId; }
QString Eventss::getTitle() const { return title; }  // This should return the correct title
int Eventss::getDuration() const { return duration; }
QString Eventss::getDate() const { return date; }
QPixmap Eventss::getImage() const { return image; }

// Setters
void Eventss::setEventID(int id) { eventId = id; }
void Eventss::setTitle(const QString &t) { title = t; }
void Eventss::setDuration(int d) { duration = d; }
void Eventss::setDate(const QString &da) { date = da; }
void Eventss::setPrice(double p) { price = p; }
