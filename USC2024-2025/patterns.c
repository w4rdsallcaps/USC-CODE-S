/*
============================================================================
FILE : para�aqueRenz_Patterns.c
AUTHOR : Renz Joseph P. Para�aque
DESCRIPTION : Assignment: Patterns 1-5
COPYRIGHT : Renz Joseph P. Para�aque
REVISION HISTORY
Date: 10.03.2024 Time: 10:11 P.M.
============================================================================
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<unistd.h>
//Global Function Declaration
void patternOne(int nth);
void patternTwo(int nth);
void patternThree(int nth);
void patternFour(int nth);
void patternFive(int nth);

int main()
{
    int nth;
    //Ask user Input
    printf("Enter limit for house up to 9: ");
    scanf("%d", &nth);
     //Error output if input is more than 9 or less than 1
    if(nth < 1 || nth > 9)
    {
        printf("\nNot a valid option!");
        sleep(5);
        system("CLS");
        return main();
    }

    putchar('\n');
    //Local Function for Pattern 1
    patternOne(nth);
    putchar('\n');
    //Local Function for Pattern 2
    patternTwo(nth);
    putchar('\n');
    //Local Function for Pattern 3
    patternThree(nth);
    putchar('\n');
    //Local Function for Pattern 4
    patternFour(nth);
    putchar('\n');
    //Local Function for Pattern 5
    patternFive(nth);
    putchar('\n');

    return 0;
}

void patternOne(int nth)
{
    //Printf Pattern 1 output
    for(int row = 1; row <= nth; row++)
    {
        for(int column = 1; column <= row ; column++)
        {
            if (column < row)
            {
                printf("*");
            }

            else
            {
                printf("%d", column);
            }
        }

        printf("\n");
    }
}

void patternTwo(int nth)
{
    //Printf Pattern 2 output
    for(int row = 1; row <= nth; row++)
    {
        //Print Blank space
        for(int column = 1; column <= nth - row ; column++)
        {
            printf(" ");
        }
        //Print center numbers
        for(int column = 1; column <= row; column++)
        {
            if(column < row || column > row)
            {
                printf("*");
            }
            else
            {
                printf("%d", column);
            }
        }
        //Print asterisk for decreasing numbers
        for(int column = row; column > 1; column)
        {
            column = column - 1;

            if(column < row || column > row)
            {
                printf("*");
            }
        }

        printf("\n");
    }
}

void patternThree(int nth)
{
    //Print Pattern 3 Output
    for(int row = 1; row <= nth; row++)
    {

        for(int column = nth; column >= row ; --column)
        {
            if(column > row)
            {
                printf(" ");
            }

            else
            {
                printf("%d", column);
            }
        }

        for(int column = 1; column < row; column++)
        {
            printf("*");
        }

        printf("\n");
    }
}

void patternFour(int nth)
{
    //Print Pattern 4 output
    for(int row = 1; row <= nth; row++)
    {

        for(int column = 1; column <= nth ; column++)
        {
            if(column < row)
            {
                printf("*");
            }

            else if(column > row)
            {
                printf(" ");
            }

            else
            {
                printf("%d", column);
            }
        }

        for(int column = nth; column >= row; column--)
        {
            if(column > row)
            {
                printf(" ");
            }

            else
            {
              printf("%d", column);
            }
        }

        for(int column = 1 ; column < row ; column++)
        {
            printf("*");
        }

        printf("\n");
    }
}

void patternFive(int nth)
{
    //Pattern 5 Output: First Half
    for(int row = 1; row <= nth; row++)
    {

        for(int column = nth; column >= 1 ; column--)
        {
            if(column > row)
            {
                printf("*");
            }

            else if(column == row)
            {
                printf("%d", column);
            }

            else
            {
                printf(" ");
            }
            
        }
        //Second Half
        for (int column = 1; column <= nth; column++) 
        {
            if(column == row)
            {
                printf("%d", column);
            }
            
            else if (column < row)
            {
                printf (" ");
            }

            else
            {
                printf ("*");
            }
         }
        
        printf("\n");
    }
}