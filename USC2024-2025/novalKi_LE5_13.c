/*
============================================================================
FILE : novalKi_LE5_12.c
AUTHOR : Kineth Montaus Noval
DESCRIPTION : Create a program that lets the user choose an operation (power problem solver, 
factorial problem solver, or finding roots for quadratic equations using quadratic formula) from the menu.
 The program will always go back to the menu and lets the user choose again an operation until the user would like to quit using the app.
COPYRIGHT : 30/09/2024
============================================================================
*/

#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    char exit_choice;
        do {
        // Display menu options to the user
        printf("Choose the type of computation you want:\n");
        printf("1. Power Problem Solver\n");
        printf("2. Factorial Problem Solver\n");
        printf("3. Quadratic Equation Solver\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        // Execute based on user's choice
        switch(choice) {
            case 1: { // Power Problem Solver
                double base;
                int exponent;
                double power_result;
                
                // Get base and exponent from user
                printf("Enter the base: ");
                scanf("%lf", &base);
                printf("Enter the exponent: ");
                scanf("%d", &exponent);
                
                // Calculate and display power result
                power_result = pow(base, exponent);
                printf("%.2lf raised to the power of %d is %.2lf\n", base, exponent, power_result);
                break;
            }
            
            case 2: { // Factorial Problem Solver
                int number;
                unsigned long long factorial = 1;
                
                // Get the number from user
                printf("Enter a non-negative integer: ");
                scanf("%d", &number);
                
                // Check for negative input and calculate factorial if valid
                if (number < 0) {
                    printf("Factorial is not defined for negative numbers!\n");
                } else {
                    for (int i = 1; i <= number; ++i) {
                        factorial *= i;
                    }
                    printf("Factorial of %d is %llu\n", number, factorial);
                }
                break;
            }
            
            case 3: { // Quadratic Equation Solver
                double a, b, c, discriminant, root1, root2;
                
                // Get coefficients a, b, and c from user
                printf("Enter coefficients a, b, and c (for equation ax^2 + bx + c = 0):\n");
                printf("a: ");
                scanf("%lf", &a);
                printf("b: ");
                scanf("%lf", &b);
                printf("c: ");
                scanf("%lf", &c);
                
                // Handle special cases and solve the equation
                if (a == 0 && b == 0) {
                    printf("No solution exists.\n");
                } else if (a == 0) {
                    root1 = -c / b;  // Linear equation solution
                    printf("There is one root: %.2lf\n", root1);
                } else {
                    discriminant = b * b - 4 * a * c;  // Calculate discriminant

                    if (discriminant < 0) {
                        printf("No real roots exist.\n");
                    } else if (discriminant == 0) {
                        root1 = -b / (2 * a);  // One root (double root)
                        printf("There is one root: %.2lf\n", root1);
                    } else {
                        root1 = (-b + sqrt(discriminant)) / (2 * a);  // Two distinct roots
                        root2 = (-b - sqrt(discriminant)) / (2 * a);
                        printf("There are two roots: %.2lf and %.2lf\n", root1, root2);
                    }
                }
                break;
            }
            
            default:
                // Handle invalid menu option
                printf("Invalid choice. Please choose between 1, 2, or 3.\n");
        }

        // Ask if the user wants to continue or exit
        printf("\n\n----- End the program? -----\n");
        printf("-----(Enter 'n' to continue)-----\n");
        printf("-----(Enter 'y' to exit application)-----\n");
        scanf(" %c", &exit_choice);  // Added space to ignore newline characters

    } while (exit_choice != 'y');  // Repeat until user chooses to exit

    return 0;
}
