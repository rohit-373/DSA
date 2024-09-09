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

int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isComplete(Node* root, int index, int nodeCount) {
    if (root == NULL)
        return true;
    
    if (index >= nodeCount)
        return false;

    return isComplete(root->left, 2*index+1, nodeCount) && isComplete(root->right, 2*index+2, nodeCount);
}

bool isCompleteBinaryTree(Node* root) {
    return isComplete(root, 0, countNodes(root));
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    
    if (isCompleteBinaryTree(root))
        printf("The tree is a complete binary tree.\n");
    else
        printf("The tree is not a complete binary tree.\n");

    return 0;
}