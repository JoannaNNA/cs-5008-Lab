#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return(newNode);
}

// Function to print the level order traversal a tree
void printLevelOrder(struct node* root) {
    // Base Case
    if(root == NULL)
        return;

    // Create an empty queue for level order traversal
    struct node **queue = (struct node **)malloc(sizeof(struct node*)*100);
    int rear = 0;
    int front = 0;
  
    // Enqueue Root and initialize height
    queue[rear++] = root;

    while(rear != front) {
        // Print front of queue and remove it from queue
        struct node *temp_node = queue[front++];
        printf("%d ", temp_node->data);

        //Enqueue left child
        if(temp_node->left)
            queue[rear++] = temp_node->left;

        //Enqueue right child
        if(temp_node->right)
            queue[rear++] = temp_node->right;
    }
    free(queue);
}

// Main function
int main() {
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->left->left->left = createNode(8);
    root->left->left->right = createNode(9);
    root->left->right->left = createNode(10);
    root->left->right->right = createNode(11);
    root->right->left->left = createNode(12);
    root->right->left->right = createNode(13);
    root->right->right->left = createNode(14);
    root->right->right->right = createNode(15);

    printf("Breadth First traversal (or Level Order traversal) of binary tree is \n");
    printLevelOrder(root);

    return 0;
}
