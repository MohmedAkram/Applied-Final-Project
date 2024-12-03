#ifndef ACCOUNTPAGE_H
#define ACCOUNTPAGE_H

#include <QMainWindow>
#include "creditcardwidget.h"
#include "customer.h"

namespace Ui {
class AccountPage;
}

class AccountPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccountPage(Customer *customer,QWidget *parent = nullptr);
    ~AccountPage();
    Customer *C;

private slots:
    void on_add_balance_clicked();

    void on_EditName_clicked();

    void on_EditEmail_clicked();

private:
    Ui::AccountPage *ui;
};

#endif // ACCOUNTPAGE_H
