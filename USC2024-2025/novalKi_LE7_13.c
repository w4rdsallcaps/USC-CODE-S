/*
============================================================================
FILE : novalKi_LE7_13.c
AUTHOR : Kineth M Noval
DESCRIPTION :  
COPYRIGHT : 07/11/2024
============================================================================
*/
#include <stdio.h>
#include <string.h>

void check_longest_string(char current[], char longest[], int *maxLength);

int main() {
    char strings[5][100];  // Array to store 5 strings, each up to 99 characters long
    char longest[100];     // Array to store the longest string found
    int maxLength = 0;

    // Ask the user to input 5 strings
    for (int i = 0; i < 5; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(strings[i], sizeof(strings[i]), stdin);
        
        // Remove the newline character if it is at the end of the string
        strings[i][strcspn(strings[i], "\n")] = '\0';

        // Check if the current string is the longest so far
        check_longest_string(strings[i], longest, &maxLength);
    }

    // Display the longest string
    printf("The longest string is: %s\n", longest);

    return 0;
}

// Function to check if the current string is the longest
void check_longest_string(char current[], char longest[], int *maxLength) {
    int length = strlen(current);
    if (length > *maxLength) {
        *maxLength = length;
        strcpy(longest, current);  // Copy current string to longest
    }
}
