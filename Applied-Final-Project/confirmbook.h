#ifndef CONFIRMBOOK_H
#define CONFIRMBOOK_H
#include "customer.h"
#include "events.h"

#include <QDialog>

namespace Ui {
class ConfirmBook;
}

class ConfirmBook : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmBook(Events* e,Customer*c,QWidget *parent = nullptr);
    ~ConfirmBook();


private:
    Ui::ConfirmBook *ui;
};

#endif // CONFIRMBOOK_H
