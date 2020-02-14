//
// Created by ABlack on 2/13/2020.
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

bool firstCheck(string &input) {
    const string notes = "CDEFGAB";
    const string octaves = "12345678";

    while(!(getline(cin,input))) {
        cout << "Invalid input. Please follow the format." << endl;
        cout << "Input (Enter X to exit):";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if(input != "X" && input != "Y") {
        //  Convert string input to a vector of characters
        vector<char> inputVec(input.begin(), input.end());
        if (inputVec.size() % 2 != 0) {
            return false;
        }
        for (int i = 0; i < inputVec.size()/2; i++) {
            if (notes.find(inputVec[2*i]) == string::npos || octaves.find(inputVec[2*i + 1]) == string::npos) {
                return false;
            }
        }
    }
    return true;
}

void resultsAndPlayAgain(const unique_ptr<Piano> &piano, string &input, bool &valid){
    cout << "\nYour current music:" << endl;
    for (int i = 0; i < piano->getNotes().size(); i++) {
        cout << piano->getNotes()[i] << piano->getOctaves()[i] << " ";
    }
    cout << "\nDelay: " << *piano->getDelay() << " milliseconds" << endl;
    cout << "Go again? Input (Enter X to exit, or Y to play your music again):";
    valid = firstCheck(input);

    while (input == "Y" || !valid) {
        if (!valid) {        // Invalid input. Continue until input is valid.
            cout << "Invalid input. Please follow the format." << endl;
            cout << "Input (Enter X to exit, or Y to play your music again):";
            valid = firstCheck(input);
        } else {
            piano->play();

            cout << "\nYour current music:" << endl;
            for (int i = 0; i < piano->getNotes().size(); i++) {
                cout << piano->getNotes()[i] << piano->getOctaves()[i] << " ";
            }
            cout << "\nDelay: " << *piano->getDelay() << " milliseconds" << endl;
            cout << "Go again? Input (Enter X to exit, or Y to play your music again):";

            valid = firstCheck(input);
        }
    }
}