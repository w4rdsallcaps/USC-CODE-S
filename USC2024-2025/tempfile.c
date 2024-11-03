#include <stdio.h>

int main () {

    int i,j, k;

    // prints middle numbers
    for (i=1; i <= 5; i++)
    {
        //prints spaces form the left
        for (j = 1; j <= 5 - i; j++)
        {
            printf (" ");
        }
        //prints the asteriks to form the shape of the pyramid
        for (k = 1; k <= i - 1; k++)
        {
            printf ("*");
        }
        printf ("%d", i);

        printf ("\n");
    }
    return 0;
}