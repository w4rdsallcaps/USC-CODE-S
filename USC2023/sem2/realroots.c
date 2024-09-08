#include <stdio.h>
#include <math.h>

// Function declarations
float quadratic1(float a, float b, float c);
float quadratic2(float a, float b, float c);
float quadratic3(float a, float b, float c);
// Main code
int main() {
    float a, b, c, x, y;
    char result;
    while (1) {
    printf("Enter the coefficients of the quadratic equation: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a == 0 && b == 0) {
        printf("There are no solutions :(\n");
    } else if (a == 0) {
        printf("There is only one root: %f\n", -c / b);
    } else {
        float discriminant = quadratic3(a, b, c);

        if (discriminant < 0) {
            printf("There are no real roots :(\n");
        } else {
            x = quadratic1(a, b, c);
            y = quadratic2(a, b, c);
            printf("The real roots are: %.2f and %.2f\n", x, y);
        }
    }
        printf("\n\n -----end the progam?----- \n\n-----(enter n to continue)-----\n\n---(enter y to exit application)--- \n ");
        scanf(" %c", &result);
        if (result == 'y') {
            break;
        }
    }
}

// Function definitions
float quadratic1(float a, float b, float c) {
    return (-b + sqrt(quadratic3(a, b, c)) / (2 * a));
}

float quadratic2(float a, float b, float c) {
    return (-b - sqrt(quadratic3(a, b, c)) / (2 * a));
}

float quadratic3(float a, float b, float c) {
    return (b * b - 4 * a * c);
}
