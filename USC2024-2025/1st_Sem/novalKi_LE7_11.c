/*
============================================================================
FILE : novalKi_LE7_11.c
AUTHOR : Kineth M Noval
DESCRIPTION : Design the logic for a program that allows a user to enter 10 numbers, 
then displays all of the numbers, the largest number, and the smallest.  
COPYRIGHT : 07/11/2024
============================================================================
*/
#include <stdio.h>

void biggest_smallest_finder(float numbers[], float *biggest, float *smallest);

int main() {
    float numbers[10], biggest, smallest;

    printf("Give me a number (1): ");
    scanf("%f", &numbers[0]);

    // Initialize biggest and smallest
    biggest = numbers[0];
    smallest = numbers[0];

    // Call the function to find biggest and smallest
    biggest_smallest_finder(numbers, &biggest, &smallest);
    //print the display
    printf("Biggest: %.1f\nSmallest: %.1f", biggest, smallest);
    return 0;
}

void biggest_smallest_finder(float numbers[], float *biggest, float *smallest) {
    int i;
    for (i = 1; i < 10; i++) {
        // Ask for the remaining numbers
        printf("Give me a number (%d): ", i + 1);
        scanf("%f", &numbers[i]);

        // Update biggest and smallest if necessary
        if (numbers[i] > *biggest) {
            *biggest = numbers[i];
        } else if (numbers[i] < *smallest) {
            *smallest = numbers[i];
        }
    }
}
