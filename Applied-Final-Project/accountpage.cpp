#include "accountpage.h"
#include "ui_accountpage.h"


AccountPage::AccountPage(Customer* customer,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AccountPage)
{
    ui->setupUi(this);
    C =customer;
    ui->NameLine->setText(QString::fromStdString(C->name));
    ui->EmailLine->setText(QString::fromStdString(C->email));
    ui->IDLine->setText(QString::number(C->customerID));
    ui->MemStautsLine->setText(C->IsVIP ? "VIP" : "Standard");
    ui->BalanceLine->setText(QString::number(C->getbalance()));
}

AccountPage::~AccountPage()
{
    delete ui;
}
