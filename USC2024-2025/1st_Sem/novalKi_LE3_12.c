/*
============================================================================
FILE : novalKi_LE3.12
AUTHOR : Kineth Montaus Noval
DESCRIPTION :  a program that extracts and adds the two least significant digits of an integer.
COPYRIGHT : 09/05/24
============================================================================
*/

#include <stdio.h>

int main() {
    //declare all the variables
    int digits, smallestInt1, smallestInt2, sumOfInts;
    //display a question asking for a number
    printf("give me a huge number!! ");
    scanf("%d",&digits);
    //compututations
    smallestInt1=  (digits % 10);
    smallestInt2 = ((digits % 100)-smallestInt1)/10 ;
    sumOfInts = smallestInt1 + smallestInt2;
    //print's the sum of the two smallest integers 
    printf("Sum: %d + %d = %d", smallestInt2,smallestInt1,sumOfInts);
    //End program
    return 0;
}