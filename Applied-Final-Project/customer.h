#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "vectorC.h"
#include"Events.h"

using namespace std;

class wallet {
public:
    int balance=0;
    vectorC<int> transactions;
    int getbalance(){return balance;};
    void editbalance(int value) {
        balance = balance+value;
        transactions.push(value);
    };
};
class Customer {
private:
    int customerID;
    string name;
    string email;
    string membershipStatus;
    int Ccredit;
    wallet *W;
    //vectorC <Events> ReservedTickets;

public:
    Customer(int id);
    Customer(int id, string Name, string Email, string MembershipStatus);
    int getbalance();
    void editbalance(int value);
    bool chechbalance(int value);
    void viewEvents();
    void bookTicket();
    void cancelBooking();
    void viewBookingHistory();
};

#endif // CUSTOMER_H
