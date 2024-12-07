#ifndef ADDEVENTDIALOG_H
#define ADDEVENTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QFileDialog>

class AddEventDialog : public QDialog {
    Q_OBJECT

public:
    AddEventDialog(QWidget *parent = nullptr);
    QString getTitle() const;
    QString getDate() const;
    int getDuration() const;
    double getPrice() const;
    QPixmap getImage() const;

private:
    QLineEdit *titleEdit;
    QLineEdit *dateEdit;
    QSpinBox *durationSpinBox;
    QDoubleSpinBox *priceSpinBox;
    QLabel *imagePreview;
    QPixmap eventImage;
    QPushButton *browseButton;
};

#endif // ADDEVENTDIALOG_H
