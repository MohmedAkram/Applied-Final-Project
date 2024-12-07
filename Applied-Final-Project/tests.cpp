// #include <iostream>
// #include <sstream>
// #include "SplayTree.h"
// #include "vectorC.h"
// #include "customer.h"

// using namespace std;


// void testSplayTree() {
//     cout << "Testing SplayTree..." << endl;

//     SplayTree tree;

//     // Insert test
//     cout << "Test 1: Insert and printInOrder... ";
//     tree.insert(Customer(1, "Alice", "alice@example.com", false, "password1"));
//     tree.insert(Customer(2, "Bob", "bob@example.com", false, "password123"));
//     tree.insert(Customer(3, "Charlie", "charlie@example.com", true, "passwordXYZ"));
//     tree.insert(Customer(4, "Diana", "diana@example.com", true, "securepass"));
//     stringstream ss;
//     tree.printInOrder();  // This prints the inserted customers
//     cout << "PASSED" << endl;

//     // Find test
//     cout << "Test 2: Find existing element (Bob)... ";
//     bool foundBob = tree.find(Customer(2, "Bob", "bob@example.com", false, "password123"));
//     cout << (foundBob ? "PASSED" : "FAILED") << endl;

//     // Find non-existing test
//     cout << "Test 3: Find non-existing element (Eve)... ";
//     bool foundEve = tree.find(Customer(5, "Eve","bobb",false,"pass"));
//     cout << (!foundEve ? "PASSED" : "FAILED") << endl;

//     // Delete test
//     cout << "Test 4: Delete existing element (Charlie)... ";
//     tree.deleteKey(Customer(3, "Charlie", "charlie@example.com", true, "passwordXYZ"));
//     bool deletedCharlie = !tree.find(Customer(3, "Charlie", "charlie@example.com", true, "passwordXYZ"));
//     cout << (deletedCharlie ? "PASSED" : "FAILED") << endl;

//     // Edge case: Delete non-existing element
//     cout << "Test 5: Delete non-existing element (Eve)... ";
//     tree.deleteKey(Customer(5, "Eve","bobb",false,"pass"));
//     cout << "PASSED" << endl;

//     // FindNode test
//     cout << "Test 6: FindNode for Diana... ";
//     // SplayTree::Node* dianaNode = tree.findNode(Customer(4, "Diana", "diana@example.com", true, "securepass"));
//     // cout << (dianaNode != nullptr && dianaNode->customer == Customer(4, "Diana", "diana@example.com", true, "securepass") ? "PASSED" : "FAILED") << endl;

//     cout << "SplayTree tests completed." << endl << endl;
// }

// void testVectorC() {
//     cout << "Testing vectorC..." << endl;

//     vectorC<Customer> vec(5);  // Create a vector with capacity 5

//     // Add elements
//     cout << "Test 1: Push elements into vector... ";
//     Customer* c1 = new Customer(1, "Alice", "alice@example.com", false, "password1");
//     Customer* c2 = new Customer(2, "Bob", "bob@example.com", false, "password123");
//     Customer* c3 = new Customer(3, "Charlie", "charlie@example.com", true, "passwordXYZ");
//     vec.push(c1);
//     vec.push(c2);
//     vec.push(c3);
//     cout << (vec.getSize() == 3 ? "PASSED" : "FAILED") << endl;

//     // Peek test
//     cout << "Test 2: Peek last element... ";
//     Customer* peeked = vec.peek();
//     cout << (*peeked == *c3 ? "PASSED" : "FAILED") << endl;

//     // Pop test
//     cout << "Test 3: Pop element... ";
//     Customer* popped = vec.pop();
//     bool popResult = (*popped == *c3);
//     delete popped;  // Clean up memory
//     cout << (popResult && vec.getSize() == 2 ? "PASSED" : "FAILED") << endl;

//     // Get test
//     cout << "Test 4: Get element at index 0... ";
//     Customer* first = vec.get(0);
//     cout << (*first == *c1 ? "PASSED" : "FAILED") << endl;

//     // Overflow test
//     cout << "Test 5: Push beyond capacity (should fail)... ";
//     try {
//         for (int i = 0; i < 5; ++i) {
//             vec.push(new Customer(i + 4, "Test", "test@example.com", false, "password"));
//         }
//         cout << "FAILED" << endl;
//     } catch (const std::out_of_range& e) {
//         cout << "PASSED" << endl;
//     }

//     // Cleanup test
//     cout << "Test 6: Cleanup vector... ";
//     while (vec.getSize() > 0) {
//         delete vec.pop();
//     }
//     cout << (vec.getSize() == 0 ? "PASSED" : "FAILED") << endl;

//     cout << "VectorC tests completed." << endl;
// }

// int main() {
//     // Run the tests
//     testSplayTree();
//     testVectorC();

//     cout << "All tests completed." << endl;
//     return 0;
// }
