//Check whether a given binary tree is symmetric around its center.
/*
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int isMirror(struct Node* t1, struct Node* t2) {
    if(t1 == NULL && t2 == NULL)
        return 1;

    if(t1 == NULL || t2 == NULL)
        return 0;

    if(t1->data != t2->data)
        return 0;

    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

int isSymmetric(struct Node* root) {
    if(root == NULL)
        return 1;
    return isMirror(root->left, root->right);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);

    root->left->left = newNode(3);
    root->left->right = newNode(4);

    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if(isSymmetric(root))
        printf("Tree is symmetric\n");
    else
        printf("Tree is not symmetric\n");

    return 0;
}