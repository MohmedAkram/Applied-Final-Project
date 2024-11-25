#include "system.h"


System::System() {

}
void System:: addCustomer(Customer customer) {
    CustomerTree.insert(customer);
}
