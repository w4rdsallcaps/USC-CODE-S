/*
============================================================================
FILE : filename.extension
AUTHOR : Kineth Montaus NOval
DESCRIPTION : 
COPYRIGHT : created
REVISION HISTORY
Date: By: Description:
revision date author description of the change
revision date author description of the change
.
.
.
revision date author description of the change
============================================================================
*/
/*
============================================================================
FUNCTION : function name
DESCRIPTION : a program that extracts and adds the two least significant digits of an integer.
ARGUMENTS : (list all parameters pass in the function)
dataType variableName - brief description
dataType variableName - brief description
.
.
.
dataType variableName - brief description
RETURNS : (no return) void
(with return)dataType - brief description
===========================================================================
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