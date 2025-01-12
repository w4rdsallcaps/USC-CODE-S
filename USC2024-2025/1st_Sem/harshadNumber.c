#include<stdio.h>
#include<windows.h>

int main(){
    int originalNumber,tempNumber = 0,tempNumberTwo = 0  ,limit = 0,i, sum = 0 ;
    printf("Give me a number: ");
    scanf("%d",&originalNumber);

    tempNumber = originalNumber;
    tempNumberTwo = originalNumber;

    while(tempNumber != 0){
        tempNumber = tempNumber / 10;
        limit++;
    }
    
    tempNumber = originalNumber;
        
    for(i = 0; i < limit; i++){
        tempNumber = originalNumber % 10;
        printf("temp number: %d\n",tempNumber);
        originalNumber = originalNumber / 10;
        printf("originalNumber = %d\n",originalNumber);
        sum += tempNumber;
    }

    if( tempNumberTwo % sum == 0 ) {
        printf("The number is a harshad number");
    }
    else{
        printf("The number is not a harshad number");
    }
    return 0;
}


