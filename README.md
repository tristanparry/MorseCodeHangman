![morse_icon](https://user-images.githubusercontent.com/64918749/142749381-b82eb312-be18-472f-b1b4-166bbf694ed1.jpg)
# Morse Code Hangman (ECE 198)

Project Group 65's submission for their ECE 198 final prototype (1A Electrical/Computer Engineering, University of Waterloo).

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

<h3>Description</h3>

> This prototype uses the STM32 Nucleo-64 Microcontroller, a 16x2 Parallel LCD, and an Active Low-Level Trigger Buzzer to create a full hangman game for a user. The game includes functionality for processing user input for morse code words, and printing appropriate data to the LCD.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

<h3>Morse Code Alphabet</h3>

> The prototype utilizes the International Morse Code Alphabet to decode user input
> 
> ![362px-International_Morse_Code_-_letters svg](https://user-images.githubusercontent.com/64918749/143285246-d951c478-bb9b-4ef1-aaca-1377b0c95f0f.png)
>
> <i>Retrieved from [CodeBug](https://www.codebug.org.uk/learn/step/540/morse-code-alphabet/)</i>

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

<h3>How To Play</h3>

> <b>PART I:</b> <i>Choosing the word</i> <br>
> > 1) Enter the number of letters in your chosen word by clicking once per character, followed by a long press. <br>
> > 2) Enter the characters in the chosen letter one by one using the provided Morse code table. If a character consists of less than four dots or  dashes, end the entry with a long press. You will see the word on the display as it is being inputted. <br>
>
> <b>PART II:</b> <i>Guessing the mystery word</i> <br>
> > 1) You have 8 tries to guess the mystery word. <br>
> > 2) Using the same method, enter the letter of your choice using the Morse code table. <br>
> > 3) The remaining number of tries can be seen on the display. <br>

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

<h3>Acknowledgements</h3>

> Project Group 65 would like to thank instructor Bernie Roehl for his provision of microcontroller source code files (ece198.h/ece198.c)

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

<i>Developed by Farzan Mirshekari & Tristan Parry, 2021</i>
