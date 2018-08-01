// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "helpers.h"

#define A4_FREQ 440
#define OCTAVE_DIVISIONS 12

const string ORDERED_NOTES[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction) {
    string numer_s = strtok(fraction, "/");
    string denom_s = strtok(NULL, "/");
    int numerator = atoi(numer_s);
    int denominator = atoi(denom_s);
    return numerator * 8 / denominator;
}

// Calculates frequency (in Hz) of a note
int frequency(string note) {
    int octave = note[strlen(note) - 1] - '0';
    note[strlen(note) - 1] = '\0';

    int steps;
    for (steps = 0; steps < OCTAVE_DIVISIONS; steps++) {
        if (strcmp(note, ORDERED_NOTES[steps]) == 0) {
            break;
        }
    }
    steps -= 9; // shift to proper distance

    int offset = steps + (12 * (octave - 4));
    return round(A4_FREQ * pow(2, offset / 12.0));
}

// Determines whether a string represents a rest
bool is_rest(string s) {
    return strlen(s) == 0;
}
