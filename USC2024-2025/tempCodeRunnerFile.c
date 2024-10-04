#include<stdio.h>

int main(){
    int layers, i, j,k,l;
    printf("give the number of layers: ");
    scanf("%d",&layers);

    printf("number 1 \n");

    for(i = 1; i <= layers;i++){
        
        for(j = 0; j < i - 1; j++){
            printf("*");
        }
        printf("%d \n",i);
    }


    printf("\nnumber 2 \n");
    for(i = 1; i <= layers; i++){
        for(j = 1; j <= layers - i; j++){
            printf(" ");
            }
        for(k = 1; k <=  layers - (layers - i) - 1; k++){
            printf("*");
        }
        printf("%d",i);
        
        for(k = 1; k <=  layers - (layers - i) - 1; k++){
            printf("*");
        }
        printf("\n");
    }

    printf("\nnumber 3 \n");
    for(i = 1; i <= layers;i++){    
        for(j = 0; j < i - 1; j++){
            printf("*");
        }
        printf("%d",i);
        for(k = 0; k <= ((layers - i)*2) - 1 ;k++ ){
        printf(" ");
        }
        printf("%d",i);
        for(l = 0; l < layers - ( layers - i)- 1; l++){
            printf("*");
        }
        printf("\n");
    }
    
return 0;

}