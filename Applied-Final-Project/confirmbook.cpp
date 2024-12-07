#include "confirmbook.h"
#include "ui_confirmbook.h"
#include "system.h"


ConfirmBook::ConfirmBook(Events* e, Customer* c, Seats* s, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConfirmBook)
{
    C = c;
    E = e;
    S = s;
    T = s->totalPrice;

    // Convert QVector<int> to QString
    QStringList seatStrings;
    for (int seatId : s->selectedSeats) {
        seatStrings.append(QString::number(seatId));
    }

    // Join the list with a comma separator
    QString seat = seatStrings.join(", ");

    ui->setupUi(this);
    ui->HallEdit->setText(QString::number(e->getEventID()));
    ui->Moviename->setText(e->getTitle());
    ui->WalletEdit->setText(QString::number(c->getbalance()));
    ui->SeatEdit->setText(seat);  // Display the selected seats here
    ui->PriceEdit->setText(QString::number(T));
    Rbalance = c->getbalance() - T;
    ui->RemainingEdit->setText(QString::number(Rbalance));

    if (s->Time == 1)
        ui->TimeEdit->setText("4:00 pm");
    else if (s->Time == 2)
        ui->TimeEdit->setText("7:00 pm");
    else if (s->Time == 3)
        ui->TimeEdit->setText("10:00 pm");
}

ConfirmBook::~ConfirmBook()
{
    delete ui;
}
void ConfirmBook::on_Confirm_clicked()
{
    if (Rbalance < 0) {
        QMessageBox::warning(this, "Insufficient balance", "Please add balance first");
        return;
    } else {
        C->editbalance(-T);
            // Deduct the amount from the customer's balance

        for (int i = 0; i < S->selectedSeats.size(); i++) // Debugging: Check the selected seats
            qDebug() << "Selected seats:"<< S->selectedSeats[i];
        for (int i = 0; i < S->selectedSeats.size(); i++) {
            int seatIndex = (S->selectedSeats[i])-1; // Get the seat index (ID)
            qDebug() << "Seat Index:" << seatIndex;

            // Validate seat index within valid range for this event and time

            if (seatIndex >= 0 && seatIndex < 40)
            {
                qDebug() << "Booking seat:" << seatIndex;
                sys.TDB[E->getEventID()-1][S->Time][seatIndex]->status = true; // Mark seat as booked
                C->ReservedTickets.push(sys.TDB[E->getEventID()-1][S->Time][seatIndex]);// Add to reserved tickets
            } else {
                qDebug() << "Invalid seat index" << seatIndex << "for this event and time.";
            }
        }
        this->close();
    }


}

