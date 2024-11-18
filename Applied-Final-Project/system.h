#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
using namespace std;

class System {
private:
    int systemID;
    string name;

public:
    System();
    System(int id, string name);

    void authenticateUser();
    void processPayment();
    void sendNotifications();
    void generateTicket();
};

#endif // SYSTEM_H
