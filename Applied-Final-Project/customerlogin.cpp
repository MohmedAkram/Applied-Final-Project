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

    // Style for input fields (line edits)
    QString lineEditStyle =
        "background-color: #f5f5f5;"     // Light-gray background
        "color: #333333;"                // Dark-gray text
        "font-size: 18px;"               // Larger, readable font
        "font-weight: normal;"           // Normal text weight

        "border-radius: 10px;"           // Slightly rounded corners
        "border: 1px solid #cccccc;";    // Subtle border

    ui->CustomerIDSignIn->setStyleSheet(lineEditStyle);
    ui->CustomerPasswordSignIn->setStyleSheet(lineEditStyle);

    // Ensure the cursor starts at the beginning
    ui->CustomerIDSignIn->setCursorPosition(0);
    ui->CustomerPasswordSignIn->setCursorPosition(0);

    // Style for buttons
    QString buttonStyle =
        "background-color: #007bff;"    // Blue background
        "color: white;"                 // White font color
        "font-size: 14px;"              // Medium font size
        "font-weight: bold;"            // Bold text

        "border-radius: 8px;"           // Rounded corners
        "border: 2px solid #0056b3;"    // Border matching button color
        "transition: background-color 0.3s ease;"  // Smooth transition for hover
        ""
        "QPushButton:hover {"
        "  background-color: #0056b3;"  // Darker blue on hover
        "  border-color: #003f7f;"      // Darker border on hover
        "}";

    ui->LoginButton->setStyleSheet(buttonStyle);
    ui->RegisterButton->setStyleSheet(buttonStyle);

    // Style for labels
    QString labelStyle =
        "color: #333333;"               // Dark-gray text color
        "font-size: 14px;"              // Clear font size
        "font-weight: bold;"            // Bold text

        "border: none;";                // No border for simplicity

    ui->IdLabel->setStyleSheet(labelStyle);
    ui->PasswordLabel->setStyleSheet(labelStyle);

    // Optional: Set a custom background color for the dialog

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
        eve2->showMaximized();
        this->hide();
        sys.ev->hide();

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
