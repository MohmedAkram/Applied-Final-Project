#ifndef EVENTS_H
#define EVENTS_H

#include <QString>
#include <QPixmap>
#include"vectorc.h"

class Events {
private:
    int eventId;          // Unique ID for the event
    QString title;        // Event title
    int duration;         // Duration in minutes
    QString date;         // Date of the event
    double price;         // Price of the event
    QPixmap image;        // Event image

public:
    // Constructors and Destructor


    Events(int id, const QString &title, int duration, const QString &date, double price, const QPixmap &img);
    Events(const Events &other) = delete;             // Delete copy constructor
    Events &operator=(const Events &other) = delete;  // Delete copy assignment operator
    Events(Events &&other) noexcept;                 // Move constructor
    Events &operator=(Events &&other) noexcept;      // Move assignment operator
    ~Events();                                       // Destructor

    // Getters
    int getEventID() const;
    QString getTitle() const;
    int getDuration() const;
    QString getDate() const;
    QPixmap getImage() const;
    QString getDetails() const;

    // Setters
    void setEventID(int id);
    void setTitle(const QString &title);
    void setDuration(int duration);
    void setDate(const QString &date);
    void setPrice(double price);
};

#endif // EVENTS_H
