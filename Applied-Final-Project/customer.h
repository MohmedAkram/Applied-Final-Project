#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "vectorC.h"
#include"Events.h"

using namespace std;

class wallet {
public:
    wallet(int b){
        balance=b;
    };
    int balance=0;
    //vectorC<int> transactions;
    int getbalance(){return balance;};
    void editbalance(int value) {
        balance = balance+value;
        //transactions.push(value);
    };
};
class Customer {
private:


    string email;
    bool IsVIP;
    int Ccredit;
    wallet *W;
    //vectorC <Events> ReservedTickets;

public:
    int customerID; ////////*****************************************
    string Password;
    string name; ////////*****************************************
    Customer(int id);
    Customer(int id, string Name, string Email,bool isvip,string password );
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


    bool operator>(const Customer& other) const {
        return customerID > other.customerID;
    }
    bool operator!=(const Customer& other) const {
        return !(*this == other);  // return true if not equal (using ==)
    }
    friend ostream& operator<<(ostream& os, const Customer& customer);
};

#endif // CUSTOMER_H
