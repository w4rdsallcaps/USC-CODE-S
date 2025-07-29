#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    int number_of_out_degree;
    struct Node** out_degree;
} Node;

typedef struct {
    int max_vertices;
    Node** vertices;
} Graph;

Node* createNode(int value);
Graph* createGraph(int vertices);
void adjustOutDegree(Node* node);
void addEdge(Graph* ptr_graph, int src, int dst);
void printGraph(Graph* ptr_graph);
void freeGraph(Graph* ptr_graph);

int main()
{
    Graph* graph = createGraph(5);
    if (graph == NULL)
    {
        printf("Failed to create graph\n");
        return 1;
    }

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    freeGraph(graph);

    return 0;
}

Node* createNode(int value)
{
    Node* ptr_node = (Node*)malloc(sizeof(Node));
    if (ptr_node == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    ptr_node->value = value;
    ptr_node->number_of_out_degree = 0;
    ptr_node->out_degree = NULL;

    return ptr_node;
}

Graph* createGraph(int vertices)
{
    Graph* ptr_graph = (Graph*)malloc(sizeof(Graph));
    if (ptr_graph == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    ptr_graph->max_vertices = vertices;
    ptr_graph->vertices = (Node**)malloc(vertices * sizeof(Node*));
    if (ptr_graph->vertices == NULL)
    {
        printf("Memory allocation failed\n");
        free(ptr_graph);
        return NULL;
    }

    for (int i = 0; i < vertices; i++)
    {
        ptr_graph->vertices[i] = createNode(i);
    }

    return ptr_graph;
}

void adjustOutDegree(Node* node)
{
    Node** temp = (Node**)realloc(node->out_degree, (node->number_of_out_degree + 1) * sizeof(Node*));
    if (temp == NULL)
    {
        printf("Memory reallocation failed\n");
        return;
    }
    node->out_degree = temp;
    node->number_of_out_degree += 1;
}

void addEdge(Graph* ptr_graph, int src, int dst)
{
    if (src < 0 || src >= ptr_graph->max_vertices ||
        dst < 0 || dst >= ptr_graph->max_vertices)
    {
        printf("Invalid vertex indices\n");
        return;
    }

    Node* src_node = ptr_graph->vertices[src];
    adjustOutDegree(src_node);
    src_node->out_degree[src_node->number_of_out_degree - 1] = ptr_graph->vertices[dst];

    Node* dst_node = ptr_graph->vertices[dst];
    adjustOutDegree(dst_node);
    dst_node->out_degree[dst_node->number_of_out_degree - 1] = ptr_graph->vertices[src];
}

void printGraph(Graph* ptr_graph)
{
    printf("Graph Structure:\n");
    for (int i = 0; i < ptr_graph->max_vertices; i++)
    {
        Node* node = ptr_graph->vertices[i];
        printf("Vertex %d (value: %d) connects to: ", i, node->value);

        if (node->number_of_out_degree == 0)
        {
            printf("No connections");
        }
        else {
            for (int j = 0; j < node->number_of_out_degree; j++)
            {
                printf("%d ", node->out_degree[j]->value);
            }
        }
        printf("\n");
    }
}

void freeGraph(Graph* ptr_graph) {
    if (ptr_graph == NULL) return;

    for (int i = 0; i < ptr_graph->max_vertices; i++) {
        if (ptr_graph->vertices[i] != NULL) {
            free(ptr_graph->vertices[i]->out_degree);
            free(ptr_graph->vertices[i]);
        }
    }

    free(ptr_graph->vertices);
    free(ptr_graph);
}
Write to Dale Ryoko Jose Cantago
