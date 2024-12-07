#ifndef ADDEVENTDIALOG_H
#define ADDEVENTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QPixmap>

class AddEventDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddEventDialog(QWidget *parent = nullptr);

    QString getTitle() const;
    int getDuration() const;
    QString getDate() const;
    double getPrice() const;
    QPixmap getImage() const;

private slots:
    void selectImage();  // Slot for selecting image
    void logout();       // Slot for logging out and returning to EventsWindow

private:
    QLineEdit *titleLineEdit;
    QSpinBox *durationSpinBox;
    QLineEdit *dateLineEdit;
    QDoubleSpinBox *priceSpinBox;
    QPushButton *selectImageButton;
    QPixmap selectedImage;
    QPushButton *addEventButton;
    QPushButton *logoutButton;  // Logout button
};

#endif // ADDEVENTDIALOG_H
