/*
============================================================================
FILE : novalKi_LE5_12.c
AUTHOR : Kineth Montaus Noval
DESCRIPTION :   Program that will ask the correct numeric passcode before the user can continue his task.
 The user is given only three trials to enter the correct passcode. When the user hit the correct passcode the program will display “ACCESS GRANTED”, 
 otherwise it will display “ACCESS DENIED” after three attempts.
COPYRIGHT : 30/09/2024
============================================================================
*/
#include<stdio.h>

int main(){
    int password = 12345, userInput, counter = 3;
    printf("Enter your password: ");
    scanf("%d",userInput);
    do {
        if(password == userInput){
        printf("RAWR YOU GOT IN!!!!!!!!!!!");
        return 0;
    }
    else{
        printf("WRONG ANSWER DO IT AGAIN: ");
        scanf("%d",&userInput);
        counter--;   
        if (counter == 0 && password != userInput  ){
            printf("RAWR I WONT LET YOU IN!!!!!!!!!!!!!!!");
        } 
        if(password == userInput){
            printf("RAWR YOU GOT IN!!!!!!!!!!!");
        return 0;
        }      
    } 
    } while(counter > 0 );
    return 0;
}