#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
class Seat {
private:
    string row;
    string seat;
    string mark;

public:
    Seat();
    Seat(string seat);
    string get_seat();
    string get_row();
    string get_mark();
    void set(string s);
    void set_seat(string seat);
    void set_mark(string m);
    void set_row(string r);

};