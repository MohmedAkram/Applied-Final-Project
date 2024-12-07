#ifndef EVENTSWINDOW1_H
#define EVENTSWINDOW1_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "vectorc.h"  // Include vectorC definition
#include "events.h"   // Include Events class definition

class EventsWindow1 : public QDialog {
    Q_OBJECT

public:
    explicit EventsWindow1(QWidget *parent, vectorC<Events>& eventsList); // Constructor accepting vectorC reference
    ~EventsWindow1() = default;

private:
    vectorC<Events>& movies;  // Reference to the passed vectorC
    QVBoxLayout *mainLayout;
    QHBoxLayout *topBarLayout;
    QScrollArea *scrollArea;
    QWidget *scrollWidget;
    QGridLayout *gridLayout;

    void setupUI();
    void loadEvents();
    void addEventToLayout(Events *event, int row, int col);
};

#endif // EVENTSWINDOW1_H
