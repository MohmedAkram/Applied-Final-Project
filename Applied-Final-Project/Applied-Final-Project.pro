QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountpage.cpp \
    admin.cpp \
    confirmbook.cpp \
    creditcardwidget.cpp \
    customer.cpp \
    customerlogin.cpp \
    events.cpp \
    eventwindow1.cpp \
    eventwindow2.cpp \
    halls.cpp \
    loginadmin.cpp \
    main.cpp \
    mainwindow.cpp \
    registerwindow.cpp \
    reserved.cpp \
    seats.cpp \
    splaytree.cpp \
    system.cpp \
    tickets.cpp \
    vectorc.cpp

HEADERS += \
    accountpage.h \
    admin.h \
    confirmbook.h \
    creditcardwidget.h \
    customer.h \
    customerlogin.h \
    events.h \
    eventwindow1.h \
    eventwindow2.h \
    halls.h \
    loginadmin.h \
    mainwindow.h \
    registerwindow.h \
    reserved.h \
    seats.h \
    splaytree.h \
    system.h \
    tickets.h \
    vectorc.h

FORMS += \
    accountpage.ui \
    confirmbook.ui \
    creditcardwidget.ui \
    customerlogin.ui \
    eventwindow1.ui \
    eventwindow2.ui \
    loginadmin.ui \
    mainwindow.ui \
    registerwindow.ui \
    reserved.ui \
    seats.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recources.qrc
