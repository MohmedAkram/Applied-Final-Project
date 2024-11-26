#include "customerlogin.h"
#include "ui_customerlogin.h"
#include "splaytree.h"
#include "system.h"

System sys;
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
    if(sys.CustomerTree.findNode(customer)->customer.Password == password )
    {
        cout<<"sucesssssssssssss";
    }



}

