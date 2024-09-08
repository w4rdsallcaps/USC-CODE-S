#include <stdio.h>

void calculateChange(float purchaseAmount, float bill);

int main() {
    float purchasedAmount, bill;
    printf("This program calculates the change:\n");
    printf("Enter purchased amount: ");
    scanf("%f", &purchasedAmount);
    printf("Enter bill: ");
    scanf("%f", &bill);

    calculateChange(purchasedAmount, bill);
}

void calculateChange(float purchaseAmount, float bill) {
    float change = bill - purchaseAmount;
    if(change < 0)
    printf("\nNot enough money to pay the purchased amount!");
    else
    {
        printf("\nYour change: %.2f\n", change);
        int twenty, ten, five, one, twentyfiveC;
        
        twenty = change / 20;
        change -= twenty * 20;

        ten = change / 10;
        change -= ten * 10;

        five = change / 5;
        change -= five * 5;

        one = change;
        change -= one;

        twentyfiveC = change / 0.25;
        change -= twentyfiveC * 0.25;

        printf("20 Pesos amount: %d\n10 Pesos amount: %d\n5 Pesos amount: %d\n1 Pesos amount: %d\n25 centavos amount: %d", twenty, ten, five, one, twentyfiveC);
    }
}