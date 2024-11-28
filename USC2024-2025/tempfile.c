#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *askingNumber(){
    static char buffer[100];
    printf("Give me a number: ");
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


int main() {
    char *input = askingNumber();
    int number = validateInt(input);

    // Print the validated integer
    printf("You entered: %d\n", number);
    return 0;
}
