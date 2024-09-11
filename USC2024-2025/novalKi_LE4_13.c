#include<stdio.h>

int main(){
    int mark1, mark2, mark3, mark4, averageGrade;

    printf("Mark 1 grade: ");
    scanf("%d", &mark1);
    printf("Mark 2 grade: ");
    scanf("%d", &mark2);   
     printf("Mark 3 grade: ");
    scanf("%d", &mark3);   
     printf("Mark 4 grade: ");
    scanf("%d", &mark4);
    averageGrade = (mark1 + mark2 + mark3 + mark4)/4;
    if (100 > averageGrade && averageGrade >= 50 ){
        printf("Final Grade: %d PASSSED", averageGrade);
    }
    else if ( 0 < averageGrade && averageGrade < 50 ) {
        printf("Final Grade: %d FAILED", averageGrade);
    }
    else {
        printf("INVALID INPUTS");
    }
    return 0;
}