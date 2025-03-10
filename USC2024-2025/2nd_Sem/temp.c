#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Motorcycle {
    char motorcycle_name[100];
    char motorcycle_brand[100];
    int year_model;
    char plate_number[100];
    struct Motorcycle *next;
    struct Motorcycle *prev;
} Motorcycle;

Motorcycle *head = NULL;

// Function Prototypes
Motorcycle *createMotorcycle(char name[], char brand[], int year, char plate[]);
void getUserInput(char name[], char brand[], int *year, char plate[]);
void prepend(char name[], char brand[], int year, char plate[]);
void append(char name[], char brand[], int year, char plate[]);
void insert(int position, char name[], char brand[], int year, char plate[]);
void removeNode(int position);
void edit(int position, char name[], char brand[], int year, char plate[]);
void display();
void displayReverse();
void makenull();
Motorcycle *first();
Motorcycle *last();
Motorcycle *retrieve(int position);
Motorcycle *search(char name[]);
int empty();

// New Modular Functions
void displayMotorcycleDetails(Motorcycle *motorcycle, int position);
void displayFirstNodes();
void displayLastNodes();
void displaySpecificNode(int position);
void searchAndDisplayMotorcycle(char name[]);
void checkListEmpty();

int main() {
    int choice;
    do {
        char name[100], brand[100], plate[100];
        int year, position;

        printf("\nChoose an action:");
        printf("\n1.) Append\n2.) Prepend\n3.) Insert at Position\n4.) Edit\n5.) Remove\n6.) Display\n7.) Display Reverse\n8.) Make list Null\n9.) Display First Nodes\n10.) Display Last Nodes\n11.) Return a specific node in the list\n12.) Search node with specific item name\n13.) Check if list is empty\n14.) EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getUserInput(name, brand, &year, plate);
                append(name, brand, year, plate);
                break;
            case 2:
                getUserInput(name, brand, &year, plate);
                prepend(name, brand, year, plate);
                break;
            case 3:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                getUserInput(name, brand, &year, plate);
                insert(position, name, brand, year, plate);
                break;
            case 4:
                printf("Enter position to edit: ");
                scanf("%d", &position);
                getUserInput(name, brand, &year, plate);
                edit(position, name, brand, year, plate);
                break;
            case 5:
                printf("Enter position to remove: ");
                scanf("%d", &position);
                removeNode(position);
                break;
            case 6:
                display();
                break;
            case 7:
                displayReverse();
                break;
            case 8:
                makenull();
                break;
            case 9:
                displayFirstNodes();
                break;
            case 10:
                displayLastNodes();
                break;
            case 11:
                printf("Enter position to retrieve: ");
                scanf("%d", &position);
                displaySpecificNode(position);
                break;
            case 12:
                printf("Enter motorcycle name to search: ");
                getchar();
                fgets(name, 100, stdin);
                name[strcspn(name, "\n")] = 0;
                searchAndDisplayMotorcycle(name);
                break;
            case 13:
                checkListEmpty();
                break;
            case 14:
                printf("Exiting program.\n");
                makenull(); // Clean up before exiting
                return 0;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 14);

    return 0;
}

Motorcycle *createMotorcycle(char name[], char brand[], int year, char plate[]) {
    Motorcycle *newMotorcycle = (Motorcycle *)malloc(sizeof(Motorcycle));
    if (!newMotorcycle) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newMotorcycle->motorcycle_name, name);
    strcpy(newMotorcycle->motorcycle_brand, brand);
    newMotorcycle->year_model = year;
    strcpy(newMotorcycle->plate_number, plate);
    newMotorcycle->next = NULL;
    newMotorcycle->prev = NULL;
    return newMotorcycle;
}

void getUserInput(char name[], char brand[], int *year, char plate[]) {
    printf("Enter motorcycle name: ");
    getchar(); 
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Enter motorcycle brand: ");
    fgets(brand, 100, stdin);
    brand[strcspn(brand, "\n")] = 0;

    printf("Enter year model: ");
    scanf("%d", year);
    getchar(); 

    printf("Enter plate number: ");
    fgets(plate, 100, stdin);
    plate[strcspn(plate, "\n")] = 0;
}

void prepend(char name[], char brand[], int year, char plate[]) {
    Motorcycle *newMotorcycle = createMotorcycle(name, brand, year, plate);
    if (!newMotorcycle) return;

    if (head == NULL) {
        head = newMotorcycle;
    } else {
        newMotorcycle->next = head;
        head->prev = newMotorcycle;
        head = newMotorcycle;
    }
}

void append(char name[], char brand[], int year, char plate[]) {
    Motorcycle *newMotorcycle = createMotorcycle(name, brand, year, plate);
    if (!newMotorcycle) return;

    if (head == NULL) {
        head = newMotorcycle;
        return;
    }

    Motorcycle *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newMotorcycle;
    newMotorcycle->prev = temp;
}

void insert(int position, char name[], char brand[], int year, char plate[]) {
    if (position <= 0) {
        prepend(name, brand, year, plate);
        return;
    }
    
    Motorcycle *newMotorcycle = createMotorcycle(name, brand, year, plate);
    if (!newMotorcycle) return;

    Motorcycle *temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range! Appending to the end.\n");
        append(name, brand, year, plate);
        free(newMotorcycle);
        return;
    }

    newMotorcycle->next = temp->next;
    newMotorcycle->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newMotorcycle;
    }

    temp->next = newMotorcycle;
}

void removeNode(int position) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Motorcycle *temp = head;

    if (position == 0) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

void edit(int position, char name[], char brand[], int year, char plate[]) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Motorcycle *temp = head;
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    strcpy(temp->motorcycle_name, name);
    strcpy(temp->motorcycle_brand, brand);
    temp->year_model = year;
    strcpy(temp->plate_number, plate);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Motorcycle *temp = head;
    printf("\nMotorcycle List:\n");
    int position = 0;
    while (temp != NULL) {
        printf("\nPosition: %d\nName: [%s]\nBrand: [%s]\nYear: [%d]\nPlate: [%s]\n", 
               position, temp->motorcycle_name, temp->motorcycle_brand, temp->year_model, temp->plate_number);
        temp = temp->next;
        position++;
    }
}

void displayReverse() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Motorcycle *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("\nMotorcycle List [Reverse]:\n");
    int position = 0;
    Motorcycle *current = head;
    while (current != NULL) {
        position++;
        current = current->next;
    }
    position--; // Adjust position to be 0-based
    
    while (temp != NULL) {
        printf("\nPosition: %d\nName: [%s]\nBrand: [%s]\nYear: [%d]\nPlate: [%s]\n", 
               position, temp->motorcycle_name, temp->motorcycle_brand, temp->year_model, temp->plate_number);
        temp = temp->prev;
        position--;
    }
}

void makenull() {
    while (head) {
        Motorcycle *temp = head;
        head = head->next;
        free(temp);
    }
    printf("List cleared!\n");
}

Motorcycle *first() {
    return head;
}

Motorcycle *last() {
    Motorcycle *temp = head;
    while (temp && temp->next) temp = temp->next;
    return temp;
}

Motorcycle *retrieve(int position) {
    Motorcycle *temp = head;
    for (int i = 0; temp && i < position; i++) temp = temp->next;
    return temp;
}

Motorcycle *search(char name[]) {
    Motorcycle *temp = head;
    while (temp) {
        if (strcmp(temp->motorcycle_name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

int empty() {
    return head == NULL;
}

// New Modular Functions
void displayMotorcycleDetails(Motorcycle *motorcycle, int position) {
    if (motorcycle) {
        printf("\nPosition: %d\n", position);
        printf("Name: [%s]\n", motorcycle->motorcycle_name);
        printf("Brand: [%s]\n", motorcycle->motorcycle_brand);
        printf("Year: [%d]\n", motorcycle->year_model);
        printf("Plate: [%s]\n", motorcycle->plate_number);
    }
}

void displayFirstNodes() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\n--- First Nodes ---\n");
    Motorcycle *temp = head;
    int position = 0;
    while (temp != NULL) {
        displayMotorcycleDetails(temp, position);
        temp = temp->next;
        position++;
        
        if (position >= 5) {
            printf("(Showing first 5 nodes. Use Display option to see all.)\n");
            break;
        }
    }
}

void displayLastNodes() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Motorcycle *temp = head;
    int total_nodes = 0;
    while (temp != NULL) {
        temp = temp->next;
        total_nodes++;
    }

    temp = head;
    for (int i = 0; i < total_nodes - 1; i++) {
        temp = temp->next;
    }

    printf("\n--- Last Nodes ---\n");
    int position = total_nodes - 1;
    int count = 0;
    while (temp != NULL && count < 5) {
        displayMotorcycleDetails(temp, position);
        temp = temp->prev;
        position--;
        count++;
    }

    if (count >= 5) {
        printf("(Showing last 5 nodes. Use Display Reverse option to see all.)\n");
    }
}

void displaySpecificNode(int position) {
    Motorcycle *found = retrieve(position);
    if (found) {
        printf("\n--- Retrieved Motorcycle ---\n");
        displayMotorcycleDetails(found, position);
    } else {
        printf("Invalid position!\n");
    }
}

void searchAndDisplayMotorcycle(char name[]) {
    Motorcycle *found = search(name);
    if (found) {
        printf("\n--- Motorcycle Found ---\n");
        
        Motorcycle *temp = head;
        int position = 0;
        while (temp != NULL) {
            if (temp == found) break;
            temp = temp->next;
            position++;
        }
        
        displayMotorcycleDetails(found, position);
    } else {
        printf("Motorcycle not found.\n");
    }
}

void checkListEmpty() {
    if (empty()) {
        printf("List is empty.\n");
        printf("Total Nodes: 0\n");
    } else {
        printf("List is not empty.\n");
        
        Motorcycle *temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        printf("Total Nodes: %d\n", count);
    }
}