//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.
/*
Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// LCA function (your logic)
struct Node* LCA(struct Node* root, int n1, int n2) {
    while(root != NULL) {
        if(n1 < root->data && n2 < root->data)
            root = root->left;
        else if(n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert elements
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    int n1 = 5, n2 = 15;

    struct Node* lca = LCA(root, n1, n2);

    if(lca != NULL)
        printf("LCA of %d and %d is: %d\n", n1, n2, lca->data);
    else
        printf("LCA not found\n");

    return 0;
}