#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include "vectorc.h"
#include "events.h"
#include "AddEventDialog.h"  // Include the dialog header for adding events
#include "eventwindow1.h"  // Include the EventsWindow1 header

class AdminWindow : public QDialog {
    Q_OBJECT

public:
    explicit AdminWindow(QWidget* parent = nullptr);
    ~AdminWindow();

private slots:
    void onAddEventClicked();  // Slot for handling the add event action
    void onLogoutClicked();    // Slot for handling the logout action

private:
    void setupUI();  // Function to set up the UI layout
    void switchToEventsWindow();  // Function to switch to EventsWindow1

    QVBoxLayout* mainLayout;
    QHBoxLayout* topBarLayout;
    QPushButton* addAdminButton;
    QPushButton* removeAdminButton;
    QPushButton* logoutButton;

    //vectorC<Events> movies;  // The vector containing all the events
};

#endif // ADMINWINDOW_H
