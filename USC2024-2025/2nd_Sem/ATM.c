#include <stdio.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 100
#define CORRECT_USERNAME "w4rds"

int main() {
    char inputted_username[MAX_USERNAME_LENGTH];
    
    do {
        printf("Enter Username: ");
        // Using %99s to prevent buffer overflow
        scanf("%99s", inputted_username);
        
        if (strcmp(CORRECT_USERNAME, inputted_username) == 0) {
            printf("Login successful!\n");
            break;
        } else {
            printf("Incorrect username. Please try again.\n");
        }
    } while (1);
    
    return 0;
}