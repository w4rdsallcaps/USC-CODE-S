/*
============================================================================
FILE : novalKi_PME4.c
AUTHOR : Kineth M Noval
DESCRIPTION :  Determines the change to be dispenses from a vending machine.
Assume user is smart and enters an amount between 1 cent and 99 cents.
The program determines a combination of coins equal to that amount.
COPYRIGHT : 17/09/2024
============================================================================
*/
#include<stdio.h>

int main(){
    //define
    int userInput,quarter,cent,nickel,penny,dime;
    //display and input
    printf("Input amount of cents between 1 and 99: ");
    scanf("%d",&userInput);
    //computations
    quarter = userInput/25;
    dime = (userInput/10) - ((quarter*25)/10);
    nickel = ((userInput/5) - (((quarter*25)+(dime*10))/5));
    penny = (userInput/1) -  (((quarter*25)+(dime*10)+(nickel*5))/1);
    //display all changes
    printf("quarter: %d\n",quarter);
    printf("dime: %d\n",dime);
    printf("nickel: %d\n",nickel);
    printf("penny: %d\n",penny);
    //break
    return 0;
}
