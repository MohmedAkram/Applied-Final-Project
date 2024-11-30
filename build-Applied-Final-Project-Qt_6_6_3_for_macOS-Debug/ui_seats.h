/********************************************************************************
** Form generated from reading UI file 'seats.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEATS_H
#define UI_SEATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_seats
{
public:

    void setupUi(QDialog *seats)
    {
        if (seats->objectName().isEmpty())
            seats->setObjectName("seats");
        seats->resize(400, 300);

        retranslateUi(seats);

        QMetaObject::connectSlotsByName(seats);
    } // setupUi

    void retranslateUi(QDialog *seats)
    {
        seats->setWindowTitle(QCoreApplication::translate("seats", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class seats: public Ui_seats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEATS_H
