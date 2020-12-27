#include "Flight.h"
#include <limits>
#include <string>
using namespace std;
/* Function press_return is responsible for starting the program
* with user's input being 'ENTER'
*/
void press_return() {
    cout << "\n<<< Press Return to Continue>>>\n";
    cout << "\n<<< Press Return to Continue>>>\n";
    cin.get();
}
/* Function display_head is responsible for displaying the header
* information.
*/
void display_head() {
    cout << "Term Project - Flight Management Program in C++ \n";
    cout << "Created by: Daman Patel \n";
    cout << "Date: March 15, 2017 \n";
    cout << "Email: daamanpatel9811@gmail.com \n";
    press_return();
}
int str_to_int(string number) {
    int result = 0;
    for (int i = 0; i < (int)number.length(); i++)
        result = 10 * result + ((int)number.at(i) - 48);
    return result;

}

/* Function is_number is responsible for checking if the
* string str is a number. Returns true if it is a number and
* returns false otherwise.
*/
bool is_number(const string& str)
{
    string::const_iterator it = str.begin();
    while (it != str.end() && isdigit(*it))
        ++it;
    return !str.empty() && it == str.end();
}
/* Function clean_input is responsible for clearing the input
*
*/
void clean_input() {
    int res;
    do {
        res = cin.get();
    } while (res != EOF && res != '\n');
}
/* Function demo is responsible for displaying the main menu
* of the aircraft program.
*/

int demo() {
    string ch;
    cout << "\nPlease select one the following options:\n";
    cout << "[1] Display Flight Seat Map. \n";
    cout << "[2] Display Passengers Information.\n";
    cout << "[3] Add a New Passenger. \n";
    cout << "[4] Remove an Existing Passenger. \n";
    cout << "[5] Save data. \n";
    cout << "[6] Quit. \n";
    cout << "Enter your choice: (1, 2, 3, 4, 5 or 6): ";
    cin >> ch;
    while ((is_number(ch) && str_to_int(ch) <= 0) || !is_number(ch) || (is_number(ch) && str_to_int(ch) > 6)) {
        clean_input();
        cout << "\nPlease only enter numbers from 1 to 6: ";
        cin >> ch;
        cout << "\n";
    }

    return  str_to_int(ch);
}
/* Function populate_flight_from_file is responsible for
* populating the aircraft with the information from a passed
* file.
*/
Flight populate_flight_from_file(string file_name) {
    ifstream inFile(file_name, ios::in);

    if (inFile.fail()) {
        cout << "Unable to open file... quitting \n";
        exit(1);
    }
    Flight f;
    int flight_row, flight_seat;
    string flight_name;
    inFile >> flight_name >> flight_row >> flight_seat;
    f.set_flight_name(flight_name);
    f.set_flight_row(flight_row);
    f.set_flight_seat(flight_seat);
    string first_name, last_name, phone, seat, row, id;
    string line;
    while (!inFile.eof()) {
        getline(inFile, line);
        first_name = line.substr(0, 19);
        last_name = line.substr(first_name.length(), 20);
        phone = line.substr(first_name.length() + last_name.length(), 21);
        seat = line.substr(first_name.length() + last_name.length() + phone.length(), 4);
        id = line.substr(first_name.length() + last_name.length() + phone.length() + seat.length(), 5);
        f.set_passenger(first_name, last_name, id, phone, seat);
    }

    inFile.close();
    return f;
}


int main() {
    Flight f;
    display_head();
    f = populate_flight_from_file("C:\\Work\\C++\\Flight_management\\flight-info.txt");
    int sel;

    while ((sel = demo())) {
        switch (sel) {
        case 1:
            f.show_map();
            press_return();
            break;
        case 2:
            f.display_passenger(f);
            press_return();
            break;
        case 3:
            f.add_passenger(f);
            break;
        case 4:
            f.remove_passenger(f);
            break;
        case 5:
            f.save_info(f, "C:\\Work\\C++\\Flight_management\\flight-info.txt");
            break;
        case 6:
            cout << "Program terminated.";
            exit(1);
            break;
        }
    }
    return 0;

}
