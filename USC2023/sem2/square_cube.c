#include <stdio.h>

int main() {
    int X, square, cubes; 
    printf("give me a number: ");
    scanf("%d", &X);
    square = X * X;
    cubes = X * X * X;
    printf("the square of the number is: %d\n", square);
    printf("the cube of the number is: %d\n", cubes);

    return 0;

}
