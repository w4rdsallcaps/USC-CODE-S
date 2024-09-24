#include<stdio.h>

int main(){
    while(1){
        char operator, result;
        float integer1, integer2, answer; // Fixed variable name

        // Input for operator and numbers
        printf("Pick your operator\n____+____\n____-____\n____*____\n____/____ \n");
        scanf(" %c", &operator);  // Add space before %c to ignore newline

        printf("Give your first integer value: ");
        scanf("%f", &integer1);

        printf("Give your second integer value: ");
        scanf("%f", &integer2);  // Corrected the variable name to 'integer2'

        // Switch case to handle different operators
        switch (operator) {
            case '+':
                answer = integer1 + integer2;
                printf("The SUM between %.2f and %.2f is %.2f\n", integer1, integer2, answer);
                break;
            case '-':
                answer = integer1 - integer2;
                printf("The DIFFERENCE between %.2f and %.2f is %.2f\n", integer1, integer2, answer);
                break;
            case '*':
                answer = integer1 * integer2;
                printf("The PRODUCT between %.2f and %.2f is %.2f\n", integer1, integer2, answer);
                break;
            case '/':
                // Handle division by zero
                if (integer2 != 0) {
                    answer = integer1 / integer2;
                    printf("The QUOTIENT between %.2f and %.2f is %.2f\n", integer1, integer2, answer);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;
            default:
                printf("Error: Invalid operator.\n");
        }

        // Prompt to continue or exit
        printf("\n\n -----End the program?----- \n\n-----(Enter 'n' to continue)-----\n\n---(Enter 'y' to exit application)--- \n ");
        scanf(" %c", &result);  // Added space to ignore newline

        if (result == 'y') {
            break;
        }
        
    }
    
    return 0;
}
