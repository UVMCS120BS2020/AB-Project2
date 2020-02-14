//
// Created by ABlack on 2/12/2020.
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

bool testFirstCheck();
bool testFirstCheckHelperGood(string input);
bool testFirstCheckHelperBad(string input);


int main(){
    if(testFirstCheck()) {
        cout << "firstCheck Test Passed." << endl;
    }

    return 0;
}

bool testFirstCheck() {
    return (testFirstCheckHelperGood("C4D4E4F4G4A4B4C5") && testFirstCheckHelperGood("X") &&
    testFirstCheckHelperGood("Y") && testFirstCheckHelperBad("C") &&
    testFirstCheckHelperBad("4") && testFirstCheckHelperBad("&") &&
    testFirstCheckHelperBad(" ") && testFirstCheckHelperBad("C4D") &&
    testFirstCheckHelperBad("C45") && testFirstCheckHelperBad("C4D4E4F4 G4A4B4C5") &&
    testFirstCheckHelperBad("4D") && testFirstCheckHelperBad("c4d4e4f4g4a4b4c5")
    );
}
bool testFirstCheckHelperGood(string input) {
    cout << "First Check Test (Good Input): ";
    if (!firstCheck(input)) {
        cout << "FAILED TEST CASE: " << input << endl;
        return false;
    } else {
        return true;
    }
}
bool testFirstCheckHelperBad(string input) {
    cout << "First Check Test (Bad Input): ";
    if (!firstCheck(input)) {
        return true;
    } else {
        cout << "FAILED TEST CASE: " << input << endl;
        return false;
    }
}

