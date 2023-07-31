#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *createNode(int value) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->value = value;
    newnode->next = NULL;
    return newnode;
}

void insert(struct node **hashTable, int size, int value) {
    int index = value % size;
    struct node *newnode = createNode(value);

    
    if (!hashTable[index]) {
        hashTable[index] = newnode;
    } else {
       
        struct node *temp = hashTable[index];
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void printTable(struct node **hashTable, int size) {
    for (int i = 0; i < size; i++) {
        struct node *temp = hashTable[i];
        printf("Chain[%d] -> ", i);
        while (temp) {
            printf("%d -> ", temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int size, n, value;

    printf("Chain Size: ");
    scanf("%d", &size);

    struct node **hashTable = (struct node **)calloc(size, sizeof(struct node *));

    printf("Number of values: ");
    scanf("%d", &n);

    printf("Input Values: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(hashTable, size, value);
    }

    printf("The table:\n");
    printTable(hashTable, size);

    return 0;
}
