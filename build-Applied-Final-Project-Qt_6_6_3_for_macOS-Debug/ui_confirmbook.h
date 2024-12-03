/********************************************************************************
** Form generated from reading UI file 'confirmbook.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMBOOK_H
#define UI_CONFIRMBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ConfirmBook
{
public:
    QLabel *Seatnumber;
    QLabel *Movie;
    QLabel *Hallnumber;
    QLabel *Time;
    QLabel *Price;
    QLabel *Remaining;
    QLabel *Wallet;
    QLineEdit *SeatEdit;
    QLineEdit *Moviename;
    QLineEdit *HallEdit;
    QLineEdit *TimeEdit;
    QLineEdit *PriceEdit;
    QLineEdit *RemainingEdit;
    QLineEdit *WalletEdit;
    QTextEdit *TicketDetails;
    QPushButton *Confirm;

    void setupUi(QDialog *ConfirmBook)
    {
        if (ConfirmBook->objectName().isEmpty())
            ConfirmBook->setObjectName("ConfirmBook");
        ConfirmBook->resize(427, 310);
        Seatnumber = new QLabel(ConfirmBook);
        Seatnumber->setObjectName("Seatnumber");
        Seatnumber->setGeometry(QRect(40, 70, 91, 21));
        Movie = new QLabel(ConfirmBook);
        Movie->setObjectName("Movie");
        Movie->setGeometry(QRect(40, 100, 91, 21));
        Hallnumber = new QLabel(ConfirmBook);
        Hallnumber->setObjectName("Hallnumber");
        Hallnumber->setGeometry(QRect(40, 130, 91, 21));
        Time = new QLabel(ConfirmBook);
        Time->setObjectName("Time");
        Time->setGeometry(QRect(40, 160, 91, 21));
        Price = new QLabel(ConfirmBook);
        Price->setObjectName("Price");
        Price->setGeometry(QRect(40, 190, 91, 21));
        Remaining = new QLabel(ConfirmBook);
        Remaining->setObjectName("Remaining");
        Remaining->setGeometry(QRect(40, 220, 131, 21));
        Wallet = new QLabel(ConfirmBook);
        Wallet->setObjectName("Wallet");
        Wallet->setGeometry(QRect(200, 0, 91, 21));
        SeatEdit = new QLineEdit(ConfirmBook);
        SeatEdit->setObjectName("SeatEdit");
        SeatEdit->setGeometry(QRect(180, 70, 201, 21));
        SeatEdit->setReadOnly(true);
        Moviename = new QLineEdit(ConfirmBook);
        Moviename->setObjectName("Moviename");
        Moviename->setGeometry(QRect(180, 100, 201, 21));
        Moviename->setAutoFillBackground(false);
        Moviename->setReadOnly(true);
        HallEdit = new QLineEdit(ConfirmBook);
        HallEdit->setObjectName("HallEdit");
        HallEdit->setGeometry(QRect(180, 130, 201, 21));
        HallEdit->setReadOnly(true);
        TimeEdit = new QLineEdit(ConfirmBook);
        TimeEdit->setObjectName("TimeEdit");
        TimeEdit->setGeometry(QRect(180, 160, 201, 21));
        TimeEdit->setReadOnly(true);
        PriceEdit = new QLineEdit(ConfirmBook);
        PriceEdit->setObjectName("PriceEdit");
        PriceEdit->setGeometry(QRect(180, 190, 201, 21));
        PriceEdit->setReadOnly(true);
        RemainingEdit = new QLineEdit(ConfirmBook);
        RemainingEdit->setObjectName("RemainingEdit");
        RemainingEdit->setGeometry(QRect(180, 220, 201, 21));
        RemainingEdit->setReadOnly(true);
        WalletEdit = new QLineEdit(ConfirmBook);
        WalletEdit->setObjectName("WalletEdit");
        WalletEdit->setGeometry(QRect(310, 0, 81, 21));
        TicketDetails = new QTextEdit(ConfirmBook);
        TicketDetails->setObjectName("TicketDetails");
        TicketDetails->setGeometry(QRect(110, 30, 151, 31));
        Confirm = new QPushButton(ConfirmBook);
        Confirm->setObjectName("Confirm");
        Confirm->setGeometry(QRect(160, 260, 131, 32));

        retranslateUi(ConfirmBook);

        QMetaObject::connectSlotsByName(ConfirmBook);
    } // setupUi

    void retranslateUi(QDialog *ConfirmBook)
    {
        ConfirmBook->setWindowTitle(QCoreApplication::translate("ConfirmBook", "Dialog", nullptr));
        Seatnumber->setText(QCoreApplication::translate("ConfirmBook", "Seat Number", nullptr));
        Movie->setText(QCoreApplication::translate("ConfirmBook", "Movie", nullptr));
        Hallnumber->setText(QCoreApplication::translate("ConfirmBook", "Hall Number", nullptr));
        Time->setText(QCoreApplication::translate("ConfirmBook", "Time", nullptr));
        Price->setText(QCoreApplication::translate("ConfirmBook", "Price", nullptr));
        Remaining->setText(QCoreApplication::translate("ConfirmBook", "Remaining Balance", nullptr));
        Wallet->setText(QCoreApplication::translate("ConfirmBook", "Wallet Balance", nullptr));
        TicketDetails->setHtml(QCoreApplication::translate("ConfirmBook", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; color:#ff2600;\">Ticket Details</span></p></body></html>", nullptr));
        Confirm->setText(QCoreApplication::translate("ConfirmBook", "Confirm Booking", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfirmBook: public Ui_ConfirmBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMBOOK_H
