#include <stdio.h>

int main() {
    float vf, vi, a, t;
    
    printf("This program calculates the final velocity\nEnter the Initial Velocity: ");
    scanf("%f", &vi);
    printf("Enter the Acceleration: ");
    scanf("%f", &a);
    printf("Enter the Time: ");
    scanf("%f", &t);

    vf = vi + (a * t);

    printf("Initial Velocity: %.2f\nAcceleration: %.2f\nTime: %.2f\n FINAL VELOCITY: %.2f", vi, a, t, vf);
    return 0;
    }
    