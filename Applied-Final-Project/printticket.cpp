#include "printticket.h"
#include "ui_printticket.h"

PrintTicket::PrintTicket(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PrintTicket)
{
    ui->setupUi(this);
}

PrintTicket::~PrintTicket()
{
    delete ui;
}
