#include <stdio.h>

void practiceOne(){
    int numbers[5] = {3, 5, 7, 8, 90};
    int *ptr;

    printf("Original array elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    ptr = numbers; 

    for (int i = 0; i < 5; i++) {
        *(ptr + i) *= 10;
    }

    printf("\nArray elements after multiplying by 10:\n");
    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
}

void practiceTwo(){
    char str[13] = "Hello World!";
    char *char_ptr = str; 

    printf("\nCharacters and their memory addresses:\n");
    while (*char_ptr != '\0') {
        printf("Character: '%c', Memory Address: %p\n", *char_ptr, (void *)char_ptr);
        char_ptr++;
    }
}

void addNumbers(int *a, int *b, int *sum) {
    *sum = *a + *b; 
    }

void practiceFour(){
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("The values of the 2D array are:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);  
        }
        printf("\n");  
    }
}

void practiceFive(){
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;  

    printf("Original array values:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));  
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        *(ptr + i) += 100;  
    }

    printf("Updated array values after adding 100:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));  
    }
    printf("\n");
}

int main() {
    int choice;

    // Display the menu to the user
    printf("Select a function to execute:\n");
    printf("1. Practice One\n");
    printf("2. Practice Two\n");
    printf("3. Practice Three\n");
    printf("4. Practice Four\n");
    printf("5. Practice Five\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            practiceOne();
            break;
        case 2:
            practiceTwo();
            break;
        case 3: {
            int num1, num2, result;
            printf("Input the first number: ");
            scanf("%d", &num1);
            printf("Input the second number: ");
            scanf("%d", &num2);
            addNumbers(&num1, &num2, &result);
            printf("The sum of %d and %d is %d\n", num1, num2, result);
            break;
        }
        case 4:
            practiceFour();
            break;
        case 5:
            practiceFive();
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
    }

    return 0;
}
