/*
============================================================================
FILE : novalKi_LE3.12
AUTHOR : Kineth Montaus Noval
DESCRIPTION :  a program that allows you to choose between a program that will calculate the area and volume of a cylinder.
 a program that will calculate the account balance after we deposited the amount of money for a given period (in years) with interest rate. 
 a program that will calculate the final velocity and time of travel of a baseball that is thrown downward from a tower of a certain height and initial speed. 
COPYRIGHT : 09/05/24
============================================================================
*/
#include <stdio.h>
#include <math.h>

// Function prototypes
void programOne(float pi, float radius, float heightOfCylinder);
void programTwo(float depositAmount, int period, float interestRate);
void programThree(float gravity, float height, float initialVelocity);

int main (){
    int whatDoYouWant;

    // Constants
    const float pi = 3.1415;
    const float gravity = 9.81;

    // Variables for each program
    float radius, heightOfCylinder;
    float depositAmount, interestRate;
    int period;
    float height, initialVelocity;

    // Program selection
    printf("Pick between programs:\n");
    printf("1.) Program that calculates area and volume of a cylinder\n");
    printf("2.) Program that calculates your deposit balance\n");
    printf("3.) Program that calculates the final velocity and travel time of a basketball\n");
    scanf("%d", &whatDoYouWant);

    if (whatDoYouWant == 1) {
        programOne(pi, radius, heightOfCylinder);
    } else if (whatDoYouWant == 2) {
        programTwo(depositAmount, period, interestRate);
    } else if (whatDoYouWant == 3) {
        programThree(gravity, height, initialVelocity);
    } else {
        printf("Invalid choice. Please choose a valid option.\n");
    }

    return 0;
}

void programOne(float pi, float radius, float heightOfCylinder){
    
    printf("Enter the radius of the cylinder: ");
    scanf("%f", &radius);
    printf("Enter the height of the cylinder: "); 
    scanf("%f", &heightOfCylinder);

    float area = 2 * pi * radius * (heightOfCylinder + radius);
    float volume = pi * radius * radius * heightOfCylinder;

    printf("Area: %.2f\n", area);
    printf("Volume: %.2f\n", volume);
}

void programTwo(float depositAmount, int period, float interestRate){
    printf("Enter the amount of money you want to deposit: ");
    scanf("%f", &depositAmount);
    printf("Enter the number of years you want to save for: ");
    scanf("%d", &period);
    printf("Enter the interest rate (in percent): ");
    scanf("%f", &interestRate);

    float rate = interestRate / 100.0;
    float realBalance = depositAmount * pow((1 + rate), period);

    printf("The balance after %d years is: %.2f\n", period, realBalance);
}

void programThree(float gravity, float height, float initialVelocity){
    printf("Enter the initial velocity: ");
    scanf("%f", &initialVelocity);
    printf("Enter the height: ");
    scanf("%f", &height);

    float discriminant = (initialVelocity * initialVelocity) - (2 * gravity * height);
    float finalVelocity = sqrt(initialVelocity * initialVelocity + 2 * gravity * height);

    printf("The final velocity is %.2f m/s\n", finalVelocity);

    if (discriminant >= 0) {
        float t1 = (-initialVelocity + sqrt(discriminant)) / gravity;
        float t2 = (-initialVelocity - sqrt(discriminant)) / gravity;

        if (t1 >= 0 && t2 >= 0) {
            printf("Time to hit the ground: %.2f seconds or %.2f seconds\n", t1, t2);
        } else if (t1 >= 0) {
            printf("Time to hit the ground: %.2f seconds\n", t1);
        } else if (t2 >= 0) {
            printf("Time to hit the ground: %.2f seconds\n", t2);
        } else {
            printf("No valid solution: object does not reach the ground.\n");
        }
    } else {
        printf("No real solution exists for the given height and velocity.\n");
    }
}

