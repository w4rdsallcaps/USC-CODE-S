#include <stdio.h>      // For input/output functions
#include <stdlib.h>     // For dynamic memory allocation
#include <string.h>     // For string operations if needed (not used here)

#define MAX_VERTICES 100  // Maximum number of vertices supported

// Node structure for the adjacency list
typedef struct Node {
    int vertex;             // Stores the index of the vertex
    struct Node* next;      // Pointer to the next adjacent node
} Node;

// Graph structure that holds adjacency list and matrix
typedef struct Graph {
    int numVertices;        // Number of vertices in the graph
    Node** adjLists;        // Array of linked lists (adjacency list)
    int** adjMatrix;        // 2D array representing the adjacency matrix
} Graph;

// Queue structure for BFS traversal
typedef struct Queue {
    int items[MAX_VERTICES];  // Array to store items
    int front, rear;          // Front and rear indices for the queue
} Queue;

// Stack structure for DFS traversal
typedef struct Stack {
    int items[MAX_VERTICES];  // Array to store items
    int top;                  // Index of the top element
} Stack;

// Function to create a new adjacency list node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Allocate memory for new node
    newNode->vertex = vertex;                     // Set the vertex value
    newNode->next = NULL;                         // Initialize next to NULL
    return newNode;                               // Return the created node
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));   // Allocate memory for the graph
    graph->numVertices = vertices;                  // Set number of vertices

    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*)); // Allocate memory for adjacency lists
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;                  // Initialize all list heads to NULL

    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));  // Allocate memory for adjacency matrix
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int)); // Allocate each row
        for (int j = 0; j < vertices; j++)
            graph->adjMatrix[i][j] = 0;             // Initialize all cells to 0
    }

    return graph;                                   // Return the created graph
}

// Function to add an undirected edge between src and dest
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);               // Create node for dest
    newNode->next = graph->adjLists[src];           // Insert at beginning of src list
    graph->adjLists[src] = newNode;                 // Update head

    newNode = createNode(src);                      // Create node for src
    newNode->next = graph->adjLists[dest];          // Insert at beginning of dest list
    graph->adjLists[dest] = newNode;                // Update head

    graph->adjMatrix[src][dest] = 1;                // Set matrix[src][dest] to 1
    graph->adjMatrix[dest][src] = 1;                // Set matrix[dest][src] to 1 (undirected)
}

// Function to remove an edge between src and dest
void removeEdge(Graph* graph, int src, int dest) {
    // Remove dest from src's adjacency list
    Node *temp = graph->adjLists[src], *prev = NULL;
    while (temp != NULL && temp->vertex != dest) {  // Find the node
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {                             // If found
        if (prev == NULL)                           // If it's the first node
            graph->adjLists[src] = temp->next;      // Update head
        else
            prev->next = temp->next;                // Skip the node
        free(temp);                                 // Free memory
    }

    // Remove src from dest's adjacency list (undirected graph)
    temp = graph->adjLists[dest];
    prev = NULL;
    while (temp != NULL && temp->vertex != src) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev == NULL)
            graph->adjLists[dest] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }

    graph->adjMatrix[src][dest] = 0;                // Update matrix to 0
    graph->adjMatrix[dest][src] = 0;
}

// Function to display the adjacency list
void displayAdjList(Graph* graph) {
    printf("\nAdjacency List:\n");
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];            // Traverse each list
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);         // Print connected vertex
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to display the adjacency matrix
void displayAdjMatrix(Graph* graph) {
    printf("\nAdjacency Matrix:\n    ");
    for (int i = 0; i < graph->numVertices; i++)
        printf("%2d ", i);                          // Print column headers
    printf("\n");

    for (int i = 0; i < graph->numVertices; i++) {
        printf("%2d: ", i);                          // Print row index
        for (int j = 0; j < graph->numVertices; j++)
            printf("%2d ", graph->adjMatrix[i][j]); // Print cell value
        printf("\n");
    }
}

// Function to free all dynamically allocated memory
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);                           // Free each node
        }
    }
    free(graph->adjLists);                          // Free list array

    for (int i = 0; i < graph->numVertices; i++)
        free(graph->adjMatrix[i]);                  // Free each matrix row
    free(graph->adjMatrix);                         // Free matrix array

    free(graph);                                    // Free the graph struct
}

// --------------------- BFS SECTION ----------------------

// Function to create a queue for BFS
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));       // Allocate memory
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if queue is empty
int isQueueEmpty(Queue* q) {
    return q->front == -1;
}

// Add item to queue
void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1)
        return;
    if (isQueueEmpty(q))
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// Remove item from queue
int dequeue(Queue* q) {
    if (isQueueEmpty(q))
        return -1;
    int item = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return item;
}

// Perform BFS traversal from a start vertex
void bfs(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};                // Track visited vertices
    Queue* q = createQueue();                       // Create queue

    visited[startVertex] = 1;                       // Mark start as visited
    enqueue(q, startVertex);                        // Enqueue start vertex

    printf("\nBFS starting from vertex %d:\n", startVertex);

    while (!isQueueEmpty(q)) {
        int currentVertex = dequeue(q);             // Get next vertex
        printf("%d ", currentVertex);               // Print it

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {                              // Traverse its neighbors
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {              // If not visited
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);              // Enqueue neighbor
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(q);                                        // Free queue
}

// --------------------- DFS SECTION ----------------------

// Create stack for DFS
Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

// Check if stack is empty
int isStackEmpty(Stack* s) {
    return s->top == -1;
}

// Push item to stack
void push(Stack* s, int value) {
    if (s->top == MAX_VERTICES - 1)
        return;
    s->items[++s->top] = value;
}

// Pop item from stack
int pop(Stack* s) {
    if (isStackEmpty(s))
        return -1;
    return s->items[s->top--];
}

// Perform DFS traversal from a start vertex
void dfs(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};                // Track visited nodes
    Stack* s = createStack();                       // Create stack

    push(s, startVertex);                           // Start DFS with start vertex

    printf("\nDFS starting from vertex %d:\n", startVertex);

    while (!isStackEmpty(s)) {
        int currentVertex = pop(s);                 // Get vertex from stack

        if (!visited[currentVertex]) {              // If not visited
            visited[currentVertex] = 1;             // Mark visited
            printf("%d ", currentVertex);           // Print it

            Node* temp = graph->adjLists[currentVertex];
            while (temp) {                          // Visit all neighbors
                int adjVertex = temp->vertex;
                if (!visited[adjVertex])
                    push(s, adjVertex);             // Push unvisited neighbor
                temp = temp->next;
            }
        }
    }
    printf("\n");
    free(s);                                        // Free stack
}

// --------------------- MAIN FUNCTION ----------------------

int main() {
    int numVertices = 6;                            // Define number of vertices
    Graph* graph = createGraph(numVertices);        // Create graph

    // Add edges to graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    // Display adjacency structures
    displayAdjList(graph);
    displayAdjMatrix(graph);

    // Perform traversals
    bfs(graph, 0);                                   // Breadth-first search
    dfs(graph, 0);                                   // Depth-first search

    // Remove an edge and show updated graph
    printf("\nRemoving edge between 1 and 4...\n");
    removeEdge(graph, 1, 4);

    // Display updated structures
    displayAdjList(graph);
    displayAdjMatrix(graph);

    bfs(graph, 0);                                   // Breadth-first search
    dfs(graph, 0);                                   // Depth-first search

    // Free memory
    freeGraph(graph);

    return 0;
}
