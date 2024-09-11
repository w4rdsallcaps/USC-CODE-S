#include<stdio.h>
#include<math.h>

int main(){
    float a, b, c, d, root1, root2 ;
    printf("give value to A: ");
    scanf ("%f",&a );
    printf("give value to B: ");
    scanf ("%f",&b );    
    printf("give value to C: ");
    scanf ("%f",&c );   
    if ( a == 0 && b == 0 ){
    printf("there is no solution");
    }
    else if (a == 0) {
        root1 = -c /b;
        printf("there is only one root : %d",root1);
    }
    else {
        d = (b*b) - (4*a*c);
            
            if (d < 0 ){
                printf("no real roots \n ");
            }
            else {
                root1 = (-b + sqrt(d)) / (2 * a);
                root2 = (-b - sqrt(d)) / (2 * a);
                printf("Two roots: %.2f and %.2f\n", root1, root2);
            } 
    }
    return 0;

}