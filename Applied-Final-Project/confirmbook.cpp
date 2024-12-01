#include "confirmbook.h"
#include "ui_confirmbook.h"

ConfirmBook::ConfirmBook(Events* e,Customer*c,Seats *s,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConfirmBook)
{
    Customer* Cu =c;
    T =s->totalPrice;
    setseatnum(s->selectedSeats);
    ui->setupUi(this);
    ui->HallEdit->setText(QString::number(e->getEventID()));
    ui->Moviename->setText(e->getTitle());
    ui->WalletEdit->setText(QString::number(c->getbalance()));
    ui->SeatEdit->setText(QString::fromStdString(seatnumber));
    ui->PriceEdit->setText(QString::number(T));
    Rbalance= c->getbalance() - T ;
    ui->RemainingEdit->setText(QString::number(Rbalance));
}

ConfirmBook::~ConfirmBook()
{
    delete ui;
}
//ConfirmBook(Event* event, Customer* C,QWidget *parent = nullptr);




void ConfirmBook::on_Confirm_clicked()
{
    if (Rbalance<0){
        QMessageBox::warning(this, "No suficient balance", "Please add balance first");
        return;
    }
    else
        Cu->editbalance(-T);
}

