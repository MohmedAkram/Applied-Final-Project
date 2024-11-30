#include "customerlogin.h"
#include "ui_customerlogin.h"
#include "splaytree.h"
#include "system.h"
#include "registerwindow.h"
#include <QMessageBox>
#include "eventwindow2.h"
#include "customer.h"

CustomerLogin::CustomerLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CustomerLogin)
{
    ui->setupUi(this);
}

CustomerLogin::~CustomerLogin()
{
    delete ui;
}

void CustomerLogin::on_LoginButton_clicked()
{
    QString ID = ui->CustomerIDSignIn->text();
    QString Password = ui->CustomerPasswordSignIn->text();
    int IDint = ID.toInt();
    std::string password = Password.toStdString();
    Customer customer(IDint, "", "", true, password);

    auto c = sys.CustomerTree.findNode(customer);
    if (c != nullptr && c->customer.Password == password)
    {
        Customer *C;
        C= new Customer(c->customer.customerID,c->customer.name,c->customer.email,c->customer.IsVIP,c->customer.Password);
        EventWindow2* eve2= new EventWindow2(C);
        eve2->show();
        this->hide();

    }
    else
    {
        QMessageBox::warning(this, "Login Failed", "Incorrect ID or Password. Please try again.");
        ui->CustomerIDSignIn->clear();
        ui->CustomerPasswordSignIn->clear();
    }
}

void CustomerLogin::on_RegisterButton_clicked()
{
    RegisterWindow *registerwindow = new RegisterWindow(this);
    registerwindow->show();
    this->close(); // Close login window when signup is clicked
}
