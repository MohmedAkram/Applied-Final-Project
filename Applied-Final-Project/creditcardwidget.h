#ifndef CREDITCARDWIDGET_H
#define CREDITCARDWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include "customer.h"
#include "accountpage.h"

class CreditCardWidget : public QWidget {
    Q_OBJECT

public:
    explicit CreditCardWidget(Customer * c, QWidget *parent = nullptr);

private slots:
    void onCheckoutClicked();

private:
    Customer * cust;
    QLineEdit *cardNumberLineEdit;
    QLineEdit *cvcLineEdit;
    QPushButton *checkoutButton;

    void setupUI();
};

#endif // CREDITCARDWIDGET_H
