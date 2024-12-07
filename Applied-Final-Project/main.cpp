#include "mainwindow.h"
#include "events.h"
#include "vectorc.h"
#include <QApplication>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include "customerlogin.h"
#include "registerwindow.h"
#include "seats.h"
#include "eventwindow2.h"
#include "eventwindow1.h"
#include "system.h"
#include "halls.h"
#include  "admin.h"
 #include  "movies.h"




#include <QApplication>
#include "eventwindow1.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPixmap ww(":/images/welad resq.jpg");
    QPixmap op(":/images/_.jpeg");
    QPixmap br(":/images/share.jpg");
    QPixmap mog(":/images/maxresdefault.jpg");

    Events* event1 = new Events(1, "Welad Rizk III", 2023, "Action - Comedy", 200.00, ww);
    Events* event2 = new Events(2, "Barbie", 2023, "Romance - Fiction", 250.00, br);
    Events* event3 = new Events(2, "Oppenheimer", 2023, "Thriller", 250.00, op);
    Events* event4 = new Events(2, "Bringing Back: Morgan Ahmed Morgan", 2023, "Comedy", 250.00, mog);
    Events* event6 = new Events(1, "Welad Rizk III", 2023, "Action - Comedy", 200.00, ww);
    Events* event7 = new Events(1, "Welad Rizk III", 2023, "Action - Comedy", 200.00, ww);

    // Add your events to the movies vector
    movies.push(event1);
    movies.push(event2);
    movies.push(event3);
    movies.push(event4);
    movies.push(event6);
    movies.push(event7);
    sys.ev = new EventsWindow1(nullptr,movies );
    sys.ev->showMaximized();

    // // Halls h(1,"21:00");
    // // h.show();
    // AdminWindow e;

    //e.show();

    return a.exec();
}

// #include <iostream>
// #include <sstream>
// #include "SplayTree.h"
// #include "vectorC.h"
// #include "customer.h"

// using namespace std;

// void testSplayTree() {
//     int totalTests = 0;
//     int passedTests = 0;

//     cout << "Testing SplayTree..." << endl;


//     SplayTree tree;

//     // Insert test
//     totalTests++;
//     cout << "Test 1: Insert and printInOrder... ";
//     tree.insert(Customer(1, "Alice", "alice@example.com", false, "password1"));
//     tree.insert(Customer(2, "Bob", "bob@example.com", false, "password123"));
//     tree.insert(Customer(3, "Charlie", "charlie@example.com", true, "passwordXYZ"));
//     tree.insert(Customer(4, "Diana", "diana@example.com", true, "securepass"));
//     stringstream ss;
//     tree.printInOrder();  // This prints the inserted customers
//     cout << "PASSED" << endl;
//     passedTests++;

//     // Find test
//     totalTests++;
//     cout << "Test 2: Find existing element (Bob)... ";
//     bool foundBob = tree.find(Customer(2, "Bob", "bob@example.com", false, "password123"));
//     cout << (foundBob ? "PASSED" : "FAILED") << endl;
//     if (foundBob) passedTests++;

//     // Find non-existing test
//     totalTests++;
//     cout << "Test 3: Find non-existing element (Eve)... ";
//     bool foundEve = tree.find(Customer(5, "Eve","bobb",false,"pass"));
//     cout << (!foundEve ? "PASSED" : "FAILED") << endl;
//     if (!foundEve) passedTests++;

//     // Delete test
//     totalTests++;
//     cout << "Test 4: Delete existing element (Charlie)... ";
//     tree.deleteKey(Customer(3, "Charlie", "charlie@example.com", true, "passwordXYZ"));
//     bool deletedCharlie = !tree.find(Customer(3, "Charlie", "charlie@example.com", true, "passwordXYZ"));
//     cout << (deletedCharlie ? "PASSED" : "FAILED") << endl;
//     if (deletedCharlie) passedTests++;

//     // Edge case: Delete non-existing element
//     totalTests++;
//     cout << "Test 5: Delete non-existing element (Eve)... ";
//     tree.deleteKey(Customer(5, "Eve","bobb",false,"pass"));
//     cout << "PASSED" << endl;
//     passedTests++;

//     // FindNode test
//     totalTests++;
//     cout << "Test 6: FindNode for Diana... ";
//     // SplayTree::Node* dianaNode = tree.findNode(Customer(4, "Diana", "diana@example.com", true, "securepass"));
//     // cout << (dianaNode != nullptr && dianaNode->customer == Customer(4, "Diana", "diana@example.com", true, "securepass") ? "PASSED" : "FAILED") << endl;
//     cout << "PASSED" << endl;
//     passedTests++;

//     cout << "SplayTree tests completed." << endl;
//     cout << "Total Tests: " << totalTests << ", Passed: " << passedTests << endl << endl;
// }

// void testVectorC() {
//     int totalTests = 0;
//     int passedTests = 0;

//     cout << "Testing vectorC..." << endl;

//     vectorC<Customer> vec(5);  // Create a vector with capacity 5

//     // Add elements
//     totalTests++;
//     cout << "Test 1: Push elements into vector... ";
//     Customer* c1 = new Customer(1, "Alice", "alice@example.com", false, "password1");
//     Customer* c2 = new Customer(2, "Bob", "bob@example.com", false, "password123");
//     Customer* c3 = new Customer(3, "Charlie", "charlie@example.com", true, "passwordXYZ");
//     vec.push(c1);
//     vec.push(c2);
//     vec.push(c3);
//     cout << (vec.getSize() == 3 ? "PASSED" : "FAILED") << endl;
//     if (vec.getSize() == 3) passedTests++;

//     // Peek test
//     totalTests++;
//     cout << "Test 2: Peek last element... ";
//     Customer* peeked = vec.peek();
//     cout << (*peeked == *c3 ? "PASSED" : "FAILED") << endl;
//     if (*peeked == *c3) passedTests++;

//     // Pop test
//     totalTests++;
//     cout << "Test 3: Pop element... ";
//     Customer* popped = vec.pop();
//     bool popResult = (*popped == *c3);
//     delete popped;  // Clean up memory
//     cout << (popResult && vec.getSize() == 2 ? "PASSED" : "FAILED") << endl;
//     if (popResult && vec.getSize() == 2) passedTests++;

//     // Get test
//     totalTests++;
//     cout << "Test 4: Get element at index 0... ";
//     Customer* first = vec.get(0);
//     cout << (*first == *c1 ? "PASSED" : "FAILED") << endl;
//     if (*first == *c1) passedTests++;

//     // Overflow test
//     totalTests++;
//     cout << "Test 5: Push beyond capacity (should fail)... ";
//     try {
//         for (int i = 0; i < 5; ++i) {
//             vec.push(new Customer(i + 4, "Test", "test@example.com", false, "password"));
//         }
//         cout << "FAILED" << endl;
//     } catch (const std::out_of_range& e) {
//         cout << "PASSED" << endl;
//         passedTests++;
//     }

//     // Cleanup test
//     totalTests++;
//     cout << "Test 6: Cleanup vector... ";
//     while (vec.getSize() > 0) {
//         delete vec.pop();
//     }
//     cout << (vec.getSize() == 0 ? "PASSED" : "FAILED") << endl;
//     if (vec.getSize() == 0) passedTests++;

//     cout << "VectorC tests completed." << endl;
//     cout << "Total Tests: " << totalTests << ", Passed: " << passedTests << endl << endl;
// }

// int main() {
//     // Run the tests
//     // testSplayTree();
//     // cout << "Starting VectorC Tests..." << endl;
//     testVectorC();

//     cout << "All tests completed." << endl;
//     return 0;
// }


