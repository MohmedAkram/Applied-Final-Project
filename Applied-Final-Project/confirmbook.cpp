#include "confirmbook.h"
#include "ui_confirmbook.h"
#include "system.h"

ConfirmBook::ConfirmBook(Events* e,Customer*c,Seats *s,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConfirmBook)
{
    C =c;
    E=e;
    S=s;
    T =s->totalPrice;
    setseatnum(s->selectedSeats);
    ui->setupUi(this);
    ui->HallEdit->setText(QString::number(e->getEventID()));
    ui->Moviename->setText(e->getTitle());
    ui->WalletEdit->setText(QString::number(c->getbalance()));
    //ui->SeatEdit->setText(QString::number(s);
    ui->PriceEdit->setText(QString::number(T));
    Rbalance= c->getbalance() - T ;
    ui->RemainingEdit->setText(QString::number(Rbalance));
    if (s->Time==1)
        ui->TimeEdit->setText("4:00 pm");
    else if (s->Time==2)
        ui->TimeEdit->setText("7:00 pm");
    else if (s->Time==3)
        ui->TimeEdit->setText("10:00 pm");
}

ConfirmBook::~ConfirmBook()
{
    delete ui;
}

void ConfirmBook::on_Confirm_clicked()
{
    if (Rbalance<0){
        QMessageBox::warning(this, "No suficient balance", "Please add balance first");
        return;
    }
    else{
        C->editbalance(-T);
        for(int i=0;i<seatnumber.size();i++){
            sys.TDB[E->getEventID()][S->Time][seatnumber[i]]->status=true;
            C->ReservedTickets.push(sys.TDB[E->getEventID()][S->Time][seatnumber[i]]);
        }
    }
}

