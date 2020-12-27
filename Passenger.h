#include "Seat.h"
using namespace std;
class Passenger {
private:
    string first_name;
    string last_name;
    string id;
    string phone;
    Seat  passenger_seat;

public:
    Passenger(string first_name, string last_name, string id, string phone, string seat);
    string get_first_name();
    string get_last_name();
    string get_id();
    string get_phone();
    Seat get_seat();

    void set_first_name(string name);
    void set_last_name(string name);
    void set_id(string id);
    void set_phone(string phone);
    void set_seat(Seat seat);
    string to_string();
    void display_passenger();
};