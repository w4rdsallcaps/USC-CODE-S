#include <stdio.h>
#include <math.h>


    int balance(int depositAmount, int period, int interestRate ); 

int main () {
    //declaring of this stuff
    int depositAmount,period,realbalance;
    float interestRate;
    //displaying and getting the input from the user
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
    //end script
    return 0;
}
    //function
    int balance(int depositAmount, int period, int interestRate ){
        //declaring more stuff
        int finalBalance,rate; 
        //computations
        float rate = interestRate /100.0;
        finalBalance = depositAmount * pow((1+rate), period);
        //end function with final balance being the resultant
        return finalBalance;
    }

