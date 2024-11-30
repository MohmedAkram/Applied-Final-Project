#ifndef EVENTWINDOW2_H
#define EVENTWINDOW2_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QMessageBox>
#include "vectorC.h" // Custom vector class
#include "Events.h"  // Events class
#include "customer.h"
#include "seats.h"
#include "accountpage.h"

class EventWindow2 : public QDialog {
    Q_OBJECT

private:
    QVBoxLayout *mainLayout;         // Main layout of the window
    QHBoxLayout *topBarLayout;       // Layout for the top bar ("My Account" button)
    QScrollArea *scrollArea;         // Scroll area to hold events
    QWidget *scrollWidget;           // Widget inside the scroll area
    QGridLayout *gridLayout;         // Grid layout for arranging event cards
    QPushButton *accountButton;      // Button for "My Account"

    vectorC<Events> movies;          // Custom vector to hold event objects

public:
    explicit EventWindow2(Customer* customer,QWidget* parent = nullptr);
    ~EventWindow2();
    Customer* C;
    void setupUI();                  // Function to set up the UI
    void loadEvents(Customer* customer);               // Function to load event data
    void addEventToLayout(Events *event,Customer* C, int row, int col); // Add an event to the grid layout
};

#endif // EVENTWINDOW2_H
