//Implement a hash table using quadratic probing with formula:
/*
h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.
*/
#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash table is full, cannot insert %d\n", key);
}

void search(int table[], int m, int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key, m) + i * i) % m;

        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }
        i++;
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, n;
    scanf("%d", &m);   // size of hash table
    scanf("%d", &n);   // number of operations

    int table[m];

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char operation[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0) {
            insert(table, m, key);
        } else if (strcmp(operation, "SEARCH") == 0) {
            search(table, m, key);
        }
    }

    return 0;
}