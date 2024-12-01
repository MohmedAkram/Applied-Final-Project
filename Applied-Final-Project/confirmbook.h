#ifndef CONFIRMBOOK_H
#define CONFIRMBOOK_H
#include "customer.h"
#include "events.h"
#include <QDialog>
#include"seats.h"
#include <QMessageBox>

namespace Ui {
class ConfirmBook;
}

class ConfirmBook : public QDialog
{
    Q_OBJECT
public:
    double T;
    string seatnumber;
    double Rbalance;
    Customer* Cu;
    void setseatnum(QVector<QString> selectedSeats){
        seatnumber= selectedSeats.join(", ").toStdString();
    };
    explicit ConfirmBook(Events* e,Customer*c,Seats *s,QWidget *parent = nullptr);
    ~ConfirmBook();


private slots:
    void on_Confirm_clicked();

private:
    Ui::ConfirmBook *ui;
};

#endif // CONFIRMBOOK_H
