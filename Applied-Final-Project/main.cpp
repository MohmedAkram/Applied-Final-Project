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
#include "halls.h"
#include  "admin.h"




#include <QApplication>
#include "eventwindow1.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    sys.ev = new EventsWindow1();
    sys.ev->showMaximized();
    // Halls h(1,"21:00");
    // h.show();
    // AdminWindow e;
    // e.show();

    return a.exec();
}

