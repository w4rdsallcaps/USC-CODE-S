#include <stdio.h>

int main() {
    // Declare a character array to store input
    char c[100];
    int i = 0;

    // Prompt user to enter a character
    printf("Enter a character: ");
    scanf("%s", c);

    // Check if the input is more than one character
    while (c[i] != '\0') {
        i++;
    }

    // Check if input is a string (more than one character)
    if (i > 1) {
        printf("You entered a string =%s= INVALID INPUT \n", c);
    }
    // Check if the character is a vowel (both lowercase and uppercase)
    else if (c[0] == 'a' || c[0] == 'e' || c[0] == 'i' || c[0] == 'o' || c[0] == 'u' ||
             c[0] == 'A' || c[0] == 'E' || c[0] == 'I' || c[0] == 'O' || c[0] == 'U') {
        printf("%c is a vowel.\n", c[0]);
    }
    // Check if the character is a consonant (both lowercase and uppercase)
    else if ((c[0] >= 'a' && c[0] <= 'z') || (c[0] >= 'A' && c[0] <= 'Z')) {
        printf("%c is a consonant.\n", c[0]);
    }
    // If it's neither a vowel nor a consonant
    else {
        printf("=%c= is not an alphabetic character INVALID INPUT.\n", c[0]);
    }

    return 0;
}