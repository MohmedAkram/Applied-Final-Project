/********************************************************************************
** Form generated from reading UI file 'reserved.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVED_H
#define UI_RESERVED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Reserved
{
public:
    QTextEdit *textEdit;

    void setupUi(QDialog *Reserved)
    {
        if (Reserved->objectName().isEmpty())
            Reserved->setObjectName("Reserved");
        Reserved->resize(430, 328);
        textEdit = new QTextEdit(Reserved);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(70, 40, 121, 41));
        textEdit->setReadOnly(true);

        retranslateUi(Reserved);

        QMetaObject::connectSlotsByName(Reserved);
    } // setupUi

    void retranslateUi(QDialog *Reserved)
    {
        Reserved->setWindowTitle(QCoreApplication::translate("Reserved", "Dialog", nullptr));
        textEdit->setHtml(QCoreApplication::translate("Reserved", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:700;\">My Tickets</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reserved: public Ui_Reserved {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVED_H
