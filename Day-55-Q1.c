//Print the nodes visible when the binary tree is viewed from the right side.
/*
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void rightView(struct Node* root) {
    if(root == NULL) return;

    struct Node* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;

    while(front < rear) {
        int size = rear - front;

        for(int i = 0; i < size; i++) {
            struct Node* temp = q[front++];

            if(i == size - 1)
                printf("%d ", temp->data);

            if(temp->left != NULL)
                q[rear++] = temp->left;
            if(temp->right != NULL)
                q[rear++] = temp->right;
        }
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(4);

    printf("Right View: ");
    rightView(root);

    return 0;
}