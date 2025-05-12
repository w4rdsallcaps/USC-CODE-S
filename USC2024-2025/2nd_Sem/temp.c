#include <stdio.h>
#include <limits.h> // For INT_MIN

#define MAX_CAPACITY 10 // Fixed maximum size

typedef struct {
    int array[MAX_CAPACITY]; // Static array of size 10
    int size; // Current number of elements (0 ≤ size ≤ 10)
} MaxHeap;

// Initialize the heap
void initHeap(MaxHeap* heap) {
    heap->size = 0; // Start empty
}

// Swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Restore heap property from a given index
void maxHeapify(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != index) {
        swap(&heap->array[index], &heap->array[largest]);
        maxHeapify(heap, largest); // Recursively fix the subtree
    }
}

// Insert a new element
void insert(MaxHeap* heap, int key) {
    if (heap->size == MAX_CAPACITY) {
        printf("Heap is full! Cannot insert %d\n", key);
        return;
    }

    // Insert at the end
    int i = heap->size;
    heap->array[i] = key;
    heap->size++;

    // Bubble up
    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2; // Move to parent
    }
}

// Remove and return the maximum element
int extractMax(MaxHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        return INT_MIN;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    int root = heap->array[0]; // Max element
    heap->array[0] = heap->array[heap->size - 1]; // Replace root with last element
    heap->size--;

    maxHeapify(heap, 0); // Restore heap property
    return root;
}

// Get the max element without removing it
int getMax(MaxHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty!\n");
        return INT_MIN;
    }
    return heap->array[0]; // Root is always max
}

// Print the heap
void printHeap(MaxHeap* heap) {
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

// Test the heap
int main() {
    MaxHeap heap;
    initHeap(&heap); // Initialize

    insert(&heap, 5);
    insert(&heap, 10);
    insert(&heap, 3);
    insert(&heap, 15);
    insert(&heap, 7);

    printHeap(&heap); // Output: 15 10 3 5 7

    printf("Max extracted: %d\n", extractMax(&heap)); // Output: 15
    printHeap(&heap); // Output: 10 7 3 5

    printf("Current max: %d\n", getMax(&heap)); // Output: 10

    return 0;
}