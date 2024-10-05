#include<stdio.h>
#include<stdlib.h>

int main()
{
    int column, i, nth, row;
    i = 0;

    printf("Enter value of N: ");
    scanf("%d", &nth);
    printf("\n");

    //Loop for Floyd pattern: Upper Portion
    for(row = 1; row <= nth; row++)
    {

        for(column = 1; column <= nth; column++)
        {
            if(column <= row)
            {
                i = i + 1;
                printf("%d\t", i);
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