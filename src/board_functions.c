////////////////////////////////////////////////////////////
//               MICROCONTROLLER FUNCTIONS                //
// Utilized within the main logic for Project 65 (main.c) // 
////////////////////////////////////////////////////////////

#include <stdbool.h>
#include "alphabet.h"
#include "board_functions.h"
#include "ece198.h"
#include "LiquidCrystal.h"

// Check for button click, calculate time button is held down
unsigned long click_time() {
    while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)); // Wait for button to be clicked
    unsigned long start = HAL_GetTick();
    while (!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)); // Wait for button to be released
    return (HAL_GetTick() - start);
}

// Measures time user clicks/holds button on microcontroller, returns
// an associated value for a short click, long click, or invalid click
int click_length(unsigned long time_measured) {
    if (time_measured <= 500) {
        return 0; // Short click
    } else if (time_measured <= 2000) {
        return 1; // Long click
    } else {
        return -1; // Invalid input
    }
}

// Gets the length of the user-inputted hangman word, by counting board button clicks
unsigned int word_length_click_counter() {
    unsigned int word_length = 0;
    while (click_length(click_time()) == 0) {
        ++word_length;
    }
    if (word_length > 16) {
        print_lcd("Word Too Long!", "Try Again!");
        HAL_Delay(1500);
        NVIC_SystemReset();
    }
    return word_length;
}

// Reads user input for a single morse code input
char parse_input() {
    int click_input = click_length(click_time());
    if (click_input == 0) { // Short click
        return '.';
    } else if (click_input == 1) { // Long click
        return '_';
    } else {
        return '\0';
    }
}

// Reads user input and fabricates a string corresponding to a morse code word
void get_word(char * word_array, unsigned int word_length) {
    for (int i = 0; i < word_length; ++i) {
        char letter[5] = {};
        for (int i = 0; i < 4; ++i) {
            letter[i] = parse_input();
            if (letter[i] == '\0') {
                break;
            }
        }
        word_array[i] = get_letter(letter);
        print_lcd_overload("Enter Word:", word_array, "");
        HAL_Delay(1000);
    }
}

// Prints passed strings to the LCD
void print_lcd(char * string_1, char * string_2) {
    clear();
    setCursor(0,0);
    print(string_1);
    setCursor(0,1);
    print(string_2);
}

// Prints passed strings to the LCD (overloaded function)
void print_lcd_overload(char * string_1, char * string_2, char * string_3) {
    clear();
    setCursor(0,0);
    print(string_1);
    setCursor(0,1);
    print(string_2);
    print(string_3);
}

// Sounds the buzzer in a specified pattern
void sound_buzzer() {
    for (int i = 0; i < 5; ++i) {
        InitializePin(GPIOC, GPIO_PIN_1, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0);
        HAL_Delay(100);
        HAL_GPIO_DeInit(GPIOC, GPIO_PIN_1);
        HAL_Delay(100);
    }
}
