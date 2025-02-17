#include <stdio.h>
#define MAX 10
#define x 1

struct motercycle{

        char name[MAX];
        char brand[MAX];
        int year_model;
        char plate_number[MAX];
        int miles;
};

void initialize(int arr[]);
void display(int arr[]);
void populate(int arr[]);
void reverse(int arr[]);
void createObject(struct motercycle *descript,int i);
void displayObject(struct motercycle *descript,int i);


int main(){
    int arr[MAX];
    int i;
    struct motercycle descript[MAX];

    display(arr);
    initialize(arr);
    display(arr);
    populate(arr);
    display(arr);
    reverse(arr);
    display(arr);
    for(i = 0; i < MAX; i++){
        createObject(&descript[i],i);
    }
    for(i = 0; i < MAX; i++){
        displayObject(&descript[i],i);
    }
    return 0;
}

void initialize(int arr[]){
    int i;
    for(i = 0; i < MAX;i++){
        arr[i]= 0;
    }
}

void display(int arr[]){
    int i;
    for(i = 0; i < MAX; i++){
        printf("[%d] ",arr[i]);
    }
    printf("\n");
}

void populate(int arr[]){
    int i;
    for(i = 0; i < MAX;i++){
        printf("\nGive value for arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
}

void reverse(int arr[]){
    int i;
    int temp_arr[MAX];

    for( i = 0; i < MAX; i++){
        temp_arr[i] = arr[MAX - i - 1];
    }

    for(int i = 0; i < MAX; i++){
        arr[i] = temp_arr[i];
}

}

void createObject(struct motercycle *descript,int i){
        printf("Name %d.)",i+1);
        scanf("%s",descript->name);
        printf("brand %d.)",i+1);
        scanf("%s",&descript->brand);
        printf("Year Model %d.)",i+1);
        scanf("%d",&descript->year_model);
        printf("plate Number %d.)",i+1);
        scanf("%s",descript->plate_number);
        printf("milage %d.)",i+1);
        scanf("%d",&descript->miles);
        printf("\n");
}

void displayObject(struct motercycle *descript,int i){
        printf("Displaying inputted motercycles...");
        printf("\n");
        printf("\nmotercycle %d.)",i+1);
        printf("\nName\t\t[%s]",descript->name);
        printf("\nbrand\t\t[%s]",descript->brand);
        printf("\nYear Model\t[%d]",descript->year_model);
        printf("\nplateNumber\t[%s]",descript->plate_number);
        printf("\nmilage\t\t[%d]",descript->miles);
}
