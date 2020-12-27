#include "Flight.h"
#include <iostream>
#include <vector>
using namespace std;

Flight::Flight() :f_row(0), f_seat(0), f_name("") {
}
int Flight::get_flight_row() {
    return f_row;
}
int Flight::get_flight_seat() {
    return f_seat;
}
string Flight::get_flight_name() {
    return f_name;
}
void Flight::get_seat_map_size() {
    cout << "Number of Rows: " << seat_map.size() << " Number of Seats: " << seat_map.at(0).size() << "\n";
}
vector<Passenger> Flight::get_passenger_list() {
    return passenger;
}

void Flight::set_flight_seat(int seat) {
    f_seat = seat;
    for (int k = 0; k < f_row; k++)
        seat_map.at(k).resize(seat);
}
void Flight::set_passenger_list(vector <Passenger> list) {
    passenger = list;
}
void Flight::set_flight_name(string name) {
    f_name = name;
}
void Flight::set_flight_row(int row) {
    f_row = row;
    seat_map.resize(row);
}

void Flight::set_passenger_list_size() {
    passenger.reserve(f_row * f_seat);
}
/* Function set_seat is responsible for setting up the
* row and seat chosen by the passenger.
*/
void Flight::set_seat(string seat) {
    if (check_seat(seat)) {
        string seat_number = "";
        string seat_letter = "";
        for (int k = 0; k < (int)seat.length(); k++) {
            if (isdigit(seat[k]))
                seat_number.push_back(seat[k]);
            else
                seat_letter.push_back(seat[k]);
        }
        int sch = (int)(seat_letter[0] - 'A');
        seat_map.at(str_to_int(seat_number)).at(sch).set_row(seat_number);
        seat_map.at(str_to_int(seat_number)).at(sch).set_seat(seat_letter);
        seat_map.at(str_to_int(seat_number)).at(sch).set_mark("X");
    }
}
/* Function erase_seat is responsible for setting up the
* row and seat chosen by the passenger.
*/
void Flight::erase_seat(string seat) {
    string seat_number = "";
    string seat_letter = "";
    for (int k = 0; k < (int)seat.length(); k++) {
        if (isdigit(seat[k]))
            seat_number.push_back(seat[k]);
        else
            seat_letter.push_back(seat[k]);
    }
    int sch = (int)(seat_letter[0] - 'A');
    seat_map.at(str_to_int(seat_number)).at(sch).set_mark(" ");
}
/* Function set_passenger is responsible for setting up the passenger's
* information. first_name is the first name of the passenger, last_name
* is the last name of the passenger and id, phone and seat
* are also passengers information.
*/
void Flight::set_passenger(string first_name, string last_name, string id, string phone, string seat)
{
    if (first_name.length() < 20)
        first_name.append(20 - first_name.length(), ' ');
    if (last_name.length() < 20)
        last_name.append(20 - last_name.length(), ' ');
    if (phone.length() < 21)
        phone.append(21 - phone.length(), ' ');
    if (seat.length() < 4)
        seat.append(4 - seat.length(), ' ');
    if (id.length() < 5)
        id.append(5 - id.length(), ' ');
    set_seat(seat);
    Passenger new_p(first_name, last_name, id, phone, seat);
    passenger.push_back(new_p);
}
void Flight::set_seat_map_size(int row, int seat)
{
    seat_map.resize(row);
    for (int k = 0; k < row; k++)
        seat_map.at(k).resize(seat);
}

void Flight::set_seat_map(vector <vector<Seat>> seat) {
    seat_map = seat;
}

/* Function showMap is responsible for displaying the aircraft's
* seats.
*/
void Flight::show_map()
{
    cout << "\n\t   Aircraft Seat Map \n\n    ";
    cout << "    ";
    for (int k = 0; k < f_seat; k++) {
        char letter = 'A';
        cout << "  " << static_cast<char>(letter + k) << " ";
    }

    cout << "\n";
    int r = 0;
    for (int k = 0; k < (f_row) * 2; k++) {
        if (k % 2 != 0) {
            cout << r << "\t";
            for (int m = 0; m < f_seat; m++) {
                if (f_seat - 1 == m)
                    cout << "| " << seat_map.at(r).at(m).get_mark() << " |";
                else
                    cout << "| " << seat_map.at(r).at(m).get_mark() << " ";
            }
            r++;

        }
        else {
            cout << "\t";
            for (int m = 0; m < f_seat; m++) {
                if (f_seat - 1 == m)
                    cout << "+---+";
                else
                    cout << "+---";
            }
        }
        cout << "\n";
    }
    cout << "\t";
    for (int z = 0; z < f_seat; z++) {
        if (f_seat - 1 == z)
            cout << "+---+";
        else
            cout << "+---";
    }
    cout << "\n";
}
/* Function str_to_int is responsible for changing the argument number
* from string to integer.
*/
int Flight::str_to_int(string number) {
    int result = 0;
    for (int i = 0; i < (int)number.length(); i++)
        result = 10 * result + ((int)number.at(i) - 48);
    return result;

}
/* Function checkId is responsible for checking the passed id with
* the id's in data. If id is matched, function returns false and
* returns true otherwise.
*/
bool Flight::check_id(string id) {
    for (Passenger p : passenger) {
        if (p.get_id().compare(id) == 0)
            return false;
    }
    return true;
}
/* Function check_seat is responsible for checking the avaliability of the
* passed string seat. Returns false if the seat is taken and returns
* true otherwise.
*/
bool Flight::check_seat(string st) {
    string seatNumber = "";
    string seatLetter = "";
    for (int k = 0; k < (int)st.length(); k++) {
        if (isdigit(st[k]))
            seatNumber.push_back(st[k]);
        else
            seatLetter.push_back(st[k]);
    }
    char avSeat = 'A';
    avSeat = avSeat + f_seat - 1;
    int s = (int)(seatLetter[0] - 'A');
    if (str_to_int(seatNumber) < 0 || str_to_int(seatNumber) >= f_row || seatLetter.compare("A") < 0 || seatLetter.compare(string(1, avSeat)) > 0)
        return false;
    else if (seat_map.at(str_to_int(seatNumber)).at(s).get_mark().compare("X") == 0)
        return false;
    else
        return true;

}
/* Function isNumber is responsible for checking if the
* string n is a number. Returns true if it is a number and
* returns false otherwise.
*/
bool Flight::is_number(const string& n)
{
    string::const_iterator it = n.begin();
    while (it != n.end() && isdigit(*it))
        ++it;
    return !n.empty() && it == n.end();
}
/* Function hasNum is responsible for checking if the
* string str has a number in it. Returns true if it does
* have a number and returns false otherwise.
*/
bool Flight::has_num(const string& str) {
    if (find_if(str.begin(), str.end(), (int(*)(int))isdigit) != str.end())
        return true;
    else
        return false;
}
/* Function hasLet is responsible for checking if the
* string st has a letter in it. Returns true if it does
* have a letter and returns false otherwise.
*/
bool Flight::has_let(const string& st) {
    if (find_if(st.begin(), st.end(), (int(*)(int))isalpha) != st.end())
        return true;
    else
        return false;
}

/* Function add_passenger is responsible for adding the passenger
* info to the database. setPassenger function is called within
* add_passenger to set up the passenger info.
*/

void Flight::add_passenger(Flight& f) {
    string first_name, last_name, phone, seat, id, row;
    char avSeat = 'A' + get_flight_seat() - 1;

    cout << "Please enter a number for the passenger id: ";
    cin >> id;
    while (!is_number(id) || (is_number(id) && !check_id(id)))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!check_id(id))
            cout << "That ID is taken, please try again: ";
        else
            cout << "Invalid input, please try again:  ";
        cin >> id;
    }

    cout << "Please enter the passenger first name: ";
    cin >> first_name;
    while (has_num(first_name))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, please try again: ";
        cin >> first_name;
    }

    cout << "Please enter the passenger last name: ";
    cin >> last_name;
    while (has_num(last_name))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, please try again: ";
        cin >> last_name;
    }

    cout << "Please enter the passenger phone number: ";
    cin >> phone;
    while (has_let(phone) || phone.length() > 12 || (is_number(row) && str_to_int(row) >= get_flight_row())) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, please try again: ";
        cin >> phone;
    }

    cout << "Enter the passenger's desired row: ";
    cin >> row;
    while (!is_number(row) || (is_number(row) && str_to_int(row) < 0) || (is_number(row) && str_to_int(row) >= get_flight_row())) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, please try again: ";
        cin >> row;
    }
seat_try_again:
    cout << "Enter the passenger's desired seat: ";
    cin >> seat;
    while (seat.compare(string(1, avSeat)) > 0 || seat.compare("A") < 0) {
        cin.clear();
        cout << "Invalid input, please try again: ";
        cin >> seat;
    }
    if (check_seat(row + seat) == false) {
        cout << "This seat is taken, please try again. \n";
        goto seat_try_again;
    }
    string fin_seat = row + seat;
    set_passenger(first_name, last_name, id, phone, fin_seat);
    cout << "Passenger was added. \n";
}
/* Function displayPassenger is responsible for displaying
* passenger information.
*/

void Flight::display_passenger(Flight& f) {
    cout << "\nFirst Name\t   Last Name\t\tPhone\t\t   Row\t  Seat\t  ID\n";
    cout << "-------------------------------------------------------------------------------\n";
    for (int i = 1; i < (int)passenger.size(); i++)
    {
        get_passenger_list().at(i).display_passenger();
        cout << "-------------------------------------------------------------------------------\n";
    }
}
/* Function removePass is responsible erasing the passenger
* with the id that matches the id passed to the function.
*/
string Flight::remove_pass(string id) {
    string res;
    for (int i = 0; i < (int)passenger.size(); i++) {
        if (passenger.at(i).get_id().compare(id) == 0) {
            res = passenger.at(i).get_seat().get_row() + passenger.at(i).get_seat().get_seat();
            erase_seat(res);
            passenger.erase(passenger.begin() + i);
            return "\nPassenger deleted. \n";
        }
    }
    return "\nPassenger was not deleted, ID not found. \n";
}
/* Function remove_passenger is responsible erasing the passenger
* information from the database.
*/
void Flight::remove_passenger(Flight& f) {
    string pass_id;
    cout << "Please enter a number for the passenger id: ";
    cin >> pass_id;
    while (!is_number(pass_id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, please try again: ";
        cin >> pass_id;
    }
    cout << remove_pass(pass_id);
}
/* Function save_info is responsible saving the passengers'
* information to a text file.
*/
void Flight::save_info(Flight& f, string file_name) {
    ofstream outFile(file_name);
    if (outFile.fail()) {
        cout << "File cant be opened " << file_name << "\n";
        exit(1);
    }

    string ans = "";

    cout << "Do you want to save the data in the " << file_name << "? Please answer <Y or N> ";
    cin >> ans;
    while (ans.compare("N") != 0 && ans.compare("Y") != 0) {
        cin.clear();
        cout << "Invalid input, please try again: ";
        cin >> ans;
    }

    if (ans.compare("Y") == 0) {
        ofstream outFile(file_name);
        if (outFile.fail()) {
            cout << "File cant be opened. \n";
            exit(1);
        }
        outFile << f.get_flight_name() << " " << f.get_flight_row() << " " << f.get_flight_seat();
        for (int i = 0; i < (int)f.get_passenger_list().size(); i++) {
            outFile << f.get_passenger_list().at(i).to_string();
        }
        cout << "All the data in the passenger list was saved into the " << file_name << ". \n";
    }
    else
        cout << "Unable to save. \n";
}