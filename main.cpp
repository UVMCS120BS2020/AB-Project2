//
// Created by ABlack on 1/29/2020.
//
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <cstdlib>
#include <cmath>
#include "Piano.h"
#include "GlobalFunctions.h"
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

typedef optional<int> optInt;

int main() {
    prompt();

    unique_ptr<Piano> piano = make_unique<Piano>();
    string input;
    cout << "Input (Enter X to exit):";
    bool valid = firstCheck(input);

    bool keepGoing = true;
    while(keepGoing) {
        if (!valid) {        // Invalid input. Continue until input is valid.
            cout << "Invalid input. Please follow the format." << endl;
            cout << "Input (Enter X to exit):";
            valid = firstCheck(input);
        } else if (valid && input != "X") {      // Valid input that is not "X". Play the notes, then ask for input.
            cout << "Enter note duration in milliseconds (enter 0 for default delay):";
            int delay;
            while (!(cin >> delay) || delay < 0) {
                cout << "Invalid input. Enter note duration in milliseconds (enter 0 for default delay):";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            piano->setDelay(delay);
            piano->play(input);

            resultsAndPlayAgain(piano, input, valid);

        } else {        // "X" was entered. Display message and end program.
            cout << "\nThanks for Playing!" << endl;
            keepGoing = false;
        }
    }
    return 0;
}


