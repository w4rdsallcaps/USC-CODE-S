#include<stdio.h>
#include<string.h>

struct bible {
    char books[5][10];
}dalesbible; 

int main(){
    struct bible dalesbible[5];
    for (int  i = 0; i < 5; i++){
        printf("BOOKS NA ");
        gets(dalesbible[i].books);
    }

    for (int i = 0; i < 5; i++){
    printf(dalesbible[i].books);
    printf("\n");    
    
    }
}