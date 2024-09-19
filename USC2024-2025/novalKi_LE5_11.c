#include<stdio.h>
int main() {
    //defining
    const int pi = 3.1415;
    int radius, height, area, volume;
    //displaying and asking for user input
    printf("Enter the radius of the cylinder: ");
    scanf("%d",&radius);
    printf("Enter The height of the cylinder: "); 
    scanf("%d", &height);
    //calculations
    area = 2*pi*radius*height + 2*pi*radius*radius;
    volume = pi*radius*height;
    //display the area volume
    printf("area: %d\nvolume: %d", area, volume );
    //end script
    return 0;
}