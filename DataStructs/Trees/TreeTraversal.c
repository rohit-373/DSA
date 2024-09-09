#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(Node *root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(Node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(12);
    root->right = createNode(9);
    root->left->left = createNode(5);
    root->left->right = createNode(6);

    printf("Inorder traversal:\n");
    inOrder(root);

    printf("\nPreorder traversal:\n");
    preOrder(root);

    printf("\nPostorder traversal:\n");
    postOrder(root);

    printf("\n");
    return 0;
}
