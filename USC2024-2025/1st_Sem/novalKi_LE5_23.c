/*
============================================================================
FILE : novalKi_LE5_23.c
AUTHOR : Kineth Noval
DESCRIPTION :  Fibonacci Series. Create a program that will display the 1-N value of the Fibonacci sequence. Use a space for the spacing between numbers horizontally.
COPYRIGHT : 09/10/2024
============================================================================
*/
#include<stdio.h>
#include <stdio.h>

int main() {
    int limit, first = 1, second = 1, next;

    // Ask user to enter the limit
    printf("Enter limit: ");
    scanf("%d", &limit);

    printf("Fibonacci sequence: %d %d", first, second);
    
    // display Fibonacci sequence until the limit is reached
    for (int i = 3; i <= limit; i++) {
        next = first + second;
        printf(" %d", next);
        first = second;
        second = next;
    }
    // print new line 
    printf("\n");
    return 0;
}
