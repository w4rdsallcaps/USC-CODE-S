#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;  // Store the value at pointer a in temp
    *a = *b;        // Assign the value at pointer b to pointer a
    *b = temp;      // Assign the value in temp to pointer b
}

int main() {
    int x = 5, y = 10;
    printf("Before swapping: x = %d, y = %d\n", x, y);

    swap(&x, &y);  // Pass the addresses of x and y to the function

    printf("After swapping: x = %d, y = %d\n", x, y);
    return 0;
}
