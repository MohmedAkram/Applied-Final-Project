/********************************************************************************
** Form generated from reading UI file 'creditcardwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITCARDWIDGET_H
#define UI_CREDITCARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_CreditCardWidget
{
public:

    void setupUi(QDialog *CreditCardWidget)
    {
        if (CreditCardWidget->objectName().isEmpty())
            CreditCardWidget->setObjectName("CreditCardWidget");
        CreditCardWidget->resize(400, 300);

        retranslateUi(CreditCardWidget);

        QMetaObject::connectSlotsByName(CreditCardWidget);
    } // setupUi

    void retranslateUi(QDialog *CreditCardWidget)
    {
        CreditCardWidget->setWindowTitle(QCoreApplication::translate("CreditCardWidget", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreditCardWidget: public Ui_CreditCardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITCARDWIDGET_H
