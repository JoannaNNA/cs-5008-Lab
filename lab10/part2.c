#include<stdio.h>
#include<stdlib.h>


#define MAX_SIZE 100


int linearProbe(int hashTable[], int size, int key) {
    int index = key % size;
    for (int i=0; i<size; i++) {
        int probeIndex = (index + i) % size;
        if (hashTable[probeIndex] == -1) {
            return probeIndex;
        }
    }
    return -1;
}


int quadraticProbe(int hashTable[], int size, int key) {
    int index = key % size;
    for (int i=0; i<size; i++) {
        int probeIndex = (index + i*i) % size;
        if (hashTable[probeIndex] == -1) {
            return probeIndex;
        }
    }
    return -1;
}


int doubleHashProbe(int hashTable[], int size, int key) {
    int h1 = key % size;
    int h2 = 7 - (key % 7);
    for (int i=0; i<size; i++) {
        int probeIndex = (h1 + i * h2) % size;
        if (hashTable[probeIndex] == -1) {
            return probeIndex;
        }
    }
    return -1;
}

void insert(int hashTable[], int size, int key, int (*probeFunction)(int[], int, int)) {
    int index = probeFunction(hashTable, size, key);
    if (index != -1) {
        hashTable[index] = key;
    }
}

void printTable(int hashTable[], int size) {
    for (int i=0; i<size; i++) {
        if (hashTable[i] != -1) {
            printf("Slot[%d]: %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int size, n, key, probeOption;

    printf("Hash Table Size: ");
    scanf("%d", &size);

    int hashTable[MAX_SIZE];
    for (int i=0; i<size; i++) {
        hashTable[i] = -1;  
    }

    printf("Number of values: ");
    scanf("%d", &n);

    printf("Choose Probing: 1 for Linear, 2 for Quadratic, 3 for Double Hashing: ");
    scanf("%d", &probeOption);

    printf("Input Values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        switch (probeOption) {
            case 1:
                insert(hashTable, size, key, linearProbe);
                break;
            case 2:
                insert(hashTable, size, key, quadraticProbe);
                break;
            case 3:
                insert(hashTable, size, key, doubleHashProbe);
                break;
            default:
                printf("Invalid option!\n");
                return -1;
        }
    }

    printf("The table:\n");
    printTable(hashTable, size);

    return 0;
}
