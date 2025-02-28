#include<stdio.h>

typedef struct {
    char motorcycle_name[100];
    char motorcycle_brand[100];
    int year_model;
    char plate_number[100];
    struct Motorcycle *next;
} Motorcycle;


void acceptUserInput(int motercycleCount,Motorcycle **head){
    for(int i = 0; i < motercycleCount; i++){
        char name[100], brand[100], plate[100];
        int year;
        printf("ENTER MOTORCYCLE DETAILS");
        
        printf("Name: ");
        getchar();
        fgets(name, sizeof(name),stdin);
        name[strspn(name,"\n")] = 0;

        printf()
    }
}

int main(){
    int motorcycleCount;
    Motorcycle * head = NULL;
    printf("This program is a motercycle catalog store'r!!\n");
    printf("How many motorcycle's do you have?\n");
    scanf("%d",&motorcycleCount);
    acceptUserInput(motorcycleCount,&head);
}