////////////////////////////////////////////////////////////
//              MORSE CODE LETTER FUNCTIONS               //
// Utilized within the main logic for Project 65 (main.c) //
////////////////////////////////////////////////////////////

#include <string.h>
#include "alphabet.h"
#include "board_functions.h"

const char * morse_alphabet[26] = {
    "._",      // A
    "_...",    // B
    "_._.",    // C
    "_..",     // D
    ".",       // E
    ".._.",    // F
    "__.",     // G
    "....",    // H
    "..",      // I
    ".___",    // J
    "_._",     // K
    "._..",    // L
    "__",      // M 
    "_.",      // N
    "___",     // O
    ".__.",    // P
    "__._",    // Q
    "._.",     // R
    "...",     // S
    "_",       // T
    ".._",     // U 
    "..._",    // V
    ".__",     // W
    "_.._",    // X
    "_.__",    // Y
    "__.."     // Z
};

// Gets a required letter from the morse code alphabet array
char get_letter(char * morse_input) {
    for (int i = 0; i < 26; ++i) {
        if (strcmp(morse_alphabet[i], morse_input) == 0) {
            return (65 + i);
        }
    }
    return 0;
}