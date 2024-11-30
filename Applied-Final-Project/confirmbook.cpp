#include "confirmbook.h"
#include "ui_confirmbook.h"

ConfirmBook::ConfirmBook(Events* e,Customer*c,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConfirmBook)
{
    ui->setupUi(this);
}

ConfirmBook::~ConfirmBook()
{
    delete ui;
}
//ConfirmBook(Event* event, Customer* C,QWidget *parent = nullptr);
