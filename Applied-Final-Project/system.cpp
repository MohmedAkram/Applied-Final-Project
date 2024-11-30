#include "system.h"

System sys;
System::System() {
    Customer c1(111,"Karim","karimelhenawy@aucegypt.edu",true,"111");
    Customer c2(222,"Karim","karimelnazir@aucegypt.edu",true,"1");
    Customer c3(333,"Zeyad","zeyadmaher@aucegypt.edu",true,"zzzz");
    Customer c4(444,"Akram","mo.elsayed@aucegypt.edu",true,"22");
    Customer c5(555,"Ali","ali.ehab@aucegypt.edu",true,"77");
    CustomerTree.insert(c1);
    CustomerTree.insert(c2);
    CustomerTree.insert(c3);
    CustomerTree.insert(c4);
    CustomerTree.insert(c5);
}
