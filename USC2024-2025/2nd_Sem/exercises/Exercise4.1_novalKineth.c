#include <stdio.h>
#include <stdbool.h>

#define MAX 10


void bubbleSort(int arr[],int sizeArr);
void printArr(int arr[],int sizeArr);
void swap(int *a,int *b);
void binarySearch(int arr[],int sizeArr,int search);
int binarySearchRecursive(int arr[], int left, int right, int query);

void main () {
    int arr[MAX], i = 0, search;
    
    printf("Give a unsorted array!! ");
    
    for(i = 0; i < MAX ;i++){
        printf("\nIndex:[%d] ",i);
        scanf("%d",&arr[i]);
    }
    
    int sizeArr = sizeof(arr) / sizeof(arr[0]);
    
    printf(" ORIGINAL ARRAY");
    printArr(arr,sizeArr);
    printf("\nbubble sorting!!\n");
    bubbleSort(arr,sizeArr);
    printf("SORTED ARRAY");
    printArr(arr,sizeArr);
    printf("Search Number: ");
    scanf("%d",&search);
    printf("\nBinarySearching!!\n");
    binarySearch(arr,sizeArr,search);

}

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
        printf("\nPass %d:", i +1);
        for(int j = 0; j < sizeArr - i - 1;j++){

            if(arr[j] > arr[j + 1 ]){
                swap(arr + j, arr + j + 1);
                swapped = true;
            }
        }
        printArr(arr,sizeArr); 
        if (swapped == false )
        break;
    }
}

void binarySearch(int arr[], int sizeArr, int query) {

    int result = binarySearchRecursive(arr, 0, sizeArr - 1, query);
    
    if (result != -1) {
        printf("\nFound %d at index %d!\n", query, result);
    } else {
        printf("\nElement %d not found in the array.\n", query);
    }
}


int binarySearchRecursive(int arr[], int left, int right, int query) {
    
    if (left > right) {
        return -1;
    }
    
    printf("Searching in: ");
    for (int i = left; i <= right; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int mid = left + (right - left) / 2;
  
    if (arr[mid] == query) {
        return mid;
    }
    
    
    if (arr[mid] < query) {
        return binarySearchRecursive(arr, mid + 1, right, query);
    }
    
    else {
        return binarySearchRecursive(arr, left, mid - 1, query);
    }
}