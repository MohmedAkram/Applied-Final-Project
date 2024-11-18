#ifndef EVENTS_H
#define EVENTS_H

#include <string>
using namespace std;

class Events {
private:
    int eventID;
    string title;
    int duration;
    string date;
    double price;

public:
    Events();
    Events(int id, string title, int duration, string date, double price);

    void getEventDetails();
    void updateEventDetails();
    void checkAvailability();
};

#endif // EVENTS_H
