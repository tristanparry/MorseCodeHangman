////////////////////////////////////////////////////////////
//         MICROCONTROLLER FUNCTIONS (HEADER FILE)        //
// Utilized within the main logic for Project 65 (main.c) //
////////////////////////////////////////////////////////////

// Check for button click, calculate time button is held down
unsigned long click_time();

// Measures time user clicks/holds button on microcontroller, returns
// an associated value for a short click, long click, or invalid click
int click_length(unsigned long time_measured);

// Gets the length of the user-inputted hangman word, by counting board button clicks
unsigned int word_length_click_counter();

// Reads user input for a single morse code input
char parse_input();

// Reads user input and fabricates a string corresponding to a morse code word
void get_word(char * word_array, unsigned int word_length);

// Prints passed strings to the LCD
void print_lcd(char * string_1, char * string_2);

// Prints passed strings to the LCD (overloaded function)
void print_lcd_overload(char * string_1, char * string_2, char * string_3);

// Sounds the buzzer in a specified pattern
void sound_buzzer();