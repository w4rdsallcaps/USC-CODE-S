/*
============================================================================
FILE : novalKi_LE8_11.c
AUTHOR : Kineth M Noval
DESCRIPTION : Write a function that sets up an array called days, 
which contains pointers to the names of the days of the week and return the name 
of the day from the given day. The function accepts the given day.
COPYRIGHT : 07/11/2024
============================================================================
*/

#include<stdio.h>
#include<ctype.h>

//function redeclaring  
int askingDay();
void displayDay(int number);
    
int main(){
    //functions in main 
    int number = askingDay(); //declaring number = return value from func askingDay
    displayDay(number); 
    return 0;
}

int askingDay(){// ask for a day
        int number = 0;

    printf("Enter a Day (between 1-7): ");
    scanf("%d",&number);
    return number;
}

void displayDay(int number){//stores an array of strings in a pointerclass 
        char *days[8] = {"  ","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
        if ( number > 7 || number < 1 ){ //logic for displaying day
        printf("INVALID INPUT");
    }
        else{
            printf("Day of The Week: %s",days[number]);
        }
    
}
