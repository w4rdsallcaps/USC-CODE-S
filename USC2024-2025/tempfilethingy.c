#include <stdio.h>
#include <unistd.h>

int main() {
    int i, j;
    float principleMoney = 10000, interestRate = 0.02, time = 6, FutureValue, debtBalance = 10250;

    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("Principle Money: %.2f\n", principleMoney);
    printf("Interest Rate: %0.2f\n", interestRate);
    printf("Time: %0.2f years\n", time);
    printf("Interest: %0.2f\n", interestRate * principleMoney);

    // Headers for Future Value Table
    printf("\n%-10s %-15s\n", "Year", "Future Value");

    for (i = 1; i <= 6; i++) {
        // Print year with left-aligned width of 10 characters
        printf("%-10d", i);

        // Print Future Value with left-aligned width of 15 characters and two decimal places
        principleMoney += 200;  // Increase principleMoney by 200 each year
        printf("%-15.2f\n", principleMoney);
        
        sleep(1);  // Sleep for 1 second for visibility
    }

    printf("\nPaying debt");
    for (i = 1; i <= 5; i++) {
        printf(".");
        sleep(1);  // Sleep for 1 second for visibility
    }

    // Headers for Debt Payment Table
    printf("\n\n%-15s %-25s\n", "Month", "Remaining Debt Balance");

    i = 0;  // Initialize 'i' to 0 to start from January

    // Modify the condition to stop the loop when debtBalance is less than or equal to zero
    while (debtBalance > 0 && i < 12) {  // Stop when debtBalance drops below zero
        // Print Month name with left-aligned width of 15 characters
        printf("%-15s", months[i]);  // Print the current month name
        i++;  // Move to the next month

        // Subtract 2500 from debtBalance and ensure no negative values
        debtBalance -= 2500;
        if (debtBalance < 0) {
            debtBalance = 0;  // Set to 0 if balance goes negative
        }

        // Print the remaining debt balance with left-aligned width of 25 characters and two decimal places
        printf("%-25.2f\n", debtBalance);
    }

    return 0;
}
