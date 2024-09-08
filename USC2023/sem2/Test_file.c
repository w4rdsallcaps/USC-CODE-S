#include<stdio.h>
#include<math.h>

float quadratic1(float a, float b, float c);
float quadratic2(float a, float b, float c);
float difference(float a, float b, float c);

int main() {
    float a, b, c, x, y;
    printf("Enter the coefficients of the quadratic equation: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a == 0 && b == 0) {
        printf("There is no solution.");
    }
    else if (a == 0) {
        printf("There is only one root: %f", -c / b);
    }
    else if  (difference(a, b, c)< 0) {
        printf("There is no real roots.");
    }
    else {
        x = quadratic1(a, b, c);
        y = quadratic2(a, b, c);
        printf("The real roots are: %.2f and %.2f", x, y);
    }
}

float quadratic1(float a, float b, float c) {
    return ((b*-1)+sqrt((b*b)-(4*a*c)))/(2*a);
}

float quadratic2(float a, float b, float c) {
    return ((b*-1)-sqrt((b*b)-(4*a*c)))/(2*a);
}

float difference(float a, float b, float c) {
    return (b*b)-(4*a*c);
}
