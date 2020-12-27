#include "Seat.h"
using namespace std;
Seat::Seat() : row(""), seat(""), mark(" ") {
}

Seat::Seat(string seat) {
    set_seat(seat);
}

string Seat::get_seat() {
    return seat;
}

string Seat::get_row() {
    return row;
}

string Seat::get_mark() {
    return mark;
}

void Seat::set_seat(string seat) {
    this->seat = seat;
}

void Seat::set_row(string r) {
    row = r;
}

void Seat::set_mark(string m) {
    mark = m;
}
/* Function set is responsible for setting up the
* row and seat chosen by the passenger.
*/
void Seat::set(string str) {
    for (int i = 0; i < (int)str.length(); i++) {
        if (isdigit(str.at(i)))
            row.push_back(str.at(i));
        else
            seat.push_back(str.at(i));
    }
}