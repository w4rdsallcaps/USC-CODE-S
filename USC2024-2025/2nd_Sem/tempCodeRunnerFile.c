#include <stdio.h>
#include <windows.h> 

// Swap function with visualization
void swap(int *a, int *b){
    Sleep(1000);
    printf("Swapping %d and %d\n", *a, *b);  // Print swap details
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int pivotfinder(int arr[], int lowest, int highest){
    int pivot = arr[highest];  // Choosing the last element as pivot
    int i = lowest - 1;

    printf("\nStarting partition with pivot = %d\n", pivot);

    for(int j = lowest; j < highest; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);  // Move smaller elements to the left
        }
    }
    swap(&arr[i + 1], &arr[highest]);  // Place pivot in the correct position

    printf("Array after partition: ");
    for(int k = lowest; k <= highest; k++){
        printf("%d ", arr[k]);
        
    }
    printf("\n");
    Sleep(1000);
    return i + 1;
}

// QuickSort function
void quicksort(int arr[], int lowest, int highest){
    if (lowest < highest){
        int pivot = pivotfinder(arr, lowest, highest);

        quicksort(arr, lowest, pivot - 1);  // Sort left part
        quicksort(arr, pivot + 1, highest); // Sort right part
    }
}

// Function to print array
void printarr(int size, int arr[]){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main(){
    int arr[] = {23, 91, 47, 15, 88, 34, 6, 72, 55, 39, 18, 64, 98, 11, 45, 79, 2, 33, 87, 50, 29, 67, 81, 
        95, 12, 74, 3, 58, 42, 20, 99, 8, 66, 31, 14, 56, 22, 93, 85, 4, 25, 60, 9, 70, 44, 32, 97, 77, 1, 48};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printarr(size, arr);
    
    printf("\nSorting process:\n");
    quicksort(arr, 0, size - 1);

    printf("\nSorted array: ");
    printarr(size, arr);

    return 0;
}
