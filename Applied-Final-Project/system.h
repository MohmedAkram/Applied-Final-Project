#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include "splaytree.h"
#include "customer.h"
#include "eventwindow1.h"
#include "tickets.h"
#include "vectorc.h"
using namespace std;
class System {
private:
    int systemID;
    string name;

public:
    System();
    ~System();
    System(int id, string name);
    SplayTree CustomerTree; // tree
    EventsWindow1 *ev;
    void generateTicket();
    Tickets* TDB[5][3][40];
    void addEventTikets();

};
extern System sys;
#endif // SYSTEM_H
