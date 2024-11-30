/********************************************************************************
** Form generated from reading UI file 'eventwindow1.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTWINDOW1_H
#define UI_EVENTWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_EventWindow1
{
public:

    void setupUi(QDialog *EventWindow1)
    {
        if (EventWindow1->objectName().isEmpty())
            EventWindow1->setObjectName("EventWindow1");
        EventWindow1->resize(400, 300);

        retranslateUi(EventWindow1);

        QMetaObject::connectSlotsByName(EventWindow1);
    } // setupUi

    void retranslateUi(QDialog *EventWindow1)
    {
        EventWindow1->setWindowTitle(QCoreApplication::translate("EventWindow1", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventWindow1: public Ui_EventWindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTWINDOW1_H
