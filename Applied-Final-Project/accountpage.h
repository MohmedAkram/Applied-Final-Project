#ifndef ACCOUNTPAGE_H
#define ACCOUNTPAGE_H

#include <QMainWindow>
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

private:
    Ui::AccountPage *ui;
};

#endif // ACCOUNTPAGE_H
