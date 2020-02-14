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
bool testFirstCheckHelper(string &input);

bool testResultsAndPlayAgain();
bool testResultsAndPlayAgainHelper(const unique_ptr<Piano> &piano, string &input, bool &valid);

bool testPiano();
bool testPianoHelper();

bool testLoadVecs();
bool testLoadVecsHelper(const vector<char> &input);

bool testCalcFrequencies();
bool testCalcFrequenciesHelper();

int main(){

    return 0;
}

bool testFirstCheck() {

}
bool testFirstCheckHelper(string &input) {

}
