#include "events.h"
#include <QString>
#include <QPixmap>

// Constructor
Events::Events(int id, const QString &t, int d, const QString &da, double p, const QPixmap &img)
    : eventId(id), title(t), duration(d), date(da), price(p), image(img) {}

// Move constructor
Events::Events(Events &&other) noexcept
    : eventId(other.eventId),
    title(std::move(other.title)),
    duration(other.duration),
    date(std::move(other.date)),
    price(other.price),
    image(std::move(other.image)) {}

// Move assignment operator
Events &Events::operator=(Events &&other) noexcept {
    if (this != &other) {
        eventId = other.eventId;
        title = std::move(other.title);
        duration = other.duration;
        date = std::move(other.date);
        price = other.price;
        image = std::move(other.image);
    }
    return *this;
}

// Destructor
Events::~Events() {
    // If any dynamically allocated resources are added in the future, free them here
}

// Getters
int Events::getEventID() const { return eventId; }
QString Events::getTitle() const { return title; }
int Events::getDuration() const { return duration; }
QString Events::getDate() const { return date; }
QPixmap Events::getImage() const { return image; }

// Returns event details as a formatted string
QString Events::getDetails() const {
    return QString("Event ID: %1\nTitle: %2\nDuration: %3 minutes\nDate: %4\nPrice: $%5")
        .arg(eventId)
        .arg(title)
        .arg(duration)
        .arg(date)
        .arg(price);
}

// Setters
void Events::setEventID(int id) { eventId = id; }
void Events::setTitle(const QString &t) { title = t; }
void Events::setDuration(int d) { duration = d; }
void Events::setDate(const QString &da) { date = da; }
void Events::setPrice(double p) { price = p; }
