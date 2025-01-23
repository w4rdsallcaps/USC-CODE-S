#include <stdio.h>
#include <windows.h>

#include "Add.c"
#include "Subtract.c"
#include "Multiply.c"
#include "Divide.c"

int main()
{
    float num1, num2 = 77, result;
    char operator, choice;

    while (1)
    {
        printf("Enter two numbers:");
        scanf("%f%f", &num1, &num2);
        printf("Num1: %f Num2: %f", num1, num2);
        system("pause");
    }

    return 0;
}