#include <stdio.h>
#include <math.h>

void main() {
    int n = 0, n2 = 1, empty; 
    for (int x = 0; x < 100; x++){
        empty = n + n2;
        printf("%d = %d\n", x,  empty);
        n = n2;
        n2 = empty;
        sleep(1);
    };

}