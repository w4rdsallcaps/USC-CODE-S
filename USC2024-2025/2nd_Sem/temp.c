#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Return 0 for success and 1 for error to simplify the use of if statements
#define c_assert(e) ((e) ? (0) : (fprintf(stderr, "%s, %d: assertion '%s' failed\n", __FILE__, __LINE__, #e), 1))

//Structs

typedef struct
{
    char *title;
    char *altTitle;

    char *author;
    char *translator;
} Manga;

typedef struct Node
{
    Manga *manga;

    struct Node *next;
    struct Node *prev;
    
    struct Node **start;
    struct Node **end;
} Node;

//Manga Functions Definition
Manga *createManga(char[], char[], char[], char[]);
void deleteManga(Manga*);
Manga *populateManga();

//Node Functions Definition
Node *createNode(int);
void deleteList(Node*);

//Other Functions
void display(Node*);
void append(Node*, Node*);
void preAppend(Node*, Node*);
void insert(Node*, Node*, int);
void removeNode(Node*, int);
void edit(Node*, int);
void reverseDisplay(Node*);

//Cleaner and extra functions
void reallocationCheck(char *chrptr, int size);
void scrclr();
void pause();

int main()
{
    Node *list = NULL, *container = NULL;
    int choice = -1, reversed = 0, n_options = 2, exit_program = 0;
    char input[10]; //will act as a buffer as i am having buffer '\n' troubles

    while (1)
    {
        //Display options
        if (list != NULL)
        { 
            printf("[1] display nodes\n");
            printf("[2] display nodes in reverse\n");
            printf("[3] append node\n");
            printf("[4] pre-append node\n");
            printf("[5] insert node\n");
            printf("[6] remove node\n");
            printf("[7] edit node\n");
            printf("[8] Exit Program\n");
            
            n_options = 8;
        }
        else
        {
            printf("[1] createNode\n");
            printf("[2] Exit Program\n");
            n_options = 2;
        }

        printf("Choice:\t");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &choice);
        input[0] = '\0';

        if (choice < 1 || choice > n_options)
        {
            choice = -1;
            continue;
        }

        switch (choice)
        {
            case 1:
                if (list == NULL) list = createNode(1);
                else display(list);
                break;
            
            case 2:
                if (list == NULL) exit_program = 1;
                else reverseDisplay(list);
                break;

            case 3:
                container = createNode(0);
                append(list, container);
                container = NULL;
                break;

            case 4:
                container = createNode(0);
                preAppend(list, container);
                container = NULL;
                break;

            case 5:
                printf("What Index Would You Like to Insert a New Node: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%d", &choice);
                input[0] = '\0';
                container = createNode(0);
                insert(list, container, choice);
                container = NULL;
                break;

            case 6:
                printf("What Index Would You Like to Remove the Node: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%d", &choice);
                input[0] = '\0';

                if (list == *(list->start) && list == *(list->end))
                {
                    deleteManga(list->manga);
                    free(list->start);
                    free(list->end);
                    free(list);

                    list = NULL;
                    break;
                }

                removeNode(list, choice);
                break;

            case 7:
                printf("What Index Would You Like to Edit the Node: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%d", &choice);
                input[0] = '\0';
                edit(list, choice);
                break;

            case 8:
                exit_program = 1;
                break;

            default:
                printf("WARNING: IF YOU SOMEHOW ENTERED THIS THEN THE PROGRAM IS BROKEN\nYOU SHOULD NOT BE ABLE TO ENTER\n");
                exit_program = 1;
                break;
        }

        pause();
        scrclr();

        if (exit_program) break;
    }

    if (list != NULL)
    {
        deleteList(list);
    }
    return 0;
}

//Manga Functions Process
Manga *createManga(char title[], char altTitle[], char author[], char translator[])
{
    //Memory Allocation for Object
    Manga *manga = (Manga*) malloc(sizeof(Manga));

    //Memory Allocation for Members
    //+1 is REQUIRED for null terminator
    manga->title = (char*) malloc(strlen(title) * sizeof(char) + 1);
    manga->altTitle = (char*) malloc(strlen(altTitle) * sizeof(char) + 1);
    manga->author = (char*) malloc(strlen(author) * sizeof(char) + 1);
    manga->translator = (char*) malloc(strlen(translator) * sizeof(char) + 1);

    //Value Allocation
    strcpy(manga->title, title);
    strcpy(manga->altTitle, altTitle);
    strcpy(manga->author, author);
    strcpy(manga->translator, translator);

    //Assertation Check
    //strcmp returns 0 if equal otherwise +-1 to the side that is larger
    if (c_assert(strcmp(manga->title, title) == 0)) exit(134);
    if (c_assert(strcmp(manga->altTitle, altTitle) == 0)) exit(134);
    if (c_assert(strcmp(manga->author, author) == 0)) exit(134);
    if (c_assert(strcmp(manga->translator, translator) == 0)) exit(134);

    return manga;
}

void deleteManga(Manga *manga)
{
    //Check incase of memory corruption
    if (c_assert(manga != NULL)) exit(134);

    free(manga->title);
    manga->title = NULL;

    free(manga->altTitle);
    manga->altTitle = NULL;

    free(manga->author);
    manga->author = NULL;

    free(manga->translator);
    manga->translator = NULL;

    free(manga);
    manga = NULL;
    if (c_assert(manga == NULL)) exit(134);
}

Manga *populateManga()
{
    Manga *manga = NULL;
    char title[100], altTitle[100], author[100], translator[100];

    printf("Enter Title             : ");
    fgets(title, 100, stdin);

    printf("Enter alternate title   : ");
    fgets(altTitle, 100, stdin);
 
    printf("Enter author            : ");
    fgets(author, 100, stdin);
    
    printf("Enter translator        : ");
    fgets(translator, 100, stdin);

    fflush(stdin); //Ensures No Errors with inputs

    title[strcspn(title, "\n")] = '\0';
    altTitle[strcspn(altTitle, "\n")] = '\0';
    author[strcspn(author, "\n")] = '\0';
    translator[strcspn(translator, "\n")] = '\0';

    manga = createManga(title, altTitle, author, translator);

    return manga;
}

//Node Functions Process
Node *createNode(int first)
{
    if (c_assert(0 <= first && first <= 1)) exit(134);

    Node *node = (Node*) malloc(sizeof(Node));
    Manga *manga = populateManga();

    if (c_assert(node != NULL)) exit(134);
    if (c_assert(manga != NULL)) exit(134);

    node->manga = manga;

    //connectors
    node->next = NULL;
    node->prev = NULL;

    if (first == 1)
    {
        node->start = (Node**) malloc(sizeof(Node*));
        node->end = (Node**) malloc(sizeof(Node*));

        if (c_assert(node->start != NULL)) exit(134);
        if (c_assert(node->end != NULL)) exit(134);

        *(node->start) = node;
        *(node->end) = node;
    }
    else
    {
        node->start = NULL;
        node->end = NULL;
    }


    if (c_assert(node->next == NULL)) exit(134);
    if (c_assert(node->prev == NULL)) exit(134);

    return node;
}

//Did not fulfill 2 minimum assertation
void deleteList(Node *list)
{
    if (c_assert(list != NULL)) exit(134);
    Node *current = *(list->start), *next;

    if (list->start != NULL) free(list->start);
    if (list->end != NULL) free(list->end);

    while (current != NULL)
    {
        next = current->next;

        deleteManga(current->manga);

        free(current);

        current = next;
    }

}

void display(Node *list)
{
    if (c_assert(list != NULL)) exit(134);
    Node *current = NULL;
    Manga *manga = NULL;
    int displayBorder = 50;

    if (list->start != NULL)
    {
        current = *(list->start);
    }
    else
    {
        current = list;
    }

    while (current != NULL)
    {
        if (c_assert(list->manga != NULL))
        {
            printf("LOG: This node has no Manga\n");
            current = current->next;
            continue;
        }

        manga = current->manga;

        //Have to seperate for visual improvement
        for (int i = 0; i < displayBorder; i++) printf("%c", 205);
        printf("\n");
        printf("Title               : %s\n", manga->title);
        printf("Alternative Title   : %s\n", manga->altTitle);
        printf("Author              : %s\n", manga->author);
        printf("Translator          : %s\n", manga->translator);
        for (int i = 0; i < displayBorder; i++) printf("%c", 205);
        printf("\n");
        
        manga = NULL;
        current = current->next;
    }
}

void append(Node *list, Node *node)
{
    if (c_assert(list != NULL)) return;
    if (c_assert(node != NULL)) return;
    if (c_assert(list->end != NULL)) return;
    
    Node *ptrNode = *(list->end);
    
    *(list->end) = node;
    node->end = list->end;
    node->start = list->start;
    
    ptrNode->next = node;
    node->prev = ptrNode;
}

void preAppend(Node *list, Node *node)
{
    if (c_assert(list != NULL)) return;
    if (c_assert(node != NULL)) return;
    if (c_assert(list->start != NULL)) return;


    Node *ptrNode = *(list->start);

    *(list->start) = node;
    node->start = list->start;
    node->end = list->end;

    ptrNode->prev = node;
    node->next = ptrNode;
}

void insert(Node *list, Node *node, int index)
{
    if (c_assert(list != NULL)) return;
    if (c_assert(node != NULL)) return;
    if (c_assert(list->start != NULL)) return;

    Node *ptrNode = *(list->start), *prev = NULL;

    for (int i = 0; i < index; i++)
    {
        prev = ptrNode;
        ptrNode = ptrNode->next;
    }

    node->prev = prev;
    node->next = ptrNode;

    //Prev Value
    if (prev != NULL) prev->next = node;
    else *(list->start) = node;

    //Next Value
    if (ptrNode != NULL) ptrNode->prev = node;
    else *(list->end) = node;

    node->start = list->start;
    node->end = list->end;
}

void removeNode(Node *list, int index)
{
    if (c_assert(list != NULL)) return;
    if (c_assert(list->start != NULL)) return;

    Node *ptrNode = *(list->start), *prev, *next;

    for (int i = 0; i < index; i++)
    {
        if (ptrNode == NULL) return;
        ptrNode = ptrNode->next;
    }

    prev = ptrNode->prev;
    next = ptrNode->next;

    if (prev != NULL) prev->next = next;

    if (next != NULL) next->prev = prev;

    if (ptrNode == *(ptrNode->start)) *ptrNode->start = next;

    if (ptrNode == *(ptrNode->end)) *ptrNode->end = prev;

    deleteManga(ptrNode->manga);
    free(ptrNode);
    
}

void edit(Node *list, int index)
{
    if (c_assert(list != NULL)) return;
    if (c_assert(list->start != NULL)) return;

    Node *ptrNode = *(list->start);
    Manga *manga = NULL;
    char title[100], altTitle[100], author[100], translator[100], *container;

    for (int i = 0; i < index; i++)
    {
        if (ptrNode == NULL) return;
        ptrNode = ptrNode->next;
    }

    manga = ptrNode->manga;

    printf("Enter Title             : %s %c ", manga->title, 175);
    fgets(title, 100, stdin);

    printf("Enter alternate title   : %s %c ", manga->altTitle, 175);
    fgets(altTitle, 100, stdin);

    printf("Enter author            : %s %c ", manga->author, 175);
    fgets(author, 100, stdin);

    printf("Enter translator        : %s %c ", manga->translator, 175);
    fgets(translator, 100, stdin);

    fflush(stdin); //Ensures No Errors with inputs

    title[strcspn(title, "\n")] = '\0';
    altTitle[strcspn(altTitle, "\n")] = '\0';
    author[strcspn(author, "\n")] = '\0';
    translator[strcspn(translator, "\n")] = '\0';

    /*
      Made a function to compress
      Essentially Realloc returns a new memory block for the correct size while does not modify
      the original continents should there be an error and will instead return NULL
    */
    reallocationCheck(manga->title, strlen(title) * sizeof(char) + 1);
    reallocationCheck(manga->altTitle, strlen(altTitle) * sizeof(char) + 1);
    reallocationCheck(manga->author, strlen(author) * sizeof(char) + 1);
    reallocationCheck(manga->translator, strlen(translator) * sizeof(char) + 1);

    strcpy(manga->title, title);
    strcpy(manga->altTitle, altTitle);
    strcpy(manga->author, author);
    strcpy(manga->translator, translator);

    if (c_assert(strcmp(manga->title, title) == 0)) exit(134);
    if (c_assert(strcmp(manga->altTitle, altTitle) == 0)) exit(134);
    if (c_assert(strcmp(manga->author, author) == 0)) exit(134);
    if (c_assert(strcmp(manga->translator, translator) == 0)) exit(134);
}

void reverseDisplay(Node *list)
{
    if (c_assert(list != NULL)) exit(134);
    Node *current = NULL;
    Manga *manga = NULL;
    int displayBorder = 50;

    if (list->end != NULL) current = *(list->end);
    else current = list;

    while (current != NULL)
    {
        if (c_assert(list->manga != NULL))
        {
            printf("LOG: This node has no Manga\n");
            current = current->prev;
            continue;
        }

        manga = current->manga;

        //Seperation for visualization
        for (int i = 0; i < displayBorder; i++) printf("%c", 205);
        printf("\n");

        printf("Title               : %s\n", manga->title);
        printf("Alternative Title   : %s\n", manga->altTitle);
        printf("Author              : %s\n", manga->author);
        printf("Translator          : %s\n", manga->translator);

        for (int i = 0; i < displayBorder; i++) printf("%c", 205);
        printf("\n");
        
        manga = NULL;
        current = current->prev;
    }
}

//Cleaner and extra functions
void reallocationCheck(char *chrptr, int size)
{
    char *container;

    if ((container = realloc(chrptr, size)) != NULL)
    {
        chrptr = container;
    }
}

void scrclr()
{
    //Allow to work on both window and linux OS
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause()
{
    #ifdef _WIN32
        system("pause");
    #else
        system("read -p \"Press Enter to continue...\"");
    #endif
}