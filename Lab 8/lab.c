#include<stdio.h>
#include<stdlib.h>

// Define the structure for an adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Function to create a new adjacency list node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge in an undirected graph
void addEdge(Node** adjList, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// Function to print the adjacency list
void printGraph(Node** adjList, int vertices) {
    for(int v = 0; v < vertices; v++) {
        Node* temp = adjList[v];
        printf("\n %d: ", v);
        while(temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL");
    }
    printf("\n");
}

int main() {
    int vertices = 4;

    // Adjacency matrix
    int adjMatrix[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 0, 1, 0}
    };

    // Print adjacency matrix
    printf("Adjacency Matrix:\n");
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    // Adjacency list
    Node* adjList[vertices];

    // Initialize each adjacency list as NULL
    for(int i = 0; i < vertices; i++)
        adjList[i] = NULL;

    // Add edges
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 0);
    addEdge(adjList, 3, 2);

    printGraph(adjList, vertices);

    return 0;
}
