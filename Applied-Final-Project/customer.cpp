#include "customer.h"
using namespace std;

Customer::Customer(int id, string Name, string Email,bool isvip,string password ) {
    customerID = id;
    name = std::move(Name);
    email = std::move(Email);
    IsVIP = isvip;
    Password = password;
}
/*int Customer::getbalance() {
    return W->getbalance();
}*/
/*void Customer::editbalance(int value) {
    W->editbalance(value);
}*/

/*bool Customer::chechbalance(int value) {
    if(getbalance()>=value) {
        return true;
    }
    return false;
}*/

void Customer::viewEvents() {

}
void Customer::bookTicket() {

}
void Customer::cancelBooking() {

}
void Customer::viewBookingHistory() {

}


