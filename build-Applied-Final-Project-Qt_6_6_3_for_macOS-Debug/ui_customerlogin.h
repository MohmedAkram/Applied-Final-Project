/********************************************************************************
** Form generated from reading UI file 'customerlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERLOGIN_H
#define UI_CUSTOMERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CustomerLogin
{
public:
    QLabel *IdLabel;
    QLabel *PasswordLabel;
    QLineEdit *CustomerIDSignIn;
    QLineEdit *CustomerPasswordSignIn;
    QPushButton *LoginButton;
    QPushButton *RegisterButton;

    void setupUi(QDialog *CustomerLogin)
    {
        if (CustomerLogin->objectName().isEmpty())
            CustomerLogin->setObjectName("CustomerLogin");
        CustomerLogin->resize(677, 350);
        IdLabel = new QLabel(CustomerLogin);
        IdLabel->setObjectName("IdLabel");
        IdLabel->setGeometry(QRect(142, 100, 101, 20));
        PasswordLabel = new QLabel(CustomerLogin);
        PasswordLabel->setObjectName("PasswordLabel");
        PasswordLabel->setGeometry(QRect(112, 150, 121, 20));
        CustomerIDSignIn = new QLineEdit(CustomerLogin);
        CustomerIDSignIn->setObjectName("CustomerIDSignIn");
        CustomerIDSignIn->setGeometry(QRect(240, 100, 201, 28));
        CustomerPasswordSignIn = new QLineEdit(CustomerLogin);
        CustomerPasswordSignIn->setObjectName("CustomerPasswordSignIn");
        CustomerPasswordSignIn->setGeometry(QRect(240, 150, 201, 28));
        LoginButton = new QPushButton(CustomerLogin);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(190, 220, 101, 51));
        RegisterButton = new QPushButton(CustomerLogin);
        RegisterButton->setObjectName("RegisterButton");
        RegisterButton->setGeometry(QRect(320, 220, 111, 51));

        retranslateUi(CustomerLogin);

        QMetaObject::connectSlotsByName(CustomerLogin);
    } // setupUi

    void retranslateUi(QDialog *CustomerLogin)
    {
        CustomerLogin->setWindowTitle(QCoreApplication::translate("CustomerLogin", "Dialog", nullptr));
        IdLabel->setText(QCoreApplication::translate("CustomerLogin", "ID", nullptr));
        PasswordLabel->setText(QCoreApplication::translate("CustomerLogin", "Password", nullptr));
        CustomerIDSignIn->setText(QString());
        LoginButton->setText(QCoreApplication::translate("CustomerLogin", "Login", nullptr));
        RegisterButton->setText(QCoreApplication::translate("CustomerLogin", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerLogin: public Ui_CustomerLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERLOGIN_H
