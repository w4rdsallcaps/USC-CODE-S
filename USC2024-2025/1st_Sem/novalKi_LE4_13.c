#include<stdio.h>

int main(){
    // Declare variables to store marks and average grade
    int mark1, mark2, mark3, mark4, averageGrade;

    // Prompt user to enter marks
    printf("Mark 1 grade: ");
    scanf("%d", &mark1);
    printf("Mark 2 grade: ");
    scanf("%d", &mark2);   
    printf("Mark 3 grade: ");
    scanf("%d", &mark3);   
    printf("Mark 4 grade: ");
    scanf("%d", &mark4);
    
    // Calculate average grade
    averageGrade = (mark1 + mark2 + mark3 + mark4)/4;
    
    // Check if average grade is valid (between 0 and 100)
    if (100 >= averageGrade && averageGrade >= 50 ){
        // If average grade is 50 or above, print "PASSED"
        printf("Final Grade: %d PASSED", averageGrade);
    }
    else if ( 0 <= averageGrade && averageGrade < 50 ) {
        // If average grade is below 50, print "FAILED"
        printf("Final Grade: %d FAILED", averageGrade);
    }
    else {
        // If average grade is invalid (outside 0-100 range), print "INVALID INPUTS"
        printf("INVALID INPUTS");
    }
    return 0;
}
