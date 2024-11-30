/********************************************************************************
** Form generated from reading UI file 'accountpage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTPAGE_H
#define UI_ACCOUNTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountPage
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *NameLine;
    QLabel *label_5;
    QLineEdit *IDLine;
    QLineEdit *EmailLine;
    QLineEdit *MemStautsLine;
    QPushButton *EditName;
    QPushButton *EditEmail;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *BalanceLine;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AccountPage)
    {
        if (AccountPage->objectName().isEmpty())
            AccountPage->setObjectName("AccountPage");
        AccountPage->resize(800, 600);
        centralwidget = new QWidget(AccountPage);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 81, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(450, 80, 58, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(240, 80, 58, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(590, 80, 131, 16));
        NameLine = new QLineEdit(centralwidget);
        NameLine->setObjectName("NameLine");
        NameLine->setGeometry(QRect(10, 110, 113, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 80, 58, 16));
        IDLine = new QLineEdit(centralwidget);
        IDLine->setObjectName("IDLine");
        IDLine->setGeometry(QRect(410, 110, 113, 21));
        IDLine->setFrame(true);
        IDLine->setReadOnly(true);
        EmailLine = new QLineEdit(centralwidget);
        EmailLine->setObjectName("EmailLine");
        EmailLine->setGeometry(QRect(190, 110, 141, 21));
        EmailLine->setFrame(true);
        MemStautsLine = new QLineEdit(centralwidget);
        MemStautsLine->setObjectName("MemStautsLine");
        MemStautsLine->setGeometry(QRect(590, 110, 113, 21));
        MemStautsLine->setReadOnly(true);
        EditName = new QPushButton(centralwidget);
        EditName->setObjectName("EditName");
        EditName->setGeometry(QRect(10, 150, 100, 32));
        EditEmail = new QPushButton(centralwidget);
        EditEmail->setObjectName("EditEmail");
        EditEmail->setGeometry(QRect(220, 150, 100, 32));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 280, 111, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 330, 81, 16));
        BalanceLine = new QLineEdit(centralwidget);
        BalanceLine->setObjectName("BalanceLine");
        BalanceLine->setGeometry(QRect(20, 370, 113, 21));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(250, 330, 81, 16));
        AccountPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AccountPage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 37));
        AccountPage->setMenuBar(menubar);
        statusbar = new QStatusBar(AccountPage);
        statusbar->setObjectName("statusbar");
        AccountPage->setStatusBar(statusbar);

        retranslateUi(AccountPage);

        QMetaObject::connectSlotsByName(AccountPage);
    } // setupUi

    void retranslateUi(QMainWindow *AccountPage)
    {
        AccountPage->setWindowTitle(QCoreApplication::translate("AccountPage", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("AccountPage", "My Account", nullptr));
        label_2->setText(QCoreApplication::translate("AccountPage", "ID", nullptr));
        label_3->setText(QCoreApplication::translate("AccountPage", "Email", nullptr));
        label_4->setText(QCoreApplication::translate("AccountPage", "Membership Status", nullptr));
        label_5->setText(QCoreApplication::translate("AccountPage", "Name", nullptr));
        EditName->setText(QCoreApplication::translate("AccountPage", "Edit", nullptr));
        EditEmail->setText(QCoreApplication::translate("AccountPage", "Edit", nullptr));
        label_6->setText(QCoreApplication::translate("AccountPage", "Wallet", nullptr));
        label_7->setText(QCoreApplication::translate("AccountPage", "Balance ", nullptr));
        label_8->setText(QCoreApplication::translate("AccountPage", "Add Balance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountPage: public Ui_AccountPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTPAGE_H
