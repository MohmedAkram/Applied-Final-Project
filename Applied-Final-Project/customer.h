#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "vectorC.h"
#include"Events.h"
#include "tickets.h"

using namespace std;

class wallet {
public:
    wallet(int b){
        balance=b;
    };
    int balance=0;
    int getbalance(){return balance;};
    void editbalance(int value) {
        balance = balance+value;
    };
};
class Customer {
public:
    vectorC <Tickets> ReservedTickets;
    string email;
    bool IsVIP;
    int Ccredit;
    wallet *W;
    int customerID; ////////*****************************************
    string Password;
    string name; ////////***************************************** pushhh
    Customer(int id);
    Customer(int id, string Name, string Email,bool isvip,string password );
    int getbalance();
    void editbalance(int value);
    bool chechbalance(int value);
    void editname(string s);
    void editemail(string s);
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
