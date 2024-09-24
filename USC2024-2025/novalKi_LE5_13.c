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

        // Variables for calculations
        switch(choice) {
            case 1: { // Power Problem Solver
                double base;
                int exponent;
                double power_result;
                
                printf("Enter the base: ");
                scanf("%lf", &base);
                printf("Enter the exponent: ");
                scanf("%d", &exponent);
                
                power_result = pow(base, exponent);
                printf("%.2lf raised to the power of %d is %.2lf\n", base, exponent, power_result);
                break;
            }
            
            case 2: { // Factorial Problem Solver
                int number;
                unsigned long long factorial = 1;
                
                printf("Enter a non-negative integer: ");
                scanf("%d", &number);
                
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
                
                printf("Enter coefficients a, b, and c (for equation ax^2 + bx + c = 0):\n");
                printf("a: ");
                scanf("%lf", &a);
                printf("b: ");
                scanf("%lf", &b);
                printf("c: ");
                scanf("%lf", &c);
                
                if (a == 0 && b == 0) {
                    printf("No solution exists.\n");
                } else if (a == 0) {
                    root1 = -c / b;
                    printf("There is one root: %.2lf\n", root1);
                } else {
                    discriminant = b * b - 4 * a * c;

                    if (discriminant < 0) {
                        printf("No real roots exist.\n");
                    } else if (discriminant == 0) {
                        root1 = -b / (2 * a);
                        printf("There is one root: %.2lf\n", root1);
                    } else {
                        root1 = (-b + sqrt(discriminant)) / (2 * a);
                        root2 = (-b - sqrt(discriminant)) / (2 * a);
                        printf("There are two roots: %.2lf and %.2lf\n", root1, root2);
                    }
                }
                break;
            }
            
            default:
                printf("Invalid choice. Please choose between 1, 2, or 3.\n");
        }

        // Ask the user if they want to quit or continue
        printf("\n\n----- End the program? -----\n");
        printf("-----(Enter 'n' to continue)-----\n");
        printf("-----(Enter 'y' to exit application)-----\n");
        scanf(" %c", &exit_choice);  // Added space to ignore newline characters

    } while (exit_choice != 'y');

    return 0;
}
