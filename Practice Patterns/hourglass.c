#include<stdio.h>
#include<stdlib.h>

int main()
{
    int column, nth, row;

    printf("Enter value of N: ");
    scanf("%d", &nth);
    printf("\n");

    //Loop for a Hourglass pattern: Upper Portion
    for(row = 1; row <= nth; row++)
    {
        //First Half: Upper Portion
        for(column = 1; column <= nth; column++)
        {
            if(column >= row)
            {
                printf("*");
            }

            else
            {
                printf(" ");
            }
        }
        //Second Half: Upper Portion
        for(column = nth - 1; column >= 1; column--)
        {            
            if(column >= row)
            {
                printf("*");
            }

            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
    //Loop for a Hourglass pattern: Lower Portion
    for(row = 2; row <= nth; row++)
    {
        //First Half: Lower Portion
        for(column = nth; column >= 2; column--)
        {
            if(column <= row)
            {
                printf("*");
            }

            else
            {
                printf(" ");
            }
        }
        //Second Half: Lower Portion
        for(column = 1; column <= nth; column++)
        {            
            if(column <= row)
            {
                printf("*");
            }

            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    putchar('\n');
    system("Pause");
    return 0;
}