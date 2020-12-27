#include "Passenger.h"
using namespace std;
Passenger::Passenger(string first_name, string last_name, string id, string phone, string seat) {
	this->first_name = first_name;
	this->last_name = last_name;
	this->id = id;
	this->phone = phone;
	passenger_seat.set(seat);
}

string Passenger::get_first_name() {
	return first_name;
}

string Passenger::get_last_name() {
	return last_name;
}

string Passenger::get_id() {
	return id;
}

string Passenger::get_phone() {
	return phone;
}

Seat Passenger::get_seat() {
	return passenger_seat;
}

void Passenger::set_first_name(string name) {
	first_name = name;
}

void Passenger::set_phone(string phone) {
	this->phone = phone;
}

void Passenger::set_seat(Seat seat) {
	this->passenger_seat = seat;
}

void Passenger::set_last_name(string name) {
	last_name = name;
}

void Passenger::set_id(string id) {
	this->id = id;
}


string Passenger::to_string() {
	string str = first_name + last_name + phone + passenger_seat.get_row() + passenger_seat.get_seat() + id + "\n";
	return str;
}
/* Function displayPassenger is responsible for displaying the
* passenger information.
*/
void Passenger::display_passenger() {
	cout << first_name << last_name << phone << passenger_seat.get_row() << "\t   " << passenger_seat.get_seat() << "\t" << id << endl;
}