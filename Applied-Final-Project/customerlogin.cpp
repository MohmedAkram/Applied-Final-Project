#include "customerlogin.h"
#include "ui_customerlogin.h"
#include "splaytree.h"
#include "system.h"
#include "registerwindow.h"

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
   Customer customer(IDint, "","",true,password);
    if(sys.CustomerTree.findNode(customer) != nullptr &&sys.CustomerTree.findNode(customer)->customer.Password == password )
    {
        sys.CustomerTree.printInOrder();
    }
    else
    {
        // Incorrect password or user not found.
        QMessageBox::warning(this, "Login Failed", "Incorrect ID or Password. Please try again.");

        // Clear input fields for retry.
        ui->CustomerIDSignIn->clear();
        ui->CustomerPasswordSignIn->clear();
    }




}


void CustomerLogin::on_RegisterButton_clicked()
{
    RegisterWindow *registerwindow = new RegisterWindow(this);
    registerwindow->show();
    this->hide();
}

