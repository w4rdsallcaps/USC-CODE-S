#include<stdio.h>

int main(){
    int layers, i, j,k,l;
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
        for(i = 1;i <= layers; i++){
        for(j = 1 ; j <= layers - i; j++){
            printf(" ");
        }
        for(k = 1; k <= layers - (layers - i) - 1 ;k++){
            printf("*");
        }
        printf("%d",i);
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
            printf("\n");
        }
        printf("\n");

        printf("number 5 \n");
        for(i = layers; i > 0; i--){
            for(k = 0  ; k <= (layers - i) -1 ; k++  ){
            printf(" ");
            }
            for(j = layers; j >= layers - (i - 2) ; j--){
                printf("*");
            }
            printf("%d",i);
            for(j = layers; j >= layers - (i - 2); j -- ){
                printf("*");
            }
            printf("\n");
        }
        //line seperator 
        for(i = 0; i <= (layers*2)-1; i++){
            printf("|");
        }
        printf("\n");
        for(i = 1; i <= layers; i++){
            for(j = 0;j <= (layers - i) - 1;j++ ){
                printf(" ");
            }
            for(k = 0; k <= i  - 2;k++ ){
                    printf("*");
            }
            printf("%d",i);
            
            for(l = 0; l <= i - 2;l++){
                printf("*");
            }
            printf("\n");
        }
        printf("\nnumber 6 \n");
        for(i = layers; i > 0; i--){
            for(j = layers; j > (layers - i) + 1; j--){
                printf("*");
            }
            printf("%d",i);
            for(k = 0; k <=((layers-i)*2)-1 ;k++){
                printf(" ");
            }
            printf("%d",i);
            for(j = layers; j > (layers -i) +1; j--){
                printf("*");
            }
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
            //for loop pritn the * in the other side 
            printf("%d",i);
            for(l = 0; l < layers - ( layers - i)- 1; l++){
                printf("*");
            }
            printf("\n");
        }
        printf("\n");

        printf("\n");
         printf("\nnumber 7 \n");
    for(i = 1; i <= layers; i++){
        for(j = layers - 1 ; j >= i ; j-- ){
            printf("*");
        }
        printf("%d",i);
        for(k = layers; k >= (layers - i*2) + 3; k--){
            printf(" ");
        }
        printf("%d",i);
        for(l = layers - 1;  l >= i ; l-- ){
            printf("*");
        }
        printf("\n");
    } 
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
        printf("\n");
    }
    printf("\n");

    break;
    }
    else{
        printf("please try again \n");
    }
    }while( 0 < layers || layers <= 9);

    return 0;
    }
    
    
