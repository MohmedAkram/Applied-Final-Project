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
    ui->add->setText(QString::number(0));
}

AccountPage::~AccountPage()
{
    delete ui;
}

void AccountPage::on_add_balance_clicked()
{
    C->editbalance(ui->add->text().toInt());
    ui->BalanceLine->setText(QString::number(C->getbalance()));
    ui->add->setText(QString::number(0));
}


void AccountPage::on_EditName_clicked()
{
    C->editname(ui->NameLine->text().toStdString());
}


void AccountPage::on_EditEmail_clicked()
{
    C->editemail(ui->EmailLine->text().toStdString());
}

