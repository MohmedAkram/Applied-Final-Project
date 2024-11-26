#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "customer.h"
#include "system.h"
#include "customerlogin.h"
RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButton_clicked()
{
    QString Email = ui->EmailInput->text();
    QString id = ui->IDinput->text();
    QString Name= ui->NameInput->text();
    QString Password= ui->PassInput->text();
    int IDint = id.toInt();
    std::string password = Password.toStdString();
    std::string email = Email.toStdString();
    std::string name = Name.toStdString();
    Customer newcustomer(IDint,name,email,false,password);
    sys.CustomerTree.insert(newcustomer);
    ui->EmailInput->clear();
    ui->IDinput->clear();
    ui->NameInput->clear();
    ui->PassInput->clear();
    CustomerLogin* customerlogin = new CustomerLogin(this);
    customerlogin->show();
    sys.CustomerTree.printInOrder();
    //close();





}

