#include "mainwindow.h"
#include "system.h"
#include "customer.h"
#include "customerlogin.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    Customer customer(1234,"wwwerffrf","rfefr",true,"lol");
    sys.CustomerTree.insert(customer);
    //sys.CustomerTree.printInOrder();
    QApplication a(argc, argv);
    CustomerLogin w;
    w.show();
    return a.exec();







}
