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

bool testPiano();
bool testPianoHelper(Piano &piano, const vector<char> &eNotes, const vector<int> &eOctaves, const optInt& delay,
        double eC, double eD, double eE, double eF, double eG, double eA, double eB);

int main() {
    if(testFirstCheck()) {
        cout << "firstCheck Test Passed." << endl;
    }
    if(testPiano()) {
        cout << "Piano Class Test Passed." << endl;
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

bool testPiano() {
    Piano piano = Piano();
    Piano piano1 = Piano();
    piano1.setNotes({'A','B','C'});
    Piano piano2 = Piano();
    piano2.setOctaves({1,2,3});
    Piano piano3 = Piano();
    piano3.setDelay(567);
    Piano piano4 = Piano();
    piano4.setDelay(0);
    Piano piano5 = Piano();
    piano5.setC(50);
    Piano piano6 = Piano();
    piano6.setD(60);
    Piano piano7 = Piano();
    piano7.setE(70);
    Piano piano8 = Piano();
    piano8.setF(80);
    Piano piano9 = Piano();
    piano9.setG(90);
    Piano piano10 = Piano();
    piano10.setA(100);
    Piano piano11 = Piano();
    piano11.setB(110);

    if(!testPianoHelper(piano, {'C','D','E','F','G','A','B','C'}, {4,4,4,4,4,4,4,4,5}, nullopt, 32.703, 36.708, 41.203, 43.654, 48.999, 55, 61.735)) {
        cout << "FAILED TEST CASE: Default Constructor" << endl;
        return false;
    }
    if(!testPianoHelper(piano1, {'A','B','C'}, {4,4,4,4,4,4,4,4,5}, nullopt, 32.703, 36.708, 41.203, 43.654, 48.999, 55, 61.735)){
        cout << "FAILED TEST CASE: setNotes" << endl;
        return false;
    }
    if(!testPianoHelper(piano2, {'C','D','E','F','G','A','B','C'}, {1,2,3}, nullopt, 32.703, 36.708, 41.203, 43.654, 48.999, 55, 61.735)) {
        cout << "FAILED TEST CASE: setOctaves" << endl;
        return false;
    }
    if(!testPianoHelper(piano3, {'C','D','E','F','G','A','B','C'}, {4,4,4,4,4,4,4,4,5}, 567, 32.703, 36.708, 41.203, 43.654, 48.999, 55, 61.735)) {
        cout << "FAILED TEST CASE: setDelay (non-zero)" << endl;
        return false;
    }
    if(!testPianoHelper(piano4, {'C','D','E','F','G','A','B','C'}, {4,4,4,4,4,4,4,4,5}, 0, 32.703, 36.708, 41.203, 43.654, 48.999, 55, 61.735)) {
        cout << "FAILED TEST CASE: setDelay (zero)" << endl;
        return false;
    }
    if(!testPianoHelper(piano5, {'C','D','E','F','G','A','B','C'}, {4,4,4,4,4,4,4,4,5}, nullopt, 50, 36.708, 41.203, 43.654, 48.999, 55, 61.735)) {
        cout << "FAILED TEST CASE: setC" << endl;
        return false;
    }
    if(!testPianoHelper(piano6, {'C','D','E','F','G','A','B','C'}, {4,4,4,4,4,4,4,4,5}, nullopt, 32.703, 60, 41.203, 43.654, 48.999, 55, 61.735)) {
        cout << "FAILED TEST CASE: setD" << endl;
        return false;
    }
    if(!testPianoHelper(piano7, {'C','D','E','F','G','A','B','C'}, {4,4,4,4,4,4,4,4,5}, nullopt, 32.703, 36.708, 70, 43.654, 48.999, 55, 61.735)) {
        cout << "FAILED TEST CASE: setE" << endl;
        return false;
    }
    if(!testPianoHelper(piano8, {'C','D','E','F','G','A','B','C'}, {4,4,4,4,4,4,4,4,5}, nullopt, 32.703, 36.708, 41.203, 80, 48.999, 55, 61.735)) {
        cout << "FAILED TEST CASE: setF" << endl;
        return false;
    }
    if(!testPianoHelper(piano9, {'C','D','E','F','G','A','B','C'}, {4,4,4,4,4,4,4,4,5}, nullopt, 32.703, 36.708, 41.203, 43.654, 90, 55, 61.735)) {
        cout << "FAILED TEST CASE: setG" << endl;
        return false;
    }
    if(!testPianoHelper(piano10, {'C','D','E','F','G','A','B','C'}, {4,4,4,4,4,4,4,4,5}, nullopt, 32.703, 36.708, 41.203, 43.654, 48.999, 100, 61.735)) {
        cout << "FAILED TEST CASE: setA" << endl;
        return false;
    }
    if(!testPianoHelper(piano11, {'C','D','E','F','G','A','B','C'}, {4,4,4,4,4,4,4,4,5}, nullopt, 32.703, 36.708, 41.203, 43.654, 48.999, 55, 110)) {
        cout << "FAILED TEST CASE: setB" << endl;
        return false;
    }
    return true;
}
bool testPianoHelper(Piano &piano, const vector<char> &eNotes, const vector<int> &eOctaves, const optInt& delay,
                     double eC, double eD, double eE, double eF, double eG, double eA, double eB) {
    if (delay == 0){
        return(piano.getNotes() == eNotes && piano.getOctaves() == eOctaves && piano.getDelay() == 500 &&
               piano.getC() == eC && piano.getD() == eD && piano.getE() == eE && piano.getF() == eF &&
               piano.getG() == eG && piano.getA() == eA && piano.getB() == eB
        );
    }
    return(piano.getNotes() == eNotes && piano.getOctaves() == eOctaves && piano.getDelay() == delay &&
           piano.getC() == eC && piano.getD() == eD && piano.getE() == eE && piano.getF() == eF &&
           piano.getG() == eG && piano.getA() == eA && piano.getB() == eB
    );
}