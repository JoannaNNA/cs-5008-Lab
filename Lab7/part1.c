#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return(newNode);
}

void printPreorder(struct node* node) {
    if (node == NULL)
        return;
 
    printf("%d ", node->data);
    printPreorder(node->left);  
    printPreorder(node->right);
}

void printInorder(struct node* node) {
    if (node == NULL)
        return;
 
    printInorder(node->left);
    printf("%d ", node->data);  
    printInorder(node->right);
}

void printPostorder(struct node* node) {
    if (node == NULL)
        return;
 
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(4);
    root->left->left->left = createNode(8);
    root->left->left->right = createNode(9);
    root->left->right = createNode(5);
    root->left->right->left = createNode(10);
    root->left->right->right = createNode(11);
    root->right = createNode(3);
    root->right->left = createNode(6);
    root->right->left->left = createNode(12);
    root->right->left->right = createNode(13);
    root->right->right = createNode(7);
    root->right->right->left = createNode(14);
    root->right->right->right = createNode(15);

    printf("Preorder traversal of binary tree is \n");
    printPreorder(root);

    printf("\nInorder traversal of binary tree is \n");
    printInorder(root);

    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);

    return 0;
}
