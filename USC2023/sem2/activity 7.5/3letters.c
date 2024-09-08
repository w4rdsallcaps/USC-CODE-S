#include <stdio.h>

#define MAX_SIZE 100

void sortAlphabetically(char arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    char letters[MAX_SIZE];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1; 
    }
    printf("Enter the array of letters (without spaces): ");
    for (int i = 0; i < size; i++) {
        scanf(" %c", &letters[i]);  
    }
    sortAlphabetically(letters, size);
    printf("\nArray in alphabetical order: ");
    for (int i = 0; i < size; i++) {
        printf("%c ", letters[i]);
    }
    printf("\n");

    return 0;
}
