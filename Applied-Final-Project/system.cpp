#include "system.h"

System sys;
Tickets* TDB;

System::System() {
    // Add customers to CustomerTree
    Customer c1(111, "Karim", "karimelhenawy@aucegypt.edu", true, "111");
    Customer c2(222, "Karim", "karimelnazir@aucegypt.edu", true, "1");
    Customer c3(333, "Zeyad", "zeyadmaher@aucegypt.edu", true, "zzzz");
    Customer c4(444, "Akram", "mo.elsayed@aucegypt.edu", true, "22");
    Customer c5(555, "Ali", "ali.ehab@aucegypt.edu", true, "77");
    CustomerTree.insert(c1);
    CustomerTree.insert(c2);
    CustomerTree.insert(c3);
    CustomerTree.insert(c4);
    CustomerTree.insert(c5);

    // Initialize the static 3D array
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 41; ++k) {
                if (k < 20) {
                    TDB[i][j][k] = new Tickets(k, i, false, false); // Dynamically allocate
                } else {
                    TDB[i][j][k] = new Tickets(k, i, false, true);  // Dynamically allocate
                }
            }
        }
    }
}

// Destructor to clean up the dynamically allocated memory
System::~System() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 41; ++k) {
                delete TDB[i][j][k]; // Free memory for each dynamically allocated Tickets object
            }
        }
    }
}
