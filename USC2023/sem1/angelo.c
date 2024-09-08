#include<stdio.h>

int main(){

    int x, y;

    printf("Enter a number: ");
    scanf("%d", &x); /*Inputting number*/

    y = x % 2; /*To calculate the remainder; gives 1 if odd, 0 if even*/

    if (y == 0)
        printf("\n\n%d is an EVEN number :D", x); /*To show that the number is even*/
    else if (!(y == 0)) /*Can also do (y == 1) if you don't wanna put the !*/ 
        printf("\n\n%d is an ODD number :D", x); /*To show that the number is odd*/
    else
        printf("You're gay"); /*- Jon Dela Cruz*//*This line of code is useless*/
    return 0;    
}