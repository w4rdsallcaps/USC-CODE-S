#include<stdio.h>
#include<windows.h>
#include<math.h>


int pwr(int n,int power){
    if(power == 1){
        return n;
    }
    else{
        int result = n * pwr(n, power - 1);
        printf("%d\n",result);
        Sleep(1000);
        return result;
    }  
}

int main(){
    int n = 0;
    int power = 0;
    printf("give me number to start on: ");
    scanf("%d",&n);
    printf("give me power to start on: ");
    scanf("%d",&power);
    int result = pwr(n,power);

    printf("\nthe result is %d",result);
    return 0;
}