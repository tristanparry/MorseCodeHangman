////////////////////////////////////////////////////////////
//          HANGMAN GAME FUNCTIONS (HEADER FILE)          //
// Utilized within the main logic for Project 65 (main.c) //
////////////////////////////////////////////////////////////

// Sets an array of the specified word length to all underscores
// (used in printing/comparing to the word array being guessed by the user)
void encrypt_word(char * encrypted_word, unsigned int word_length);

// Compares the user's current input letter with the initially chosen word, updating/revealing
// characters in the encrypted word as necessary
void check_letter(char user_choice, char * chosen_word, char * encrypted_word, unsigned int word_length, unsigned int * num_tries_left);

// Checks if the entire encrypted word is revealed (if the user has won the game)
bool is_game_won(char * encrypted_word,  unsigned intword_length);