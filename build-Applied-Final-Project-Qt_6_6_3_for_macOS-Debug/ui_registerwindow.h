/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *IDinput;
    QLineEdit *NameInput;
    QLineEdit *EmailInput;
    QLineEdit *PassInput;
    QPushButton *pushButton;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(675, 484);
        label = new QLabel(RegisterWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 160, 71, 31));
        label_2 = new QLabel(RegisterWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 200, 63, 20));
        label_3 = new QLabel(RegisterWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 240, 71, 20));
        label_4 = new QLabel(RegisterWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(150, 280, 71, 20));
        IDinput = new QLineEdit(RegisterWindow);
        IDinput->setObjectName("IDinput");
        IDinput->setGeometry(QRect(220, 160, 161, 28));
        NameInput = new QLineEdit(RegisterWindow);
        NameInput->setObjectName("NameInput");
        NameInput->setGeometry(QRect(220, 200, 161, 28));
        EmailInput = new QLineEdit(RegisterWindow);
        EmailInput->setObjectName("EmailInput");
        EmailInput->setGeometry(QRect(220, 240, 161, 28));
        PassInput = new QLineEdit(RegisterWindow);
        PassInput->setObjectName("PassInput");
        PassInput->setGeometry(QRect(220, 280, 161, 28));
        pushButton = new QPushButton(RegisterWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(260, 350, 83, 29));

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWindow", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWindow", "Email", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterWindow", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("RegisterWindow", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
