#ifndef EVENTSS_H
#define EVENTSS_H

#include <QDialog>
#include <QString>
#include <QPixmap>

namespace Ui {
class Eventss;  // Forward declaration of the UI class
}

class Eventss : public QDialog
{
    Q_OBJECT

private:
    int eventId;
    QString title;
    int duration;
    QString date;
    double price;
    QPixmap image;
    Ui::Eventss *ui;  // Declare the UI pointer

public:
    // Default constructor
    explicit Eventss(QWidget *parent = nullptr);

    // Parameterized constructor
    Eventss(int id, const QString &t, int d, const QString &da, double p, const QPixmap &img);

    // Destructor
    ~Eventss();

    // Deleted copy constructor
    Eventss(const Eventss& other) = delete;

    // Move constructor
    Eventss(Eventss&& other) noexcept;

    // Deleted copy assignment operator
    Eventss& operator=(const Eventss& other) = delete;

    // Move assignment operator
    Eventss& operator=(Eventss&& other) noexcept;

    // Getter methods
    int getEventID() const;
    QString getTitle() const;
    int getDuration() const;
    QString getDate() const;
    QPixmap getImage() const;

    // Setter methods
    void setEventID(int id);
    void setTitle(const QString &title);
    void setDuration(int duration);
    void setDate(const QString &date);
    void setPrice(double price);
};

#endif // EVENTSS_H
