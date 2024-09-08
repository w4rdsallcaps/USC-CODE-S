#include<stdio.h>

int main()
{
int y = 500, x;
printf("Input the secret number to win the game.\n\n");

printf("Secret Number:");
scanf("%d", x);

if (x == y)
printf("Congratulations! You've won the game!\n\n");

else if (x > y)
printf("Your Secret Number is too high! :( \n\n");

else if (x < y)
printf("Your Secret Number is too low! :( \n\n");

    return 0;
}