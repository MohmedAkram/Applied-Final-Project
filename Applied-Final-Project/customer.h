#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "vectorC.h"
#include"Events.h"

using namespace std;

/*class wallet {
public:
    int balance=0;
    vectorC<int> transactions;
    int getbalance(){return balance;};
    void editbalance(int value) {
        balance = balance+value;
        transactions.push(value);
    };
};*/
class Customer {
private:
    int customerID;
    string name;
    string email;
<<<<<<< HEAD
    string membershipStatus;
    wallet *W;
=======
    bool IsVIP;
    int Ccredit;
    //wallet *W;
>>>>>>> 7f8122dd3d9bd4adbff4aff806b07763879a4783
    //vectorC <Events> ReservedTickets;

public:
    Customer(int id);
    Customer(int id, string Name, string Email,bool isvip);
    int getbalance();
    void editbalance(int value);
    bool chechbalance(int value);
    void viewEvents();
    void bookTicket();
    void cancelBooking();
    void viewBookingHistory();
    bool operator<(const Customer& other) const {
        return customerID < other.customerID;
    }

    bool operator==(const Customer& other) const {
        return customerID == other.customerID;
    }
};

#endif // CUSTOMER_H
