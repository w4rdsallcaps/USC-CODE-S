#include<stdio.h>
int numberEnteries();
void  EnteringArr(int limit,int arr[]);
int *searchTarget(int limit,int arr[]);
void displayIndex(int index);

int main(){
    
    int limit, index;
    int arr[99];
    
    limit = numberEnteries();
    EnteringArr( limit, arr);
    index = searchTarget(limit, arr);
    displayIndex(index);
    return 0;
}


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

int *searchTarget(int limit,int arr[]){
    int target; 
    printf("Search data: ");
    scanf("%d",&target);

    for (int i = 0; i < limit; i ++){
        if (* (arr + i) == target ){
            return i;
        }
    }
    return -1;
}

void displayIndex(int index){
    if(index == -1 ){
        printf("NOT FOUND");
    } 
    else{
        printf("FOUND in index: %d ",index);
    }
}
