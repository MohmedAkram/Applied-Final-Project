#include "confirmbook.h"
#include "ui_confirmbook.h"

ConfirmBook::ConfirmBook(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConfirmBook)
{
    ui->setupUi(this);
}

ConfirmBook::~ConfirmBook()
{
    delete ui;
}
