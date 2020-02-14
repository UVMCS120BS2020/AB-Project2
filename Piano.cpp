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
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

typedef optional<int> optInt;

Piano::Piano() {
    notes = {'C','D','E','F','G','A','B','C'};
    octaves = {4,4,4,4,4,4,4,4,5};
    delay = nullopt;
    c = 32.703;
    d = 36.708;
    e = 41.203;
    f = 43.654;
    g = 48.999;
    a = 55;
    b = 61.735;
}

const vector<char> &Piano::getNotes() const {
    return notes;
}
const vector<int> &Piano::getOctaves() const {
    return octaves;
}
optInt Piano::getDelay() const
{
    return delay;
}
double Piano::getC() const {
    return c;
}
double Piano::getD() const {
    return d;
}
double Piano::getE() const {
    return e;
}
double Piano::getF() const {
    return f;
}
double Piano::getG() const {
    return g;
}
double Piano::getA() const {
    return a;
}
double Piano::getB() const {
    return b;
}

void Piano::setNotes(const vector<char> &notes) {
    this->notes = notes;
}
void Piano::setOctaves(const vector<int> &octaves) {
    this->octaves = octaves;
}
void Piano::setDelay(int delay) {
    if (delay == 0) {
        this->delay = 500;
    } else {
        this->delay = delay;
    }
}
void Piano::setC(double c) {
    this->c = c;
}
void Piano::setD(double d) {
    this->d = d;
}
void Piano::setE(double e) {
    this->e = e;
}
void Piano::setF(double f) {
    this->f = f;
}
void Piano::setG(double g) {
    this->g = g;
}
void Piano::setA(double a) {
    this->a = a;
}
void Piano::setB(double b) {
    this->b = b;
}

void Piano::play() {
    vector<double> frequencies = calcFrequencies();
    for(int i = 0; i < frequencies.size(); i++) {
        cout << notes[i] << octaves[i] << endl;
        if (delay){
            Beep(frequencies[i], *delay);
        } else {
            Beep(frequencies[i], 500);
        }
    }
}

void Piano::play(string input) {
    vector<char> inputVec(input.begin(), input.end());
    loadVecs(inputVec);
    vector<double> frequencies = calcFrequencies();
    for(int i = 0; i < frequencies.size(); i++) {
        cout << notes[i] << octaves[i] << endl;
        if (delay){
            Beep(frequencies[i], *delay);
        } else {
            Beep(frequencies[i], 500);
        }
    }
}

void Piano::loadVecs(const vector<char> &input) {
    notes.clear();
    octaves.clear();
    for(int i = 0; i < input.size()/2; i++) {
        notes.push_back(input[2*i]);
        // Convert character to respective integer (not its ASCII value).
        int inputInt = input[2*i + 1] - '0';
        octaves.push_back(inputInt);
    }
}

vector<double> Piano::calcFrequencies() {
    vector<double> frequencies;
    double freq;
    for(int i = 0; i < notes.size(); i++) {
        freq = 0;
        switch(notes[i]) {
            case 'C':
                freq = c*pow(2.0,octaves[i]-1);
                break;
            case 'D':
                freq = d*pow(2.0,octaves[i]-1);
                break;
            case 'E':
                freq = e*pow(2.0,octaves[i]-1);
                break;
            case 'F':
                freq = f*pow(2.0,octaves[i]-1);
                break;
            case 'G':
                freq = g*pow(2.0,octaves[i]-1);
                break;
            case 'A':
                freq = a*pow(2.0,octaves[i]-1);
                break;
            case 'B':
                freq = b*pow(2.0,octaves[i]-1);
                break;
        }
        frequencies.push_back(freq);
    }
    return frequencies;
}




void prompt() {
    cout << "\t\t **********Simple Electronic Music Maker**********" << endl;
    cout << "\t\t Please enter a string in this format: &#&#&#...." << endl;
    cout << "\t\t & is a note-- C,D,E,F,G,A,B (Case sensitive)" << endl;
    cout << "\t\t # is an octave-- an integer from 1 to 8" << endl;
    cout << "\t\t Your input must begin with a note, and each note must be followed by an octave number." << endl;
    cout << "\t\t Example: C4D4E4F4G4A4B4C5" << endl;
}
