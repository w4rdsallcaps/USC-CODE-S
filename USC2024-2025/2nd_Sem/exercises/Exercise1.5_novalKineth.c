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

Motorcycle *createMotorcycle(char name[], char brand[], int year, char plate[]);
void getUserInput(char name[], char brand[], int *year, char plate[]);
void prepend(char name[], char brand[], int year, char plate[]);
void append(char name[], char brand[], int year, char plate[]);
void insert(int position, char name[], char brand[], int year, char plate[]);
void removeNode(int position);
void edit(int position, char name[], char brand[], int year, char plate[]);
void display();
void displayReverse();

int main() {
    int choice;
    do {
        printf("\nChoose an action:");
        printf("\n1.) Append\n2.) Prepend\n3.) Insert at Position\n4.) Edit\n5.) Remove\n6.) Display\n7.) Display Reverse\n8.) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        char name[100], brand[100], plate[100];
        int year, position;

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
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 8);

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
    while (temp != NULL) {
        printf("\nName: [%s]\nBrand: [%s]\nYear: [%d]\nPlate: [%s]\n", temp->motorcycle_name, temp->motorcycle_brand, temp->year_model, temp->plate_number);
        temp = temp->next;
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
    while (temp != NULL) {
        printf("\nName: [%s]\nBrand: [%s]\nYear: [%d]\nPlate: [%s]\n", temp->motorcycle_name, temp->motorcycle_brand, temp->year_model, temp->plate_number);
        temp = temp->prev; 
    }
}
