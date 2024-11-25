#ifndef ADMIN_H
#define ADMIN_H

#include "vectorC.h"
#include <string>

    using namespace std;

struct AdminCredential
{
    int username;
    string password;
};
class Admin
{
private:
    vectorC<AdminCredential> adminCredentials;

public:
    Admin();
    bool authenticate(int username, const string& password);
    bool isAdmin(int username);
    void addAdmin(int username, const string& password);
    void removeAdmin(int username);

};

#endif
