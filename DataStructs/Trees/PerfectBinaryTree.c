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

bool isPerfect(Node *root, int d, int level) {
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return d == level+1;
    if (root->left == NULL || root->right == NULL)
        return false;
    return isPerfect(root->left, d, level+1) && isPerfect(root->right, d, level+1);
}

bool isPerfectBinaryTree(Node *root) {
    int d = 0;
    Node *temp = root;
    while (temp != NULL) {
        d++;
        temp = temp->left;
    }
    return isPerfect(root, d, 0);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    if (isPerfectBinaryTree(root))
        printf("The tree is a perfect binary tree.\n");
    else
        printf("The tree is not a perfect binary tree.\n");

    return 0;
}