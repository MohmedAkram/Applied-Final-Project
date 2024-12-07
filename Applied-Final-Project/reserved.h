#ifndef RESERVED_H
#define RESERVED_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>
#include "customer.h"

namespace Ui {
class Reserved;
}

class Reserved : public QDialog
{
    Q_OBJECT

public:
    explicit Reserved(Customer* customer, QWidget *parent = nullptr);
    ~Reserved();

private:
    Ui::Reserved *ui;
    Customer* currentCustomer;
    QVBoxLayout* mainLayout;
    QHBoxLayout* topBarLayout;
    QScrollArea* scrollArea;
    QWidget* scrollWidget;
    QGridLayout* gridLayout;

    void setupUI();
    void loadTickets();
    void addTicketToLayout(Tickets* ticket, int row, int col);
};

#endif // RESERVED_H
