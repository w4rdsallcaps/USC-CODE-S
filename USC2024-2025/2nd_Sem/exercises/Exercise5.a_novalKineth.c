#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 1000

void push(int stack[], int *size, int n);
int pop(int stack[], int *size);
void printInstructions();
void printExamples();

int main()
{
    int stack[MAX_STACK_SIZE], size = 0, value1 = 0, value2 = 0, result = 0;
    char input[MAX_EXPR_SIZE];

    printInstructions();

    while (1)
    {
        printf("Enter a number (0-9) or operator (+ - * /) or command: ");
        scanf(" %s", input);
        if (strcmp(input, "exit") == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }
        if (strcmp(input, "example") == 0 || strcmp(input, "examples") == 0) {
            printExamples();
            continue;
        }
        if (strcmp(input, "stack") == 0) {
            printf("Current stack (top to bottom): ");
            for (int i = 0; i < size; i++) {
                printf("%d ", stack[i]);
            }
            printf("\n");
            continue;
        }
        if (strcmp(input, "pop") == 0) {
            if (size > 0) {
                int popped = pop(stack, &size);
                printf("Popped %d from the stack.\n", popped);
            } else {
                printf("Cannot pop: Stack is empty.\n");
            }
            continue;
        }
        if (strcmp(input, "clear") == 0) {
            size = 0;
            printf("Stack cleared.\n");
            continue;
        }

        char temp_c = input[0];

        if (isdigit(temp_c))
        {
            push(stack, &size, temp_c - '0');
            printf("Pushed %c onto the stack.\n", temp_c);
            continue;
        }
        if (temp_c == '+' || temp_c == '-' || temp_c == '*' || temp_c == '/')
        {
            if (size < 2) 
            {
                printf("Error: Not enough operands for operation '%c'\n", temp_c);
                continue;
            }

            value2 = pop(stack, &size);
            value1 = pop(stack, &size);

            switch (temp_c)
            {
                case '+': 
                    result = value1 + value2; 
                    printf("Operation: %d + %d = %d\n", value1, value2, result);
                    break;
                case '-': 
                    result = value1 - value2; 
                    printf("Operation: %d - %d = %d\n", value1, value2, result);
                    break;
                case '*': 
                    result = value1 * value2; 
                    printf("Operation: %d * %d = %d\n", value1, value2, result);
                    break;
                case '/':
                    {
                        if (value2 == 0) {
                            printf("Error: Division by zero\n");
                            push(stack, &size, value1);
                            push(stack, &size, value2);
                            continue;
                        }
                        result = value1 / value2;
                        printf("Operation: %d / %d = %d\n", value1, value2, result);
                        break;
                    }
            }

            push(stack, &size, result);
            printf("Result %d pushed onto the stack.\n", result);
        }
        else if (!isdigit(temp_c) && strcmp(input, "exit") != 0 && 
                 strcmp(input, "example") != 0 && strcmp(input, "stack") != 0 &&
                 strcmp(input, "clear") != 0 && strcmp(input, "pop") != 0) {
            printf("Invalid input: '%s'. Please enter a digit, operator, or command.\n", input);
        }
    }

    if (size == 1) 
        printf("Final result: %d\n", stack[0]);
    else if (size > 1) {
        printf("Warning: Multiple values remain on the stack. Top value: %d\n", stack[0]);
        printf("All values (top to bottom): ");
        for (int i = 0; i < size; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
    else
        printf("Stack is empty. No result.\n");

    return 0;
}

void push(int stack[], int *size, int n)
{
    if (*size >= MAX_STACK_SIZE) {
        printf("Stack overflow: Cannot push more elements.\n");
        return;
    }
    for (int i = *size; i > 0; i--) 
        stack[i] = stack[i - 1];
    stack[0] = n;
    (*size) += 1;
}

int pop(int stack[], int *size)
{
    if (*size == 0) {
        printf("Stack underflow: Cannot pop from empty stack.\n");
        return -1;
    }
    int top = stack[0];

    for (int i = 0; i < *size - 1; i++) 
        stack[i] = stack[i + 1];

    (*size) -= 1;

    return top;
}

void printInstructions() {
    printf("\n=======================================================\n");
    printf("         INTERACTIVE POSTFIX CALCULATOR            \n");
    printf("=======================================================\n");
    printf("Instructions:\n");
    printf("- Enter single digits (0-9) to push them onto the stack\n");
    printf("- Enter operators (+, -, *, /) to perform operations\n");
    printf("- Available commands:\n");
    printf("  'exit'     - Exit the program\n");
    printf("  'example'  - Show example postfix calculations\n");
    printf("  'stack'    - View the current contents of the stack\n");
    printf("  'pop'      - Remove the top element from the stack\n");
    printf("  'clear'    - Clear the stack\n");
    printf("=======================================================\n\n");
}

void printExamples() {
    printf("\nPostfix Calculation Examples:\n");
    printf("For the expression (5+7)*(6+7) in postfix notation: 57+67+*\n");
    printf("Step by step:\n");
    printf("1. Push 5, Push 7           Stack: [7, 5]\n");
    printf("2. Apply +                  Stack: [12]\n");
    printf("3. Push 6, Push 7           Stack: [7, 6, 12]\n");
    printf("4. Apply +                  Stack: [13, 12]\n");
    printf("5. Apply *                  Stack: [156]\n");
    printf("Final result: 156\n\n");
    
    printf("For the expression 2+3*4 in postfix notation: 234*+\n");
    printf("Step by step:\n");
    printf("1. Push 2                   Stack: [2]\n");
    printf("2. Push 3                   Stack: [3, 2]\n");
    printf("3. Push 4                   Stack: [4, 3, 2]\n");
    printf("4. Apply * (3*4)            Stack: [12, 2]\n");
    printf("5. Apply + (2+12)           Stack: [14]\n");
    printf("Final result: 14\n\n");
}