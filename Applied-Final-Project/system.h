#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include "splaytree.h"
#include "customer.h"
#include "eventwindow1.h"
using namespace std;
class System {
private:
    int systemID;
    string name;

public:
    System();
    System(int id, string name);
    SplayTree CustomerTree; // tree
    EventsWindow1 *ev;
    void authenticateUser();
    void processPayment();
    void sendNotifications();
    void generateTicket();

};
extern System sys;
#endif // SYSTEM_H
