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
    explicit AccountPage(QWidget *parent = nullptr);
    ~AccountPage();

private slots:
    void on_NameLine_cursorPositionChanged(int arg1, int arg2);

    void on_EmailLine_cursorPositionChanged(int arg1, int arg2);

    void on_IDLine_cursorPositionChanged(int arg1, int arg2);

    void on_MemStautsLine_cursorPositionChanged(int arg1, int arg2);

    void on_BalanceLine_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::AccountPage *ui;
};

#endif // ACCOUNTPAGE_H
