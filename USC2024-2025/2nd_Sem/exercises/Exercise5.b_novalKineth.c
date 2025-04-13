#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[100];
    char service[100];
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(char name[], char service[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->service, service);
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Added %s to the queue for '%s' service.\n", name, service);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. No one to serve.\n");
        return;
    }

    Node* temp = front;
    printf("Now serving %s for '%s' service.\n", temp->name, temp->service);

    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Current queue:\n");
    Node* temp = front;
    int position = 1;
    while (temp != NULL) {
        printf("%d. %s - %s\n", position++, temp->name, temp->service);
        temp = temp->next;
    }
}


void printMenu() {
    printf("\n========== GOVERNMENT SERVICE QUEUE SYSTEM ==========\n");
    printf("1. Enqueue (Join Queue)\n");
    printf("2. Dequeue (Serve Next)\n");
    printf("3. View Queue\n");
    printf("4. Exit\n");
    printf("=====================================================\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char name[100];
    int serviceOption;
    char* services[] = {"ID Renewal", "Passport Application", "Police Clearance"};

    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter your name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; 

                printf("Select a service:\n");
                for (int i = 0; i < 3; i++) {
                    printf("  %d. %s\n", i + 1, services[i]);
                }
                printf("Choice: ");
                scanf("%d", &serviceOption);
                getchar();

                if (serviceOption < 1 || serviceOption > 3) {
                    printf("Invalid service option.\n");
                } else {
                    enqueue(name, services[serviceOption - 1]);
                }
                break;

            case 2:
                dequeue();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                printf("Exiting. Have a nice day!\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
