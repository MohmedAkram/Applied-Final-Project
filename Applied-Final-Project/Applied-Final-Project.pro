QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountpage.cpp \
    admin.cpp \
    customer.cpp \
    customerlogin.cpp \
    events.cpp \
    halls.cpp \
    loginadmin.cpp \
    main.cpp \
    mainwindow.cpp \
    printticket.cpp \
    registerwindow.cpp \
    splaytree.cpp \
    system.cpp \
    tickets.cpp \
    tickets2.cpp \
    vectorc.cpp \

HEADERS += \
    accountpage.h \
    admin.h \
    customer.h \
    customerlogin.h \
    events.h \
    halls.h \
    loginadmin.h \
    mainwindow.h \
    printticket.h \
    registerwindow.h \
    splaytree.h \
    system.h \
    tickets.h \
    tickets2.h \
    vectorc.h \
FORMS += \
    accountpage.ui \
    customerlogin.ui \
    loginadmin.ui \
    mainwindow.ui \
    printticket.ui \
    tickets2.ui \
    registerwindow.ui
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recources.qrc
