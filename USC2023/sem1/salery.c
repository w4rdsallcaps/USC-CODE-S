#include <stdio.h>

int main(){

    int salary;
    char Name[20];
    
    printf("enter name: ");
    gets(Name);

    printf("\nEnter Salary: ");
    scanf("%d", &salary);
    int weekly = 5 * salary; //5 working days per week
    int monthly = weekly * 4; //4 weeks per month
    int yearly = monthly * 52; //52 weeks per year
    printf("Hi %s, here is your income: \n\tweekly: %d \n\tmonthly: %d \n\tyearly: %d \n\t", Name, weekly, monthly, yearly);
    printf("\n----------------------------------------------");
    return 0;
}
