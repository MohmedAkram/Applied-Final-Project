#include "accountpage.h"
#include "ui_accountpage.h"

AccountPage::AccountPage(Customer* customer, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AccountPage)
{
    ui->setupUi(this);
    C = customer;

    // Set background color and padding
    this->setStyleSheet("background-color: #B4E7E2; padding: 20px; color: #2F4F4F;");

    // Set window title
    setWindowTitle("Account Page");

    // Populate text fields with data
    ui->NameLine->setText(QString::fromStdString(C->name));
    ui->EmailLine->setText(QString::fromStdString(C->email));
    ui->IDLine->setText(QString::number(C->customerID));
    ui->MemStautsLine->setText(C->IsVIP ? "VIP" : "Standard");
    ui->BalanceLine->setText(QString::number(C->getbalance()));
    ui->add->setText(QString::number(0));

    // Define a common style for text fields
    QString textFieldStyle = R"(
        border-radius: 10px;
        background-color: #e6f7ff;
        padding: 2px 2px;
        font-size: 10px;
        font-family: Arial, sans-serif;
        border: 1px solid #FF69B4;
    )";

    // Apply styles to text fields
    ui->NameLine->setStyleSheet(textFieldStyle);
    ui->EmailLine->setStyleSheet(textFieldStyle);
    ui->IDLine->setStyleSheet(textFieldStyle);
    ui->MemStautsLine->setStyleSheet(textFieldStyle);
    ui->BalanceLine->setStyleSheet(textFieldStyle);
    ui->add->setStyleSheet(textFieldStyle);

    // Define a common style for buttons
    QString buttonStyle = R"(
        background-color: #FF69B4;
        color: white;
        font-size: 10px;
        font-family: Arial, sans-serif;
        padding: 5px 5px;
        border-radius: 5px;
        font-weight: bold;
        box-shadow: 0px 0px 10px rgba(255, 105, 180, 0.5);
    )";

    // Apply styles to buttons
    ui->add_balance->setStyleSheet(buttonStyle);
    ui->EditName->setStyleSheet(buttonStyle);
    ui->EditEmail->setStyleSheet(buttonStyle);
}

AccountPage::~AccountPage()
{
    delete ui;
}

void AccountPage::on_add_balance_clicked()
{
    C->editbalance(ui->add->text().toInt());
    hide();
    CreditCardWidget *c = new CreditCardWidget(C);
    c->show();
}

void AccountPage::on_EditName_clicked()
{
    C->editname(ui->NameLine->text().toStdString());
}

void AccountPage::on_EditEmail_clicked()
{
    C->editemail(ui->EmailLine->text().toStdString());
}
