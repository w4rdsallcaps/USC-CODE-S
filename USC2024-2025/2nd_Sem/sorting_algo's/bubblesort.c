#include <stdio.h>
#include <stdbool.h>



void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void printArr(int arr[],int sizeArr){
    printf("\n");
    for(int i = 0; i < sizeArr; i++){
        printf("[%d] ",arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[],int sizeArr){

    for(int i = 0; i < sizeArr - 1; i++){
        bool swapped = false; 

        for(int j = 0; j < sizeArr - i - 1;j++){

            if(arr[j] > arr[j + 1 ]){
                swap(arr + j, arr + j + 1);
                printArr(arr,sizeArr);
                swapped = true;
            }
        } 
        if (swapped == false )
        break;
    }
}


void main () {
    int arr[] = {2,5,4,8,9,6,1,0,7,3,10};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    
    printf(" ORIGINAL ARRAY");
    printArr(arr,sizeArr);
    printf("\nbubble sorting!!\n");
    bubbleSort(arr,sizeArr);
    printf("SORTED ARRAY");
    printArr(arr,sizeArr);

}

