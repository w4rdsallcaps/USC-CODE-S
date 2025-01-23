#include<stdio.h>

int main (void){
    float numberOne = 0,numberTwo = 0;
    char operator,choice;
    while(1){
        printf("Enter the first & Sercond number:");
        scanf("%f %f",&numberOne,&numberTwo);
        printf("What operator do you want to use?\nsubtract(-)\nadd(+)\nmultiply(*)\ndivide(/):");
        scanf(" %c",&operator);

        printf("the equation you made is the following [%.2f %c %.2f = ]",numberOne,operator,numberTwo);
        printf("\nDo you want to compute? (y/n):");
        scanf(" %c",&choice);

        if (choice == 'n'){
            break;
        }
        else if (choice == 'y'){
            ;
        }
        else{
            printf("Invalid input");
        }   
    }
    
    return 0;
}