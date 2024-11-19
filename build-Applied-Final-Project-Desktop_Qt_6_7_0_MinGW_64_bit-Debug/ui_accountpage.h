/********************************************************************************
** Form generated from reading UI file 'accountpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTPAGE_H
#define UI_ACCOUNTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountPage
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AccountPage)
    {
        if (AccountPage->objectName().isEmpty())
            AccountPage->setObjectName("AccountPage");
        AccountPage->resize(800, 600);
        centralwidget = new QWidget(AccountPage);
        centralwidget->setObjectName("centralwidget");
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
    } // retranslateUi

};

namespace Ui {
    class AccountPage: public Ui_AccountPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTPAGE_H
