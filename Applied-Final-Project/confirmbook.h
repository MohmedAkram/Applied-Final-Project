#ifndef CONFIRMBOOK_H
#define CONFIRMBOOK_H

#include <QDialog>

namespace Ui {
class ConfirmBook;
}

class ConfirmBook : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmBook(QWidget *parent = nullptr);
    ~ConfirmBook();

private:
    Ui::ConfirmBook *ui;
};

#endif // CONFIRMBOOK_H
