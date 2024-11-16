/*
============================================================================
FILE : novalKi_LE7_12.c
AUTHOR : Kineth M Noval
DESCRIPTION :  Ask a string and determine how many vowels and consonants.
COPYRIGHT : 07/11/2024
============================================================================
*/
#include <stdio.h>
#include <ctype.h>

int is_vowel(char ch);

int main() {
    char str[100];   
    // Ask for string and receive
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);   

    // Loop through each character in the string
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if the character is an alphabet letter
        if (isalpha(str[i])) {
            // Call the is_vowel function to check if it's a vowel
            if (is_vowel(str[i])) {
                printf("%c is a vowel.\n", str[i]);   // Print if it's a vowel
            } else {
                printf("%c is a consonant.\n", str[i]);   // Print if it's a consonant
            }
        }
    }
    
    return 0;
}

// Function to check if a character is a vowel
int is_vowel(char ch) {   
    ch = tolower(ch);     // Convert to lowercase for easy comparison

    // Check if character is a vowel and return 1 (true) or 0 (false)
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
