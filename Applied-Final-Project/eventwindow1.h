#ifndef EVENTSWINDOW1_H
#define EVENTSWINDOW1_H

#include <QDialog>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QPixmap>
#include "events.h"
#include "vectorc.h"
#include "customerlogin.h"
#include "registerwindow.h"
#include "seats.h"
#include "eventwindow2.h"

class EventsWindow1 : public QDialog {
    Q_OBJECT

public:
    explicit EventsWindow1(QWidget *parent = nullptr);

private:
    void setupUI();
    void loadEvents();
    void addEventToLayout(Events *event, int row, int col);

    vectorC<Events> movies;

    QVBoxLayout *mainLayout;
    QHBoxLayout *topBarLayout;
    QScrollArea *scrollArea;
    QWidget *scrollWidget;
    QGridLayout *gridLayout;
};

#endif // EVENTSWINDOW1_H
