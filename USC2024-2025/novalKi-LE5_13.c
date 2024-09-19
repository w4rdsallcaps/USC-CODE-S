#include<stdio.h>
#include<math.h>
int main(){
    const float gravity = 9.81;
    float  height, initialVelocity,discriminant, time, finalVelocity,t1,t2;
    printf("Enter the initial velocity: ");
    scanf("%f",&initialVelocity);
    printf("enter the height: ");
    scanf("%f", &height);
    
    discriminant = (initialVelocity*initialVelocity) - (2*gravity*height);

    finalVelocity = sqrt(initialVelocity*initialVelocity+2*gravity*height);
    printf("the final Velocity is %d ", finalVelocity);
    if (discriminant >= 0) {
        // Use the quadratic formula to calculate time
        t1 = (-initialVelocity + sqrt(discriminant)) / gravity;
        t2 = (-initialVelocity - sqrt(discriminant)) / gravity;
        
        // We discard negative time values
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
        // If the discriminant is negative, no real solution exists for time
        printf("No real solution exists for the given height and velocity.\n");
    }
    return 0;
}
