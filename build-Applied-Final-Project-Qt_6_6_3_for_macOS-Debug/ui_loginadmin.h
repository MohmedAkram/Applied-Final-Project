/********************************************************************************
** Form generated from reading UI file 'loginadmin.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
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
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *Loginadmin)
    {
        if (Loginadmin->objectName().isEmpty())
            Loginadmin->setObjectName("Loginadmin");
        Loginadmin->resize(407, 328);
        lineEdit = new QLineEdit(Loginadmin);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(70, 100, 113, 21));
        lineEdit_2 = new QLineEdit(Loginadmin);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(70, 160, 113, 21));
        label = new QLabel(Loginadmin);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 70, 131, 21));
        label_2 = new QLabel(Loginadmin);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 130, 121, 20));
        pushButton = new QPushButton(Loginadmin);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 200, 100, 32));
        pushButton_2 = new QPushButton(Loginadmin);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 240, 100, 32));
        label_3 = new QLabel(Loginadmin);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 250, 121, 20));
        lineEdit_3 = new QLineEdit(Loginadmin);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(140, 30, 113, 21));

        retranslateUi(Loginadmin);

        QMetaObject::connectSlotsByName(Loginadmin);
    } // setupUi

    void retranslateUi(QDialog *Loginadmin)
    {
        Loginadmin->setWindowTitle(QCoreApplication::translate("Loginadmin", "Dialog", nullptr));
        lineEdit->setText(QString());
        label->setText(QCoreApplication::translate("Loginadmin", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("Loginadmin", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("Loginadmin", "Login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Loginadmin", "Signup", nullptr));
        label_3->setText(QCoreApplication::translate("Loginadmin", "Create an account", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("Loginadmin", "Login Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Loginadmin: public Ui_Loginadmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINADMIN_H
