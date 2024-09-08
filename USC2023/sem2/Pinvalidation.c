#include <stdio.h>
#include <string.h>

int main() {
    char correctPin[] = "12345678"; 
    char enteredPin[20];  
    int attempts = 0;
    while (1) {
        printf("Enter your PIN: ");
        scanf("%s", enteredPin);
        if (strcmp(enteredPin, correctPin) == 0) {
            printf("Success, you may now proceed...\n");
            break; 
        } else {
            attempts++;
            if (attempts < 3) {
                printf("Sorry, Wrong PIN. Please try again.\n");
            } else {
                printf("Sorry, you have entered the wrong PIN, three attempts were over.\n");
                break; 
            }
        }
    }
    return 0;
}