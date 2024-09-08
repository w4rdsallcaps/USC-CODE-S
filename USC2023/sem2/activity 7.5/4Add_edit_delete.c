#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void addElement(int arr[], int *size, int element) {
    if (*size < MAX_SIZE) {
        arr[*size] = element;
        (*size)++;
        printf("Element added successfully.\n");
    } else {
        printf("Array is full. Cannot add more elements.\n");
    }
}

void editElement(int arr[], int size, int index, int newValue) {
    if (index >= 0 && index < size) {
        arr[index] = newValue;
        printf("Element at index %d edited successfully.\n", index);
    } else {
        printf("Invalid index. Edit failed.\n");
    }
}

void deleteElement(int arr[], int *size, int index) {
    if (index >= 0 && index < *size) {
        for (int i = index; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element at index %d deleted successfully.\n", index);
    } else {
        printf("Invalid index. Delete failed.\n");
    }
}

int main() {
    int array[MAX_SIZE];
    int size = 0;
    int choice, index, newValue;

    do {
        printf("\nMenu:\n");
        printf("1. Add element\n");
        printf("2. Edit element\n");
        printf("3. Delete element\n");
        printf("4. Display array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add: ");
                int elementToAdd;
                scanf("%d", &elementToAdd);
                addElement(array, &size, elementToAdd);
                break;

            case 2:
                printf("Enter the index to edit: ");
                scanf("%d", &index);
                printf("Enter the new value: ");
                scanf("%d", &newValue);
                editElement(array, size, index, newValue);
                break;

            case 3:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                deleteElement(array, &size, index);
                break;

            case 4:
                displayArray(array, size);
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
