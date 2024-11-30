/********************************************************************************
** Form generated from reading UI file 'eventwindow2.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTWINDOW2_H
#define UI_EVENTWINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_EventWindow2
{
public:

    void setupUi(QDialog *EventWindow2)
    {
        if (EventWindow2->objectName().isEmpty())
            EventWindow2->setObjectName("EventWindow2");
        EventWindow2->resize(400, 300);

        retranslateUi(EventWindow2);

        QMetaObject::connectSlotsByName(EventWindow2);
    } // setupUi

    void retranslateUi(QDialog *EventWindow2)
    {
        EventWindow2->setWindowTitle(QCoreApplication::translate("EventWindow2", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventWindow2: public Ui_EventWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTWINDOW2_H
