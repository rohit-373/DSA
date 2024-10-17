#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int diameter = INT_MIN;

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* createTree(Node* root, int* arr, int n, int i) {
    if (i < n) {
        root = createNode(arr[i]);
        root->left = createTree(root->left, arr, n, 2*i+1);
        root->right = createTree(root->right, arr, n, 2*i+2);
    }
    return root;
}

int calcHeight(Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = calcHeight(root->left);
    int rightHeight = calcHeight(root->right);
    diameter = (diameter > (leftHeight + rightHeight)) ? diameter : (leftHeight + rightHeight);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int diameterofTree(Node* root) {
    if (root == NULL)
        return 0;
    calcHeight(root);
    return diameter;
}

void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n, *arr;
    Node* root = NULL;
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    root = createTree(root, arr, n, 0);
    printf("%d\n", diameterofTree(root));
    return 0;
}