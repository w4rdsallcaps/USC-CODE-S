#include <stdio.h>

int main (){
    char operation;
    float userInp, secUserinp, answer;

    printf("Input:");
    scanf ("%c", &operation);

    printf ("First Input:");
    scanf ("%f", &userInp);

    printf ("Second Input:");
    scanf ("%f", &secUserinp);

    if (operation == '+' ) {
        answer = userInp+secUserinp;
        printf ("This is the answer: %.2f", answer);
    }

    else if (operation == '-' ) {
        answer = userInp-secUserinp;
        printf ("This is the answer: %.2f", answer);
    }

    else if (operation == '*' ){
        answer = userInp*secUserinp;
        printf ("This is the answer:%.2f", answer);
    }

    else if (operation == '/' ){
        answer = userInp/secUserinp;
        printf ("This is the answer:%.2f", answer);
    }

    else {
        printf ("Operation not available");
    }
    


    return 0;
}