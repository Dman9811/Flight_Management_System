#include "Passenger.h"
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <algorithm>
using namespace std;
class Flight {
private:
    int f_row;
    int f_seat;
    string f_name;
    vector<vector<Seat>> seat_map;
    vector<Passenger> passenger;

public:

    Flight();
    string get_flight_name();
    int get_flight_row();
    int get_flight_seat();
    vector<Passenger> get_passenger_list();
    void get_seat_map_size();
    void set_flight_name(string name);
    void set_flight_row(int row);
    void set_flight_seat(int seat);
    void set_seat_map_size(int row, int seat);
    void set_seat_map(vector <vector<Seat>> seat);
    void set_passenger_list(vector<Passenger> list);
    void set_passenger_list_size();
    void set_passenger(string first_name, string last_name, string id, string phone, string seat);
    void set_seat(string seat);
    void erase_seat(string seat);
    void show_map();
    int str_to_int(string num);
    string remove_pass(string id);
    bool check_id(string i);
    bool check_seat(string s);
    bool has_num(const string& str);
    bool has_let(const string& st);
    bool is_number(const string& n);
    void display_passenger(Flight& f);
    void add_passenger(Flight& f);
    void remove_passenger(Flight& f);
    void save_info(Flight& f, string file_name);
};
