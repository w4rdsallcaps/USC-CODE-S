#include<stdio.h>
#include<math.h>

int main(){
    // Declare variables to store coefficients and roots
    float a, b, c, d, root1, root2;

    // Prompt user to enter coefficients
    printf("Give value to A: ");
    scanf("%f", &a);
    printf("Give value to B: ");
    scanf("%f", &b);    
    printf("Give value to C: ");
    scanf("%f", &c);   

    // Check if equation is linear (a = 0)
    if (a == 0 && b == 0) {
        // If both a and b are 0, there is no solution
        printf("There is no solution");
    }
    else if (a == 0) {
        // If a is 0, there is only one root
        root1 = -c / b;
        printf("There is only one root: %.2f", root1);
    }
    else {
        // Calculate discriminant (d)
        d = (b*b) - (4*a*c);
        
        // Check if discriminant is negative (no real roots)
        if (d < 0) {
            printf("No real roots\n");
        }
        else {
            // Calculate roots using quadratic formula
            root1 = (-b + sqrt(d)) / (2 * a);
            root2 = (-b - sqrt(d)) / (2 * a);
            printf("Two roots: %.2f and %.2f\n", root1, root2);
        } 
    }
    return 0;
}