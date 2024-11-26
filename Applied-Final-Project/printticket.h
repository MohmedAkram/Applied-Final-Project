#ifndef PRINTTICKET_H
#define PRINTTICKET_H

#include <QDialog>

namespace Ui {
class PrintTicket;
}

class PrintTicket : public QDialog
{
    Q_OBJECT

public:
    explicit PrintTicket(QWidget *parent = nullptr);
    ~PrintTicket();

private:
    Ui::PrintTicket *ui;
};

#endif // PRINTTICKET_H
