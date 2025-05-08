#include <stdio.h>

//make a pointer to a using *b pointing to the adress of a
void sqr(int *b){
    // multiply the pointer to the adress by its self to squar it 
    //altering the value not just visiting 
    *b *= *b;
}

int main (){
    int a = 5;
    //pass the adress of a which is equals to 5
    sqr(&a);
    //print the value after squaring
    printf("[%d]",a);
}

