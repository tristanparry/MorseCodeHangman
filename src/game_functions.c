////////////////////////////////////////////////////////////
//                HANGMAN GAME FUNCTIONS                  //
// Utilized within the main logic for Project 65 (main.c) //
////////////////////////////////////////////////////////////

#include <stdbool.h>
#include "board_functions.h"
#include "ece198.h"
#include "LiquidCrystal.h"

// Sets an array of the specified word length to all underscores
// (used in printing/comparing to the word array being guessed by the user)
void encrypt_word(char * encrypted_word, unsigned int word_length) {
    for (int i = 0; i < word_length; ++i) {
        encrypted_word[i] = '_';
    }
}

// Compares the user's current input letter with the initially chosen word, updating/revealing
// characters in the encrypted word as necessary
void check_letter(char user_choice, char * chosen_word, char * encrypted_word, unsigned int word_length, unsigned int * num_tries_left) {
    bool is_in_word = false;
    for (int i = 0; i < word_length; ++i) {
        if (chosen_word[i] == user_choice) {
            encrypted_word[i] = user_choice;
            is_in_word = true;
        }
    }
    if (!is_in_word) {
        --(*num_tries_left);
    }
}

// Checks if the entire encrypted word is revealed (if the user has won the game)
bool is_game_won(char * encrypted_word, unsigned int word_length) {
    for (int i = 0; i < word_length; ++i) {
        if (encrypted_word[i] == '_') {
            return false;
        }
    }
    return true;
}
