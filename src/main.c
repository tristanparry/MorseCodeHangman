/////////////////////////////////////////////////////////////////////
//                       MAIN PROGRAM FILE                         //
// ECE 198 - Project Group 65 - Farzan Mirshekari & Tristan Parry  //
//                        Developed 2021                           //
/////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "alphabet.h"
#include "board_functions.h"
#include "game_functions.h"
#include "ece198.h"
#include "LiquidCrystal.h"

int main(void) {

    //////////////////////////////
    // HARDWARE INITIALIZATIONS //
    //////////////////////////////
    
    HAL_Init(); // Initialize the Hardware Abstraction Layer
    // __HAL_RCC_GPIOA_CLK_ENABLE(); // Enable port A (for the on-board LED, for example)
    __HAL_RCC_GPIOB_CLK_ENABLE(); // Enable port B (for the rotary encoder inputs, for example)
    __HAL_RCC_GPIOC_CLK_ENABLE(); // Enable port C (for the on-board blue pushbutton, for example)
    LiquidCrystal(GPIOB, GPIO_PIN_9, GPIO_PIN_8, GPIO_PIN_6, GPIO_PIN_10, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_3); // LCD DISPLAY
    
    /////////////////////
    // MAIN GAME LOGIC //
    /////////////////////

    print_lcd("   Morse Code   ", "    Hangman!    ");

    char chosen_word[16] = {};
    char hidden_word[16] = {};
    unsigned int num_tries_left = 8;

    unsigned int word_length = word_length_click_counter();
    print_lcd("Enter Word:", "");
    get_word(chosen_word, word_length);
    encrypt_word(hidden_word, word_length);
    print_lcd(hidden_word, "");
    
    // Game Loop
    while (num_tries_left > 0) {

        char buff[100];
        sprintf(buff, "%d", num_tries_left);
        print_lcd_overload(hidden_word, "Tries: ", buff);

        char letter[5] = {};
        for (int i = 0; i < 4; ++i) {
            letter[i] = parse_input();
            if (letter[i] == '\0') {
                break;
            }
        }
        
        char user_choice = get_letter(letter);

        sprintf(buff, "%d", num_tries_left);
        print_lcd_overload(hidden_word, "Tries: ", buff);

        check_letter(user_choice, chosen_word, hidden_word, word_length, &num_tries_left);
        print_lcd(hidden_word, buff);
        
        if (is_game_won(hidden_word, word_length)) {
            print_lcd(hidden_word, "");
            HAL_Delay(1500);
            print_lcd("**** WINNER ****", "****************");
            sound_buzzer();
            NVIC_SystemReset();
        }
    }
    if (!is_game_won(hidden_word, word_length)) {
        print_lcd_overload("You Lost!", "Word: ", chosen_word);
        sound_buzzer();
        NVIC_SystemReset();
    }
}

// This function is called by the HAL once every millisecond
void SysTick_Handler(void) { HAL_IncTick(); }