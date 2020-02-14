//
// Created by ABlack on 1/29/2020.
//

#ifndef AB_PROJECT2_PIANO_H
#define AB_PROJECT2_PIANO_H
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <cstdlib>
#include <cmath>
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
using namespace std;

typedef optional<int> optInt;

class Piano {
private:
    vector<char> notes;
    vector<int> octaves;
    optInt delay;
    double c;
    double d;
    double e;
    double f;
    double g;
    double a;
    double b;
public:

    /*
     * Default Constructor
     * Requires: Nothing.
     * Modifies: notes, octaves, c, d, e, f, g, a, b
     * Effects: Sets fields to default values.
     */
    Piano();

    /*
     * Getters
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects: Returns value of the field(s).
     */
    const vector<char> &getNotes() const;
    const vector<int> &getOctaves() const;
    optInt getDelay() const;
    double getC() const;
    double getD() const;
    double getE() const;
    double getF() const;
    double getG() const;
    double getA() const;
    double getB() const;

    /*
     * Setters
     * Requires: character vector and double inputs.
     * Modifies: The field(s) being set.
     * Effects: Sets the field(s) to the input values.
     */
    void setNotes(const vector<char> &notes);
    void setOctaves(const vector<int> &octaves);
    void setDelay(int delay);
    void setC(double c);
    void setD(double d);
    void setE(double e);
    void setF(double f);
    void setG(double g);
    void setA(double a);
    void setB(double b);

    /*
     * Play
     * Requires: Nothing.
     * Modifies: cout
     * Effects: Uses notes and octaves fields of a Piano object to play respective tones.
     * Calls: calcFrequencies
     */
    void play();

    /*
     * Play
     * Requires: Character vector input.
     * Modifies: cout
     * Effects: Uses user input to play respective tones.
     * Calls: loadVecs, calcFrequencies
     */
    void play(string input);

    /*
     * Load (field) Vectors
     * Requires: Character vector input.
     * Modifies: notes, octaves
     * Effects: Takes user's input and loads values into respective field vectors.
     */
    void loadVecs(const vector<char> &input);

    /*
     * Calculate Frequencies
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects: Uses field vectors to calculate the frequencies of each note.
     *          The frequencies are pushed into a vector and returned.
     */
    vector<double> calcFrequencies();

};

/*
 * Requires: Nothing.
 * Modifies: cout
 * Effects: Displays information prompt for the program.
 * Global function
 */
void prompt();

#endif //AB_PROJECT2_PIANO_H
