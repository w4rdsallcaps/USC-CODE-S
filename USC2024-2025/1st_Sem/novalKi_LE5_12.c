/*
============================================================================
FILE : novalKi_LE5_12.c
AUTHOR : Kineth Montaus Noval
DESCRIPTION :   Program that will ask the correct numeric passcode before the user can continue his task.
 The user is given only three trials to enter the correct passcode. When the user hit the correct passcode the program will display “ACCESS GRANTED”, 
 otherwise it will display “ACCESS DENIED” after three attempts.
COPYRIGHT : 30/09/2024
============================================================================
*/
#include<stdio.h>

int main() {
    int password = 12345;    // Correct password
    int userInput;           // Stores user input
    int counter = 3;         // Number of attempts allowed

    printf("Enter your password: ");
    scanf("%d", &userInput);  // Get the first input

    // Loop to allow the user up to 3 attempts
    do {
        if (password == userInput) {  // Check if the password is correct
            printf("RAWR YOU GOT IN!!!!!!!!!!!");
            return 0;  // Exit program if successful
        } 
        else {
            printf("WRONG ANSWER DO IT AGAIN: ");
            scanf("%d", &userInput);  // Get another input
            counter--;  // Decrease attempts remaining

            if (counter == 0 && password != userInput) {  // Last attempt failed
                printf("RAWR I WONT LET YOU IN!!!!!!!!!!!!!!!");
            }

            if (password == userInput) {  // Check again if new input is correct
                printf("RAWR YOU GOT IN!!!!!!!!!!!");
                return 0;  // Exit if successful
            }
        }
    } while (counter > 0);  // Repeat until no attempts left

    return 0;  // End program
}
