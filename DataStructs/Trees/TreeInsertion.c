#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* createTree(Node* root, int* arr, int n, int i) {
    if (i < n) {
        root = createNode(arr[i]);
        root->left = createTree(root->left, arr, n, 2 * i + 1);
        root->right = createTree(root->right, arr, n, 2 * i + 2);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 6, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = createTree(root, arr, n, 0);
    inorder(root);
    return 0;
}