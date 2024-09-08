
#include <stdio.h>
 
 //function declaration
char * triangletype(int x, int y, int z);

//main code
int main() {
    while (1) {
        int x, y, z;
        char result;
        printf("\ngive me all three sides of the triangle A,B,C:\n");
        scanf("%d %d %d",&x,&y,&z);
        printf("\n%s", triangletype(x,y,z));
        printf("\n\n -----end the progam?----- \n\n-----(enter n to continue)-----\n\n---(enter y to exit application)--- \n ");
        scanf(" %c", &result);
        if (result == 'y') {
            break;
        }
    }
    return 0;
}
//fuction code
char * triangletype (int x, int y, int z) {
    if (x == y && y == z) {
        return "The triangle is equilateral";
    }
    else if (y < x + z) {
        return "The triangle is isosceles";
    }
    else {
        return "The triangle is scalene";
    }
}

