#ifndef CUSTOMERLOGIN_H
#define CUSTOMERLOGIN_H

#include <QDialog>
#include<QMessageBox>

namespace Ui {
class CustomerLogin;
}

class CustomerLogin : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerLogin(QWidget *parent = nullptr);
    ~CustomerLogin();

private slots:
    void on_LoginButton_clicked();

    void on_RegisterButton_clicked();

private:
    Ui::CustomerLogin *ui;
};

#endif // CUSTOMERLOGIN_H
