#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 10 

typedef struct{
    // int array[MAX]; static array size
    int* array;
    int capacity;
    int size;
} MaxHeap;


            //for static if ever
// void initHeap(createNewMaxHeap* heap){
//     heap->size = 0;
// }

MaxHeap* createNewMaxHeap(int capacity){
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));  //allocate memory for heap structure 
    heap->capacity = capacity; //Set the max capacity
    heap->size = 0; // will be empty at the start
    heap->array =(int*)malloc(capacity * sizeof(int));  //allocate for the array
    return heap; //return the whole heap
}


void swap(int* a,int* b){//swapping
    int temp = *a;
    *a = *b;
    *b = temp;
}


void insert(MaxHeap* heap, int key){
    if(heap ->size == heap -> capacity){
        printf("HEAP IS FULL");
    }
    int i = heap->size;// make index value equal to size 
    heap->array[i] = key; // make the value of that index be the key
    heap->size++;//up the size brah 

    //Fix the heap property by swapping upward 
    while(i != 0 && heap->array[(i - 1) / 2] < heap->array[i]){
        swap(&heap->array[i],&heap->array[(i-1) / 2]); //swap the parent and child if its bigger or not
        i =(i - 1) /2; // make the index value the parents to escape
    }

}

void printHeap(MaxHeap* heap){
    printf("heap elements:\n ");
    for(int i = 0; i < heap->size;i++){
        printf("[%d]",heap->array[i]);
    }
    printf("\n");
}

void getMax(MaxHeap* heap){
    if(heap->size <= 0){ //if heap is empty return its empty
        printf("heap is empty brah");
        return;
    }

    printf("here is the Max Value: [%d]\n",heap->array[0]);
}

void maxHeapify(MaxHeap* heap,int index){
    int largest = index;  // Assume current node is the largest
    int left = 2 * index +1;  // Left child index
    int right = 2 * index + 2; // Right child index

    if(left < heap->size && heap->array[left] > heap->array[largest]){
        largest = left;
    }
    if(right < heap->size && heap->array[right] > heap->array[largest]){
        largest = right;
    }

    if(largest != index ){
        swap(&heap->array[index],&heap->array[largest]);
        maxHeapify(heap,largest);
    }
    
}

int removeMax(MaxHeap* heap){
    if(heap->size <= 0){ //if heap is empty return its empty
        printf("heap is empty brah\n");
        return INT_MIN;
    }
    int max = heap->array[0];

    printf("Deleting [%d]\n",heap->array[0]);
    printf("removing...\n");

   
    //printf("%d",heap->size);
    
    if(heap->size == 1){
        heap->size--;
        printf("removed.\n");
        return max;
    }

    heap->array[0] = heap->array[--heap->size];

    maxHeapify(heap,0);

    printf("removal complete!\n");
    return max;
}

int main(){
MaxHeap* heap = createNewMaxHeap(10);
    insert(heap, 3);
    printHeap(heap);
     insert(heap, 2);
     printHeap(heap);
     insert(heap, 15);
     printHeap(heap);
     insert(heap, 5);
     printHeap(heap);
     insert(heap, 4);
     printHeap(heap);
     insert(heap, 45);
     printHeap(heap);
    
    getMax(heap);
    
    removeMax(heap);
    printHeap(heap);
    
    free(heap->array);
    free(heap);
}

