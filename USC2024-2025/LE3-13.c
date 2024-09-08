/*
============================================================================
FILE : filename.extension
AUTHOR : Kineth Montaus NOval
DESCRIPTION : 
COPYRIGHT : created
REVISION HISTORY
Date: By: Description:
revision date author description of the change
revision date author description of the change
.
.
.
revision date author description of the change
============================================================================
*/
/*
============================================================================
FUNCTION : function name
DESCRIPTION :
ARGUMENTS : (list all parameters pass in the function)
dataType variableName - brief description
dataType variableName - brief description
.
.
.
dataType variableName - brief description
RETURNS : (no return) void
(with return)dataType - brief description
===========================================================================
*/

#include <stdio.h>

int main(){
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