/*
============================================================================
FILE : novalKi_LE5_21.c
AUTHOR : Kineth Noval
DESCRIPTION : The program will ask the user to input
 the number of rows and columns the table should have and display the multiplication table on screen.
Use tab for the spacing between numbers horizontally. Passing grade of 50.

COPYRIGHT : 09/10/2024
============================================================================
*/

#include<stdio.h>
#include<conio.h>
int main(){
int rowlim,collim,row,col;

//ask for rows and colums
printf("Enter a row: ");
scanf("%d", &rowlim);
printf("Enter a column: ");
scanf("%d", &collim);

// coloumn number printing
for (col = 0; col<=collim; col++){
}
//row number printing
for (row = 1; row<=rowlim; row++){
    for (col = 1; col<=collim; col++){
        //display the periodic table
        printf("\t|%d|", col*row);
    }
    //print to the next line
    printf("\n");
//end prorgram
}
return 0;
}
