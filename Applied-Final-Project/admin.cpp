/*#include "Admin.h"
Admin::Admin()
{
    adminCredentials= vectorC<AdminCredentials>(5);
}
bool Admin::authenticate(int username, const int &password)
{
    for(int i=0;i<adminCredentials.getSize();i++)
    {
        if(adminCredentials.peek().username==username && adminCredentials.peek().password==password)
        {
            return true;
        }
    }
    return false;
}

bool Admin::isAdmin(int username)
{
    for(int i=0;i<adminCredentials.getSize();i++)
    {
        if(adminCredentials.peek().username==username)
        {
            return true;
        }
    }
    return false;
}

void Admin::addAdmin(int username, const int &password)
{
    if(adminCredentials.peek().username==username)
    {
        adminCredentials.peek().password=password;// If the AdminId already exists it will update the password
        return;
    }
    adminCredentials.push(AdminCredential(username,password));
}
void Admin::removeAdmin(int username)
{
    vectorC<adminCredentials> filtered;
    for (int i = 0; i < adminCredentials.getSize(); i++)
    {
        if (adminCredentials[i].username != username)// this is to accesses all elements by index and compares the AdminId
        {
            filtered.push(adminCredentials[i]);//push all other elements into the vectors except the element that will be removed
        }
    }
    adminCredentials = filtered; // this will replace the original vector with filtered vector
}
*/
