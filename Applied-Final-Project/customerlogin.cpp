#include "customerlogin.h"
#include "ui_customerlogin.h"
#include "splaytree.h"
#include "system.h"
#include "registerwindow.h"
#include <QMessageBox>
#include "eventwindow2.h"
#include "customer.h"
#include "admin.h"
 #include  "movies.h"

CustomerLogin::CustomerLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CustomerLogin)
{
    ui->setupUi(this);

    // Style for input fields (line edits)
    QString lineEditStyle =
        "background-color: white;"       // White background
        "color: black;"                  // Black text color
        "font-size: 16px;"               // Readable font size
        "font-weight: normal;"           // Normal text weight
        "border: 2px solid #FF69B4;"     // Pink border
        "border-radius: 10px;"           // Rounded corners
        "padding: 5px;";                 // Padding inside the box

    ui->CustomerIDSignIn->setStyleSheet(lineEditStyle);
    ui->CustomerPasswordSignIn->setStyleSheet(lineEditStyle);

    // Ensure the cursor starts at the beginning
    ui->CustomerIDSignIn->setCursorPosition(0);
    ui->CustomerPasswordSignIn->setCursorPosition(0);

    // Style for buttons
    QString buttonStyle =
        "background-color: #007bff;"     // Blue background
        "color: white;"                  // White text color
        "font-size: 18px;"               // Larger font size
        "font-weight: bold;"             // Bold text
        "border: 2px solid #FF69B4;"     // Pink border
        "border-radius: 12px;"           // Rounded corners
        "padding: 10px 20px;"            // Larger size for buttons
        "transition: background-color 0.3s ease;"  // Smooth transition for hover
        ""
        "QPushButton:hover {"
        "  background-color: #0056b3;"   // Darker blue on hover
        "  border-color: #003f7f;"       // Darker border on hover
        "}";

    ui->LoginButton->setStyleSheet(buttonStyle);
    ui->RegisterButton->setStyleSheet(buttonStyle);

    // Style for labels
    QString labelStyle =
        "color: #333333;"                // Dark-gray text color
        "font-size: 14px;"               // Clear font size
        "font-weight: bold;"             // Bold text
        "border: none;";                 // No border

    ui->IdLabel->setStyleSheet(labelStyle);
    ui->PasswordLabel->setStyleSheet(labelStyle);
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
        C = new Customer(c->customer.customerID, c->customer.name, c->customer.email, c->customer.IsVIP, c->customer.Password);
        EventWindow2* eve2 = new EventWindow2(C, this, movies);
        eve2->showMaximized();
        this->hide();
        sys.ev->hide();
    }

    else if (IDint== 1000 && Password =="1000"   ){
        AdminWindow *e= new AdminWindow;

        e->show();
        hide();
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
    RegisterWindow* registerwindow = new RegisterWindow(this);
    registerwindow->show();
    this->close(); // Close login window when signup is clicked
}
