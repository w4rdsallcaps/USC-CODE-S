/*
============================================================================
FILE : novalKi_LE3.13
AUTHOR : Kineth Montaus Noval
DESCRIPTION : a program that prints the tuition for 2 semesters at ABC College. ABC charges PHP 450 for registration, 
plus PHP 450 per unit and a penalty of PHP 2,260 for each 12 units or fraction of 12.
COPYRIGHT : 09/05/24
============================================================================
*/


#include <stdio.h>

int main()
{
    // Constants for registration fee, unit payment per unit, and penalty charge
    const int registrationFee = 450, unitPay = 450, penaltyCharge = 2260;
    
    // Variables to store the number of units for each semester and their corresponding fees
    int firstSemUnit, secondSemUnit;
    float firstSemFee, secondSemFee, totalTuitionFee;
    
    // Temporary variables to hold intermediate calculation results for penalty charges
    double temporaryOne, temporaryTwo;

    // Prompt user for number of units for the first semester
    printf("1st Semester Number of Units: ");
    scanf("%d", &firstSemUnit);

    // Prompt user for number of units for the second semester
    printf("2nd Semester Number of Units: ");
    scanf("%d", &secondSemUnit);

    // Calculate first semester fee: (units * unit pay) + registration fee + penalty
    firstSemFee = firstSemUnit * unitPay;
    firstSemFee = firstSemFee + registrationFee;
    temporaryOne = firstSemUnit / 12.0;  
    firstSemFee = firstSemFee + (temporaryOne * penaltyCharge);  

    // Calculate second semester fee: (units * unit pay) + registration fee + penalty
    secondSemFee = secondSemUnit * unitPay;
    secondSemFee = secondSemFee + registrationFee;
    temporaryTwo = secondSemUnit / 12.0;  
    secondSemFee = secondSemFee + (temporaryTwo * penaltyCharge);  

    // Calculate total tuition fee as the sum of both semester fees
    totalTuitionFee = firstSemFee + secondSemFee;

    // Output the calculated fees for both semesters and the total tuition fee
    printf("\nFirst semester fee: %.2f\nSecond semester fee: %.2f\nTotal Tuition Fee: %.2f", firstSemFee, secondSemFee, totalTuitionFee);

    return 0;
}