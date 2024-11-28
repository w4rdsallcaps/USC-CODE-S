/*
============================================================================
FILE : novalKi_LE8_13.c
AUTHOR : Kineth M Noval
DESCRIPTION : Create a function that determine and returns 
the maximum number in an array of integers using pointers. 
The function accepts the starting address of the array and number of entries.
COPYRIGHT : 26/11/2024
============================================================================
*/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//redeclaring the functions 
char *numberEnteries();
int validateInt(const char *input);
void  EnteringArr(int limit,int arr[]);
void findingLargest(int limit,int arr[]);


int main(){
    int arr[99];
    //run functiong thru main 
    char *input = numberEnteries();
    int limit = validateInt(input);
    EnteringArr( limit, arr);
    findingLargest(limit,arr);
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

//function for enteringArr
void  EnteringArr(int limit,int arr[]){
    for (int i = 0; i < limit ; i++){
        printf("Enter number: ");
        scanf ("%d",&arr[i]);
    }
}

//function for finding Largest Number and displaying 
void findingLargest(int limit,int arr[]){
    int *largest = arr[0];

    for(int i = 1; i < limit; i ++){
        if (largest < arr[i]){
            largest = arr[i]; 
        }
    }
    printf("Maximum Number: %d",largest);
}
