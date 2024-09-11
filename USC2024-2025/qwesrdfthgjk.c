#include <stdio.h>

int main(){
    int z, x, y, r;
    printf("give me 2 numbers \n");
    scanf("%d%d", &x, &y);
    z = x - y;
    if(z < 0 )
    {
        r = x + y;
    } 
    else if (z == 0)
    {
        r = (2*x) + (2*y);
    }
    else 
    {
        r = x*y;
    }
    printf("X = %d Y = %d R = %d ", x, y, r );
    return 0;
}
