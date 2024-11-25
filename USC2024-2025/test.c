#include<stdio.h>
    void activityOne();
    void activityTwo();
int main (){
    activityOne();
    activityTwo();
    return 0;
}

    void activityOne(){
        int number1 = 2,number2 = 3,number3 = 4,number4 = 5,sum = 0;
        int *p1,*p2,*p3,*p4;

        p1 = &number1;
        p2 = &number2;
        p3 = &number3;
        p4 = &number4;

        sum = *p1 + *p2 + *p3 + *p4;

        printf("Sum:%d \nAdress p1: %p \nAdress p2: %p \nAdress p3: %p \nAdress p4: %p",sum, p1, p2,p3,p4);
    }
    void activityTwo(){
        int x[5] = {1,2,3,4,5};
        int *p1;
        p1 = x;
        printf("%d",*p1);
        x[4] = *p1 + p1[4];
        printf("\narray digits\n");
        for(int i = 0; i < 5; i++){
            printf("%d, ",p1[i]);
        }
        
    }