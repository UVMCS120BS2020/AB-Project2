//
// Created by ABlack on 2/13/2020.
//

#ifndef AB_PROJECT2_GLOBALFUNCTIONS_H
#define AB_PROJECT2_GLOBALFUNCTIONS_H
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <cstdlib>
#include <cmath>
#include "Piano.h"
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

typedef optional<int> optInt;


/*
 * Input Check
 * Requires: String input.
 * Modifies: cin, cout
 * Effects: Checks the string for valid input. Returns true if the input follows
 *          the format, and returns false otherwise.
 * Global function
 */
bool firstCheck(string &input);

/*
 * Results and Play Again
 * Requires: Piano object pointer, string input, valid boolean.
 * Modifies: cin, cout, input, valid
 * Effects: Displays the results of newly entered music,
 *          and prompts user for new input, including playing the same music again.
 * Calls: firstCheck, getNotes, getOctaves, getDelay,
 * Global function
 */
void resultsAndPlayAgain(const unique_ptr<Piano> &piano, string &input, bool &valid);





#endif //AB_PROJECT2_GLOBALFUNCTIONS_H
