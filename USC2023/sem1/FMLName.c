#include <stdio.h>
int main() {
    char Name[256];
    char MName[256];
    char LName[256];
    printf("Enter First Name: ");
    gets(Name);
    printf("Enter Middle name: ");
    gets(MName);
    printf("Enter Last Name: ");
    gets(LName);
    printf("Your Name is %s %s %s", Name, MName, LName);

    return 0;

}

