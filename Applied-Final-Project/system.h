#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include "splaytree.h"
#include "customer.h"
using namespace std;

class System {
private:
    int systemID;
    string name;

public:
    System();
    System(int id, string name);
    void addCustomer(int id, const std::string& name, const std::string& email, bool isvip);
    SplayTree<Customer> CustomerTree;
    void authenticateUser();
    void processPayment();
    void sendNotifications();
    void generateTicket();
};

#endif // SYSTEM_H
