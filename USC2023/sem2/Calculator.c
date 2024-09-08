#include <stdio.h>

int main(void) {
    float X,Y,answer;
    char operator[0];
    printf("Enter a number: ");
    scanf("%f",&X);
    printf("Enter another number: ");
    scanf("%f",&Y);
    printf("Enter an operator: ");
    scanf("%s",operator); 
    

    if (operator[0] == '+'){
        answer = X + Y;
        printf("here is the answer %0.2f", answer);
    } else if (operator[0] == '-'){
        answer = X - Y;
        printf("here is the answer %0.2f", answer);
    } else if (operator[0] == '*'){
        answer = X * Y;
        printf("here is the answer %0.2f", answer);
    } else if (operator[0] == '/'){
        answer = X / Y;
        printf("here is the answer %0.2f", answer);
    }
    return 0;
    
}