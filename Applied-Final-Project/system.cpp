#include "system.h"


System::System() {

}
void addCustomer(int id, const std::string& name, const std::string& email, bool isvip) {
    Customer newCustomer(id, name, email, isvip);
    CustomerTree.insert(newCustomer);
}
