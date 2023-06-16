#include <stdio.h>
#include <stdlib.h>

// Define the structure for linked list node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new node with given data
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (!newNode)
    {
        printf("Memory error\n");
        exit(0);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Function to add a node at the end of the Linked List
void addNode(Node **head, int data)
{
    Node *newNode = createNode(data);
    Node *temp = *head;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    // Traverse to the end of the list
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print the linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Recursive function to reverse the linked list
Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest = reverseList(head->next);
    head->next->next = head;

    head->next = NULL;

    return rest;
}

// Driver code
int main()
{
    Node *head = NULL;
    int size, data;

    printf("Input list size: ");
    scanf("%d", &size);

    printf("Input elements of the array:\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data);
        addNode(&head, data);
    }

    printf("The list:\n");
    printList(head);

    head = reverseList(head);

    printf("The reversed list:\n");
    printList(head);

    return 0;
}