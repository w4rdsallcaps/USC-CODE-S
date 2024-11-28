/*
============================================================================
FILE : novalKi_LE8_12.c
AUTHOR : Kineth M Noval
DESCRIPTION : Write a function to search an element in array using
 pointers and return the index location. The function accepts the 
 starting address of the array, number of entries and number to search.
COPYRIGHT : 26/11/2024
============================================================================
*/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//redelcaring functions
char *numberEnteries();
int validateInt(const char *input);
void  EnteringArr(int limit,int arr[]);
int searchTarget(int limit,int arr[]);
void displayIndex(int index);

int main(){
    // decalre arr
    int arr[99];
    //passing functions thru main 
    char *input = numberEnteries();
    int limit = validateInt(input);
    EnteringArr( limit, arr);
    int index = searchTarget(limit, arr);
    displayIndex(index);
    return 0;
}

//asking for number of entries and error trapping  
 char *numberEnteries(){
    static char buffer[100];
    printf("Enter number of entries: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    return buffer;
}


// Function to validate and return an integer
int validateInt(const char *input) {
    char *endptr;
    int value = strtol(input, &endptr, 10);

    if (*endptr != '\0') {
        fprintf(stderr, "Invalid input. Please enter a valid integer.\n");
        exit(EXIT_FAILURE); 
    }

    return value; 
}

//inputting the inputs into the array 
void  EnteringArr(int limit,int arr[]){
    for (int i = 0; i < limit ; i++){
        printf("Enter number: ");
        scanf ("%d",&arr[i]);
    }
}
//function to look for looking for specific number 
int searchTarget(int limit,int arr[]){
    int target; 
    printf("Search data: ");
    scanf("%d",&target);

    for (int i = 0; i < limit; i ++){
        if (* (arr + i) == target ){
            return i;
        }
    }
    return -1;
}
//function to display what index the target was found 
void displayIndex(int index){
    if(index == -1 ){
        printf("NOT FOUND");
    } 
    else{
        printf("FOUND in index: %d ",index);
    }
}
