
#include<stdio.h>
    int numberEnteries(){
    int limit;
    printf("Enter number of entries: ");
    scanf("%d", &limit);
    return limit;
}

void  EnteringArr(int limit,int arr[]){
    for (int i = 0; i < limit ; i++){
        printf("Enter number: ");
        scanf ("%d",&arr[i]);
    }
}

void findingLargest(int limit,int arr[]){
    int *largest = arr[0];

    for(int i = 1; i < limit; i ++){
        if (largest < arr[i]){
            largest = arr[i]; 
        }
    }
    printf("Maximum Number: %d",largest);
}

int main(){
    int limit, arr[99];
    limit = numberEnteries();
    EnteringArr( limit, arr);
    findingLargest(limit,arr);
    return 0;
}