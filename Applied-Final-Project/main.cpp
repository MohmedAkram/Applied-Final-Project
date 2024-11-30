#include "mainwindow.h"
#include "events.h"
#include "vectorc.h"
#include <QApplication>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include "customerlogin.h"
#include "registerwindow.h"
#include "seats.h"
#include "eventwindow2.h"
#include "eventwindow1.h"
#include "system.h"




#include <QApplication>
#include "eventwindow1.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    EventsWindow1 eventWindow;
    // Create and show the EventWindow
    //EventWindow2 E2;
    eventWindow.show();
    //E2.show();

    return a.exec();
}

