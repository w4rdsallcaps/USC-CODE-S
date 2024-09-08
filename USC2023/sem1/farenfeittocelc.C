#include <stdio.h>

int main() {
    float F, C;
    printf("enter your number: ");
    scanf ("%f", &F);
    C = (F-32)*5/9;
    printf("\n%.2f fahrenheit is equals to %.2f celsius", F, C);

    return 0;
    
}

