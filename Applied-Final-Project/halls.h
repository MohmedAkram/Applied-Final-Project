#ifndef HALLS_H
#define HALLS_H

#include <string>
using namespace std;

class Halls {
private:
    int hallID;
    string name;
    int capacity;
    string location;

public:
    Halls();
    Halls(int id, string name, int capacity, string location);

    void checkHallAvailability();
    void getSeatingPlan();
    void assignToEvent();
};

#endif // HALLS_H
