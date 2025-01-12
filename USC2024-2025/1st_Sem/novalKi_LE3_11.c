/*
============================================================================
FILE :  novalKi_LE3.11
AUTHOR : Kineth Montaus Noval
DESCRIPTION : Create a program that asks for user’s yearly pay and displays his weekly pay.
COPYRIGHT : 09/05/24
============================================================================
*/

#include<stdio.h>

int main(){
    //variable and constant declaration
    float yearlyPay, WeeklyPay ;
    const float convertionrate = 52.14;
    //display what is your yearly Pay?
    printf("what is your yearly Pay? ");
    //take information
    scanf("%f", &yearlyPay);
    //calculation
    WeeklyPay = yearlyPay/convertionrate;
    //display weekly pay
    printf("This is your yearly pay as a week: %.2f", WeeklyPay);
    //end program
    return 0;
}