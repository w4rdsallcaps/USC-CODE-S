/*
============================================================================
FILE : novalKi_LE5_21.c
AUTHOR : Kineth Noval
DESCRIPTION : Create a program that would display a pyramid 
COPYRIGHT : 09/10/2024
============================================================================
*/

#include <stdio.h>

int main(){
    int nValue;

    // ask for a nValue
    printf("Enter a value for N: ");
    scanf("%d", &nValue);

    for (int i = 1; i <= nValue; i++){
        //loop for space
        for (int j = 0; j <= nValue - i; j++){
            printf(" ");
        }
        
        //loop for left to middle increasing 
        for (int k = 1; k <= i; k++){
            printf("%d", k);
        }
        //loop for right decending value
        for (int l = i - 1; l >= 1; l--){
            printf("%d", l);
        }

        //new line
        printf("\n");
    }

    return 0;
}