/*
============================================================================
FILE : novalKi_LE5_11.c
AUTHOR : Kineth Montaus Noval
DESCRIPTION : Average of Even Numbers and Product of Odd Numbers. Program that will ask 10 integers and display
 the average of all even numbers and the product of all odd numbers entered by the user.

COPYRIGHT : 30/09/2024
============================================================================
*/

#include <stdio.h>

int main() {
    // Variable Declarations
    int number, evenSum = 0, evenCounter = 0, oddProd = 0; 

    // Loop to read 10 integers from the user
    for (int counter = 0; counter < 10; counter++) {
        // Prompt the user to input a number
        printf("Input no. #%d: ", counter + 1);
        scanf("%d", &number);

        // Check if the number is even
        if (number % 2 == 0) {
            evenSum += number;     // Add the even number to evenSum
            evenCounter++;         // Increment the count of even numbers
        } 
        else { // Number is odd
            if (oddProd == 0) {    // Initialize oddProd if it's the first odd number
                oddProd = 1;
            }
            oddProd *= number;     // Multiply the odd number to oddProd
        }
    }

    // Calculate and display results
    if (evenCounter != 0) {
        // Print average of even numbers (sum / count)
        printf("Even Average: %d\n", evenSum / evenCounter);
    } 
    else {
        // No even numbers entered, so average is zero
        printf("Even Average: 0\n");
    }
    
    // Print product of odd numbers
    printf("Odd Product: %d", oddProd);

    return 0;  // Exit the program
}
