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

    int balance(int depositAmount, int period, int interestRate ); 

int main (){
    // starting if statement 
    int whatDoYouWant;
    //1
     const int pi = 3.1415;
    int radius, heightOfCylinder, area, volume;
    //2
    int depositAmount,period,realbalance;
    float interestRate;
    //3
    const float gravity = 9.81;
    float  height, initialVelocity,discriminant, time, finalVelocity,t1,t2;

    // the tree way type shit
    printf(" pick between programs \n 1.)program that calculate area and volume of a cylinder\n 2.) program that calculates your program\n3.)program that calculates the final velocity and travel time of a basekball \n ");
    scanf("%d",&whatDoYouWant);
    if (whatDoYouWant == 1){
        printf("Enter the radius of the cylinder: ");
        scanf("%d",&radius);
        printf("Enter The height of the cylinder: "); 
        scanf("%d", &heightOfCylinder);
        //calculations
        area = 2*pi*radius*heightOfCylinder + 2*pi*radius*radius;
        volume = pi*radius*heightOfCylinder;
        //display the area volume
        printf("area: %d\nvolume: %d", area, volume ); 
    }
    else if (whatDoYouWant == 2){
        printf("Enter the amount of money you want to deposit: ");
        scanf("%d", &depositAmount);
        printf("Enter the number of years you want to save for: ");
        scanf("%d", &period);
        printf("Enter the interest rate (in percent): ");
        scanf("%f", &interestRate);
        //calling the function
        realbalance = balance(depositAmount ,period ,interestRate );
        //printing the balance
        printf("The balance after %d years is: %d\n", period, realbalance);   
    }

    else if (whatDoYouWant == 3){
        // display and ask for users input
        printf("Enter the initial velocity: ");
        scanf("%f",&initialVelocity);
        printf("enter the height: ");
        scanf("%f", &height);
        //solve for discriminantand finalvelocity
        discriminant = (initialVelocity*initialVelocity) - (2*gravity*height);
        finalVelocity = sqrt(initialVelocity*initialVelocity+2*gravity*height);
        //display the final velocity
        printf("the final Velocity is %d ", finalVelocity);

        //if discriminant is equals to or greated that 0 then do calculations
            if (discriminant >= 0) {

                // Use the quadratic formula to calculate time
                t1 = (-initialVelocity + sqrt(discriminant)) / gravity;
                t2 = (-initialVelocity - sqrt(discriminant)) / gravity;
                
                // if both numbers are above or equals0
                if (t1 >= 0 && t2 >= 0) {
                    printf("Time to hit the ground: %.2f seconds or %.2f seconds\n", t1, t2);
                } 

                // if only t1 is above or equals to 0
                else if (t1 >= 0) {
                    printf("Time to hit the ground: %.2f seconds\n", t1);
                } 

                // if only t2 is above or equals to 0
                else if (t2 >= 0) {
                    printf("Time to hit the ground: %.2f seconds\n", t2);
                } 

                //if time is not real
                else {
                    printf("No valid solution: object does not reach the ground.\n");
                }

                 // If the discriminant is negative, no real solution exists for time
            } else {
                printf("No real solution exists for the given height and velocity.\n");     
       }
    }
    else {
        printf("Invalid choice. Please choose a valid option.\n");
    }
    //end the program 
    return 0;
}

    //function
    int balance(int depositAmount, int period, int interestRate ){
        //declaring more stuff
        int finalBalance ;
        float rate; 
        //computations
         rate = interestRate /100.0;
        finalBalance = depositAmount * pow((1+rate), period);
        //end function with final balance being the resultant
        return finalBalance;
    }