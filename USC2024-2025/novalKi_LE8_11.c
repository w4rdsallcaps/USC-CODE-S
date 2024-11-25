#include<stdio.h>

int askingDay();
void displayDay(int number);
    
int main(){
    int number = askingDay();
    displayDay(number);
    return 0;
}

int askingDay(){
        int number = 0;

    printf("Enter a Day (between 1-7): ");
    scanf("%d",&number);
    return number;
}

void displayDay(int number){
        char *days[8] = {"  ","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
        if ( number > 7 || number < 1 ){
        printf("INVALID INPUT");
    }
        else{
            printf("Day of The Week: %s",days[number]);
        }
    
}
