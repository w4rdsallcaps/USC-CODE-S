#include <stdio.h>

int main(){

    for(int i = 1; i <= 9; i++){
        printf("%d\n", i);

        for(int j = 1; j <= i; i++){
            printf("*");
        }
    }
    return 0;
}