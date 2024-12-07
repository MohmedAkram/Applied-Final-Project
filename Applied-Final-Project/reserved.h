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
#include "tickets.h" // Ensure Tickets is included if it's used as a parameter

namespace Ui {
class Reserved;
}

class Reserved : public QDialog
{
    Q_OBJECT

public:
    explicit Reserved(Customer* customer, QWidget *parent = nullptr);
    ~Reserved();

private slots:
    void onCancelTicketClicked(QWidget *ticketWidget, Tickets* ticket); // **Declaration for the cancel button slot**

private:
    Ui::Reserved *ui;
    Customer* currentCustomer;
    QVBoxLayout* mainLayout;
    QHBoxLayout* topBarLayout;
    QScrollArea* scrollArea;
    QWidget* scrollWidget;
    QString getTimeFromIndex(int timeIndex);
    QGridLayout* gridLayout;

    void setupUI();
    void loadTickets();
    void addTicketToLayout(Tickets* ticket, int row, int col);
};

#endif // RESERVED_H
