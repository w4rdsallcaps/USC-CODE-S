#include <stdio.h>

int main(){
    int i,j,n,m;
    i=j=3;
    n=2*i++;
    m=2*++j;
    printf("%d,%d,%d,%d",i,j,n,m);

    return 0;
}