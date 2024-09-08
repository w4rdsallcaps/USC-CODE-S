#include<stdio.h>

float areacircle(float x);
float arearectangle(float x, float y);
float areatriangle(float x, float y);

int main () {
    float x, y, result, choice;
    float pi=3.14159;
    while (1) {
        printf("1. circle\n2 rectangle\n3 triangle\n4. Exit program \nchoose which one:\n");
        printf("what is your choice?");
        choice = getch();
            
        if (choice == '1'){
        printf("\nwhat is your radius? ");
        scanf("%f", &x);
        result = areacircle(x);
        printf("the area of the circle is %.2f", result); 
        }
        else if (choice == '2'){
            printf("\nwhat is your base and height? ");
        scanf("%f %f",&x, &y);
        result = arearectangle(x,y);
        printf("the area of the rectangle is %.2f", result);
        }	
        else if (choice == '3'){
            printf("\nwhat is your base and height? ");
        scanf("%f %f",&x, &y);
        result = areatriangle(x,y);
        printf("the area of the triangle is %.2f", result);
        }
        else if (choice == '4') {
            printf("\nThank you for using this program!");
            break;
        }
        else {
            printf("\nInvalid choice dumbass");
        }
    }
	return 0;
}

float areacircle(float x){
	float pi=3.14159;
	return pi*(x*x);
}
float arearectangle (float x, float y){
	return (x*y);
}
float areatriangle (float x, float y){
	return (x*y)/2;
}
