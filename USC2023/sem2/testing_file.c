#include <stdio.h>

int main(void) {
    float X, Y, answer;
    char operator[2];
    printf("Enter a number: ");
    scanf("%f", &X);
    printf("Enter another number: ");
    scanf("%f", &Y);
    printf("Enter an operator: ");
    scanf("%s", operator);

    if (operator[0] == '+') {
        answer = X + Y;
        printf("The answer is %2.f\n", answer);
    } else if (operator[0] == '-') {
        answer = X - Y;
        printf("The answer is %2.f\n", answer);
    } else if (operator[0] == '*') {
        answer = X * Y;
        printf("The answer is %2.f\n", answer);
    } else if (operator[0] == '/') {       
            answer = X / Y;
            printf("The answer is %2.f\n", answer);
      
    }

    return 0;
}
