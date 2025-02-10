#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int value;
    struct queue* next;
    struct queue* prev;
} queue;

// Function prototypes
queue* createQueue(int value);
void printValue(queue* node);
void freeQueue(queue* node);

int main() {
    queue* test = createQueue(52);
    
    printValue(test);
    printf("\n");
    
    freeQueue(test);
    return 0;
}

queue* createQueue(int value) {
    queue* newNode = malloc(sizeof(queue));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    return newNode;
}

void printValue(queue* node) {
    static int printed = 0;
    
    if (!printed) {
        printf("%d", node->value);
        printed = 1;
    }
}

void freeQueue(queue* node) {
    free(node);
}