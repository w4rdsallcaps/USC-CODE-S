#include<stdio.h>

int main(){
    int layers, i, j,k,l;
    printf("give a number between 1 and 9 for number of layers: ");
    scanf("%d",&layers);
    printf("\nnumber 6 \n");
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
    return 0;
    }