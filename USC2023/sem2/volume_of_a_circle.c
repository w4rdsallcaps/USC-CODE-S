#include <stdio.h>


int main() { 
    float Pi,radius;
    Pi = 3.14159; 
printf("what is the radius of the circle: ");
	scanf("%f", &radius);

    float Volume = (4.0/3.0 )*Pi*(radius*radius*radius);
    printf("\nthe Volume of the circle is: %f", Volume);
    
    return 0;
}

