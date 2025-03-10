#include<stdio.h>
#include<windows.h>

int decrease(int n){
    if(n == 0){
        return 0;
    }
    else{
        Sleep(1000);
        printf("\n%d",n);
        n--;
        decrease(n);
    }  
}

int main(){
    int n = 0;

    printf("give me number to start on: ");
    scanf("%d",&n);
    decrease(n);
    return 0;
}