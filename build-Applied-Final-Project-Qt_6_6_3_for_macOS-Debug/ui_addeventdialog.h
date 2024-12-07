/********************************************************************************
** Form generated from reading UI file 'addeventdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEVENTDIALOG_H
#define UI_ADDEVENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_AddEventDialog
{
public:

    void setupUi(QDialog *AddEventDialog)
    {
        if (AddEventDialog->objectName().isEmpty())
            AddEventDialog->setObjectName("AddEventDialog");
        AddEventDialog->resize(400, 300);

        retranslateUi(AddEventDialog);

        QMetaObject::connectSlotsByName(AddEventDialog);
    } // setupUi

    void retranslateUi(QDialog *AddEventDialog)
    {
        AddEventDialog->setWindowTitle(QCoreApplication::translate("AddEventDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEventDialog: public Ui_AddEventDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEVENTDIALOG_H
