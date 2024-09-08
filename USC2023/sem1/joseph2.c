#include <stdio.h>

int main() {
    int x = 499, y;

    printf("Guess the secret number to win!\nEnter your guess: ");

    while (1) {
        scanf("%d", &y); // Read the guess

        if (y > x) {
            printf("Number too high, try again: ");
        } else if (y < x) {
            printf("Number too low, try again: ");
        } else {
            printf("Congratulations! You've guessed the secret number!\n");
            break; // Exit the loop when the guess is correct
        }
    }

    return 0;
}