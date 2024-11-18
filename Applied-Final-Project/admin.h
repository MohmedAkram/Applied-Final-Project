#ifndef ADMIN_H
#define ADMIN_H

#include <string>
using namespace std;

class Admin {
private:
    int adminID;
    string name;
    string email;
    string phone;

public:
    Admin();
    Admin(int id, string name, string email, string phone);

    void addEvent();
    void removeEvent();
    void assignHall();
    void generateReport();
    void manageUsers();
};

#endif // ADMIN_H
