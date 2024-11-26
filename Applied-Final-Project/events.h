#ifndef EVENTS_H
#define EVENTS_H

#include <QString>
#include <QPixmap>

namespace Ui {
class Events;
}

class Events {

private:

    int eventId;
    QString title;
    int duration;
    QString date;
    double price;
    QPixmap image;

public:
    // Constructors and Destructor
    explicit Events(QWidget *parent = nullptr);
    Events(int id, const QString &title, int duration, const QString &date, double price, const QPixmap &img);
    ~Events();

    // Rule of Five: Move Constructor and Assignment
    Events(Events &&other) noexcept;
    Events &operator=(Events &&other) noexcept;

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
