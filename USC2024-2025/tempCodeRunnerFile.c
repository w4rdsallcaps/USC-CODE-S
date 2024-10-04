#include<stdio.h>

int main(){
    int layers, i, j,k,l;
    //do wile loop for number if between 0 and equals to 9 if not then asks again
    do{
    printf("give a number between 1 and 9 for number of layers: ");
    scanf("%d",&layers);
    if(0 < layers && layers <= 9){
        
        printf("\nnumber 1 \n");
        //for loop to display the numbers
        for(i = 1; i <= layers;i++){
            //for loop to print * ( print a * for ever counter - 1)
            for(j = 0; j < i - 1; j++){
                printf("*");
            }
            //print the counter and go to the next line 
            printf("%d \n",i);
        }
        printf("\nnumber 2 \n");
        //for loop to display the numbers 
        for(i = 1;i <= layers; i++){
        //for loop to display the spaces (print the same amount of spaces as layers - current count )
        for(j = 1 ; j <= layers - i; j++){
            printf(" ");
        //for loop to display * (  layers - (layers - i) - 1 )
        }
        for(k = 1; k <= layers - (layers - i) - 1 ;k++){
            printf("*");
        }
        //display numbers
        printf("%d",i);
        // to the next line
        printf("\n");
    }
        printf("\nnumber 3 \n");
        //for loop to make the counter
        for(i = 1; i <= layers; i++){
            //for loop to print spaces making it go to the spaces ( print the same amount of spaces as layers);
            for(j = 1; j <= layers - i; j++){
                printf(" ");
                }
            //for loop to print * (print * for every (layers - (layers - every counter)) - 1 )
            for(k = 1; k <=  layers - (layers - i) - 1; k++){
                printf("*");
            }
            //display the numbers
            printf("%d",i);
            //display the * again same process lang 
            for(k = 1; k <=  layers - (layers - i) - 1; k++){
                printf("*");
            }
            //to the next line
            printf("\n");
        }

        printf("\nnumber 4 \n");
        //for loop to make the counter
        for(i = 1; i <= layers;i++){
            //for loop to print * in the left(print counter - 1);      
            for(j = 0; j < i - 1; j++){
                printf("*");
            } 
            //print the counter
            printf("%d",i);
            //for loop to print the spaces between two numbers( ((layers - counter)*2) -1)
            for(k = 0; k <= ((layers - i)*2) - 1 ;k++ ){
            printf(" ");
            }
            //for loop pritn the * in the other side 
            printf("%d",i);
            for(l = 0; l < layers - ( layers - i)- 1; l++){
                printf("*");
            }
            // print to the next line
            printf("\n");
        }
        
        printf("\nnumber 5 \n");
        //for loop for the count 
        for(i = layers; i > 0; i--){
            // for loop for the left side spaces ((layers - i) -1)
            for(k = 0  ; k <= (layers - i) -1 ; k++  ){
            printf(" ");
            }
            //for loop to print the left side * 
            for(j = 0; j < i - 1  ; j++){
                printf("*");
            }
            //print numbers
            printf("%d",i);
            //print ride side spaces
            for(j = 0; j <  i - 1 ; j++){
                printf("*");
            }
            // end 
            printf("\n");
        }
        //for loop, bottom triangle counter 
        for(i = 1; i <= layers; i++){
            //display spaces 
            for(j = 0;j <= layers - i - 1 ;j++ ){
                printf(" ");
            }
            //display * 
            for(k = 0; k <= i  - 2;k++ ){
                    printf("*");
            }
            //display numbers
            printf("%d",i);
            //display * same as the first * loop
            for(l = 0; l <= i - 2;l++){
                printf("*");
            }
            //move to the next loop
            printf("\n");

        }
        printf("\nnumber 6 \n");
        //print the numbers starting the number of layers going down to 1 
        for(i = layers; i > 0; i--){
            // display the * left side 
            for(j = 0; j <  i - 1; j++){
                printf("*");
            }
            //display the spaces in the center
            printf("%d",i);
            for(k = 0; k <=((layers-i)*2)-1 ;k++){
                printf(" ");
            }
            //display the * right side
            printf("%d",i);
            for(j = 0; j < i - 1; j++){
                printf("*");
            }
            //move to the next line
            printf("\n");
        } 

        //for loop to make the buttom counter
        for(i = 1; i <= layers;i++){
            //for loop to print * in the left(print counter - 1);      
            for(j = 0; j < i - 1; j++){
                printf("*");
            } 
            //print the counter
            printf("%d",i);
            //for loop to print the spaces between two numbers( ((layers - counter)*2) -1)
            for(k = 0; k <= ((layers - i)*2) - 1 ;k++ ){
            printf(" ");
            }
            //display the counter
            printf("%d",i);
            //for loop pritn the * in the other side 
            for(l = 0; l < layers - ( layers - i)- 1; l++){
                printf("*");
            }
            //next line
            printf("\n");
        }
         printf("\nnumber 7 \n");
         //for loop for counter starting from 1 to layers top
    for(i = 1; i <= layers; i++){
        //display * left side
        for(j = 0 ; j < layers - i ; j++ ){
            printf("*");
        }
        //display the spaces in between
        printf("%d",i);
            for(k = 0; k < (i-1)*2 ; k++){
                printf(" ");
            }
        //display the * to the right
        printf("%d",i);
        for(l = 0 ;  l < layers - i ; l++ ){
            printf("*");
        }
        // to the next line
        printf("\n");
    } 
        //for loop to make the counter
    for(i = 1; i <= layers;i++){
        //for loop to print * in the left(print counter - 1);      
        for(j = 0; j < i - 1; j++){
            printf("*");
        } 
        //display the counter
        printf("%d",i);
        //for loop to display the spaces between two numbers( ((layers - counter)*2) -1)
        for(k = 0; k <= ((layers - i)*2) - 1 ;k++ ){
        printf(" ");
        }
        //for loop display the * in the right side
        printf("%d",i);
        for(l = 0; l < layers - ( layers - i)- 1; l++){
            printf("*");
        }
        // to the next line
        printf("\n");
    }
    printf("\n");
    //ends if statement
    break;

    }
    //if not between 0 and equals to 9 ask user this
    else{
        printf("please try again \n");
    }
    //return user to start if condition not met
    }while( 0 < layers || layers <= 9);
    
    //end code
    return 0;
    }