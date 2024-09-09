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

int height(Node* root) {
    if (root == NULL)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalancedBinaryTree(Node* root) {
    if (root == NULL)
        return true;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return abs(leftHeight - rightHeight) <= 1 && isBalancedBinaryTree(root->left) && isBalancedBinaryTree(root->right);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    //root->left->right->left = createNode(6);
    
    if (isBalancedBinaryTree(root))
        printf("The tree is a balance binary tree.\n");
    else
        printf("The tree is not a balance binary tree.\n");

    return 0;
}