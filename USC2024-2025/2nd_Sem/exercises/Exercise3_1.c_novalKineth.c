#include<stdio.h>
#include<windows.h>

int sum(int n,int sumOf){
    if(n == 0){
        return sumOf;
    }
    else{
        sumOf += n;
        printf("\n%d",sumOf);
        n--;
        Sleep(1000);
        sum(n,sumOf);
    }  
}

int main(){
    int n = 0;
    int sumOf = 0;
    printf("give me number to start on: ");
    scanf("%d",&n);
    int result = sum(n,sumOf);

    printf("\nthe result is %d",result);
    return 0;
}