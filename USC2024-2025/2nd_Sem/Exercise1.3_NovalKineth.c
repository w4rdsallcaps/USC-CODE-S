#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "dealership_data.txt"
#define MAX_LINE 1024

typedef struct {
    char motorcycle_name[100];
    char motorcycle_brand[100];
    int year_model;
    char plate_number[100];
} Motorcycle;

typedef struct {
    char dealership_name[100];
    char dealership_address[100];
    char dealership_owner[100];
    int num_motorcycles;
    Motorcycle *catalog;
} Dealership;

// Function prototypes
void populate_dealership(Dealership *d);
void populate_motorcycle(Motorcycle *m);
void clear_input_buffer(void);
void get_string_input(char *buffer, int size);
void display_dealership_info(Dealership *dealerships, int num_dealerships);
void save_to_file(Dealership *dealerships, int num_dealerships);
int load_from_file(Dealership **dealerships);

int main() {
    Dealership *dealerships = NULL;
    int num_dealerships = 0;
    int new_dealerships;
    
    // Try to load existing data
    num_dealerships = load_from_file(&dealerships);
    printf("\nLoaded %d dealerships from file.\n", num_dealerships);

    printf("\n[THIS PROGRAM IS FOR STORING MOTORCYCLE INFORMATION AND THEIR RESPECTIVE DEALERSHIPS]\n\n");
    printf("Enter number of new dealerships to add: ");
    while (scanf("%d", &new_dealerships) != 1 || new_dealerships < 0) {
        printf("Please enter a valid number: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    // Reallocate memory to add new dealerships
    int total_dealerships = num_dealerships + new_dealerships;
    dealerships = (Dealership *)realloc(dealerships, total_dealerships * sizeof(Dealership));
    if (dealerships == NULL && total_dealerships > 0) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Populate new dealership information
    for (int i = num_dealerships; i < total_dealerships; i++) {
        printf("\n=== Dealership %d Information ===\n", i + 1);
        populate_dealership(&dealerships[i]);

        printf("Enter number of motorcycles in this dealership: ");
        while (scanf("%d", &dealerships[i].num_motorcycles) != 1 || dealerships[i].num_motorcycles <= 0) {
            printf("Please enter a valid positive number: ");
            clear_input_buffer();
        }
        clear_input_buffer();

        dealerships[i].catalog = (Motorcycle *)malloc(dealerships[i].num_motorcycles * sizeof(Motorcycle));
        if (dealerships[i].catalog == NULL) {
            printf("Memory allocation failed!\n");
            for (int j = 0; j < i; j++) {
                free(dealerships[j].catalog);
            }
            free(dealerships);
            return 1;
        }

        for (int j = 0; j < dealerships[i].num_motorcycles; j++) {
            printf("\n--- Motorcycle %d Information ---\n", j + 1);
            populate_motorcycle(&dealerships[i].catalog[j]);
        }
    }

    display_dealership_info(dealerships, total_dealerships);
    save_to_file(dealerships, total_dealerships);

    // Cleanup
    for (int i = 0; i < total_dealerships; i++) {
        free(dealerships[i].catalog);
    }
    free(dealerships);

    return 0;
}

void save_to_file(Dealership *dealerships, int num_dealerships) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    fprintf(file, "%d\n", num_dealerships);
    
    for (int i = 0; i < num_dealerships; i++) {
        fprintf(file, "%s\n%s\n%s\n%d\n", 
            dealerships[i].dealership_name,
            dealerships[i].dealership_address,
            dealerships[i].dealership_owner,
            dealerships[i].num_motorcycles);
        
        for (int j = 0; j < dealerships[i].num_motorcycles; j++) {
            fprintf(file, "%s\n%s\n%d\n%s\n",
                dealerships[i].catalog[j].motorcycle_name,
                dealerships[i].catalog[j].motorcycle_brand,
                dealerships[i].catalog[j].year_model,
                dealerships[i].catalog[j].plate_number);
        }
    }

    fclose(file);
    printf("\nData has been saved to %s\n", FILENAME);
}

int load_from_file(Dealership **dealerships) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return 0;  // File doesn't exist or can't be opened
    }

    int num_dealerships;
    fscanf(file, "%d\n", &num_dealerships);

    *dealerships = (Dealership *)malloc(num_dealerships * sizeof(Dealership));
    if (*dealerships == NULL && num_dealerships > 0) {
        fclose(file);
        return 0;
    }

    char buffer[MAX_LINE];
    for (int i = 0; i < num_dealerships; i++) {
        // Read dealership info
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = 0;
        strcpy((*dealerships)[i].dealership_name, buffer);

        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = 0;
        strcpy((*dealerships)[i].dealership_address, buffer);

        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = 0;
        strcpy((*dealerships)[i].dealership_owner, buffer);

        fscanf(file, "%d\n", &(*dealerships)[i].num_motorcycles);

        // Allocate and read motorcycle catalog
        (*dealerships)[i].catalog = (Motorcycle *)malloc((*dealerships)[i].num_motorcycles * sizeof(Motorcycle));
        if ((*dealerships)[i].catalog == NULL && (*dealerships)[i].num_motorcycles > 0) {
            // Handle allocation failure
            for (int j = 0; j < i; j++) {
                free((*dealerships)[j].catalog);
            }
            free(*dealerships);
            fclose(file);
            return 0;
        }

        for (int j = 0; j < (*dealerships)[i].num_motorcycles; j++) {
            fgets(buffer, sizeof(buffer), file);
            buffer[strcspn(buffer, "\n")] = 0;
            strcpy((*dealerships)[i].catalog[j].motorcycle_name, buffer);

            fgets(buffer, sizeof(buffer), file);
            buffer[strcspn(buffer, "\n")] = 0;
            strcpy((*dealerships)[i].catalog[j].motorcycle_brand, buffer);

            fscanf(file, "%d\n", &(*dealerships)[i].catalog[j].year_model);

            fgets(buffer, sizeof(buffer), file);
            buffer[strcspn(buffer, "\n")] = 0;
            strcpy((*dealerships)[i].catalog[j].plate_number, buffer);
        }
    }

    fclose(file);
    return num_dealerships;
}

// Rest of the functions (populate_dealership, populate_motorcycle, clear_input_buffer, 
// get_string_input, display_dealership_info) remain unchanged from the original code
void populate_dealership(Dealership *d) {
    printf("Dealership Name: ");
    get_string_input(d->dealership_name, sizeof(d->dealership_name));
    
    printf("Dealership Address: ");
    get_string_input(d->dealership_address, sizeof(d->dealership_address));
    
    printf("Dealership Owner: ");
    get_string_input(d->dealership_owner, sizeof(d->dealership_owner));
}

void populate_motorcycle(Motorcycle *m) {
    printf("Motorcycle Name: ");
    get_string_input(m->motorcycle_name, sizeof(m->motorcycle_name));
    
    printf("Motorcycle Brand: ");
    get_string_input(m->motorcycle_brand, sizeof(m->motorcycle_brand));
    
    printf("Year Model: ");
    while (scanf("%d", &m->year_model) != 1 || m->year_model < 1900 || m->year_model > 2100) {
        printf("Please enter a valid year (1900-2100): ");
        clear_input_buffer();
    }
    clear_input_buffer();
    
    printf("Plate Number: ");
    get_string_input(m->plate_number, sizeof(m->plate_number));
}

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void get_string_input(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0;  // Remove trailing newline
}

void display_dealership_info(Dealership *dealerships, int num_dealerships) {
    printf("\n=== DEALERSHIP AND MOTORCYCLE INFORMATION ===\n");
    
    for (int i = 0; i < num_dealerships; i++) {
        printf("\nDealership %d:\n", i + 1);
        printf("Name: %s\n", dealerships[i].dealership_name);
        printf("Address: %s\n", dealerships[i].dealership_address);
        printf("Owner: %s\n", dealerships[i].dealership_owner);
        printf("Number of Motorcycles: %d\n", dealerships[i].num_motorcycles);
        
        printf("\nMotorcycles in this dealership:\n");
        for (int j = 0; j < dealerships[i].num_motorcycles; j++) {
            printf("\n  Motorcycle %d:\n", j + 1);
            printf("  Name: %s\n", dealerships[i].catalog[j].motorcycle_name);
            printf("  Brand: %s\n", dealerships[i].catalog[j].motorcycle_brand);
            printf("  Year: %d\n", dealerships[i].catalog[j].year_model);
            printf("  Plate Number: %s\n", dealerships[i].catalog[j].plate_number);
        }
        printf("\n----------------------------------------\n");
    }
}