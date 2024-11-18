#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
private:
    int customerID;
    string name;
    string email;
    string phone;
    string membershipStatus;

public:
    Customer();
    Customer(int id, string name, string email, string phone, string membershipStatus);

    void viewEvents();
    void bookTicket();
    void cancelBooking();
    void viewBookingHistory();
};

#endif // CUSTOMER_H
