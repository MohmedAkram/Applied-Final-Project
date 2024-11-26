/********************************************************************************
** Form generated from reading UI file 'loginadmin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINADMIN_H
#define UI_LOGINADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Loginadmin
{
public:
    QLineEdit *adminId;
    QLineEdit *Pass;
    QLabel *AdminID;
    QLabel *password;
    QPushButton *Login;
    QPushButton *Signup;
    QLabel *Createaccount;
    QLineEdit *LoginPage;

    void setupUi(QDialog *Loginadmin)
    {
        if (Loginadmin->objectName().isEmpty())
            Loginadmin->setObjectName("Loginadmin");
        Loginadmin->resize(407, 328);
        adminId = new QLineEdit(Loginadmin);
        adminId->setObjectName("adminId");
        adminId->setGeometry(QRect(70, 100, 113, 21));
        Pass = new QLineEdit(Loginadmin);
        Pass->setObjectName("Pass");
        Pass->setGeometry(QRect(70, 160, 113, 21));
        AdminID = new QLabel(Loginadmin);
        AdminID->setObjectName("AdminID");
        AdminID->setGeometry(QRect(70, 70, 131, 21));
        password = new QLabel(Loginadmin);
        password->setObjectName("password");
        password->setGeometry(QRect(70, 130, 121, 20));
        Login = new QPushButton(Loginadmin);
        Login->setObjectName("Login");
        Login->setGeometry(QRect(70, 200, 100, 32));
        Signup = new QPushButton(Loginadmin);
        Signup->setObjectName("Signup");
        Signup->setGeometry(QRect(220, 240, 100, 32));
        Createaccount = new QLabel(Loginadmin);
        Createaccount->setObjectName("Createaccount");
        Createaccount->setGeometry(QRect(70, 250, 121, 20));
        LoginPage = new QLineEdit(Loginadmin);
        LoginPage->setObjectName("LoginPage");
        LoginPage->setGeometry(QRect(140, 30, 113, 21));

        retranslateUi(Loginadmin);

        QMetaObject::connectSlotsByName(Loginadmin);
    } // setupUi

    void retranslateUi(QDialog *Loginadmin)
    {
        Loginadmin->setWindowTitle(QCoreApplication::translate("Loginadmin", "Dialog", nullptr));
        adminId->setText(QString());
        AdminID->setText(QCoreApplication::translate("Loginadmin", "Admin Id", nullptr));
        password->setText(QCoreApplication::translate("Loginadmin", "Password", nullptr));
        Login->setText(QCoreApplication::translate("Loginadmin", "Login", nullptr));
        Signup->setText(QCoreApplication::translate("Loginadmin", "Signup", nullptr));
        Createaccount->setText(QCoreApplication::translate("Loginadmin", "Create an account", nullptr));
        LoginPage->setText(QCoreApplication::translate("Loginadmin", "Login Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Loginadmin: public Ui_Loginadmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINADMIN_H
