#include <stdio.h>
#include <unistd.h>

int main(){
    int i,j, spaces = 5;
    float principleMoney = 10000, interestRate = 0.02, time = 6,FutureValue,debtBalance = 10250;

    const char *months[] = {
        "January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"
    };

    printf("Principle Money: %.2f\n",principleMoney);
    printf("Interest Rate: %0.2f\n",interestRate);
    printf("Time: %0.2f years\n", time);
    printf("interest: %0.2f\n",interestRate*principleMoney);

    printf("Year"); 

    for(j=1; j<= spaces; j++){
        printf(" ");
    }
    
    printf("Future Value \n");

    for(i=1; i <= 6; i++){    
    printf("%d",i);
    for(j=1; j <= spaces + 3; j++){
            printf(" ");
        }
    
    printf("%.2f",principleMoney = principleMoney + 200 );
    printf("\n");
    sleep(1);
    }
    
    printf("\n");
    printf("Paying debt");
    for(i = 1; i <= 3; i++){
        printf(".");
        sleep(1);
    }
    
    printf("\n");
    
    printf("%-15s %-20s\n", "Month", "Remaining Debt Balance");

    i = 0;
    while(debtBalance > 0.1 && i < 12)
    {
        printf("%-15s",months[i]);
        i++;
        debtBalance = debtBalance - 2500;
        if (debtBalance < 0){
            debtBalance = 0;
        }
        printf("%-25.2f\n",debtBalance);
        sleep(1);
    }
return 0;  
//rawrr
}